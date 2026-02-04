#!/bin/bash
# Quick compile-only count - doesn't compare opcodes, just counts compilable files
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/compile_count_$$
mkdir -p "$TMPDIR"

ok=0
fail=0
skip=0
total=0

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"

    if [ ! -f "$expected" ]; then
        skip=$((skip + 1))
        continue
    fi

    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TESTDIR/$base.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")
    fi

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    total=$((total + 1))

    if "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null; then
        ok=$((ok + 1))
    else
        fail=$((fail + 1))
    fi
done

echo "Compilable: $ok / $total (skip=$skip)"
echo "Errors: $fail"
rm -rf "$TMPDIR"
