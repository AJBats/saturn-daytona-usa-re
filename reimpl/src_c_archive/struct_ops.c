/* struct_ops.c -- Struct/array index calculations and accessors
 *
 * These functions compute struct offsets using shift-based multiplication.
 * FUN_0603F1E0: index * 12 (shift 2 + shift 3)
 * FUN_0603F1F0: index * 24 (shift 3 + shift 4)
 * FUN_0603F202: read byte at index*12 + base + 0xB
 * FUN_0603F216: read byte at index*24 + base + 0xB
 *
 * Original addresses: 0x0603F1E0, 0x0603F1F0, 0x0603F202, 0x0603F216
 */

int FUN_0603F1E0(int param_1, int param_2)
{
    return (param_1 << 2) + (param_1 << 3) + param_2;
}

int FUN_0603F1F0(int param_1, int param_2)
{
    return (param_1 << 3) + (param_1 << 4) + param_2;
}

unsigned char FUN_0603F202(int param_1, int param_2)
{
    int addr = (param_1 << 2) + (param_1 << 3) + param_2;
    return *(unsigned char *)(addr + 0xB);
}

char FUN_0603F216(int param_1, int param_2)
{
    return *(unsigned char *)((param_1 << 3) + (param_1 << 4) + param_2 + 0xB);
}
