	.text
    .global transition_medium_b
transition_medium_b:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0600FE98, r4
    mov.l @r4, r3
    add #-0x1, r3
    mov.l r3, @r4
    mov.w   .L_wpool_0600FE92, r2
    cmp/eq r2, r3
    bf      .L_0600FE74
    mov.l   .L_pool_0600FE9C, r2
    mov.l r2, @r15
    mov.l   .L_pool_0600FEA0, r4
    mov.l   .L_pool_0600FEA4, r3
    jsr @r3
    mov r2, r5
    mov.l   .L_pool_0600FEA8, r7
    mov #0x0, r6
    mov.l @r15, r5
    mov.l   .L_pool_0600FEAC, r3
    mov.l @(4, r7), r7
    add r3, r7
    mov.l   .L_pool_0600FEB0, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r2
    mov.l   .L_pool_0600FEB4, r3
    mov.l r2, @r3
    mov #0x10, r2
    mov.l   .L_pool_0600FEB8, r3
    mov.b r2, @r3
.L_0600FE74:
    mov.l   .L_pool_0600FEBC, r7
    mov.w   .L_wpool_0600FE94, r6
    mov.w   .L_wpool_0600FE96, r5
    mov.l   .L_pool_0600FEC0, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0600FEC4, r4
    mov.l   .L_pool_0600FEC8, r3
    jsr @r3
    nop
    mov.l   .L_0600FECC, r4
    add #0x4, r15
    mov.l   .L_pool_0600FEC8, r3
    jmp @r3
    lds.l @r15+, pr
.L_wpool_0600FE92:
    .short  0x00AB
.L_wpool_0600FE94:
    .short  0x0090
.L_wpool_0600FE96:
    .short  0x07A2
.L_pool_0600FE98:
    .long  sym_0607EBCC
.L_pool_0600FE9C:
    .long  sym_06094FA8
.L_pool_0600FEA0:
    .long  sym_060EFB24
.L_pool_0600FEA4:
    .long  dma_memory_transfer
.L_pool_0600FEA8:
    .long  sym_06063838
.L_pool_0600FEAC:
    .long  0x00009000
.L_pool_0600FEB0:
    .long  sym_06028400
.L_pool_0600FEB4:
    .long  sym_06078864
.L_pool_0600FEB8:
    .long  sym_0607887F
.L_pool_0600FEBC:
    .long  sym_0605ACE4
.L_pool_0600FEC0:
    .long  sym_060284AE
.L_0600FEC4:
    .long  0x25F001E0
.L_pool_0600FEC8:
    .long  sym_06011F1C
.L_0600FECC:
    .long  0x25F00520
