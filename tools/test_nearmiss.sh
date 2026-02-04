#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/nearmiss_$$
mkdir -p "$TMPDIR"

test_func() {
    local base=$1
    local flags=$2
    local label=$3

    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    $CC1 -quiet $flags "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null
    tr -d '\r' < "$TMPDIR/$base.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/$base.ops"
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp"

    local our_count=$(wc -l < "$TMPDIR/$base.ops")
    local exp_count=$(wc -l < "$TMPDIR/$base.exp")

    echo "=== $base ($label) flags='$flags' ours=$our_count exp=$exp_count ==="
    if diff -q "$TMPDIR/$base.ops" "$TMPDIR/$base.exp" >/dev/null 2>&1; then
        echo "PASS"
    else
        diff --unified=0 "$TMPDIR/$base.exp" "$TMPDIR/$base.ops" | grep '^[+-][a-z]' | head -10
    fi
    echo ""
}

# Confirm FUN_060349B6 passes with -O2 -m2 (no -mbsr)
test_func "FUN_060349B6" "-O2 -m2" "no-bsr"

# Near-misses from BSR experiment
test_func "FUN_0600F870" "-O2 -m2" "no-bsr, 2 diffs expected"
test_func "FUN_06018E70" "-O2 -m2" "no-bsr, 1 diff expected"
test_func "FUN_06040964" "-O2 -m2" "no-bsr, 3 diffs expected"

# Also test bt.s vs bt+nop pattern functions with -mnofill
test_func "FUN_0602760C" "-O2 -m2 -mbsr -mnofill" "mnofill"
test_func "FUN_0602761E" "-O2 -m2 -mbsr -mnofill" "mnofill"
test_func "FUN_06027630" "-O2 -m2 -mbsr -mnofill" "mnofill"

# Show full asm for near-miss FUN_06018E70
echo "=== Full asm: FUN_06018E70 -O2 -m2 ==="
tr -d '\r' < "$SRCDIR/FUN_06018E70.c" > "$TMPDIR/FUN_06018E70.c"
$CC1 -quiet -O2 -m2 "$TMPDIR/FUN_06018E70.c" -o "$TMPDIR/FUN_06018E70_full.s" 2>/dev/null
cat "$TMPDIR/FUN_06018E70_full.s"

echo ""
echo "=== Full asm: FUN_0600F870 -O2 -m2 ==="
tr -d '\r' < "$SRCDIR/FUN_0600F870.c" > "$TMPDIR/FUN_0600F870.c"
$CC1 -quiet -O2 -m2 "$TMPDIR/FUN_0600F870.c" -o "$TMPDIR/FUN_0600F870_full.s" 2>/dev/null
cat "$TMPDIR/FUN_0600F870_full.s"

rm -rf "$TMPDIR"
