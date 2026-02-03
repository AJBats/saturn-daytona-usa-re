#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TDIR=/mnt/d/Projects/SaturnReverseTest/tests
FUNC=${1:?Usage: test_nobsr.sh FUN_XXXXXXXX}

tr -d '\r' < "$TDIR/$FUNC.c" > "/tmp/test_nobsr_$FUNC.c"
$CC1 -quiet -O2 -m2 "/tmp/test_nobsr_$FUNC.c" -o "/tmp/test_nobsr_$FUNC.s" 2>/dev/null

echo "=== Opcodes (no -mbsr) ==="
tr -d '\r' < "/tmp/test_nobsr_$FUNC.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//'
echo ""
echo "=== Expected ==="
tr -d '\r' < "$TDIR/$FUNC.expected" | sed '/^$/d'
echo ""
echo "=== Diff ==="
diff <(tr -d '\r' < "/tmp/test_nobsr_$FUNC.s" | grep -P '^\t[a-z]' | awk '{print $1}' | sed 's/,$//') \
     <(tr -d '\r' < "$TDIR/$FUNC.expected" | sed '/^$/d')
echo "exit: $?"
