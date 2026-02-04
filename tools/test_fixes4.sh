#!/bin/bash
# More targeted fix attempts
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
        cat /tmp/fix_opcodes.txt | paste - - - - -
        echo ""
        echo "Expected opcodes:"
        cat /tmp/fix_expected.txt | paste - - - - -
        echo ""

        if diff -q /tmp/fix_opcodes.txt /tmp/fix_expected.txt > /dev/null 2>&1; then
            echo ">>> MATCH! <<<"
        else
            echo ">>> DIFF (count ours=$(wc -l < /tmp/fix_opcodes.txt) exp=$(wc -l < /tmp/fix_expected.txt)) <<<"
            diff --side-by-side /tmp/fix_expected.txt /tmp/fix_opcodes.txt
        fi
    else
        echo "COMPILE ERROR:"
        cat /tmp/fix_test.err
    fi
    echo ""
}

# FUN_06018EC8: The original loads a SHORT (0x00E0) and does extu.b
# Then the second store uses the original (non-masked) value
# So both stores get the SAME byte but through different paths:
#   store1: extu.b(val) -> byte  (the 0xE0 byte via unsigned mask)
#   store2: val directly as byte (mov.b just writes low 8 bits)
# The key is that both writes produce byte 0xE0.
# The original loads val once as mov.w (short) and uses it for both stores.
# We need extu.b to appear in our output.

compile_and_compare "FUN_06018EC8: extern short + casts" '
extern short DAT_06018ed6;
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    REG_25B00217 = (unsigned char)DAT_06018ed6;
    REG_25B00237 = (char)DAT_06018ed6;
}
' "$TESTDIR/FUN_06018EC8.expected"

# The original needs extu.b between the short load and the first store
# That means the first cast must be unsigned char (extu.b)
# And the second store uses the full short value (mov.b just takes low byte)

# Let me try: what if the short is loaded from inline address?
compile_and_compare "FUN_06018EC8: inline short ptr" '
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
    short s = *(short *)0x06018ed6;
    REG_25B00217 = (unsigned char)s;
    REG_25B00237 = (char)s;
}
' "$TESTDIR/FUN_06018EC8.expected"

# FUN_0603F4E0: The issue is instruction ordering
# Expected: sts.l, mov, add, mov, mov.l, bsr, add, mov, mov, bsr, mov.l, mov.w, add, lds.l, rts, nop
# Ours:     sts.l, add, mov.l, mov, add, bsr, mov, mov.l, mov, bsr, mov, mov.w, add, lds.l, rts, nop
# The instruction sequences are nearly identical but reordered.
# Expected has mov #2 before add #-12 (setup r6 before stack alloc)
# Expected has mov.l in bsr delay slot for 2nd call, not before

# Try reordering declarations/operations
compile_and_compare "FUN_0603F4E0: reorder v2" '
extern void FUN_0603f3f6();

int FUN_0603f4e0(param_1)
    int param_1;
{
    volatile int saved_param;
    short local_10[2];
    char auStack_8[8];

    saved_param = param_1;
    FUN_0603f3f6(param_1, auStack_8, 2);
    FUN_0603f3f6(saved_param, local_10, 2);
    return (int)local_10[0];
}
' "$TESTDIR/FUN_0603F4E0.expected"

# FUN_0603F500: Also check struct version carefully
compile_and_compare "FUN_0603F500: struct v3" '
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

# FUN_06038F34: The original uses r2 for addresses, r4 for zero, r1 for one
# Expected: mov #0,r4 / mov #1,r1 / then address loads in r2
# GCC uses r0 for addresses.
# The issue is: GCC loads addr to r0, then constant, then store
# Original loads BOTH constants first, THEN does addr+store pairs
# There are 6 address loads and the original manages with just 3 mov# insns total

# What if we try a completely different approach: make the addresses into an array?
compile_and_compare "FUN_06038F34: struct approach" '
struct block {
    short s;
    short pad;
    int a;
    int b;
    int c;
    int d;
    int e;
};

void FUN_06038f34()
{
    struct block *p = (struct block *)0x060635B4;
    p->s = 0;
    p->a = 1;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
}
'  "$TESTDIR/FUN_06038F34.expected"
