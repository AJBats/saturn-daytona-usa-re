#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/test_specific_$$
mkdir -p "$TMPDIR"

for base in "$@"; do
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && { echo "$base: NO C FILE"; continue; }

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>"$TMPDIR/$base.err"
  if [ ! -f "$TMPDIR/$base.s" ]; then
    echo "$base: COMPILE ERROR"
    cat "$TMPDIR/$base.err"
    continue
  fi

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full"
  sed 's/\t/ /g' < "$TMPDIR/$base.full" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
    echo "$base: PASS (ours=$ours orig=$orig)"
  else
    ndiff=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    echo "$base: FAIL (ours=$ours orig=$orig delta=$delta ndiff=$ndiff)"
    diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
    echo "--- Our asm ---"
    cat -n "$TMPDIR/$base.full"
  fi
  echo ""
done

rm -rf "$TMPDIR"
