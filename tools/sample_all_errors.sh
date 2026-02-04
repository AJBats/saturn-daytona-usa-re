#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/sall_$$
mkdir -p "$TMPDIR"

show_error_lines() {
    local base=$1
    local pattern=$2
    local cfile="$SRCDIR/$base.c"
    [ ! -f "$cfile" ] && return
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"

    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")

    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    echo "=== $base ==="
    echo "$errout" | grep -v "In function" | grep -v "^$" | grep -v "warning:" | head -3
    for lineno in $(echo "$errout" | grep -v "In function" | grep -v "warning:" | grep "$pattern" | head -2 | sed 's/^[^:]*:\([0-9]*\):.*/\1/'); do
        echo "  LINE $lineno: $(sed -n "${lineno}p" "$TMPDIR/$base.c")"
    done
    echo ""
}

echo "=========================================="
echo "CATEGORY: void value not ignored (43 files)"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "void value not ignored"; then
        show_error_lines "$base" "void value"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

echo "=========================================="
echo "CATEGORY: invalid type argument (59 files)"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "invalid type argument"; then
        show_error_lines "$base" "invalid type"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

echo "=========================================="
echo "CATEGORY: subscripted value (22 files)"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "subscripted value"; then
        show_error_lines "$base" "subscripted"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

echo "=========================================="
echo "CATEGORY: undeclared (15 files)"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "undeclared"; then
        show_error_lines "$base" "undeclared"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

echo "=========================================="
echo "CATEGORY: parse error (12 files)"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "parse error"; then
        show_error_lines "$base" "parse error"
        count=$((count + 1))
        [ $count -ge 8 ] && break
    fi
done

rm -rf "$TMPDIR"
