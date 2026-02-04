#!/bin/bash
# Analyze delta=+1 functions with 3 diffs - best candidates for new PASS
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/dp1_$$
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

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full"
  sed 's/\t/ /g' < "$TMPDIR/$base.full" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  echo "=== $base (ours=$ours orig=$orig delta=$delta) ==="
  echo "FLAGS: $FLAGS"
  echo "--- Opcode diff ---"
  diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
  echo "--- Our full asm ---"
  cat -n "$TMPDIR/$base.full"
  echo ""
}

echo "============================================"
echo "DELTA=+1 FUNCTIONS WITH 3 DIFFS"
echo "============================================"
for f in FUN_060148FC FUN_0601492C FUN_06014994; do
  analyze_func "$f"
done

echo ""
echo "============================================"
echo "DELTA=-1 FUNCTIONS WITH 1 DIFF (root cause)"
echo "============================================"
for f in FUN_06018E70 FUN_0603B734 FUN_06042BEE; do
  analyze_func "$f"
  # Check if the missing insn is related to BSR
  echo "--- Expected opcodes ---"
  tr -d '\r' < "$TESTDIR/$f.expected"
  echo ""
done

echo ""
echo "============================================"
echo "DELTA=-1 WITH 3 DIFFS (root cause)"
echo "============================================"
for f in FUN_060054EA FUN_06014A42 FUN_0602755C FUN_06035C08 FUN_06038520 FUN_0603EF54 FUN_0603F1F0 FUN_0603F520 FUN_06040964 FUN_06042BBE; do
  analyze_func "$f"
done

rm -rf "$TMPDIR"
