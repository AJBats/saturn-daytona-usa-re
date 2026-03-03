	.text
    .global particle_sys_mgr
particle_sys_mgr:
    sts.l pr, @-r15
    mov r6, r14
    mulu r6, r4
    mov r5, r13
    mov.w   .L_06028610, r6
    add #0xA, r5
    sts macl, r7
    shlr16 r7
    add r4, r7
    .byte   0xBE, 0xDD    /* bsr 0x06028368 (external) */
    mov #0x8, r4
    shlr16 r14
    exts.w r14, r7
    mov r13, r5
    .byte   0xBE, 0xD8    /* bsr 0x06028368 (external) */
    mov #0x8, r4
    mov.l   .L_060285DC, r5
    mov #0x2E, r0
    mov.l @(8, r5), r2
    or r6, r0
    mov.l @r2, r2
    tst r12, r12
    lds.l @r15+, pr
    add r13, r2
    mov.w r0, @(14, r2)
    bf.s    .L_060285D4
    mov.l @r15+, r12
    mov #0x2D, r1
    or r6, r1
    mov.w r1, @r2
.L_060285D4:
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .short  0x2710
.L_060285DC:
    .long  sym_06028614
    .long  0x45186763
    .long  0x96144509
    .long  0x354C4500
    .long  0xAEE4E408
    .long  0x45186763
    .long  0x960C4509
    .long  0x354C4500
    .long  0xAEC2E408
    .long  0x45186763
    .long  0x96044509
    .long  0x354C4500
    .long  0xAEE8E408
.L_06028610:
    .short  0xF000
    .short  0x0009

    .global sym_06028614
sym_06028614:
    .long  sym_06061294
    .long  sym_06061298
    .long  sym_0606129C
    .long  sym_060612A0
    .long  loc_060612A4
    .long  loc_060612A8

    .global sym_0602862C
sym_0602862C:
    .long  sym_060612AC
    .long  sym_060612B0
    .long  sym_060612B4
    .long  sym_060612B8
    .long  loc_060612BC
    .long  loc_060612C0

    .global sym_06028644
sym_06028644:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0000
    .word 0x0020
    .word 0x0020
    .word 0x0020
    .word 0x0020
