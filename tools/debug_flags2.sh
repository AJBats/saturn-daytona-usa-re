#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/debug2_$$
mkdir -p "$TMPDIR"

for base in FUN_060349B6 FUN_06033504; do
    echo "=== $base ==="
    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TDIR/$base.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TDIR/$base.flags")
    fi

    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null

    # Extract opcodes same way as harness
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/$base.opcodes"

    # Normalize expected same way as harness
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

    echo "Opcodes file (hexdump):"
    xxd "$TMPDIR/$base.opcodes" | tail -3
    echo "Expected file (hexdump):"
    xxd "$TMPDIR/$base.exp_clean" | tail -3

    echo "Opcodes line count: $(wc -l < "$TMPDIR/$base.opcodes")"
    echo "Expected line count: $(wc -l < "$TMPDIR/$base.exp_clean")"
    echo "Opcodes byte count: $(wc -c < "$TMPDIR/$base.opcodes")"
    echo "Expected byte count: $(wc -c < "$TMPDIR/$base.exp_clean")"

    echo "Diff result:"
    diff "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean"
    echo "Exit code: $?"
    echo ""
done
rm -rf "$TMPDIR"
