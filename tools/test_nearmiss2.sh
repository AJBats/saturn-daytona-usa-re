#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/nearmiss2_$$
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
        echo "FAIL - diffs:"
        diff --unified=0 "$TMPDIR/$base.exp" "$TMPDIR/$base.ops" | grep '^[+-][a-z]' | head -10
    fi
    echo ""
}

# FUN_0600F870: try no-bsr + mnofill
test_func "FUN_0600F870" "-O2 -m2 -mnofill" "no-bsr, mnofill"

# FUN_0600F870: try no-bsr + mno-rts-fill
test_func "FUN_0600F870" "-O2 -m2 -mno-rts-fill" "no-bsr, no-rts-fill"

# FUN_0600F870: try no-bsr + mnofill + mno-rts-fill
test_func "FUN_0600F870" "-O2 -m2 -mnofill -mno-rts-fill" "no-bsr, mnofill, no-rts-fill"

# Now try a broad sweep: test each FAIL function with various flag combos
echo "=== BROAD SWEEP: testing all functions with -O2 -m2 -mnofill ==="
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    [ ! -f "$TDIR/$base.expected" ] && continue

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    tr -d '\r' < "$TDIR/$base.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/${base}_exp.ops"

    # Test with -O2 -m2 -mnofill (no bsr, unfill conditional branches)
    $CC1 -quiet -O2 -m2 -mnofill "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nf.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_nf.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_nf.ops"

    if diff -q "$TMPDIR/${base}_nf.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1; then
        echo "*** NEW PASS: $base with -O2 -m2 -mnofill"
    fi

    # Test with -O2 -m2 -mbsr -mnofill
    $CC1 -quiet -O2 -m2 -mbsr -mnofill "$TMPDIR/$base.c" -o "$TMPDIR/${base}_bf.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_bf.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_bf.ops"

    if diff -q "$TMPDIR/${base}_bf.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1; then
        echo "*** NEW PASS: $base with -O2 -m2 -mbsr -mnofill"
    fi

    # Test with -O2 -m2 -mnosignext
    $CC1 -quiet -O2 -m2 -mnosignext "$TMPDIR/$base.c" -o "$TMPDIR/${base}_ns.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_ns.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_ns.ops"

    if diff -q "$TMPDIR/${base}_ns.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1; then
        echo "*** NEW PASS: $base with -O2 -m2 -mnosignext"
    fi

    # Test with -O2 -m2 -mbsr -mnosignext
    $CC1 -quiet -O2 -m2 -mbsr -mnosignext "$TMPDIR/$base.c" -o "$TMPDIR/${base}_bs.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_bs.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_bs.ops"

    if diff -q "$TMPDIR/${base}_bs.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1; then
        echo "*** NEW PASS: $base with -O2 -m2 -mbsr -mnosignext"
    fi

    # Test with -O2 -m2 -mbsr -mno-bsr-fill
    $CC1 -quiet -O2 -m2 -mbsr -mno-bsr-fill "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nbf.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_nbf.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_nbf.ops"

    if diff -q "$TMPDIR/${base}_nbf.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1; then
        echo "*** NEW PASS: $base with -O2 -m2 -mbsr -mno-bsr-fill"
    fi

    # Test with -O2 -m2 -mbsr -mno-rts-fill
    $CC1 -quiet -O2 -m2 -mbsr -mno-rts-fill "$TMPDIR/$base.c" -o "$TMPDIR/${base}_nrf.s" 2>/dev/null || continue
    tr -d '\r' < "$TMPDIR/${base}_nrf.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//' > "$TMPDIR/${base}_nrf.ops"

    if diff -q "$TMPDIR/${base}_nrf.ops" "$TMPDIR/${base}_exp.ops" >/dev/null 2>&1; then
        echo "*** NEW PASS: $base with -O2 -m2 -mbsr -mno-rts-fill"
    fi
done

rm -rf "$TMPDIR"
echo ""
echo "=== SWEEP DONE ==="
