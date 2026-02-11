#include "game.h"

/*
 * car_iteration.c -- Per-frame car iteration and state management
 *
 * Hand-translated from annotated ASM (asm/per_car_loop.s, asm/object_management.s)
 * and verified instruction-by-instruction against build/aprog.s binary.
 *
 * Functions:
 *   FUN_0600C302 (0x0600C302) -- Car state finalize (heading + timers)
 *   FUN_0600DE40 (0x0600DE40) -- Simple car update wrapper
 *   FUN_0600DE54 (0x0600DE54) -- VS mode car update wrapper
 *   FUN_0600DF66 (0x0600DF66) -- Mode-dispatched car update
 *   FUN_0600DE70 (0x0600DE70) -- Per-frame car iteration loop
 *
 * All wrapper functions (DE40, DE54, DF66, DE70) perform setup then
 * tail-call FUN_0600E0C0, which is the common per-car physics pipeline.
 *
 * Call hierarchy (state 15 = main race):
 *   state_15 → FUN_0600DE70 → FUN_0600E4F2 (per car) → E0C0
 *   state_15 → FUN_0600DE40 → FUN_0600E410 → E0C0
 *   state_15 → FUN_0600DE54 → FUN_0600E99C → E0C0
 *   state_15 → FUN_0600DF66 → E410/E47C (by mode) → E0C0
 */

/* Forward declarations for external dependencies */
extern void FUN_0600E0C0(void);
extern void FUN_0600E410(void);
extern void FUN_0600E47C(void);
extern void FUN_0600E99C(void);
extern void FUN_0600E4F2(void);
extern void FUN_0600A8BC(void);
extern void FUN_0602F99C(void);
extern void FUN_06034900(void);
extern void FUN_0602F7EA(void);
extern unsigned int FUN_06035340(void);

/* Game state addresses used by these functions */
#define RACE_PARAM_A        (*(volatile int *)0x0607EA98)
#define RACE_HALF_STORE     (*(volatile short *)0x060786CA)
#define RENDER_FLAG_BYTE    (*(volatile unsigned char *)0x06083255)
#define MODE_FLAG_BYTE      (*(volatile unsigned char *)0x06083261)
#define CAR_COUNT_BYTE      (*(volatile unsigned char *)0x06078634)
#define CAR_SPECIAL_FLAG    (*(volatile unsigned char *)0x06078635)
#define RACE_FLAG_WORD      (*(volatile short *)0x0607ED8C)
#define CAR_MODE_STATE      (*(volatile int *)0x0607EAE4)
#define LOOP_STATE          (*(volatile int *)0x0607ED88)
#define RENDER_VAR          (*(volatile int *)0x06063EF0)


/* ================================================================
 * FUN_0600C302 -- Car State Finalize (0x0600C302)
 *
 * CONFIDENCE: DEFINITE (per_car_loop.s lines 305-410, binary verified)
 * Pool verified:
 *   0x0600C384 = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600C36A = 0x0172 (timer 1 offset)
 *   0x0600C36C = 0x0174 (timer 2 offset)
 *   0x0600C36E = 0x00DC (zone timer offset)
 *   0x0600C370 = 0x00E6 (primary zone threshold)
 *   0x0600C372 = 0x0084 (extended check offset)
 *   0x0600C374 = 0x008C (extended check threshold)
 *   0x0600C416 = 0x009B (secondary zone lower bound)
 *   0x0600C418 = 0x00E6 (secondary zone upper bound)
 *   0x0600C41A = 0x0172 (timer write offset)
 *
 * Called per-car from physics pipeline.
 * Expands heading value, decrements timers, sets zone state.
 *
 * NOTE: Annotation in per_car_loop.s incorrectly stated offsets as
 * 0x17C/0x178 -- binary shows 0xE4/0xE0. Zone timer offset stated
 * as 0x9B -- binary shows 0xDC.
 * ================================================================ */
void FUN_0600C302(void)
{
    int car = CAR_PTR_TARGET;
    int heading, val84;

    /* Expand heading: car[0x68] << 5 -> car[0xE4] and car[0xE0] */
    heading = *(volatile int *)((char *)car + 0x68);
    heading <<= 5;
    *(volatile int *)((char *)car + 0xE4) = heading;
    *(volatile int *)((char *)car + 0xE0) = heading;

    /* Timer 1 at car[0x172]: decrement if positive */
    {
        short t = *(volatile short *)((char *)car + 0x172);
        if (t > 0)
            *(volatile short *)((char *)car + 0x172) = t - 1;
    }

    /* Timer 2 at car[0x174]: decrement if positive */
    {
        short t = *(volatile short *)((char *)car + 0x174);
        if (t > 0)
            *(volatile short *)((char *)car + 0x174) = t - 1;
    }

    /* Zone timer at car[0xDC]: if active, return early */
    if (*(volatile short *)((char *)car + 0xDC) != 0)
        return;

    /* Primary zone: heading >= 0xE6 -> set timer1=18, timer2=0 */
    heading = *(volatile int *)((char *)car + 0x68);
    if (heading >= 0xE6) {
        *(volatile short *)((char *)car + 0x172) = 18;
        *(volatile short *)((char *)car + 0x174) = 0;
        return;
    }

    /* Extended check: car[0x84] must be >= 0x8C to continue */
    val84 = *(volatile int *)((char *)car + 0x84);
    if (val84 < 0x8C)
        return;

    /* Secondary zone: 0x9B < car[0x68] < 0xE6 -> timer1=0, timer2=18 */
    heading = *(volatile int *)((char *)car + 0x68);
    if (heading <= 0x9B || heading >= 0xE6)
        return;

    *(volatile short *)((char *)car + 0x172) = 0;
    *(volatile short *)((char *)car + 0x174) = 18;
}


/* ================================================================
 * FUN_0600DE40 -- Simple Car Update Wrapper (0x0600DE40)
 *
 * CONFIDENCE: DEFINITE (object_management.s, binary verified)
 * Pool verified:
 *   0x0600DEB4 = 0x0607EA98 (race param A)
 *   0x0600DEB8 = 0x060786CA (half-speed store)
 *
 * Halves race param, stores it, calls E410 (physics), tail-calls E0C0.
 * Used in pre-race and race states for single-player car updates.
 * ================================================================ */
void FUN_0600DE40(void)
{
    int val = RACE_PARAM_A;
    val >>= 1;
    RACE_HALF_STORE = (short)val;

    FUN_0600E410();
    FUN_0600E0C0();
}


/* ================================================================
 * FUN_0600DE54 -- VS Mode Car Update Wrapper (0x0600DE54)
 *
 * CONFIDENCE: DEFINITE (object_management.s, binary verified)
 * Pool verified:
 *   0x0600DEB4 = 0x0607EA98 (race param A)
 *   0x0600DEB8 = 0x060786CA (half-speed store)
 *   0x0600DEBC = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600DEC0 = 0x0607E940 (CAR_PTR_CURRENT)
 *
 * Like DE40 but also copies CAR_PTR_TARGET to CAR_PTR_CURRENT,
 * then calls E99C instead of E410. Used for VS mode.
 * ================================================================ */
void FUN_0600DE54(void)
{
    int val = RACE_PARAM_A;
    val >>= 1;
    RACE_HALF_STORE = (short)val;

    CAR_PTR_CURRENT = CAR_PTR_TARGET;

    FUN_0600E99C();
    FUN_0600E0C0();
}


/* ================================================================
 * FUN_0600DF66 -- Mode-Dispatched Car Update (0x0600DF66)
 *
 * CONFIDENCE: DEFINITE (object_management.s, binary verified)
 * Pool verified:
 *   0x0600DFB4 = 0x0607EA98 (race param A)
 *   0x0600DFB8 = 0x060786CA (half-speed store)
 *   0x0600DFBC = 0x06083261 (mode flag byte)
 *
 * Reads a mode byte from 0x06083261, dispatches:
 *   mode 0: E410 (standard physics update)
 *   mode 1: E47C (alternate physics)
 *   mode 2: E47C (alternate physics)
 *   default: skip to E0C0
 * All paths tail-call E0C0.
 * ================================================================ */
void FUN_0600DF66(void)
{
    int val = RACE_PARAM_A;
    val >>= 1;
    RACE_HALF_STORE = (short)val;

    {
        unsigned char mode = MODE_FLAG_BYTE;

        if (mode == 0)
            FUN_0600E410();
        else if (mode == 1 || mode == 2)
            FUN_0600E47C();
    }

    FUN_0600E0C0();
}


/* ================================================================
 * FUN_0600DE70 -- Per-Frame Car Iteration Loop (0x0600DE70)
 *
 * CONFIDENCE: DEFINITE (object_management.s lines 376-490, binary verified)
 * Pool verified:
 *   0x0600DEB4 = 0x0607EA98 (race param)
 *   0x0600DEB8 = 0x060786CA (half store)
 *   0x0600DEBC = 0x0607E944 (CAR_PTR_TARGET)
 *   0x0600DEC0 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600DEC4 = 0x0607ED8C (race flag word)
 *   0x0600DEC8 = 0x0607EAE4 (car mode state)
 *   0x0600DECC = 0x0607ED88 (loop state)
 *   0x0600DED0 = 0x06035340 (param calculation function)
 *   0x0600DED4 = 0x06063EF0 (render variable)
 *   0x0600DED8 = 0x06078900 (CAR_ARRAY_BASE)
 *   0x0600DEB2 = 0x0268 (CAR_STRUCT_SIZE)
 *   0x0600DF94 = 0x06078635 (car special flag byte)
 *   0x0600DF9C = 0x06078634 (car count byte)
 *   0x0600DFA0 = 0x0600A8BC (audio update)
 *   0x0600DFA4 = 0x06083255 (render flag byte)
 *   0x0600DFA8 = 0x06034900 (render path A)
 *   0x0600DFAC = 0x0602F7EA (render path B / sprite_transform)
 *   0x0600DFB0 = 0x0602F99C (finalize)
 *
 * Main per-frame car iteration loop. Iterates over all active cars,
 * managing car pointers and race state flags. After the loop,
 * runs audio update, rendering, and finalize, then tail-calls E0C0.
 *
 * Called from state 15 (main race state) handler.
 *
 * NOTE: FUN_06035340 is called with implicit r0/r1 parameters
 * (non-standard calling convention). The L1 stub won't process
 * these correctly. Original sets r0=*(0x0607EA98), r1=-4.
 * ================================================================ */
void FUN_0600DE70(void)
{
    int car_base = CAR_ARRAY_BASE;
    int car_second = CAR_ARRAY_BASE + CAR_STRUCT_SIZE;
    int saved_render_var = RENDER_VAR;
    unsigned int i;
    int result;

    /* Calculate and store race half-param via FUN_06035340 */
    result = (int)FUN_06035340();
    RACE_HALF_STORE = (short)result;

    /* Iterate over all active cars */
    for (i = 0; i < (unsigned int)CAR_COUNT_BYTE; i++) {
        unsigned char flag = CAR_SPECIAL_FLAG;

        if (flag != 0) {
            if (i == 0) {
                /* First car with special flag: use second car slot */
                RACE_FLAG_WORD = 1;
                CAR_PTR_TARGET = car_second;
                CAR_PTR_CURRENT = car_second;
            } else {
                /* Non-first car with special flag: reset to first car */
                RACE_FLAG_WORD = 0;
                LOOP_STATE -= 2;
                CAR_PTR_TARGET = car_base;
                RENDER_VAR = saved_render_var;
                CAR_PTR_CURRENT = CAR_PTR_TARGET;
            }
        } else {
            /* No special flag: initialize car mode state if zero */
            if (CAR_MODE_STATE == 0)
                CAR_MODE_STATE = 1;
        }

        FUN_0600E4F2();
    }

    /* Post-loop: audio update */
    FUN_0600A8BC();

    /* Rendering: choose path based on render flag */
    if (RENDER_FLAG_BYTE != 0)
        FUN_06034900();
    else
        FUN_0602F7EA();

    /* Finalize */
    FUN_0602F99C();

    /* Common per-car physics pipeline */
    FUN_0600E0C0();
}
