#!/bin/bash
# Identify "structural matches" — functions where delta=0 and the sorted
# opcode multiset is identical (same opcodes, different ordering)
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

struct_match=0
struct_fail=0
pass_count=0
fail_count=0
total=0

echo "=== STRUCTURAL MATCH ANALYSIS ==="
echo ""
echo "Functions with identical opcode multisets (same opcodes, any order):"
echo ""

for cfile in "$TESTDIR"/FUN_*.c; do
  base=$(basename "$cfile" .c)
  [ ! -f "$TESTDIR/${base}.expected" ] && continue

  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/${base}.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/${base}.flags")

  $CC1 -quiet $FLAGS "$cfile" -o "/tmp/${base}.s" 2>/dev/null

  our_ops=$(grep -P '^\t' "/tmp/${base}.s" | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  expected_ops=$(tr -d '\r' < "$TESTDIR/${base}.expected" | grep -v '^$')

  total=$((total + 1))

  # Exact match
  if [ "$our_ops" = "$expected_ops" ]; then
    pass_count=$((pass_count + 1))
    continue
  fi

  # Check sorted multiset match (same opcodes, different order)
  our_sorted=$(echo "$our_ops" | sort)
  exp_sorted=$(echo "$expected_ops" | sort)

  if [ "$our_sorted" = "$exp_sorted" ]; then
    struct_match=$((struct_match + 1))
    our_count=$(echo "$our_ops" | wc -l)

    # Show the diff
    diff_lines=$(diff <(echo "$our_ops") <(echo "$expected_ops") | grep '^[<>]' | wc -l)
    echo "  STRUCT_MATCH  $base  ($our_count insns, $diff_lines reordered lines)"
  else
    fail_count=$((fail_count + 1))
  fi
done

echo ""
echo "=== SUMMARY ==="
echo "Total: $total"
echo "Exact PASS: $pass_count"
echo "Structural match (same opcodes, different order): $struct_match"
echo "True FAIL (different opcodes): $fail_count"
echo ""
echo "Effective match rate: $((pass_count + struct_match)) / $total ($(( (pass_count + struct_match) * 100 / total ))%)"
