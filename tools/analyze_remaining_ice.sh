#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/ice_analyze_$$
mkdir -p "$TMPDIR"

for f in FUN_0602B58E FUN_0602B5A2 FUN_06030FC0 FUN_0603136E FUN_0603DDFC; do
  cfile="$SRCDIR/$f.c"
  [ ! -f "$cfile" ] && continue
  tr -d '\r' < "$cfile" > "$TMPDIR/$f.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="/mnt/d/Projects/SaturnReverseTest/tests/$f.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi
  echo "=== $f ==="
  "$CC1" -quiet $FLAGS "$TMPDIR/$f.c" -o /dev/null 2>&1
  echo ""
done

rm -rf "$TMPDIR"
