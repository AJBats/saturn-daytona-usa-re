#!/bin/bash
# Look at expected opcodes for all 2-insn untested functions
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue

    count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
    [ "$count" -ne 2 ] && continue

    opcodes=$(tr -d '\r' < "$exp" | sed '/^$/d' | tr '\n' ' ')

    # Get address from function name
    addr=$(echo "$base" | sed 's/FUN_//')

    # Look up Ghidra decomp
    decomp=$(tr -d '\r' < "$GHIDRA" | grep -A 20 "^// FUN_$addr" | head -20 2>/dev/null)

    echo "$base  opcodes=[$opcodes]"
    if [ -n "$decomp" ]; then
        echo "$decomp" | head -8
    else
        echo "  (no Ghidra decomp found)"
    fi
    echo ""
done
