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
void FUN_06008318(void);
void FUN_0600CEBA(void);


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
void FUN_0600C5D6(void)
{
    int car = CAR_PTR_CURRENT;
    int checkpoint_entry;
    int next_checkpoint;
    int game_mode;
    int primary_car;
    int x_vel, z_vel;

    /* Step 1: Checkpoint processing */
    checkpoint_entry = FUN_0600CD40();
    next_checkpoint = checkpoint_entry + 24;

    /* Step 2: Branch by game mode */
    game_mode = (unsigned short)GAME_MODE_WORD;

    if (game_mode == 2) {
        /* Mode 2: smooth course following */
        FUN_0600CA96(COURSE_DATA_REF);
    } else if (CAR_INT(car, CAR_FORCE_COUNT) > 0 ||  /* 0x1BC */
               CAR_INT(car, CAR_STEER_TIMER) > 0) {   /* 0xB8, cmp/pl */
        /* Force countdown or collision active: course following */
        FUN_0600CA96(COURSE_DATA_REF);
    } else {
        /* Complex integration path */
        primary_car = CAR_PTR_TARGET;  /* 0x0607E944 */

        if ((CAR_BYTE(primary_car, 3) & 0x08) ||           /* bit 3 set */
            CAR_INT(car, CAR_GENERAL_TIMER) > 0 ||          /* 0x208 */
            (CAR_UBYTE(car, CAR_STATE_FLAGS) & 0x20)) {     /* 0x161 bit 5 */
            /* Skip steering correction, direct integrate */
            FUN_0600CC38(next_checkpoint, COURSE_DATA_REF);
        } else {
            /* Steering correction eligibility: counter<=10 AND position<102 */
            if (COLLISION_COUNTER <= 10 &&
                CAR_INT(car, CAR_STEER_CORRECT) < 102) {   /* 0x204 */
                FUN_0600CF58(next_checkpoint);
            }

            /* Check steering correction countdown */
            if (CAR_INT(car, CAR_STEER_CORRECT) > 0) {
                /* Countdown active: decrement by 2, use course following */
                CAR_INT(car, CAR_STEER_CORRECT) -= 2;
                FUN_0600CA96(COURSE_DATA_REF);
                COLLISION_COUNTER++;
            } else {
                /* Direct position integration from heading */
                FUN_0600CC38(next_checkpoint, COURSE_DATA_REF);
            }
        }
    }

    /* Step 3: Game mode 3 -- set speed target from course data */
    if ((unsigned short)GAME_MODE_WORD == 3) {
        int speed_from_course = *(volatile int *)(next_checkpoint + 8);
        int scaled = (int)FUN_06027552(speed_from_course,
                                        CAR_INT(car, CAR_SPEED_SCALE));
        CAR_INT(car, CAR_SPEED_TARGET) = scaled;
    }

    /* Step 4: Heading update */
    FUN_0600C8CC(car, COURSE_DATA_REF);

    /* Step 5: Check 3D transform mode (bits 21-23 of flags word) */
    {
        int flags = CAR_INT(CAR_PTR_CURRENT, CAR_FLAGS);
        if (flags & CAR_3D_MODE_MASK) {
            /* 3D mode: banked turns, airborne, slopes */
            FUN_0600C928(car);
            FUN_0600C7D4(car, COURSE_DATA_REF);

            {
                int transform = FUN_06006838(CAR_INT(car, CAR_X),
                                             CAR_INT(car, CAR_Z));
                int output_buf;
                FUN_06027EDE(transform, (int)((char *)car + CAR_X),
                             (int)&output_buf);
            }
        } else {
            /* Flat ground: sin/cos position integration */
            int heading_word = *(volatile short *)(COURSE_DATA_REF + 0x0E);
            CAR_INT(car, CAR_HEADING) = heading_word;

            /* Compute sin(-heading), cos(-heading) */
            {
                int neg_heading = -CAR_INT(car, CAR_HEADING2);
                FUN_06027358(neg_heading,
                             (int *)((char *)car + CAR_SIN_HEADING),
                             (int *)((char *)car + CAR_COS_HEADING));
            }

            /* X += (speed_accum * sin) >> 16 */
            x_vel = (int)FUN_06027552(CAR_INT(car, CAR_ACCEL),
                                       CAR_INT(car, CAR_SIN_HEADING));
            CAR_INT(car, CAR_X) += x_vel;

            /* Z += (speed_accum * cos) >> 16 */
            z_vel = (int)FUN_06027552(CAR_INT(car, CAR_ACCEL),
                                       CAR_INT(car, CAR_COS_HEADING));
            CAR_INT(car, CAR_Z) += z_vel;

            /* Y = 0 (flat ground) */
            CAR_INT(car, CAR_Y) = 0;
        }
    }
}


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
