#!/bin/bash
# Test more fix variants
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

compile_and_show() {
    local name="$1"
    local src="$2"
    echo "========================================"
    echo "  $name"
    echo "========================================"
    echo "$src" > /tmp/fix_test.c
    if $CC1 -quiet -O2 -m2 -mbsr /tmp/fix_test.c -o /tmp/fix_test.s 2>/tmp/fix_test.err; then
        cat /tmp/fix_test.s | grep -vP '^[!L\t\.]' | head -2
        echo "---FULL ASM---"
        cat /tmp/fix_test.s
        echo "---OPCODES---"
        grep -P '^\t[a-z]' /tmp/fix_test.s | awk '{print $1}' | sed 's/,$//'
        echo "---"
        echo "Count: $(grep -cP '^\t[a-z]' /tmp/fix_test.s)"
    else
        echo "COMPILE ERROR:"
        cat /tmp/fix_test.err
    fi
    echo ""
}

# FUN_06018EC8 fix v2 - check full asm
compile_and_show "FUN_06018EC8 fix v2 FULL" '
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    short val = 0x00E0;
    REG_25B00217 = (unsigned char)val;
    REG_25B00237 = (char)val;
}
'

# FUN_0603F4E0 fix FULL asm
compile_and_show "FUN_0603F4E0 fix FULL" '
extern void FUN_0603f3f6();

int FUN_0603f4e0(param_1)
    int param_1;
{
    short local_10[2];
    volatile int saved_param;
    char auStack_8[8];

    saved_param = param_1;
    FUN_0603f3f6(param_1, auStack_8, 2);
    FUN_0603f3f6(saved_param, local_10, 2);
    return (int)local_10[0];
}
'

# FUN_0603F500: try different approach - dont use volatile, reorder
compile_and_show "FUN_0603F500 fix v2: no volatile, stack layout" '
extern void FUN_0603f3f6();

int FUN_0603f500(param_1)
    int param_1;
{
    volatile int uStack_c;
    int local_10;
    char auStack_8[8];

    uStack_c = param_1;
    FUN_0603f3f6(param_1, auStack_8, 4);
    FUN_0603f3f6(uStack_c, &local_10, 4);
    return local_10;
}
'

# FUN_0603F500: try with explicit stack frame
compile_and_show "FUN_0603F500 fix v3: minimal volatile" '
extern void FUN_0603f3f6();

int FUN_0603f500(param_1)
    int param_1;
{
    struct { int val; int saved; char buf[8]; } frame;

    frame.saved = param_1;
    FUN_0603f3f6(param_1, frame.buf, 4);
    FUN_0603f3f6(frame.saved, &frame.val, 4);
    return frame.val;
}
'

# FUN_06038F34: try casting to make GCC use different regs
compile_and_show "FUN_06038F34 fix v3: pointer-based" '
void FUN_06038f34()
{
    int *p;
    p = (int *)0x060635B4;
    *(short *)p = 0;
    p = (int *)0x060635B8;
    *p = 1;
    p = (int *)0x060635BC;
    *p = 0;
    *((int *)0x060635C0) = 0;
    *((int *)0x060635C4) = 0;
    *((int *)0x060635C8) = 0;
}
'

# FUN_06038F34: try with volatile int for constants
compile_and_show "FUN_06038F34 fix v4: mov+mov style" '
void FUN_06038f34()
{
    register int zero = 0;
    register int one = 1;

    *(volatile short *)0x060635B4 = zero;
    *(volatile int *)0x060635B8 = one;
    *(volatile int *)0x060635BC = zero;
    *(volatile int *)0x060635C0 = zero;
    *(volatile int *)0x060635C4 = zero;
    *(volatile int *)0x060635C8 = zero;
}
'

# FUN_0601DB84: try different loop structure
compile_and_show "FUN_0601DB84 fix v2: while loop" '
void FUN_0601db84()
{
    int counter = 0x000186A0;

    while (1) {
        counter = counter - 1;
        if (counter == 0) {
            *(int *)0x06086050 = 1;
            return;
        }
        if (*(int *)0x25A02C20 == 0) {
            return;
        }
    }
}
'

# FUN_0601DB84 fix v3: Try to match original's structure more closely
compile_and_show "FUN_0601DB84 fix v3: counter with explicit store" '
void FUN_0601db84()
{
    int *store = (int *)0x06086050;
    volatile int *poll = (volatile int *)0x25A02C20;
    int counter = 0x000186A0;

    do {
        counter = counter - 1;
        if (counter == 0) {
            *store = 1;
            return;
        }
    } while (*poll != 0);
}
'
