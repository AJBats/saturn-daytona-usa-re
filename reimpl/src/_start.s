    .section .text.startup
    .global _start
    .type _start, @function
/* _start() — program entry point and main game loop.
 * Initializes system, then loops: per_frame_update → state dispatch.
 * State table at end drives all game modes (boot, attract, race, etc.).
 * The bitmask computation (1 << state) uses an optimized shift ladder.
 */
_start:
    .global sym_06003000
sym_06003000:
    mov.l .L_system_init, r1
    mov #0x0, r0
    mov.l .L_initial_sp, r15      /* SP = top of stack area */
    jsr @r1                       /* call system_init() */
    ldc r0, sr                    /* SR = 0: unmask all interrupts (delay slot) */
.L_main_loop:
    mov.l .L_per_frame_update, r0
    jsr @r0                       /* call per_frame_update() */
    nop
    mova .L_state_table, r0       /* r0 = state table base address */
    mov.l .L_sym_0605AD10, r1
    mov.l .L_sym_0607EBC0, r2
    mov.l @r1, r1                 /* r1 = current game state index */
    mov.l .L_sym_0607EBC4, r3
    mov.l r1, @r2                 /* shadow copy of state */
    mov r1, r6                    /* r6 = state (for bitmask calc) */
    mov #0x1, r4                  /* r4 = 1 (will become 1 << state) */
    mov #0x10, r5
    cmp/gt r6, r5                 /* 16 > state? */
    bt/s .L_check_8
    mov #0x8, r5                  /* (delay slot) */
    shll16 r4                     /* r4 <<= 16 */
    add #-0x10, r6                /* state -= 16 */
.L_check_8:
    cmp/gt r6, r5                 /* 8 > state? */
    bt/s .L_check_6
    mov #0x6, r5                  /* (delay slot) */
    shll8 r4                      /* r4 <<= 8 */
    add #-0x8, r6                 /* state -= 8 */
.L_check_6:
    cmp/gt r6, r5                 /* 6 > state? */
    bt .L_check_done
    shll2 r4                      /* r4 <<= 2 */
    shll2 r4                      /* r4 <<= 2 */
    shll2 r4                      /* r4 <<= 2 (total <<= 6) */
    add #-0x6, r6                 /* state -= 6 */
.L_check_done:
    tst r6, r6                    /* remaining == 0? */
    bt .L_dispatch
.L_shift_loop:
    dt r6                         /* r6-- */
    bf/s .L_shift_loop
    shll r4                       /* r4 <<= 1 (delay slot) */
.L_dispatch:
    mov.l .L_sym_0607EBC8, r2
    mov.l r4, @r3                 /* state_bitmask = 1 << state */
    mov.l @r2, r5                 /* r5 = frame_counter */
    shll2 r1                      /* r1 = state * 4 */
    mov.l @(r0, r1), r0           /* r0 = state_table[state] */
    add #0x1, r5                  /* frame_counter++ */
    jsr @r0                       /* call state handler */
    mov.l r5, @r2                 /* store frame_counter (delay slot) */
    bra .L_main_loop
    nop

/* Constant pool */
.L_system_init:
    .4byte system_init
.L_per_frame_update:
    .4byte per_frame_update
.L_initial_sp:
    .4byte sym_06003000
.L_sym_0607EBC0:
    .4byte sym_0607EBC0
.L_sym_0607EBC4:
    .4byte sym_0607EBC4
.L_sym_0605AD10:
    .4byte sym_0605AD10
.L_sym_0607EBC8:
    .4byte sym_0607EBC8
/* State dispatch table — indexed by game state (0..38) */
.L_state_table:
    .4byte state_boot_init
    .4byte loc_0600890A
    .4byte state_attract_setup
    .4byte state_attract_active
    .4byte state_mode_select_entry
    .4byte state_mode_select_active
    .4byte state_course_select_init
    .4byte state_course_select_active
    .4byte state_car_select_init
    .4byte state_car_select_active
    .4byte state_loading_init
    .4byte state_loading_check
    .4byte state_race_prepare
    .4byte state_pre_race
    .4byte state_race_setup
    .4byte state_race_main
    .4byte state_post_countdown
    .4byte state_post_lap
    .4byte state_time_extend_setup
    .4byte state_time_extend_active
    .4byte state_race_complete
    .4byte state_post_race_cleanup
    .4byte state_attract_return
    .4byte state_demo_setup
    .4byte state_post_race_init
    .4byte state_post_race_display
    .4byte state_postrace_wait_init
    .4byte state_postrace_countdown
    .4byte state_abort
    .4byte state_results_screen
    .4byte state_resource_load
    .4byte state_memory_route
