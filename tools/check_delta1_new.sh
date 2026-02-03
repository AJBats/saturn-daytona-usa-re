#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

for f in FUN_060359DA FUN_06035C80 FUN_0603F4E0 FUN_0603F500; do
  [ ! -f "$TESTDIR/${f}.c" ] && continue
  [ ! -f "$TESTDIR/${f}.expected" ] && continue

  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/${f}.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/${f}.flags")

  $CC1 -quiet $FLAGS "$TESTDIR/${f}.c" -o "/tmp/${f}.s" 2>/dev/null

  echo "=== $f ==="
  echo "--- Our asm ---"
  grep -P '^\t' "/tmp/${f}.s" | grep -v '^\t\.'
  echo "--- Expected opcodes ---"
  tr -d '\r' < "$TESTDIR/${f}.expected"
  echo ""
  echo "--- Diff (opcodes only) ---"
  our_ops=$(grep -P '^\t' "/tmp/${f}.s" | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r')
  exp_ops=$(tr -d '\r' < "$TESTDIR/${f}.expected" | grep -v '^$')
  diff <(echo "$our_ops") <(echo "$exp_ops") || true
  echo "========================================="
  echo ""
done
