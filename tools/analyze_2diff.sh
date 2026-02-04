#!/bin/bash
# Analyze delta=0, 2-diff functions to find fixable patterns
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/analyze_2diff_$$
mkdir -p "$TMPDIR"

FUNCS="FUN_0601164A FUN_0601209E FUN_060192CA FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_060285E0 FUN_06028600 FUN_06035C80 FUN_0603C05C FUN_0603F3DA FUN_0603F4CC FUN_06040954"

for base in $FUNCS; do
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

  # Full asm (opcode + operands)
  grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full"
  # Just opcodes
  sed 's/\t/ /g' < "$TMPDIR/$base.full" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  echo "=== $base ==="
  echo "FLAGS: $FLAGS"
  echo "--- Opcode diff ---"
  diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
  echo "--- Our full asm (with line numbers) ---"
  cat -n "$TMPDIR/$base.full"
  echo ""
done

rm -rf "$TMPDIR"
