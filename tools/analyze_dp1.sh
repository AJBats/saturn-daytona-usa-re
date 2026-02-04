#!/bin/bash
# Analyze delta=+1 functions to find removable extra instructions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/dp1_analyze_$$
mkdir -p "$TMPDIR"

echo "=== All delta=+1 functions ==="
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

  grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full"
  sed 's/\t/ /g' < "$TMPDIR/$base.full" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
  tr -d '\r' < "$exp_file" > "$TMPDIR/$base.exp"

  ours=$(wc -l < "$TMPDIR/$base.opcodes")
  orig=$(wc -l < "$TMPDIR/$base.exp")
  delta=$((ours - orig))

  if [ "$delta" -eq 1 ]; then
    ndiffs=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')
    echo ""
    echo "=== $base (ours=$ours orig=$orig diffs=$ndiffs) ==="
    echo "FLAGS: $FLAGS"
    echo "--- Opcode diff ---"
    diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
    if [ "$ndiffs" -le 5 ]; then
      echo "--- Our full asm ---"
      cat -n "$TMPDIR/$base.full"
    fi
  fi
done

rm -rf "$TMPDIR"
