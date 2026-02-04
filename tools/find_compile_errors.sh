#!/bin/bash
# Find all files that fail to compile and show their error messages
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/compile_errors_$$
mkdir -p "$TMPDIR"

echo "=== Files that fail to compile ==="
error_count=0
ice_count=0

for cfile in "$SRCDIR"/*.c; do
  base=$(basename "$cfile" .c)

  # Skip if no .expected file
  [ ! -f "$TESTDIR/$base.expected" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="$TESTDIR/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi

  errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>&1)
  exitcode=$?

  if [ $exitcode -ne 0 ] || [ ! -f "$TMPDIR/$base.s" ]; then
    if echo "$errout" | grep -q "Internal compiler error"; then
      echo "ICE: $base"
      echo "  $errout" | head -3
      ice_count=$((ice_count + 1))
    else
      echo "ERROR: $base"
      echo "  $errout" | head -5
      error_count=$((error_count + 1))
    fi
    echo ""
  fi
done

echo "=== Summary ==="
echo "Compile errors: $error_count"
echo "ICE crashes: $ice_count"
echo "Total: $((error_count + ice_count))"

rm -rf "$TMPDIR"
