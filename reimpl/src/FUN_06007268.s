

    .section .text.FUN_06007268


    .global FUN_06007268
    .type FUN_06007268, @function
FUN_06007268:
    sts.l pr, @-r15
    mov.l   .L_pool_060072C0, r3
    mov.l   .L_pool_060072C0, r2
    mov.l @r3, r3
    add #0x1, r3
    mov.l r3, @r2
    mov #0x3, r3
    mov.l   .L_pool_060072C4, r2
    mov.l r3, @r2
    mov.l   .L_pool_060072C8, r3
    jsr @r3
    nop
    mov.l   .L_pool_060072CC, r2
    mov.l   .L_pool_060072D0, r3
    mov.l   .L_pool_060072C0, r1
    mov.l @r2, r2
    mov.l @r1, r1
    add r3, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r1
    bt      .L_06007298
    bra     .L_060072B6
    nop
.L_06007298:
    mov.l   .L_pool_060072D4, r5
    mov.l @r5, r0
    tst r0, r0
    bt      .L_060072B6
    mov.l   .L_pool_060072D8, r0
    mov.w @r0, r0
    extu.w r0, r0
    or #0x3, r0
    extu.w r0, r0
    mov.l   .L_060072DC, r3
    mov.w r0, @r3
    mov #0x0, r4
    mov.l   .L_pool_060072E0, r3
    mov.l r4, @r3
    mov.l r4, @r5
.L_060072B6:
    mov #0x4, r2
    mov.l   .L_pool_060072C4, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
.L_pool_060072C0:
    .4byte  sym_06059F44
.L_pool_060072C4:
    .4byte  sym_06059F54
.L_pool_060072C8:
    .4byte  controller_input_update
.L_pool_060072CC:
    .4byte  FUN_0605ACC4
.L_pool_060072D0:
    .4byte  sym_06059F58
.L_pool_060072D4:
    .4byte  sym_06063F58
.L_pool_060072D8:
    .4byte  sym_060A4C92
.L_060072DC:
    .4byte  0x25D00002
.L_pool_060072E0:
    .4byte  sym_060635C4

    .global sym_060072E4
sym_060072E4:
    mov.l r15, @-r15


    .global FUN_060072E6
    .type FUN_060072E6, @function
FUN_060072E6:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l r7, @-r15
    mov.l r6, @-r15
    mov.l r5, @-r15
    mov.l r4, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l r1, @-r15
    mov.l r0, @-r15
    sts.l pr, @-r15
    sts.l mach, @-r15
    sts.l macl, @-r15

    .byte   0xD3, 0x16    /* mov.l .L_06007364, r3 */
    mov.w   .L_0600735C, r5
    mov.l @r3, r3
    jsr @r3
    mov #-0x1, r4

    .byte   0xD2, 0x14    /* mov.l .L_06007368, r2 */
    .byte   0xD3, 0x14    /* mov.l .L_06007368, r3 */
    mov.l @r2, r2
    add #0x1, r2
    mov.l r2, @r3

    mov.w   .L_0600735E, r5
    mov.b @r5, r4
    extu.b r4, r0
    and #0x87, r0
    mov.b r0, @r5

    .byte   0xD3, 0x0E    /* mov.l .L_06007364, r3 */
    mov.w   .L_06007360, r4
    mov.l @r3, r3
    jsr @r3
    mov #0x0, r5

    lds.l @r15+, macl
    lds.l @r15+, mach
    lds.l @r15+, pr
    mov.l @r15+, r0
    mov.l @r15+, r1
    mov.l @r15+, r2
    mov.l @r15+, r3
    mov.l @r15+, r4
    mov.l @r15+, r5
    mov.l @r15+, r6
    mov.l @r15+, r7
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    mov.l @r15+, r15
    rte
    nop

.L_0600735C:
    .2byte  0x0083
.L_0600735E:
    .2byte  0xFE11
.L_06007360:
    .2byte  0xFF7C
    .2byte  0xFFFF

.L_06007364:
    .4byte  sym_06000344
.L_06007368:
    .4byte  sym_06059F40
