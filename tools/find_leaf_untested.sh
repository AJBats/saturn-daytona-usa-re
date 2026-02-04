#!/bin/bash
# Find untested LEAF functions with Ghidra decomps - these have best chance of passing
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue

    insn_count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
    [ "$insn_count" -gt 15 ] && continue

    # Check if it's a LEAF function (no jsr/bsr in expected)
    has_call=$(tr -d '\r' < "$exp" | grep -c -E '^(jsr|bsr|sts\.l)')
    [ "$has_call" -gt 0 ] && continue

    # Check valid boundary (rts+nop or similar)
    last=$(tr -d '\r' < "$exp" | sed '/^$/d' | tail -1)

    # Check Ghidra
    base_lower=$(echo "$base" | tr 'A-F' 'a-f')
    ghidra_match=$(grep -i "^FUNC $base_lower " "$GHIDRA" | head -1)
    ghidra_insns=""
    ghidra_type=""
    has_ghidra="no"
    if [ -n "$ghidra_match" ]; then
        has_ghidra="yes"
        ghidra_insns=$(echo "$ghidra_match" | tr -d '\r' | sed 's/.*insns=\([0-9]*\).*/\1/')
        ghidra_type=$(echo "$ghidra_match" | tr -d '\r' | sed 's/.*type=\([A-Z]*\).*/\1/')
    fi

    opcodes=$(tr -d '\r' < "$exp" | sed '/^$/d' | tr '\n' ' ')
    echo "$base  exp=$insn_count  ghidra=$ghidra_insns  type=$ghidra_type  has_decomp=$has_ghidra  [$opcodes]"
done
