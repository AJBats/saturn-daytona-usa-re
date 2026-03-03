
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
    .byte   0xA0, 0x13    /* bra 0x0603836C (external */
    lds.l @r15+, pr
    .2byte  0xFFFF
.L_pool_06038348:
    .4byte  sym_06038F34
.L_pool_0603834C:
    .4byte  sym_060A4C60
.L_pool_06038350:
    .4byte  sym_060A4C68
.L_pool_06038354:
    .4byte  sym_060A4C78
.L_pool_06038358:
    .4byte  sym_060A4C40
.L_pool_0603835C:
    .4byte  sym_060A4C54
.L_pool_06038360:
    .4byte  sym_060A4C44
.L_pool_06038364:
    .4byte  sym_060A4C4C
.L_pool_06038368:
    .4byte  display_init_chain
