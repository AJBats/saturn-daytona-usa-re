#!/bin/bash
# Analyze the closest-to-matching functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/close_fails_$$
mkdir -p "$TMPDIR"

analyze_func() {
  local base="$1"
  local cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && return

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && return

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' > "$TMPDIR/$base.full"
  awk '{print $1}' "$TMPDIR/$base.full" > "$TMPDIR/$base.opc"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  local ours=$(wc -l < "$TMPDIR/$base.opc" | tr -d ' ')
  local orig=$(wc -l < "$TMPDIR/$base.exp" | tr -d ' ')
  local delta=$((ours - orig))

  echo "=== $base (delta=$delta, ours=$ours, orig=$orig) ==="
  echo "  Opcode diff:"
  diff "$TMPDIR/$base.opc" "$TMPDIR/$base.exp" | head -20
  echo "  Our asm:"
  cat -n "$TMPDIR/$base.full"
  echo ""
}

echo "##############################"
echo "# DELTA=0, DIFFS=2 FUNCTIONS #"
echo "##############################"

for func in FUN_0601143E FUN_06011450 FUN_0601209E FUN_060192CA FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_060285E0 FUN_06028600 FUN_06035C80 FUN_0603C05C FUN_0603F3DA FUN_0603F4CC FUN_06040954; do
  analyze_func "$func"
done

echo "##############################"
echo "# DELTA=-1, DIFFS=1 FUNCTIONS#"
echo "##############################"

for func in FUN_06018E70 FUN_06019324 FUN_060337FC FUN_0603B734 FUN_06042BEE; do
  analyze_func "$func"
done

rm -rf "$TMPDIR"
