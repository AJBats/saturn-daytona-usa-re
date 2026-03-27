
    .section .text.FUN_06012AC4


    .global FUN_06012AC4
    .type FUN_06012AC4, @function
FUN_06012AC4:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    .byte   0xDC, 0x1C    /* mov.l .L_pool_06012B40, r12 */
    .byte   0xDD, 0x1D    /* mov.l .L_pool_06012B44, r13 */
    .byte   0xDE, 0x1D    /* mov.l .L_pool_06012B48, r14 */
    mov.w   .L_wpool_06012B39, r5
    mov r12, r7
    mov r14, r6
    jsr @r13
    mov #0x8, r4
    mov r12, r7
    mov r14, r6
    .byte   0x95, 0x2A    /* mov.w .L_wpool_06012B38, r5 */
    jsr @r13
    mov #0x8, r4
    mov r12, r7
    mov r14, r6
    .byte   0x95, 0x26    /* mov.w .L_wpool_06012B3A, r5 */
    jsr @r13
    mov #0x8, r4
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06012AFA
    .type FUN_06012AFA, @function
FUN_06012AFA:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06012B4F, r14
    mov.l @r14, r0
    tst #0x4, r0
    bt      .L_06012B24
    mov.l   .L_pool_06012B53, r3
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_wpool_06012B39, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    mov.w   .L_wpool_06012B3F, r3
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06012B57, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_06012B28
    nop
.L_06012B24:
    bsr     FUN_06012AC4
    nop
.L_06012B28:
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_06012B39:
    .2byte  0x061C
    .4byte  0x069C071C
.L_wpool_06012B3F:
    .2byte  0x4000
    .2byte  0xFFFF
    .4byte  sym_0605ACDD
    .4byte  sym_060283E0
    .4byte  0x0000F000
.L_pool_06012B4F:
    .4byte  sym_060788FC
.L_pool_06012B53:
    .4byte  sym_06063800
.L_pool_06012B57:
    .4byte  sym_06028400
