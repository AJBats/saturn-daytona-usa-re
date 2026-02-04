#!/bin/bash
# Categorize all delta=-1 functions by root cause
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/catdm1_$$
mkdir -p "$TMPDIR"

bsr_count=0
bra_count=0
sched_count=0
other_count=0

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

  [ "$delta" -ne -1 ] && continue
  diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1 && continue

  # Check if our asm uses bsr (which original doesn't)
  has_bsr=$(grep -c '^	bsr' "$TMPDIR/$base.s" || true)
  # Check if our asm uses bra for tail call
  has_bra=$(grep -c '^	bra' "$TMPDIR/$base.s" || true)
  # Check if expected has jsr where we have bsr
  exp_jsr=$(grep -c '^jsr' "$TMPDIR/$base.exp" || true)
  our_bsr=$(grep -c '^bsr' "$TMPDIR/$base.opcodes" || true)
  exp_bsr=$(grep -c '^bsr' "$TMPDIR/$base.exp" || true)
  our_bra=$(grep -c '^bra' "$TMPDIR/$base.opcodes" || true)
  exp_bra=$(grep -c '^bra' "$TMPDIR/$base.exp" || true)
  exp_jmp=$(grep -c '^jmp' "$TMPDIR/$base.exp" || true)

  ndiff=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')

  # Categorize
  if [ "$our_bsr" -gt "$exp_bsr" ]; then
    echo "BSR  $base (ndiff=$ndiff, our_bsr=$our_bsr exp_bsr=$exp_bsr)"
    bsr_count=$((bsr_count + 1))
  elif [ "$our_bra" -gt "$exp_bra" ] && [ "$exp_jmp" -gt 0 ]; then
    echo "BRA  $base (ndiff=$ndiff, our_bra=$our_bra exp_bra=$exp_bra exp_jmp=$exp_jmp)"
    bra_count=$((bra_count + 1))
  elif [ "$ndiff" -le 2 ]; then
    echo "SCHED $base (ndiff=$ndiff)"
    sched_count=$((sched_count + 1))
  else
    echo "OTHER $base (ndiff=$ndiff)"
    # Show the diff for diagnosis
    diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | head -8
    other_count=$((other_count + 1))
  fi
done

echo ""
echo "=== SUMMARY ==="
echo "BSR (our bsr vs their jsr): $bsr_count"
echo "BRA tail call (our bra vs their jmp): $bra_count"
echo "Scheduling reorder: $sched_count"
echo "Other: $other_count"
echo "Total: $((bsr_count + bra_count + sched_count + other_count))"

rm -rf "$TMPDIR"
