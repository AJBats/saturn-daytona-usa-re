#!/bin/bash
# Find untested functions that have both .expected AND Ghidra decomp
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

# Get list of all function addresses in Ghidra decomp
ghidra_funcs=$(tr -d '\r' < "$GHIDRA" | grep -oP '^// FUN_\K[0-9a-f]+' | sort)

count=0
has_decomp=0

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue

    insn_count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
    [ "$insn_count" -gt 15 ] && continue  # skip large functions

    addr=$(echo "$base" | sed 's/FUN_//' | tr 'A-F' 'a-f')

    # Check if in Ghidra decomp
    if echo "$ghidra_funcs" | grep -q "^${addr}$"; then
        opcodes=$(tr -d '\r' < "$exp" | sed '/^$/d' | tr '\n' ' ')
        echo "$base  $insn_count insns  [$opcodes]"
        has_decomp=$((has_decomp + 1))
    fi
    count=$((count + 1))
done

echo ""
echo "=== $has_decomp untested <=15-insn functions with Ghidra decomp (out of $count total) ==="
