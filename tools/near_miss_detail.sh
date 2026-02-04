#!/bin/bash
# Detailed diff analysis for near-miss functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/nearmiss_$$
mkdir -p "$TMPDIR"

# Functions that got down to 1 diff with flags
declare -A BEST_FLAGS
BEST_FLAGS[FUN_0603850C]="-O2 -m2 -mnofill"
BEST_FLAGS[FUN_06038520]="-O2 -m2 -mnofill"

# Also check some that got to 3-4 diffs
BEST_FLAGS[FUN_06040680]="-O2 -m2 -mbsr -mnofill"
BEST_FLAGS[FUN_0603F8B8]="-O2 -m2 -mno-rts-fill"
BEST_FLAGS[FUN_06035C1C]="-O2 -m2 -mnofill"
BEST_FLAGS[FUN_06041310]="-O2 -m2 -mnofill"

for base in "${!BEST_FLAGS[@]}"; do
    flags="${BEST_FLAGS[$base]}"
    echo "=== $base with flags: $flags ==="

    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    $CC1 -quiet $flags "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null

    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/$base.opcodes"
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

    echo "Diff:"
    diff -u "$TMPDIR/$base.exp_clean" "$TMPDIR/$base.opcodes" | head -30
    echo ""

    echo "Full asm output:"
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]'
    echo ""
    echo "Expected:"
    cat "$TMPDIR/$base.exp_clean"
    echo ""
    echo "---"
    echo ""
done

rm -rf "$TMPDIR"
