#!/bin/bash
# Analyze delta=-1, 1-diff functions (we're 1 insn shorter)
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/dm1_1diff_$$
mkdir -p "$TMPDIR"

FUNCS="FUN_06018E70 FUN_06019324 FUN_0603B734 FUN_06042BEE"

for base in $FUNCS; do
  cfile="$SRCDIR/$base.c"
  [ ! -f "$cfile" ] && cfile="$TESTDIR/$base.c"
  [ ! -f "$cfile" ] && continue

  tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

  # Test with different flag combinations
  for flags_label in "default(-O2 -m2 -mbsr)" "no-bsr(-O2 -m2)"; do
    FLAGS=$(echo "$flags_label" | sed 's/.*(\(.*\))/\1/')
    label=$(echo "$flags_label" | sed 's/(.*//')

    "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
    [ ! -f "$TMPDIR/$base.s" ] && continue

    grep -P '^\t[a-z]' "$TMPDIR/$base.s" > "$TMPDIR/$base.full"
    sed 's/\t/ /g' < "$TMPDIR/$base.full" | awk '{print $1}' > "$TMPDIR/$base.opcodes"
    tr -d '\r' < "$TESTDIR/$base.expected" > "$TMPDIR/$base.exp"

    ours=$(wc -l < "$TMPDIR/$base.opcodes")
    orig=$(wc -l < "$TMPDIR/$base.exp")
    delta=$((ours - orig))
    ndiffs=$(diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" | grep -c '^[<>]')

    if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
      status="*** PASS ***"
    else
      status="FAIL"
    fi

    echo "=== $base [$label] delta=$delta diffs=$ndiffs $status ==="
    if [ "$status" != "*** PASS ***" ]; then
      echo "--- Opcode diff ---"
      diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp"
      echo "--- Our full asm ---"
      cat -n "$TMPDIR/$base.full"
    fi
    echo ""
  done
done

rm -rf "$TMPDIR"
