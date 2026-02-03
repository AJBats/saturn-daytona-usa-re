#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

# Try different C source formulations for the byte copy loop
echo "=== Variant 1: Original (int params, explicit cast) ==="
cat > /tmp/copyloop1.c << 'CEOF'
void FUN_0602760c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  int iVar2 = 0;
  param_3 = param_3 + -1;
  do {
    *(char *)(param_1 + iVar2) = *(char *)(param_2 + iVar2);
    iVar2 = iVar2 + 1;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copyloop1.c -o /tmp/copyloop1.s 2>/dev/null
grep -P '^\t' /tmp/copyloop1.s | grep -v '^\t\.'

echo ""
echo "=== Variant 2: char* params, array indexing ==="
cat > /tmp/copyloop2.c << 'CEOF'
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
$CC1 -quiet -O2 -m2 -mbsr /tmp/copyloop2.c -o /tmp/copyloop2.s 2>/dev/null
grep -P '^\t' /tmp/copyloop2.s | grep -v '^\t\.'

echo ""
echo "=== Variant 3: register keyword ==="
cat > /tmp/copyloop3.c << 'CEOF'
void FUN_0602760c(param_1, param_2, param_3)
    register char *param_1;
    register char *param_2;
    register int param_3;
{
  register int iVar2 = 0;
  param_3--;
  do {
    param_1[iVar2] = param_2[iVar2];
    iVar2++;
  } while (param_3 > iVar2);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copyloop3.c -o /tmp/copyloop3.s 2>/dev/null
grep -P '^\t' /tmp/copyloop3.s | grep -v '^\t\.'

echo ""
echo "=== Variant 4: Pointer-based loop (post-increment) ==="
cat > /tmp/copyloop4.c << 'CEOF'
void FUN_0602760c(dst, src, count)
    char *dst;
    char *src;
    int count;
{
  char *end = dst + count;
  do {
    *dst = *src;
    dst++;
    src++;
  } while (dst != end);
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/copyloop4.c -o /tmp/copyloop4.s 2>/dev/null
grep -P '^\t' /tmp/copyloop4.s | grep -v '^\t\.'

echo ""
echo "=== Expected (9 insns): mov #0,r0 / add #-1,r6 / mov.b @(r0,r5),r1 / cmp/gt r0,r6 / mov.b r1,@(r0,r4) / bt/s / add #1,r0 / rts / add #1,r6 ==="
