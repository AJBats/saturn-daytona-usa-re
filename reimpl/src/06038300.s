	.text
    .global display_hw_init
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
    .short  0xFFFF
.L_pool_06038348:
    .long  sym_06038F34
.L_pool_0603834C:
    .long  sym_060A4C60
.L_pool_06038350:
    .long  sym_060A4C68
.L_pool_06038354:
    .long  sym_060A4C78
.L_pool_06038358:
    .long  sym_060A4C40
.L_pool_0603835C:
    .long  sym_060A4C54
.L_pool_06038360:
    .long  sym_060A4C44
.L_pool_06038364:
    .long  sym_060A4C4C
.L_pool_06038368:
    .long  display_init_chain
