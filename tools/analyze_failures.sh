#!/bin/bash
# Analyze specific failure functions to find fixable patterns
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

# Functions with delta=+1 or +2 that might be fixable
FUNCS="FUN_0602760C FUN_0602761E FUN_06027630 FUN_06035E3C FUN_06038F34 FUN_0603B96A FUN_0603F4E0 FUN_0603F500 FUN_06035E5E FUN_0603BF5A FUN_0603A766 FUN_0600D336"

for f in $FUNCS; do
  [ ! -f "$TESTDIR/${f}.c" ] && continue
  [ ! -f "$TESTDIR/${f}.expected" ] && continue

  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/${f}.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/${f}.flags")

  $CC1 -quiet $FLAGS "$TESTDIR/${f}.c" -o "/tmp/${f}.s" 2>/dev/null

  # Extract opcodes with operands
  our_ops=$(grep -P '^\t' "/tmp/${f}.s" | sed 's/^\t//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  our_count=$(echo "$our_ops" | wc -l)
  exp_count=$(tr -d '\r' < "$TESTDIR/${f}.expected" | grep -v '^$' | wc -l)

  echo "=========================================="
  echo "$f  (ours=$our_count expected=$exp_count delta=$((our_count - exp_count)))"
  echo "--- Full assembly ---"
  grep -P '^\t' "/tmp/${f}.s" | grep -v '^\.'
  echo "--- Expected opcodes ---"
  tr -d '\r' < "$TESTDIR/${f}.expected"
  echo ""
done
