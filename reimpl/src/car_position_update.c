#include "game.h"

/* Per-file car struct access macros */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))

/*
 * car_position_update.c -- Car-to-object position transfer
 *
 * Hand-translated from binary at 0x060061C8 (53 instructions).
 *
 * Functions:
 *   FUN_060061C8 (0x060061C8) -- Apply car position to display objects
 *
 * Takes the current car's X/Y/Z world position and applies it to 4
 * display object structs. Each struct is a 12-byte position record
 * (X at +0, Y at +4, Z at +8). X and Z are accumulated (+=), Y is
 * replaced directly.
 *
 * Also calls rendering setup functions (position projection, heading
 * rotation) and decrements OBJ_STATE_PRIMARY by 48 (one render slot).
 *
 * Called from per_car_loop.c.
 */

/* External dependencies */
extern void FUN_06026DBC(void);             /* position projection setup */
extern void FUN_06026E0C(void);             /* render state processing */
extern void FUN_06026EDE(int heading);      /* heading rotation setup */
extern void FUN_06026FFC(int table, int output);  /* position table lookup */

/* 4 display object position structs (12 bytes each: X, Y, Z) */
#define OBJ_POS_A  ((volatile int *)0x06063E9C)
#define OBJ_POS_B  ((volatile int *)0x06063EB0)
#define OBJ_POS_C  ((volatile int *)0x06063ED8)
#define OBJ_POS_D  ((volatile int *)0x06063EC4)

/* 4 position lookup tables */
#define TABLE_A    0x0604464C
#define TABLE_B    0x06044640
#define TABLE_C    0x06044658
#define TABLE_D    0x06044664


/* ================================================================
 * FUN_060061C8 -- Car-to-Object Position Transfer (0x060061C8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x060061C8-0x06006260)
 * Pool verified:
 *   0x06006264 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x06006268 = 0x06026DBC (position projection setup)
 *   0x0600626C = 0x06026E0C (render state processing)
 *   0x06006270 = 0x06026EDE (heading rotation)
 *   0x06006274 = 0x06026FFC (position table lookup)
 *   0x06006278 = 0x06063E9C (output A)
 *   0x0600627C = 0x0604464C (table A)
 *   0x06006280 = 0x06063EB0 (output B)
 *   0x06006284 = 0x06044640 (table B)
 *   0x06006288 = 0x06063ED8 (output C)
 *   0x0600628C = 0x06044658 (table C)
 *   0x06006290 = 0x06063EC4 (output D)
 *   0x06006294 = 0x06044664 (table D)
 *   0x06006298 = 0x06089EDC (OBJ_STATE_PRIMARY)
 *
 * Algorithm:
 *   1. Load car X/Y/Z position from current car struct
 *   2. Call position/heading setup functions
 *   3. 4x: call FUN_06026FFC(table, output) for each object
 *   4. 4x: accumulate X/Z, set Y in each output struct
 *   5. Decrement OBJ_STATE_PRIMARY by 48 (release render slot)
 *
 * 53 instructions. Saves r14, r13, r12, r11, PR.
 * ================================================================ */
void FUN_060061C8(void)
{
    int car = CAR_PTR_CURRENT;
    int car_x = CAR_INT(car, CAR_X);
    int car_y = CAR_INT(car, CAR_Y);
    int car_z = CAR_INT(car, CAR_Z);

    /* Phase 1: Setup rendering state */
    FUN_06026DBC();
    FUN_06026E0C();
    FUN_06026EDE(CAR_INT(car, CAR_HEADING3));

    /* Phase 2: Position table lookups for 4 display objects */
    FUN_06026FFC(TABLE_A, (int)OBJ_POS_A);
    FUN_06026FFC(TABLE_B, (int)OBJ_POS_B);
    FUN_06026FFC(TABLE_C, (int)OBJ_POS_C);
    FUN_06026FFC(TABLE_D, (int)OBJ_POS_D);

    /* Phase 3: Apply car world position to each display object */
    /* Object A */
    OBJ_POS_A[0] += car_x;
    OBJ_POS_A[1]  = car_y;
    OBJ_POS_A[2] += car_z;

    /* Object B */
    OBJ_POS_B[0] += car_x;
    OBJ_POS_B[1]  = car_y;
    OBJ_POS_B[2] += car_z;

    /* Object C */
    OBJ_POS_C[0] += car_x;
    OBJ_POS_C[1]  = car_y;
    OBJ_POS_C[2] += car_z;

    /* Object D */
    OBJ_POS_D[0] += car_x;
    OBJ_POS_D[1]  = car_y;
    OBJ_POS_D[2] += car_z;

    /* Phase 4: Release one render slot */
    OBJ_STATE_PRIMARY -= 48;
}
