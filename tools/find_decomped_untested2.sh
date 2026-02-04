#!/bin/bash
# Find untested functions that have both .expected AND Ghidra decomp
# Handle case differences (expected files use uppercase, Ghidra uses lowercase)
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt

# Build list of Ghidra functions with metadata (lowercase)
ghidra_data=$(tr -d '\r' < "$GHIDRA" | grep '^FUNC ' | awk '{print $2, $4, $6, $8}')

count=0
has_decomp=0

for exp in "$TDIR"/*.expected; do
    base=$(basename "$exp" .expected)
    cfile="$SRCDIR/$base.c"
    [ -f "$cfile" ] && continue

    insn_count=$(tr -d '\r' < "$exp" | sed '/^$/d' | wc -l)
    [ "$insn_count" -gt 15 ] && continue

    # Convert to lowercase for matching
    base_lower=$(echo "$base" | tr 'A-F' 'a-f')

    # Check if in Ghidra decomp
    match=$(echo "$ghidra_data" | grep -i "^${base_lower} ")
    if [ -n "$match" ]; then
        ghidra_insns=$(echo "$match" | awk '{print $3}')
        ghidra_type=$(echo "$match" | awk '{print $4}')
        opcodes=$(tr -d '\r' < "$exp" | sed '/^$/d' | tr '\n' ' ')
        echo "$base  exp=$insn_count  ghidra=$ghidra_insns  type=$ghidra_type  [$opcodes]"
        has_decomp=$((has_decomp + 1))
    fi
    count=$((count + 1))
done

echo ""
echo "=== $has_decomp untested <=15-insn functions with Ghidra decomp ==="
