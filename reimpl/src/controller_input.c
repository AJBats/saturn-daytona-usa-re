/* controller_input.c -- Controller setup and input initialization
 *
 * FUN_06012400: Initialize 4 controller slots and set flag
 *   Calls 0x0601D5F4 once if not initialized, then calls FUN_06012450
 *   for 4 controller data blocks at 0x060788C0-0x060788E4 (12 bytes apart)
 *
 * FUN_0601444C: Get frame counter value and display it as a VDP number
 *
 * Original addresses: 0x06012400, 0x0601444C
 */

extern void FUN_06012450(int, int);

void FUN_06012400(void)
{
    char *ptr = (char *)0x060788F0;
    if (*ptr == 0) {
        (*(void (*)(int, int))0x0601D5F4)(0, 0xAE110FFF);
        *(char *)0x060788F0 = 1;
    }
    FUN_06012450(0x060788C0, 0);
    FUN_06012450(0x060788CC, 1);
    FUN_06012450(0x060788D8, 2);
    FUN_06012450(0x060788E4, 3);
}

void FUN_0601444C(void)
{
    int val;
    val = (*(int (*)())0x06034FE0)();
    (*(void (*)(int, int, int, int))0x06028430)(0xc, 0x1c8, 0x18, val);
}
