#!/bin/bash
# Analyze delta=0, 4-diff functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/analyze_4diff_$$
mkdir -p "$TMPDIR"

FUNCS="FUN_06005174 FUN_06018EC8 FUN_06033330 FUN_0603C0A0 FUN_0603F8B8"

for base in $FUNCS; do
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && { echo "=== $base: COMPILE ERROR ==="; continue; }

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full"
  sed 's/\t/ /g' < "$TMPDIR/$base.full" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  echo "=== $base ==="
  echo "--- Opcode diff ---"
  diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
  echo "--- Our full asm ---"
  cat -n "$TMPDIR/$base.full"
  echo "--- C source ---"
  cat -n "$SRCDIR/$base.c" | head -30
  echo ""
done

rm -rf "$TMPDIR"
