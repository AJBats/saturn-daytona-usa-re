
    .section .text.FUN_0603FD40


    .global dma_param_chain_init
    .type dma_param_chain_init, @function
dma_param_chain_init:
    mov.l r14, @-r15
    mov #0x64, r0
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov #0x1, r12
    mov.l r10, @-r15
    mov r6, r11
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x40, r15
    mov.l   .L_pool_palette_render_main, r9
    mov.l r5, @r15
    mov.l r7, @(4, r15)
    mov.l @(r0, r15), r10
    mov.l   .L_pool_disable_scroll, r3
    mov #0x68, r0
    mov.l @(r0, r15), r8
    jsr @r3
    mov r14, r4
    mov.l r13, @(52, r15)
    mov #0x7, r3
    mov r15, r4
    mov.l r12, @(56, r15)
    mov.l r3, @(60, r15)
    mov.l   .L_pool_color_palette_setup, r3
    jsr @r3
    add #0x34, r4
    mov.l @(4, r15), r2
    mov.l r2, @(12, r15)
    mov.l @r15, r3
    mov.l r3, @(16, r15)
    mov r8, r3
    shlr2 r3
    mov.l r3, @(8, r15)
    cmp/pl r11
    bf/s    .L_y_not_positive
    mov.l r3, @(20, r15)
    bra     .L_y_dir_done
    mov.l r12, @(24, r15)
.L_y_not_positive:
    cmp/pz r11
    bt      .L_y_dir_zero
    mov #0x2, r3
    mov.l r3, @(24, r15)
    bra     .L_y_dir_done
    nop
.L_y_dir_zero:
    mov.l r13, @(24, r15)
.L_y_dir_done:
    cmp/pl r10
    bf      .L_x_not_positive
    bra     .L_x_dir_done
    mov.l r12, @(28, r15)
.L_x_not_positive:
    cmp/pz r10
    bt      .L_x_dir_zero
    mov #0x2, r3
    mov.l r3, @(28, r15)
    bra     .L_x_dir_done
    nop
    .2byte  0xFFFF              /* alignment padding */
.L_pool_palette_render_main:
    .4byte  palette_render_main
.L_pool_disable_scroll:
    .4byte  sym_06042BBE
.L_pool_color_palette_setup:
    .4byte  sym_06042A8C
.L_x_dir_zero:
    mov.l r13, @(28, r15)
.L_x_dir_done:
    mov r14, r5
    mov r15, r4
    mov.w   .L_wpool_block_size, r3
    mov.l r3, @(32, r15)
    shlr2 r3
    mov.l r3, @(36, r15)
    mov.l r13, @(40, r15)
    mov.w   .L_wpool_scroll_flags, r3
    mov.l r3, @(48, r15)
    mov.l   .L_pool_palette_engine_core, r3
    jsr @r3
    add #0xC, r4
    mov.l   .L_pool_enable_scroll, r3
    jsr @r3
    mov r14, r4
.L_poll_render:
    jsr @r9
    mov r14, r4
    tst r0, r0
    bt      .L_poll_render
    mov #0x3, r4
    mov.l @(8, r15), r14
    mov.l @(4, r15), r3
    mov.l @r15, r2
    mul.l r14, r10
    sts macl, r6
    shll2 r6
    mul.l r14, r11
    add r3, r6
    sts macl, r5
    shll2 r5
    add r2, r5
    .byte   0xB0, 0xED    /* bsr 0x0603FFE6 (external) */
    and r8, r4
    mov r8, r5
    mov.l   .L_pool_mem_clear, r3
    jsr @r3
    mov.l @r15, r4
    add #0x40, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x000B              /* trailing data (rts encoding) */
    .2byte  0xE000              /* trailing data (mov #0, r0 encoding) */
.L_wpool_block_size:
    .2byte  0x0800
.L_wpool_scroll_flags:
    .2byte  0x017F
    .2byte  0xFFFF              /* alignment padding */
.L_pool_palette_engine_core:
    .4byte  palette_engine_core
.L_pool_enable_scroll:
    .4byte  sym_06042BAC
.L_pool_mem_clear:
    .4byte  sym_0603C05C

    .global loc_0603FE40
loc_0603FE40:
    rts
    mov #0x1, r0
