
    .section .text.FUN_06038300


    .global display_hw_init
    .type display_hw_init, @function
display_hw_init:
    sts.l pr, @-r15
    mov.l   .L_pool_06038348, r3
    jsr @r3
    nop
    mov.l   .L_pool_0603834C, r5
    mov #0x0, r4
    mov.l r4, @r5
    extu.w r4, r0
    extu.w r4, r3
    mov.l r4, @(4, r5)
    mov.l   .L_pool_06038350, r5
    mov.l r4, @r5
    mov.l r4, @(4, r5)
    mov.l   .L_pool_06038354, r5
    mov.l r4, @r5
    mov.l r4, @(4, r5)
    mov.l   .L_pool_06038358, r5
    mov.w r4, @r5
    mov.w r0, @(2, r5)
    extu.w r4, r0
    mov.l   .L_pool_0603835C, r5
    mov.w r3, @r5
    mov.w r0, @(2, r5)
    mov r4, r3
    mov.l   .L_pool_06038360, r5
    mov r3, r2
    mov.l r4, @r5
    mov.l r3, @(4, r5)
    mov.l   .L_pool_06038364, r5
    mov.l r2, @r5
    mov.l   .L_pool_06038368, r3
    jsr @r3
    mov.l r2, @(4, r5)
    .byte   0xA0, 0x13    /* bra 0x0603836C (external — vdp2_regs_setup) */
    lds.l @r15+, pr
    .2byte  0xFFFF              /* padding */
.L_pool_06038348:
    .4byte  sym_06038F34        /* display_param_reset function */
.L_pool_0603834C:
    .4byte  sym_060A4C60        /* view offset structure A (8 bytes) */
.L_pool_06038350:
    .4byte  sym_060A4C68        /* view offset structure B (8 bytes) */
.L_pool_06038354:
    .4byte  sym_060A4C78        /* color accumulator (8 bytes) */
.L_pool_06038358:
    .4byte  sym_060A4C40        /* scene pending flags (4 bytes, word pairs) */
.L_pool_0603835C:
    .4byte  sym_060A4C54        /* scene render state (4 bytes, word pairs) */
.L_pool_06038360:
    .4byte  sym_060A4C44        /* scene source A data (8 bytes) */
.L_pool_06038364:
    .4byte  sym_060A4C4C        /* scene dirty flags (8 bytes) */
.L_pool_06038368:
    .4byte  display_init_chain  /* display init chain function */
