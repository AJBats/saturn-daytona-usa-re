#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/srem_$$
mkdir -p "$TMPDIR"

show_context() {
    local base=$1
    local pattern=$2
    local cfile="$SRCDIR/$base.c"
    [ ! -f "$cfile" ] && return
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")

    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    # Show all non-warning error lines
    echo "=== $base ==="
    echo "$errout" | grep -v "In function" | grep -v "^$" | grep -v "warning:" | head -5
    for lineno in $(echo "$errout" | grep -v "In function" | grep -v "warning:" | grep "$pattern" | head -3 | sed 's/^[^:]*:\([0-9]*\):.*/\1/'); do
        echo "  LINE $lineno: $(sed -n "${lineno}p" "$TMPDIR/$base.c")"
    done
    echo ""
}

echo "=========================================="
echo "REMAINING: void value not ignored"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "void value not ignored"; then
        show_context "$base" "void value"
        count=$((count + 1))
        [ $count -ge 10 ] && break
    fi
done

echo "=========================================="
echo "REMAINING: invalid type argument"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "invalid type argument"; then
        show_context "$base" "invalid type"
        count=$((count + 1))
        [ $count -ge 10 ] && break
    fi
done

echo "=========================================="
echo "REMAINING: subscripted value"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "subscripted value"; then
        show_context "$base" "subscripted"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

echo "=========================================="
echo "REMAINING: undeclared"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "undeclared"; then
        show_context "$base" "undeclared"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

rm -rf "$TMPDIR"
