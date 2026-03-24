
    .section .text.FUN_06040B34


    .global FUN_06040B34
    .type FUN_06040B34, @function
FUN_06040B34:
    mov.l r14, @-r15
    mov #0x0, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x18, r15
    mov.l r5, @(20, r15)
    mov.l   .L_pool_06040B50, r3
    mov.b @(r0, r3), r2
    extu.b r2, r2
    tst r2, r2
    bt/s    .L_06040B54
    mov r4, r13
    .reloc ., R_SH_IND12W, FUN_06040BF2 - 4
    .2byte 0xA000    /* bra FUN_06040BF2 (linker-resolved) */
    mov #0x0, r0
.L_pool_06040B50:
    .4byte  sym_0606367C
.L_06040B54:
    mov r15, r3
    add #0x4, r3
    mov.l r3, @-r15
    mov r15, r7
    mov.l @(24, r15), r6
    mov.l @(16, r13), r5
    .byte   0xD3, 0x26    /* mov.l .L_pool_06040BFC, r3 */
    add #0x4, r7
    jsr @r3
    mov.l @(4, r13), r4
    tst r0, r0
    bt/s    .L_06040B72
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_06040BF2 - 4
    .2byte 0xA000    /* bra FUN_06040BF2 (linker-resolved) */
    mov #0x0, r0
.L_06040B72:
    .byte   0xD3, 0x23    /* mov.l .L_pool_06040C00, r3 */
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06040B80
    .reloc ., R_SH_IND12W, FUN_06040BF2 - 4
    .2byte 0xA000    /* bra FUN_06040BF2 (linker-resolved) */
    mov #0x0, r0
.L_06040B80:
    mov.l @(4, r15), r3
    cmp/pl r3
    bt      .L_06040B8A
    .reloc ., R_SH_IND12W, FUN_06040BF2 - 4
    .2byte 0xA000    /* bra FUN_06040BF2 (linker-resolved) */
    mov #0x0, r0
.L_06040B8A:
    mov r14, r6
    mov r14, r5


    .global FUN_06040B8E
    .type FUN_06040B8E, @function
FUN_06040B8E:
    mov.l r14, @-r15
