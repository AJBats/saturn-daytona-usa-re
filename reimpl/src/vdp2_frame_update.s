
    .section .text.FUN_060171AC


    .global vdp2_frame_update
    .type vdp2_frame_update, @function
vdp2_frame_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_scroll_data_base, r11
    mov.l   .L_pool_vdp1_cmd_builder, r12
    mov.l   .L_pool_cmd_counter, r13
    mov.l   .L_pool_write_ptr, r14
    mov.l   .L_pool_game_state, r4
    mov.l @r4, r0
    cmp/eq #0x15, r0
    .word 0x0129
    cmp/eq #0x19, r0
    .word 0x0029
    or r1, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l   .L_pool_slot_flags, r5
    mov.b @r5, r3
    extu.b r3, r3
    tst r3, r3
    .word 0x0029
    xor #0x1, r0
    mov #0x1, r3
    add r5, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    .word 0x0129
    and r1, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l @r4, r0
    cmp/eq #0x19, r0
    bf      .L_standard_layers
    mov.l @r14, r5
    mov.w   DAT_0601729e, r4
    jsr @r12
    add r11, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
    mov r3, r5
    mov.w   .L_wpool_scroll_layer5_offset, r4
    jsr @r12
    add r11, r4
    mov r11, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov r3, r5
    mov.l r3, @r14
    jsr @r12
    add #0x78, r4
    mov r11, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov r3, r5
    mov.l r3, @r14
    jsr @r12
    add #0x60, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
.L_standard_layers:
    mov.l @r14, r5
    mov r11, r4
    jsr @r12
    add #0x48, r4
    mov.l @r13, r2
    mov r11, r4
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
    mov r3, r5
    jsr @r12
    add #0x30, r4
    mov.l @r13, r2
    mov r11, r4
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
    mov r3, r5
    jsr @r12
    add #0x18, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov r3, r5
    mov.l r3, @r14
    jsr @r12
    mov r11, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    mov.l @r14, r3
    add #0x20, r3
    mov.l r3, @r14
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601729e
DAT_0601729e:
    .2byte  0x00A8
.L_wpool_scroll_layer5_offset:
    .2byte  0x0090                      /* [HIGH] offset 0x90 into scroll data table (layer 5) */
    .2byte  0xFFFF
.L_pool_scroll_data_base:
    .4byte  sym_06085490
.L_pool_vdp1_cmd_builder:
    .4byte  sym_060280F8
.L_pool_cmd_counter:
    .4byte  sym_0605A008
.L_pool_write_ptr:
    .4byte  sym_060785FC
.L_pool_game_state:
    .4byte  g_game_state
.L_pool_slot_flags:
    .4byte  sym_06084FC8
