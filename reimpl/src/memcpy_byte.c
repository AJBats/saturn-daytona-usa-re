/* memcpy_byte.c -- Byte-level memory copy
 *
 * FUN_0602760C: Copy (param_3 - 1) bytes from param_2 to param_1.
 *   Note: the count is decremented before the loop, so it copies (n-1) bytes.
 *   This is likely an off-by-one in the decomp; the original may intend n bytes.
 *
 * Original address: 0x0602760C
 */

void FUN_0602760C(char *param_1, char *param_2, int param_3)
{
    int i = 0;
    param_3--;
    do {
        *(char *)(param_1 + i) = *(char *)(param_2 + i);
        i++;
    } while (param_3 > i);
}
