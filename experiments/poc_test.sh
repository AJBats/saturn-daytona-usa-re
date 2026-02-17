#!/bin/bash
# POC: Assemble both versions, link, extract raw bytes, compare
set -e

TOOLDIR="/mnt/d/Projects/SaturnReverseTest/tools/sh-elf/bin"
AS="$TOOLDIR/sh-elf-as"
LD="$TOOLDIR/sh-elf-ld"
OBJCOPY="$TOOLDIR/sh-elf-objcopy"

DIR="/mnt/d/Projects/SaturnReverseTest/experiments"

echo "=== Assembling original (all .byte) ==="
$AS -big -o "$DIR/poc_original.o" "$DIR/poc_original.s"

echo "=== Assembling symbolic (.long _SYMBOL) ==="
$AS -big -o "$DIR/poc_symbolic.o" "$DIR/poc_symbolic.s"

echo "=== Linking original ==="
$LD -EB -T "$DIR/poc_link.ld" -o "$DIR/poc_original.elf" "$DIR/poc_original.o"

echo "=== Linking symbolic ==="
$LD -EB -T "$DIR/poc_link.ld" -o "$DIR/poc_symbolic.elf" "$DIR/poc_symbolic.o"

echo "=== Extracting raw binary ==="
$OBJCOPY -O binary "$DIR/poc_original.elf" "$DIR/poc_original.bin"
$OBJCOPY -O binary "$DIR/poc_symbolic.elf" "$DIR/poc_symbolic.bin"

echo "=== Sizes ==="
ls -la "$DIR/poc_original.bin" "$DIR/poc_symbolic.bin"

echo ""
echo "=== Binary comparison ==="
if cmp -s "$DIR/poc_original.bin" "$DIR/poc_symbolic.bin"; then
    echo "MATCH! Byte-identical output."
else
    echo "MISMATCH! Differences found:"
    cmp -l "$DIR/poc_original.bin" "$DIR/poc_symbolic.bin" | head -20
    echo ""
    echo "Original hex:"
    xxd "$DIR/poc_original.bin" | tail -10
    echo ""
    echo "Symbolic hex:"
    xxd "$DIR/poc_symbolic.bin" | tail -10
fi
