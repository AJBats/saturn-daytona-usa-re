#!/bin/bash
# Find untested functions with valid-looking expected files
# (must end with rts+delay or bra+delay, indicating proper boundary detection)
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

count=0

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue

    insn_count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
    [ "$insn_count" -gt 15 ] && continue
    [ "$insn_count" -lt 3 ] && continue  # skip 1-2 insn (likely truncated)

    # Check if ends with rts or bra (last 2 lines)
    last_two=$(tr -d '\r' < "$exp" | sed '/^$/d' | tail -2 | tr '\n' ' ')
    if echo "$last_two" | grep -qE '(rts|bra|jmp) '; then
        # Check if in Ghidra decomp
        addr_lower=$(echo "$base" | sed 's/FUN_//' | tr 'A-F' 'a-f')
        has_ghidra=$(tr -d '\r' < "$GHIDRA" | grep -c "^FUNC ${base}\|^FUNC FUN_${addr_lower} ")

        opcodes=$(tr -d '\r' < "$exp" | sed '/^$/d' | tr '\n' ' ')
        type_info=""
        if [ "$has_ghidra" -gt 0 ]; then
            type_info=$(tr -d '\r' < "$GHIDRA" | grep -i "^FUNC FUN_${addr_lower} " | awk '{print $8}')
            type_info=" ghidra=$type_info"
        fi
        echo "$base  $insn_count insns$type_info  [$opcodes]"
        count=$((count + 1))
    fi
done

echo ""
echo "=== $count valid untested functions with 3-15 insns ==="
