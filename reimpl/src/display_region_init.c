/* display_region_init.c -- Display region configuration
 *
 * Functions:
 *   FUN_0601B074 (0x0601B074) -- Initialize display region for background
 *
 * Calls FUN_06039100 to configure a VDP display region with fixed
 * parameters: position (0,48), size 48, bounds (256,352).
 *
 * Original address: 0x0601B074
 */

/* VDP display region configuration (8 params: 4 register + 4 stack shorts) */
extern unsigned int FUN_06039100(unsigned int param_1, int param_2,
    unsigned int param_3, int param_4,
    short param_5, short param_6, short param_7, short param_8);


/* ================================================================
 * FUN_0601B074 -- Display Region Init (0x0601B074)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0601B074-0x0601B094)
 * Pool verified:
 *   0x0601B0C6 = 0x0100 (256, horizontal bound, mov.w pool)
 *   0x0601B0C8 = 0x0160 (352, vertical bound, mov.w pool)
 *   0x0601B0CC = 0x06039100 (display region config function)
 *
 * 16 instructions. Saves PR.
 * ================================================================ */
void FUN_0601B074(void)
{
    /* Configure display region:
     *   position = (0, 48)
     *   size = (48, 0)
     *   bounds = (352, 256, 352, 256)
     */
    FUN_06039100(0, 48, 48, 0, (short)352, (short)256, (short)352, (short)256);
}
