#!/bin/bash
# Find small untested functions where expected insn count ~= Ghidra insn count
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
APROG=/mnt/d/Projects/SaturnReverseTest/build/aprog.s
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue
    grep -q "^${base}:" "$APROG" || continue

    insn_count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
    [ "$insn_count" -gt 20 ] && continue

    last2=$(tr -d '\r' < "$exp" | sed '/^$/d' | tail -2 | tr '\n' '+')

    base_lower=$(echo "$base" | tr 'A-F' 'a-f')
    ghidra_match=$(grep -i "^FUNC $base_lower " "$GHIDRA" | head -1)
    if [ -n "$ghidra_match" ]; then
        ghidra_insns=$(echo "$ghidra_match" | tr -d '\r' | sed 's/.*insns=\([0-9]*\).*/\1/')
        ghidra_type=$(echo "$ghidra_match" | tr -d '\r' | sed 's/.*type=\([A-Z]*\).*/\1/')
        diff=$((insn_count - ghidra_insns))
        if [ "$diff" -lt 0 ]; then diff=$((-diff)); fi
        if [ "$diff" -le 3 ]; then
            echo "$base  exp=$insn_count  ghidra=$ghidra_insns  type=$ghidra_type  last=[$last2]"
        fi
    fi
done
