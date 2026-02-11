#include "game.h"

/*
 * car_table_init.c -- Car table initialization for race start
 *
 * Hand-translated from binary at 0x0600629C (238 instructions).
 *
 * Functions:
 *   FUN_0600629C (0x0600629C) -- Initialize car slots for race
 *
 * Sets up the car table (40 slots at 0x06078900, 0x268 bytes each):
 * - In normal mode (byte@0x06078635 == 0): init all cars via loop
 * - In VS mode (byte@0x06078635 != 0): init player + opponent only
 * - Configures physics defaults, timer counters, camera globals
 * - Tail-calls FUN_060067c8 for additional setup
 *
 * Called from race_init.c.
 */

#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))

/* Car table layout (CAR_STRUCT_SIZE already in game.h as 0x268) */
#define CAR_TABLE_BASE       0x06078900

/* Car pointer globals */
#define CAR_PTR_PRIMARY      (*(volatile int *)0x0607E940)
#define CAR_PTR_SECONDARY    (*(volatile int *)0x0607E944)

/* Timer/counter shorts (zeroed at init) */
#define TIMER_SHORT_0        (*(volatile short *)0x0605DF4E)
#define TIMER_SHORT_1        (*(volatile short *)0x0605DF50)
#define TIMER_SHORT_2        (*(volatile short *)0x0605DF52)
#define TIMER_SHORT_3        (*(volatile short *)0x0605DF54)

/* Mode flag: 0=normal, nonzero=VS */
#define MODE_BYTE            (*(volatile unsigned char *)0x06078635)

/* Configuration bytes (3 bytes: used for car[0x9E], car[0x7C], car[0x9C]) */
#define CONFIG_BYTES         ((volatile unsigned char *)0x0607ED90)

/* Course/mode flag (0=normal, nonzero=VS/special) */
#define COURSE_FLAG          (*(volatile int *)0x0607EAD8)

/* Number of active cars (NB: game.h NUM_CARS_ACTIVE=0x0607EAD8 is different;
   this function uses 0x0607EA98 per pool at 0x06006450) */
#define NUM_CARS_ACTIVE      (*(volatile int *)0x0607EA98)

/* Player car config values */
#define CONFIG_VAL_9C        (*(volatile int *)0x0607EAB8)
#define CONFIG_VAL_9E        (*(volatile short *)0x06063F42)
#define CONFIG_VAL_7C        (*(volatile int *)0x06078868)

/* Game state (NB: game.h GAME_STATE_629C=0x0607EBD0 is different;
   this function uses 0x0607EBC0 per pool at 0x06006468) */
#define GAME_STATE_629C      (*(volatile int *)0x0607EBC0)

/* Output flag */
#define RACE_FLAG_OUTPUT     (*(volatile int *)0x0607EAD0)

/* Camera/rotation chain globals */
#define G_ROTATION_A         (*(volatile int *)0x06063EF0)
#define G_ROTATION_B         (*(volatile int *)0x06063EF4)
#define G_CAMERA_F10         (*(volatile int *)0x06063F10)
#define G_CAMERA_E78         (*(volatile int *)0x06063E78)
#define G_CAMERA_E8C         (*(volatile int *)0x06063E8C)
#define G_CAMERA_E64         (*(volatile int *)0x06063E64)
#define G_CAMERA_E50         (*(volatile int *)0x06063E50)
#define G_CAMERA_F14         (*(volatile int *)0x06063F14)

/* Misc init globals */
#define G_COUNTER_20D0       (*(volatile int *)0x060620D0)
#define G_MODE_E1C           (*(volatile int *)0x06063E1C)
#define G_FLAG_9F30          (*(volatile int *)0x06059F30)
#define G_POS_E24            (*(volatile int *)0x06063E24)
#define G_POS_E34            (*(volatile int *)0x06063E34)
#define G_POS_E28            (*(volatile int *)0x06063E28)
#define G_POS_E2C            (*(volatile int *)0x06063E2C)
#define G_POS_E30            (*(volatile int *)0x06063E30)
#define G_POS_EEC            (*(volatile int *)0x06063EEC)
#define G_STATE_E20          (*(volatile int *)0x06063E20)

/* Fixed-point constant: camera Z offset (0xFEA00000 = -0x1600000) */
#define CAMERA_Z_OFFSET      0xFEA00000

/* Camera position constants */
#define CAM_POS_X_DEFAULT    0x00058000
#define CAM_POS_Y_DEFAULT    0x0000F300
#define CAM_POS_Z_DEFAULT    0x006E0000
#define CAM_POS_W_DEFAULT    0x00100000

/* External functions */
extern void FUN_0600e1d4(void);        /* per-car initialization */
extern void FUN_0600d280(void);        /* player car config */
extern void FUN_0602e5e4(void);        /* physics table setup */
extern void FUN_06038bd4(int, int);    /* mode configuration */
extern int  FUN_060067c8(void);        /* additional race setup (tail call) */


/* ================================================================
 * FUN_0600629C -- Car Table Init for Race Start (0x0600629C)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600629C-0x060064F0)
 * Pool verified (35+ constants):
 *   0x06006364 = 0x06078900 (car table base)
 *   0x0600635E = 0x0268 (car struct size)
 *   0x06006368 = 0x0600E1D4 (per-car init function)
 *   0x0600636C = 0x0607E944 (car ptr secondary)
 *   0x06006370 = 0x0607E940 (car ptr primary)
 *   0x06006384 = 0x06078635 (mode byte)
 *   0x06006388 = 0x0607ED90 (config bytes)
 *   0x0600638C = 0x0607EAD8 (course flag)
 *   0x06006450 = 0x0607EA98 (car count)
 *   0x06006460 = 0x0600D280 (player config function)
 *   0x06006464 = 0x0602E5E4 (physics setup function)
 *   0x06006468 = 0x0607EBC0 (game state)
 *   0x06006470 = 0x0607EAD0 (race flag)
 *   0x0600648C = 0xFEA00000 (camera Z constant)
 *   0x0600655C = 0x06038BD4 (mode config function)
 *   ... (see full list in binary)
 *
 * Algorithm:
 *   1. Zero 4 timer shorts
 *   2. Branch on mode byte:
 *      - VS mode: init car slot 1 (opponent) then slot 0 (player)
 *      - Normal: loop through all cars
 *   3. Configure player car physics defaults (0x74, 0x90, 0x9C, 0x9E, 0x7C)
 *   4. Call FUN_0600D280, FUN_0602E5E4
 *   5. Set race flag based on game state
 *   6. Initialize camera/rotation chain globals
 *   7. Set car[0xDC]/[0xDE] based on course mode
 *   8. Initialize misc globals and camera position constants
 *   9. Tail-call FUN_060067c8
 *
 * 238 instructions. Saves r8-r14, PR, MACL.
 * ================================================================ */
void FUN_0600629C(void)
{
    /* Phase 1: Zero timer/counter shorts */
    TIMER_SHORT_0 = 0;
    TIMER_SHORT_1 = 0;
    TIMER_SHORT_2 = 0;
    TIMER_SHORT_3 = 0;

    /* Phase 2: Initialize car slots based on mode */
    if (MODE_BYTE != 0) {
        /* VS mode: set up opponent car (slot 1) first */
        int car1_addr = CAR_TABLE_BASE + CAR_STRUCT_SIZE;
        CAR_PTR_PRIMARY = car1_addr;
        CAR_PTR_SECONDARY = car1_addr;

        /* Init opponent car */
        CAR_INT(CAR_PTR_PRIMARY, 4) = 0;
        FUN_0600e1d4();

        /* Configure opponent car fields */
        {
            int car = CAR_PTR_SECONDARY;
            CAR_INT(car, 0x74) = 0x38;
            CAR_INT(car, 0x90) = 0x38;
            CAR_SHORT(car, 0x9E) = (unsigned char)CONFIG_BYTES[0];
            CAR_SHORT(car, 0x7C) = (unsigned char)CONFIG_BYTES[1];
            CAR_SHORT(car, 0x9C) = (unsigned char)CONFIG_BYTES[2];
        }

        /* Set opponent car[0xDC]/[0xDE] based on course flag */
        if (COURSE_FLAG == 0) {
            CAR_SHORT(CAR_PTR_PRIMARY, 0xDC) = 3;
            CAR_SHORT(CAR_PTR_PRIMARY, 0xDE) = 3;
        } else {
            CAR_SHORT(CAR_PTR_PRIMARY, 0xDC) = 0;
            CAR_SHORT(CAR_PTR_PRIMARY, 0xDE) = 0;
        }

        /* Set up player car (slot 0) */
        CAR_PTR_PRIMARY = CAR_TABLE_BASE;
        CAR_PTR_SECONDARY = CAR_TABLE_BASE;
        CAR_INT(CAR_PTR_PRIMARY, 4) = 0;
        FUN_0600e1d4();
    } else {
        /* Normal mode: initialize all cars in a loop */
        int i;
        for (i = 0; i < NUM_CARS_ACTIVE; i++) {
            int car_addr = CAR_TABLE_BASE + i * CAR_STRUCT_SIZE;
            CAR_PTR_PRIMARY = car_addr;
            CAR_INT(car_addr, 4) = i;
            FUN_0600e1d4();
        }
    }

    /* Phase 3: Configure player car physics defaults */
    {
        int car = CAR_PTR_SECONDARY;
        CAR_INT(car, 0x74) = 0x38;      /* physics param A */
        CAR_INT(car, 0x90) = 0x38;      /* physics param B */
        CAR_SHORT(car, 0x9C) = (short)CONFIG_VAL_9C;
        CAR_SHORT(car, 0x9E) = CONFIG_VAL_9E;
        CAR_SHORT(car, 0x7C) = (short)CONFIG_VAL_7C;
    }

    /* Phase 4: Additional configuration */
    FUN_0600d280();
    FUN_0602e5e4();

    /* Phase 5: Set race flag based on game state */
    if (GAME_STATE_629C == 0x0E && COURSE_FLAG == 0) {
        RACE_FLAG_OUTPUT = 1;
    } else {
        RACE_FLAG_OUTPUT = 0;
    }

    /* Phase 6: Initialize camera/rotation globals */
    {
        int car = CAR_PTR_SECONDARY;
        G_ROTATION_A = CAR_INT(car, 0x20);
        G_ROTATION_B = 0;
        G_CAMERA_F10 = 0;
        G_CAMERA_E78 = 0;
        G_CAMERA_E8C = G_CAMERA_E78;
        G_CAMERA_E64 = G_CAMERA_E8C;
        G_CAMERA_E50 = G_CAMERA_E64;
        G_CAMERA_F14 = (int)CAMERA_Z_OFFSET;

        /* Phase 7: Set car[0xDC]/[0xDE] based on course mode */
        if (COURSE_FLAG != 0) {
            CAR_SHORT(car, 0xDC) = 0;
            CAR_SHORT(car, 0xDE) = 0;
        } else {
            CAR_SHORT(car, 0xDC) = 3;
            CAR_SHORT(car, 0xDE) = 3;
        }
    }

    /* Phase 8: Initialize misc globals */
    G_COUNTER_20D0 = 0;
    G_MODE_E1C = 2;
    G_FLAG_9F30 = 1;
    FUN_06038bd4(8, 0);

    /* Camera position defaults */
    G_POS_E24 = CAM_POS_X_DEFAULT;
    G_POS_E34 = CAM_POS_Y_DEFAULT;
    G_POS_E28 = CAM_POS_Z_DEFAULT;
    G_POS_E2C = CAM_POS_W_DEFAULT;
    G_POS_E30 = 0;
    G_POS_EEC = CAM_POS_Y_DEFAULT;
    G_STATE_E20 = 2;

    /* Phase 9: Tail call to additional race setup */
    FUN_060067c8();
}
