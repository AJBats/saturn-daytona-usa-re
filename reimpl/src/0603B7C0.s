	.text
    .global sys_timer_config
sys_timer_config:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603B840, r10
    mov.l   .L_pool_0603B844, r11
    mov.w   DAT_0603b838, r12
    mov r4, r13
    bra     .L_0603B7FC
    mov #0x0, r14
.L_0603B7D8:
    mov.l @r13, r0
    tst r0, r0
    bf      .L_0603B7E8
    mov.l @(8, r13), r5
    jsr @r11
    mov r14, r4
    bra     .L_0603B7EE
    nop
.L_0603B7E8:
    mov.l @(8, r13), r5
    jsr @r10
    mov r14, r4
.L_0603B7EE:
    mov r0, r4
    and r12, r4
    tst r4, r4
    bt      .L_0603B7FA
    bra     .L_0603B802
    nop
.L_0603B7FA:
    add #0x1, r14
.L_0603B7FC:
    mov.l @(4, r13), r2
    cmp/ge r2, r14
    bf      .L_0603B7D8
.L_0603B802:
    mov.l @(4, r13), r2
    cmp/gt r2, r14
    bf      .L_0603B80C
    bra     .L_0603B810
    mov #0x0, r0
.L_0603B80C:
    mov r14, r0
    add #0x1, r0
.L_0603B810:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .short  0xE700
    .long  0xD6096462
    .long  0x9309343C
    .long  0xA0136573
    .long  0x9006004E
    .long  0x20088B0B
    .long  0xA0110009

    .global DAT_0603b838
DAT_0603b838:
    .short  0x0080

    .global DAT_0603b83a
DAT_0603b83a:
    .short  0x0C3C
    .long  0x00ECFFFF
.L_pool_0603B840:
    .long  sym_0603F216
.L_pool_0603B844:
    .long  sprite_batch_emit
    .long  sym_060A4D14
    .long  0x921E342C
    .long  0x75016362
    .long  0x62323523
    .long  0x8BE86262
    .long  0x63223530
    .long  0x8B01A003
    .long  0x6473E201
    .long  0x90110426
    .long  0x000B6043
    .long  0xE300900C
    .long  0x000B0436
    .long  0xD7066572
    .long  0x9308353C
    .long  0xA00DE600
    .long  0x35408B07
    .long  0xA00D0009

    .global DAT_0603b88c
DAT_0603b88c:
    .short  0x00F0

    .global DAT_0603b88e
DAT_0603b88e:
    .short  0x00EC
    .long  0x0C3CFFFF
    .long  sym_060A4D14
    .long  0x923F352C
    .long  0x76016372
    .long  0x62323623
    .long  0x8BEE6272
    .long  0x63223630
    .long  0x8B00E500
    .long  0x000B6053
