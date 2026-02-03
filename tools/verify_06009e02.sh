#!/bin/bash
set -e
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

cat > /tmp/fun_06009e02.c << 'EOF'
extern int counter_0607EBCC;
extern int state_0605AD10;
extern void func_0601389E();
extern void func_06018E70();
extern char flag_0607864B;

void FUN_06009E02()
{
    counter_0607EBCC = counter_0607EBCC - 1;
    if (counter_0607EBCC == 0) {
        state_0605AD10 = 30;
    }
    func_0601389E();
    if (state_0605AD10 != 27) {
        func_06018E70();
    }
    flag_0607864B = 1;
}
EOF

echo "=== GCC 2.6.3 output ==="
$CC1 -quiet -O2 /tmp/fun_06009e02.c -o /tmp/fun_06009e02.s
cat /tmp/fun_06009e02.s

echo ""
echo "=== Original binary ==="
echo "06009E02: sts.l pr,@-r15"
echo "06009E04: mov.l @(PC),r4       -> 0x0607EBCC"
echo "06009E06: mov.l @r4,r3"
echo "06009E08: add #-1,r3"
echo "06009E0A: tst r3,r3"
echo "06009E0C: bf/s 0x06009E16"
echo "06009E0E: mov.l r3,@r4         (delay slot - always executes)"
echo "06009E10: mov #30,r3"
echo "06009E12: mov.l @(PC),r2       -> 0x0605AD10"
echo "06009E14: mov.l r3,@r2"
echo "06009E16: mov.l @(PC),r3       -> 0x0601389E"
echo "06009E18: jsr @r3"
echo "06009E1A: nop"
echo "06009E1C: mov.l @(PC),r0       -> 0x0605AD10"
echo "06009E1E: mov.l @r0,r0"
echo "06009E20: cmp/eq #27,r0"
echo "06009E22: bt 0x06009E2A"
echo "06009E24: mov.l @(PC),r3       -> 0x06018E70"
echo "06009E26: jsr @r3"
echo "06009E28: nop"
echo "06009E2A: mov #1,r2"
echo "06009E2C: mov.l @(PC),r3       -> 0x0607864B"
echo "06009E2E: lds.l @r15+,pr"
echo "06009E30: rts"
echo "06009E32: mov.b r2,@r3         (delay slot)"
