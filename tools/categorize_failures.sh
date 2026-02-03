#!/bin/bash
# Categorize all failures by delta value
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

declare -A delta_counts
declare -A delta_funcs

for cfile in "$TESTDIR"/FUN_*.c; do
  base=$(basename "$cfile" .c)
  [ ! -f "$TESTDIR/${base}.expected" ] && continue

  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/${base}.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/${base}.flags")

  $CC1 -quiet $FLAGS "$cfile" -o "/tmp/${base}.s" 2>/dev/null

  our_ops=$(grep -P '^\t' "/tmp/${base}.s" | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  expected_ops=$(tr -d '\r' < "$TESTDIR/${base}.expected" | grep -v '^$')

  our_count=$(echo "$our_ops" | wc -l)
  exp_count=$(echo "$expected_ops" | wc -l)
  delta=$((our_count - exp_count))

  match="FAIL"
  [ "$our_ops" = "$expected_ops" ] && match="PASS"

  if [ "$match" = "FAIL" ]; then
    if [ -z "${delta_counts[$delta]}" ]; then
      delta_counts[$delta]=0
    fi
    delta_counts[$delta]=$((${delta_counts[$delta]} + 1))
    delta_funcs[$delta]="${delta_funcs[$delta]} $base"
  fi
done

echo "=== FAILURE DISTRIBUTION BY DELTA ==="
echo ""
for d in $(echo "${!delta_counts[@]}" | tr ' ' '\n' | sort -n); do
  echo "delta=$d: ${delta_counts[$d]} functions"
  echo "  ${delta_funcs[$d]}"
  echo ""
done

echo "=== SUMMARY ==="
total_neg=0
total_zero=0
total_pos_small=0
total_pos_big=0
for d in $(echo "${!delta_counts[@]}" | tr ' ' '\n' | sort -n); do
  if [ "$d" -lt 0 ]; then
    total_neg=$((total_neg + ${delta_counts[$d]}))
  elif [ "$d" -eq 0 ]; then
    total_zero=$((total_zero + ${delta_counts[$d]}))
  elif [ "$d" -le 2 ]; then
    total_pos_small=$((total_pos_small + ${delta_counts[$d]}))
  else
    total_pos_big=$((total_pos_big + ${delta_counts[$d]}))
  fi
done

echo "Our code shorter (delta<0): $total_neg functions"
echo "Same count, diff order (delta=0): $total_zero functions"
echo "Our code slightly longer (delta=+1 to +2): $total_pos_small functions"
echo "Our code much longer (delta>=+3): $total_pos_big functions"
