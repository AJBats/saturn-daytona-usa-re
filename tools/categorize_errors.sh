#!/bin/bash
# Categorize remaining compile errors after bulk fixes
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/errcat_$$
mkdir -p "$TMPDIR"

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    if ! "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>"$TMPDIR/$base.err"; then
        # Get the first non-warning, non-"In function" error line
        err=$(grep -v "warning:" "$TMPDIR/$base.err" | grep -v "In function" | grep -v "(Each undeclared" | grep -v "for each function" | head -1 | sed "s|$TMPDIR/||" | sed 's/.*\.c:[0-9]*: //')
        echo "$err"
    fi
done | sort | uniq -c | sort -rn | head -30

rm -rf "$TMPDIR"
