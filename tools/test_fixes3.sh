#!/bin/bash
# Detailed comparison of fix opcodes vs expected
CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
TESTDIR=/mnt/d/Projects/SaturnReverseTest/tests

compile_and_compare() {
    local name="$1"
    local src="$2"
    local expected="$3"
    echo "========================================"
    echo "  $name"
    echo "========================================"
    echo "$src" > /tmp/fix_test.c
    if $CC1 -quiet -O2 -m2 -mbsr /tmp/fix_test.c -o /tmp/fix_test.s 2>/tmp/fix_test.err; then
        grep -P '^\t[a-z]' /tmp/fix_test.s | awk '{print $1}' | sed 's/,$//' > /tmp/fix_opcodes.txt
        tr -d '\r' < "$expected" | sed '/^$/d' | sed 's|bf/s|bf.s|;s|bt/s|bt.s|' > /tmp/fix_expected.txt

        echo "Our opcodes:"
        cat /tmp/fix_opcodes.txt
        echo ""
        echo "Expected opcodes:"
        cat /tmp/fix_expected.txt
        echo ""

        if diff -q /tmp/fix_opcodes.txt /tmp/fix_expected.txt > /dev/null 2>&1; then
            echo ">>> MATCH! <<<"
        else
            echo ">>> DIFF <<<"
            diff /tmp/fix_expected.txt /tmp/fix_opcodes.txt
        fi
        echo "Our count: $(wc -l < /tmp/fix_opcodes.txt)  Expected: $(wc -l < /tmp/fix_expected.txt)"
    else
        echo "COMPILE ERROR:"
        cat /tmp/fix_test.err
    fi
    echo ""
}

# FUN_06018EC8 fix
compile_and_compare "FUN_06018EC8" '
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    short val = 0x00E0;
    REG_25B00217 = (unsigned char)val;
    REG_25B00237 = (char)val;
}
' "$TESTDIR/FUN_06018EC8.expected"

# FUN_0603F4E0 fix
compile_and_compare "FUN_0603F4E0" '
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
' "$TESTDIR/FUN_0603F4E0.expected"

# FUN_0603F500 fix (struct-based)
compile_and_compare "FUN_0603F500" '
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
' "$TESTDIR/FUN_0603F500.expected"

# Also try FUN_06038F34 - more variations
echo "========================================"
echo "  FUN_06038F34 - all variations"
echo "========================================"
echo "Expected opcodes (15):"
tr -d '\r' < "$TESTDIR/FUN_06038F34.expected" | sed '/^$/d'
echo ""

# Original approach but with the stores in the exact order the original uses
# Original: mov #0,r4 / mov #1,r1 / load addr / mov.w r4,@r2 / ... / mov.l r4,@r2 * 4
# The key is: load both constants FIRST then do all the stores
for variant in "v5" "v6" "v7"; do
    if [ "$variant" = "v5" ]; then
        src='
void FUN_06038f34()
{
    register int r4 = 0;
    register int r1 = 1;

    *(short *)0x060635B4 = (short)r4;
    *(int *)0x060635B8 = r1;
    *(int *)0x060635BC = r4;
    *(int *)0x060635C0 = r4;
    *(int *)0x060635C4 = r4;
    *(int *)0x060635C8 = r4;
}
'
        desc="register ints"
    elif [ "$variant" = "v6" ]; then
        # What if we declare them in a different order?
        src='
void FUN_06038f34()
{
    int one;
    int zero;
    one = 1;
    zero = 0;

    *(short *)0x060635B4 = (short)zero;
    *(int *)0x060635B8 = one;
    *(int *)0x060635BC = zero;
    *(int *)0x060635C0 = zero;
    *(int *)0x060635C4 = zero;
    *(int *)0x060635C8 = zero;
}
'
        desc="int one/zero reverse order"
    else
        # What if we use a base pointer approach
        src='
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
'
        desc="base pointer approach"
    fi
    echo "  $variant ($desc):"
    echo "$src" > /tmp/fix_test.c
    $CC1 -quiet -O2 -m2 -mbsr /tmp/fix_test.c -o /tmp/fix_test.s 2>/dev/null
    grep -P '^\t[a-z]' /tmp/fix_test.s | awk '{print $1}' | sed 's/,$//'
    echo "  Count: $(grep -cP '^\t[a-z]' /tmp/fix_test.s)"
    echo ""
done
