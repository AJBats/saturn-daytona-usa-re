#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

cat > /tmp/test_d336_v2.c << 'CEOF'
void FUN_0600d336()
{
  int *baseA;
  int *baseB;

  baseA = (int *)0x06078900;
  baseB = (int *)(0x06078900 + 0x0268);

  if ((*(unsigned int *)0x0607EBC4 & 0x00200000) == 0) {
    if (*(int *)((char *)baseA + 0x01F4) < *(int *)((char *)baseB + 0x01F4)) {
      *(int *)((char *)baseA + 0x0224) = 1;
      *(int *)((char *)baseB + 0x0224) = 0;
    } else {
      *(int *)((char *)baseA + 0x0224) = 0;
      *(int *)((char *)baseB + 0x0224) = 1;
    }
  }
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/test_d336_v2.c -o /tmp/test_d336_v2.s 2>&1
echo "V2 insns: $(grep -cP '^\t[a-z]' /tmp/test_d336_v2.s)"

cat > /tmp/test_d336_v3.c << 'CEOF'
void FUN_0600d336()
{
  char *baseA;
  char *baseB;

  baseA = (char *)0x06078900;
  baseB = baseA + 0x0268;

  if ((*(unsigned int *)0x0607EBC4 & 0x00200000) == 0) {
    if (*(int *)(baseA + 0x01F4) >= *(int *)(baseB + 0x01F4)) {
      *(int *)(baseA + 0x0224) = 0;
      *(int *)(baseB + 0x0224) = 1;
    } else {
      *(int *)(baseA + 0x0224) = 1;
      *(int *)(baseB + 0x0224) = 0;
    }
  }
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/test_d336_v3.c -o /tmp/test_d336_v3.s 2>&1
echo "V3 insns: $(grep -cP '^\t[a-z]' /tmp/test_d336_v3.s)"

echo "=== V2 asm ==="
cat /tmp/test_d336_v2.s
echo ""
echo "=== V3 asm ==="
cat /tmp/test_d336_v3.s
