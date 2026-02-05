#!/bin/bash
# Generate function catalog from test results
cd /mnt/d/Projects/SaturnReverseTest

echo "# Function Catalog"
echo ""
echo "Generated: $(date)"
echo ""
echo "## Summary"
echo ""

# Run test harness and capture results
results=$(bash tools/test_harness.sh 2>&1)

# Count stats
pass_count=$(echo "$results" | grep -c "^PASS")
fail_count=$(echo "$results" | grep -c "^FAIL")
skip_count=$(echo "$results" | grep -c "^SKIP")
total=$((pass_count + fail_count))

echo "- **PASS**: $pass_count functions (binary-perfect match)"
echo "- **FAIL**: $fail_count functions (codegen differences)"
echo "- **SKIP**: $skip_count functions (no .expected file)"
echo "- **Total tested**: $total"
echo "- **Pass rate**: $(echo "scale=1; $pass_count * 100 / $total" | bc)%"
echo ""

echo "## Delta Distribution"
echo ""
echo "| Delta Range | Count | Description |"
echo "|-------------|-------|-------------|"

# Count deltas
delta_neg_big=$(echo "$results" | grep -E "^FAIL.*delta=-[0-9]{2,}" | wc -l)
delta_neg_small=$(echo "$results" | grep -E "^FAIL.*delta=-[1-9]\)" | wc -l)
delta_zero=$(echo "$results" | grep -E "^FAIL.*delta=0\)" | wc -l)
delta_pos_small=$(echo "$results" | grep -E "^FAIL.*delta=[1-9]\)" | wc -l)
delta_pos_big=$(echo "$results" | grep -E "^FAIL.*delta=[0-9]{2,}\)" | wc -l)

echo "| delta < -9 | $delta_neg_big | Our code much shorter (better optimization) |"
echo "| -9 <= delta < 0 | $delta_neg_small | Our code slightly shorter |"
echo "| delta = 0 | $delta_zero | Same count, different opcodes (scheduling) |"
echo "| 0 < delta <= 9 | $delta_pos_small | Our code slightly longer |"
echo "| delta > 9 | $delta_pos_big | Our code much longer (wrong codegen) |"
echo ""

echo "## PASS Functions (Binary Perfect)"
echo ""
echo "| Function | Insns |"
echo "|----------|-------|"
echo "$results" | grep "^PASS" | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    insns=$(echo "$line" | grep -oP '\d+ insns' | grep -oP '^\d+')
    echo "| $func | $insns |"
done
echo ""

echo "## Close Matches (delta = 0)"
echo ""
echo "Same instruction count but different opcodes - scheduling/register allocation differences."
echo ""
echo "| Function | Insns |"
echo "|----------|-------|"
echo "$results" | grep -E "^FAIL.*delta=0\)" | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    insns=$(echo "$line" | grep -oP 'ours=\d+' | grep -oP '\d+')
    echo "| $func | $insns |"
done
echo ""

echo "## Near Misses (|delta| = 1 or 2)"
echo ""
echo "| Function | Ours | Orig | Delta |"
echo "|----------|------|------|-------|"
echo "$results" | grep -E "^FAIL.*delta=(-[12]|[12])\)" | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    ours=$(echo "$line" | grep -oP 'ours=\d+' | grep -oP '\d+')
    orig=$(echo "$line" | grep -oP 'orig=\d+' | grep -oP '\d+')
    delta=$(echo "$line" | grep -oP 'delta=-?\d+' | grep -oP '\-?\d+')
    echo "| $func | $ours | $orig | $delta |"
done
