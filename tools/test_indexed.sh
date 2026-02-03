#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

for f in FUN_06027344 FUN_06027348 FUN_0601AB8C; do
  echo "=== $f ==="
  $CC1 -quiet -O2 -m2 -mbsr "$TESTDIR/${f}.c" -o "/tmp/${f}.s" 2>&1
  echo "--- Our output (opcodes): ---"
  grep -P '^\t' "/tmp/${f}.s" | sed 's/\t//' | sed 's/\t.*//' | sed 's/ .*//'
  echo "--- Expected: ---"
  tr -d '\r' < "$TESTDIR/${f}.expected" | head -20
  echo ""
  echo "--- Full asm: ---"
  cat "/tmp/${f}.s"
  echo ""
  echo "========================================="
done
