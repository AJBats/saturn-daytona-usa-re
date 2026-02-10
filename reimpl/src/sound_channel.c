/* sound_channel.c -- Sound channel lookup and VBLANK sync
 *
 * FUN_06020E3C: Find a sound channel by ID in a 16-entry table.
 *   Each entry is 0x44 (68) bytes apart at base 0x0608782C.
 *   Returns the index (0-15) if found, or 16 if not found.
 *
 * FUN_06026CE0: VBLANK synchronization -- write 1 to 0x060635C4,
 *   then busy-wait counting iterations until it changes (cleared by VBlank ISR).
 *   Stores the iteration count at 0x0605A010 (frame timing metric).
 *
 * FUN_06020946: Clear VDP name table entries for 28 slots
 *   Calls 0x06035228 first (matrix reset?), then loops 28 times
 *   writing zero data at computed offsets.
 *
 * Original addresses: 0x06020E3C, 0x06026CE0, 0x06020946
 */

unsigned char FUN_06020E3C(char param_1)
{
    unsigned char i = 0;
    do {
        if (param_1 == ((int *)0x0608782C)[(short)((unsigned short)i * 0x44)]) {
            return i;
        }
        i = i + 1;
    } while (i < 0x10);
    return i;
}

void FUN_06026CE0(void)
{
    int count;

    count = 0;
    *(volatile int *)0x060635C4 = 1;
    do {
        count = count + 1;
    } while (*(volatile int *)0x060635C4 == 1);
    *(int *)0x0605A010 = count;
}

void FUN_06020946(void)
{
    char auStack_70[96];
    unsigned char i;

    (*(void (*)())0x06035228)();
    i = 0;
    do {
        (*(void (*)(int, char *, int, int))0x06028400)(4, auStack_70, (unsigned int)i << 7, 0);
        (*(void (*)(int, char *, int, int))0x06028400)(4, auStack_70, ((unsigned int)(i << 6) + 0x2c) << 1, 0);
        i = i + 1;
    } while (i < 0x1c);
}
