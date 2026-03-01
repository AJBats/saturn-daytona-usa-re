
    .section .text.FUN_06011310


    .global position_ranking_display
    .type position_ranking_display, @function
position_ranking_display:
    mov.l r14, @-r15
    mov #0x3, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_mode_config_flags, r5
    mov.l   .L_game_mode_byte, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0xB, r0
    bf/s    .L_not_mode_b
    mov r4, r12
    mov.l @r5, r0
    tst #0x1, r0
    bt      .L_mode_b_use_4
    bra     .L_elem_count_set
    mov r12, r11
.L_mode_b_use_4:
    bra     .L_elem_count_set
    mov #0x4, r11
.L_not_mode_b:
    mov #0x2, r3
    mov.l @r5, r11
    and r4, r11
    cmp/ge r3, r11
    bt      .L_elem_count_4
    bra     .L_elem_count_set
    mov r12, r11
.L_elem_count_4:
    mov #0x4, r11
.L_elem_count_set:
    mov.l   .L_transition_state, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_no_transition
    bra     .L_begin_draw_group1
    mov.l r12, @r15
.L_no_transition:
    mov.l r11, @r15
.L_begin_draw_group1:
    mov.l   .L_fn_draw_elem, r13
    mov.l   .L_disp_struct, r14
    mov.l @r15, r9
    mov.w   .L_vdp1_cmd_offset_a, r6
    mov.l   .L_sprite_position_a, r5
    mov.l @(4, r14), r7
    shll8 r9
    shll2 r9
    shll2 r9
    add r9, r7
    jsr @r13
    mov #0x4, r4
    mov.l   .L_trans_type_flag, r10
    mov.l @(4, r14), r7
    mov.w   DAT_060113b4, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_use_inactive_sprite_a
    add r9, r7
    mov.l   .L_sprite_active_a, r5
    bra     .L_draw_elem_2
    nop
.L_use_inactive_sprite_a:
    mov.l   .L_sprite_inactive_a, r5
.L_draw_elem_2:
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r14), r7
    mov.w   .L_vdp1_cmd_offset_c, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_use_inactive_sprite_b
    add r9, r7
    mov.l   .L_sprite_active_b, r5
    bra     .L_draw_elem_3
    nop
.L_use_inactive_sprite_b:
    mov.l   .L_sprite_inactive_b, r5
.L_draw_elem_3:
    jsr @r13
    mov #0x4, r4
    mov.l   .L_transition_state, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bt      .L_use_alt_elem_count
    bra     .L_begin_draw_group2
    mov.l r12, @r15
.L_vdp1_cmd_offset_a:
    .2byte  0x0288                          /* VDP1 cmd offset: position elem 1 */

    .global DAT_060113b4
DAT_060113b4:
    .2byte  0x051C                          /* VDP1 cmd offset: position elem 2 */
.L_vdp1_cmd_offset_c:
    .2byte  0x0518                          /* VDP1 cmd offset: position elem 3 */
.L_mode_config_flags:
    .4byte  sym_0607EBC8                    /* mode configuration flags (32-bit) */
.L_game_mode_byte:
    .4byte  sym_0607887F                    /* game mode byte (0xB = variant) */
.L_transition_state:
    .4byte  sym_0607EADC                    /* transition state (32-bit) */
.L_fn_draw_elem:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_disp_struct:
    .4byte  sym_06063828                    /* display structure (VDP1 base at +4) */
.L_sprite_position_a:
    .4byte  sym_0605A7FC                    /* position sprite data (group 1) */
.L_trans_type_flag:
    .4byte  sym_06078644                    /* transmission type flag (nonzero = AT) */
.L_sprite_active_a:
    .4byte  sym_0605A9B0                    /* active state sprite (AT, elem 2) */
.L_sprite_inactive_a:
    .4byte  sym_0605A9B8                    /* inactive state sprite (MT, elem 2) */
.L_sprite_active_b:
    .4byte  sym_0605A998                    /* active state sprite (AT, elem 3) */
.L_sprite_inactive_b:
    .4byte  sym_0605A978                    /* inactive state sprite (MT, elem 3) */
.L_use_alt_elem_count:
    mov.l r11, @r15
.L_begin_draw_group2:
    mov.l @r15, r12
    mov.l @(4, r14), r7
    mov.w   DAT_06011462, r6
    mov.l   .L_sprite_position_b, r5
    add #0x2, r12
    shll8 r12
    shll2 r12
    shll2 r12
    add r12, r7
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r14), r7
    mov.w   .L_vdp1_cmd_offset_e, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_use_inactive_sprite_c
    add r12, r7
    mov.l   .L_sprite_active_c, r5
    bra     .L_draw_elem_5
    nop
.L_use_inactive_sprite_c:
    mov.l   .L_sprite_inactive_c, r5
.L_draw_elem_5:
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r14), r7
    mov.w   DAT_06011466, r6
    mov.l @r10, r0
    tst r0, r0
    bt/s    .L_use_inactive_sprite_d
    add r12, r7
    mov.l   .L_sprite_active_d, r5
    bra     .L_draw_elem_6
    nop
.L_use_inactive_sprite_d:
    mov.l   .L_sprite_inactive_d, r5
.L_draw_elem_6:
    jsr @r13
    mov #0x4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0601143E
sym_0601143E:
    mov.l   .L_disp_struct_b, r7
    mov.l @(4, r7), r7
    mov.l   .L_offset_0xD000, r3
    add r3, r7
    mov #0xE, r6
    mov.l   .L_sprite_elem_14px, r5
    mov.l   .L_fn_draw_elem_b, r3
    jmp @r3
    mov #0x4, r4

    .global sym_06011450
sym_06011450:
    mov.l   .L_disp_struct_b, r7
    mov.l @(4, r7), r7
    mov.l   .L_mask_0xE000, r3
    add r3, r7
    mov #0x10, r6
    mov.l   .L_sprite_elem_16px, r5
    mov.l   .L_fn_draw_elem_b, r3
    jmp @r3
    mov #0x4, r4

    .global DAT_06011462
DAT_06011462:
    .2byte  0x02B6                          /* VDP1 cmd offset: position elem 4 */
.L_vdp1_cmd_offset_e:
    .2byte  0x054A                          /* VDP1 cmd offset: position elem 5 */

    .global DAT_06011466
DAT_06011466:
    .2byte  0x0546                          /* VDP1 cmd offset: position elem 6 */
.L_sprite_position_b:
    .4byte  sym_0605A8B6                    /* position sprite data (group 2) */
.L_sprite_active_c:
    .4byte  sym_0605A9B0                    /* active state sprite (AT, elem 5) */
.L_sprite_inactive_c:
    .4byte  sym_0605A9B8                    /* inactive state sprite (MT, elem 5) */
.L_sprite_active_d:
    .4byte  sym_0605A9A0                    /* active state sprite (AT, elem 6) */
.L_sprite_inactive_d:
    .4byte  sym_0605A980                    /* inactive state sprite (MT, elem 6) */
.L_disp_struct_b:
    .4byte  sym_06063828                    /* display structure (VDP1 base at +4) */
.L_offset_0xD000:
    .4byte  0x0000D000                      /* VDP1 display offset for 14px elem */
.L_sprite_elem_14px:
    .4byte  sym_0605A634                    /* sprite data for 14-pixel position icon */
.L_fn_draw_elem_b:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_mask_0xE000:
    .4byte  0x0000E000                      /* VDP1 display offset for 16px elem */
.L_sprite_elem_16px:
    .4byte  sym_0605A718                    /* sprite data for 16-pixel position icon */

    .global sym_06011494
sym_06011494:
    extu.w r4, r0
    mov #0x0, r2
    .byte   0xD1, 0x19    /* mov.l [transition_state_ptr], r1 */   ! r1 = &transition_state
    .byte   0xD3, 0x18    /* mov.l [ranking_config_table], r3 */   ! r3 = ranking_config_table base
    shll2 r0
    mov.l r2, @r1
    shll2 r0
    .byte   0xD1, 0x18    /* mov.l [active_display_slot], r1 */    ! r1 = &active_display_slot
    add r3, r0
    mov.l @r0, r2
    rts
    mov.l r2, @r1
