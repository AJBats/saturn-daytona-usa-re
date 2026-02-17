#!/bin/bash
# Test: assemble symbolic version with RELOCATED addresses.
# The instruction bytes should be identical (they're .byte literals).
# The pool entries should contain the NEW addresses, NOT the originals.
set -e

TOOLDIR="/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin"
AS="$TOOLDIR/sh-elf-as"
LD="$TOOLDIR/sh-elf-ld"
OBJCOPY="$TOOLDIR/sh-elf-objcopy"

DIR="/mnt/d/Projects/SaturnReverseTest/experiments"

echo "=== Assembling symbolic version ==="
$AS -big -o "$DIR/poc_symbolic.o" "$DIR/poc_symbolic.s"

echo "=== Linking at ORIGINAL addresses ==="
$LD -EB -T "$DIR/poc_link.ld" -o "$DIR/poc_at_original.elf" "$DIR/poc_symbolic.o"
$OBJCOPY -O binary "$DIR/poc_at_original.elf" "$DIR/poc_at_original.bin"

echo "=== Linking at RELOCATED addresses ==="
$LD -EB -T "$DIR/poc_relocated.ld" -o "$DIR/poc_at_relocated.elf" "$DIR/poc_symbolic.o"
$OBJCOPY -O binary "$DIR/poc_at_relocated.elf" "$DIR/poc_at_relocated.bin"

echo ""
echo "=== Pool bytes at original addresses ==="
echo "Pool starts at offset 142 (0x8E), 8 entries × 4 bytes = 32 bytes"
xxd -s 142 -l 32 "$DIR/poc_at_original.bin"

echo ""
echo "=== Pool bytes at relocated addresses ==="
xxd -s 142 -l 32 "$DIR/poc_at_relocated.bin"

echo ""
echo "=== Instruction bytes comparison (first 130 bytes — should be IDENTICAL) ==="
if cmp -s -n 130 "$DIR/poc_at_original.bin" "$DIR/poc_at_relocated.bin"; then
    echo "INSTRUCTIONS MATCH — same bytes regardless of where things are placed."
else
    echo "INSTRUCTIONS DIFFER — this would be a problem!"
fi

echo ""
echo "=== Pool comparison (bytes 142-174 — should be DIFFERENT) ==="
if cmp -s -n 32 <(dd if="$DIR/poc_at_original.bin" bs=1 skip=142 count=32 2>/dev/null) \
                 <(dd if="$DIR/poc_at_relocated.bin" bs=1 skip=142 count=32 2>/dev/null); then
    echo "POOLS IDENTICAL — symbols didn't relocate (BAD!)"
else
    echo "POOLS DIFFER — symbols relocated to new addresses (GOOD!)"
fi

echo ""
echo "=== Expected pool[1] values ==="
echo "Original: FUN_06008318 → should be 06 00 83 18"
echo "Relocated: FUN_06009318 → should be 06 00 93 18"
echo ""
echo "Actual pool[1] (bytes 146-149):"
echo -n "  Original:  "; xxd -s 146 -l 4 "$DIR/poc_at_original.bin" | awk '{print $2, $3}'
echo -n "  Relocated: "; xxd -s 146 -l 4 "$DIR/poc_at_relocated.bin" | awk '{print $2, $3}'
