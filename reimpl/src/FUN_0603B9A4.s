
    .section .text.FUN_0603B9A4


    .global FUN_0603B9A4
    .type FUN_0603B9A4, @function
FUN_0603B9A4:
    sts.l pr, @-r15
    add #-0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603B96A - 4
    .2byte 0xB000    /* bsr FUN_0603B96A (linker-resolved) */
    mov.l r4, @r15
    cmp/eq #-0x1, r0
    bf/s    .L_0603B9CE
    mov r0, r4
    .byte   0xD4, 0x0C    /* mov.l .L_pool_0603B9E4, r4 */
    mov.l @r4, r4
    add #0x34, r4
    mov #0x60, r0
    mov.l @(r0, r4), r3
    shll2 r3
    mov r4, r2
    add r2, r3
    mov.l @r15, r1
    mov.l r1, @r3
    mov #0x60, r0
    mov.l @(r0, r4), r3
    add #0x1, r3
    mov.l r3, @(r0, r4)
.L_0603B9CE:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop


    .global FUN_0603B9D6
    .type FUN_0603B9D6, @function
FUN_0603B9D6:
    mov.l r14, @-r15
    sts.l pr, @-r15
    tst r4, r4
    bf      .L_0603B9E8
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  sym_060A4D14
.L_0603B9E8:
    .reloc ., R_SH_IND12W, FUN_0603B96A - 4
    .2byte 0xB000    /* bsr FUN_0603B96A (linker-resolved) */
    nop
    cmp/eq #-0x1, r0
    bt/s    .L_0603BA26
    mov r0, r4
    mov #0x60, r0
    mov r4, r6
    mov r4, r5
    .byte   0xD7, 0x1B    /* mov.l .L_pool_0603BA68, r7 */
    add #0x1, r6
    mov.l @r7, r7
    shll2 r6
    add #0x34, r7
    mov.l @(r0, r7), r3
    add #-0x1, r3
    mov r3, r14
    mov.l r3, @(r0, r7)
    cmp/ge r14, r4
    bt/s    .L_0603BA26
    shll2 r5
.L_0603BA10:
    mov r7, r0
    mov r7, r2
    mov r6, r3
    add #0x1, r4
    add r5, r2
    add #0x4, r6
    mov.l @(r0, r3), r1
    mov.l r1, @r2
    cmp/ge r14, r4
    bf/s    .L_0603BA10
    add #0x4, r5
.L_0603BA26:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
