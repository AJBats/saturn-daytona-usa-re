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
 *   FUN_0600E4F2 (0x0600E4F2) -- Full pipeline entry (DE70 mode)
 *
 * Both copy CAR_PTR_TARGET to CAR_PTR_CURRENT, run subsystem updates,
 * then branch into physics/rendering pipelines.
 *
 * Original addresses: 0x0600E410, 0x0600E47C, 0x0600E4F2
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
extern void FUN_0600D780(int player_flag);  /* checkpoint change detection */
extern unsigned int FUN_06027552(int a, int b);  /* fpmul */

/* E4F2-specific dependencies */
extern void FUN_0602ECF2(void);   /* render pipeline (non-countdown path) */
extern void FUN_0600DB64(void);   /* player-only post-render */
extern void FUN_0600EA18(int car); /* post-physics position update */
extern void FUN_0602D9F0(void);   /* VDP1 command render (tail-call) */
extern void FUN_0600C994(void);   /* heading/course processing */


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
    *(volatile int *)((char *)car + CAR_PROJECTED_B) = projected;
    *(volatile int *)((char *)car + CAR_PROJECTED_A) = projected;
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

    /* Step 15: Tail-call post-physics (r4 undefined from prior jsr) */
    FUN_0600D780(0);
}


/* ================================================================
 * FUN_0600E4F2 -- Full Pipeline Physics Entry (0x0600E4F2)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600E4F2-0x0600E718)
 * Pool verified:
 *   0x0600E570 = 0x060786BC (countdown timer address)
 *   0x0600E574 = 0x06063D9E (display source word)
 *   0x0600E578 = 0x06063F44 (display dest word)
 *   0x0600E524 = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600E528 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600E57C = 0x06078900 (CAR_ARRAY_BASE)
 *   0x0600E522 = 0x0268 (car struct size, word pool)
 *   0x0600E580 = 0x0607E948 (secondary car pointer storage)
 *   0x0600E6A0 = 0x060081F4 (pre-physics)
 *   0x0600E6A4 = 0x060085B8 (brake force)
 *   0x0600E6A8 = 0x06030A06 (timer trigger)
 *   0x0600E6AC = 0x06030EE0 (timer decrement)
 *   0x0600E6B0 = 0x06078635 (pause/skip flag byte)
 *   0x0600E6B4 = 0x060786C0 (X velocity delta)
 *   0x0600E6B8 = 0x060786C4 (Z velocity delta)
 *   0x0600E6BC = 0x060786C8 (rotation delta, word)
 *   0x0600E6C0 = 0x06063EF0 (rotation store)
 *   0x0600E6C4 = 0x06006838 (grid pack)
 *   0x0600E6C8 = 0x060786B8 (grid result storage)
 *   0x0600E6CC = 0x06005ECC (pre-render setup)
 *   0x0600E6D0 = 0x0602ECF2 (render pipeline)
 *   0x0600E6D4 = 0x06027CA4 (scene renderer)
 *   0x0600E6D8-E6E4 = scene buffer addresses
 *   0x0600E69C = 0x01B0 (rotation copy offset, word pool)
 *   0x0600E6E8 = 0x0600DB64 (player-only post-render)
 *   0x0600E6EC = 0x0600DA7C (collision/update)
 *   0x0600E6F0 = 0x0600CE66 (checkpoint/lap)
 *   0x0600E6F4 = 0x0603053C (render finalize)
 *   0x0600E6F8 = 0x0600D780 (checkpoint change detect)
 *   0x0600E69E = 0x0228 (velocity source offset, word pool)
 *   0x0600E6FC = 0x0607EA9C (velocity factor)
 *   0x0600E700 = 0x0600C994 (heading processing)
 *   0x0600E704 = 0x06083255 (VDP render flag byte)
 *   0x0600E708 = 0x0602D9F0 (VDP1 render tail-call)
 *
 * Algorithm:
 *   1. Copy word from *0x06063D9E to *0x06063F44
 *   2. Copy TARGET car pointer to CURRENT
 *   3. Store car[1] address to *0x0607E948
 *   4. Set is_non_player: 0 if car==car[0], else 1
 *   5. Subsystem updates: 060081F4, 060085B8, 06030A06, 06030EE0
 *   6. If countdown (*0x060786BC > 0) and skip flag (*0x06078635 == 0):
 *      a. Decrement countdown
 *      b. Add position/rotation deltas from 0x060786C0/C4/C8
 *      c. Copy updated rotation to car[0x30], car[0x28], *0x06063EF0
 *      d. Grid pack + pre-render (NO 4x scene render)
 *   7. Else (normal path):
 *      a. FUN_0602ECF2 (render pipeline)
 *      b. Grid pack + pre-render + 4x scene render
 *   8. Convergence: car[0x1B0] = car[0x20]
 *   9. If player (is_non_player==0): FUN_0600DB64
 *  10. FUN_0600DA7C, FUN_0600CE66, FUN_0603053C(0)
 *  11. FUN_0600D780(is_non_player)
 *  12. Velocity projection: car[0x1F4] = car[0x228]*(*0x0607EA9C) + car[0x1EC]
 *  13. FUN_0600C994
 *  14. If countdown<=0 and skip_flag==0: FUN_0600EA18(car)
 *  15. If skip_flag==0 and *0x06083255==0: tail-call FUN_0602D9F0
 *
 * Called from FUN_0600DE70.
 * ~276 instructions total. Uses 6 callee-saved slots (r14,r13,r12,r11,pr,macl).
 * ================================================================ */
void FUN_0600E4F2(void)
{
    int car;
    int is_non_player;

    /* Step 1: Copy display word */
    *(volatile short *)0x06063F44 = *(volatile short *)0x06063D9E;

    /* Steps 2-3: Setup car pointers */
    car = CAR_PTR_TARGET;
    CAR_PTR_CURRENT = car;
    *(volatile int *)0x0607E948 = CAR_ARRAY_BASE + CAR_STRUCT_SIZE;

    /* Step 4: Player check (car[0] = player → is_non_player = 0) */
    if (car == CAR_ARRAY_BASE)
        is_non_player = 0;
    else
        is_non_player = 1;

    /* Step 5: Subsystem updates */
    FUN_060081F4();
    FUN_060085B8();
    FUN_06030A06();
    FUN_06030EE0();

    /* Steps 6-7: Countdown vs normal path */
    if (*(volatile int *)0x060786BC > 0 &&
        *(volatile unsigned char *)0x06078635 == 0) {
        /* Step 6: Active countdown — decrement and apply deltas */
        int count = *(volatile int *)0x060786BC;
        int rot;

        count--;
        *(volatile int *)0x060786BC = count;

        /* Add position deltas */
        *(volatile int *)((char *)car + 0x10) += *(volatile int *)0x060786C0;
        *(volatile int *)((char *)car + 0x18) += *(volatile int *)0x060786C4;

        /* Add rotation delta (word-sized, sign-extended) */
        rot = *(volatile int *)((char *)car + 0x20);
        rot += (int)*(volatile short *)0x060786C8;
        *(volatile int *)((char *)car + 0x20) = rot;
        *(volatile int *)((char *)car + 0x30) = rot;
        *(volatile int *)((char *)car + 0x28) = rot;
        *(volatile int *)0x06063EF0 = rot;

        /* Grid pack + pre-render (skip 4x scene render) */
        *(volatile int *)0x060786B8 = FUN_06006838(
            *(volatile int *)((char *)car + 0x10),
            *(volatile int *)((char *)car + 0x18));
        FUN_06005ECC();
    } else {
        /* Step 7: Normal path — render pipeline + 4x scene render */
        FUN_0602ECF2();

        *(volatile int *)0x060786B8 = FUN_06006838(
            *(volatile int *)((char *)car + 0x10),
            *(volatile int *)((char *)car + 0x18));
        FUN_06005ECC();

        FUN_06027CA4(0x06063EB0, 0);
        FUN_06027CA4(0x06063E9C, 1);
        FUN_06027CA4(0x06063ED8, 2);
        FUN_06027CA4(0x06063EC4, 3);
    }

    /* Step 8: Copy rotation to car[0x1B0] */
    *(volatile int *)((char *)car + CAR_HEADING_BACKUP) =
        *(volatile int *)((char *)car + 0x20);

    /* Step 9: Player-only post-render */
    if (is_non_player == 0)
        FUN_0600DB64();

    /* Step 10: Collision, checkpoint, finalize */
    FUN_0600DA7C();
    FUN_0600CE66();
    FUN_0603053C(0);

    /* Step 11: Checkpoint change detection */
    FUN_0600D780(is_non_player);

    /* Step 12: Velocity projection */
    {
        int vel = *(volatile int *)((char *)car + CAR_RANKING);
        int factor = *(volatile int *)0x0607EA9C;
        int base_val = *(volatile int *)((char *)car + 0x1EC);
        *(volatile int *)((char *)car + CAR_VEL_PROJ) = vel * factor + base_val;
    }

    /* Step 13: Heading processing */
    FUN_0600C994();

    /* Step 14: Post-physics position update (countdown inactive + skip_flag clear) */
    if (*(volatile int *)0x060786BC <= 0 &&
        *(volatile unsigned char *)0x06078635 == 0) {
        FUN_0600EA18(car);
    }

    /* Step 15: VDP1 render tail-call (both flags must be zero) */
    if (*(volatile unsigned char *)0x06078635 == 0 &&
        *(volatile unsigned char *)0x06083255 == 0) {
        FUN_0602D9F0();
    }
}
