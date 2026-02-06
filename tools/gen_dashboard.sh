#!/bin/bash
# Generate dashboard-ready markdown tables for function status
# Output can be directly copy-pasted into dashboard/*.md

cd /mnt/d/Projects/SaturnReverseTest

echo "# Function Status Dashboard Data"
echo ""
echo "Generated: $(date '+%Y-%m-%d %H:%M')"
echo ""
echo "Copy-paste the relevant sections into dashboard/asm_matching.md"
echo ""
echo "---"
echo ""

# Run test harness and capture results
results=$(bash tools/test_harness.sh 2>&1)

# Count stats
pass_count=$(echo "$results" | grep -c "^PASS")
fail_count=$(echo "$results" | grep -c "^FAIL")
total=$((pass_count + fail_count))

# Count deltas
delta_neg=$(echo "$results" | grep -E "^FAIL.*delta=-" | wc -l)
delta_zero=$(echo "$results" | grep -E "^FAIL.*delta=0\)" | wc -l)
delta_pos=$(echo "$results" | grep -E "^FAIL.*delta=[1-9]" | wc -l)

echo "## Summary"
echo ""
echo "| Metric | Value |"
echo "|--------|-------|"
echo "| Total tested | $total |"
echo "| PASS | $pass_count ($(echo "scale=1; $pass_count * 100 / $total" | bc)%) |"
echo "| FAIL | $fail_count |"
echo ""

echo "## Delta Breakdown"
echo ""
echo "| Category | Count | Meaning | Tractability |"
echo "|----------|-------|---------|--------------|"
echo "| delta=0 | $delta_zero | Same count, different opcodes | Scheduling - challenging |"
echo "| delta<0 | $delta_neg | Our code shorter | Better optimization - intentional |"
echo "| delta>0 | $delta_pos | Our code longer | Register allocation - challenging |"
echo ""

echo "## PASS Functions ($pass_count)"
echo ""
echo "| Function | Insns | Notes |"
echo "|----------|-------|-------|"
echo "$results" | grep "^PASS" | sort | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    insns=$(echo "$line" | grep -oP '\d+ insns' | grep -oP '^\d+')
    echo "| $func | $insns | |"
done
echo ""

echo "## FAIL delta=0 ($delta_zero)"
echo ""
echo "Same instruction count, different opcodes (scheduling/allocation)."
echo ""
echo "| Function | Insns | Notes |"
echo "|----------|-------|-------|"
echo "$results" | grep -E "^FAIL.*delta=0\)" | sort | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    insns=$(echo "$line" | grep -oP 'ours=\d+' | grep -oP '\d+')
    echo "| $func | $insns | |"
done
echo ""

echo "## FAIL delta<0 (Our Code Better)"
echo ""
echo "| Function | Ours | Orig | Delta | Notes |"
echo "|----------|------|------|-------|-------|"
echo "$results" | grep -E "^FAIL.*delta=-" | sort | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    ours=$(echo "$line" | grep -oP 'ours=\d+' | grep -oP '\d+')
    orig=$(echo "$line" | grep -oP 'orig=\d+' | grep -oP '\d+')
    delta=$(echo "$line" | grep -oP 'delta=-?\d+' | grep -oP '\-?\d+')
    echo "| $func | $ours | $orig | $delta | |"
done
echo ""

echo "## FAIL delta>0 (Our Code Longer)"
echo ""
echo "| Function | Ours | Orig | Delta | Notes |"
echo "|----------|------|------|-------|-------|"
echo "$results" | grep -E "^FAIL.*delta=[1-9]" | sort | while read line; do
    func=$(echo "$line" | awk '{print $2}')
    ours=$(echo "$line" | grep -oP 'ours=\d+' | grep -oP '\d+')
    orig=$(echo "$line" | grep -oP 'orig=\d+' | grep -oP '\d+')
    delta=$(echo "$line" | grep -oP 'delta=-?\d+' | grep -oP '\-?\d+')
    echo "| $func | $ours | $orig | $delta | |"
done
