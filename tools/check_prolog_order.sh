#!/bin/bash
# Check how many delta=0 functions have sts.l ordering as the only difference
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/prolog_check_$$
mkdir -p "$TMPDIR"

sts_reorder=0
other_d0=0

for exp_file in "$TESTDIR"/*.expected; do
  base=$(basename "$exp_file" .expected)
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && cfile="$TESTDIR/$base.c"
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

  if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
    continue  # PASS
  fi

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if [ "$delta" -eq 0 ]; then
    ndiffs=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    if [ "$ndiffs" -le 4 ]; then
      # Check if sts.l is in the diff
      sts_in_diff=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c 'sts.l')
      if [ "$sts_in_diff" -gt 0 ]; then
        echo "STS_REORDER: $base (diffs=$ndiffs)"
        sts_reorder=$((sts_reorder + 1))
      else
        # Check if it's a mov/add reorder only
        diff_lines=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep '^[<>]' | sed 's/^[<>] //')
        echo "OTHER_D0: $base (diffs=$ndiffs) [$diff_lines]"
        other_d0=$((other_d0 + 1))
      fi
    fi
  fi
done

echo ""
echo "=== Summary ==="
echo "STS.L reorder: $sts_reorder"
echo "Other delta=0 (<=4 diffs): $other_d0"

rm -rf "$TMPDIR"
