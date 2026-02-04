#!/bin/bash
# Count files that truly fail to compile (no .s produced)
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/real_errors_$$
mkdir -p "$TMPDIR"

total=0
compile_ok=0
compile_fail=0

for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && cfile="$TESTDIR/$base.c"
  [ ! -f "$cfile" ] && continue

  total=$((total + 1))
  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  if [ -f "$TMPDIR/$base.s" ]; then
    compile_ok=$((compile_ok + 1))
  else
    compile_fail=$((compile_fail + 1))
    # Show the actual error
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/${base}2.s" 2>&1)
    # Get first actual error line (not warning)
    first_err=$(echo "$errout" | grep -v warning | grep -m1 ":")
    if [ -z "$first_err" ]; then
      first_err=$(echo "$errout" | grep -m1 ":")
    fi
    echo "FAIL: $base  $first_err"
  fi
done

echo ""
echo "=== Summary ==="
echo "Total with .expected: $total"
echo "Compile OK: $compile_ok"
echo "Compile FAIL: $compile_fail"

rm -rf "$TMPDIR"
