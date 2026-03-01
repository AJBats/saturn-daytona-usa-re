
    .section .text.FUN_0600A4CA


    .global camera_scene_setup
    .type camera_scene_setup, @function
camera_scene_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov r4, r13
    .byte   0xD8, 0x15    /* mov.l .L_sprite_index_table, r8 — sprite index table base */
    .byte   0xD9, 0x17    /* mov.l .L_rot_chain_b_params, r9 — rotation chain B params */
    .byte   0xDA, 0x10    /* mov.l .L_fn_chain_b, r10 — transform chain B function */
    .byte   0xDB, 0x17    /* mov.l .L_rot_chain_a_params, r11 — rotation chain A params */
    .byte   0xDC, 0x0B    /* mov.l .L_fn_chain_a, r12 — transform chain A function */
    .byte   0xD0, 0x17    /* mov.l .L_race_end_state, r0 — &race_end_state */
    bra     .L_dispatch_state
    mov.l @r0, r0
.L_state_0:
    mov r13, r14
    .byte   0xD4, 0x16    /* mov.l .L_s0_chain_a_src, r4 — state 0 chain A source array */
    shll2 r14
    add r14, r11
    add r14, r4
    mov.l @r11, r5
    jsr @r12
    mov.l @r4, r4
    add r14, r9
    mov.l @r9, r6
    mov r8, r5
    add #0x54, r5
    .byte   0xD4, 0x11    /* mov.l .L_s0_chain_b_model, r4 — state 0 chain B model array */
    bra     .L_chain_b_call
    mov.w @r5, r5
    .2byte  0xFFFF
    .4byte  sym_060628C8
    .4byte  sym_06062874
.L_fn_chain_a:
    .4byte  sym_06031D8C
    .4byte  sym_0606291C
    .4byte  sym_06089E9E
    .4byte  sym_06062820
.L_fn_chain_b:
    .4byte  sym_06031A28
    .4byte  sym_060621DC
    .4byte  sym_06062130
    .4byte  sym_06062184
.L_sprite_index_table:
    .4byte  sym_06089E44
    .4byte  sym_060620DC
.L_rot_chain_b_params:
    .4byte  sym_060634DC
.L_rot_chain_a_params:
    .4byte  sym_060634F8
.L_race_end_state:
    .4byte  sym_0607EAD8
.L_s0_chain_a_src:
    .4byte  sym_06063488
.L_s0_chain_b_model:
    .4byte  sym_06063434
.L_state_1:
    mov r13, r14
    .byte   0xD4, 0x25    /* mov.l .L_s1_chain_a_src, r4 — state 1 chain A source array */
    shll2 r14
    add r14, r11
    add r14, r4
    mov.l @r11, r5
    jsr @r12
    mov.l @r4, r4
    add r14, r9
    mov.l @r9, r6
    mov r8, r5
    add #0x54, r5
    .byte   0xD4, 0x20    /* mov.l .L_s1_chain_b_model, r4 — state 1 chain B model array */
    bra     .L_chain_b_call
    mov.w @r5, r5
.L_state_2:
    mov r13, r14
    .byte   0xD4, 0x1F    /* mov.l .L_s2_chain_a_src, r4 — state 2 chain A source array */
    shll2 r14
    add r14, r11
    add r14, r4
    mov.l @r11, r5
    jsr @r12
    mov.l @r4, r4
    add r14, r9
    mov.l @r9, r6
    mov r8, r5
    add #0x54, r5
    mov.w @r5, r5
    .byte   0xD4, 0x1A    /* mov.l .L_s2_chain_b_model, r4 — state 2 chain B model array */
.L_chain_b_call:
    add r14, r4
    jsr @r10
    mov.l @r4, r4
    bra     .L_epilogue
    nop
.L_dispatch_state:
    cmp/eq #0x0, r0
    bt      .L_state_0
    cmp/eq #0x1, r0
    bt      .L_state_1
    cmp/eq #0x2, r0
    bt      .L_state_2
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
