#include "game.h"

/* Per-file car struct access macros */
#define CAR_INT(car, off)    (*(volatile int *)((char *)(car) + (off)))

/*
 * alt_physics.c -- Alternate physics pipeline (AI/VS mode)
 *
 * Hand-translated from binary at 0x0600E7C8 (104 instructions).
 *
 * Functions:
 *   FUN_0600E7C8 (0x0600E7C8) -- Alternate car physics update
 *
 * This is the alternate physics pipeline, called for AI-controlled cars
 * or VS mode. It runs a subset of physics subsystems, then performs
 * heading convergence based on a mode byte, and finishes with
 * checkpoint tracking and optional camera projection.
 *
 * Called from physics_entry.c.
 */

/* External dependencies */
extern void FUN_06008318(void);             /* physics subsystem A */
extern void FUN_06008640(void);             /* physics subsystem B */
extern void FUN_0600D266(void);             /* heading/position update */
extern void FUN_0600C4F8(void);             /* speed processing */
extern void FUN_0602D88E(void);             /* misc physics step */
extern void FUN_0600CEBA(void);             /* checkpoint advance */
extern unsigned int FUN_06027552(int a, int b);  /* fpmul: (a*b)>>16 */

/* Mode byte: selects heading convergence algorithm */
#define CONVERGENCE_MODE     (*(volatile unsigned char *)0x06083261)

/* Global multiplier for velocity projection */
#define VEL_PROJ_MULTIPLIER  (*(volatile int *)0x0607EA9C)

/* Car field at offset 0x25C: target heading for convergence */
#define CAR_CONVERGENCE_HDG  0x25C


/* ================================================================
 * FUN_0600E7C8 -- Alternate Physics Pipeline (0x0600E7C8)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600E7C8-0x0600E904)
 * Pool verified:
 *   0x0600E878 = 0x0607E940 (CAR_PTR_CURRENT)
 *   0x0600E87C = 0x06008318 (physics subsystem A)
 *   0x0600E880 = 0x06008640 (physics subsystem B)
 *   0x0600E884 = 0x0600D266 (heading update)
 *   0x0600E888 = 0x0600C4F8 (speed processing)
 *   0x0600E88C = 0x0602D88E (misc physics)
 *   0x0600E890 = 0x06083261 (convergence mode byte)
 *   0x0600E894 = 0x00008000 (180-degree bias)
 *   0x0600E928 = 0x0600CEBA (checkpoint advance)
 *   0x0600E92C = 0x0607EA9C (vel proj multiplier)
 *   0x0600E930 = 0x0607EBC4 (GAME_STATE_BIT)
 *   0x0600E934 = 0x00200000 (state mask for projection)
 *   0x0600E938 = 0x066505B3 (projection constant)
 *   0x0600E93C = 0x06027552 (fpmul)
 * Word pool:
 *   0x0600E86C = 0x025C (convergence heading target)
 *   0x0600E86E = 0x0208 (CAR_GENERAL_TIMER)
 *   0x0600E870 = 0x01E4 (CAR_CHECKPOINT_IDX)
 *   0x0600E872 = 0x01F8 (CAR_TARGET_HDG)
 *   0x0600E874 = 0x0400 (1024, correction count)
 *   0x0600E91E = 0x0228 (CAR_RANKING)
 *   0x0600E920 = 0x01F8 (CAR_TARGET_HDG, reused)
 *   0x0600E922 = 0x00E4 (CAR_PROJECTED_B)
 *   0x0600E924 = 0x00E0 (CAR_PROJECTED_A)
 *
 * Algorithm:
 *   1. Call 5 physics subsystems in sequence
 *   2. Switch on convergence mode byte:
 *      - Mode 1: interpolate heading toward target (25%/frame)
 *      - Mode 2: interpolate with 180° bias (50%/frame), timer logic
 *      - Default: skip to common path
 *   3. Common path: call checkpoint advance, compute vel_proj,
 *      look up segment, optionally project camera
 *
 * 104 instructions. Saves r14, PR, MACL.
 * ================================================================ */
void FUN_0600E7C8(void)
{
    int car = CAR_PTR_CURRENT;

    /* Phase 1: Run physics subsystems */
    FUN_06008318();
    FUN_06008640();
    FUN_0600D266();
    FUN_0600C4F8();
    FUN_0602D88E();

    /* Phase 2: Heading convergence based on mode */
    {
        int mode = CONVERGENCE_MODE;

        if (mode == 1) {
            /* Mode 1: 25% heading convergence per frame */
            int heading2 = CAR_INT(car, CAR_HEADING2);
            int target = CAR_INT(car, CAR_CONVERGENCE_HDG);
            int diff = target - heading2;
            /* shll16, shar, shar, shlr16, exts.w = (short)(diff) >> 2 */
            int scaled = (int)(short)((short)diff >> 2);
            int result = (short)(heading2 + scaled);

            CAR_INT(car, CAR_HEADING3) = result;
            CAR_INT(car, CAR_HEADING2) = result;
        }
        else if (mode == 2) {
            /* Mode 2: 50% heading convergence with 180-degree bias */
            int heading2 = CAR_INT(car, CAR_HEADING2);
            int target = CAR_INT(car, CAR_CONVERGENCE_HDG);
            int diff = target - heading2 + 0x8000;
            /* shll16, shar, shlr16, exts.w = (short)(diff) >> 1 */
            int scaled = (int)(short)((short)diff >> 1);
            int result = (short)(heading2 + scaled);

            CAR_INT(car, CAR_HEADING3) = result;
            CAR_INT(car, CAR_HEADING2) = result;

            /* Timer-based checkpoint target heading update */
            if (CAR_INT(car, CAR_GENERAL_TIMER) != 0) {
                int timer = CAR_INT(car, CAR_GENERAL_TIMER) - 1;
                CAR_INT(car, CAR_GENERAL_TIMER) = timer;

                if (timer == 0) {
                    /* Timer expired: look up checkpoint entry segment */
                    int chk_idx = CAR_INT(car, CAR_CHECKPOINT_IDX);
                    int table_base = CAR_INT(car, CAR_CHECKPOINT_BASE);
                    int entry = table_base + chk_idx * 24;
                    int segment = *(volatile short *)(entry + 0x14);

                    CAR_INT(car, CAR_TARGET_HDG) = segment;
                    CAR_INT(car, CAR_STEER_CORRECT) = 1024;
                }
            }
        }
    }

    /* Phase 3: Common path — checkpoint and projection */
    FUN_0600CEBA();

    /* Compute velocity projection: car[0x1F4] = car[0x228] * multiplier + car[0x1EC] */
    {
        int ranking = CAR_INT(car, CAR_RANKING);
        int multiplier = VEL_PROJ_MULTIPLIER;
        int chk_param = CAR_INT(car, CAR_CHECKPOINT_PARAM);

        CAR_INT(car, CAR_VEL_PROJ) = ranking * multiplier + chk_param;
    }

    /* Look up current checkpoint segment for target heading */
    {
        int chk_idx = CAR_INT(car, CAR_CHECKPOINT_IDX);
        int table_base = CAR_INT(car, CAR_CHECKPOINT_BASE);
        int entry = table_base + chk_idx * 24;
        int segment = *(volatile short *)(entry + 0x14);

        CAR_INT(car, CAR_TARGET_HDG) = segment;
    }

    /* Camera projection if game state allows */
    if (GAME_STATE_BIT & 0x00200000) {
        unsigned int raw;
        int projected;

        raw = FUN_06027552(CAR_INT(car, CAR_ACCEL), 0x066505B3);
        projected = (int)(short)(raw >> 16);

        CAR_INT(car, CAR_PROJECTED_B) = projected;
        CAR_INT(car, CAR_PROJECTED_A) = projected;
    }
}
