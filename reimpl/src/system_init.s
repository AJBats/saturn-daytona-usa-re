/* system_init.s -- System initialization (called from _start)
 * Translation unit: 0x060030FC - 0x060032D4
 *
 * Function catalog:
 *   system_init       — Full system boot: SMPC reset enable, BSS clear,
 *                       secondary SH-2 startup, interrupts, VDP, sound, CD.
 *   sound_timer_init  — Configure SH-2 FRT (Free-Running Timer) for sound timing.
 *   vdp_init_dispatch — Install SCU interrupt vectors for VDP/timer handlers.
 *
 * Boot sequence (system_init):
 *   1. Send RESENAB (0x19) to SMPC — enables hardware reset button
 *   2. Zero BSS regions (two ranges)
 *   3. Initialize subsystem manager (sym_0603BF7C)
 *   4. Start secondary SH-2 (sym_06034E58 = SMPC SSHON sequence)
 *   5. Set SCU interrupt mask (disable most interrupts)
 *   6. Initialize CD subsystem (cd_progress_notify)
 *   7. Install VDP interrupt vectors (vdp_init_dispatch)
 *   8. Initialize game engine (engine_init_global)
 *   9. Boot SCSP sound system (sound_scsp_boot)
 *  10. Configure FRT for sound timing (sound_timer_init)
 *  11. Initialize sound channels (race_sound_handler)
 *  12. Re-enable needed interrupts (unmask VBlank etc.)
 *  13. Initialize camera, display channels, special handlers
 *  14. Set boot state = 2 (ready)
 */

    .section .text.FUN_060030FC


/* system_init() — Called once from _start. Initializes all hardware and
 * software subsystems, ending with game state = 2 (boot complete).
 */
    .global system_init
    .type system_init, @function
system_init:
    mov.l r14, @-r15
    mov #0x1, r14              /* r14 = 1 (poll mask + SMPC busy flag) */
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x0, r12              /* r12 = 0 (BSS fill value) */
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_bss_end_a, r10
    mov.l   .L_bss_end_b, r11
    mov.l   .L_smpc_sf, r13   /* r13 = 0x20100063 (SMPC SF register) */
    mov.l   .L_fn_subsys_init, r3
    mov.l @r3, r3
    jsr @r3                    /* subsystem pre-init(r4=1) */
    mov r14, r4

    /* === Step 1: Send RESENAB to SMPC (enable reset button) === */
.L_0600311A:
    mov.b @r13, r2             /* read SMPC SF */
    extu.b r2, r2
    and r14, r2                /* test bit 0 (busy) */
    cmp/eq r14, r2
    bt      .L_0600311A        /* spin while SF.busy == 1 */
    extu.b r14, r2
    mov.b r2, @r13             /* SF = 1 (set busy before command) */
    mov #0x19, r3              /* 0x19 = RESENAB command */
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2              /* SMPC COMREG = RESENAB */
.L_0600312E:
    mov.b @r13, r2             /* read SMPC SF */
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0600312E        /* spin while SF.busy == 1 (command executing) */

    /* === Step 2: Zero BSS region A === */
    mov.l   .L_bss_start_a, r4
    bra     .L_06003142
    mov.l @r4, r4              /* r4 = BSS start address */
.L_0600313E:
    mov.l r12, @r4             /* *r4 = 0 */
    add #0x4, r4
.L_06003142:
    mov.l @r11, r2             /* r2 = BSS end address */
    cmp/hs r2, r4              /* r4 >= end? */
    bf      .L_0600313E        /* no: keep zeroing */

    /* Zero BSS region B */
    mov.l   .L_bss_start_b, r4
    bra     .L_06003170
    mov.l @r4, r4
    .2byte  0xFFFF             /* padding */

    /* === Constant pool: boot setup === */
.L_bss_end_a:
    .4byte  sym_06059C58       /* BSS region A end pointer */
.L_bss_end_b:
    .4byte  sym_06059C50       /* BSS region B end pointer */
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_fn_subsys_init:
    .4byte  sym_06000320       /* subsystem pre-init function ptr */
.L_smpc_comreg_ct:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_bss_start_a:
    .4byte  sym_06059C4C       /* BSS region A start pointer */
.L_bss_start_b:
    .4byte  sym_06059C54       /* BSS region B start pointer */
.L_0600316C:
    mov.l r12, @r4             /* *r4 = 0 */
    add #0x4, r4
.L_06003170:
    mov.l @r10, r2
    cmp/hs r2, r4
    bf      .L_0600316C

    /* === Step 3-14: Subsystem initialization chain === */
    mov.l   .L_fn_bus_init, r3
    jsr @r3                    /* bus/memory controller init (r4=0) */
    mov #0x0, r4
    mov.l   .L_fn_secondary_boot, r3
    jsr @r3                    /* secondary SH-2 startup (SMPC SSHON + init) */
    nop
    mov.l   .L_fn_int_setup, r2
    mov.w   .L_int_mask_boot, r5 /* r5 = 0x0083 (mask: VBI + Timer0 + Timer1) */
    mov.l @r2, r2
    jsr @r2                    /* SCU interrupt setup: disable most, keep VBI+timers */
    mov #-0x1, r4              /* r4 = -1 (all bits = enable param) */
    mov.l   .L_fn_cd_init, r3
    jsr @r3                    /* cd_progress_notify() — init CD subsystem */
    nop
    bsr     vdp_init_dispatch  /* install VDP interrupt handlers */
    nop
    mov.l   .L_fn_engine_init, r3
    jsr @r3                    /* engine_init_global() */
    nop
    mov.l   .L_fn_sound_boot, r3
    jsr @r3                    /* sound_scsp_boot() — boot sound CPU */
    nop
    bsr     sound_timer_init   /* configure FRT for sound timing */
    nop
    mov.l   .L_fn_race_sound, r3
    jsr @r3                    /* race_sound_handler() — init sound channels */
    nop
    mov.l   .L_fn_int_setup, r2
    mov.w   .L_int_mask_run, r4 /* r4 = 0xFF7C (unmask: VBI, HBI, sprite end, etc.) */
    mov.l @r2, r2
    jsr @r2                    /* SCU interrupt setup: enable runtime interrupts */
    mov #0x0, r5               /* r5 = 0 */
    mov.l   .L_fn_camera_init, r3
    jsr @r3                    /* camera subsystem init */
    nop
    mov.l   .L_fn_display_init, r3
    jsr @r3                    /* display subsystem init */
    nop
    mov.l   .L_fn_channel_cfg, r3
    jsr @r3                    /* channel_config_a() */
    nop
    mov.l   .L_fn_special_init, r3
    jsr @r3                    /* special handler init */
    nop
    mov #0x2, r2
    mov.l   .L_boot_state, r3
    mov.l r2, @r3              /* boot_state = 2 (initialization complete) */
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    /* === Word pool === */
.L_int_mask_boot:
    .2byte  0x0083             /* SCU interrupt mask: VBlank-IN + Timer0 + Timer1 */
.L_int_mask_run:
    .2byte  0xFF7C             /* SCU interrupt mask: enable runtime interrupts */
    .2byte  0xFFFF             /* padding */

    /* === Constant pool: init functions === */
.L_fn_bus_init:
    .4byte  sym_0603BF7C       /* bus/memory controller init */
.L_fn_secondary_boot:
    .4byte  sym_06034E58       /* secondary SH-2 boot sequence */
.L_fn_int_setup:
    .4byte  sym_06000344       /* SCU interrupt setup function ptr */
.L_fn_cd_init:
    .4byte  cd_progress_notify
.L_fn_engine_init:
    .4byte  engine_init_global
.L_fn_sound_boot:
    .4byte  sound_scsp_boot
.L_fn_race_sound:
    .4byte  race_sound_handler
.L_fn_camera_init:
    .4byte  sym_06005174       /* camera subsystem init */
.L_fn_display_init:
    .4byte  sym_0601F936       /* display subsystem init */
.L_fn_channel_cfg:
    .4byte  channel_config_a
.L_fn_special_init:
    .4byte  sym_060149E0       /* special handler init */
.L_boot_state:
    .4byte  sym_0605AD10       /* boot state variable (0=booting, 2=ready) */

/* sound_timer_init() — Configure SH-2 Free-Running Timer (FRT)
 * Sets up FRT for sound timing interrupts.
 *
 * SH-2 FRT registers (base 0xFFFFFE10):
 *   TIER (+0x00) = Timer Interrupt Enable — set OCIAE (Output Compare A IE)
 *   FTCSR (+0x01) = Timer Status — set CCLRA (clear on compare A match)
 *   TCR (+0x06) = Timer Control — clock select, clear source
 *   OCRA (+0x04) = Output Compare A — match value
 *
 * Configures: OCRA for periodic interrupts, enables compare-match interrupt.
 */
    .global sound_timer_init
    .type sound_timer_init, @function
sound_timer_init:
    sts.l pr, @-r15
    mov.l   .L_fn_vector_setup, r3
    mov.l   .L_fn_frt_handler, r5
    mov.l @r3, r3
    jsr @r3                    /* install FRT interrupt handler (vector 0x65) */
    mov #0x65, r4              /* r4 = FRT OCIA vector number */
    mov.w   .L_frt_tier, r5   /* r5 = 0xFFFFFE10 (TIER register) */
    mov.b @r5, r4
    mov #0xF, r2
    and r2, r4                 /* clear upper nibble of TIER */
    extu.b r4, r0
    or #0x8, r0                /* set bit 3 = OCIAE (Output Compare A IE) */
    extu.b r0, r0
    mov.b r0, @r5              /* write TIER */
    mov.w   .L_frt_ftcsr, r6  /* r6 = 0xFFFFFE11 (FTCSR register) */
    mov.b @r6, r4
    mov #0x1, r5
    extu.b r4, r4
    or r5, r4                  /* set bit 0 = CCLRA (clear on compare A) */
    extu.b r4, r4
    mov.b r4, @r6              /* write FTCSR */
    mov.w   .L_frt_tcr, r4    /* r4 = 0xFFFFFE16 (TCR register) */
    mov.b @r4, r3
    extu.b r3, r3
    mov #-0x4, r2
    and r2, r3                 /* clear bits [1:0] (clock = internal/1) */
    mov.b r3, @r4              /* write TCR */
    add #0x1, r4               /* r4 = 0xFFFFFE17 (TOCR) */
    mov.b @r4, r3
    extu.b r3, r3
    mov #-0x11, r2             /* 0xEF = ~0x10 */
    and r2, r3                 /* clear bit 4 */
    extu.b r3, r3
    mov.b r3, @r4              /* write TOCR */
    mov.w   .L_frt_ocra, r3   /* r3 = 0xFFFFFE14 (OCRA high byte) */
    mov.b r5, @r3              /* OCRA high = 0x01 */
    mov #0x66, r2
    add #0x1, r3               /* r3 = 0xFFFFFE15 (OCRA low byte) */
    mov #0x0, r4
    mov.b r2, @r3              /* OCRA low = 0x66 → OCRA = 0x0166 (358 cycles) */
    add #-0x3, r3              /* r3 = 0xFFFFFE12 (FRC high byte) */
    mov.b r4, @r3              /* FRC high = 0 */
    add #0x1, r3               /* r3 = 0xFFFFFE13 (FRC low byte) */
    lds.l @r15+, pr
    rts
    mov.b r4, @r3              /* FRC low = 0 (reset counter) */

/* vdp_init_dispatch() — Install SCU interrupt vectors for VDP handlers.
 * Registers VBlank-IN, VBlank-OUT, and Sprite-Draw-End handlers via the
 * SCU vector setup function.
 *
 * Vector assignments:
 *   Vector 4 (0x04)  = sym_06028218 (VBlank-IN handler)
 *   Vector 6 (0x06)  = sym_06028230 (VBlank-OUT handler)
 *   Vector 9 (0x09)  = sym_06028248 (Sprite-Draw-End handler)
 *   Vector 0x104-0x109 = same handlers (secondary SH-2 vectors)
 */
    .global vdp_init_dispatch
    .type vdp_init_dispatch, @function
vdp_init_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_vector_setup, r14 /* r14 = vector setup function ptr */

    /* Primary SH-2 vectors */
    mov.l   .L_fn_vblank_in, r5
    mov.l @r14, r3
    jsr @r3                    /* install VBlank-IN handler (vector 4) */
    mov #0x4, r4
    mov.l @r14, r2
    mov.l   .L_fn_vblank_out, r5
    jsr @r2                    /* install VBlank-OUT handler (vector 6) */
    mov #0x6, r4
    mov.l @r14, r3
    mov.l   .L_fn_sprite_end, r5
    jsr @r3                    /* install Sprite-Draw-End handler (vector 9) */
    mov #0x9, r4

    /* Secondary SH-2 vectors (vector + 0x100) */
    mov.l @r14, r2
    mov.l   .L_fn_vblank_in, r5
    mov.w   .L_vec_vbi_secondary, r4
    jsr @r2                    /* install secondary VBlank-IN (vector 0x104) */
    nop
    mov.l @r14, r3
    mov.l   .L_fn_vblank_out, r5
    mov.w   .L_vec_vbo_secondary, r4
    jsr @r3                    /* install secondary VBlank-OUT (vector 0x106) */
    nop
    mov.l @r14, r2
    mov.l   .L_fn_sprite_end, r5
    mov.w   .L_vec_sde_secondary, r4
    lds.l @r15+, pr
    jmp @r2                    /* tail-call: install secondary Sprite-End (0x109) */
    mov.l @r15+, r14

    /* === Word pool: FRT registers (sign-extend to 0xFFFFFExx) === */
.L_frt_tier:
    .2byte  0xFE10             /* -> 0xFFFFFE10: FRT TIER (Timer Interrupt Enable) */
.L_frt_ftcsr:
    .2byte  0xFE11             /* -> 0xFFFFFE11: FRT FTCSR (Timer Status/Control) */
.L_frt_tcr:
    .2byte  0xFE16             /* -> 0xFFFFFE16: FRT TCR (Timer Control) */
.L_frt_ocra:
    .2byte  0xFE14             /* -> 0xFFFFFE14: FRT OCRA (Output Compare A) */
.L_vec_vbi_secondary:
    .2byte  0x0104             /* vector 0x104 = secondary SH-2 VBlank-IN */
.L_vec_vbo_secondary:
    .2byte  0x0106             /* vector 0x106 = secondary SH-2 VBlank-OUT */
.L_vec_sde_secondary:
    .2byte  0x0109             /* vector 0x109 = secondary SH-2 Sprite-End */

    /* === Constant pool: vector setup === */
.L_fn_vector_setup:
    .4byte  sym_06000310       /* SCU interrupt vector setup function ptr */
.L_fn_frt_handler:
    .4byte  sym_060072E4       /* FRT compare-match interrupt handler */
.L_fn_vblank_in:
    .4byte  sym_06028218       /* VBlank-IN handler */
.L_fn_vblank_out:
    .4byte  sym_06028230       /* VBlank-OUT handler */
.L_fn_sprite_end:
    .4byte  sym_06028248       /* Sprite-Draw-End handler */
