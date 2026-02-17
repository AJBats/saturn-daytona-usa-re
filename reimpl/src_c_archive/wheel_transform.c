#include "game.h"

/*
 * wheel_transform.c -- Wheel contact position transform and ground pitch/roll
 *
 * Hand-translated from binary at 0x06005ECC (302 instructions).
 *
 * Functions:
 *   FUN_06005ECC (0x06005ECC) -- Wheel position world transform and tilt computation
 *
 * This is the core ground-contact system for a car. It:
 *   1. Transforms 8 local-space position vectors into world space using
 *      the car's heading rotation matrix (via the transform stack).
 *   2. Adds the car's world position (X, Y, Z) to each transformed result.
 *   3. For each of 4 wheel contact positions, queries the terrain height
 *      via FUN_06006838(X, Z) and applies ground contact via FUN_06027EDE.
 *   4. Computes the car body's Y position as the average of 4 wheel heights.
 *   5. Transforms and processes a center reference point similarly.
 *   6. Computes pitch (car[0x1C]) and roll (car[0x24]) tilt angles from
 *      the differences in wheel Y positions using atan2.
 *
 * Wheel layout (inferred from pitch/roll computation):
 *   buf_B (0x06063E4C) = front-left   buf_D (0x06063E60) = front-right
 *   buf_C (0x06063E74) = rear-left    buf_A (0x06063E88) = rear-right
 *   (Extra buffers E-H at 0x06063E9C-0x06063ED8 are visual/shadow contact points.)
 *
 * Pitch = atan2((front_Y - rear_Y), pitch_scale)
 * Roll  = atan2((left_Y - right_Y), roll_scale)
 *
 * Called from physics_entry.c.
 *
 * Original address: 0x06005ECC
 */

/* External function declarations */
extern void FUN_06026DBC(void);                     /* transform stack push */
extern void FUN_06026E0C(void);                     /* transform stack operation */
extern void FUN_06026EDE(int heading);               /* heading rotation */
extern void FUN_06026FFC(int *input, int *output);   /* matrix transform */
extern int  FUN_06006838(int x, int z);              /* terrain height query */
extern void FUN_06027EDE(int height, int buf, int extra); /* ground contact apply */
extern unsigned int FUN_06027552(int a, int b);      /* fixed-point multiply */
extern int  FUN_0602744C(int delta, int scale);      /* atan2 angle */

/* Car pointer */
#define CAR_PTR               (*(volatile int *)0x0607E944)

/* 4 wheel contact position buffers (each 20 bytes: X, Y, Z, +2 extra ints) */
#define WHEEL_BUF_FL          ((volatile int *)0x06063E4C)  /* front-left (B) */
#define WHEEL_BUF_FR          ((volatile int *)0x06063E60)  /* front-right (D) */
#define WHEEL_BUF_RL          ((volatile int *)0x06063E74)  /* rear-left (C) */
#define WHEEL_BUF_RR          ((volatile int *)0x06063E88)  /* rear-right (A) */

/* 4 extra position buffers (shadow/visual contact points, 20 bytes each) */
#define EXTRA_BUF_E           ((volatile int *)0x06063E9C)
#define EXTRA_BUF_F           ((volatile int *)0x06063EB0)
#define EXTRA_BUF_H           ((volatile int *)0x06063EC4)
#define EXTRA_BUF_G           ((volatile int *)0x06063ED8)

/* Local-space transform input vectors (12 bytes each) */
#define LOCAL_FL              ((int *)0x0604464C)
#define LOCAL_FR              ((int *)0x06044640)
#define LOCAL_RL              ((int *)0x06044658)
#define LOCAL_RR              ((int *)0x06044664)
#define LOCAL_E               ((int *)0x06044688)
#define LOCAL_F               ((int *)0x0604467C)
#define LOCAL_G               ((int *)0x06044694)
#define LOCAL_H               ((int *)0x060446A0)
#define LOCAL_CENTER          ((int *)0x060446AC)

/* Heading rotation offset */
#define ROTATION_OFFSET       (*(volatile int *)0x06063F10)

/* Mode flag */
#define MODE_FLAG             (*(volatile int *)0x0607EAD8)

/* Pitch scale constants */
#define PITCH_SCALE_SHORT     0x0002CCCC   /* ~2.8 in 16.16 fixed-point */
#define PITCH_SCALE_LONG      0x000D6666   /* ~13.4 in 16.16 fixed-point */
/* Roll scale constant */
#define ROLL_SCALE            0x00011998   /* ~1.1 in 16.16 fixed-point */

/* Fixed-point half (0.5 in 16.16) */
#define FP_HALF               0x00008000

/* Car struct field offsets */
#define CAR_X_OFF        0x10
#define CAR_Y_OFF        0x14
#define CAR_Z_OFF        0x18
#define CAR_PITCH_OFF    0x1C
#define CAR_HEADING_OFF  0x20
#define CAR_ROLL_OFF     0x24
#define CAR_FIELD_1EC    0x1EC


/* ================================================================
 * FUN_06005ECC -- Wheel Position Transform & Ground Contact (0x06005ECC)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x06005ECC-0x060061AE)
 * Pool verified:
 *   0x06005FC0 = 0x06063E88 (wheel buf RR / A)
 *   0x06005FC4 = 0x06063E4C (wheel buf FL / B)
 *   0x06005FC8 = 0x06063E74 (wheel buf RL / C)
 *   0x06005FCC = 0x06063E60 (wheel buf FR / D)
 *   0x06005FD0 = 0x0607E944 (car pointer)
 *   0x06005FD4 = 0x06026DBC (transform stack push)
 *   0x06005FD8 = 0x06026E0C (transform stack operation)
 *   0x06005FDC = 0x06063F10 (rotation offset)
 *   0x06005FE0 = 0x06026EDE (heading rotation)
 *   0x06005FE4 = 0x0604464C (local FL)
 *   0x06005FE8 = 0x06026FFC (matrix transform)
 *   0x06005FEC = 0x06044640 (local FR)
 *   0x06005FF0 = 0x06044658 (local RL)
 *   0x06005FF4 = 0x06044664 (local RR)
 *   0x06005FF8 = 0x06063E9C (extra E)
 *   0x06005FFC = 0x06044688 (local E)
 *   0x06006000 = 0x06063EB0 (extra F)
 *   0x06006004 = 0x0604467C (local F)
 *   0x06006008 = 0x06063ED8 (extra G)
 *   0x0600600C = 0x06044694 (local G)
 *   0x06006010 = 0x06063EC4 (extra H)
 *   0x06006014 = 0x060446A0 (local H)
 *   0x0600611C = 0x06063ED8 (extra G — 2nd ref)
 *   0x06006120 = 0x06063EC4 (extra H — 2nd ref)
 *   0x06006124 = 0x06006838 (terrain height)
 *   0x06006128 = 0x06027EDE (ground contact apply)
 *   0x0600612C = 0x060446AC (local center)
 *   0x06006130 = 0x06026FFC (matrix transform — 2nd ref)
 *   0x06006134 = 0x0607EAD8 (mode flag)
 *   0x06006138 = 0x00008000 (FP_HALF)
 *   0x0600613C = 0x06027552 (fixed-point multiply)
 *   0x06006140 = 0x0002CCCC (pitch scale short)
 *   0x060061B0 = 0x000D6666 (pitch scale long)
 *   0x060061B4 = 0x00008000 (FP_HALF — 2nd ref)
 *   0x060061B8 = 0x06027552 (fixed-point multiply — 2nd ref)
 *   0x060061BC = 0x0602744C (atan2)
 *   0x060061C0 = 0x00011998 (roll scale)
 *   0x060061C4 = 0x06089EDC (matrix stack pointer)
 * Word pool:
 *   0x06006116 = 0x01EC (car field offset)
 *   0x06006118 = 0x00DC (threshold value 220)
 *
 * 302 instructions. Saves r8-r14, PR. 28-byte stack frame.
 * ================================================================ */
#if 0 /* FUN_06005ECC -- replaced by ASM import */
void FUN_06005ECC(void)
{
    volatile int *car = (volatile int *)(int)CAR_PTR;

    /* Extract car world position */
    int car_x = *(volatile int *)((char *)car + CAR_X_OFF);
    int car_y = *(volatile int *)((char *)car + CAR_Y_OFF);
    int car_z = *(volatile int *)((char *)car + CAR_Z_OFF);

    /* === Phase 1: Set up rotation matrix from car heading === */
    FUN_06026DBC();
    FUN_06026E0C();
    {
        int heading = *(volatile int *)((char *)car + CAR_HEADING_OFF);
        heading += ROTATION_OFFSET;
        FUN_06026EDE(heading);
    }

    /* === Phase 2: Transform 8 local-space positions into rotated space === */

    /* 4 wheel contact positions */
    FUN_06026FFC(LOCAL_FL, (int *)WHEEL_BUF_FL);
    FUN_06026FFC(LOCAL_FR, (int *)WHEEL_BUF_FR);
    FUN_06026FFC(LOCAL_RL, (int *)WHEEL_BUF_RL);
    FUN_06026FFC(LOCAL_RR, (int *)WHEEL_BUF_RR);

    /* 4 extra positions (shadow/visual contact) */
    FUN_06026FFC(LOCAL_E, (int *)EXTRA_BUF_E);
    FUN_06026FFC(LOCAL_F, (int *)EXTRA_BUF_F);
    FUN_06026FFC(LOCAL_G, (int *)EXTRA_BUF_G);
    FUN_06026FFC(LOCAL_H, (int *)EXTRA_BUF_H);

    /* === Phase 3: Add car world position to all transformed results === */

    /* Wheel positions: add full X, Y, Z */
    WHEEL_BUF_FL[0] += car_x;  WHEEL_BUF_FL[1] += car_y;  WHEEL_BUF_FL[2] += car_z;
    WHEEL_BUF_FR[0] += car_x;  WHEEL_BUF_FR[1] += car_y;  WHEEL_BUF_FR[2] += car_z;
    WHEEL_BUF_RR[0] += car_x;  WHEEL_BUF_RR[1] += car_y;  WHEEL_BUF_RR[2] += car_z;
    WHEEL_BUF_RL[0] += car_x;  WHEEL_BUF_RL[1] += car_y;  WHEEL_BUF_RL[2] += car_z;

    /* Extra positions: add X and Z only (Y stays as local offset) */
    EXTRA_BUF_E[0] += car_x;   EXTRA_BUF_E[2] += car_z;
    EXTRA_BUF_F[0] += car_x;   EXTRA_BUF_F[2] += car_z;
    EXTRA_BUF_G[0] += car_x;   EXTRA_BUF_G[2] += car_z;
    EXTRA_BUF_H[0] += car_x;   EXTRA_BUF_H[2] += car_z;

    /* === Phase 4: Query terrain height for each wheel position === */
    /* FUN_06006838(world_X, world_Z) returns terrain height at that XZ position.
     * FUN_06027EDE(height, buf_ptr, buf_ptr+14) applies ground contact result.
     * The +14 byte offset accesses a field at offset 0x0E in the 20-byte buffer. */
    {
        int h;

        h = FUN_06006838((int)WHEEL_BUF_FL[0], (int)WHEEL_BUF_FL[2]);
        FUN_06027EDE(h, (int)WHEEL_BUF_FL, (int)WHEEL_BUF_FL + 14);

        h = FUN_06006838((int)WHEEL_BUF_FR[0], (int)WHEEL_BUF_FR[2]);
        FUN_06027EDE(h, (int)WHEEL_BUF_FR, (int)WHEEL_BUF_FR + 14);

        h = FUN_06006838((int)WHEEL_BUF_RR[0], (int)WHEEL_BUF_RR[2]);
        FUN_06027EDE(h, (int)WHEEL_BUF_RR, (int)WHEEL_BUF_RR + 14);

        h = FUN_06006838((int)WHEEL_BUF_RL[0], (int)WHEEL_BUF_RL[2]);
        FUN_06027EDE(h, (int)WHEEL_BUF_RL, (int)WHEEL_BUF_RL + 14);
    }

    /* === Phase 5: Update car body Y = average of 4 wheel Y positions === */
    int avg_y;
    {
        int sum = (int)WHEEL_BUF_FR[1] + (int)WHEEL_BUF_FL[1]
                + (int)WHEEL_BUF_RR[1] + (int)WHEEL_BUF_RL[1];
        avg_y = sum >> 2;  /* arithmetic shift right by 2 = divide by 4 */
    }
    *(volatile int *)((char *)car + CAR_Y_OFF) = avg_y;

    /* === Phase 6: Transform and process center reference point === */
    int center[3];
    FUN_06026FFC(LOCAL_CENTER, center);

    /* Add car position (using avg_y for Y component) */
    center[0] += car_x;
    center[1] += avg_y;
    center[2] += car_z;

    /* Query terrain at center and apply ground contact */
    {
        int h = FUN_06006838(center[0], center[2]);
        FUN_06027EDE(h, (int)center, (int)center + 4);
    }

    /* === Phase 7: Compute pitch and roll tilt angles === */

    /* Determine pitch computation mode:
     *   Path A: center_Y matches avg_y (center offset = 0), OR (mode == 1 && car[0x1EC] >= 220)
     *     → Normalize front pair Y, use short pitch scale
     *   Path B: otherwise
     *     → Use center_Y directly, use long pitch scale */
    int front_y_ref;
    int pitch_scale;

    if (avg_y == center[1]
        || ((*(volatile int *)MODE_FLAG) == 1
            && *(volatile int *)((char *)car + CAR_FIELD_1EC) >= 220))
    {
        /* Path A: use normalized front wheel pair Y height */
        front_y_ref = (int)FUN_06027552(FP_HALF, (int)WHEEL_BUF_FL[1] + (int)WHEEL_BUF_FR[1]);
        pitch_scale = PITCH_SCALE_SHORT;
    } else {
        /* Path B: use center Y world position directly */
        front_y_ref = center[1];
        pitch_scale = PITCH_SCALE_LONG;
    }

    /* Compute normalized Y heights for rear pair, left pair, right pair */
    int rear_y_ref  = (int)FUN_06027552(FP_HALF, (int)WHEEL_BUF_RL[1] + (int)WHEEL_BUF_RR[1]);
    int left_y_ref  = (int)FUN_06027552(FP_HALF, (int)WHEEL_BUF_RL[1] + (int)WHEEL_BUF_FL[1]);
    int right_y_ref = (int)FUN_06027552(FP_HALF, (int)WHEEL_BUF_RR[1] + (int)WHEEL_BUF_FR[1]);

    /* Pitch angle = atan2(front - rear, pitch_scale) */
    *(volatile int *)((char *)car + CAR_PITCH_OFF) =
        FUN_0602744C(front_y_ref - rear_y_ref, pitch_scale);

    /* Roll angle = atan2(left - right, roll_scale) */
    *(volatile int *)((char *)car + CAR_ROLL_OFF) =
        FUN_0602744C(left_y_ref - right_y_ref, ROLL_SCALE);

    /* === Phase 8: Pop transform matrix stack === */
    {
        volatile int *stack_reg = (volatile int *)0x06089EDC;
        *stack_reg = *stack_reg - 48;
    }
}
#endif
