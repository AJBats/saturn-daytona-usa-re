/* obj_vtable.c -- Object vtable init and data accessor
 *
 * FUN_0603F3DA: Initialize an object descriptor (5 fields)
 *   [0] = pointer to param_2 (resource pointer)
 *   [1] = 0x043C + global base offset
 *   [2] = 0xFFFFFFFF (sentinel/invalid)
 *   [3] = 0
 *   [4] = read from param_2->field_10
 *
 * FUN_0603F4B0: Call FUN_0603F3F6 to read 1 byte and return it
 * FUN_0603F4CC: Call FUN_0603F3F6 to read 2 bytes (short) and return it
 * FUN_0603F520: Call FUN_0603F3F6 to read 4 bytes (int) and return it
 *
 * FUN_0603F3F6 is a generic "read N bytes from resource stream" function.
 *
 * Original addresses: 0x0603F3DA, 0x0603F4B0, 0x0603F4CC, 0x0603F520
 */

extern void FUN_0603F3F6(void *buf, ...);

void FUN_0603F3DA(int *param_1, int *param_2)
{
    *param_1 = (int)param_2;
    param_1[1] = 0x043C + *(int *)0x060A4D14;
    param_1[2] = 0xffffffff;
    param_1[4] = *(int *)(*param_2 + 0x10);
    param_1[3] = 0;
}

#if 0 /* FUN_0603F4B0 -- replaced by ASM import */
int FUN_0603F4B0(void)
{
    char buf[4];
    FUN_0603F3F6(buf);
    return buf[0];
}
#endif

/* FUN_0603F4B0 -- original binary (28 bytes) */
__asm__(
    ".section .text.FUN_0603F4B0, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603F4B0\n"
    ".global _FUN_0603f4b0\n"
    ".type _FUN_0603F4B0, @function\n"
    "_FUN_0603F4B0:\n"
    "_FUN_0603f4b0:\n"
    ".byte 0x4F, 0x22, 0x7F, 0xFC, 0xBF, 0x9F, 0x65, 0xF3, 0x60, 0xF0, 0x7F, 0x04, 0x4F, 0x26, 0x00, 0x0B\n"  /* 0x0603F4B0 */
    ".byte 0x00, 0x09, 0x08, 0x00, 0x06, 0x03, 0xB2, 0x1C, 0x06, 0x03, 0x60, 0xFC\n"  /* 0x0603F4C0 */
);


/* FUN_0603F4CC -- original binary (20 bytes) */
__asm__(
    ".section .text.FUN_0603F4CC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603F4CC\n"
    ".global _FUN_0603f4cc\n"
    ".type _FUN_0603F4CC, @function\n"
    "_FUN_0603F4CC:\n"
    "_FUN_0603f4cc:\n"
    ".byte 0x4F, 0x22, 0xE6, 0x02, 0x7F, 0xFC, 0xBF, 0x90, 0x65, 0xF3, 0x60, 0xF1, 0x7F, 0x04, 0x4F, 0x26\n"  /* 0x0603F4CC */
    ".byte 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0603F4DC */
);


/* FUN_0603F520 -- original binary (20 bytes) */
__asm__(
    ".section .text.FUN_0603F520, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603F520\n"
    ".global _FUN_0603f520\n"
    ".type _FUN_0603F520, @function\n"
    "_FUN_0603F520:\n"
    "_FUN_0603f520:\n"
    ".byte 0x4F, 0x22, 0xE6, 0x04, 0x7F, 0xFC, 0xBF, 0x66, 0x65, 0xF3, 0x60, 0xF2, 0x7F, 0x04, 0x4F, 0x26\n"  /* 0x0603F520 */
    ".byte 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0603F530 */
);

