#include "game.h"

/*
 * visual_physics_update.c -- Pre-render physics pipeline for visual buffers
 *
 * Hand-translated from binary at 0x0600DFD0 (28 instructions).
 *
 * Functions:
 *   FUN_0600DFD0 (0x0600DFD0) -- Visual physics update pipeline
 *
 * Called from race_state_handlers.c during the race game state.
 * Prepares the car's visual representation by:
 *   1. Setting up car pointer and half-speed display value
 *   2. Calling FUN_0602DB00 (unknown — possibly shadow/visual prep)
 *   3. Querying terrain height at car's world XZ position
 *   4. Running wheel_transform (FUN_06005ECC) for ground contact
 *   5. Running 3D visibility test (FUN_06027CA4) for 4 extra visual buffers
 *   6. Tail-calling per_car_loop (FUN_0600E0C0) for per-car processing
 *
 * The extra buffers (F, E, G, H) are shadow/visual contact points used
 * by the rendering pipeline, distinct from the 4 primary wheel positions.
 *
 * Original address: 0x0600DFD0
 */

/* External dependencies */
extern void FUN_0602DB00(void);                    /* visual/shadow prep (variant A) */
extern void FUN_0602DC18(void);                    /* visual/shadow prep (variant B) */
extern int  FUN_06006838(int x, int z);            /* terrain height query */
extern void FUN_06005ECC(void);                    /* wheel transform */
extern void FUN_06027CA4(int buf, int index);      /* 3D visibility test */
extern char *FUN_06033020(int *pos);               /* Y-axis post-processing */
extern void FUN_0600E0C0(void);                    /* per_car_loop */

/* Car pointer source */
#define CAR_PTR_ADDR      (*(volatile int *)0x0607E944)

/* Game state value (halved for display) */
#define SPEED_STATE       (*(volatile int *)0x0607EA98)
#define DISPLAY_HALF_SPD  (*(volatile short *)0x060786CA)

/* Car slot pointer (used by wheel_transform and per_car_loop) */
#define CAR_SLOT_PTR      (*(volatile int *)0x0607E940)
#define CAR_SLOT_DATA     (*(volatile int *)0x0607E948)

/* Terrain height result */
#define TERRAIN_HEIGHT    (*(volatile int *)0x060786B8)

/* Extra visual buffers (shadow/visual contact points) */
#define EXTRA_BUF_F       0x06063EB0
#define EXTRA_BUF_E       0x06063E9C
#define EXTRA_BUF_G       0x06063ED8
#define EXTRA_BUF_H       0x06063EC4


/* ================================================================
 * FUN_0600DFD0 -- Visual Physics Update Pipeline (0x0600DFD0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600DFD0-0x0600E022)
 * Pool verified:
 *   0x0600E024 = 0x0607E944 (car pointer address)
 *   0x0600E028 = 0x0607EA98 (speed state)
 *   0x0600E02C = 0x060786CA (display half speed)
 *   0x0600E030 = 0x0607E940 (car slot pointer)
 *   0x0600E034 = 0x06078B68 (car slot data value)
 *   0x0600E038 = 0x0607E948 (car slot data ptr)
 *   0x0600E03C = 0x0602DB00 (visual/shadow prep)
 *   0x0600E040 = 0x06006838 (terrain height)
 *   0x0600E044 = 0x060786B8 (terrain height result)
 *   0x0600E048 = 0x06005ECC (wheel_transform)
 *   0x0600E04C = 0x06027CA4 (3D visibility test)
 *   0x0600E050 = 0x06063EB0 (extra buf F)
 *   0x0600E054 = 0x06063E9C (extra buf E)
 *   0x0600E058 = 0x06063ED8 (extra buf G)
 *   0x0600E05C = 0x06063EC4 (extra buf H)
 *
 * 28 instructions. Saves r14, PR. Tail-calls FUN_0600E0C0.
 * ================================================================ */
void FUN_0600DFD0(void)
{
    int car_ptr = CAR_PTR_ADDR;

    /* Store (speed_state >> 1) as display half-speed value */
    DISPLAY_HALF_SPD = (short)(SPEED_STATE >> 1);

    /* Set car slot pointer for downstream functions */
    CAR_SLOT_PTR = car_ptr;
    CAR_SLOT_DATA = (int)0x06078B68;

    /* Visual/shadow preparation */
    FUN_0602DB00();

    /* Query terrain height at car's world XZ position */
    {
        int car_x = *(volatile int *)(car_ptr + 0x10);
        int car_z = *(volatile int *)(car_ptr + 0x18);
        TERRAIN_HEIGHT = FUN_06006838(car_x, car_z);
    }

    /* Run wheel position transform and ground contact */
    FUN_06005ECC();

    /* Run 3D visibility test for 4 extra visual buffers */
    FUN_06027CA4(EXTRA_BUF_F, 0);
    FUN_06027CA4(EXTRA_BUF_E, 1);
    FUN_06027CA4(EXTRA_BUF_G, 2);
    FUN_06027CA4(EXTRA_BUF_H, 3);

    /* Continue with per-car loop processing (tail call) */
    FUN_0600E0C0();
}


/* ================================================================
 * FUN_0600E060 -- Extended Visual Physics Update (0x0600E060)
 *
 * Near-duplicate of FUN_0600DFD0 with two differences:
 *   - Calls FUN_0602DC18 instead of FUN_0602DB00 (variant B prep)
 *   - Extra call to FUN_06033020(car_ptr + 0x14) for Y-axis processing
 *
 * Called from race_state_handlers.c during a different game mode or
 * car type that requires additional Y-position post-processing.
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600E060-0x0600E0BE)
 * Pool verified:
 *   0x0600E0EC = 0x0607E944 (car pointer address)
 *   0x0600E0F0 = 0x0607EA98 (speed state)
 *   0x0600E0F4 = 0x060786CA (display half speed)
 *   0x0600E0F8 = 0x0607E940 (car slot pointer)
 *   0x0600E0FC = 0x06078B68 (car slot data value)
 *   0x0600E100 = 0x0607E948 (car slot data ptr)
 *   0x0600E104 = 0x0602DC18 (visual/shadow prep variant B)
 *   0x0600E108 = 0x06006838 (terrain height)
 *   0x0600E10C = 0x060786B8 (terrain height result)
 *   0x0600E110 = 0x06005ECC (wheel_transform)
 *   0x0600E114 = 0x06027CA4 (3D visibility test)
 *   0x0600E118 = 0x06063EB0 (extra buf F)
 *   0x0600E11C = 0x06063E9C (extra buf E)
 *   0x0600E120 = 0x06063ED8 (extra buf G)
 *   0x0600E124 = 0x06063EC4 (extra buf H)
 *   0x0600E128 = 0x06033020 (Y-axis post-processing)
 *
 * 46 instructions. Saves r13, r14, PR. Tail-calls FUN_0600E0C0.
 * ================================================================ */
void FUN_0600E060(void)
{
    int car_ptr = CAR_PTR_ADDR;

    /* Store (speed_state >> 1) as display half-speed value */
    DISPLAY_HALF_SPD = (short)(SPEED_STATE >> 1);

    /* Set car slot pointer for downstream functions */
    CAR_SLOT_PTR = car_ptr;
    CAR_SLOT_DATA = (int)0x06078B68;

    /* Visual/shadow preparation (variant B) */
    FUN_0602DC18();

    /* Query terrain height at car's world XZ position */
    {
        int car_x = *(volatile int *)(car_ptr + 0x10);
        int car_z = *(volatile int *)(car_ptr + 0x18);
        TERRAIN_HEIGHT = FUN_06006838(car_x, car_z);
    }

    /* Run wheel position transform and ground contact */
    FUN_06005ECC();

    /* Run 3D visibility test for 4 extra visual buffers */
    FUN_06027CA4(EXTRA_BUF_F, 0);
    FUN_06027CA4(EXTRA_BUF_E, 1);
    FUN_06027CA4(EXTRA_BUF_G, 2);
    FUN_06027CA4(EXTRA_BUF_H, 3);

    /* Y-axis post-processing on car position (car_ptr + 0x14 = Y offset) */
    FUN_06033020((int *)(car_ptr + 0x14));

    /* Continue with per-car loop processing (tail call) */
    FUN_0600E0C0();
}
