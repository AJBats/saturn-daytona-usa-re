#!/bin/bash
# Find functions closest to PASS
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/easy_wins2_$$
mkdir -p "$TMPDIR"

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

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$exp_file" > "$TMPDIR/$base.exp"

  if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
    continue  # already PASS
  fi

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))
  ndiffs=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')

  if [ "$delta" -eq 0 ] && [ "$ndiffs" -le 8 ]; then
    echo "DELTA0  diffs=$ndiffs  $base  (ours=$ours)"
  elif [ "$delta" -eq 1 ] && [ "$ndiffs" -le 7 ]; then
    echo "DELTA+1 diffs=$ndiffs  $base  (ours=$ours)"
  elif [ "$delta" -eq -1 ] && [ "$ndiffs" -le 3 ]; then
    echo "DELTA-1 diffs=$ndiffs  $base  (ours=$ours)"
  fi
done | sort -t= -k2 -n

rm -rf "$TMPDIR"
