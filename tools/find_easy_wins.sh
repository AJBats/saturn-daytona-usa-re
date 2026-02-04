#!/bin/bash
# Find delta=0 and delta=+1 functions with fewest opcode diffs
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/wins_$$
mkdir -p "$TMPDIR"

echo "=== DELTA=0 FUNCTIONS (sorted by diff count) ==="
for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
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

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" > /dev/null 2>&1; then
    continue  # already PASS
  fi

  if [ "$delta" -eq 0 ]; then
    ndiff=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    echo "$ndiff $base (size=$ours)"
  fi
done | sort -n | head -30

echo ""
echo "=== DELTA=+1 FUNCTIONS (sorted by diff count) ==="
for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
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

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if [ "$delta" -eq 1 ]; then
    ndiff=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    echo "$ndiff $base (ours=$ours orig=$orig)"
  fi
done | sort -n | head -30

echo ""
echo "=== DELTA=-1 FUNCTIONS (sorted by diff count) ==="
for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
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

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if [ "$delta" -eq -1 ]; then
    ndiff=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    echo "$ndiff $base (ours=$ours orig=$orig)"
  fi
done | sort -n | head -30

rm -rf "$TMPDIR"
