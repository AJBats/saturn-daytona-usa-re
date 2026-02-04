#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/sfin_$$
mkdir -p "$TMPDIR"

echo "=========================================="
echo "REMAINING: parse error (12 files)"
echo "=========================================="
count=0
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    if echo "$errout" | grep -v "warning:" | grep -q "parse error"; then
        echo "=== $base ==="
        echo "$errout" | grep -v "warning:" | head -5
        # Show first few lines of file to check function signature
        head -5 "$TMPDIR/$base.c" | while IFS= read -r line; do echo "  > $line"; done
        echo ""
        count=$((count + 1))
    fi
done

echo "=========================================="
echo "REMAINING: invalid type (5), subscript (3), undeclared (3)"
echo "=========================================="
for cfile in "$SRCDIR"/*.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    FLAGS="-O2 -m2 -mbsr"
    [ -f "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags" ] && FLAGS=$(tr -d '\r' < "/mnt/d/Projects/SaturnReverseTest/tests/$base.flags")
    errout=$("$CC1" -quiet $FLAGS "$TMPDIR/$base.c" -o /dev/null 2>&1)
    real_err=$(echo "$errout" | grep -v "In function" | grep -v "^$" | grep -v "warning:" | head -1 | sed 's|^[^:]*:[0-9]*: ||')
    case "$real_err" in
        invalid\ type*|subscripted*|*undeclared*|invalid\ lvalue*|request\ for\ member*)
            echo "=== $base: $real_err ==="
            lineno=$(echo "$errout" | grep -v "warning:" | grep -v "In function" | head -1 | sed 's/^[^:]*:\([0-9]*\):.*/\1/')
            echo "  LINE $lineno: $(sed -n "${lineno}p" "$TMPDIR/$base.c")"
            echo ""
            ;;
    esac
done

rm -rf "$TMPDIR"
