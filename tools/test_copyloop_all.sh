#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

echo "=== Byte copy (FUN_0602760C) with char* ==="
cat > /tmp/copy_byte.c << 'CEOF'
void FUN_0602760c(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3--;
  do {
    param_1[iVar2] = param_2[iVar2];
    iVar2++;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copy_byte.c -o /tmp/copy_byte.s 2>/dev/null
echo "Opcodes:"
grep -P '^\t' /tmp/copy_byte.s | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r'

echo ""
echo "=== Word copy (FUN_0602761E) with short* ==="
cat > /tmp/copy_word.c << 'CEOF'
void FUN_0602761e(param_1, param_2, param_3)
    short *param_1;
    short *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3 = (param_3 + -2) / 2;
  do {
    param_1[iVar2] = param_2[iVar2];
    iVar2++;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copy_word.c -o /tmp/copy_word.s 2>/dev/null
echo "Opcodes:"
grep -P '^\t' /tmp/copy_word.s | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r'
echo "Full asm:"
grep -P '^\t' /tmp/copy_word.s | grep -v '^\t\.'

echo ""
echo "=== Long copy (FUN_06027630) with int* ==="
cat > /tmp/copy_long.c << 'CEOF'
void FUN_06027630(param_1, param_2, param_3)
    int *param_1;
    int *param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3 = (param_3 + -4) / 4;
  do {
    param_1[iVar2] = param_2[iVar2];
    iVar2++;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copy_long.c -o /tmp/copy_long.s 2>/dev/null
echo "Opcodes:"
grep -P '^\t' /tmp/copy_long.c -o /tmp/copy_long.s | sed 's/^\t//' | sed 's/\t.*//' | sed 's/ .*//' | grep -v '^\.' | grep -v '^$' | tr -d '\r'
echo "Full asm:"
grep -P '^\t' /tmp/copy_long.s | grep -v '^\t\.'

echo ""
echo "Expected byte (9): mov add mov.b cmp/gt mov.b bt.s add rts add"
echo "Expected word (9): mov add mov.w cmp/gt mov.w bt.s add rts add"
echo "Expected long (9): mov add mov.l cmp/gt mov.l bt.s add rts add"
