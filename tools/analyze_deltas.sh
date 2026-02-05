#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/delta_analysis_$$
mkdir -p "$TMPDIR"

for cfile in "$SRCDIR"/*.c; do
  base=$(basename "$cfile" .c)
  [ ! -f "$TESTDIR/$base.expected" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
  FLAGS="-O2 -m2 -mbsr"
  [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

  "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
  [ ! -f "$TMPDIR/$base.s" ] && continue

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" | sed 's/\t/ /g' | awk '{print $1}' > "$TMPDIR/$base.opc"
  tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opc" | tr -d ' ')
  orig=$(wc -l < "$TMPDIR/$base.exp" | tr -d ' ')

  if diff -q "$TMPDIR/$base.opc" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
    continue
  fi

  delta=$((ours - orig))
  diffs=$(diff "$TMPDIR/$base.opc" "$TMPDIR/$base.exp" | grep -c '^[<>]')
  echo "$delta $diffs $base"
done > "$TMPDIR/all_fails.txt"

echo "=== Total failures: $(wc -l < "$TMPDIR/all_fails.txt" | tr -d ' ') ==="
echo ""
echo "=== Delta distribution ==="
awk '{print $1}' "$TMPDIR/all_fails.txt" | sort -n | uniq -c | sort -k2 -n

echo ""
echo "=== Delta=0 functions (sorted by diff count, top 30) ==="
awk '$1 == 0' "$TMPDIR/all_fails.txt" | sort -t' ' -k2 -n | head -30

echo ""
echo "=== Delta=+1 functions (sorted by diff count, top 20) ==="
awk '$1 == 1' "$TMPDIR/all_fails.txt" | sort -t' ' -k2 -n | head -20

echo ""
echo "=== Delta=+2 functions (top 15) ==="
awk '$1 == 2' "$TMPDIR/all_fails.txt" | sort -t' ' -k2 -n | head -15

echo ""
echo "=== Delta=-1 functions (top 20) ==="
awk '$1 == -1' "$TMPDIR/all_fails.txt" | sort -t' ' -k2 -n | head -20

rm -rf "$TMPDIR"
