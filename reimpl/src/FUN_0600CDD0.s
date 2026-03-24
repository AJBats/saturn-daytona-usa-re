
    .section .text.FUN_0600CDD0


    .global FUN_0600CDD0
    .type FUN_0600CDD0, @function
FUN_0600CDD0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x2D    /* mov.l .L_pool_0600CE90, r14 */
    .byte   0x90, 0x53    /* mov.w .L_wpool_0600CE86, r0 */
    mov.l @r14, r14
    mov.l @(r0, r14), r13
    add #-0x4, r0
    mov r13, r3
    shll2 r13
    shll2 r3
    shll r13
    shll2 r3
    add r3, r13
    mov.l @(r0, r14), r3
    add r3, r13
    mov.w @(22, r13), r0
    mov r0, r3
    extu.w r3, r3
    .byte   0x90, 0x45    /* mov.w .L_wpool_0600CE88, r0 */
    mov.l r3, @(r0, r14)
    add #0x60, r0
    mov.l @(r0, r14), r4
    tst r4, r4
    bt      .L_0600CE0C
    mov r4, r12
    bra     .L_0600CE10
    add #-0x1, r12
.L_0600CE0C:
    .byte   0xDC, 0x21    /* mov.l .L_pool_0600CE94, r12 */
    mov.l @r12, r12
.L_0600CE10:
    mov r12, r11
    mov r12, r3
    .byte   0x90, 0x39    /* mov.w .L_wpool_0600CE8A, r0 */
    mov.l @(24, r14), r5
    shll2 r11
    shll2 r3
    mov.l @(r0, r14), r2
    shll r11
    shll2 r3
    add r3, r11
    add r2, r11
    mov.l @(4, r11), r3
    mov.l @r11, r4
    mov.l @(16, r14), r2
    sub r3, r5
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600CE98, r3 */
    jsr @r3
    sub r2, r4
    exts.w r0, r6
    exts.w r6, r5
    mov.w @(14, r13), r0
    mov r5, r4
    mov r0, r7
    shll2 r7
    sub r7, r4
    cmp/pz r4
    bt      .L_0600CE4C
    mov r7, r2
    bra     .L_0600CE4E
    sub r5, r2
.L_0600CE4C:
    mov r4, r2
.L_0600CE4E:
    .byte   0x93, 0x1D    /* mov.w .L_wpool_0600CE8C, r3 */
    cmp/gt r3, r2
    bf      .L_0600CE58
    .byte   0x90, 0x17    /* mov.w .L_wpool_0600CE86, r0 */
    mov.l r12, @(r0, r14)
.L_0600CE58:
    mov r13, r0
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0600CE66
    .type FUN_0600CE66, @function
FUN_0600CE66:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x09    /* mov.l .L_pool_0600CE91, r14 */
    mov.w   DAT_0600ce8e, r0
    mov.l @r14, r14
    mov.l @(r0, r14), r3
    add #0x4, r0
    mov.l r3, @(r0, r14)
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_0600CE9C
    .reloc ., R_SH_IND12W, FUN_0600CD40 - 4
    .2byte 0xB000    /* bsr FUN_0600CD40 (linker-resolved) */
    nop
    bra     .L_0600CEA0
    nop

    .global DAT_0600ce86
DAT_0600ce86:
    mov.b r14, @(r0, r1)

    .global DAT_0600ce88
DAT_0600ce88:
    mov.b r8, @(r0, r1)

    .global DAT_0600ce8a
DAT_0600ce8a:
    .word 0x01E0

    .global DAT_0600ce8c
DAT_0600ce8c:
    shll r0

    .global DAT_0600ce8e
DAT_0600ce8e:
    .2byte  0x01EC
.L_pool_0600CE91:
    .4byte  sym_0607E940
    .4byte  sym_0607EA9C
    .4byte  FUN_0602744C
.L_0600CE9C:
    bsr     FUN_0600CDD0
    nop
.L_0600CEA0:
    .byte   0x90, 0x4B    /* mov.w .L_wpool_0600CF3A, r0 */
    .byte   0xD3, 0x28    /* mov.l .L_pool_0600CF44, r3 */
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    shll2 r2
    add #0x68, r0
    add r3, r2
    mov.w @r2, r2
    extu.w r2, r2
    mov.l r2, @(r0, r14)
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global FUN_0600CEBA
    .type FUN_0600CEBA, @function
FUN_0600CEBA:
    sts.l pr, @-r15
    .byte   0xD4, 0x22    /* mov.l .L_0600CF48, r4 */
    mov.w   DAT_0600cf3a, r0
    .byte   0xD3, 0x20    /* mov.l .L_0600CF44, r3 */
    mov.l @r4, r4
    mov.l @r3, r3
    mov.l @(r0, r4), r5
    add #0x68, r0
    shll2 r5
    mov.l @(r0, r4), r2
    add r3, r5
    add #0x4, r0
    mov.l r2, @(r0, r4)
    mov.w @r5, r3
    add #-0x4, r0
    extu.w r3, r3
    mov.l r3, @(r0, r4)
    mov.w   .L_0600CF3C, r1
    mov.w   .L_0600CF3E, r2
    .byte   0xD3, 0x1A    /* mov.l .L_0600CF4C, r3 */
    add r4, r1
    add r4, r2
    jsr @r3
    mov #0x2, r0
    mov r5, r2
    .byte   0xD3, 0x17    /* mov.l .L_0600CF4C, r3 */
    mov.w   .L_0600CF3E, r1
    add #0x2, r2
    add r4, r1
    jsr @r3
    mov #0x2, r0
    mov.w   DAT_0600cf40, r0
    mov.l @(r0, r4), r6
    add #-0x4, r0
    mov.l @(r0, r4), r3
    sub r3, r6
    exts.w r6, r6
    exts.w r6, r5
    cmp/pl r5
    bf      .L_0600CF34
    .byte   0xD2, 0x11    /* mov.l .L_0600CF50, r2 */
    mov.l @r2, r2
    add #-0x10, r2
    cmp/gt r2, r5
    bf      .L_0600CF34
    mov.w   .L_0600CF42, r0
    mov.l @(r0, r4), r2
    add #0x1, r2
    mov.l r2, @(r0, r4)
    add #-0xC, r0
    mov.l r2, @(r0, r4)
    .byte   0xD5, 0x0C    /* mov.l .L_0600CF54, r5 */
    mov.l @r5, r3
    add #0x10, r0
    mov.l @(r0, r4), r2
    sub r2, r3
    add #-0xC, r0
    mov.l r3, @(r0, r4)
    mov.l @r5, r3
    add #0xC, r0
    mov.l r3, @(r0, r4)
.L_0600CF34:
    lds.l @r15+, pr
    rts
    nop

    .global DAT_0600cf3a
DAT_0600cf3a:
    .2byte  0x0184
.L_0600CF3C:
    .2byte  0x0162
.L_0600CF3E:
    .2byte  0x0160

    .global DAT_0600cf40
DAT_0600cf40:
    .2byte  0x01F0
.L_0600CF42:
    .2byte  0x0228
.L_0600CF44:
    .4byte  sym_0607EB84
.L_0600CF48:
    .4byte  sym_0607E940
.L_0600CF4C:
    .4byte  sym_06035228
.L_0600CF50:
    .4byte  sym_0607EA9C
.L_0600CF54:
    .4byte  sym_0607EBD0
