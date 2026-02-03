#!/bin/bash
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

echo "=== Original (16 insns) ==="
cat > /tmp/multistore1.c << 'CEOF'
void FUN_06038f34()
{
  *(short *)0x060635B4 = 0;
  *(int *)0x060635B8 = 1;
  *(int *)0x060635BC = 0;
  *(int *)0x060635C0 = 0;
  *(int *)0x060635C4 = 0;
  *(int *)0x060635C8 = 0;
  return;
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/multistore1.c -o /tmp/multistore1.s 2>/dev/null
grep -P '^\t' /tmp/multistore1.s | grep -v '^\t\.'
echo "Count: $(grep -cP '^\t' /tmp/multistore1.s | grep -v '^\t\.')"

echo ""
echo "=== With explicit zero/one variables ==="
cat > /tmp/multistore2.c << 'CEOF'
void FUN_06038f34()
{
  int zero = 0;
  int one = 1;
  *(short *)0x060635B4 = zero;
  *(int *)0x060635B8 = one;
  *(int *)0x060635BC = zero;
  *(int *)0x060635C0 = zero;
  *(int *)0x060635C4 = zero;
  *(int *)0x060635C8 = zero;
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/multistore2.c -o /tmp/multistore2.s 2>/dev/null
grep -P '^\t' /tmp/multistore2.s | grep -v '^\t\.'

echo ""
echo "=== With struct-based approach ==="
cat > /tmp/multistore3.c << 'CEOF'
void FUN_06038f34()
{
  int *base = (int *)0x060635B4;
  *(short *)base = 0;
  base[1] = 1;
  base[2] = 0;
  base[3] = 0;
  base[4] = 0;
  base[5] = 0;
}
CEOF
$CC1 -quiet -O2 -m2 -mbsr /tmp/multistore3.c -o /tmp/multistore3.s 2>/dev/null
grep -P '^\t' /tmp/multistore3.s | grep -v '^\t\.'

echo ""
echo "Expected (15): mov mov mov.l mov.w mov.l mov.l mov.l mov.l mov.l mov.l mov.l mov.l mov.l rts mov.l"
