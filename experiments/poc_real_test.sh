#!/bin/bash
# Test: real ASM mnemonics vs original .byte — do they produce identical bytes?
set -e

TOOLDIR="/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin"
AS="$TOOLDIR/sh-elf-as"
LD="$TOOLDIR/sh-elf-ld"
OBJCOPY="$TOOLDIR/sh-elf-objcopy"

DIR="/mnt/d/Projects/SaturnReverseTest/experiments"

echo "=== Assembling original (.byte) ==="
$AS -big -o "$DIR/poc_original.o" "$DIR/poc_original.s"

echo "=== Assembling real ASM (mnemonics + symbolic pool) ==="
$AS -big -o "$DIR/poc_real_asm.o" "$DIR/poc_real_asm.s"

echo "=== Linking both at original addresses ==="
$LD -EB -T "$DIR/poc_link.ld" -o "$DIR/poc_original.elf" "$DIR/poc_original.o"
$LD -EB -T "$DIR/poc_real_link.ld" -o "$DIR/poc_real_asm.elf" "$DIR/poc_real_asm.o"

echo "=== Extracting raw binary ==="
$OBJCOPY -O binary "$DIR/poc_original.elf" "$DIR/poc_original.bin"
$OBJCOPY -O binary "$DIR/poc_real_asm.elf" "$DIR/poc_real_asm.bin"

echo ""
echo "=== Sizes ==="
echo -n "  Original (.byte): "; wc -c < "$DIR/poc_original.bin"
echo -n "  Real ASM (with 2B pad): "; wc -c < "$DIR/poc_real_asm.bin"

echo ""
echo "=== Comparing function bytes (skip 2-byte pad in real ASM) ==="
# Real ASM has 2 extra bytes at the start (alignment pad)
# Compare original[0:174] vs real_asm[2:176]
dd if="$DIR/poc_real_asm.bin" bs=1 skip=2 of="$DIR/poc_real_asm_stripped.bin" 2>/dev/null

if cmp -s "$DIR/poc_original.bin" "$DIR/poc_real_asm_stripped.bin"; then
    echo "PERFECT MATCH! Real ASM mnemonics produce identical function bytes."
else
    echo "MISMATCH. Finding differences..."
    echo ""
    cmp -l "$DIR/poc_original.bin" "$DIR/poc_real_asm_stripped.bin" 2>/dev/null | head -20
    echo ""
    echo "Original hexdump:"
    xxd "$DIR/poc_original.bin"
    echo ""
    echo "Real ASM hexdump (stripped):"
    xxd "$DIR/poc_real_asm_stripped.bin"
fi
