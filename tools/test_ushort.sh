#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/ushort_$$
mkdir -p "$TMPDIR"

for base in FUN_0603850C FUN_06038520; do
    echo "=== $base ==="
    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    $CC1 -quiet -O2 -m2 -mnofill "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>&1

    echo "Our opcodes:"
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'

    echo "Expected:"
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'

    echo ""
    echo "Full asm:"
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]'
    echo ""
done

rm -rf "$TMPDIR"
