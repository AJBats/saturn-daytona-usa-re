#ifndef GAME_H
#define GAME_H

/*
 * game.h -- Daytona USA game state, globals, and function declarations
 *
 * All addresses in the 0x0605xxxx-0x0607xxxx range are work RAM globals.
 * The BIOS/IP.BIN sets up function pointer tables at 0x060003xx before
 * our code runs.
 */

/* ---- BIOS function pointer tables (set up by IP.BIN before we run) ---- */
#define BIOS_FUNC_0310  (*(void (**)(int, int))0x06000310)
#define BIOS_FUNC_0320  (*(void (**)(int))0x06000320)
#define BIOS_FUNC_0344  (*(void (**)(int, int))0x06000344)

/* ---- Game state globals ---- */
#define GAME_STATE       (*(volatile int *)0x0605AD10)
#define GAME_STATE_COPY  (*(volatile int *)0x0607EBC0)
#define GAME_STATE_BIT   (*(volatile int *)0x0607EBC4)
#define FRAME_COUNTER    (*(volatile int *)0x0607EBC8)

/* ---- Memory region pointers (initialized by BIOS, used for clearing) ---- */
#define MEM_REGION1_START (*(int **)0x06059C4C)
#define MEM_REGION1_END   (*(int **)0x06059C50)
#define MEM_REGION2_START (*(int **)0x06059C54)
#define MEM_REGION2_END   (*(int **)0x06059C58)

/* ---- Init functions (called by FUN_060030FC) ---- */
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

/* ---- Main loop functions ---- */
void FUN_0600A392(void);

/* ---- State handler table ---- */
typedef void (*state_handler_t)(void);

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

#endif /* GAME_H */
