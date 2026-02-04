#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/nobsr_$$
mkdir -p "$TMPDIR"

# Test BSR-related delta=-1 functions with -mbsr removed
for base in FUN_06033AAC FUN_06034708; do
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && { echo "$base: NO C FILE"; continue; }

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  # With BSR (current)
  FLAGS_BSR="-O2 -m2 -mbsr"
  "$CC1" -quiet $FLAGS_BSR "$TMPDIR/$base.c" -o "$TMPDIR/${base}_bsr.s" 2>/dev/null
  grep -P '^\t[a-z]' "$TMPDIR/${base}_bsr.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_bsr.opc"
  bsr_match="FAIL"
  diff -q "$TMPDIR/${base}_bsr.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1 && bsr_match="PASS"
  bsr_ndiff=$(diff "$TMPDIR/${base}_bsr.opc" "$TMPDIR/$base.exp" | grep -c '^[<>]')
  bsr_delta=$(($(wc -l < "$TMPDIR/${base}_bsr.opc") - $(wc -l < "$TMPDIR/$base.exp")))

  # Without BSR
  FLAGS_NOBSR="-O2 -m2"
  "$CC1" -quiet $FLAGS_NOBSR "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nobsr.s" 2>/dev/null
  grep -P '^\t[a-z]' "$TMPDIR/${base}_nobsr.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_nobsr.opc"
  nobsr_match="FAIL"
  diff -q "$TMPDIR/${base}_nobsr.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1 && nobsr_match="PASS"
  nobsr_ndiff=$(diff "$TMPDIR/${base}_nobsr.opc" "$TMPDIR/$base.exp" | grep -c '^[<>]')
  nobsr_delta=$(($(wc -l < "$TMPDIR/${base}_nobsr.opc") - $(wc -l < "$TMPDIR/$base.exp")))

  echo "$base: bsr=$bsr_match(delta=$bsr_delta,ndiff=$bsr_ndiff) nobsr=$nobsr_match(delta=$nobsr_delta,ndiff=$nobsr_ndiff)"
  if [ "$nobsr_match" = "PASS" ]; then
    echo "  *** FIXED by removing -mbsr ***"
  elif [ "$nobsr_ndiff" -lt "$bsr_ndiff" ]; then
    echo "  improved ($bsr_ndiff -> $nobsr_ndiff diffs)"
  fi
done

echo ""
echo "=== BRA tail call functions ==="
# Test if removing -mbsr helps BRA tail call cases
for base in FUN_0600338C FUN_06014A42; do
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && { echo "$base: NO C FILE"; continue; }

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  for FLAGS in "-O2 -m2 -mbsr" "-O2 -m2" "-O2 -m2 -mbsr -fno-schedule-insns2"; do
    "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/${base}_test.s" 2>/dev/null
    grep -P '^\t[a-z]' "$TMPDIR/${base}_test.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_test.opc"
    match="FAIL"
    diff -q "$TMPDIR/${base}_test.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1 && match="PASS"
    ndiff=$(diff "$TMPDIR/${base}_test.opc" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    delta=$(($(wc -l < "$TMPDIR/${base}_test.opc") - $(wc -l < "$TMPDIR/$base.exp")))
    echo "  $base [$FLAGS]: $match (delta=$delta, ndiff=$ndiff)"
  done
done

rm -rf "$TMPDIR"
