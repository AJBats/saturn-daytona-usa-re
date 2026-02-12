/* subsystem_setup.c -- Subsystem initialization routines
 *
 * Functions:
 *   FUN_060198E0 (0x060198E0) -- Pre-race subsystem init with state byte config
 *   FUN_0601550C (0x0601550C) -- Struct array rotation/position init loop
 *
 * FUN_060198E0: Calls configuration helpers, writes state bytes, then
 * tail-calls into the main subsystem handler chain.
 *
 * FUN_0601550C: Copies position data from source array (0x0605B838) into
 * struct array entries at base 0x06084FC8 (stride 0x44), sets rotation
 * values, and increments a counter byte for the given slot.
 *
 * Original addresses: 0x060198E0, 0x0601550C
 */

extern void FUN_0602853E(int param);
extern int *FUN_06028560(void);
extern void FUN_06019928(void);
extern void course_select_display_update(void);
extern void FUN_0601a940(void);

/* State configuration bytes */
#define SUBSYS_STATE_A   (*(volatile unsigned char *)0x06085FF1)
#define SUBSYS_STATE_B   (*(volatile unsigned char *)0x06085FF6)
#define SUBSYS_STATE_C   (*(volatile unsigned char *)0x06085FF7)


/* ================================================================
 * FUN_060198E0 -- Pre-Race Subsystem Init (0x060198E0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060198E0-0x0601990C)
 * Pool verified:
 *   0x06019910 = 0x0602853E (config helper A)
 *   0x06019914 = 0x06028560 (config helper B)
 *   0x06019918 = 0x06085FF1 (state byte A)
 *   0x0601991C = 0x06085FF6 (state byte B)
 *   0x06019920 = 0x06085FF7 (state byte C)
 *   BSR target 0x06019928 (local helper)
 *   BSR target 0x0601A80C (secondary init)
 *   0x06019924 = 0x0601A940 (tail-call target)
 *
 * 22 instructions. Saves PR. Tail-calls FUN_0601a940.
 * ================================================================ */
void FUN_060198E0(void)
{
    FUN_0602853E(12);
    FUN_06028560();

    /* Configure state bytes */
    SUBSYS_STATE_A = 1;
    SUBSYS_STATE_B = 1;
    SUBSYS_STATE_C = 0xFF;

    /* Chain into subsystem handlers */
    FUN_06019928();
    course_select_display_update();
    FUN_0601a940();  /* original: tail-jump via jmp @r3 */
}


/* ================================================================
 * FUN_0601550C -- Struct Array Position/Rotation Init (0x0601550C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601550C-0x0601559A)
 * Pool verified:
 *   [0x0601559C] = 0x0605B838 (source array, 8 bytes per entry)
 *   [0x060155A0] = 0x06084FC8 (destination struct base, stride 0x44)
 *
 * Loops over 4 entries:
 *   - Copies 2 ints from source[i*8] to dest[i*0x44+0x1C] and [+0x20]
 *   - Sets rotation value at dest[i*0x44+0x24] to 96 (default)
 *   - For entries 1 and 2, overrides rotation to 80
 * After the loop, increments a counter byte at dest[param*0x44+0x02].
 *
 * Leaf function (no PR save). 48 instructions. Saves r10-r12,r14.
 * Parameter: r4 = slot index for counter increment.
 * ================================================================ */
void FUN_0601550C(int param)
{
    volatile char *src = (volatile char *)0x0605B838;
    volatile char *base = (volatile char *)0x06084FC8;
    int i;

    for (i = 0; i < 4; i++) {
        int src_off = i << 3;     /* i * 8 */
        int dst_off = (short)((i << 2) + (i << 6));  /* i * 68, sign-extended */

        *(volatile int *)(base + dst_off + 0x1C) = *(volatile int *)(src + src_off);
        *(volatile int *)(base + dst_off + 0x20) = *(volatile int *)(src + src_off + 4);
        *(volatile int *)(base + dst_off + 0x24) = 96;  /* 0x60 default rotation */

        if (i == 1 || i == 2) {
            *(volatile int *)(base + dst_off + 0x24) = 80;  /* 0x50 override */
        }
    }

    /* Increment counter byte at param's struct entry */
    {
        int idx = (unsigned char)param;
        int off = (short)((idx << 2) + (idx << 6));  /* idx * 68, sign-extended */
        unsigned char val = *(volatile unsigned char *)(base + off + 2);
        *(volatile unsigned char *)(base + off + 2) = (unsigned char)(val + 1);
    }
}
