#!/bin/bash
# Test proposed C source fixes for batch 3 functions
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

compile_and_show() {
    local name="$1"
    local src="$2"
    echo "========================================"
    echo "  $name"
    echo "========================================"
    echo "$src" > /tmp/fix_test.c
    if $CC1 -quiet -O2 -m2 -mbsr /tmp/fix_test.c -o /tmp/fix_test.s 2>/tmp/fix_test.err; then
        grep -P '^\t[a-z]' /tmp/fix_test.s | awk '{print $1}' | sed 's/,$//'
        echo "---"
        echo "Count: $(grep -cP '^\t[a-z]' /tmp/fix_test.s)"
    else
        echo "COMPILE ERROR:"
        cat /tmp/fix_test.err
    fi
    echo ""
}

# FUN_06018EC8: Replace extern with literal 0xE0
compile_and_show "FUN_06018EC8 fix: literal 0xE0" '
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    REG_25B00217 = (unsigned char)0xE0;
    REG_25B00237 = (char)0xE0;
}
'

# FUN_06018EC8: Try with short local
compile_and_show "FUN_06018EC8 fix v2: short local" '
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    short val = 0x00E0;
    REG_25B00217 = (unsigned char)val;
    REG_25B00237 = (char)val;
}
'

# FUN_06038F34: Named variables
compile_and_show "FUN_06038F34 fix: named variables" '
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
'

# FUN_06038F34: Reorder stores
compile_and_show "FUN_06038F34 fix v2: reorder stores" '
void FUN_06038f34()
{
    *(int *)0x060635BC = 0;
    *(int *)0x060635C0 = 0;
    *(int *)0x060635C4 = 0;
    *(int *)0x060635C8 = 0;
    *(short *)0x060635B4 = 0;
    *(int *)0x060635B8 = 1;
}
'

# FUN_0603F4E0: volatile saved param
compile_and_show "FUN_0603F4E0 fix: volatile saved" '
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

# FUN_0603F500: volatile saved param
compile_and_show "FUN_0603F500 fix: volatile saved" '
extern void FUN_0603f3f6();

int FUN_0603f500(param_1)
    int param_1;
{
    int local_10;
    volatile int saved_param;
    char auStack_8[8];

    saved_param = param_1;
    FUN_0603f3f6(param_1, auStack_8, 4);
    FUN_0603f3f6(saved_param, &local_10, 4);
    return local_10;
}
'

# FUN_0601DB84: explicit flag variable
compile_and_show "FUN_0601DB84 fix: explicit flag" '
void FUN_0601db84()
{
    int counter;
    int flag;

    flag = 1;
    counter = 0x000186A0;

    do {
        counter = counter - 1;
        if (counter == 0) {
            *(int *)0x06086050 = flag;
            return;
        }
    } while (*(int *)0x25A02C20 != 0);
}
'

# FUN_0602E5E4: array index style
compile_and_show "FUN_0602E5E4 fix: array index" '
extern int *DAT_0607E944;
extern int DAT_06083264;
extern int DAT_06083268;

void FUN_0602e5e4()
{
    int *p;
    p = DAT_0607E944;
    DAT_06083264 = p[0x8E];
    DAT_06083268 = p[0x8F];
}
'
