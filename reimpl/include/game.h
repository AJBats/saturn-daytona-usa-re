/* game.h -- Daytona USA game state, structures, and globals
 *
 * Derived from annotated ASM files: player_physics.s, speed_position.s,
 * car_collision.s, collision_response.s, force_system.s, force_tables.s,
 * lap_counting.s, vblank_system.s, ai_behavior.s, ai_physics_pipeline.s.
 *
 * All offsets verified against pool constants in aprog.s disassembly.
 */

#ifndef GAME_H
#define GAME_H

#include "saturn.h"

/* ===================================================================
 * Fixed-Point Math
 *
 * All arithmetic in Daytona is 32-bit fixed-point. No FPU on SH-2.
 * Most values use 16.16 format (top 16 = integer, bottom 16 = frac).
 * Angles are 16-bit (0x0000-0xFFFF = 0-360 degrees), often stored
 * in 32-bit registers with only lower 16 bits meaningful.
 * =================================================================== */
typedef int fixed16;    /* 16.16 fixed-point */
typedef int angle16;    /* 16-bit angle in 32-bit container */


/* ===================================================================
 * Car Object Struct (0x268 bytes per car, 40 slots)
 *
 * Base address: 0x06078900
 * Stride: 0x268 (616 bytes)
 * Active cars: determined by car_count at 0x0607EAD8
 *
 * This is THE central data structure of the game. Every subsystem
 * (physics, rendering, collision, AI, lap counting) accesses it.
 * =================================================================== */

#define CAR_ARRAY_BASE      0x06078900
#define CAR_STRUCT_SIZE     0x268
#define MAX_CARS            40

/* Car struct field offsets -- used for raw pointer arithmetic in L1 code.
 * These will become struct fields in L2 when we define CarState. */

#define CAR_FLAGS           0x000   /* int:  bit flags (see below) */
#define CAR_FLAGS_BYTE0     0x000   /* byte: input flags */
#define CAR_FLAGS_BYTE1     0x001   /* byte: secondary flags */
#define CAR_FLAGS_BYTE3     0x003   /* byte: collision/state flags */
#define CAR_SUBTYPE         0x004   /* int:  car sub-type / partner ptr */
#define CAR_SPEED           0x008   /* int:  speed (heading-relative scalar) */
#define CAR_ACCEL           0x00C   /* int:  acceleration / distance accum */
#define CAR_X               0x010   /* int:  X position (world coords) */
#define CAR_Y               0x014   /* int:  Y position (world coords) */
#define CAR_Z               0x018   /* int:  Z position (world coords) */
#define CAR_HEADING         0x020   /* int:  heading (yaw angle) */
#define CAR_HEADING2        0x028   /* int:  heading copy (stored/target) */
#define CAR_HEADING3        0x030   /* int:  heading copy (tertiary) */
#define CAR_PRE_COLL_X      0x038   /* int:  pre-collision X backup */
#define CAR_PRE_COLL_Z      0x03C   /* int:  pre-collision Z backup */

#define CAR_STEER_TIMER     0x0B8   /* int:  steering input timer */
#define CAR_PHYS_FIELD_BC   0x0BC   /* int:  force secondary timer */
#define CAR_MODE            0x0D4   /* short: mode field (20=force, 40=gear, 10=steer) */
#define CAR_SPEED_DELTA     0x0FC   /* int:  clamped speed delta */

#define CAR_STATE_FLAGS     0x161   /* byte: state flags (bit 5 = steer override) */

#define CAR_SIN_HEADING     0x18C   /* int:  sin(-heading) cached */
#define CAR_COS_HEADING     0x190   /* int:  cos(-heading) cached */
#define CAR_SPEED_TARGET    0x194   /* int:  speed target */
#define CAR_SPEED_SCALE     0x198   /* int:  per-car speed curve */

#define CAR_FORCE_SUB       0x1B4   /* int:  force sub-record value */
#define CAR_FORCE_PTR       0x1B8   /* int:  force running pointer */
#define CAR_FORCE_COUNT     0x1BC   /* int:  force primary countdown */
#define CAR_STATE_BITS      0x1C0   /* int:  state bits (bits 30-31) */
#define CAR_FORCE_X         0x1C8   /* int:  X force component */
#define CAR_FORCE_Z         0x1CC   /* int:  Z force component */
#define CAR_FORCE_ANG       0x1D0   /* int:  angular force */
#define CAR_STEER_DEFLECT   0x1D8   /* int:  gear steering deflection */
#define CAR_GEAR_DIR        0x1DC   /* int:  gear direction (+1/-1) */

#define CAR_CHECKPOINT_BASE 0x1E0   /* int:  checkpoint table base ptr */
#define CAR_CHECKPOINT_IDX  0x1E4   /* int:  current checkpoint index */
#define CAR_CHECKPOINT_CUM  0x1E8   /* int:  cumulative checkpoint count */
#define CAR_CHECKPOINT_PARAM 0x1EC  /* int:  checkpoint parameter */
#define CAR_CHECKPOINT_PREV 0x1F0   /* int:  previous frame checkpoint */

#define CAR_STEER_CORRECT   0x204   /* int:  steering correction countdown */
#define CAR_GENERAL_TIMER   0x208   /* int:  general timer */

#define CAR_GEAR_SOUND      0x258   /* short: gear shift sound param */

/* Car flags (offset +0x000, 32-bit) */
#define CAR_FLAG_GAS        0x40    /* byte 0 bit 6: gas button */
#define CAR_FLAG_BRAKE      0x80    /* byte 0 bit 5: brake button */
#define CAR_FLAG_SHIFT_UP   0x20    /* byte 0 bit 5: shift up */
#define CAR_FLAG_SHIFT_DOWN 0x10    /* byte 0 bit 4: shift down */
#define CAR_FLAG_SPECIAL    0x08    /* byte 0 bit 3: special state */
#define CAR_FLAG_COLLISION  (1 << 27) /* bit 27: collision occurred */
#define CAR_FLAG_ACTIVE     0x00E00000 /* bits 21-23: car type (0=inactive) */
#define CAR_FLAG_3D_MODE    0x00E00000 /* bits 21-23: 3D transform mode */


/* ===================================================================
 * Game State Machine
 *
 * The main loop is a 32-state machine. Each state has a handler
 * function and per-state frame timing target.
 * =================================================================== */

#define NUM_GAME_STATES     32

/* Game state globals */
#define GAME_STATE          (*(volatile int *)0x0605AD10)
#define GAME_STATE_COPY     (*(volatile int *)0x0607EBC0)
#define GAME_STATE_BIT      (*(volatile int *)0x0607EBC4)
#define FRAME_COUNTER       (*(volatile int *)0x0607EBC8)
#define GAME_STATE_VAR      (*(volatile int *)0x0607EBD0)

/* State handler function pointer type */
typedef void (*state_handler_t)(void);


/* ===================================================================
 * VBlank / Frame Timing State
 *
 * Documented in vblank_system.s (DEFINITE confidence).
 * Two-phase VBlank: IN handler (0x06006F3C) and OUT handler (0x06007268).
 * =================================================================== */

#define VBLANK_COUNTER      (*(volatile int *)0x0607864C)   /* incremented every 1/60s */
#define VBLANK_OUT_COUNTER  (*(volatile int *)0x06059F44)   /* VBlank-OUT counter */
#define VBLANK_PHASE        (*(volatile int *)0x06059F54)   /* 1=IN, 3=OUT-start, 4=OUT-end */

#define FB_STATE            (*(volatile unsigned short *)0x060635B4)  /* frame buffer state (0-3) */
#define FB_STATE_VAR        (*(volatile int *)0x06063F58)    /* frame buffer state variable */
#define FRAME_SEC_COUNTER   (*(volatile int *)0x060635C0)    /* secondary frame counter */
#define FRAME_READY_FLAG    (*(volatile int *)0x060635C4)    /* cleared when buffer swapped */

#define VBL_DISABLE_FLAG    (*(volatile unsigned short *)0x0605A00C)  /* non-zero = skip VBlank handler */
#define TVMR_SHADOW         (*(volatile unsigned short *)0x060A4C90)  /* cached VDP1 TVMR setting */
#define FBCR_SHADOW         (*(volatile unsigned short *)0x060A4C92)  /* cached VDP1 FBCR setting */

#define FBCR_SWAP_MODE      (*(volatile int *)0x060635B8)    /* 1 = timed FBCR swap active */
#define FBCR_SWAP_THRESHOLD (*(volatile int *)0x060635BC)    /* frame count threshold for swap */

/* Timing computation variables */
#define TIMING_VAL_3C       (*(volatile int *)0x06059F3C)
#define TIMING_VAL_38       (*(volatile int *)0x06059F38)
#define TIMING_RESULT       (*(volatile int *)0x06059F34)
#define TIMING_BASE_ADDR    0x0606B178

/* Per-state frame timing targets (byte array, 32 entries) */
#define FRAME_TIMING_TABLE  ((volatile unsigned char *)0x06059F58)


/* ===================================================================
 * Controller Input
 *
 * From vblank_system.s VBlank-IN handler button processing.
 * =================================================================== */

#define INPUT_STATE         (*(volatile int *)0x0605B6D8)    /* processed input state */

/* Input button bits (tested in VBlank-IN handler) */
#define INPUT_SPECIAL       0x20000000  /* bit 29: special/system button */
#define INPUT_RIGHT         0x04        /* bit 2: right direction */
#define INPUT_LEFT          0x10        /* bit 4: left direction */
#define INPUT_START         0x20        /* bit 5: start button */
#define INPUT_A_GAS         0x40        /* bit 6: A button (gas) */
#define INPUT_B_BRAKE       0x80        /* bit 7: B button (brake) */


/* ===================================================================
 * Car System Globals
 * =================================================================== */

#define CAR_PTR_CURRENT     (*(volatile int *)0x0607E940)    /* current car ptr (player) */
#define CAR_PTR_TARGET      (*(volatile int *)0x0607E944)    /* target car ptr (for collision) */
#define CAR_COUNT           (*(volatile int *)0x0607EAD8)    /* active car count */
#define DEMO_MODE_FLAG      (*(volatile int *)0x0607EAE0)    /* non-zero = demo (skip collisions) */


/* ===================================================================
 * Rendering Pipeline State
 *
 * High-reference addresses from game RAM map.
 * 0x06094A30 (185 refs) and 0x06094AB0 (87 refs) are core render state.
 * =================================================================== */

#define RENDER_STATE_A      (*(volatile int *)0x06094A30)    /* primary render state (185 refs) */
#define RENDER_STATE_B      (*(volatile int *)0x06094AB0)    /* secondary render state (87 refs) */
#define RENDER_PARAM_A      (*(volatile int *)0x06094A28)    /* render parameter */
#define RENDER_PARAM_B      (*(volatile int *)0x06094A20)    /* render parameter */
#define RENDER_OUTPUT       (*(volatile int *)0x06094EF4)    /* render output state */

#define VDP1_CMD_BASE_PTR   (*(volatile int *)0x0605A008)    /* VDP1 command buffer ptr */
#define VDP1_CMD_FLAG       (*(volatile int *)0x06059F44)    /* VDP1 rendering flag */
#define VDP1_BATCH_FLAG     (*(volatile int *)0x060635AC)    /* VDP1 batch flag */

/* Color palette bank select */
#define PALETTE_BANK_SEL    (*(volatile short *)0x060635DE)  /* selects CRAM bank */


/* ===================================================================
 * Sound System State
 *
 * From sound_driver.s (HIGH confidence).
 * =================================================================== */

#define SOUND_TIMEOUT_FLAG  (*(volatile int *)0x06086050)    /* set to 1 on mailbox timeout */
#define SOUND_CMD_MIRROR    (*(volatile int *)0x0608604C)    /* local sound command mirror */
#define SOUND_CHAN_STATE     (*(volatile int *)0x0605DF94)    /* channel state address */


/* ===================================================================
 * Object State
 *
 * High-reference addresses from game RAM map.
 * =================================================================== */

#define OBJ_STATE_PRIMARY   (*(volatile int *)0x06089EDC)    /* 118 refs -- primary obj state */
#define OBJ_STATE_SECONDARY (*(volatile int *)0x0608A52C)    /* 55 refs */
#define OBJ_RENDER_FLAGS    (*(volatile short *)0x0608AC20)  /* 51 refs */


/* ===================================================================
 * CD / Session State
 * =================================================================== */

#define CD_SESSION_BASE     (*(volatile int *)0x060A5400)    /* 99 refs -- CD session data */
#define CD_STATE_A          (*(volatile int *)0x060A4D14)    /* 44 refs */
#define CD_STATE_B          (*(volatile int *)0x060A3E68)    /* 34 refs */


/* ===================================================================
 * Memory Region Pointers (initialized by BIOS, used for clearing)
 * =================================================================== */

#define MEM_REGION1_START   (*(int **)0x06059C4C)
#define MEM_REGION1_END     (*(int **)0x06059C50)
#define MEM_REGION2_START   (*(int **)0x06059C54)
#define MEM_REGION2_END     (*(int **)0x06059C58)


/* ===================================================================
 * Phase / Course Control
 *
 * From force_tables.s and game state analysis.
 * =================================================================== */

#define PHASE_FLAG          (*(volatile short *)0x0605A016)   /* phase (set 4 on force expire) */
#define COURSE_SELECT       (*(volatile int *)0x0605AD00)     /* current course index */

/* Force system globals */
#define FORCE_GEAR_CAR_PTR  (*(volatile int *)0x0607EBE0)    /* gear shift car ptr storage */
#define FORCE_SETUP_COUNT   (*(volatile char *)0x0607EBEC)   /* force setup counter */


/* ===================================================================
 * Display Elements
 *
 * Frame-related display state from vblank_system.s button handlers.
 * =================================================================== */

#define DISPLAY_SCROLL_A    (*(volatile int *)0x06063F60)    /* scroll/display param A */
#define DISPLAY_TIMING      (*(volatile int *)0x06059F34)    /* computed timing value */
#define DISPLAY_RENDER_A    (*(volatile int *)0x060612B4)    /* render address A */
#define DISPLAY_RENDER_B    (*(volatile int *)0x0606129C)    /* render address B */


/* ===================================================================
 * Function Declarations
 *
 * Init functions (called by FUN_060030FC / system_init)
 * =================================================================== */

void system_init(void);
void sound_timer_init(void);
void vdp_init_dispatcher(void);

void FUN_0603BF7C(int param);
void FUN_06034E58(void);
void FUN_06012CF4(void);
void FUN_06004A98(void);
void FUN_06012E6A(void);
void FUN_06018EE4(void);
void FUN_06005174(void);
void FUN_0601F936(void);
void FUN_0601492C(void);
void FUN_060149E0(void);

/* Main loop */
void FUN_0600A392(void);

/* State handlers */
extern const state_handler_t state_handlers[];

void state_0_handler(void);
void state_1_handler(void);
void state_2_handler(void);
void state_3_handler(void);
void state_4_handler(void);
void state_5_handler(void);
void state_6_handler(void);
void state_7_handler(void);
void state_8_handler(void);
void state_9_handler(void);
void state_10_handler(void);
void state_11_handler(void);
void state_12_handler(void);
void state_13_handler(void);
void state_14_handler(void);
void state_15_handler(void);
void state_16_handler(void);
void state_17_handler(void);
void state_18_handler(void);
void state_19_handler(void);
void state_20_handler(void);
void state_21_handler(void);
void state_22_handler(void);
void state_23_handler(void);
void state_24_handler(void);
void state_25_handler(void);
void state_26_handler(void);
void state_27_handler(void);
void state_28_handler(void);
void state_29_handler(void);
void state_30_handler(void);
void state_31_handler(void);


#endif /* GAME_H */
