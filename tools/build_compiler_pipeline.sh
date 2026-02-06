#!/bin/bash
set -e

PROJDIR="/mnt/d/Projects/SaturnReverseTest"
GENDIR="$PROJDIR/build/gen"
CC1="$PROJDIR/tools/gcc26-build/cc1"
AS="$PROJDIR/tools/sh-elf/bin/sh-elf-as"
LD="$PROJDIR/tools/sh-elf/bin/sh-elf-ld"
OBJCOPY="$PROJDIR/tools/sh-elf/bin/sh-elf-objcopy"

OUTDIR="$PROJDIR/build/compiler_rebuilt"
mkdir -p "$OUTDIR"

# Disc extraction constants
DISC_TRACK="$PROJDIR/external_resources/Daytona USA (USA)/Daytona USA (USA) (Track 01).bin"
DISC_OFFSET=49408    # 0xC100
APROG_SIZE=394896
BASE_ADDR=0x06003000
END_ADDR=0x06063690

# Reference binary (extracted from disc)
ORIG_BIN="$OUTDIR/aprog_original.bin"

echo "=== Building via Compiler Pipeline ==="

# Step 0: Extract original APROG from disc
echo "Step 0: Extracting APROG from disc..."
if [ ! -f "$DISC_TRACK" ]; then
    echo "  ERROR: Disc not found: $DISC_TRACK"
    exit 1
fi
dd if="$DISC_TRACK" bs=1 skip=$DISC_OFFSET count=$APROG_SIZE of="$ORIG_BIN" 2>/dev/null
echo "  Extracted $APROG_SIZE bytes from offset 0x$(printf '%X' $DISC_OFFSET)"

# Step 1: Compile all C files to assembly
echo "Step 1: Compiling C files to assembly..."
cd "$GENDIR"
count=0
failed=0
total=$(ls -1 FUN_*.c 2>/dev/null | wc -l)

for cfile in FUN_*.c; do
    base="${cfile%.c}"
    sfile="$OUTDIR/${base}.s"

    # Compile C to assembly
    if "$CC1" -quiet -O2 -m2 "$cfile" -o "$sfile" 2>/dev/null; then
        count=$((count + 1))
    else
        echo "  ERROR compiling $cfile"
        failed=$((failed + 1))
    fi

    if [ $((count % 200)) -eq 0 ] && [ $count -gt 0 ]; then
        echo "  Compiled $count / $total files..."
    fi
done
echo "  Compiled $count files ($failed failed)"

# Step 2: Extract .byte directives and create combined file
echo "Step 2: Creating combined assembly..."

# Read symbols to get function addresses
declare -A func_addrs
while IFS='=' read -r name addr; do
    name=$(echo "$name" | tr -d ' ;')
    addr=$(echo "$addr" | tr -d ' ;')
    if [ -n "$name" ] && [ -n "$addr" ]; then
        func_addrs[$name]=$addr
    fi
done < <(grep '^FUN_' "$PROJDIR/build/aprog_syms_merged.txt" | tr -d '\r')

# Create combined assembly
combined="$OUTDIR/aprog_combined.s"
echo "! Combined assembly from compiler pipeline" > "$combined"
echo "! Auto-generated - do not edit" >> "$combined"
echo "" >> "$combined"
echo "	.text" >> "$combined"

# Sort functions by address
cd "$OUTDIR"
sorted_funcs=$(for f in FUN_*.s; do
    name="${f%.s}"
    addr="${func_addrs[$name]}"
    if [ -n "$addr" ]; then
        echo "$addr $name"
    fi
done | sort -n | awk '{print $2}')

prev_end=$BASE_ADDR
for name in $sorted_funcs; do
    addr="${func_addrs[$name]}"
    if [ -z "$addr" ]; then
        continue
    fi

    addr_dec=$((addr))
    offset=$((addr_dec - BASE_ADDR))

    # Add .org directive if there's a gap
    if [ $offset -gt $((prev_end - BASE_ADDR)) ]; then
        # Fill gap with original bytes from disc-extracted binary
        gap_start=$((prev_end - BASE_ADDR))
        gap_size=$((offset - gap_start))
        if [ $gap_size -gt 0 ]; then
            echo "" >> "$combined"
            echo "	.org $gap_start" >> "$combined"
            dd if="$ORIG_BIN" bs=1 skip=$gap_start count=$gap_size 2>/dev/null | \
                xxd -p | fold -w32 | sed 's/\(..\)/0x\1, /g; s/, $//; s/^/	.byte /' >> "$combined"
        fi
    fi

    # Add function
    echo "" >> "$combined"
    echo "	.org $offset" >> "$combined"
    echo "_${name}:" >> "$combined"

    # Check if this is inline asm (.byte) or real C (instructions)
    # Label format is _FUN_xxxxxxxx where hex part is lowercase
    # E.g., FUN_060032D4 -> _FUN_060032d4
    name_label=$(echo "$name" | sed 's/\(FUN_\)\(.*\)/\1\L\2/')

    if grep -q '\.byte' "${name}.s"; then
        # Inline asm - extract .byte lines
        grep '\.byte' "${name}.s" >> "$combined"
        byte_count=$(grep -c '\.byte' "${name}.s" 2>/dev/null || echo 0)
        func_size=$((byte_count * 2))
    else
        # Real C - extract instructions between function label and pool/end
        sed -n "/^_${name_label}:/,/^L[0-9]/p" "${name}.s" | \
            grep -P '^\t[a-z]' >> "$combined" || true
        # Also grab constant pool entries
        sed -n "/^L[0-9]/,\$p" "${name}.s" | \
            grep -E '^\t\.(word|long|short|align)' >> "$combined" || true
        # Estimate size: count instruction lines * 2 bytes avg
        insn_count=$(sed -n "/^_${name_label}:/,/^L[0-9]/p" "${name}.s" | grep -cP '^\t[a-z]' 2>/dev/null || echo 0)
        func_size=$((insn_count * 2))
    fi

    prev_end=$((addr_dec + func_size))
done

# Fill remaining space to end
final_offset=$((prev_end - BASE_ADDR))
total_size=$((END_ADDR - BASE_ADDR))
if [ $final_offset -lt $total_size ]; then
    gap_size=$((total_size - final_offset))
    echo "" >> "$combined"
    echo "	.org $final_offset" >> "$combined"
    dd if="$ORIG_BIN" bs=1 skip=$final_offset count=$gap_size 2>/dev/null | \
        xxd -p | fold -w32 | sed 's/\(..\)/0x\1, /g; s/, $//; s/^/	.byte /' >> "$combined"
fi

echo "  Created combined assembly"

# Step 3: Assemble
echo "Step 3: Assembling..."
"$AS" -o "$OUTDIR/aprog_combined.o" "$combined" 2>&1

echo "  Created object file"

# Step 4: Create linker script
echo "Step 4: Creating linker script..."
cat > "$OUTDIR/aprog.ld" << 'EOF'
OUTPUT_FORMAT("elf32-sh")
OUTPUT_ARCH(sh)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x06003000, LENGTH = 0x60690
}

SECTIONS
{
    .text 0x06003000 :
    {
        *(.text)
        *(.text.*)
    } > RAM

    /DISCARD/ :
    {
        *(.comment)
        *(.gnu*)
        *(.note*)
        *(.data)
        *(.bss)
    }
}
EOF

# Step 5: Link
echo "Step 5: Linking..."
"$LD" -T "$OUTDIR/aprog.ld" -o "$OUTDIR/aprog_rebuilt.elf" "$OUTDIR/aprog_combined.o" 2>&1

# Step 6: Extract binary
echo "Step 6: Extracting binary..."
"$OBJCOPY" -O binary "$OUTDIR/aprog_rebuilt.elf" "$OUTDIR/aprog_rebuilt.bin"

# Step 7: Compare with original (disc-extracted)
echo ""
echo "=== Comparison ==="
orig_size=$(stat -c%s "$ORIG_BIN")
new_size=$(stat -c%s "$OUTDIR/aprog_rebuilt.bin")

echo "Original: $orig_size bytes"
echo "Rebuilt:  $new_size bytes"

if [ "$orig_size" -eq "$new_size" ]; then
    if cmp -s "$ORIG_BIN" "$OUTDIR/aprog_rebuilt.bin"; then
        echo ""
        echo "SUCCESS! Binary is IDENTICAL to original."
    else
        diff_count=$(cmp -l "$ORIG_BIN" "$OUTDIR/aprog_rebuilt.bin" | wc -l)
        echo ""
        echo "Size matches but $diff_count bytes differ"
        echo "First 10 differences:"
        cmp -l "$ORIG_BIN" "$OUTDIR/aprog_rebuilt.bin" | head -10
    fi
else
    echo ""
    echo "Size mismatch: $((new_size - orig_size)) byte difference"
fi

echo ""
echo "Output: $OUTDIR/aprog_rebuilt.bin"
