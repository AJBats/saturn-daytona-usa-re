#!/bin/bash
# Test hypothesis: -fno-schedule-insns2 fixes scheduling-diff functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/sched_test_$$
mkdir -p "$TMPDIR"

# Test all delta=0 2-diff functions plus some 4-diff ones
FUNCS="FUN_0601164A FUN_060192CA FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_060285E0 FUN_06028600 FUN_06035C80 FUN_0603C05C FUN_0603F3DA FUN_0603F4CC FUN_06040954 FUN_06005174 FUN_06018EC8 FUN_06019324 FUN_0603C0A0 FUN_0603F8B8"

echo "=== Testing with -fno-schedule-insns2 ==="
for base in $FUNCS; do
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && { cfile="$TESTDIR/$base.c"; }
  [ ! -f "$cfile" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  # Compile with -fno-schedule-insns2
  FLAGS_NOSCHED="$FLAGS -fno-schedule-insns2"
  "$CC1" -quiet $FLAGS_NOSCHED "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nosched.s" 2>/dev/null
  [ ! -f "$TMPDIR/${base}_nosched.s" ] && { echo "  $base: compile error with -fno-schedule-insns2"; continue; }

  # Also compile normally for comparison
  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/${base}_normal.s" 2>/dev/null

  # Extract opcodes
  grep -P '^\t[a-z]' "$TMPDIR/${base}_nosched.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_nosched.opcodes"
  grep -P '^\t[a-z]' "$TMPDIR/${base}_normal.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_normal.opcodes"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  normal_ours=$(wc -l < "$TMPDIR/${base}_normal.opcodes")
  nosched_ours=$(wc -l < "$TMPDIR/${base}_nosched.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")

  normal_match="FAIL"
  nosched_match="FAIL"
  diff -q "$TMPDIR/${base}_normal.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1 && normal_match="PASS"
  diff -q "$TMPDIR/${base}_nosched.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1 && nosched_match="PASS"

  normal_ndiff=$(diff "$TMPDIR/${base}_normal.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
  nosched_ndiff=$(diff "$TMPDIR/${base}_nosched.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')

  status=""
  if [ "$nosched_match" = "PASS" ] && [ "$normal_match" = "FAIL" ]; then
    status="*** FIXED by -fno-schedule-insns2 ***"
  elif [ "$nosched_ndiff" -lt "$normal_ndiff" ]; then
    status="improved ($normal_ndiff -> $nosched_ndiff diffs)"
  elif [ "$nosched_ndiff" -gt "$normal_ndiff" ]; then
    status="WORSE ($normal_ndiff -> $nosched_ndiff diffs)"
  else
    status="unchanged ($normal_ndiff diffs)"
  fi

  echo "  $base: normal=$normal_match($normal_ndiff) nosched=$nosched_match($nosched_ndiff) $status"
done

echo ""
echo "=== Now testing ALL currently-PASS functions for regression ==="
# Check a sample of PASS functions don't regress
pass_funcs=$(grep "^PASS" /dev/stdin 2>/dev/null || true)

# Actually let's test all .expected files
pass_count=0
regress_count=0
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

  # Normal compile
  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/${base}_n.s" 2>/dev/null
  [ ! -f "$TMPDIR/${base}_n.s" ] && continue

  grep -P '^\t[a-z]' "$TMPDIR/${base}_n.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_n.opc"
  tr -d '\r' < "$exp_file" > "$TMPDIR/$base.exp"

  if diff -q "$TMPDIR/${base}_n.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
    # This is a PASS function - check if -fno-schedule-insns2 breaks it
    FLAGS_NOSCHED="$FLAGS -fno-schedule-insns2"
    "$CC1" -quiet $FLAGS_NOSCHED "$TMPDIR/$base.c" -o "$TMPDIR/${base}_ns.s" 2>/dev/null
    if [ -f "$TMPDIR/${base}_ns.s" ]; then
      grep -P '^\t[a-z]' "$TMPDIR/${base}_ns.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/${base}_ns.opc"
      if ! diff -q "$TMPDIR/${base}_ns.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
        echo "  REGRESSION: $base"
        regress_count=$((regress_count + 1))
      fi
    fi
    pass_count=$((pass_count + 1))
  fi
done

echo "  Checked $pass_count PASS functions, $regress_count regressions"

rm -rf "$TMPDIR"
