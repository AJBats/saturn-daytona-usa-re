#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
$CC1 -quiet -O2 -m2 -mbsr /mnt/d/Projects/SaturnReverseTest/src/FUN_0602E5E4.c -o /tmp/e5e4.s
echo "=== OUR OUTPUT ==="
tr -d '\r' < /tmp/e5e4.s | grep -P '^\t[a-z]'
echo ""
echo "=== EXPECTED ==="
tr -d '\r' < /mnt/d/Projects/SaturnReverseTest/tests/FUN_0602E5E4.expected | sed '/^$/d'
