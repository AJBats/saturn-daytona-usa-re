
    .section .text.FUN_06027498


    .global FUN_06027498
    .type FUN_06027498, @function
FUN_06027498:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    bsr     .L_060274DA
    mov r4, r5
    .reloc ., R_SH_IND12W, FUN_06027476 - 4
    .2byte 0xB000    /* bsr FUN_06027476 (linker-resolved) */
    mov r0, r4
    cmp/pl r0
    bf      .L_060274D4
    mov.l   .L_060274F8, r4
    bsr     FUN_0602755C
    mov r0, r5
    mov.l @(0, r14), r1
    mov.l @(4, r14), r2
    dmuls.l r0, r1
    mov.l @(8, r14), r3
    sts mach, r4
    sts macl, r1
    xtrct r4, r1
    dmuls.l r0, r2
    mov.l r1, @(0, r14)
    sts mach, r4
    sts macl, r2
    xtrct r4, r2
    dmuls.l r0, r3
    mov.l r2, @(4, r14)
    sts mach, r4
    sts macl, r3
    xtrct r4, r3
    mov.l r3, @(8, r14)
.L_060274D4:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060274DA:
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    rts
    xtrct r1, r0
    .2byte  0x0009
    .4byte  0x002F2F20
    .4byte  0x002F0000
    .4byte  0x00008000
.L_060274F8:
    .4byte  0x00010000
    .4byte  0x40003FFC
    .4byte  0x0FFC4000
    .4byte  0x3FEB3FD6
    .4byte  0x3FBA3F97
    .4byte  0x3F6A3F2F
    .4byte  0x3EFB3EA4
    .4byte  0x3D7403E8
    .4byte  0x001E0028
    .4byte  0x00320046
    .4byte  0x00640096
    .4byte  0x00FA01F4
    .4byte  0x00000AC0
    .4byte  0x00001581
    .4byte  0x000047AE
    .4byte  0x0000B333
    .4byte  0x00018000
    .4byte  0x0002F333
    .4byte  0x00053333
    .4byte  0x0008B333
    .4byte  0x0015B6DB

    .global FUN_0602754C
FUN_0602754C:
    swap.w r4, r0
    rts
    exts.w r0, r0


    .global FUN_06027552
    .type FUN_06027552, @function
FUN_06027552:
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    rts
    xtrct r4, r0
    .global FUN_0602755C
FUN_0602755C:

    .global FUN_0602755C
FUN_0602755C:
    mov.w   .L_06027570, r2
    mov r4, r3
    mov.l r5, @(0, r2)
    shlr16 r3
    exts.w r3, r3
    mov.l r3, @(16, r2)
    shll16 r4
    mov.l r4, @(20, r2)
    rts
    mov.l @(28, r2), r0
.L_06027570:
    .2byte  0xFF00
    .2byte  0x0000

    .global FUN_06027574
FUN_06027574:
    cmp/eq r4, r5
    bt      .L_06027592
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_06027592
    cmp/hi r4, r5
    bt      .L_06027596
    add r6, r5
    add r6, r4
    add #-0x1, r5
.L_06027588:
    mov.b @r5, r7
    dt r6
    mov.b r7, @-r4
    bf/s    .L_06027588
    add #-0x1, r5
.L_06027592:
    rts
    nop
.L_06027596:
    mov.b @r5+, r7
    dt r6
    mov.b r7, @r4
    bf/s    .L_06027596
    add #0x1, r4
    rts
    nop

    .global FUN_060275A4
FUN_060275A4:
    cmp/eq r4, r5
    bt      .L_060275C6
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_060275C6
    mov r6, r7
    cmp/hi r4, r5
    bt/s    .L_060275CA
    shlr r6
    add r7, r5
    add r7, r4
    add #-0x4, r5
.L_060275BC:
    mov.w @r5, r7
    dt r6
    mov.w r7, @-r4
    bf/s    .L_060275BC
    add #-0x2, r5
.L_060275C6:
    rts
    nop
.L_060275CA:
    mov.w @r5+, r7
    dt r6
    mov.w r7, @r4
    bf/s    .L_060275CA
    add #0x2, r4
    rts
    nop

    .global FUN_060275D8
FUN_060275D8:
    cmp/eq r4, r5
    bt      .L_060275FA
    mov #0x0, r7
    cmp/eq r7, r6
    bt      .L_060275FA
    mov r6, r7
    cmp/hi r4, r5
    bt/s    .L_060275FE
    shlr2 r6
    add r7, r5
    add r7, r4
    add #-0x4, r5
.L_060275F0:
    mov.l @r5, r7
    dt r6
    mov.l r7, @-r4
    bf/s    .L_060275F0
    add #-0x4, r5
.L_060275FA:
    rts
    nop
.L_060275FE:
    mov.l @r5+, r7
    dt r6
    mov.l r7, @r4
    bf/s    .L_060275FE
    add #0x4, r4
    rts
    nop

    .global FUN_0602760C
FUN_0602760C:
    mov #0x0, r0
    add #-0x1, r6
.L_06027610:
    mov.b @(r0, r5), r1
    cmp/gt r0, r6
    mov.b r1, @(r0, r4)
    bt/s    .L_06027610
    add #0x1, r0
    rts
    add #0x1, r6

    .global FUN_0602761E
FUN_0602761E:
    mov #0x0, r0
    add #-0x2, r6
.L_06027622:
    mov.w @(r0, r5), r1
    cmp/gt r0, r6
    mov.w r1, @(r0, r4)
    bt/s    .L_06027622
    add #0x2, r0
    rts
    add #0x2, r6

    .global FUN_06027630
FUN_06027630:
    mov #0x0, r0
    add #-0x4, r6
.L_06027634:
    mov.l @(r0, r5), r1
    cmp/gt r0, r6
    mov.l r1, @(r0, r4)
    bt/s    .L_06027634
    add #0x4, r0
    rts
    add #0x4, r6

    .global FUN_06027642
FUN_06027642:
    mov.l @r5+, r0
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(0, r4)
    mov.l r1, @(4, r4)
    mov.l r2, @(8, r4)
    mov.l r3, @(12, r4)
    mov.l @r5+, r0
    mov.l @r5+, r1
    mov.l @r5+, r2
    mov.l @r5+, r3
    mov.l r0, @(16, r4)
    mov.l r1, @(20, r4)
    mov.l r2, @(24, r4)
    mov.l r3, @(28, r4)
    dt r6
    bf/s    FUN_06027642
    add #0x20, r4
    rts
    nop

    .global FUN_0602766C
FUN_0602766C:
    .byte   0xD0, 0x07
    mov.l @r0, r0
    .byte   0xD1, 0x07
    tst r1, r0
    bf      FUN_0602766C
    .byte   0xD1, 0x07
    mov.w   .L_0602768A, r2
    mov.l r4, @(4, r1)
    mov.l r5, @(0, r1)
    mov.l r6, @(8, r1)
    mov.l r2, @(12, r1)
    mov #0x7, r0
    mov.l r0, @(20, r1)
    rts
    mov.l r2, @(16, r1)
.L_0602768A:
    .2byte  0x0101
.L_0602768C:
    .4byte  0x25FE007C
.L_06027690:
    .4byte  0x0000272E
.L_06027694:
    .4byte  0x25FE0000
    .4byte  0x00090000

    .global FUN_0602769C
FUN_0602769C:
    mov.w   .L_060276C0, r1
    mov.w   .L_060276CA, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r0
    mov.l @r4, r2
    neg r0, r0
    mov.l @(28, r1), r4
    dmuls.l r2, r4
    sts mach, r2
    dmuls.l r0, r4
    mov.w r2, @r5
    sts mach, r0
    rts
    mov.w r0, @(2, r5)
.L_060276C0:
    .2byte  0xFF00
    .2byte  0x0009
    .4byte  0x00010000
    .2byte  0xFF00
.L_060276CA:
    .2byte  0x00A0
