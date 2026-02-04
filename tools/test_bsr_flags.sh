#!/bin/bash
# Test per-function flag effects on BSR-affected functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

test_function() {
    local name="$1"
    local flags="$2"
    local label="$3"

    tr -d '\r' < "$SRCDIR/$name.c" > /tmp/test_func.c
    $CC1 -quiet $flags /tmp/test_func.c -o /tmp/test_func.s 2>/dev/null
    echo "=== $name ($label: $flags) ==="
    grep -P '^\t[a-z]' /tmp/test_func.s | awk '{print $1}' | sed 's/,$//'
}

compare_function() {
    local name="$1"

    echo "============================================================"
    echo "Testing: $name"
    echo "============================================================"

    # Compile with -mbsr
    tr -d '\r' < "$SRCDIR/$name.c" > /tmp/test_func.c
    $CC1 -quiet -O2 -m2 -mbsr /tmp/test_func.c -o /tmp/test_bsr.s 2>/dev/null
    grep -P '^\t[a-z]' /tmp/test_bsr.s | awk '{print $1}' | sed 's/,$//' > /tmp/ours_bsr.txt

    # Compile without -mbsr
    $CC1 -quiet -O2 -m2 /tmp/test_func.c -o /tmp/test_nobsr.s 2>/dev/null
    grep -P '^\t[a-z]' /tmp/test_nobsr.s | awk '{print $1}' | sed 's/,$//' > /tmp/ours_nobsr.txt

    # Expected
    tr -d '\r' < "$TDIR/$name.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > /tmp/expected_clean.txt

    echo ""
    echo "--- With -mbsr ($(wc -l < /tmp/ours_bsr.txt) insns) ---"
    cat /tmp/ours_bsr.txt
    echo ""

    echo "--- Without -mbsr ($(wc -l < /tmp/ours_nobsr.txt) insns) ---"
    cat /tmp/ours_nobsr.txt
    echo ""

    echo "--- Expected ($(wc -l < /tmp/expected_clean.txt) insns) ---"
    cat /tmp/expected_clean.txt
    echo ""

    # Check matches
    if diff -q /tmp/ours_bsr.txt /tmp/expected_clean.txt > /dev/null 2>&1; then
        echo ">>> MATCH with -mbsr!"
    elif diff -q /tmp/ours_nobsr.txt /tmp/expected_clean.txt > /dev/null 2>&1; then
        echo ">>> MATCH without -mbsr!"
    else
        echo ">>> No match. Diffs vs expected:"
        echo "  With -mbsr:"
        diff /tmp/ours_bsr.txt /tmp/expected_clean.txt 2>/dev/null | head -6
        echo "  Without -mbsr:"
        diff /tmp/ours_nobsr.txt /tmp/expected_clean.txt 2>/dev/null | head -6
    fi
    echo ""
}

# Test all BSR-affected functions
echo "Testing BSR-affected functions with -mbsr vs -O2 -m2 only"
echo ""

for func in FUN_0601FD20 FUN_06041180 FUN_060210F6 FUN_06009E02 FUN_0600A4AA FUN_06041330; do
    if [ -f "$SRCDIR/$func.c" ] && [ -f "$TDIR/$func.expected" ]; then
        compare_function "$func"
    else
        echo "SKIP $func (missing source or expected)"
    fi
done

# Also test tail-call affected functions
echo ""
echo "============================================================"
echo "Testing tail-call affected functions"
echo "============================================================"

for func in FUN_06014A42; do
    if [ -f "$SRCDIR/$func.c" ] && [ -f "$TDIR/$func.expected" ]; then
        compare_function "$func"
    fi
done
