#!/bin/bash
# Find untested functions that ARE in aprog.s (have labels) and have Ghidra decomps
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
APROG=/mnt/d/Projects/SaturnReverseTest/build/aprog.s
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

count=0
for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue

    # Check if in aprog.s
    if ! grep -q "^${base}:" "$APROG"; then
        continue
    fi

    insn_count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)

    # Check last 2 instructions
    last2=$(tr -d '\r' < "$exp" | sed '/^$/d' | tail -2 | tr '\n' '+')

    # Check if in Ghidra
    base_lower=$(echo "$base" | tr 'A-F' 'a-f')
    ghidra_match=$(grep -i "^FUNC $base_lower " "$GHIDRA" | head -1)
    ghidra_insns=""
    ghidra_type=""
    if [ -n "$ghidra_match" ]; then
        ghidra_insns=$(echo "$ghidra_match" | tr -d '\r' | sed 's/.*insns=\([0-9]*\).*/\1/')
        ghidra_type=$(echo "$ghidra_match" | tr -d '\r' | sed 's/.*type=\([A-Z]*\).*/\1/')
    fi

    echo "$base  exp=$insn_count  ghidra=$ghidra_insns  type=$ghidra_type  last=[$last2]"
    count=$((count+1))
done

echo ""
echo "=== $count untested functions with aprog.s labels ==="
