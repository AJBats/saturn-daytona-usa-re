
    .section .text.FUN_06004F28


    .global FUN_06004F28
    .type FUN_06004F28, @function
FUN_06004F28:
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0xC, r15
    mov.l   .L_06004FDC, r10
    mov.l   .L_06004FE0, r11
    mov.l   .L_06004FE4, r12
    mov.l   .L_06004FE8, r14
    mov.l r4, @(4, r15)
    mov.l r7, @r15
    tst r3, r3
    bt/s    .L_06004F7E
    mov r6, r13
    mov.l @(4, r15), r4
    mov.w @(2, r4), r0
    mov.w @r4, r2
    mov r0, r3
    mulu.w r2, r3
    sts macl, r3
    add #0x2, r3
    shll r3
    extu.w r3, r3
    mov r3, r0
    extu.w r3, r6
    mov.w r0, @(8, r15)
    mov.l   .L_06004FEC, r8
    mov.l @(4, r15), r5
    mov.l   .L_06004FF0, r2
    mov.l @r8, r8
    jsr @r2
    mov r8, r4
    mov.w @(8, r15), r0
    mov r0, r4
    extu.w r4, r4
    mov.l   .L_06004FEC, r3
    mov.l @r3, r3
    add r4, r3
    mov.l   .L_06004FEC, r2
    mov.l r3, @r2
    mov.l   .L_06004FF4, r5
    mov.l @r5, r1
    add r4, r1
    bra     .L_06004F80
    mov.l r1, @r5
.L_06004F7E:
    mov.l @(4, r15), r8
.L_06004F80:
    tst r13, r13
    bt      .L_0600504E
    mov #0x3, r3
    and r9, r3
    tst r3, r3
    bf/s    .L_06005000
    mov #0x8, r4
    mov.l @r14, r3
    and r4, r9
    mov.l @r12, r2
    shll2 r3
    shll r3
    add r10, r3
    tst r9, r9
    bt/s    .L_06004FB6
    mov.l r2, @(4, r3)
    mov.l @r12, r5
    mov.l   .L_06004FF8, r3
    shll2 r5
    shll2 r5
    shll r5
    add r3, r5
    mov.l   .L_06004FFC, r3
    jsr @r3
    mov r13, r4
    bra     .L_06004FD0
    nop
.L_06004FB6:
    mov.l @r15, r6
    mov.l @r12, r4
    mov.l   .L_06004FF8, r3
    shll2 r6
    shll2 r4
    shll2 r6
    shll2 r4
    shll r6
    shll r4
    add r3, r4
    mov.l   .L_06004FF0, r3
    jsr @r3
    mov r13, r5
.L_06004FD0:
    mov.l @r15, r2
    mov.l @r12, r3
    add r2, r3
    mov.l r3, @r12
    bra     .L_06005064
    nop
.L_06004FDC:
    .4byte  sym_06063750                 /* display command table base */
.L_06004FE0:
    .4byte  sym_06059F1C
.L_06004FE4:
    .4byte  sym_06059F18
.L_06004FE8:
    .4byte  sym_06059F10
.L_06004FEC:
    .4byte  sym_06063D90
.L_06004FF0:
    .4byte  FUN_0602761E
.L_06004FF4:
    .4byte  sym_06063D94
.L_06004FF8:
    .4byte  0x25E00000
.L_06004FFC:
    .4byte  FUN_06028654
.L_06005000:
    mov.l @r14, r2
    and r4, r9
    mov.l @r11, r3
    shll2 r2
    shll r2
    add r10, r2
    tst r9, r9
    bt/s    .L_06005028
    mov.l r3, @(4, r2)
    mov.l @r11, r5
    mov.l   .L_pool_060050D8, r3
    shll2 r5
    shll2 r5
    shll r5
    add r3, r5
    mov.l   .L_pool_060050DC, r3
    jsr @r3
    mov r13, r4
    bra     .L_06005042
    nop
.L_06005028:
    mov.l @r15, r6
    mov.l @r11, r4
    mov.l   .L_pool_060050D8, r3
    shll2 r6
    shll2 r4
    shll2 r6
    shll2 r4
    shll r6
    shll r4
    add r3, r4
    mov.l   .L_060050E0, r3
    jsr @r3
    mov r13, r5
.L_06005042:
    mov.l @r15, r2
    mov.l @r11, r3
    add r2, r3
    mov.l r3, @r11
    bra     .L_06005064
    nop
.L_0600504E:
    mov.l @r14, r2
    mov.l @r14, r3
    shll2 r2
    add #-0x1, r3
    shll r2
    shll2 r3
    add r10, r2
    shll r3
    add r10, r3
    mov.l @(4, r3), r1
    mov.l r1, @(4, r2)
.L_06005064:
    mov.l @r14, r3
    shll2 r3
    shll r3
    add r10, r3
    mov.l r8, @r3
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    add #0xC, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0600508A
sym_0600508A:
    mov #0x4, r3


    .global FUN_0600508C
    .type FUN_0600508C, @function
FUN_0600508C:
    mov.l r14, @-r15
    and r3, r6
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x4, r15
    mov.l r5, @r15
    tst r6, r6
    bt/s    .L_060050EC
    mov r4, r13
    mov r13, r4
    mov r13, r5
    mov.l   .L_060050E4, r11
    mov.w @(2, r4), r0
    mov.w @r4, r3
    mov.l @r11, r14
    mov r0, r12
    mulu.w r3, r12
    mov.l   .L_060050E0, r3
    sts macl, r12
    add #0x2, r12
    shll r12
    extu.w r12, r12
    extu.w r12, r6
    jsr @r3
    mov r14, r4
    extu.w r12, r5
    mov.l @r11, r2
    add r5, r2
    mov.l r2, @r11
    mov.l   .L_060050E8, r4
    mov.l @r4, r3
    add r5, r3
    mov.l r3, @r4
    bra     .L_060050EE
    nop
.L_pool_060050D8:
    .4byte  0x25E20000
.L_pool_060050DC:
    .4byte  FUN_06028654
.L_060050E0:
    .4byte  FUN_0602761E
.L_060050E4:
    .4byte  sym_06063D90
.L_060050E8:
    .4byte  sym_06063D94
.L_060050EC:
    mov r13, r14
.L_060050EE:
    mov.l   .L_pool_0600515C, r5
    mov.l   .L_pool_06005160, r4
    mov.l @r15, r3
    mov.l @r4, r2
    shll2 r2
    shll r2
    add r5, r2
    mov.l r3, @(4, r2)
    mov.l @r4, r3
    shll2 r3
    shll r3
    add r5, r3
    mov.l r14, @r3
    mov.l @r4, r2
    add #0x1, r2
    mov.l r2, @r4
    add #0x4, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0600511E
sym_0600511E:
    mov #0x3, r3

    .global FUN_06005120
    .type FUN_06005120, @function
FUN_06005120:
    mov.l r14, @-r15
    and r7, r3
    add #-0x8, r15
    mov.l r4, @r15
    mov.l r6, @(4, r15)
    tst r3, r3
    bf      .L_06005134
    mov.l   .L_06005164, r14
    bra     .L_06005136
    nop
.L_06005134:
    mov.l   .L_06005168, r14
.L_06005136:
    mov #0x8, r2
    and r2, r7
    tst r7, r7
    bt/s    .L_0600514C
    add r5, r14
    mov r14, r5
    mov.l @r15, r4
    add #0x8, r15
    mov.l   .L_0600516C, r3
    jmp @r3
    mov.l @r15+, r14
.L_0600514C:
    mov.l @(4, r15), r6
    mov.l @r15, r5
    mov r14, r4
    add #0x8, r15
    mov.l   .L_06005170, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_0600515C:
    .4byte  sym_06063750
.L_pool_06005160:
    .4byte  sym_06059F10
.L_06005164:
    .4byte  0x25E00000
.L_06005168:
    .4byte  0x25E20000
.L_0600516C:
    .4byte  FUN_06028654
.L_06005170:
    .4byte  FUN_06027630

    .global sym_06005174
sym_06005174:
    .byte   0xD5, 0x2A    /* mov.l .L_pool_06005220, r5 */
    mov #0x0, r4
    mov.w r4, @r5
    extu.w r4, r0
    mov.w r0, @(2, r5)
    extu.w r4, r0
    mov.w r0, @(4, r5)
    extu.w r4, r0
    mov.w r0, @(6, r5)
    add #0x8, r5
    extu.w r4, r0
    mov.w r4, @r5
    mov.w r0, @(2, r5)
    extu.w r4, r0
    mov.w r0, @(4, r5)
    extu.w r4, r0
    rts
    mov.w r0, @(6, r5)
