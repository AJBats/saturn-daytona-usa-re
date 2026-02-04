#!/bin/bash
# Generate structured catalog data for all functions
# Output: TSV with columns: name, insns_ours, insns_orig, delta, status, error_category, diff_summary
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/catalog_$$
mkdir -p "$TMPDIR"

extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

# Header
echo -e "name\tinsns_ours\tinsns_orig\tdelta\tstatus\terror_cat\tdiff_summary\thand_tuned"

for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    expected="$TESTDIR/$base.expected"

    # Check if hand-tuned (has non-Ghidra patterns: no FUN_ in function def, or has manual comments history)
    hand_tuned="ghidra"
    if [ -f "$TESTDIR/$base.flags" ]; then
        hand_tuned="tuned"
    fi
    # Check git log for manual edits before the bulk generation commit
    first_commit=$(git -C /mnt/d/Projects/SaturnReverseTest log --diff-filter=A --format=%H -- "src/$base.c" 2>/dev/null | tail -1)
    if [ -n "$first_commit" ] && [ "$first_commit" != "6ba7c56" ] && [ "$first_commit" != "353bf01" ]; then
        hand_tuned="tuned"
    fi

    if [ ! -f "$expected" ]; then
        echo -e "$base\t-\t-\t-\tno_expected\t-\t-\t$hand_tuned"
        continue
    fi

    # Get expected insn count
    exp_count=$(tr -d '\r' < "$expected" | sed '/^$/d' | wc -l)

    FLAGS="-O2 -m2 -mbsr"
    if [ -f "$TESTDIR/$base.flags" ]; then
        FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")
    fi

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    # Compile
    if ! "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>"$TMPDIR/$base.err"; then
        # Categorize compile error
        err_msg=$(cat "$TMPDIR/$base.err" 2>/dev/null)
        error_cat="unknown"

        if echo "$err_msg" | grep -q "internal error\|Aborted\|core dump"; then
            error_cat="cc1_crash"
        elif echo "$err_msg" | grep -q "void value not ignored"; then
            error_cat="void_value"
        elif echo "$err_msg" | grep -q "called object is not a function"; then
            error_cat="not_function"
        elif echo "$err_msg" | grep -q "invalid type argument"; then
            error_cat="invalid_deref"
        elif echo "$err_msg" | grep -q "subscripted value"; then
            error_cat="bad_subscript"
        elif echo "$err_msg" | grep -q "parse error"; then
            error_cat="parse_error"
        elif echo "$err_msg" | grep -q "undeclared"; then
            error_cat="undeclared"
        elif echo "$err_msg" | grep -q "conflicting types\|previous declaration"; then
            error_cat="type_conflict"
        else
            error_cat="other"
        fi

        # Get first real error line
        first_err=$(grep -v "warning:" "$TMPDIR/$base.err" | grep -v "In function" | grep -v "(Each undecl" | grep -v "for each func" | head -1 | sed "s|$TMPDIR/||" | sed 's/.*\.c:[0-9]*: //' | tr '\t' ' ')
        echo -e "$base\t-\t$exp_count\t-\tcompile_error\t$error_cat\t$first_err\t$hand_tuned"
        continue
    fi

    # Extract and compare opcodes
    extract_opcodes "$TMPDIR/$base.s" > "$TMPDIR/$base.opcodes"
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

    our_count=$(wc -l < "$TMPDIR/$base.opcodes")
    delta=$((our_count - exp_count))

    if diff -q "$TMPDIR/$base.opcodes" "$TMPDIR/$base.exp_clean" > /dev/null 2>&1; then
        echo -e "$base\t$our_count\t$exp_count\t0\tPASS\t-\t-\t$hand_tuned"
    else
        # Get diff summary
        diff_lines=$(diff "$TMPDIR/$base.exp_clean" "$TMPDIR/$base.opcodes" 2>/dev/null | grep '^[<>]' | wc -l)

        # Classify the diff pattern
        diff_output=$(diff "$TMPDIR/$base.exp_clean" "$TMPDIR/$base.opcodes" 2>/dev/null | grep '^[<>]')
        diff_cat=""

        # Check for specific patterns in diffs
        if [ "$delta" -eq 0 ] && [ "$diff_lines" -eq 2 ]; then
            diff_cat="1-swap"
        elif [ "$delta" -eq 0 ] && [ "$diff_lines" -le 6 ]; then
            diff_cat="scheduling"
        elif echo "$diff_output" | grep -q "bsr\|jsr"; then
            diff_cat="call_encoding"
        elif echo "$diff_output" | grep -q "bf\.s\|bt\.s\|bf$\|bt$"; then
            diff_cat="delay_slot"
        elif echo "$diff_output" | grep -q "cmp/ge\|cmp/gt\|cmp/hi"; then
            diff_cat="comparison"
        elif echo "$diff_output" | grep -q "mul\|shll\|shlr\|mulu"; then
            diff_cat="multiply"
        elif echo "$diff_output" | grep -q "extu\|exts"; then
            diff_cat="sign_ext"
        elif echo "$diff_output" | grep -q "mov\.l\|mov\.w\|mov\.b"; then
            diff_cat="addressing"
        else
            diff_cat="mixed"
        fi

        echo -e "$base\t$our_count\t$exp_count\t$delta\tFAIL\t$diff_cat\t${diff_lines}_diffs\t$hand_tuned"
    fi
done

rm -rf "$TMPDIR"
