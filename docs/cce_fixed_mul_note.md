# Note for CCE engineer — fixed-point multiply in C decompilation

## Discovery

Cygnus 2.7-96Q3 does NOT generate `dmuls.l` from `long long` multiply expressions. Instead it emits `__muldi3` library calls (software 64x64->64), which is functionally different from the hardware `dmuls.l` (32x32->64).

## CCE current approach

CCE's decompilation (FUN_06037E28.c) calls `DAT_06048180()` as an extern for fixed-point multiply. This works but means the multiply is a function call, not inlined.

## Better solution

Cygnus 2.7 supports GCC inline asm. This generates perfect `dmuls.l + xtrct` inline:

```c
static int fixed_mul(int a, int b)
{
    int hi, lo;
    asm("dmuls.l %2,%3\n\tsts mach,%0\n\tsts macl,%1"
        : "=r"(hi), "=r"(lo) : "r"(a), "r"(b));
    return (hi << 16) | ((unsigned int)lo >> 16);
}
```

Compiles to exactly:

```asm
dmuls.l r4,r5
sts mach,r0
sts macl,r1
shll16  r0
shlr16  r1
rts
or  r1,r0
```

No library calls, no extern function, inlines at every call site.

## Question

Is CCE using `DAT_06048180` because the original code actually called that function, or was it a workaround for the `__muldi3` issue? If it's a workaround, switching to inline asm would produce tighter code that better matches the original.

## Tested on

- Cygnus 2.7-96Q3 SOA-960904 (SH-2 target)
- DOSBox-X on Windows 11
- Flags: `GCC -O2 -fomit-frame-pointer -x c -S`
