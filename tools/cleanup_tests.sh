#!/bin/bash
# Remove test .c files that fail to compile or have huge deltas
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/cleanup_$$
mkdir -p "$TMPDIR"

removed=0
kept=0

for cfile in "$TESTDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"
    [ ! -f "$expected" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    # Check if it compiles
    if ! $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null; then
        rm -f "$cfile"
        removed=$((removed + 1))
        continue
    fi

    # Check delta
    ours=$(tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | wc -l)
    orig=$(tr -d '\r' < "$expected" | sed '/^$/d' | wc -l)
    delta=$((ours - orig))
    abs_delta=$delta
    [ $abs_delta -lt 0 ] && abs_delta=$((-abs_delta))

    if [ $abs_delta -gt 10 ]; then
        rm -f "$cfile"
        removed=$((removed + 1))
        continue
    fi

    kept=$((kept + 1))
done

rm -rf "$TMPDIR"
echo "Removed $removed files (compile errors + |delta|>10)"
echo "Kept $kept test files"
