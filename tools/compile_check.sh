#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/compile_check_$$
mkdir -p "$TMPDIR"

PASS=0
FAIL=0
TOTAL=0

for cfile in "$TESTDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    TOTAL=$((TOTAL + 1))
    if $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>"$TMPDIR/$base.err"; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        ERR=$(head -1 "$TMPDIR/$base.err")
        echo "FAIL  $base  $ERR"
    fi
done

echo ""
echo "Compile check: $PASS OK / $FAIL errors / $TOTAL total"

rm -rf "$TMPDIR"
