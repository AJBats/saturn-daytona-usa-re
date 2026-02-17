#include "game.h"

/*
 * player_physics.c -- Core player physics pipeline
 *
 * Hand-translated from DEFINITE/HIGH-confidence annotated ASM
 * (asm/speed_position.s, asm/player_physics.s) and verified
 * instruction-by-instruction against build/aprog.s raw binary.
 *
 * Functions:
 *   FUN_0600D266  -- Friction stub (no-op in original binary)
 *   FUN_0600C4F8  -- Speed curve calculation
 *   FUN_0600C5D6  -- Position integration
 *   FUN_0600E71A  -- Player physics orchestrator
 *   FUN_06008318  -- Controller input (gear shifting)
 *   FUN_0600CEBA  -- Track segment advancement
 *
 * Note: The original binary uses non-standard register passing for
 * some helper calls (e.g., FUN_06034F78 uses r0/r1/r2). In this
 * reimpl, all functions use standard GCC SH-2 calling convention
 * (r4/r5/r6/r7), which is consistent since both caller and callee
 * are recompiled C.
 */


/* ================================================================
 * Car struct access macros
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))
#define CAR_BYTE(car, off)   (*(volatile signed char *)((char *)(car) + (off)))
#define CAR_UBYTE(car, off)  (*(volatile unsigned char *)((char *)(car) + (off)))


/* ================================================================
 * Speed system constants (from pool constants in speed_position.s)
 * ================================================================ */
#define SPEED_TABLE_A_BASE    0x060477EC
#define SPEED_TABLE_B_BASE    0x060454CC
#define SPEED_BASE_OFFSET     ((int)0xFEC00000)   /* -20,971,520 */
#define SPEED_DECEL_LIMIT     (-4014)              /* 0xF052 sign-extended */
#define SPEED_CONV_FACTOR     0x00480000           /* 72 << 16 */
#define SPEED_FLAG_SKIP       0x8000               /* bit 15 of state flags */

/* Steering/input constants */
#define GEAR_STEER_TABLE_BASE 0x060453CC
#define GEAR_TIMER_VALUE      32
#define GEAR_INPUT_THRESHOLD  0x0258               /* 600 frames before input allowed */

/* 3D mode mask (bits 21-23 of car flags word) */
#define CAR_3D_MODE_MASK      0x00E00000


/* ================================================================
 * Additional globals (beyond game.h)
 * ================================================================ */
#define COLLISION_COUNTER     (*(volatile int *)0x0607EBDC)
#define TOTAL_CAR_COUNT_G     (*(volatile int *)0x0607EA9C)
#define GAME_MODE_WORD        (*(volatile unsigned short *)0x06087804)
#define COURSE_DATA_REF       0x06078680
#define TRACK_SEG_TABLE_PTR   (*(volatile int *)0x0607EB84)
#define ACTIVE_INPUT_CAR_PTR  (*(volatile int *)0x0607EBE0)
#define INPUT_EVENT_COUNTER   (*(volatile char *)0x0607EBEC)


/* ================================================================
 * Extern helper declarations
 * ================================================================ */
extern unsigned int FUN_06027552(int a, int b);
extern void FUN_06027358(int angle, int *sin_out, int *cos_out);
extern int  FUN_0600CD40(void);
extern void FUN_0600CA96(int course_ref);
extern void FUN_0600CC38(int checkpoint, int course_ref);
extern void FUN_0600C8CC(int car, int course_ref);
extern void FUN_0600CF58(int checkpoint);
extern void FUN_0600C928(int car);
extern void FUN_0600C7D4(int car, int course_ref);
extern int  FUN_06006838(int x, int z);
extern void FUN_06027EDE(int transform, int pos_ptr, int output);
extern void FUN_06034F78(int val, int param, int base_ptr);
extern void FUN_06008640(void);
extern void FUN_06035228(void);

/* Forward declarations (defined later in this file) */
#if 0 /* FUN_06008318 -- replaced by ASM import */
void FUN_06008318(void);
#endif
#if 0 /* FUN_0600CEBA -- replaced by ASM import */
void FUN_0600CEBA(void);
#endif


/* ================================================================
 * FUN_0600D266 -- Friction Stub (0x0600D266)
 *
 * CONFIDENCE: DEFINITE
 * Both player and AI physics call this. It's a no-op (rts + nop).
 * Likely a placeholder for a drag model baked into force tables.
 * ================================================================ */
void FUN_0600D266(void)
{
}

/* FUN_06008318 -- original binary (256 bytes) */
__asm__(
    ".section .text.FUN_06008318, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06008318\n"
    ".type _FUN_06008318, @function\n"
    "_FUN_06008318:\n"
    ".byte 0x4F, 0x22, 0xD4, 0x15, 0x90, 0x1C, 0x63, 0x42, 0x00, 0x3E, 0x20, 0x08, 0x89, 0x28, 0x63, 0x42\n"  /* 0x06008318 */
    ".byte 0x90, 0x16, 0x02, 0x3E, 0x72, 0xFF, 0x03, 0x26, 0x65, 0x42, 0xD3, 0x10, 0x62, 0x42, 0x05, 0x5E\n"  /* 0x06008328 */
    ".byte 0x61, 0x23, 0x45, 0x00, 0x90, 0x0D, 0x35, 0x3C, 0x03, 0x1E, 0x43, 0x15, 0x8F, 0x02, 0x65, 0x51\n"  /* 0x06008338 */
    ".byte 0xA0, 0x02, 0x63, 0x5F, 0x61, 0x5F, 0x63, 0x1B, 0x90, 0x06, 0x02, 0x36, 0xA0, 0x43, 0x00, 0x09\n"  /* 0x06008348 */
    ".byte 0x00, 0xB8, 0x01, 0xDC, 0x03, 0x01, 0x02, 0x01, 0x01, 0xD8, 0xFF, 0xFF, 0xAE, 0x11, 0x1B, 0xFF\n"  /* 0x06008358 */
    ".byte 0x06, 0x01, 0xD5, 0xF4, 0x06, 0x03, 0x4F, 0x78, 0x06, 0x07, 0xE9, 0x40, 0x06, 0x04, 0x53, 0xCC\n"  /* 0x06008368 */
    ".byte 0xD2, 0x23, 0x93, 0x3E, 0x62, 0x22, 0x32, 0x37, 0x8B, 0x2D, 0xD3, 0x22, 0x90, 0x3A, 0x63, 0x32\n"  /* 0x06008378 */
    ".byte 0x00, 0x3E, 0x20, 0x08, 0x8B, 0x27, 0xE6, 0x28, 0x62, 0x42, 0xD7, 0x1F, 0x60, 0x23, 0x60, 0x00\n"  /* 0x06008388 */
    ".byte 0xC8, 0x10, 0x8D, 0x0E, 0xE5, 0x20, 0x63, 0x42, 0x90, 0x2D, 0x03, 0x56, 0x63, 0x42, 0xE2, 0xFF\n"  /* 0x06008398 */
    ".byte 0x90, 0x2A, 0x03, 0x26, 0x63, 0x42, 0x27, 0x32, 0x62, 0x42, 0x66, 0x6F, 0x90, 0x25, 0xA0, 0x12\n"  /* 0x060083A8 */
    ".byte 0x02, 0x65, 0x62, 0x42, 0x60, 0x23, 0x60, 0x00, 0xC8, 0x20, 0x89, 0x0C, 0x63, 0x42, 0x90, 0x1A\n"  /* 0x060083B8 */
    ".byte 0x03, 0x56, 0x63, 0x42, 0xE2, 0x01, 0x90, 0x17, 0x03, 0x26, 0x63, 0x42, 0x27, 0x32, 0x62, 0x42\n"  /* 0x060083C8 */
    ".byte 0x66, 0x6F, 0x90, 0x12, 0x02, 0x65, 0xE5, 0x00, 0x62, 0x42, 0x91, 0x0F, 0xD3, 0x0B, 0x43, 0x0B\n"  /* 0x060083D8 */
    ".byte 0x60, 0x53, 0x62, 0x42, 0x91, 0x0B, 0xD3, 0x09, 0x43, 0x0B, 0x60, 0x53, 0x4F, 0x26, 0x00, 0x0B\n"  /* 0x060083E8 */
    ".byte 0x00, 0x09, 0x02, 0x58, 0x00, 0xBC, 0x00, 0xB8, 0x01, 0xDC, 0x00, 0xD4, 0x03, 0x01, 0x02, 0x01\n"  /* 0x060083F8 */
    ".byte 0x06, 0x07, 0xEB, 0xD0, 0x06, 0x07, 0xE9, 0x40, 0x06, 0x07, 0xEB, 0xE0, 0x06, 0x03, 0x4F, 0x78\n"  /* 0x06008408 */
);


/* ================================================================
 * FUN_0600C4F8 -- Speed Curve Calculation (0x0600C4F8)
 *
 * CONFIDENCE: DEFINITE (speed_position.s)
 * Verified instruction-by-instruction against binary 0600C4F8-0600C5D4.
 * All 14 pool constants cross-checked.
 *
 * Algorithm:
 *   1. Decrement frame timer car[0xD4] if positive
 *   2. If state flag bit 15 set: early return
 *   3. If car[0xBC]>0 or car[0xB8]!=0: force decel limit
 *   4. Otherwise: two-table lookup, scale, clamp delta
 *   5. Accumulate into car[0x0C], floor at 0
 *   6. Convert accumulator to speed index car[0x08]
 * ================================================================ */
#if 0 /* FUN_0600C4F8 -- replaced by ASM import */
void FUN_0600C4F8(void)
{
    int car = CAR_PTR_CURRENT;
    short timer;
    int speed_idx, table_a_val, table_b_val;
    int base_speed, target, half, delta;
    int accum;
    unsigned int raw;

    /* Step 1: Decrement frame timer (word) if positive */
    timer = CAR_SHORT(car, CAR_MODE);  /* 0xD4 */
    if (timer > 0) {
        CAR_SHORT(car, CAR_MODE) = timer - 1;
    }

    /* Step 2: Check state flag bit 15 -- skip all speed calc */
    if (GAME_STATE_BIT & SPEED_FLAG_SKIP) {
        return;
    }

    /* Step 3: Check collision/brake flags */
    if (CAR_INT(car, CAR_PHYS_FIELD_BC) > 0 ||   /* 0xBC */
        CAR_INT(car, CAR_STEER_TIMER) != 0) {     /* 0xB8 */
        /* Speed limited: apply deceleration constant */
        CAR_INT(car, CAR_SPEED_DELTA) = SPEED_DECEL_LIMIT;
    } else {
        /* Step 4: Normal speed curve from two course tables */
        speed_idx = CAR_INT(car, CAR_SPEED);  /* 0x08 */

        table_a_val = *(volatile int *)(SPEED_TABLE_A_BASE + speed_idx * 4);
        table_b_val = *(volatile int *)(SPEED_TABLE_B_BASE + speed_idx * 4);
        base_speed = SPEED_BASE_OFFSET + (table_a_val - table_b_val);

        /* Extract upper 16 bits via multiply-by-1 */
        base_speed = (int)FUN_06027552(base_speed, 1);

        /* Scale by per-car tuning parameter */
        target = (int)FUN_06027552(base_speed, CAR_INT(car, CAR_SPEED_SCALE));
        half = target >> 1;  /* arithmetic right shift (shar) */

        /* Compute delta = speed target - accumulator */
        delta = CAR_INT(car, CAR_SPEED_TARGET) - CAR_INT(car, CAR_ACCEL);

        /* Clamp delta to [-4014, half] */
        if (delta < SPEED_DECEL_LIMIT) {
            CAR_INT(car, CAR_SPEED_DELTA) = SPEED_DECEL_LIMIT;
        } else if (delta > half) {
            CAR_INT(car, CAR_SPEED_DELTA) = half;
        } else {
            CAR_INT(car, CAR_SPEED_DELTA) = delta;
        }
    }

    /* Step 5: Accumulate -- add clamped delta, floor at 0 */
    accum = CAR_INT(car, CAR_ACCEL) + CAR_INT(car, CAR_SPEED_DELTA);
    if (accum > 0) {
        CAR_INT(car, CAR_ACCEL) = accum;
    } else {
        CAR_INT(car, CAR_ACCEL) = 0;
    }

    /* Step 6: Convert accumulator to speed index */
    /* shlr16 + exts.w = (short)(unsigned_result >> 16) */
    raw = FUN_06027552(CAR_INT(car, CAR_ACCEL), SPEED_CONV_FACTOR);
    CAR_INT(car, CAR_SPEED) = (int)(short)(raw >> 16);
}
#endif


/* ================================================================
 * FUN_0600C5D6 -- Position Integration (0x0600C5D6)
 *
 * CONFIDENCE: HIGH (speed_position.s)
 * Prologue and dispatch logic verified instruction-by-instruction.
 * Flat-ground sin/cos integration fully verified.
 * 3D transform path annotated but uses stack manipulation elision.
 *
 * High-level flow:
 *   1. Checkpoint processing (FUN_0600CD40)
 *   2. Branch by game mode and car state
 *   3. Steering correction eligibility
 *   4. Heading update
 *   5. Flat ground: sin/cos XZ integration
 *      OR 3D mode: full coordinate transform
 * ================================================================ */
/* FUN_0600C5D6 -- original binary (376 bytes) */
__asm__(
    ".section .text.FUN_0600C5D6, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600C5D6\n"
    ".global _FUN_0600c5d6\n"
    ".type _FUN_0600C5D6, @function\n"
    "_FUN_0600C5D6:\n"
    "_FUN_0600c5d6:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x4F, 0x22, 0x7F, 0xFC, 0xDA, 0x0E\n"  /* 0x0600C5D6 */
    ".byte 0xDB, 0x0F, 0xDE, 0x0F, 0xDD, 0x10, 0xB3, 0xA8, 0x6E, 0xE2, 0x6C, 0x03, 0xD0, 0x0F, 0x60, 0x01\n"  /* 0x0600C5E6 */
    ".byte 0x60, 0x0D, 0x88, 0x02, 0x8D, 0x08, 0x7C, 0x18, 0x90, 0x0A, 0x02, 0xEE, 0x42, 0x15, 0x89, 0x03\n"  /* 0x0600C5F6 */
    ".byte 0x90, 0x07, 0x02, 0xEE, 0x42, 0x15, 0x8B, 0x12, 0xB2, 0x42, 0x64, 0xD3, 0xA0, 0x3E, 0x00, 0x09\n"  /* 0x0600C606 */
    ".byte 0x01, 0xBC, 0x00, 0xB8, 0xFF, 0xFF, 0x00, 0x48, 0x00, 0x00, 0x06, 0x02, 0x75, 0x52, 0x06, 0x07\n"  /* 0x0600C616 */
    ".byte 0xEB, 0xDC, 0x06, 0x07, 0xE9, 0x40, 0x06, 0x07, 0x86, 0x80, 0x06, 0x08, 0x78, 0x04, 0xD2, 0x33\n"  /* 0x0600C626 */
    ".byte 0x62, 0x22, 0x60, 0x23, 0x84, 0x03, 0xC8, 0x08, 0x8B, 0x25, 0x90, 0x59, 0x03, 0xEE, 0x43, 0x15\n"  /* 0x0600C636 */
    ".byte 0x89, 0x21, 0x90, 0x56, 0x00, 0xEC, 0xC8, 0x20, 0x8B, 0x1D, 0xE2, 0x0A, 0x63, 0xB2, 0x33, 0x27\n"  /* 0x0600C646 */
    ".byte 0x89, 0x06, 0x90, 0x4F, 0xE3, 0x66, 0x02, 0xEE, 0x32, 0x33, 0x89, 0x01, 0xB4, 0x79, 0x64, 0xC3\n"  /* 0x0600C656 */
    ".byte 0x90, 0x48, 0x02, 0xEE, 0x42, 0x15, 0x8B, 0x09, 0x90, 0x44, 0x02, 0xEE, 0x72, 0xFE, 0x0E, 0x26\n"  /* 0x0600C666 */
    ".byte 0xB2, 0x0E, 0x64, 0xD3, 0x62, 0xB2, 0x72, 0x01, 0xA0, 0x08, 0x2B, 0x22, 0x65, 0xD3, 0xB2, 0xD8\n"  /* 0x0600C676 */
    ".byte 0x64, 0xC3, 0xA0, 0x03, 0x00, 0x09, 0x65, 0xD3, 0xB2, 0xD3, 0x64, 0xC3, 0xD0, 0x1D, 0x60, 0x01\n"  /* 0x0600C686 */
    ".byte 0x60, 0x0D, 0x88, 0x03, 0x8B, 0x06, 0x90, 0x2E, 0x05, 0xEE, 0x4A, 0x0B, 0x54, 0xC2, 0x91, 0x2B\n"  /* 0x0600C696 */
    ".byte 0x31, 0xEC, 0x21, 0x02, 0x65, 0xD3, 0xB1, 0x0E, 0x64, 0xE3, 0xD2, 0x16, 0x62, 0x22, 0x63, 0x22\n"  /* 0x0600C6A6 */
    ".byte 0xD2, 0x16, 0x23, 0x29, 0x23, 0x38, 0x8B, 0x2C, 0x85, 0xD7, 0x63, 0x03, 0x1E, 0x08, 0x96, 0x1C\n"  /* 0x0600C6B6 */
    ".byte 0x95, 0x1C, 0x54, 0xEA, 0xD3, 0x12, 0x36, 0xEC, 0x35, 0xEC, 0x43, 0x0B, 0x64, 0x4B, 0x90, 0x15\n"  /* 0x0600C6C6 */
    ".byte 0x05, 0xEE, 0x4A, 0x0B, 0x54, 0xE3, 0x53, 0xE4, 0x33, 0x0C, 0x1E, 0x34, 0x90, 0x0D, 0x05, 0xEE\n"  /* 0x0600C6D6 */
    ".byte 0x4A, 0x0B, 0x54, 0xE3, 0x53, 0xE6, 0x33, 0x0C, 0x1E, 0x36, 0xE2, 0x00, 0xA0, 0x24, 0x1E, 0x25\n"  /* 0x0600C6E6 */
    ".byte 0x02, 0x08, 0x01, 0x61, 0x02, 0x04, 0x01, 0x98, 0x01, 0x94, 0x01, 0x90, 0x01, 0x8C, 0x06, 0x07\n"  /* 0x0600C6F6 */
    ".byte 0xE9, 0x44, 0x06, 0x08, 0x78, 0x04, 0x06, 0x07, 0xE9, 0x40, 0x00, 0xE0, 0x00, 0x00, 0x06, 0x02\n"  /* 0x0600C706 */
    ".byte 0x73, 0x58, 0xB1, 0x06, 0x64, 0xE3, 0x65, 0xD3, 0xB0, 0x59, 0x64, 0xE3, 0x66, 0xF3, 0x65, 0xE3\n"  /* 0x0600C716 */
    ".byte 0x2F, 0x66, 0x75, 0x10, 0x2F, 0x56, 0x55, 0xE6, 0xD3, 0x25, 0x43, 0x0B, 0x54, 0xE4, 0x64, 0x03\n"  /* 0x0600C726 */
    ".byte 0x65, 0xF6, 0xD3, 0x23, 0x43, 0x0B, 0x66, 0xF6, 0x7F, 0x04, 0x4F, 0x26, 0x6A, 0xF6, 0x6B, 0xF6\n"  /* 0x0600C736 */
    ".byte 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600C746 */
);



/* ================================================================
 * FUN_0600E71A -- Player Physics Orchestrator (0x0600E71A)
 *
 * CONFIDENCE: DEFINITE (player_physics.s)
 * All 5 jsr targets and inline section verified against binary.
 * Pool constants at 0x0600E7A8-0x0600E7C4 cross-checked.
 *
 * Pipeline:
 *   1. FUN_06008318 -- Controller input: gear shift, steering
 *   2. FUN_06008640 -- Force table selection
 *   3. FUN_0600D266 -- Friction (stub)
 *   4. FUN_0600C4F8 -- Speed computation
 *   5. FUN_0600C5D6 -- Collision/position integration
 *   6. (inline)     -- Timer countdown, segment update
 *   7. FUN_0600CEBA -- Track segment advancement
 *   8. (inline)     -- Score/ranking computation
 * ================================================================ */
#if 0 /* FUN_0600E71A -- replaced by ASM import */
void FUN_0600E71A(void)
{
    int car = CAR_PTR_CURRENT;
    int timer_val;

    /* Step 1: Controller input */
    FUN_06008318();

    /* Step 2: Force table selection */
    FUN_06008640();

    /* Step 3: Friction (no-op stub) */
    FUN_0600D266();

    /* Step 4: Speed computation */
    FUN_0600C4F8();

    /* Step 5: Position integration */
    FUN_0600C5D6();

    /* Step 6 (inline): Timer countdown and track segment check */
    timer_val = CAR_INT(car, CAR_GENERAL_TIMER);  /* 0x208 */
    if (timer_val > 0) {
        timer_val--;
        CAR_INT(car, CAR_GENERAL_TIMER) = timer_val;
        if (timer_val == 0) {
            /* Timer hit zero: read next track segment data */
            int seg_idx = CAR_INT(car, CAR_CHECKPOINT_IDX);  /* 0x1E4 */
            int stride = seg_idx * 24;  /* 8 + 16 = 24 bytes per entry */
            int table_base = CAR_INT(car, CAR_CHECKPOINT_BASE);  /* 0x1E0 */
            int entry_addr = table_base + stride;
            int seg_val = *(volatile short *)(entry_addr + 0x14);

            CAR_INT(car, 0x1F8) = seg_val;
            CAR_INT(car, CAR_STEER_CORRECT) = 0x0400;  /* 0x204 = 1024 */
        }
    }

    /* Step 7: Track segment advancement */
    FUN_0600CEBA();

    /* Step 8 (inline): Score/ranking computation */
    /* ranking = car[0x228] * total_car_count + car[0x1EC] */
    {
        int position = CAR_INT(car, 0x228);
        int count = TOTAL_CAR_COUNT_G;
        int base = CAR_INT(car, CAR_CHECKPOINT_PARAM);  /* 0x1EC */
        CAR_INT(car, 0x1F4) = position * count + base;
    }
}
#endif


#if 0 /* FUN_06008318 -- replaced by ASM import */
/* ================================================================
 * FUN_06008318 -- Controller Input Handler (0x06008318)
 *
 * CONFIDENCE: HIGH (player_physics.s)
 * Pool constants verified against raw binary at 0x06008318-0x060083F8.
 * Key corrections from annotation:
 *   - Timer field is car[0xB8] (not 0x1DC as annotated)
 *   - Gear sound writes to car[0xD4] as word (not 0x258)
 *   - Direction stored at car[0x1DC]
 *   - Steering deflection output at car[0x1D8]
 *
 * Two modes:
 *   A) Active steering timer (car[0xB8] != 0):
 *      Decrement timer, look up deflection from table, apply sign
 *   B) No timer, frame count > threshold:
 *      Check gear shift buttons, start new timer
 *   C) Always: FUN_06034F78 twice for steering column interpolation
 * ================================================================ */
void FUN_06008318(void)
{
    int car = CAR_PTR_CURRENT;
    int steer_timer;

    /* Check active steering timer */
    steer_timer = CAR_INT(car, CAR_STEER_TIMER);  /* 0xB8 */
    if (steer_timer != 0) {
        /* Active steering: decrement timer and apply deflection */
        int new_timer;
        int direction;
        short table_val;
        int deflection;

        new_timer = steer_timer - 1;
        CAR_INT(car, CAR_STEER_TIMER) = new_timer;

        /* Look up deflection from gear steering table */
        table_val = *(volatile short *)(GEAR_STEER_TABLE_BASE + new_timer * 2);

        /* Apply sign based on direction */
        direction = CAR_INT(car, CAR_GEAR_DIR);  /* 0x1DC */
        if (direction > 0) {
            deflection = (int)(short)table_val;
        } else {
            deflection = -(int)(short)table_val;
        }

        CAR_INT(car, CAR_STEER_DEFLECT) = deflection;  /* 0x1D8 */
    } else {
        /* No active steering: check gear shift buttons */
        int frame_count = GAME_STATE_VAR;  /* 0x0607EBD0 */
        if (frame_count > GEAR_INPUT_THRESHOLD) {
            /* Check if input is locked */
            if (CAR_INT(car, CAR_PHYS_FIELD_BC) == 0) {  /* 0xBC */
                unsigned char flags = CAR_UBYTE(car, 0);

                /* Check shift DOWN (bit 0x10) */
                if (flags & 0x10) {
                    CAR_INT(car, CAR_STEER_TIMER) = GEAR_TIMER_VALUE;
                    CAR_INT(car, CAR_GEAR_DIR) = -1;
                    ACTIVE_INPUT_CAR_PTR = car;
                    CAR_SHORT(car, CAR_MODE) = 40;  /* 0xD4 */
                }
                /* Check shift UP (bit 0x20) */
                else if (flags & 0x20) {
                    CAR_INT(car, CAR_STEER_TIMER) = GEAR_TIMER_VALUE;
                    CAR_INT(car, CAR_GEAR_DIR) = 1;
                    ACTIVE_INPUT_CAR_PTR = car;
                    CAR_SHORT(car, CAR_MODE) = 40;  /* 0xD4 */
                }
            }
        }
    }

    /* Finalize: interpolate two steering column values toward 0 */
    /* Original passes args in r0/r1/r2 (non-standard); we use r4/r5/r6 */
    FUN_06034F78(0, 0x0301, car);
    FUN_06034F78(0, 0x0201, car);
}
#endif


/* ================================================================
 * FUN_0600CEBA -- Track Segment Advancement (0x0600CEBA)
 *
 * CONFIDENCE: HIGH (player_physics.s)
 * Segment table via 0x0607EB84, stride=4, heading interpolation
 * via FUN_06035228 confirmed.
 *
 * Reads current segment from car[0x184], looks up heading from
 * segment table, interpolates car heading toward target, and
 * checks for segment boundary crossing.
 * ================================================================ */
#if 0 /* FUN_0600CEBA -- replaced by ASM import */
void FUN_0600CEBA(void)
{
    int car = CAR_PTR_CURRENT;
    int seg_idx;
    int seg_table_base;
    int seg_entry;
    int target_heading;
    int new_heading, old_heading;
    int delta;

    /* Read segment index and table */
    seg_idx = CAR_INT(car, 0x184);
    seg_table_base = TRACK_SEG_TABLE_PTR;

    /* Back up distance */
    CAR_INT(car, CAR_CHECKPOINT_PREV) = CAR_INT(car, CAR_CHECKPOINT_PARAM);

    /* Look up target heading from segment table */
    seg_entry = seg_table_base + seg_idx * 4;
    target_heading = (unsigned short)(*(volatile short *)seg_entry);
    CAR_INT(car, CAR_CHECKPOINT_PARAM) = target_heading;

    /* Interpolate heading via FUN_06035228 (called twice) */
    /* Note: FUN_06035228 exists as Ghidra L1 lift, takes non-standard args */
    /* For now, just call it -- exact param passing TBD */
    FUN_06035228();
    FUN_06035228();

    /* Check segment crossing */
    new_heading = CAR_INT(car, CAR_CHECKPOINT_PARAM);
    old_heading = CAR_INT(car, CAR_CHECKPOINT_PREV);
    delta = (short)(new_heading - old_heading);

    if (delta > 0) {
        int threshold = TOTAL_CAR_COUNT_G - 16;
        if (delta > threshold) {
            /* Segment crossed: increment counters */
            int count = CAR_INT(car, CAR_CHECKPOINT_PREV) + 1;
            CAR_INT(car, CAR_CHECKPOINT_PREV) = count;
            CAR_INT(car, CAR_CHECKPOINT_IDX) = count;

            /* Update distance remaining */
            int total = GAME_STATE_VAR;
            int current = CAR_INT(car, 0x1F4);
            CAR_INT(car, CAR_CHECKPOINT_BASE) = total - current;
            CAR_INT(car, CAR_CHECKPOINT_PARAM) = total;
        }
    }
}
#endif
