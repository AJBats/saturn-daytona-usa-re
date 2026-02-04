#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/debug_$$
mkdir -p "$TMPDIR"

for base in FUN_060349B6 FUN_06033504; do
    echo "=== $base ==="
    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TDIR/$base.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")
        echo "Using flags from .flags file: [$FLAGS]"
    else
        echo "No .flags file found, using defaults: $FLAGS"
    fi

    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>&1

    echo "Our opcodes:"
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'

    echo "Expected:"
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'

    echo ""
done
rm -rf "$TMPDIR"
