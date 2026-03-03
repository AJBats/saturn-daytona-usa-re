	.text
    .global save_checksum_calc
save_checksum_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r13
    mov.l   .L_pool_0603B988, r14
    mov.w   .L_wpool_0603B986, r3
    mov.l @r14, r14
    add r3, r14
    tst r13, r13
    bt.s    .L_0603B960
    mov.l r4, @(8, r14)
    mov.l @r14, r0
    tst r0, r0
    bt      .L_0603B960
    mov r13, r5
    mov.l @r14, r3
    jsr @r3
    mov.l @(4, r14), r4
.L_0603B960:
    mov r13, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .short  0xD607
    .long  0x66627634
    .long  0xA00DE500
    .long  0x62536363
    .long  0x4208323C
    .long  0x62223420
    .long  0x8B04A008
    .short  0x0009
.L_wpool_0603B986:
    .short  0x00B8
.L_pool_0603B988:
    .long  sym_060A4D14
    .long  0x7501E060
    .long  0x026E3523
    .long  0x8BEEE060
    .long  0x026E3520
    .long  0x8B00E5FF
    .long  0x000B6053
