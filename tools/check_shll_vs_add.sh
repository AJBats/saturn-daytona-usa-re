#!/bin/bash
# Check how many functions have add rN,rN where expected has shll
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

count=0
for cfile in $TDIR/FUN_*.c; do
  base=$(basename "$cfile" .c)
  expected="$TDIR/$base.expected"
  [ -f "$expected" ] || continue

  $CC1 -quiet -O2 -m2 -mbsr "$cfile" -o "/tmp/$base.s" 2>/dev/null

  # Check if we use "add rN,rN" (doubling)
  our_add=$(grep -cP '^\tadd\tr[0-9]+,r[0-9]+$' "/tmp/$base.s" 2>/dev/null || echo 0)
  # Check if expected has shll
  exp_shll=$(grep -c '^shll$' <(tr -d '\r' < "$expected") 2>/dev/null || echo 0)

  if [ "$our_add" -gt 0 ] && [ "$exp_shll" -gt 0 ]; then
    echo "MISMATCH: $base (our add=$our_add, exp shll=$exp_shll)"
    count=$((count + 1))
  fi
done

echo ""
echo "Total functions with add-vs-shll mismatch: $count"
