#!/bin/bash
# Test a single function's compilation and size
set -e

PROJDIR="/mnt/d/Projects/SaturnReverseTest"
CC1="$PROJDIR/tools/gcc26-build/cc1"
AS="$PROJDIR/tools/sh-elf/bin/sh-elf-as"

func="$1"
if [ -z "$func" ]; then
    echo "Usage: $0 FUN_XXXXXXXX"
    exit 1
fi

# Get function address from symbol table
addr=$(grep "^${func} " "$PROJDIR/build/aprog_syms_merged.txt" | cut -d= -f2 | tr -d ' ;')
if [ -z "$addr" ]; then
    echo "Function $func not found in symbol table"
    exit 1
fi

echo "Testing $func at $addr"

# Create temp dir
tmpdir=$(mktemp -d)
trap "rm -rf $tmpdir" EXIT

# Compile
echo "Compiling..."
$CC1 -quiet -O2 -m2 "$PROJDIR/build/gen/${func}.c" -o "$tmpdir/${func}.s" 2>&1

# Check type
if grep -q '\.byte' "$tmpdir/${func}.s"; then
    echo "Type: inline asm"
    # Count .byte pairs (each line has 2 bytes)
    bytes=$(grep -c '\.byte' "$tmpdir/${func}.s")
    size=$((bytes * 2))
    echo "Size: $size bytes"
else
    echo "Type: real C"
    # Count instructions
    insns=$(sed -n "/^_/,/^L[0-9]/p" "$tmpdir/${func}.s" | grep -cP '^\t[a-z]')
    echo "Instructions: $insns"
    # Each instruction is 2 bytes
    size=$((insns * 2))

    # Also check pool size
    pool_entries=$(grep -cE '^\t\.(long|short|word)' "$tmpdir/${func}.s" || echo 0)
    pool_size=$((pool_entries * 4))  # Rough estimate
    echo "Pool entries: $pool_entries (est $pool_size bytes)"

    total=$((size + pool_size))
    echo "Estimated total: $total bytes"
fi

# Show assembly
echo ""
echo "Assembly:"
grep -A 30 "^_" "$tmpdir/${func}.s" | head -35
