#!/bin/bash
# Automated test harness for compiler verification
# Compiles C source files, extracts opcode mnemonics, compares against expected
# Usage: Run in WSL with: MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash tools/test_harness.sh
set -e

# Auto-detect project directory from script location
PROJDIR="$(cd "$(dirname "$0")/.." && pwd)"
CC1=$PROJDIR/tools/gcc26-build/cc1
SRCDIR=$PROJDIR/src
TESTDIR=$PROJDIR/tests
TMPDIR=/tmp/harness_$$
mkdir -p "$TMPDIR"

PASS=0
FAIL=0
TOTAL=0

# Extract opcode mnemonics from GCC .s output (one per line)
# Filters out directives, labels, constant pool entries, comments
# Uses tr -d '\r' to handle CRLF from Windows filesystem
extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

# Compare two opcode files and report result
compare_opcodes() {
    local name="$1"
    local actual="$2"
    local expected="$3"

    local our_count=$(wc -l < "$actual")
    local exp_count=$(wc -l < "$expected")

    TOTAL=$((TOTAL + 1))

    if diff -q "$actual" "$expected" > /dev/null 2>&1; then
        echo "PASS  $name  ($our_count insns)"
        PASS=$((PASS + 1))
    else
        echo "FAIL  $name  (ours=$our_count orig=$exp_count delta=$((our_count - exp_count)))"
        # Show first 3 differences
        diff --unified=0 "$expected" "$actual" 2>/dev/null | grep '^[+-][a-z]' | head -6 | while read line; do
            echo "      $line"
        done
        FAIL=$((FAIL + 1))
    fi
}

echo "================================================================"
echo "  Compiler Verification Test Harness"
echo "  CC1: $CC1"
echo "  Source: $SRCDIR"
echo "  Tests: $TESTDIR"
echo "================================================================"
echo ""

# Find all test cases (each src/*.c with a matching tests/*.expected file)
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"

    if [ ! -f "$expected" ]; then
        echo "SKIP  $base  (no .expected file)"
        continue
    fi

    # Determine compiler flags (per-function .flags file overrides default)
    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TESTDIR/$base.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")
    fi

    # Compile (strip CRLF from source first)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    if ! $CC1 -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>"$TMPDIR/$base.err"; then
        echo "FAIL  $base  (compile error)"
        head -3 "$TMPDIR/$base.err" | while read line; do
            echo "      $line"
        done
        FAIL=$((FAIL + 1))
        TOTAL=$((TOTAL + 1))
        continue
    fi

    # Extract opcodes from our output
    extract_opcodes "$TMPDIR/$base.s" > "$TMPDIR/$base.opcodes"

    # Normalize expected (strip CRLF, blank lines, and bf/s→bf.s notation)
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

    # Compare
    compare_opcodes "$base" "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean"
done

echo ""
echo "================================================================"
echo "  Results: $PASS PASS / $FAIL FAIL / $TOTAL total"
echo "  Pass rate: $(( (PASS * 100) / (TOTAL > 0 ? TOTAL : 1) ))%"
echo "================================================================"

# Cleanup
rm -rf "$TMPDIR"

# Exit with failure if any tests failed (useful for scripting)
[ "$FAIL" -eq 0 ]
