#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
SRCDIR=/mnt/d/Projects/SaturnReverseTest/src
TDIR=/mnt/d/Projects/SaturnReverseTest/tests

echo "=== FUN_0601FD20 with -O2 -m2 -mbsr ==="
$CC1 -quiet -O2 -m2 -mbsr "$SRCDIR/FUN_0601FD20.c" -o /tmp/fd20_bsr.s 2>/dev/null
echo "--- Full asm ---"
cat /tmp/fd20_bsr.s | tr -d '\r' | grep -P '^\t[a-z]'
echo ""

echo "=== FUN_0601FD20 with -O2 -m2 ==="
$CC1 -quiet -O2 -m2 "$SRCDIR/FUN_0601FD20.c" -o /tmp/fd20_nobsr.s 2>/dev/null
echo "--- Full asm ---"
cat /tmp/fd20_nobsr.s | tr -d '\r' | grep -P '^\t[a-z]'
echo ""

echo "=== FUN_0601FD20 with -O2 -m2 -mnofill ==="
$CC1 -quiet -O2 -m2 -mnofill "$SRCDIR/FUN_0601FD20.c" -o /tmp/fd20_nofill.s 2>/dev/null
echo "--- Full asm ---"
cat /tmp/fd20_nofill.s | tr -d '\r' | grep -P '^\t[a-z]'
echo ""

echo "=== Expected ==="
cat "$TDIR/FUN_0601FD20.expected" | tr -d '\r' | sed '/^$/d'
