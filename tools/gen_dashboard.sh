#!/bin/bash
# Generate dashboard-ready markdown tables for ALL function status
# Output can be directly copy-pasted into dashboard/*.md

cd /mnt/d/Projects/SaturnReverseTest

echo "# Function Status Dashboard Data"
echo ""
echo "Generated: $(date '+%Y-%m-%d %H:%M')"
echo ""
echo "---"
echo ""

# Run test harness and capture results
results=$(bash tools/test_harness.sh 2>&1)

# Count all source files
total_src=$(ls src/*.c 2>/dev/null | wc -l)
total_expected=$(ls tests/*.expected 2>/dev/null | wc -l)

# Count stats from test harness
pass_count=$(echo "$results" | grep -c "^PASS")
fail_count=$(echo "$results" | grep -c "^FAIL")
skip_count=$((total_src - pass_count - fail_count))

# Count deltas
delta_neg=$(echo "$results" | grep -E "^FAIL.*delta=-" | wc -l)
delta_zero=$(echo "$results" | grep -E "^FAIL.*delta=0\)" | wc -l)
delta_pos=$(echo "$results" | grep -E "^FAIL.*delta=[1-9]" | wc -l)

echo "## Summary"
echo ""
echo "| Metric | Value |"
echo "|--------|-------|"
echo "| Total source files | $total_src |"
echo "| Expected files | $total_expected |"
echo "| PASS | $pass_count |"
echo "| FAIL | $fail_count |"
echo "| No expected | $skip_count |"
echo ""

echo "## Delta Breakdown (of $fail_count FAIL)"
echo ""
echo "| Category | Count | Meaning |"
echo "|----------|-------|---------|"
echo "| delta=0 | $delta_zero | Same count, different opcodes |"
echo "| delta<0 | $delta_neg | Our code shorter |"
echo "| delta>0 | $delta_pos | Our code longer |"
echo ""

echo "## All Functions ($total_src)"
echo ""
echo "| Function | Status | Ours | Orig | Delta | Notes |"
echo "|----------|--------|------|------|-------|-------|"

# Process ALL source files
for cfile in src/FUN_*.c; do
    base=$(basename "$cfile" .c)

    # Check test harness result
    line=$(echo "$results" | grep "  $base  ")

    if echo "$line" | grep -q "^PASS"; then
        insns=$(echo "$line" | grep -oP '\d+ insns' | grep -oP '^\d+')
        echo "| $base | PASS | $insns | $insns | 0 | |"
    elif echo "$line" | grep -q "^FAIL"; then
        ours=$(echo "$line" | grep -oP 'ours=\d+' | grep -oP '\d+')
        orig=$(echo "$line" | grep -oP 'orig=\d+' | grep -oP '\d+')
        delta=$(echo "$line" | grep -oP 'delta=-?\d+' | grep -oP '\-?\d+')
        echo "| $base | FAIL | $ours | $orig | $delta | |"
    else
        # No expected file
        echo "| $base | - | - | - | - | No expected |"
    fi
done
