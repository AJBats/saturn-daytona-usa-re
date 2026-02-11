#include "game.h"

/*
 * camera_setup.c -- Pre-update camera/AI setup
 *
 * Hand-translated from annotated ASM (asm/per_car_loop.s lines 222-302)
 * and verified instruction-by-instruction against build/aprog.s binary.
 *
 * Functions:
 *   FUN_0600E99C (0x0600E99C) -- Camera target projection + state cleanup
 *
 * Called from FUN_0600DE54 (VS mode car update wrapper) before the
 * main per-car physics pipeline (FUN_0600E0C0).
 *
 * NOTE: The asm/per_car_loop.s annotation has OFFSET ERRORS:
 *   Annotation says camera stores go to car[0x228]/[0x21C] -- WRONG
 *   Binary shows camera stores go to car[0xE4]/[0xE0]
 *   Annotation says cleanup clears car[0x1EC]/[0xE0] -- WRONG
 *   Binary shows cleanup clears car[0x228]/[0x21C]
 *   Pool verification at 0x0600E9E8=0x00E4, 0x0600E9EA=0x00E0,
 *   0x0600E9E2=0x0228 confirms the correct offsets.
 *
 * Original address: 0x0600E99C
 */

/* External dependencies */
extern void FUN_0600E906(void);                  /* AI physics entry */
extern unsigned int FUN_06027552(int a, int b);  /* fpmul: (a*b)>>16 */


/* ================================================================
 * FUN_0600E99C -- Pre-Update Camera/AI Setup (0x0600E99C)
 *
 * CONFIDENCE: DEFINITE (per_car_loop.s lines 234-302, binary verified)
 * Pool verified:
 *   0x0600EA08 = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600EA0C = 0x0607EAD8 (camera mode flag)
 *   0x0600EA10 = 0x066505B3 (projection constant)
 *   0x0600E9FC = 0x06027552 (fpmul address)
 *   0x0600EA14 = 0x0607EAD0 (global mode indicator)
 *   0x0600E9E8 = 0x00E4 (first camera store offset)
 *   0x0600E9EA = 0x00E0 (second camera store offset)
 *   0x0600E9EC = 0x01EC (state check offset)
 *   0x0600E9E2 = 0x0228 (first cleanup offset)
 *
 * Algorithm:
 *   1. Call FUN_0600E906 (AI update)
 *   2. If camera mode (*0x0607EAD8) == 0:
 *      - Project car Y position (car[0xC]) through fpmul(Y, 0x066505B3)
 *      - Shift result >> 16, sign-extend to 32-bit
 *      - Store to car[0xE4] and car[0xE0]
 *   3. If car[0x1EC] == 0:
 *      - Clear *0x0607EAD0
 *      - Clear car[0x228] and car[0x21C]
 *
 * 35 instructions. Uses callee-saved r14 for car pointer.
 * ================================================================ */
void FUN_0600E99C(void)
{
    int car = CAR_PTR_TARGET;

    FUN_0600E906();

    /* Camera projection when not in special mode */
    if (*(volatile int *)0x0607EAD8 == 0) {
        unsigned int raw;
        int projected;

        raw = FUN_06027552(*(volatile int *)((char *)car + 0xC), 0x066505B3);
        projected = (int)(short)(raw >> 16);

        *(volatile int *)((char *)car + 0xE4) = projected;
        *(volatile int *)((char *)car + 0xE0) = projected;
    }

    /* State cleanup: clear camera targets when state is 0 */
    if (*(volatile int *)((char *)car + 0x1EC) == 0) {
        *(volatile int *)0x0607EAD0 = 0;
        *(volatile int *)((char *)car + 0x228) = 0;
        *(volatile int *)((char *)car + 0x21C) = 0;
    }
}
