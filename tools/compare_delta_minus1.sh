#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

for f in FUN_0600DE54 FUN_060149CC FUN_060149E0 FUN_06033504; do
  echo "=== $f ==="
  $CC1 -quiet -O2 -m2 -mbsr $TDIR/$f.c -o /tmp/$f.s 2>/dev/null
  echo "--- ours ---"
  grep -P '^\t[a-z]' /tmp/$f.s | sed 's/\t//' | awk '{print $1}'
  echo "--- expected ---"
  tr -d '\r' < $TDIR/$f.expected
done
