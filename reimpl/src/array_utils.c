/* array_utils.c -- Array/memory block operations
 *
 * FUN_06033504: Increment block counter at 0x0605A008 and offset table at 0x060785FC
 * lap_counter_display: Decrement a timer/counter at offset 0x150 from a base pointer
 * FUN_06038044: Copy 8 shorts from source to a fixed physics mode table
 * FUN_060370C0: Zero 15 bytes of a struct (2 ints + 7 chars)
 * FUN_0603F8B8: Write 6 int values to consecutive array slots
 * FUN_0603F9B8: Reset object, then set field 0 and field 2
 *
 * Original addresses: 0x06033504, 0x06030EE0, 0x06038044, 0x060370C0,
 *   0x0603F8B8, 0x0603F9B8
 */

extern void FUN_0603FA1A(int *, int);

char *FUN_06033504(void)
{
    char *puVar1 = (char *)0x0605A008;
    *(int *)0x0605A008 = *(int *)0x0605A008 + 1;
    *(int *)0x060785FC = *(int *)0x060785FC + 0x20;
    return puVar1;
}

int lap_counter_display(void)
{
    short *p;
    short val;

    p = (short *)(*(int *)0x0607E940 + 0x0150);
    val = *p;
    if (val > 0) {
        *p = val - 1;
    }
    return 0x0150;
}

int FUN_06038044(int param_1)
{
    unsigned short i;
    int base = 0x060A3D88;

    i = 0;
    do {
        *(short *)(base + (i << 1) + 0x10) = *(short *)(param_1 + (i << 1));
        i = i + 1;
    } while (i < 8);
    return base;
}

void FUN_060370C0(int *param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    *((char *)param_1 + 8) = 0;
    *((char *)param_1 + 9) = 0;
    *((char *)param_1 + 10) = 0;
    *((char *)param_1 + 11) = 0;
    *((char *)param_1 + 12) = 0;
    *((char *)param_1 + 13) = 0;
    *((char *)param_1 + 14) = 0;
}

int *FUN_0603F8B8(int *param_1, int p2, int p3, int p4, int p5, int p6, int p7)
{
    *param_1 = p2;
    param_1[1] = p3;
    param_1[2] = p4;
    param_1[3] = p5;
    param_1[4] = p6;
    param_1[5] = p7;
    return param_1;
}

#if 0 /* FUN_0603F9B8 -- replaced by ASM import */
void FUN_0603F9B8(int *param_1, int param_2, int param_3)
{
    FUN_0603FA1A(param_1, 0xffffffff);
    *param_1 = param_2;
    param_1[2] = param_3;
}
#endif

/* FUN_0603F9B8 -- original binary (4 bytes) */
__asm__(
    ".section .text.FUN_0603F9B8, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603F9B8\n"
    ".type _FUN_0603F9B8, @function\n"
    "_FUN_0603F9B8:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x43\n"  /* 0x0603F9B8 */
);
