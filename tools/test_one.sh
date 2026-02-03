#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
FUNC=${1:-FUN_0600DE40}

echo "Testing $FUNC"
tr -d '\r' < "$TDIR/$FUNC.c" > /tmp/test_one.c
$CC1 -quiet -O2 -m2 -mbsr /tmp/test_one.c -o /tmp/test_one.s 2>&1
echo "--- our opcodes ---"
tr -d '\r' < /tmp/test_one.s | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo "--- expected ---"
tr -d '\r' < "$TDIR/$FUNC.expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|'
echo "--- full asm ---"
cat /tmp/test_one.s
