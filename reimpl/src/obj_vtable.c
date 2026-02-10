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

int FUN_0603F4B0(void)
{
    char buf[4];
    FUN_0603F3F6(buf);
    return buf[0];
}

int FUN_0603F4CC(int a, int b)
{
    short buf[2];
    FUN_0603F3F6(buf, b, 2);
    return buf[0];
}

int FUN_0603F520(int a, int b)
{
    int buf[1];
    FUN_0603F3F6(buf, b, 4);
    return buf[0];
}
