
    .section .text.FUN_06028580


    .global FUN_06028580
    .type FUN_06028580, @function
FUN_06028580:
    mov.l r14, @-r15
    shll8 r5
    shlr2 r5
    add r4, r5
    mov.l r13, @-r15
    shll r5
    .byte   0x94, 0x25    /* mov.w .L_wpool_060285DA, r4 */
    cmp/pz r6
    mov.l r12, @-r15
    .byte   0x8D, 0x01    /* bt/s 0x06028598 (external) */
    .word 0x0C29
    neg r6, r6


    .global FUN_06028598
    .type FUN_06028598, @function
FUN_06028598:
    sts.l pr, @-r15
    mov r6, r14
    mulu.w r6, r4
    mov r5, r13
    mov.w   .L_06028610, r6
    add #0xA, r5
    sts macl, r7
    shlr16 r7
    add r4, r7
    .reloc ., R_SH_IND12W, FUN_06028368 - 4
    .2byte 0xB000    /* bsr FUN_06028368 (linker-resolved) */
    mov #0x8, r4
    shlr16 r14
    exts.w r14, r7
    mov r13, r5
    .reloc ., R_SH_IND12W, FUN_06028368 - 4
    .2byte 0xB000    /* bsr FUN_06028368 (linker-resolved) */
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
    bf/s    .L_060285D4
    mov.l @r15+, r12
    mov #0x2D, r1
    or r6, r1
    mov.w r1, @r2
.L_060285D4:
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x2710
.L_060285DC:
    .4byte  sym_06028614
    .global FUN_060285E0
FUN_060285E0:
    .4byte  0x45186763
    .4byte  0x96144509
    .4byte  0x354C4500
    .4byte  0xAEE4E408
    .4byte  0x45186763
    .4byte  0x960C4509
    .4byte  0x354C4500
    .4byte  0xAEC2E408
    .global FUN_06028600
FUN_06028600:
    .4byte  0x45186763
    .4byte  0x96044509
    .4byte  0x354C4500
    .4byte  0xAEE8E408
.L_06028610:
    .2byte  0xF000
    .2byte  0x0009

    .global sym_06028614
sym_06028614:
    .4byte  sym_06061294
    .4byte  sym_06061298
    .4byte  sym_0606129C
    .4byte  sym_060612A0
    .4byte  FUN_06061258
    .4byte  FUN_0606125C

    .global sym_0602862C
sym_0602862C:
    .4byte  sym_060612AC
    .4byte  sym_060612B0
    .4byte  sym_060612B4
    .4byte  sym_060612B8
    .4byte  FUN_06061270
    .4byte  FUN_06061274

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
