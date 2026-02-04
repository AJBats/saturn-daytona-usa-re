#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/wins_analyze_$$
mkdir -p "$TMPDIR"

analyze_func() {
  local base=$1
  local cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && return

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && return

  # Full asm lines (opcode + operands)
  grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full_asm"
  # Just opcodes
  sed 's/\t/ /g' < "$TMPDIR/$base.full_asm" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  echo "=== $base (ours=$ours orig=$orig delta=$delta) ==="
  echo "FLAGS: $FLAGS"
  echo "--- Opcode diff ---"
  diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
  echo "--- Our full asm ---"
  cat -n "$TMPDIR/$base.full_asm"
  echo ""
}

echo "============================================"
echo "DELTA=0 FUNCTIONS WITH 2 DIFFS"
echo "============================================"
for f in FUN_0601164A FUN_060192CA FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_060285E0 FUN_06028600 FUN_06035C80 FUN_0603C05C FUN_0603F3DA FUN_0603F4CC FUN_06040954; do
  analyze_func "$f"
done

echo ""
echo "============================================"
echo "DELTA=-1 FUNCTIONS WITH 1 DIFF"
echo "============================================"
for f in FUN_06018E70 FUN_0603B734 FUN_06042BEE; do
  analyze_func "$f"
done

echo ""
echo "============================================"
echo "DELTA=0 FUNCTIONS WITH 4 DIFFS"
echo "============================================"
for f in FUN_06005174 FUN_06018EC8 FUN_06019324 FUN_0603C0A0 FUN_0603F8B8; do
  analyze_func "$f"
done

rm -rf "$TMPDIR"
