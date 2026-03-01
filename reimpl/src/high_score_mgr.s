
    .section .text.FUN_0603C10C


    .global high_score_mgr
    .type high_score_mgr, @function
high_score_mgr:
    sts.l pr, @-r15
    mov.l   .L_pool_0603C17C, r12
    .byte   0xB6, 0x24    /* bsr 0x0603CD5C */
    mov #0x0, r14
    mov.l   .L_pool_0603C180, r3
    jsr @r3
    nop
    mov.l   .L_pool_0603C184, r3
    jsr @r3
    nop
    mov.l   .L_pool_0603C188, r3
    jsr @r3
    nop
    mov.l   .L_pool_0603C18C, r3
    jsr @r3
    nop
    mov.l   .L_pool_0603C190, r3
    jsr @r3
    nop
    extu.b r14, r4
.L_clear_loop:
    extu.b r4, r0
    shll2 r0
    add #0x1, r4
    extu.b r4, r3
    cmp/ge r13, r3
    bf/s    .L_clear_loop
    mov.l r14, @(r0, r12)
    mov #0x0, r2
    mov.l   .L_pool_0603C194, r3
    mov.l r2, @r3
    mov.l   .L_pool_0603C198, r2
    mov.b r14, @r2
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0603C156
sym_0603C156:
    mov.l   .L_pool_0603C19C, r0
    mov.w   .L_wpool_0603C17A, r3
    mov.w @r0, r0
    extu.w r0, r0
    and r3, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    rts
    shar r0
.L_wpool_0603C17A:
    .2byte  0x3000
.L_pool_0603C17C:
    .4byte  sym_060A4D60
.L_pool_0603C180:
    .4byte  render_credits_stub
.L_pool_0603C184:
    .4byte  bus_lock_table_ctrl
.L_pool_0603C188:
    .4byte  display_nop_stub_a
.L_pool_0603C18C:
    .4byte  display_nop_stub_b
.L_pool_0603C190:
    .4byte  display_element_draw
.L_pool_0603C194:
    .4byte  sym_060A4D80
.L_pool_0603C198:
    .4byte  sym_060A4DA6
.L_pool_0603C19C:
    .4byte  sym_060A3D96
    .4byte  0xE300D227
    .4byte  0x000B2230
