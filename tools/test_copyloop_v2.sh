#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

echo "=== Byte copy (char* + byte offset) ==="
cat > /tmp/copy_byte.c << 'CEOF'
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3--;
  do {
    *(char *)(param_1 + iVar2) = *(char *)(param_2 + iVar2);
    iVar2++;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copy_byte.c -o /tmp/copy_byte.s 2>/dev/null
grep -P '^\t' /tmp/copy_byte.s | grep -v '^\t\.'

echo ""
echo "=== Word copy (char* + byte offset, cast to short*) ==="
cat > /tmp/copy_word.c << 'CEOF'
void FUN_0602761e(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3 -= 2;
  do {
    *(short *)(param_1 + iVar2) = *(short *)(param_2 + iVar2);
    iVar2 += 2;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copy_word.c -o /tmp/copy_word.s 2>/dev/null
grep -P '^\t' /tmp/copy_word.s | grep -v '^\t\.'

echo ""
echo "=== Long copy (char* + byte offset, cast to int*) ==="
cat > /tmp/copy_long.c << 'CEOF'
void FUN_06027630(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3 -= 4;
  do {
    *(int *)(param_1 + iVar2) = *(int *)(param_2 + iVar2);
    iVar2 += 4;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copy_long.c -o /tmp/copy_long.s 2>/dev/null
grep -P '^\t' /tmp/copy_long.s | grep -v '^\t\.'

echo ""
echo "Expected (9 each):"
echo "byte: mov add mov.b cmp/gt mov.b bt.s add rts add"
echo "word: mov add mov.w cmp/gt mov.w bt.s add rts add"
echo "long: mov add mov.l cmp/gt mov.l bt.s add rts add"
