
    .section .text.FUN_06041D74


    .global FUN_06041D74
    .type FUN_06041D74, @function
FUN_06041D74:
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_pool_06041DF4, r14
    mov.l r4, @r15
    mov #0x1, r4
    mov.l @r14, r3
    mov.w   .L_wpool_06041DEC, r0
    mov.l @(r0, r3), r2
    cmp/eq r4, r2
    bf/s    .L_06041E0C
    mov r4, r12
    mov.l @r14, r2
    mov.w   .L_wpool_06041DEE, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bf      .L_06041DDE
    mov.l @r14, r3
    mov.w   DAT_06041df0, r0
    mov.l @(r0, r3), r2
    mov.l   .L_06041DF8, r3
    cmp/eq r3, r2
    bf      .L_06041DDE
    mov.l @r14, r5
    mov.w   DAT_06041df2, r0
    mov.l   .L_pool_06041DFC, r3
    mov.l @(r0, r5), r5
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041DB6
    bra     .L_06041EDC
    mov #0x1, r0
.L_06041DB6:
    mov r15, r4
    mov.l   .L_pool_06041E00, r3
    jsr @r3
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov.l @r15, r3
    mov.l @r3, r2
    add #0x1, r2
    mov.l r2, @r3
    mov.l @r14, r3
    mov #0x4, r2
    mov.w   .L_wpool_06041DEC, r0
    mov.l r2, @(r0, r3)
    bra     .L_06041E0C
    nop
.L_06041DDE:
    mov.l @r14, r4
    mov.w   DAT_06041df0, r0
    mov.l @(r0, r4), r4
    tst r4, r4
    bf      .L_06041E04
    bra     .L_06041E0C
    mov r13, r12
.L_wpool_06041DEC:
    .2byte  0x0338
.L_wpool_06041DEE:
    .2byte  0x0340

    .global DAT_06041df0
DAT_06041df0:
    .2byte  0x0344

    .global DAT_06041df2
DAT_06041df2:
    .2byte  0x033C
.L_pool_06041DF4:
    .4byte  sym_060A5400
.L_06041DF8:
    .4byte  0x0000FFFF
.L_pool_06041DFC:
    .4byte  FUN_060364D4
.L_pool_06041E00:
    .4byte  FUN_060349B6
.L_06041E04:
    mov.l @r14, r2
    mov #0x2, r3
    mov.w   .L_wpool_06041EB4, r0
    mov.l r3, @(r0, r2)
.L_06041E0C:
    mov.l @r14, r0
    mov.w   .L_wpool_06041EB4, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_06041E56
    mov.l @r14, r6
    mov.w   DAT_06041eb6, r0
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   .L_pool_06041EBC, r3
    mov.l @(r0, r6), r6
    add #-0x4, r0
    mov.l @(r0, r5), r5
    add #-0x4, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    mov.l @r15, r2
    mov.l @r2, r3
    add #0x1, r3
    tst r4, r4
    bf/s    .L_06041E56
    mov.l r3, @r2
    mov.l @r14, r3
    mov #0x3, r2
    mov.w   .L_wpool_06041EB4, r0
    mov r15, r4
    mov.l r2, @(r0, r3)
    mov.l   .L_pool_06041EC0, r3
    jsr @r3
    add #0x4, r4
    mov.l @r14, r2
    mov r15, r3
    add #0x4, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
.L_06041E56:
    mov.l @r14, r0
    mov.w   .L_wpool_06041EB4, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_06041E80
    mov.w   .L_wpool_06041EB8, r2
    mov.l   .L_pool_06041EC4, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_06041E78
    bra     .L_06041E7A
    mov #0x1, r4
.L_06041E78:
    mov #0x0, r4
.L_06041E7A:
    tst r4, r4
    bt      .L_06041E80
    mov r13, r12
.L_06041E80:
    mov.l @r14, r0
    mov.w   .L_wpool_06041EB4, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x4, r0
    bf      .L_06041EAA
    mov #0x40, r2
    mov.l   .L_pool_06041EC4, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_06041EA2
    bra     .L_06041EA4
    mov #0x1, r5
.L_06041EA2:
    mov #0x0, r5
.L_06041EA4:
    tst r5, r5
    bt      .L_06041EAA
    mov r13, r12
.L_06041EAA:
    mov r12, r0
    cmp/eq #0x1, r0
    bf      .L_06041EC8
    bra     .L_06041EDC
    mov #0x1, r0
.L_wpool_06041EB4:
    .2byte  0x0338

    .global DAT_06041eb6
DAT_06041eb6:
    .2byte  0x0344
.L_wpool_06041EB8:
    .2byte  0x0080
    .2byte  0xFFFF
.L_pool_06041EBC:
    .4byte  FUN_0603683C
.L_pool_06041EC0:
    .4byte  FUN_060349B6
.L_pool_06041EC4:
    .4byte  sym_06035C4E
.L_06041EC8:
    .byte   0xD4, 0x33    /* mov.l .L_pool_06041F98, r4 */
    .byte   0xD3, 0x34    /* mov.l .L_pool_06041F9C, r3 */
    jsr @r3
    nop
    mov.l @r14, r2
    mov.w   DAT_06041f90, r0
    mov.l r13, @(r0, r2)
    mov.l @r14, r3
    mov.l r13, @(52, r3)
    mov r13, r0
.L_06041EDC:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


   .global FUN_06041EE8
   .type FUN_06041EE8, @function
FUN_06041EE8:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    .global FUN_06041EEE
FUN_06041EEE:
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_06041FA0, r12
    mov.l   .L_06041FA4, r14
    mov.w   .L_06041F92, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf/s    .L_06041F60
    mov r4, r13
    mov.l @r14, r5
    mov.w   DAT_06041f94, r3
    mov.l @r14, r4
    mov.w   DAT_06041f96, r0
    add r3, r5
    mov.l   .L_06041FA8, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r15, r4
    mov.l @r13, r2
    add #0x1, r2
    mov.l r2, @r13
    jsr @r12
    add #0x4, r4
    mov r15, r2
    mov #0x40, r0
    mov #0x0, r5
    mov.l @r14, r3
    add #0x4, r2
    mov.b @r2, r1
    mov.b r1, @(r0, r3)
    mov.l @r14, r4
    mov.w   DAT_06041f96, r0
    mov.l   .L_06041FAC, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041F40
    bra     .L_0604206E
    mov #0x1, r0
.L_06041F40:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r3
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r1
    mov #0x40, r0
    mov.b r1, @(r0, r3)
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x2, r3
    mov.w   .L_06041F92, r0
    mov.l r3, @(r0, r2)
.L_06041F60:
    mov.l @r14, r0
    mov.w   .L_06041F92, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_06041FD4
    mov.l @r14, r7
    mov.w   DAT_06041f96, r0
    mov.l @r14, r6
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   .L_06041FB0, r3
    mov.l @(r0, r7), r7
    add #0xC, r0
    mov.l @(r0, r6), r6
    add #-0x4, r0
    mov.l @(r0, r5), r5
    add #-0x4, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041FB4
    bra     .L_0604206E
    mov #0x1, r0

    .global DAT_06041f90
DAT_06041f90:
    .word 0x0338
.L_06041F92:
    .2byte  0x0348

    .global DAT_06041f94
DAT_06041f94:
    .2byte  0x035C

    .global DAT_06041f96
DAT_06041f96:
    .2byte  0x034C
    .4byte  0x0000FFF7
    .4byte  FUN_06035C54
.L_06041FA0:
    .4byte  FUN_060349B6
.L_06041FA4:
    .4byte  sym_060A5400
.L_06041FA8:
    .4byte  FUN_060363BC
.L_06041FAC:
    .4byte  FUN_06036380
.L_06041FB0:
    .4byte  FUN_0603697C
.L_06041FB4:
    mov r15, r4
    jsr @r12
    add #0x4, r4
    mov.l @r14, r3
    mov r15, r2
    add #0x4, r2
    mov.b @r2, r1
    mov #0x40, r0
    mov.b r1, @(r0, r3)
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x3, r3
    mov.w   .L_0604207A, r0
    mov.l r3, @(r0, r2)
.L_06041FD4:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
    .global FUN_06041FDA
FUN_06041FDA:
    cmp/eq #0x3, r0
    bf      .L_06042004
    mov.w   DAT_0604207c, r2
    mov.l   .L_06042080, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_06041FF6
    bra     .L_06041FF8
    mov #0x1, r5
.L_06041FF6:
    mov #0x0, r5
.L_06041FF8:
    tst r5, r5
    bt      .L_06042004
    mov.l @r14, r3
    mov #0x4, r2
    mov.w   .L_0604207A, r0
    mov.l r2, @(r0, r3)
.L_06042004:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x4, r0
    bf      .L_06042036
    mov.l @r14, r5
    mov.w   DAT_0604207e, r0
    mov.l @r14, r4
    mov.l   .L_06042084, r3
    mov.l @(r0, r5), r5
    add #-0x10, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06042028
    bra     .L_0604206E
    mov #0x1, r0
.L_06042028:
    mov.l @r13, r3
    add #0x1, r3
    mov.l r3, @r13
    mov.l @r14, r2
    mov #0x5, r3
    mov.w   .L_0604207A, r0
    mov.l r3, @(r0, r2)
.L_06042036:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x5, r0
    bf      .L_06042068
    mov #0x40, r2
    mov.l   .L_06042080, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_06042058
    bra     .L_0604205A
    mov #0x1, r5
.L_06042058:
    mov #0x0, r5
.L_0604205A:
    mov r5, r0
    cmp/eq #0x1, r0
    bf      .L_06042068
    mov.l @r14, r3
    mov #0x0, r2
    mov.w   .L_0604207A, r0
    mov.l r2, @(r0, r3)
.L_06042068:
    mov.l @r14, r0
    mov.w   .L_0604207A, r1
    mov.l @(r0, r1), r0
.L_0604206E:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0604207A:
    .2byte  0x0348

    .global DAT_0604207c
DAT_0604207c:
    .2byte  0x0100

    .global DAT_0604207e
DAT_0604207e:
    .2byte  0x035C
.L_06042080:
    .4byte  sym_06035C4E
.L_06042084:
    .4byte  FUN_06036380
