#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src

for f in FUN_0600A3D2 FUN_0600B43C FUN_0600C138 FUN_0600D0FA FUN_0600E37A; do
  cfile="$SRCDIR/$f.c"
  [ ! -f "$cfile" ] && continue
  tmp="/tmp/ice_test_$f.c"
  tr -d '\r' < "$cfile" > "$tmp"
  FLAGS="-O2 -m2 -mbsr"
  ffile="/mnt/d/Projects/SaturnReverseTest/tests/$f.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi
  result=$("$CC1" -quiet $FLAGS "$tmp" -o /dev/null 2>&1)
  if echo "$result" | grep -q "internal"; then
    echo "$f: STILL ICE"
    echo "$result" | head -3
  elif [ -z "$result" ]; then
    echo "$f: COMPILES OK (no output)"
  else
    echo "$f: COMPILES (with warnings/errors)"
    echo "$result" | head -2
  fi
done
