#!/bin/bash
# Show diffs for new delta=0 functions (not in original 34)
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests
TMPDIR=/tmp/diff0_$$
mkdir -p "$TMPDIR"

extract_opcodes() {
    tr -d '\r' < "$1" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
}

# New delta=0 functions with few diffs
for base in FUN_060192CA FUN_06019324 FUN_06021128 FUN_060280C4 FUN_060281B8 FUN_0600DF66; do
    cfile="$SRCDIR/$base.c"
    expected="$TESTDIR/$base.expected"
    [ ! -f "$cfile" ] && continue
    [ ! -f "$expected" ] && continue

    FLAGS="-O2 -m2 -mbsr"
    [ -f "$TESTDIR/$base.flags" ] && FLAGS=$(tr -d '\r' < "$TESTDIR/$base.flags")

    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    if "$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>/dev/null; then
        extract_opcodes "$TMPDIR/$base.s" > "$TMPDIR/$base.opcodes"
        tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > "$TMPDIR/$base.exp_clean"

        our_count=$(wc -l < "$TMPDIR/$base.opcodes")
        exp_count=$(wc -l < "$TMPDIR/$base.exp_clean")

        echo "=== $base (insns=$our_count/$exp_count) ==="
        diff --unified=1 "$TMPDIR/$base.exp_clean" "$TMPDIR/$base.opcodes"
        echo ""
    else
        echo "=== $base === COMPILE FAILED"
    fi
done

rm -rf "$TMPDIR"
