#!/bin/bash
# Find small Ghidra decomps that look simple enough to compile
GHIDRA=/mnt/d/Projects/SaturnReverseTest/ghidra_project/decomp_all.txt
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

# Find LEAF functions with <=10 insns
grep "^FUNC .* type=LEAF" "$GHIDRA" | tr -d '\r' | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    insns=$(echo "$line" | sed 's/.*insns=\([0-9]*\).*/\1/')
    [ "$insns" -gt 10 ] && continue

    # Skip if already has C source
    func_upper=$(echo "$func" | tr 'a-f' 'A-F')
    [ -f "$SRCDIR/${func_upper}.c" ] && continue

    # Check if has expected file
    [ -f "$TDIR/${func_upper}.expected" ] || continue

    # Get expected insn count
    exp_count=$(tr -d '\r' < "$TDIR/${func_upper}.expected" | sed '/^$/d' | wc -l)

    # Check if counts match (within 2)
    diff=$((exp_count - insns))
    if [ "$diff" -lt 0 ]; then diff=$((-diff)); fi
    [ "$diff" -gt 2 ] && continue

    # Get the Ghidra decomp (check for complexity)
    LINE=$(grep -n "^FUNC $func " "$GHIDRA" | head -1 | cut -d: -f1)
    NEXTLINE=$(tail -n +$((LINE+1)) "$GHIDRA" | grep -n "^FUNC " | head -1 | cut -d: -f1)
    if [ -z "$NEXTLINE" ]; then NEXTLINE=50; fi
    decomp=$(sed -n "$((LINE+1)),$((LINE+NEXTLINE-1))p" "$GHIDRA" | tr -d '\r')

    # Check for bad patterns
    has_unaff=$(echo "$decomp" | grep -c "unaff_")
    has_stack=$(echo "$decomp" | grep -c "in_stack")
    has_jumptable=$(echo "$decomp" | grep -c "jumptable")
    has_warning=$(echo "$decomp" | grep -c "WARNING")

    if [ "$has_unaff" -eq 0 ] && [ "$has_stack" -eq 0 ] && [ "$has_jumptable" -eq 0 ] && [ "$has_warning" -eq 0 ]; then
        echo "=== $func_upper  (ghidra=$insns exp=$exp_count) ==="
        echo "$decomp" | head -15
        echo ""
    fi
done
