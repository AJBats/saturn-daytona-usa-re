/* sound_channel.c -- Sound channel lookup and VBLANK sync
 *
 * FUN_06020E3C: Find a sound channel by ID in a 16-entry table.
 *   Each entry is 0x44 (68) bytes apart at base 0x0608782C.
 *   Returns the index (0-15) if found, or 16 if not found.
 *
 * vdp1_texture_palette_init: VBLANK synchronization -- write 1 to 0x060635C4,
 *   then busy-wait counting iterations until it changes (cleared by VBlank ISR).
 *   Stores the iteration count at 0x0605A010 (frame timing metric).
 *
 * FUN_06020946: Clear VDP name table entries for 28 slots
 *   Calls 0x06035228 first (matrix reset?), then loops 28 times
 *   writing zero data at computed offsets.
 *
 * FUN_06014468: Sound volume parameter from input state.
 *   Reads input word, inverts low byte, shifts right 3, clamps to max.
 *   If value changed, sends sound command. Looks up table entry.
 *
 * Original addresses: 0x06020E3C, 0x06026CE0, 0x06020946, 0x06014468
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

void vdp1_texture_palette_init(void)
{
    int count;

    count = 0;
    *(volatile int *)0x060635C4 = 1;
    do {
        count = count + 1;
    } while (*(volatile int *)0x060635C4 == 1);
    *(int *)0x0605A010 = count;
}

#if 0 /* FUN_06020946 -- replaced by ASM import */
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
#endif


/* sound_cmd_dispatch: FUN_0601D5F4(r4, r5) */
extern void FUN_0601D5F4(int r4, int r5);

/* ================================================================
 * FUN_06014468 -- Sound Volume Parameter from Input (0x06014468)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06014468-0x060144D6)
 * Pool verified:
 *   [0x060144E8] = 0x06084B08 (current volume value)
 *   [0x060144EC] = 0x06063D98 (input state base)
 *   [0x060144F0] = 0x0000FFFF (inversion mask)
 *   [0x060144F4] = 0x06084B0C (previous volume value)
 *   [0x060144F8] = 0x06084B18 (stage counter)
 *   [0x060144FC] = 0xAB111DFF (sound command ID)
 *   [0x06014500] = 0x0601D5F4 (sound_cmd_dispatch)
 *   [0x06014504] = 0x0605AD2C (lookup table base)
 *   [0x06014508] = 0x06084B20 (lookup result destination)
 *
 * Reads 16-bit input word at 0x06063D9C, inverts low byte, arithmetic
 * right-shifts by 3, clamps to max_val. Saves old value, sets new.
 * If stage counter >= 3, overrides to 27 or 28 depending on value.
 * If value changed from previous, sends sound command 0xAB111DFF.
 * Finally looks up table[value] and stores result.
 *
 * 36 instructions. Non-leaf (calls sound_cmd_dispatch). Saves r14+PR.
 * Parameters: r4 unused (overwritten), r5 = max clamp value.
 * No callers found in binary — likely called via function pointer table.
 * ================================================================ */
void FUN_06014468(int unused, int max_val)
{
    (void)unused;

    volatile int *vol_cur = (volatile int *)0x06084B08;
    volatile int *vol_prev = (volatile int *)0x06084B0C;

    /* Read input state, invert low byte, shift right 3 */
    unsigned int raw = *(volatile unsigned short *)0x06063D9C;
    raw ^= 0xFFFF;
    raw &= 0xFF;
    int value = (int)raw >> 3;  /* arithmetic shift right 3 */
    value = (unsigned short)value;

    /* Clamp to max_val */
    if ((short)value > (short)max_val) {
        value = (unsigned short)max_val;
    }

    /* Save previous, set current */
    *vol_prev = *vol_cur;
    *vol_cur = (unsigned short)value;

    /* Stage override: if stage counter >= 3, override volume */
    if ((unsigned int)*(volatile int *)0x06084B18 >= 3u) {
        if ((short)(unsigned short)value >= 15) {
            *vol_cur = 28;
        } else {
            *vol_cur = 27;
        }
    }

    /* If value changed, send sound command */
    if (*vol_cur != *vol_prev) {
        FUN_0601D5F4(0, (int)0xAB111DFF);
    }

    /* Lookup table and store result */
    {
        int cur = *vol_cur;
        unsigned char entry = *(volatile unsigned char *)(0x0605AD2C + cur);
        *(volatile int *)0x06084B20 = entry;
    }
}

/* FUN_06020946 -- original binary (10 bytes) */
__asm__(
    ".section .text.FUN_06020946, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06020946\n"
    ".type _FUN_06020946, @function\n"
    "_FUN_06020946:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0xEB, 0x1C\n"  /* 0x06020946 */
);
