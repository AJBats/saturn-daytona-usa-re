
    .section .text.FUN_0600C74E


    .global ai_orchestrator
    .type ai_orchestrator, @function
ai_orchestrator:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDE, 0x1D    /* mov.l .L_pool_0600C7D0, r14 */ ! r14 = &car_state_ptr (sym_0607E940)
    .byte   0xDD, 0x1D    /* mov.l .L_pool_0600C7D4, r13 */  ! r13 = course/track data base (sym_06078680)

    .byte   0xB2, 0xF1    /* bsr 0x0600CD40 (external) */       ! call track_pos_query — find next waypoint
    mov.l @r14, r14

    .byte   0xB1, 0x9A    /* bsr 0x0600CA96 (external) */       ! call course_correct — smooth waypoint tracking
    mov r13, r4

    mov #0x2D, r3
    mov.w   DAT_0600c7be, r0
    mov.l @(r0, r14), r4
    cmp/gt r3, r4
    bf      .L_no_speed_zone
    mov #0x3C, r3
    cmp/ge r3, r4
    bt      .L_no_speed_zone
    mov.w   DAT_0600c7c0, r3
    mov.l r3, @(40, r14)
    bra     .L_after_speed
    nop

.L_no_speed_zone:
    mov r13, r5
    .byte   0xB0, 0xA6    /* bsr 0x0600C8CC (external) */       ! call ai_speed_trampoline — compute target speed
    mov r14, r4

.L_after_speed:
    mov.l @(40, r14), r2
    mov.l r2, @(32, r14)

    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_skip_speed_boost
    .byte   0xB0, 0xF1    /* bsr 0x0600C970 (external) */       ! call speed_boost_lookup — apply course-specific adjustment
    mov r14, r4

.L_skip_speed_boost:
    .byte   0xB0, 0xCB    /* bsr 0x0600C928 (external) */       ! call velocity_friction — apply aerodynamic drag
    mov r14, r4

    mov r13, r5
    .byte   0xB0, 0x1E    /* bsr 0x0600C7D4 (external) */       ! call heading_speed_damping
    mov r14, r4

    mov r15, r6
    mov r14, r5
    mov.l r6, @-r15
    add #0x10, r5
    mov.l r5, @-r15
    mov.l @(24, r14), r5
    .byte   0xD3, 0x07    /* mov.l .L_pool_0600C7C8, r3 */ ! r3 = coord_grid_pack (sym_06006838)
    jsr @r3
    mov.l @(16, r14), r4

    mov r0, r4
    mov.l @r15+, r5
    .byte   0xD3, 0x06    /* mov.l .L_pool_0600C7CC, r3 */ ! r3 = scene_render_alt
    jsr @r3
    mov.l @r15+, r6

    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600c7be
DAT_0600c7be:
    .2byte  0x01EC                         /* offset to track position index in AI state */

    .global DAT_0600c7c0
DAT_0600c7c0:
    .2byte  0x4000                         /* fixed override heading for speed zone */
    .2byte  0xFFFF                         /* alignment padding */
.L_pool_0600C7C8:
    .4byte  sym_06006838                   /* coord_grid_pack — terrain elevation query */
.L_pool_0600C7CC:
    .4byte  scene_render_alt               /* AI car sprite/render update */
.L_pool_0600C7D0:
    .4byte  sym_0607E940                   /* pointer to current AI car state struct */
.L_pool_0600C7D4:
    .4byte  sym_06078680                   /* course/track data base */
