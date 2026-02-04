#!/bin/bash
# BSR Experiment: Focused on delta=-1 and delta=-2 functions only
# For each: compile with BSR and without BSR, show detailed diff
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/bsr_exp_$$
mkdir -p "$TMPDIR"

extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

# Exact delta=-1 functions (from harness_results.txt)
DELTA1="FUN_060054EA FUN_0600D8A4 FUN_060149CC FUN_060149E0 FUN_06014A42 FUN_06018E70 FUN_060192B4 FUN_0602755C FUN_0603446C FUN_06034560 FUN_06035438 FUN_06038520 FUN_0603B734 FUN_0603B96A FUN_0603B9A4 FUN_0603BF5A FUN_0603EF54 FUN_0603EFD4 FUN_0603F1E0 FUN_0603F1F0 FUN_0603F216 FUN_0603F520 FUN_06040964 FUN_06041310 FUN_06042BBE FUN_06042BEE"

# Exact delta=-2 functions (from harness_results.txt)
DELTA2="FUN_06006838 FUN_0600A4AA FUN_0600A8BC FUN_06011678 FUN_0601476C FUN_060172E4 FUN_06020DEE FUN_0603307C FUN_06035C92 FUN_06038A48 FUN_060394C2 FUN_060394F0 FUN_0603A766 FUN_0603F202 FUN_0603FA00 FUN_06041330 FUN_0604188C FUN_06042BAC"

echo "================================================================"
echo "  BSR EXPERIMENT - delta=-1 and delta=-2 functions"
echo "================================================================"
echo ""

# Category arrays (space-separated strings)
CAT_PASS=""
CAT_IMPROVED=""
CAT_NOCHANGE=""
CAT_NOSRC=""

process_func() {
    local func="$1"
    local delta_type="$2"
    local cfile="$SRCDIR/$func.c"
    local expected="$TDIR/$func.expected"

    if [ ! -f "$cfile" ]; then
        echo "SKIP  $func  (no source file $cfile)"
        CAT_NOSRC="$CAT_NOSRC $func:nosrc"
        return
    fi
    if [ ! -f "$expected" ]; then
        echo "SKIP  $func  (no .expected file)"
        CAT_NOSRC="$CAT_NOSRC $func:noexp"
        return
    fi

    # Check for per-function flags
    local base_flags="-O2 -m2 -mbsr"
    if [ -f "$TDIR/$func.flags" ]; then
        base_flags=$(tr -d '\r' < "$TDIR/$func.flags")
    fi

    # Strip CRLF from source
    tr -d '\r' < "$cfile" > "$TMPDIR/$func.c"

    # Normalize expected
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$func.exp"
    local exp_count=$(wc -l < "$TMPDIR/$func.exp")

    # Compile WITH BSR (current default)
    if ! $CC1 -quiet $base_flags "$TMPDIR/$func.c" -o "$TMPDIR/$func.bsr.s" 2>/dev/null; then
        echo "ERROR $func  (compile failed with BSR)"
        CAT_NOSRC="$CAT_NOSRC $func:err"
        return
    fi
    extract_opcodes "$TMPDIR/$func.bsr.s" > "$TMPDIR/$func.bsr.ops"
    local bsr_count=$(wc -l < "$TMPDIR/$func.bsr.ops")

    # Compile WITHOUT BSR
    local nobsr_flags=$(echo "$base_flags" | sed 's/-mbsr//')
    if ! $CC1 -quiet $nobsr_flags "$TMPDIR/$func.c" -o "$TMPDIR/$func.nobsr.s" 2>/dev/null; then
        echo "ERROR $func  (compile failed without BSR)"
        CAT_NOSRC="$CAT_NOSRC $func:err"
        return
    fi
    extract_opcodes "$TMPDIR/$func.nobsr.s" > "$TMPDIR/$func.nobsr.ops"
    local nobsr_count=$(wc -l < "$TMPDIR/$func.nobsr.ops")

    local bsr_delta=$((bsr_count - exp_count))
    local nobsr_delta=$((nobsr_count - exp_count))

    # Count BSR/JSR/BRA usage
    local bsr_uses=$(grep -c '^bsr$' "$TMPDIR/$func.bsr.ops" || true)
    local jsr_bsr=$(grep -c '^jsr$' "$TMPDIR/$func.bsr.ops" || true)
    local bra_bsr=$(grep -c '^bra$' "$TMPDIR/$func.bsr.ops" || true)
    local nobsr_jsr=$(grep -c '^jsr$' "$TMPDIR/$func.nobsr.ops" || true)
    local bra_nobsr=$(grep -c '^bra$' "$TMPDIR/$func.nobsr.ops" || true)

    # Check exp uses jsr or bsr
    local exp_jsr=$(grep -c '^jsr$' "$TMPDIR/$func.exp" || true)
    local exp_bsr=$(grep -c '^bsr$' "$TMPDIR/$func.exp" || true)
    local exp_bra=$(grep -c '^bra$' "$TMPDIR/$func.exp" || true)

    # Check if nobsr matches expected
    local nobsr_match="FAIL"
    diff -q "$TMPDIR/$func.nobsr.ops" "$TMPDIR/$func.exp" >/dev/null 2>&1 && nobsr_match="PASS"

    local bsr_match="FAIL"
    diff -q "$TMPDIR/$func.bsr.ops" "$TMPDIR/$func.exp" >/dev/null 2>&1 && bsr_match="PASS"

    # Whether BSR/noBSR outputs differ
    local outputs_same="no"
    diff -q "$TMPDIR/$func.bsr.ops" "$TMPDIR/$func.nobsr.ops" >/dev/null 2>&1 && outputs_same="yes"

    echo "--- $func  ($delta_type) ---"
    echo "    flags_used: $base_flags"
    echo "    counts: bsr=$bsr_count nobsr=$nobsr_count exp=$exp_count"
    echo "    deltas: bsr_d=$bsr_delta nobsr_d=$nobsr_delta"
    echo "    calls:  BSR=$bsr_uses JSR(bsr)=$jsr_bsr BRA(bsr)=$bra_bsr | JSR(nobsr)=$nobsr_jsr BRA(nobsr)=$bra_nobsr"
    echo "    expected: JSR=$exp_jsr BSR=$exp_bsr BRA=$exp_bra"
    echo "    outputs_identical=$outputs_same"

    if [ "$nobsr_match" = "PASS" ]; then
        echo "    RESULT: *** PASS with no-BSR ***"
        CAT_PASS="$CAT_PASS $func"
    elif [ "$outputs_same" = "yes" ]; then
        echo "    RESULT: NO CHANGE (BSR not the issue)"
        CAT_NOCHANGE="$CAT_NOCHANGE $func"
    else
        # Check if nobsr is closer
        local bsr_diffs=$(diff "$TMPDIR/$func.bsr.ops" "$TMPDIR/$func.exp" 2>/dev/null | grep -c '^[<>]' || true)
        local nobsr_diffs=$(diff "$TMPDIR/$func.nobsr.ops" "$TMPDIR/$func.exp" 2>/dev/null | grep -c '^[<>]' || true)

        if [ "$nobsr_diffs" -lt "$bsr_diffs" ]; then
            echo "    RESULT: IMPROVED (diffs $bsr_diffs -> $nobsr_diffs)"
            echo "    remaining diffs (no-BSR vs expected):"
            diff --unified=1 "$TMPDIR/$func.exp" "$TMPDIR/$func.nobsr.ops" 2>/dev/null | grep '^[+-][a-z]' | head -10 | while read line; do
                echo "      $line"
            done
            CAT_IMPROVED="$CAT_IMPROVED $func"
        elif [ "$nobsr_diffs" -gt "$bsr_diffs" ]; then
            echo "    RESULT: WORSE without BSR (diffs $bsr_diffs -> $nobsr_diffs)"
            CAT_NOCHANGE="$CAT_NOCHANGE $func"
        else
            echo "    RESULT: DIFFERENT but same distance (diffs=$bsr_diffs)"
            CAT_NOCHANGE="$CAT_NOCHANGE $func"
        fi
    fi

    # Show BSR vs expected diff (brief) if not pass
    if [ "$nobsr_match" != "PASS" ] && [ "$bsr_match" != "PASS" ]; then
        echo "    bsr-vs-expected diff:"
        diff --unified=1 "$TMPDIR/$func.exp" "$TMPDIR/$func.bsr.ops" 2>/dev/null | grep '^[+-][a-z]' | head -10 | while read line; do
            echo "      $line"
        done
    fi

    echo ""
}

echo "======================== DELTA=-1 ========================"
echo ""
for func in $DELTA1; do
    process_func "$func" "delta=-1"
done

echo ""
echo "======================== DELTA=-2 ========================"
echo ""
for func in $DELTA2; do
    process_func "$func" "delta=-2"
done

echo ""
echo "================================================================"
echo "  SUMMARY"
echo "================================================================"
echo ""
echo "PASS with no-BSR (need .flags '-O2 -m2'):"
for f in $CAT_PASS; do echo "  $f"; done
[ -z "$CAT_PASS" ] && echo "  (none)"
echo ""
echo "IMPROVED with no-BSR (closer but not matching):"
for f in $CAT_IMPROVED; do echo "  $f"; done
[ -z "$CAT_IMPROVED" ] && echo "  (none)"
echo ""
echo "NO CHANGE / BSR not the issue:"
for f in $CAT_NOCHANGE; do echo "  $f"; done
[ -z "$CAT_NOCHANGE" ] && echo "  (none)"
echo ""
echo "SKIPPED / ERRORS:"
for f in $CAT_NOSRC; do echo "  $f"; done
[ -z "$CAT_NOSRC" ] && echo "  (none)"

rm -rf "$TMPDIR"
