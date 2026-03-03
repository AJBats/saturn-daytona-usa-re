	.text
    .global course_data_loader
course_data_loader:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601B5F8, r14
    mov.l   .L_0601B5FC, r5
    mov.l   .L_0601B600, r4
    jsr @r14
    mov #0x60, r6
    mov.l   .L_0601B604, r5
    mov.l   .L_0601B608, r4
    jsr @r14
    mov #0x20, r6
    mov.l   .L_0601B60C, r5
    mov.l   .L_0601B610, r4
    jsr @r14
    mov #0x20, r6
    mov.w   .L_0601B5F4, r6
    mov.l   .L_0601B614, r5
    mov.l   .L_0601B618, r4
    mov.l   .L_0601B61C, r3
    jsr @r3
    nop
    mov.l   .L_0601B620, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0601B624, r3
    jsr @r3
    nop
    mov.l   .L_0601B628, r2
    mov #0x16, r6
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_0601B62C, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_0601B630, r3
    jsr @r3
    mov #0x8, r4
    mov #0x0, r6
    mov.l   .L_0601B634, r5
    mov.l   .L_0601B638, r4
    mov.b @r5, r5
    .byte   0xB2, 0x38    /* bsr 0x0601BA50 (external) */
    mov.b @r4, r4
    mov #0x0, r2
    mov.l   .L_0601B63C, r3
    mov.b r2, @r3
    mov #0x4, r2
    mov.l   .L_0601B640, r3
    mov.b r2, @r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601B5F4:
    .short  0x0180
    .short  0xFFFF
.L_0601B5F8:
    .long  memcpy_word_idx
.L_0601B5FC:
    .long  sym_0604866C
.L_0601B600:
    .long  0x25F006C0
.L_0601B604:
    .long  sym_0604862C
.L_0601B608:
    .long  0x25F00720
.L_0601B60C:
    .long  sym_060485EC
.L_0601B610:
    .long  0x25F00740
.L_0601B614:
    .long  sym_0604996C
.L_0601B618:
    .long  0x25F00000
.L_0601B61C:
    .long  dma_transfer
.L_0601B620:
    .long  sym_0602853E
.L_0601B624:
    .long  sym_06028560
.L_0601B628:
    .long  sym_060638C8
.L_0601B62C:
    .long  0x0000C000
.L_0601B630:
    .long  sym_06028400
.L_0601B634:
    .long  sym_0605D4F5
.L_0601B638:
    .long  sym_0605D4F4
.L_0601B63C:
    .long  sym_0605D4FA
.L_0601B640:
    .long  sym_0608600D
