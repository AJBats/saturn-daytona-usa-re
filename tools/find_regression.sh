#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/find_reg_$$
mkdir -p "$TMPDIR"

# List of known PASS functions from before the patch
# (43 total - let's check them all)
for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && cfile="$TESTDIR/$base.c"
  [ ! -f "$cfile" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && continue

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/$base.opc"
  tr -d '\r' < "$exp_file" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opc")
  orig=$(wc -l < "$TMPDIR/$base.exp")

  if diff -q "$TMPDIR/$base.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
    echo "PASS $base"
  fi
done

rm -rf "$TMPDIR"
