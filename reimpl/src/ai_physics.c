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
#if 0 /* FUN_0600C74E -- replaced by ASM import */
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
#endif


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
/* FUN_0600E906 -- original binary (150 bytes) */
__asm__(
    ".section .text.FUN_0600E906, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600E906\n"
    ".type _FUN_0600E906, @function\n"
    "_FUN_0600E906:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x4F, 0x12, 0xDE, 0x0C, 0xD0, 0x0D, 0x60, 0x02, 0x20, 0x08, 0x8D, 0x18\n"  /* 0x0600E906 */
    ".byte 0x6E, 0xE2, 0xE3, 0x00, 0xA0, 0x3B, 0x1E, 0x33, 0x02, 0x28, 0x01, 0xF8, 0x00, 0xE4, 0x00, 0xE0\n"  /* 0x0600E916 */
    ".byte 0xFF, 0xFF, 0x06, 0x00, 0xCE, 0xBA, 0x06, 0x07, 0xEA, 0x9C, 0x06, 0x07, 0xEB, 0xC4, 0x00, 0x20\n"  /* 0x0600E926 */
    ".byte 0x00, 0x00, 0x06, 0x65, 0x05, 0xB3, 0x06, 0x02, 0x75, 0x52, 0x06, 0x07, 0xE9, 0x40, 0x06, 0x07\n"  /* 0x0600E936 */
    ".byte 0xEA, 0xD8, 0xD3, 0x29, 0x43, 0x0B, 0x00, 0x09, 0xD3, 0x29, 0x43, 0x0B, 0x00, 0x09, 0xD5, 0x28\n"  /* 0x0600E946 */
    ".byte 0xD3, 0x29, 0x43, 0x0B, 0x54, 0xE3, 0x40, 0x29, 0x60, 0x0F, 0x1E, 0x02, 0x52, 0xE8, 0xD3, 0x26\n"  /* 0x0600E956 */
    ".byte 0x43, 0x0B, 0x1E, 0x2C, 0x90, 0x3A, 0xD3, 0x25, 0x02, 0xEE, 0x63, 0x32, 0x70, 0xC4, 0x02, 0x37\n"  /* 0x0600E966 */
    ".byte 0x03, 0xEE, 0x02, 0x1A, 0x70, 0x08, 0x32, 0x3C, 0x0E, 0x26, 0x70, 0xF8, 0x00, 0xEE, 0x20, 0x08\n"  /* 0x0600E976 */
    ".byte 0x8B, 0x05, 0xE3, 0x00, 0x90, 0x2B, 0x0E, 0x36, 0x93, 0x2A, 0x70, 0xE8, 0x0E, 0x36, 0x4F, 0x16\n"  /* 0x0600E986 */
    ".byte 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600E996 */
);


/* FUN_0600C74E -- original binary (134 bytes) */
__asm__(
    ".section .text.FUN_0600C74E, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600C74E\n"
    ".type _FUN_0600C74E, @function\n"
    "_FUN_0600C74E:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x4F, 0x22, 0x7F, 0xFC, 0xDE, 0x1D, 0xDD, 0x1D, 0xB2, 0xF1, 0x6E, 0xE2\n"  /* 0x0600C74E */
    ".byte 0xB1, 0x9A, 0x64, 0xD3, 0xE3, 0x2D, 0x90, 0x2B, 0x04, 0xEE, 0x34, 0x37, 0x8B, 0x06, 0xE3, 0x3C\n"  /* 0x0600C75E */
    ".byte 0x34, 0x33, 0x89, 0x03, 0x93, 0x25, 0x1E, 0x3A, 0xA0, 0x03, 0x00, 0x09, 0x65, 0xD3, 0xB0, 0xA6\n"  /* 0x0600C76E */
    ".byte 0x64, 0xE3, 0x52, 0xEA, 0x1E, 0x28, 0x50, 0xE1, 0x20, 0x08, 0x8B, 0x01, 0xB0, 0xF1, 0x64, 0xE3\n"  /* 0x0600C77E */
    ".byte 0xB0, 0xCB, 0x64, 0xE3, 0x65, 0xD3, 0xB0, 0x1E, 0x64, 0xE3, 0x66, 0xF3, 0x65, 0xE3, 0x2F, 0x66\n"  /* 0x0600C78E */
    ".byte 0x75, 0x10, 0x2F, 0x56, 0x55, 0xE6, 0xD3, 0x07, 0x43, 0x0B, 0x54, 0xE4, 0x64, 0x03, 0x65, 0xF6\n"  /* 0x0600C79E */
    ".byte 0xD3, 0x06, 0x43, 0x0B, 0x66, 0xF6, 0x7F, 0x04, 0x4F, 0x26, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600C7AE */
    ".byte 0x01, 0xEC, 0x40, 0x00, 0xFF, 0xFF, 0x06, 0x00, 0x68, 0x38, 0x06, 0x02, 0x7E, 0xDE, 0x06, 0x07\n"  /* 0x0600C7BE */
    ".byte 0xE9, 0x40, 0x06, 0x07, 0x86, 0x80\n"  /* 0x0600C7CE */
);
