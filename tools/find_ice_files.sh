#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/ice_check_$$
mkdir -p "$TMPDIR"

ice_count=0
ok_count=0
err_count=0

for cfile in "$SRCDIR"/*.c; do
  base=$(basename "$cfile" .c)
  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  ffile="/mnt/d/Projects/SaturnReverseTest/tests/$base.flags"
  if [ -f "$ffile" ]; then
    FLAGS=$(tr -d '\r' < "$ffile")
  fi
  result=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
  if echo "$result" | grep -q "internal"; then
    echo "ICE: $base"
    ice_count=$((ice_count + 1))
  elif echo "$result" | grep -v "warning:" | grep -q "error\|parse error\|undeclared\|invalid\|subscript"; then
    err_count=$((err_count + 1))
  else
    ok_count=$((ok_count + 1))
  fi
done

echo ""
echo "=== SUMMARY ==="
echo "Compile OK: $ok_count"
echo "ICE crash:  $ice_count"
echo "Other err:  $err_count"
echo "Total:      $((ok_count + ice_count + err_count))"

rm -rf "$TMPDIR"
