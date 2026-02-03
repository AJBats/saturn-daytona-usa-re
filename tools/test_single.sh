#!/bin/bash
# Test a single function: compile and compare
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
FUNC=${1:?Usage: test_single.sh FUN_XXXXXXXX}

tr -d '\r' < "$TDIR/$FUNC.c" > "/tmp/test_$FUNC.c"
$CC1 -quiet -O2 -m2 -mbsr "/tmp/test_$FUNC.c" -o "/tmp/test_$FUNC.s"

echo "=== Our assembly ==="
cat "/tmp/test_$FUNC.s"
echo ""
echo "=== Opcodes ==="
tr -d '\r' < "/tmp/test_$FUNC.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""
echo "=== Expected ==="
tr -d '\r' < "$TDIR/$FUNC.expected" | sed '/^$/d'
echo ""
echo "=== Diff ==="
diff <(tr -d '\r' < "/tmp/test_$FUNC.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//') \
     <(tr -d '\r' < "$TDIR/$FUNC.expected" | sed '/^$/d')
echo "exit: $?"
