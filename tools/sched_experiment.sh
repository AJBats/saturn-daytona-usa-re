#!/bin/bash
# Scheduling Experiment: Test -fno-schedule-insns2 effect on opcode matching
# Hypothesis: Post-reload scheduling may cause instruction reordering differences
# Usage: MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/sched_experiment.sh
set -e

PROJDIR="$(cd "$(dirname "$0")/.." && pwd)"
CC1=$PROJDIR/tools/gcc26-build/cc1
SRCDIR=$PROJDIR/src
TESTDIR=$PROJDIR/tests
TMPDIR=/tmp/sched_exp_$$
OUTFILE=$PROJDIR/docs/scheduling_experiment.md
mkdir -p "$TMPDIR"

DELTA0_FUNCS="FUN_06005174 FUN_0600C970 FUN_0600D12C FUN_06011494 FUN_0601164A FUN_060122F4 FUN_06018EC8 FUN_0601AB8C FUN_0601FD20 FUN_06026590 FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_0602760C FUN_0602761E FUN_06027630 FUN_060285E0 FUN_06028600 FUN_0602F71C FUN_06033520 FUN_06035C1C FUN_06035C80 FUN_0603B878 FUN_0603C05C FUN_0603C0A0 FUN_0603F3DA FUN_0603F4CC FUN_0603F4E0 FUN_0603F500 FUN_0603F8B8 FUN_06040954 FUN_06040E88 FUN_06041128"

PASS_FUNCS="FUN_060058FA FUN_0600D266 FUN_0600DE40 FUN_0600DE54 FUN_0600F870 FUN_06012E00 FUN_06012E62 FUN_06012E6A FUN_06012E7C FUN_06012E84 FUN_06012EBC FUN_06012EC4 FUN_06012EDC FUN_06012F00 FUN_06012F10 FUN_06012F20 FUN_06012F50 FUN_06012F58 FUN_06012F60 FUN_0601E0DE FUN_0601F8BC FUN_06026DF8 FUN_0602754C FUN_0602853E FUN_06028560 FUN_060322E8 FUN_06033504 FUN_060349B6 FUN_06035C48 FUN_06035C4E FUN_06035C6E FUN_0603850C FUN_0603F4B0 FUN_0603F92C FUN_0603F9F2 FUN_0603F9F6 FUN_060401E4 FUN_060409DE FUN_06041884"

DEFAULT_FLAGS="-O2 -m2 -mbsr"

extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

compile_func() {
    local base="$1" flags="$2" outsuffix="$3"
    tr -d '\r' < "$SRCDIR/$base.c" > "$TMPDIR/$base.c"
    if $CC1 -quiet $flags "$TMPDIR/$base.c" -o "$TMPDIR/${base}${outsuffix}.s" 2>"$TMPDIR/${base}${outsuffix}.err"; then
        extract_opcodes "$TMPDIR/${base}${outsuffix}.s" > "$TMPDIR/${base}${outsuffix}.opcodes"
        return 0
    else
        return 1
    fi
}

check_match() {
    local base="$1" outsuffix="$2"
    local opcodes="$TMPDIR/${base}${outsuffix}.opcodes"
    local expected="$TESTDIR/$base.expected"
    if [ ! -f "$expected" ]; then echo "SKIP"; return; fi
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/${base}${outsuffix}.exp_clean"
    if diff -q "$opcodes" "$TMPDIR/${base}${outsuffix}.exp_clean" > /dev/null 2>&1; then
        echo "PASS"
    else
        local our_count=$(wc -l < "$opcodes")
        local exp_count=$(wc -l < "$TMPDIR/${base}${outsuffix}.exp_clean")
        echo "FAIL(ours=$our_count,orig=$exp_count,delta=$((our_count - exp_count)))"
    fi
}

get_diff_summary() {
    if diff -q "$1" "$2" > /dev/null 2>&1; then echo "identical"
    else local c=$(diff "$1" "$2" 2>/dev/null | grep -c '^[<>]' || true); echo "${c}_lines_differ"
    fi
}

echo "================================================================"
echo "  Scheduling Experiment: -fno-schedule-insns2"
echo "  CC1: $CC1"
echo "================================================================"
echo ""

declare -a D0_NAMES D0_DEFAULT D0_NOSCHED D0_SCHED_DIFF
declare -a PA_NAMES PA_DEFAULT PA_NOSCHED PA_SCHED_DIFF

echo "--- Delta=0 Functions (looking for improvements) ---"
d0_idx=0; d0_improved=0; d0_regressed=0; d0_unchanged=0; d0_skip=0
for func in $DELTA0_FUNCS; do
    if [ ! -f "$SRCDIR/$func.c" ]; then echo "SKIP  $func  (no source)"; d0_skip=$((d0_skip+1)); continue; fi
    if [ ! -f "$TESTDIR/$func.expected" ]; then echo "SKIP  $func  (no .expected)"; d0_skip=$((d0_skip+1)); continue; fi
    FLAGS="$DEFAULT_FLAGS"
    [ -f "$TESTDIR/$func.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$func.flags")
    if ! compile_func "$func" "$FLAGS" "_default"; then echo "ERR   $func  (compile err default)"; continue; fi
    if ! compile_func "$func" "$FLAGS -fno-schedule-insns2" "_nosched"; then echo "ERR   $func  (compile err nosched)"; continue; fi
    dr=$(check_match "$func" "_default"); nr=$(check_match "$func" "_nosched")
    sd=$(get_diff_summary "$TMPDIR/${func}_default.opcodes" "$TMPDIR/${func}_nosched.opcodes")
    D0_NAMES[$d0_idx]="$func"; D0_DEFAULT[$d0_idx]="$dr"; D0_NOSCHED[$d0_idx]="$nr"; D0_SCHED_DIFF[$d0_idx]="$sd"
    st=""
    if [ "$dr" != "PASS" ] && [ "$nr" = "PASS" ]; then st="IMPROVED"; d0_improved=$((d0_improved+1))
    elif [ "$dr" = "PASS" ] && [ "$nr" != "PASS" ]; then st="REGRESSED"; d0_regressed=$((d0_regressed+1))
    else st="unchanged"; d0_unchanged=$((d0_unchanged+1)); fi
    printf "%-20s default=%-35s nosched=%-35s sched_diff=%-20s %s\n" "$func" "$dr" "$nr" "$sd" "$st"
    d0_idx=$((d0_idx+1))
done

echo ""
echo "--- Currently-Passing Functions (regression check) ---"
pa_idx=0; pa_regressed=0; pa_still_pass=0; pa_skip=0
for func in $PASS_FUNCS; do
    if [ ! -f "$SRCDIR/$func.c" ]; then echo "SKIP  $func  (no source)"; pa_skip=$((pa_skip+1)); continue; fi
    if [ ! -f "$TESTDIR/$func.expected" ]; then echo "SKIP  $func  (no .expected)"; pa_skip=$((pa_skip+1)); continue; fi
    FLAGS="$DEFAULT_FLAGS"
    [ -f "$TESTDIR/$func.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$func.flags")
    if ! compile_func "$func" "$FLAGS" "_default"; then echo "ERR   $func  (compile err default)"; continue; fi
    if ! compile_func "$func" "$FLAGS -fno-schedule-insns2" "_nosched"; then echo "ERR   $func  (compile err nosched)"; continue; fi
    dr=$(check_match "$func" "_default"); nr=$(check_match "$func" "_nosched")
    sd=$(get_diff_summary "$TMPDIR/${func}_default.opcodes" "$TMPDIR/${func}_nosched.opcodes")
    PA_NAMES[$pa_idx]="$func"; PA_DEFAULT[$pa_idx]="$dr"; PA_NOSCHED[$pa_idx]="$nr"; PA_SCHED_DIFF[$pa_idx]="$sd"
    st=""
    if [ "$dr" = "PASS" ] && [ "$nr" != "PASS" ]; then st="REGRESSED"; pa_regressed=$((pa_regressed+1))
    elif [ "$dr" = "PASS" ] && [ "$nr" = "PASS" ]; then st="still_pass"; pa_still_pass=$((pa_still_pass+1))
    else st="other"; fi
    printf "%-20s default=%-35s nosched=%-35s sched_diff=%-20s %s\n" "$func" "$dr" "$nr" "$sd" "$st"
    pa_idx=$((pa_idx+1))
done

echo ""
echo "================================================================"
echo "  SUMMARY"
echo "================================================================"
echo "Delta=0 ($d0_idx tested, $d0_skip skipped): improved=$d0_improved unchanged=$d0_unchanged regressed=$d0_regressed"
echo "Passing ($pa_idx tested, $pa_skip skipped): still_pass=$pa_still_pass regressed=$pa_regressed"
echo ""

# --- Generate Markdown Report ---
exec 3>"$OUTFILE"
echo "# Scheduling Experiment: -fno-schedule-insns2" >&3
echo "" >&3
echo "**Date**: $(date +%Y-%m-%d)" >&3
echo "**Hypothesis**: Post-reload instruction scheduling (\`-fno-schedule-insns2\`) may be causing instruction reordering differences between our compiler output and the original binary." >&3
echo "" >&3
echo "**Method**: For each test function, compile with two flag sets:" >&3
echo "1. **Default**: per-function flags (typically \`-O2 -m2 -mbsr\`)" >&3
echo "2. **No-sched2**: same flags + \`-fno-schedule-insns2\`" >&3
echo "" >&3
echo "Compare each output against \`tests/FUNC.expected\` (original binary opcodes)." >&3
echo "" >&3
echo "## Summary" >&3
echo "" >&3
echo "### Delta=0 Functions ($d0_idx tested, $d0_skip skipped)" >&3
echo "" >&3
echo "| Metric | Count |" >&3
echo "|--------|-------|" >&3
echo "| Improved (FAIL -> PASS) | $d0_improved |" >&3
echo "| Unchanged | $d0_unchanged |" >&3
echo "| Regressed (PASS -> FAIL) | $d0_regressed |" >&3
echo "" >&3
echo "### Currently-Passing Functions ($pa_idx tested, $pa_skip skipped)" >&3
echo "" >&3
echo "| Metric | Count |" >&3
echo "|--------|-------|" >&3
echo "| Still passing | $pa_still_pass |" >&3
echo "| Regressed | $pa_regressed |" >&3
echo "" >&3
echo "## Detailed Results: Delta=0 Functions" >&3
echo "" >&3
echo "| Function | Default | No-sched2 | Sched Changed? | Verdict |" >&3
echo "|----------|---------|-----------|----------------|---------|" >&3

for ((i=0; i<d0_idx; i++)); do
    f="${D0_NAMES[$i]}"; d="${D0_DEFAULT[$i]}"; n="${D0_NOSCHED[$i]}"; s="${D0_SCHED_DIFF[$i]}"
    v=""
    if [ "$d" != "PASS" ] && [ "$n" = "PASS" ]; then v="IMPROVED"
    elif [ "$d" = "PASS" ] && [ "$n" != "PASS" ]; then v="REGRESSED"
    elif [ "$s" = "identical" ]; then v="no effect"
    else v="changed but still fails"; fi
    echo "| $f | $d | $n | $s | $v |" >&3
done

echo "" >&3
echo "## Detailed Results: Currently-Passing Functions" >&3
echo "" >&3
echo "| Function | Default | No-sched2 | Sched Changed? | Verdict |" >&3
echo "|----------|---------|-----------|----------------|---------|" >&3

for ((i=0; i<pa_idx; i++)); do
    f="${PA_NAMES[$i]}"; d="${PA_DEFAULT[$i]}"; n="${PA_NOSCHED[$i]}"; s="${PA_SCHED_DIFF[$i]}"
    v=""
    if [ "$d" = "PASS" ] && [ "$n" = "PASS" ]; then v="OK"
    elif [ "$d" = "PASS" ] && [ "$n" != "PASS" ]; then v="REGRESSED"
    elif [ "$s" = "identical" ]; then v="no effect"
    else v="changed"; fi
    echo "| $f | $d | $n | $s | $v |" >&3
done

echo "" >&3
echo "## Diff Details" >&3
echo "" >&3
echo "### Functions where -fno-schedule-insns2 improved the result" >&3
echo "" >&3

fi2=0
for ((i=0; i<d0_idx; i++)); do
    f="${D0_NAMES[$i]}"; d="${D0_DEFAULT[$i]}"; n="${D0_NOSCHED[$i]}"
    if [ "$d" != "PASS" ] && [ "$n" = "PASS" ]; then
        fi2=1
        echo "#### $f" >&3
        echo '```' >&3
        echo "Default: $d" >&3
        echo "No-sched2: PASS" >&3
        echo "" >&3
        echo "Diff (default vs no-sched2 opcodes):" >&3
        diff "$TMPDIR/${f}_default.opcodes" "$TMPDIR/${f}_nosched.opcodes" >&3 2>&1 || true
        echo '```' >&3
        echo "" >&3
    fi
done
[ "$fi2" -eq 0 ] && { echo "None." >&3; echo "" >&3; }

echo "### Functions where -fno-schedule-insns2 changed output but still fails" >&3
echo "" >&3

fc2=0
for ((i=0; i<d0_idx; i++)); do
    f="${D0_NAMES[$i]}"; d="${D0_DEFAULT[$i]}"; n="${D0_NOSCHED[$i]}"; s="${D0_SCHED_DIFF[$i]}"
    if [ "$s" != "identical" ] && [ "$n" != "PASS" ] && [ "$d" != "PASS" ]; then
        fc2=1
        echo "#### $f" >&3
        echo '```' >&3
        echo "Default: $d" >&3
        echo "No-sched2: $n" >&3
        echo "" >&3
        echo "Diff of default vs no-sched2 opcodes:" >&3
        diff "$TMPDIR/${f}_default.opcodes" "$TMPDIR/${f}_nosched.opcodes" >&3 2>&1 || true
        echo "" >&3
        echo "Diff of no-sched2 vs expected:" >&3
        diff "$TMPDIR/${f}_nosched.opcodes" "$TMPDIR/${f}_nosched.exp_clean" >&3 2>&1 || true
        echo '```' >&3
        echo "" >&3
    fi
done
[ "$fc2" -eq 0 ] && { echo "None." >&3; echo "" >&3; }

echo "### Currently-passing functions that regressed" >&3
echo "" >&3

fr2=0
for ((i=0; i<pa_idx; i++)); do
    f="${PA_NAMES[$i]}"; d="${PA_DEFAULT[$i]}"; n="${PA_NOSCHED[$i]}"
    if [ "$d" = "PASS" ] && [ "$n" != "PASS" ]; then
        fr2=1
        echo "#### $f" >&3
        echo '```' >&3
        echo "Default: PASS" >&3
        echo "No-sched2: $n" >&3
        echo "" >&3
        echo "Diff (no-sched2 vs expected):" >&3
        diff "$TMPDIR/${f}_nosched.opcodes" "$TMPDIR/${f}_nosched.exp_clean" >&3 2>&1 || true
        echo '```' >&3
        echo "" >&3
    fi
done
[ "$fr2" -eq 0 ] && { echo "None." >&3; echo "" >&3; }

echo "## Conclusion" >&3
echo "" >&3
if [ "$d0_improved" -gt 0 ]; then
    echo "- **$d0_improved out of $d0_idx** delta=0 functions improved to PASS with -fno-schedule-insns2" >&3
    echo "- **$pa_regressed out of $pa_idx** currently-passing functions regressed" >&3
    echo "- Hypothesis **SUPPORTED**: Post-reload scheduling is a significant source of opcode differences" >&3
else
    echo "- **0 out of $d0_idx** delta=0 functions improved to PASS with -fno-schedule-insns2" >&3
    echo "- **$pa_regressed out of $pa_idx** currently-passing functions regressed" >&3
    echo "- Hypothesis **NOT SUPPORTED**: Post-reload scheduling is not a significant source of opcode differences" >&3
fi
echo "" >&3

exec 3>&-
echo "Report written to: $OUTFILE"
rm -rf "$TMPDIR"
