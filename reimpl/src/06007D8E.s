	.text
    .global dma_queue_commit
dma_queue_commit:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x1, r12
    mov.w   .L_wpool_06007D9E, r13
    mov.w   .L_wpool_06007DA0, r14
    bra     .L_06007DCE
    mov #0x0, r4
.L_wpool_06007D9E:
    .short  0xFE11
.L_wpool_06007DA0:
    .short  0x0080
    .short  0xFFFF
    .long  sym_060281B8
    .long  sym_0606A4F8
    .long  0x00008000
    .long  sym_0608AC20
    .long  sym_06078624
    .long  sym_0603C000
    .long  sym_060280F8
    .long  sym_06078620
    .long  0x0000FFFF
    .long  0x21800000
.L_06007DCC:
    mov r12, r4
.L_06007DCE:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_06007DCC
    mov.b @r13, r0
    and #0xF, r0
    mov.b r0, @r13
    .byte   0xD5, 0x08    /* mov.l .L_pool_06007E02, r5 */
    tst r4, r4
    bt      .L_06007DEE
    mov.w @r5, r3
    add #-0xA, r3
    mov.w r3, @r5
    bra     .L_06007DF4
    nop
.L_06007DEE:
    mov.w @r5, r2
    add #0xA, r2
    mov.w r2, @r5
.L_06007DF4:
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x02    /* mov.l .L_pool_06007E06, r3 */
    jmp @r3
    mov.l @r15+, r14
    .short  0xFFFF
.L_pool_06007E02:
    .long  sym_0605A1C0
.L_pool_06007E06:
    .long  sym_0603C000
