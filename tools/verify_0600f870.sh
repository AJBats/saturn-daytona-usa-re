#!/bin/bash
# Compile FUN_0600F870 and compare against original binary disassembly
set -e

CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

cat > /tmp/fun_0600f870.c << 'EOF'
extern void func_060114AC();
extern int func_06011094();

extern short counter_0607887C;
extern char flag_0607887F;

int FUN_0600F870()
{
    int result;
    short val;

    func_060114AC(0);
    result = func_06011094();
    val = counter_0607887C;
    counter_0607887C = val - 1;
    if ((short)(val - 1) <= 0) {
        flag_0607887F = 4;
    }
    return result;
}
EOF

echo "=== Compiling with GCC 2.6.3 (-O2) ==="
$CC1 -quiet -O2 /tmp/fun_0600f870.c -o /tmp/fun_0600f870.s

echo "=== Our GCC 2.6.3 output ==="
cat /tmp/fun_0600f870.s

echo ""
echo "=== Original binary disassembly ==="
echo "0600F870: sts.l pr,@-r15"
echo "0600F872: mov.l @(0x64,PC),r3    -> 0x060114AC"
echo "0600F874: jsr @r3"
echo "0600F876: mov #0,r4              (delay slot)"
echo "0600F878: mov.l @(0x60,PC),r3    -> 0x06011094"
echo "0600F87A: jsr @r3"
echo "0600F87C: nop                    (delay slot)"
echo "0600F87E: mov.l @(0x60,PC),r4    -> 0x0607887C"
echo "0600F880: mov.w @r4,r2"
echo "0600F882: add #-1,r2"
echo "0600F884: mov.w r2,@r4"
echo "0600F886: exts.w r2,r2"
echo "0600F888: cmp/pl r2"
echo "0600F88A: bt 0x0600F892          (skip to epilogue)"
echo "0600F88C: mov #4,r2"
echo "0600F88E: mov.l @(0x54,PC),r3    -> 0x0607887F"
echo "0600F890: mov.b r2,@r3"
echo "0600F892: lds.l @r15+,pr"
echo "0600F894: rts"
echo "0600F896: nop                    (delay slot)"
