#include "game.h"

/*
 * per_car_loop.c -- Per-car update loop (racing mode)
 *
 * Hand-translated from annotated ASM (asm/per_car_loop.s lines 55-219)
 * and verified instruction-by-instruction against build/aprog.s binary.
 *
 * Functions:
 *   FUN_0600E0C0 (0x0600E0C0) -- Per-car update loop
 *
 * Called as a tail-call from all car iteration wrappers (DE40, DE54,
 * DF66, DE70). Iterates over all non-player cars (starting at index 1),
 * running timer updates, AI/player physics, and rendering per car.
 *
 * NOTE: The asm/per_car_loop.s annotation incorrectly states that
 * AI cars go through the render check. Binary verification at
 * 0x0600E15A shows bra 0x0600E190 (loop_next), meaning AI cars
 * skip rendering entirely. Only the player path falls through to
 * the render check.
 *
 * Original address: 0x0600E0C0
 */

/* External dependencies - timer/countdown */
extern void FUN_06030A06(void);   /* per-car countdown timer trigger (unlabeled) */
extern void FUN_06030EE0(void);   /* per-car timer decrement (unlabeled) */

/* External dependencies - physics */
extern void FUN_0600E906(void);   /* AI physics entry */
extern void FUN_0600E71A(void);   /* player physics orchestrator */

/* External dependencies - rendering */
extern void FUN_060061C8(void);   /* pre-render setup */
extern void FUN_06027CA4(int buffer, int index);  /* 3D scene renderer */
extern void FUN_0603053C(int arg); /* render finalize */


/* ================================================================
 * FUN_0600E0C0 -- Per-Car Update Loop (0x0600E0C0)
 *
 * CONFIDENCE: DEFINITE (per_car_loop.s lines 60-219, binary verified)
 * Pool verified:
 *   0x0600E12C = 0x0607EBC4 (master flags)
 *   0x0600E130 = 0x06078900 (car array base)
 *   0x0600E0EA = 0x0268 (car struct size, word pool)
 *   0x0600E134 = 0x00008000 (player flag bitmask)
 *   0x0600E0F8 = 0x0607E940 (current car pointer storage)
 *   0x0600E114 = 0x06027CA4 (3D scene renderer)
 *   0x0600E138 = 0x0607EAE0 (demo mode skip flag)
 *   0x0600E1B0 = 0x06030A06 (timer trigger, unlabeled)
 *   0x0600E1B4 = 0x06030EE0 (timer decrement, unlabeled)
 *   0x0600E1B8 = 0x060061C8 (pre-render setup)
 *   0x0600E1BC = 0x06063EB0 (scene buffer 0)
 *   0x0600E1C0 = 0x06063E9C (scene buffer 1)
 *   0x0600E1C4 = 0x06063ED8 (scene buffer 2)
 *   0x0600E1C8 = 0x06063EC4 (scene buffer 3)
 *   0x0600E1CC = 0x0603053C (render finalize, unlabeled)
 *   0x0600E1D0 = 0x0607EA98 (car count / race param)
 *
 * Algorithm:
 *   1. Skip entirely if demo mode (*0x0607EAE0 != 0)
 *   2. Loop from car index 1 to car_count-1:
 *      a. Compute car_ptr = base + index * 0x268
 *      b. Store car_ptr to *0x0607E940
 *      c. Call timer trigger + timer decrement
 *      d. If master_flags & 0x8000: AI path (E906), skip to next car
 *      e. Else: player path (E71A), then check render flag
 *      f. If car[1] & 0x80: render (pre-render, 4x scene, finalize)
 *   3. Return
 *
 * IMPORTANT: Binary shows AI cars (step d) skip rendering entirely.
 * The annotation incorrectly says both paths reach .check_render.
 *
 * 78 instructions total. Uses 7 callee-saved registers.
 * ================================================================ */
void FUN_0600E0C0(void)
{
    unsigned int i;

    /* Demo mode check */
    if (*(volatile int *)0x0607EAE0 != 0)
        return;

    /* Iterate non-player cars: index 1 to car_count-1 */
    for (i = 1; i < *(volatile unsigned int *)0x0607EA98; i++) {
        int car_ptr = CAR_ARRAY_BASE + (int)(i * CAR_STRUCT_SIZE);

        /* Store current car pointer */
        *(volatile int *)0x0607E940 = car_ptr;

        /* Per-car timer updates */
        FUN_06030A06();
        FUN_06030EE0();

        /* Player vs AI dispatch */
        if (*(volatile int *)0x0607EBC4 & 0x8000) {
            /* AI car: run AI update, skip rendering */
            FUN_0600E906();
        } else {
            /* Player car: run physics, then check render */
            FUN_0600E71A();

            /* Render check: car byte[1] bit 7 */
            {
                int cp = *(volatile int *)0x0607E940;
                unsigned char render_flag = *(volatile unsigned char *)(cp + 1);

                if (render_flag & 0x80) {
                    /* Pre-render setup */
                    FUN_060061C8();

                    /* Render 4 scene buffers */
                    FUN_06027CA4(0x06063EB0, 0);
                    FUN_06027CA4(0x06063E9C, 1);
                    FUN_06027CA4(0x06063ED8, 2);
                    FUN_06027CA4(0x06063EC4, 3);

                    /* Finalize render */
                    FUN_0603053C(1);
                }
            }
        }
    }
}
