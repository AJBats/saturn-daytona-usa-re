#include "game.h"

/*
 * ai_physics.c -- AI car physics pipeline
 *
 * Hand-translated from DEFINITE-confidence annotated ASM
 * (asm/ai_behavior.s) and verified instruction-by-instruction
 * against build/aprog.s raw binary.
 *
 * Functions:
 *   FUN_0600E906  -- AI physics entry (per-car per-frame)
 *   FUN_0600C74E  -- AI processing orchestrator
 *   ai_speed_boost (0x0600C970) -- Speed zone boost lookup (static)
 *
 * The AI physics pipeline is the counterpart to the player physics
 * pipeline in player_physics.c. AI cars follow waypoints instead of
 * controller input, using angle/distance computations for steering
 * and speed control.
 *
 * KEY DIFFERENCE FROM PLAYER:
 *   Player: SMPC input -> force tables -> velocity -> position
 *   AI:     Waypoint angle -> heading damping -> velocity = (target-current)/16
 *
 * Shared helpers with player (stubs in asm_game_core.c):
 *   FUN_0600CD40 -- Waypoint targeting
 *   FUN_0600CA96 -- Course correction
 *   FUN_0600C8CC -- Speed targeting
 *   FUN_0600C928 -- Velocity/friction
 *   FUN_0600C7D4 -- Heading/steering with speed-based damping
 */


/* ================================================================
 * Car struct access macros (same as player_physics.c)
 * ================================================================ */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))
#define CAR_SHORT(car, off)  (*(volatile short *)((char *)(car) + (off)))


/* ================================================================
 * AI-specific constants (from pool constants in ai_behavior.s)
 * All pool addresses verified against binary.
 * ================================================================ */
#define AI_CAR_PTR_ADDR       0x0607E940   /* ptr to current AI car state */
#define COURSE_DATA_BASE      0x06078680   /* track/course data base (r13) */
#define AI_FLAG_ADDR          0x0607EAD8   /* processing flag (0=process) */
#define TOTAL_CAR_COUNT_ADDR  0x0607EA9C   /* total car count for scoring */
#define SPEED_CONV_FACTOR     0x00480000   /* 72 << 16, same as player */
#define SPEED_BOOST_TABLE     0x0605A1E0   /* 30-entry signed word table */

/* Speed zone: override target when track_pos in [46, 59] */
#define SPEED_ZONE_OVERRIDE   0x4000       /* pool at 0x0600C7C0 */

/* Boost zone: add table entry when track_pos in [69, 98] */
#define BOOST_ZONE_LOW        69
#define BOOST_ZONE_HIGH       98


/* ================================================================
 * Extern helper declarations
 * ================================================================ */
extern void         FUN_0600D266(void);
extern unsigned int FUN_06027552(int a, int b);
extern void         FUN_0600CEBA(void);
extern int          FUN_0600CD40(void);
extern void         FUN_0600CA96(int course_ref);
extern void         FUN_0600C8CC(int car, int course_ref);
extern void         FUN_0600C928(int car);
extern void         FUN_0600C7D4(int car, int course_ref);
extern int          FUN_06006838(int x, int z);
extern void         FUN_06027EDE(int transform, int pos_ptr, int output);

/* Forward declaration */
void FUN_0600C74E(void);


/* ================================================================
 * ai_speed_boost (0x0600C970) -- Speed Boost Lookup
 *
 * CONFIDENCE: DEFINITE (ai_behavior.s lines 478-515)
 * Every opcode verified. Range [69,98], table 0x0605A1E0 confirmed.
 *
 * If track position is in [69, 98], adds a signed 16-bit speed
 * adjustment from a 30-entry table to car[0x0C] (accumulator).
 * Creates course-specific speed profiles for AI cars.
 * ================================================================ */
static void ai_speed_boost(int car)
{
    int track_pos = CAR_INT(car, 0x1EC);

    if (track_pos >= BOOST_ZONE_LOW && track_pos <= BOOST_ZONE_HIGH) {
        int index = track_pos - BOOST_ZONE_LOW;
        short adjustment = *(volatile short *)(SPEED_BOOST_TABLE + index * 2);
        CAR_INT(car, 0x0C) += (int)adjustment;
    }
}


/* ================================================================
 * FUN_0600C74E -- AI Processing Orchestrator (0x0600C74E)
 *
 * CONFIDENCE: DEFINITE (ai_behavior.s lines 92-188)
 * All opcodes, branch targets, and pool constants verified against
 * aprog.s byte-for-byte at 0x0600C74E-0x0600C7BC.
 * Pool: 0x0600C7CC=0x0607E940, 0x0600C7D0=0x06078680,
 *       0x0600C7C4=0x06006838, 0x0600C7C8=0x06027EDE
 *
 * Coordinates all AI behavior for one frame:
 *   1. FUN_0600CD40  -- Waypoint targeting
 *   2. FUN_0600CA96  -- Course correction
 *   3. Speed zone check [46,59] or FUN_0600C8CC
 *   4. Copy target heading to current
 *   5. Conditional speed boost (if normal racing mode)
 *   6. FUN_0600C928  -- Velocity/friction
 *   7. FUN_0600C7D4  -- Heading/steering with speed-based damping
 *   8. FUN_06006838  -- Grid coordinate packing
 *   9. FUN_06027EDE  -- AI sprite/rendering update
 * ================================================================ */
void FUN_0600C74E(void)
{
    int car = CAR_PTR_CURRENT;      /* *0x0607E940 */
    int course = COURSE_DATA_BASE;
    int track_pos;
    int output_buf;

    /* Step 1: Waypoint targeting */
    FUN_0600CD40();

    /* Step 2: Course correction */
    FUN_0600CA96(course);

    /* Step 3: Speed zone check */
    track_pos = CAR_INT(car, 0x1EC);
    if (track_pos > 45 && track_pos < 60) {
        /* In speed zone [46, 59]: override target heading/speed */
        CAR_INT(car, 0x28) = SPEED_ZONE_OVERRIDE;
    } else {
        /* Normal: compute target speed from waypoint distance */
        FUN_0600C8CC(car, course);
    }

    /* Step 4: Copy target heading to current */
    CAR_INT(car, 0x20) = CAR_INT(car, 0x28);

    /* Step 5: Conditional speed boost (only in normal racing mode) */
    if (CAR_INT(car, 0x04) == 0) {
        ai_speed_boost(car);
    }

    /* Step 6: Velocity/friction */
    FUN_0600C928(car);

    /* Step 7: Heading/steering update with speed-based damping */
    FUN_0600C7D4(car, course);

    /* Step 8: Pack coordinates into grid index */
    {
        int transform = FUN_06006838(CAR_INT(car, 0x10),    /* X */
                                     CAR_INT(car, 0x18));   /* Z */

        /* Step 9: AI sprite/rendering update */
        FUN_06027EDE(transform,
                     (int)((char *)car + 0x10),
                     (int)&output_buf);
    }
}


/* ================================================================
 * FUN_0600E906 -- AI Physics Entry Point (0x0600E906)
 *
 * CONFIDENCE: DEFINITE (verified against binary lines 24851-24926)
 * All pool constants verified:
 *   0x0600E940 = 0x0607E940 (car ptr)
 *   0x0600E944 = 0x0607EAD8 (flag)
 *   0x0600E9F0 = 0x0600D266 (friction)
 *   0x0600E9F4 = 0x0600C74E (AI orchestrator)
 *   0x0600E9F8 = 0x00480000 (speed conv)
 *   0x0600E9FC = 0x06027552 (fixed_mul)
 *   0x0600EA00 = 0x0600CEBA (track segment)
 *   0x0600EA04 = 0x0607EA9C (total car count)
 *   0x0600E9E2 = 0x0228 (score field offset)
 *   0x0600E9E4 = 0x021C (waypoint tracking field)
 *   0x0600E9E6 = 0x0200 (reset value = 512)
 *
 * Called once per AI car per frame. Pipeline:
 *   1. Check processing flag at 0x0607EAD8
 *   2. FUN_0600D266  -- Friction stub (shared with player)
 *   3. FUN_0600C74E  -- AI processing orchestrator
 *   4. Speed computation (same formula as player)
 *   5. Heading copy to car[0x30]
 *   6. FUN_0600CEBA  -- Track segment advancement (shared)
 *   7. Score/ranking computation
 *   8. Conditional waypoint tracking reset
 * ================================================================ */
void FUN_0600E906(void)
{
    int car = CAR_PTR_CURRENT;      /* *0x0607E940 */
    int flag = *(volatile int *)AI_FLAG_ADDR;

    /* If flag nonzero: clear accumulator and return immediately */
    if (flag != 0) {
        CAR_INT(car, 0x0C) = 0;
        return;
    }

    /* Step 1: Friction (no-op stub, shared with player) */
    FUN_0600D266();

    /* Step 2: AI processing orchestrator */
    FUN_0600C74E();

    /* Step 3: Speed computation (same formula as player)
     * speed = (short)(fixed_mul(accel, 0x480000) >> 16) */
    {
        int speed_raw = (int)FUN_06027552(CAR_INT(car, 0x0C),
                                          SPEED_CONV_FACTOR);
        speed_raw >>= 16;
        CAR_INT(car, 0x08) = (short)speed_raw;
    }

    /* Step 4: Copy heading to car[0x30] */
    CAR_INT(car, 0x30) = CAR_INT(car, 0x20);

    /* Step 5: Track segment advancement */
    FUN_0600CEBA();

    /* Step 6: Score/ranking computation
     * ranking = car[0x228] * total_car_count + car[0x1EC] */
    {
        int position = CAR_INT(car, 0x228);
        int count = *(volatile int *)TOTAL_CAR_COUNT_ADDR;
        int base = CAR_INT(car, 0x1EC);
        CAR_INT(car, 0x1F4) = position * count + base;
    }

    /* Step 7: Conditional waypoint tracking reset
     * If track position index is zero: reset tracking fields */
    if (CAR_INT(car, 0x1EC) == 0) {
        CAR_INT(car, 0x21C) = 0;
        CAR_INT(car, 0x204) = 0x0200;  /* 512 */
    }
}
