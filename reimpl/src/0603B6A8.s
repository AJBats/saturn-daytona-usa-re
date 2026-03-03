	.text
    .global menu_ranking_display
menu_ranking_display:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r5, @r15
    mov.l   .L_pool_0603B724, r14
    mov.w   .L_wpool_0603B71C, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0603B6CA
    cmp/pz r4
    bf      .L_0603B6CA
    mov.l @r14, r2
    mov.w   .L_wpool_0603B71E, r0
    mov.l @(r0, r2), r3
    cmp/ge r3, r4
    bf      .L_0603B6D4
.L_0603B6CA:
    mov #-0xA, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0603B6D4:
    mov.l @r14, r0
    mov.w   .L_wpool_0603B720, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_0603B6F6
    mov.l @r14, r5
    mov.w   .L_wpool_0603B71C, r0
    mov.l   .L_pool_0603B728, r3
    jsr @r3
    mov.l @(r0, r5), r5
    mov r0, r5
    mov #0xC, r6
    mov.l   .L_pool_0603B72C, r3
    jsr @r3
    mov.l @r15, r4
    bra     .L_0603B70A
    nop
.L_0603B6F6:
    mov.l @r14, r5
    mov.w   .L_wpool_0603B71C, r0
    mov.l   .L_pool_0603B730, r3
    jsr @r3
    mov.l @(r0, r5), r5
    mov r0, r5
    mov #0xC, r6
    mov.l   .L_pool_0603B72C, r3
    jsr @r3
    mov.l @r15, r4
.L_0603B70A:
    mov #0x0, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xA1, 0x14    /* bra 0x0603B93C (external) */
    mov.l @r15+, r14
    .long  0x7F044F26
    .long  0x000B6EF6
.L_wpool_0603B71C:
    .short  0x00A0
.L_wpool_0603B71E:
    .short  0x00A4
.L_wpool_0603B720:
    .short  0x0098
    .short  0xFFFF
.L_pool_0603B724:
    .long  sym_060A4D14
.L_pool_0603B728:
    .long  sym_0603F1F0
.L_pool_0603B72C:
    .long  sym_060360FC
.L_pool_0603B730:
    .long  sym_0603F1E0
    .long  0xD41DD31E
    .long  0x64427404
    .long  0x2432D21D
    .long  0x1421D31D
    .long  0x1432D21D
    .long  0x000B1423
