#include "game.h"

/*
 * stubs.c -- Placeholder implementations for untranslated functions
 *
 * Each stub is a no-op. As functions get translated into their own .c files,
 * delete the corresponding stub here. The linker will error on duplicates,
 * which tells you what to remove.
 *
 * To find what a stub should do, check:
 *   1. asm/<subsystem>.s  -- annotated ASM with human-readable descriptions
 *   2. build/aprog.s      -- raw disassembly at the function address
 *   3. src/FUN_XXXXXXXX.c -- existing decomp C (if it exists, for the 886 functions)
 *   4. ghidra_project/decomp_all.txt -- Ghidra decompilation output
 */

/* -- Init subsystem stubs (called by system_init / FUN_060030FC) -- */

/* 0x0603BF7C: Hardware subsystem init, param=0 */
void course_system_init(int param) { (void)param; }

/* 0x06034E58: Graphics/rendering setup */
void menu_system_init(void) { }

/* 0x06012CF4: Object/physics table setup */
void game_subsystem_init(void) { }

/* 0x06004A98: Global engine initialization (big function, sets up everything) */
void global_engine_init(void) { }

/* 0x06012E6A: now in resource_loader.c */

/* 0x06018EE4: Camera/viewport initialization */
void cd_system_init(void) { }

/* 0x06005174: Animation/sprite frame init */
void object_system_init(void) { }

/* 0x0601F936: Sound/audio system init */
void render_system_init(void) { }

/* 0x0601492C: now in vdp1_cmd.c */

/* 0x060149E0: now in game_state_utils.c */

/* -- Main loop stubs -- */

/* per_frame_setup: moved to per_frame_setup.c */

/* -- State handler stubs (32-state machine, we have 18 slots) -- */
/* Original addresses from jump table at 0x0600307C */

void state_0_handler(void)  { }  /* 0x060088CC */
void state_1_handler(void)  { }  /* 0x0600890A */
void state_2_handler(void)  { }  /* 0x06008938 -- init sets state=2, so this runs first */
void state_3_handler(void)  { }  /* 0x06008A18 */
void state_4_handler(void)  { }  /* 0x06008CCC */
void state_5_handler(void)  { }  /* 0x06008D74 */
void state_6_handler(void)  { }  /* 0x06008B04 */
void state_7_handler(void)  { }  /* 0x06008B34 */
void state_8_handler(void)  { }  /* 0x06008B78 */
void state_9_handler(void)  { }  /* 0x06008B9C */
void state_10_handler(void) { }  /* 0x06008BD8 */
void state_11_handler(void) { }  /* 0x06008BFC */
void state_12_handler(void) { }  /* 0x06008E00 */
void state_13_handler(void) { }  /* 0x06008E48 */
/* state_14_handler through state_17_handler: moved to race_state_handlers.c */

/* state_18_handler through state_20_handler: moved to race_state_handlers.c */
/* state_21_handler through state_25_handler: moved to race_state_handlers.c */
/* state_26_handler through state_31_handler: moved to race_state_handlers.c */
