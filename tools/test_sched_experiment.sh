#!/bin/bash
# Scheduling experiment: compare -fno-schedule-insns2 output against expected
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

# Test delta=0 functions (scheduling diffs) with and without -fno-schedule-insns2
DELTA0_FUNCS="FUN_06005174 FUN_0601164A FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_060285E0 FUN_06028600 FUN_0603C05C FUN_0603C0A0 FUN_0603F3DA FUN_06040E88 FUN_0600C928 FUN_06011494 FUN_0600C970"

echo "=== SCHEDULING EXPERIMENT ==="
echo "Testing delta=0 functions with -fno-schedule-insns2"
echo ""

for f in $DELTA0_FUNCS; do
  [ ! -f "$TESTDIR/${f}.c" ] && continue
  [ ! -f "$TESTDIR/${f}.expected" ] && continue

  # Get per-function flags if any
  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/${f}.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/${f}.flags")

  # Compile with normal flags
  $CC1 -quiet $FLAGS "$TESTDIR/${f}.c" -o "/tmp/${f}_normal.s" 2>/dev/null

  # Compile with -fno-schedule-insns2
  $CC1 -quiet $FLAGS -fno-schedule-insns2 "$TESTDIR/${f}.c" -o "/tmp/${f}_nosched.s" 2>/dev/null

  # Extract opcodes
  normal_ops=$(grep -P '^\t' "/tmp/${f}_normal.s" | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  nosched_ops=$(grep -P '^\t' "/tmp/${f}_nosched.s" | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  expected_ops=$(tr -d '\r' < "$TESTDIR/${f}.expected")

  normal_count=$(echo "$normal_ops" | wc -l)
  nosched_count=$(echo "$nosched_ops" | wc -l)
  expected_count=$(echo "$expected_ops" | wc -l)

  normal_match="NO"
  nosched_match="NO"
  [ "$normal_ops" = "$expected_ops" ] && normal_match="YES"
  [ "$nosched_ops" = "$expected_ops" ] && nosched_match="YES"

  normal_diff=$(diff <(echo "$normal_ops") <(echo "$expected_ops") | grep '^[<>]' | wc -l)
  nosched_diff=$(diff <(echo "$nosched_ops") <(echo "$expected_ops") | grep '^[<>]' | wc -l)

  echo "$f: normal=$normal_count(diffs=$normal_diff) nosched=$nosched_count(diffs=$nosched_diff) expected=$expected_count  normal_match=$normal_match  nosched_match=$nosched_match"

  if [ "$nosched_match" = "YES" ]; then
    echo "  *** NEWLY PASSING with -fno-schedule-insns2 ***"
  elif [ "$nosched_diff" -lt "$normal_diff" ]; then
    echo "  improved with -fno-schedule-insns2 (fewer diffs)"
  elif [ "$nosched_diff" -gt "$normal_diff" ]; then
    echo "  worse with -fno-schedule-insns2"
  else
    echo "  no change"
  fi
done

echo ""
echo "=== Also testing some delta!=0 functions ==="

OTHER_FUNCS="FUN_060058FA FUN_0600D266 FUN_06026DF8 FUN_06035C48 FUN_06035C4E FUN_060322E8"
for f in $OTHER_FUNCS; do
  [ ! -f "$TESTDIR/${f}.c" ] && continue
  [ ! -f "$TESTDIR/${f}.expected" ] && continue

  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/${f}.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/${f}.flags")

  $CC1 -quiet $FLAGS -fno-schedule-insns2 "$TESTDIR/${f}.c" -o "/tmp/${f}_nosched.s" 2>/dev/null
  nosched_ops=$(grep -P '^\t' "/tmp/${f}_nosched.s" | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  expected_ops=$(tr -d '\r' < "$TESTDIR/${f}.expected")

  nosched_match="NO"
  [ "$nosched_ops" = "$expected_ops" ] && nosched_match="YES"

  if [ "$nosched_match" = "YES" ]; then
    echo "$f: STILL PASSING with -fno-schedule-insns2"
  else
    echo "$f: REGRESSION with -fno-schedule-insns2"
  fi
done
