#include "game.h"

/*
 * physics_entry.c -- Physics pipeline entry points
 *
 * Hand-translated from build/aprog.s binary, verified instruction-by-instruction.
 * These functions are the entry points to the per-car physics pipeline,
 * called from the car iteration wrappers (DE40, DF66, DE54, DE70).
 *
 * Functions:
 *   FUN_0600E410 (0x0600E410) -- Standard physics entry (single player)
 *   FUN_0600E47C (0x0600E47C) -- Alternate physics entry (mode 1/2)
 *
 * Both copy CAR_PTR_TARGET to CAR_PTR_CURRENT, run subsystem updates,
 * then branch into physics/rendering pipelines.
 *
 * Original addresses: 0x0600E410, 0x0600E47C
 */

/* External dependencies */
extern void FUN_060081F4(void);   /* pre-physics subsystem update */
extern void FUN_060085B8(void);   /* brake force application */
extern void FUN_06030A06(void);   /* countdown timer trigger */
extern void FUN_06030EE0(void);   /* timer decrement */
extern void FUN_0600E71A(void);   /* player physics orchestrator */
extern void FUN_0600E7C8(void);   /* alternate physics path */
extern void FUN_0600A8BC(void);   /* audio update */
extern int  FUN_06006838(int x, int z);  /* grid coordinate pack */
extern void FUN_06005ECC(void);   /* pre-render setup */
extern void FUN_06027CA4(int buffer, int index);  /* 3D scene renderer */
extern void FUN_0600DA7C(void);   /* collision/update */
extern void FUN_0600CE66(void);   /* checkpoint/lap processing */
extern void FUN_0603053C(int arg); /* render finalize */
extern void FUN_0600D780(void);   /* post-physics tail-call */
extern unsigned int FUN_06027552(int a, int b);  /* fpmul */


/* ================================================================
 * FUN_0600E410 -- Standard Physics Entry (0x0600E410)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600E410-0x0600E454)
 * Pool verified:
 *   0x0600E45C = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600E460 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600E464 = 0x060081F4 (pre-physics update)
 *   0x0600E468 = 0x060085B8 (brake force)
 *   0x0600E46C = 0x06030A06 (timer trigger)
 *   0x0600E470 = 0x06030EE0 (timer decrement)
 *   0x0600E474 = 0x066505B3 (projection constant)
 *   0x0600E478 = 0x06027552 (fpmul)
 *   0x0600E456 = 0x00E4 (first store offset)
 *   0x0600E458 = 0x00E0 (second store offset)
 *
 * Pipeline:
 *   1. Copy TARGET car pointer to CURRENT
 *   2. FUN_060081F4 (pre-physics subsystem)
 *   3. FUN_060085B8 (brake force)
 *   4. FUN_06030A06 (countdown timer trigger)
 *   5. FUN_06030EE0 (timer decrement)
 *   6. FUN_0600E71A (player physics)
 *   7. Project Y: fpmul(car[0xC], 0x066505B3) >> 16, sign-extend
 *   8. Store to car[0xE4] and car[0xE0]
 *
 * Called from FUN_0600DE40 and FUN_0600DF66 (mode 0).
 * 35 instructions total.
 * ================================================================ */
void FUN_0600E410(void)
{
    int car;
    unsigned int raw;
    int projected;

    /* Step 1: Copy TARGET to CURRENT */
    car = CAR_PTR_TARGET;
    CAR_PTR_CURRENT = car;

    /* Steps 2-5: Subsystem updates */
    FUN_060081F4();
    FUN_060085B8();
    FUN_06030A06();
    FUN_06030EE0();

    /* Step 6: Player physics */
    FUN_0600E71A();

    /* Steps 7-8: Project Y and store */
    raw = FUN_06027552(*(volatile int *)((char *)car + 0xC), 0x066505B3);
    projected = (int)(short)(raw >> 16);
    *(volatile int *)((char *)car + 0xE4) = projected;
    *(volatile int *)((char *)car + 0xE0) = projected;
}


/* ================================================================
 * FUN_0600E47C -- Alternate Physics Entry (0x0600E47C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600E47C-0x0600E4F0)
 * Pool verified:
 *   0x0600E524 = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600E528 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600E52C = 0x0600A8BC (audio update)
 *   0x0600E530 = 0x060081F4 (pre-physics update)
 *   0x0600E534 = 0x060085B8 (brake force)
 *   0x0600E538 = 0x06030A06 (timer trigger)
 *   0x0600E53C = 0x06030EE0 (timer decrement)
 *   0x0600E540 = 0x06006838 (grid coordinate pack)
 *   0x0600E544 = 0x060786B8 (grid result storage)
 *   0x0600E548 = 0x06005ECC (pre-render setup)
 *   0x0600E54C = 0x06027CA4 (3D scene renderer)
 *   0x0600E550-E55C = scene buffer addresses
 *   0x0600E560 = 0x0600DA7C (collision/update)
 *   0x0600E564 = 0x0600CE66 (checkpoint/lap)
 *   0x0600E568 = 0x0603053C (render finalize)
 *   0x0600E56C = 0x0600D780 (post-physics tail-call)
 *
 * Pipeline:
 *   1. Copy TARGET car pointer to CURRENT
 *   2. FUN_0600A8BC (audio update)
 *   3. FUN_060081F4 (pre-physics)
 *   4. FUN_060085B8 (brake force)
 *   5. FUN_06030A06 (countdown timer)
 *   6. FUN_06030EE0 (timer decrement)
 *   7. FUN_0600E7C8 (alternate physics path)
 *   8. FUN_06006838(car[0x10], car[0x18]) → grid pack
 *   9. Store grid result to *0x060786B8
 *  10. FUN_06005ECC (pre-render setup)
 *  11. 4x FUN_06027CA4 (scene render buffers 0-3)
 *  12. FUN_0600DA7C (collision/update)
 *  13. FUN_0600CE66 (checkpoint/lap processing)
 *  14. FUN_0603053C(0) (render finalize)
 *  15. Tail-call FUN_0600D780 (post-physics)
 *
 * Called from FUN_0600DF66 (mode 1/2).
 * ~60 instructions total.
 * ================================================================ */
void FUN_0600E47C(void)
{
    int car;
    int grid_result;

    /* Step 1: Copy TARGET to CURRENT */
    car = CAR_PTR_TARGET;
    CAR_PTR_CURRENT = car;

    /* Steps 2-6: Audio + subsystem updates */
    FUN_0600A8BC();
    FUN_060081F4();
    FUN_060085B8();
    FUN_06030A06();
    FUN_06030EE0();

    /* Step 7: Alternate physics path */
    FUN_0600E7C8();

    /* Steps 8-9: Grid coordinate packing */
    grid_result = FUN_06006838(
        *(volatile int *)((char *)car + 0x10),   /* X */
        *(volatile int *)((char *)car + 0x18));  /* Z */
    *(volatile int *)0x060786B8 = grid_result;

    /* Step 10: Pre-render setup */
    FUN_06005ECC();

    /* Step 11: Render 4 scene buffers */
    FUN_06027CA4(0x06063EB0, 0);
    FUN_06027CA4(0x06063E9C, 1);
    FUN_06027CA4(0x06063ED8, 2);
    FUN_06027CA4(0x06063EC4, 3);

    /* Steps 12-14: Collision, lap, finalize */
    FUN_0600DA7C();
    FUN_0600CE66();
    FUN_0603053C(0);

    /* Step 15: Tail-call post-physics */
    FUN_0600D780();
}
