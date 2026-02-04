#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TMPDIR=/tmp/quick_check_$$
mkdir -p "$TMPDIR"

errors=0
success=0
total=0

for cfile in "$SRCDIR"/FUN_0600338C.c "$SRCDIR"/FUN_060033E6.c "$SRCDIR"/FUN_06003430.c "$SRCDIR"/FUN_06008640.c "$SRCDIR"/FUN_0600CF58.c "$SRCDIR"/FUN_060030FC.c "$SRCDIR"/FUN_06003274.c "$SRCDIR"/FUN_060032D4.c "$SRCDIR"/FUN_0600330A.c "$SRCDIR"/FUN_060146D2.c; do
    base=$(basename "$cfile" .c)
    tr -d '\r' < "$cfile" > "$TMPDIR/$base.c"
    total=$((total + 1))
    if "$CC1" -quiet -O2 -m2 -mbsr "$TMPDIR/$base.c" -o "$TMPDIR/$base.s" 2>"$TMPDIR/$base.err"; then
        echo "OK   $base"
        success=$((success + 1))
    else
        echo "FAIL $base"
        head -2 "$TMPDIR/$base.err"
        errors=$((errors + 1))
    fi
done

echo ""
echo "$success OK / $errors FAIL / $total total"
rm -rf "$TMPDIR"
