	.text
    .global screen_flash_effect
screen_flash_effect:
    sts.l pr, @-r15
    mov.l   .L_pool_060283AC, r0
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r2, r5
    .byte   0xBF, 0x97    /* bsr 0x060282C0 (external) */
    mov r7, r4
    mov r0, r1
    mov #0x16, r7
    mov #0x0, r0
.L_06028398:
    mov.b @r1+, r3
    add r6, r3
    mov.w r3, @(r0, r5)
    cmp/eq r7, r0
    bf.s    .L_06028398
    add #0x2, r0
    lds.l @r15+, pr
    rts
    nop
    .short  0x0000
.L_pool_060283AC:
    .long  sym_06028614
    .long  0xA003E302
    .long  0xA001E306
    .long  0xE30ED008
    .long  0x024E6222
    .long  0x325CE50F
    .long  0x61736033
    .long  0x21594709
    .long  0x316C4709
    .long  0x02152338
    .long  0x8FF673FE
    .long  0x000B0009
    .long  sym_06028614

    .global sym_060283E0
sym_060283E0:
    mov.l   .L_pool_060283F8, r0
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r5, r2
.L_060283E8:
    mov.b @r7+, r3
    tst r3, r3
    bt      .L_060283FC
    add r6, r3
    mov.w r3, @r2
    bra     .L_060283E8
    add #0x2, r2
    .short  0x0000
.L_pool_060283F8:
    .long  sym_06028614
.L_060283FC:
    rts
    nop

    .global sym_06028400
sym_06028400:
    mov.l   .L_pool_0602842C, r0
    mov.l @(r0, r4), r4
    mov.l @r4, r4
    add r4, r6
    mov #-0x80, r4
    mov.w @r5+, r3
    mov.w @r5+, r2
    add r3, r4
    add r3, r4
    neg r4, r4
.L_06028414:
    mov r3, r1
.L_06028416:
    mov.w @r5+, r0
    add r7, r0
    mov.w r0, @r6
    dt r1
    bf.s    .L_06028416
    add #0x2, r6
    dt r2
    bf.s    .L_06028414
    add r4, r6
    rts
    nop
.L_pool_0602842C:
    .long  sym_06028614

    .global sym_06028430
sym_06028430:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
