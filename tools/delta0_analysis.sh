#!/bin/bash
# Delta=0 analysis script: compiles each function, diffs opcodes vs expected,
# and outputs full instruction-level diffs for classification.
# Run in WSL: MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/delta0_analysis.sh

set -e

PROJDIR="/mnt/d/Projects/SaturnReverseTest"
CC1="$PROJDIR/tools/gcc26-build/cc1"
SRCDIR="$PROJDIR/src"
TESTDIR="$PROJDIR/tests"
TMPDIR="/tmp/delta0_$$"
mkdir -p "$TMPDIR"

FLAGS="-O2 -m2 -mbsr"

FUNCS="FUN_06005174 FUN_0600C970 FUN_0600D12C FUN_06011494 FUN_0601164A FUN_060122F4 FUN_06018EC8 FUN_0601AB8C FUN_0601FD20 FUN_06026590 FUN_06026E0C FUN_060270D0 FUN_06027344 FUN_06027348 FUN_0602760C FUN_0602761E FUN_06027630 FUN_060285E0 FUN_06028600 FUN_0602F71C FUN_06033520 FUN_06035C1C FUN_06035C80 FUN_0603B878 FUN_0603C05C FUN_0603C0A0 FUN_0603F3DA FUN_0603F4CC FUN_0603F4E0 FUN_0603F500 FUN_0603F8B8 FUN_06040954 FUN_06040E88 FUN_06041128"

# Extract opcode mnemonics from GCC .s output (one per line)
extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

# Extract full instruction lines (mnemonic + operands) from GCC .s output
extract_full_insns() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | sed 's/^\t//' | sed 's/\t/ /g'
}

echo "================================================================"
echo "  Delta=0 Opcode Difference Analysis"
echo "  $(date)"
echo "================================================================"
echo ""

for func in $FUNCS; do
    cfile="$SRCDIR/$func.c"
    expected="$TESTDIR/$func.expected"

    if [ ! -f "$cfile" ] || [ ! -f "$expected" ]; then
        echo "SKIP $func (missing files)"
        continue
    fi

    # Compile
    tr -d '\r' < "$cfile" > "$TMPDIR/$func.c"
    if ! $CC1 -quiet $FLAGS "$TMPDIR/$func.c" -o "$TMPDIR/$func.s" 2>"$TMPDIR/$func.err"; then
        echo "=== $func: COMPILE ERROR ==="
        cat "$TMPDIR/$func.err"
        echo ""
        continue
    fi

    # Extract opcodes
    extract_opcodes "$TMPDIR/$func.s" > "$TMPDIR/$func.opcodes"
    tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$func.exp_clean"

    # Extract full instructions for context
    extract_full_insns "$TMPDIR/$func.s" > "$TMPDIR/$func.full_insns"

    our_count=$(wc -l < "$TMPDIR/$func.opcodes")
    exp_count=$(wc -l < "$TMPDIR/$func.exp_clean")
    delta=$((our_count - exp_count))

    if diff -q "$TMPDIR/$func.opcodes" "$TMPDIR/$func.exp_clean" > /dev/null 2>&1; then
        echo "=== $func: PASS (now matches, $our_count insns) ==="
        echo ""
        continue
    fi

    echo "=== $func: delta=$delta (ours=$our_count orig=$exp_count) ==="

    # Show numbered side-by-side of opcodes
    echo "--- Expected vs Ours (opcodes only) ---"
    diff -u "$TMPDIR/$func.exp_clean" "$TMPDIR/$func.opcodes" | head -60
    echo ""

    # Show our full instructions for context
    echo "--- Our full assembly ---"
    cat -n "$TMPDIR/$func.full_insns"
    echo ""

    # Count differences by type
    echo "--- Difference summary ---"
    diff "$TMPDIR/$func.exp_clean" "$TMPDIR/$func.opcodes" | grep -E '^[<>]' | sort | uniq -c | sort -rn | head -20
    echo ""
    echo "========================================"
    echo ""
done

# Cleanup
rm -rf "$TMPDIR"
