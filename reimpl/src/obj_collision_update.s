
    .section .text.FUN_06020C3C


    .global obj_collision_update
    .type obj_collision_update, @function
obj_collision_update:
    sts.l pr, @-r15
    add #-0x20, r15
    mov r15, r1
    mov.l   .L_pool_cmd_template_a, r2
    mov.l   .L_pool_memcpy_byte, r3
    add #0x10, r1
    jsr @r3
    mov #0x10, r0
    mov r15, r1
    mov.l   .L_pool_cmd_template_b, r2
    mov.l   .L_pool_memcpy_byte, r3
    jsr @r3
    mov #0x10, r0
    mov.l   .L_pool_cmd_ready_flag, r7
    mov.l   .L_pool_cmd_list_base, r6
    mov.l   .L_pool_pipe_buf_1, r5
    mov #0x1, r4
    mov.l   .L_pool_display_timer, r0
    mov.w @r0, r0
    bra     .L_dispatch_timer
    extu.w r0, r0
.L_case_timer_1:
    mov #0xF, r3
    extu.w r4, r4
    mov.l   .L_pool_vdp2_ctrl_ch32, r0
    mov.w r0, @(10, r5)
    mov #0x20, r0
    mov.w r3, @(r0, r6)
    mov.w r4, @r7
    mov r15, r4
    mov.l   .L_pool_vdp1_cmd_copy, r3
    jsr @r3
    add #0x10, r4
    bra     .L_epilogue
    nop
.L_case_timer_2:
    mov.l   .L_pool_vdp2_ctrl_ch8, r0
    mov #0xF, r3
    extu.w r4, r4
    mov.w r0, @(10, r5)
    mov #0x20, r0
    mov.w r3, @(r0, r6)
    mov.w r4, @r7
    mov.l   .L_pool_vdp1_cmd_copy, r3
    jsr @r3
    mov r15, r4
    bra     .L_epilogue
    nop
.L_case_timer_3:
    .byte   0xBE, 0x55    /* bsr 0x06020946 (external) */
    nop
    bra     .L_epilogue
    nop
.L_case_timer_4:
    mov.l   .L_pool_display_layer_cfg, r3
    jsr @r3
    mov #0x4, r4
    bra     .L_epilogue
    nop
.L_dispatch_timer:
    cmp/eq #0x1, r0
    bt      .L_case_timer_1
    cmp/eq #0x2, r0
    bt      .L_case_timer_2
    cmp/eq #0x3, r0
    bt      .L_case_timer_3
    cmp/eq #0x4, r0
    bt      .L_case_timer_4
.L_epilogue:
    mov #0x0, r2
    mov.l   .L_pool_display_timer, r3
    add #0x20, r15
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_pool_cmd_template_a:
    .4byte  sym_0605F588
.L_pool_memcpy_byte:
    .4byte  sym_06035228
.L_pool_cmd_template_b:
    .4byte  sym_0605F598
.L_pool_cmd_ready_flag:
    .4byte  sym_060635AC
.L_pool_cmd_list_base:
    .4byte  sym_060A3D88
.L_pool_pipe_buf_1:
    .4byte  sym_060A3DB0
.L_pool_display_timer:
    .4byte  sym_0608780C
.L_pool_vdp2_ctrl_ch32:
    .4byte  0x0000C060
.L_pool_vdp1_cmd_copy:
    .4byte  sym_06038044
.L_pool_vdp2_ctrl_ch8:
    .4byte  0x0000C044
.L_pool_display_layer_cfg:
    .4byte  sym_0602853E
