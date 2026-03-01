
    .section .text.FUN_06011094


    .global hud_course_render
    .type hud_course_render, @function
hud_course_render:
    mov.l r14, @-r15
    mov #0x3, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_mode_config_flags, r5
    mov.l   .L_game_mode_byte, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x3, r0
    bf/s    .L_not_race_mode
    mov r4, r14
    mov.l @r5, r0
    tst #0x1, r0
    bt      .L_race_mode_use_4
    bra     .L_elem_count_chosen
    mov r14, r12
.L_race_mode_use_4:
    bra     .L_elem_count_chosen
    mov #0x4, r12
.L_not_race_mode:
    mov.l @r5, r12
    mov #0x2, r3
    and r4, r12
    cmp/ge r3, r12
    bt      .L_generic_use_4
    bra     .L_elem_count_chosen
    mov r14, r12
.L_generic_use_4:
    mov #0x4, r12
.L_elem_count_chosen:
    mov.l   .L_display_struct, r4
    mov.w   .L_struct_offset_a, r0
    mov.l   .L_transition_state, r9
    mov.l @(r0, r4), r11
    add #0x10, r0
    mov.l @(r0, r4), r10
    mov.l @r9, r0
    tst r0, r0
    bt      .L_no_transition_g1
    bra     .L_begin_group1
    mov.l r14, @r15
.L_no_transition_g1:
    mov.l r12, @r15
.L_begin_group1:
    mov.l   .L_fn_hud_elem_draw, r13
    mov.l @r15, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.l r7, @(4, r15)
    add r11, r7
    mov.w   .L_vdp1_cmd_offset_1a, r6
    mov.l   .L_course_type_a, r0
    mov.l   .L_sprite_table_a, r3
    mov.l @r0, r0
    shll2 r0
    mov.l r3, @(12, r15)
    mov.l @(r0, r3), r5
    jsr @r13
    mov #0x4, r4
    mov.l   .L_course_type_b, r8
    mov.l @(4, r15), r7
    mov.w   .L_vdp1_cmd_offset_1b, r6
    mov.l   .L_sprite_table_c, r3
    mov.l @r8, r0
    add r10, r7
    shll2 r0
    mov.l r3, @r15
    mov.l @(r0, r3), r5
    jsr @r13
    mov #0x8, r4
    mov.l @r9, r0
    cmp/eq #0x1, r0
    bt      .L_use_alt_count_g2
    bra     .L_begin_group2
    mov.l r14, @(4, r15)

    .global DAT_0601112c
.L_struct_offset_a:
DAT_0601112c:
    .2byte  0x00D4                          /* display struct offset for VDP1 base A */
.L_vdp1_cmd_offset_1a:
    .2byte  0x0282                          /* VDP1 cmd offset: group 1 element A */
.L_vdp1_cmd_offset_1b:
    .2byte  0x048C                          /* VDP1 cmd offset: group 1 element B */
    .2byte  0xFFFF                          /* padding */
.L_mode_config_flags:
    .4byte  sym_0607EBC8                    /* mode configuration flags (32-bit) */
.L_game_mode_byte:
    .4byte  sym_0607887F                    /* game mode byte (0x3 = race) */
.L_display_struct:
    .4byte  sym_06063750                    /* display/object table base struct */
.L_transition_state:
    .4byte  sym_0607EADC                    /* transition state (32-bit) */
.L_fn_hud_elem_draw:
    .4byte  sym_06028400                    /* HUD element draw function */
.L_course_type_a:
    .4byte  sym_06078644                    /* course type index A (dword) */
.L_sprite_table_a:
    .4byte  sym_0605AC70                    /* course sprite table A (9 entries, 3 per course) */
.L_course_type_b:
    .4byte  sym_0605AD00                    /* course type index B (dword) */
.L_sprite_table_c:
    .4byte  sym_0605AB98                    /* course sprite table C (indexed by course_type) */
.L_use_alt_count_g2:
    mov.l r12, @(4, r15)
.L_begin_group2:
    mov.l @(4, r15), r7
    add #0x2, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.l r7, @(8, r15)
    add r11, r7
    .byte   0x96, 0x4D    /* mov.w .L_vdp1_cmd_offset_2a, r6 */   ! r6 = VDP1 cmd offset, group 2 elem A
    .byte   0xD5, 0x29    /* mov.l .L_pool_sprite_table_a_2, r5 */  ! r5 = &course_sprite_table_a
    mov.l @(12, r15), r3
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @(12, r5), r5
    jsr @r13
    mov #0x4, r4
    mov.l @(8, r15), r7
    .byte   0x96, 0x44    /* mov.w .L_vdp1_cmd_offset_2b, r6 */   ! r6 = VDP1 cmd offset, group 2 elem B
    mov.l @r8, r5
    mov.l @r15, r3
    add r10, r7
    shll2 r5
    add r3, r5
    mov.l @(12, r5), r5
    jsr @r13
    mov #0x8, r4
    mov.l @r9, r0
    cmp/eq #0x2, r0
    bt      .L_use_alt_count_g3
    bra     .L_begin_group3
    mov.l r14, @(8, r15)
.L_use_alt_count_g3:
    mov.l r12, @(8, r15)
.L_begin_group3:
    mov.l @(8, r15), r7
    add #0x4, r7
    shll8 r7
    shll2 r7
    shll2 r7
    mov.l r7, @(4, r15)
    add r11, r7
    .byte   0x96, 0x2F    /* mov.w .L_vdp1_cmd_offset_3a, r6 */   ! r6 = VDP1 cmd offset, group 3 elem A
    .byte   0xD5, 0x19    /* mov.l .L_pool_sprite_table_a_3, r5 */  ! r5 = &course_sprite_table_a
    mov.l @(12, r15), r3
    mov.l @r5, r5
    shll2 r5
    add r3, r5
    mov.l @(24, r5), r5
    jsr @r13
    mov #0x4, r4
    mov.l @(4, r15), r7
    .byte   0x96, 0x26    /* mov.w .L_vdp1_cmd_offset_3b, r6 */   ! r6 = VDP1 cmd offset, group 3 elem B
    mov.l @r8, r5
    mov.l @r15, r3
    add r10, r7
    shll2 r5
    add r3, r5
    mov.l @(24, r5), r5
    jsr @r13
    mov #0x8, r4
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
