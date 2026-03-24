
    .section .text.FUN_06033614


    .global FUN_06033614
    .type FUN_06033614, @function
FUN_06033614:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r8
    mov.l @r15+, r0
    rts
    nop
    .4byte  sym_0603363C
    .4byte  FUN_06027348
    .4byte  FUN_06027344

    .global sym_06033630
sym_06033630:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    shll r0
    .word 0x0000
    .word 0x8E00

    .global sym_0603363C
sym_0603363C:
    .word 0x0000
    .word 0x0000
    .word 0x0000
    mov.b r0, @(0, gbr)
    .word 0x0000
    add #0x0, r6
    .global FUN_06033648
FUN_06033648:
    mov.l r0, @-r15
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_060336F2 - 4
    .2byte 0xB000    /* bsr FUN_060336F2 (linker-resolved) */
    nop
    lds.l @r15+, pr
    bf      .L_0603365A
    mov.l @r15+, r0
    bra     .L_0603366C
    mov #0x1, r6
.L_0603365A:
    .byte   0xD0, 0x82    /* mov.l .L_pool_06033864, r0 */
    mov.l @r0, r0
    cmp/pl r0
    .byte   0x89, 0x28    /* bt 0x060336B4 (external) */
    mov.l @r15+, r0
    .byte   0xD6, 0x15    /* mov.l .L_pool_060336BC, r6 */
    mov.l @r6, r6
    mov.l @r6, r6
    add #-0x1, r6
.L_0603366C:
    mov.l r0, @-r15
    .byte   0xD2, 0x14    /* mov.l .L_pool_060336C0, r2 */
    mov.l @(r0, r2), r3
    mov #0x0, r4
    cmp/eq r4, r3
    .byte   0x8B, 0x00    /* bf 0x0603367A (external) */
    mov #0x1, r4


    .global FUN_0603367A
    .type FUN_0603367A, @function
FUN_0603367A:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_060336C8 - 4
    .2byte 0xB000    /* bsr FUN_060336C8 (linker-resolved) */
    nop
    lds.l @r15+, pr
.L_06033682:
    .byte   0xD5, 0x10    /* mov.l .L_pool_060336C4, r5 */
    add r5, r0
    mov.l @(r0, r2), r3
    cmp/eq r4, r3
    bt      .L_06033692
    add #-0x1, r6
    cmp/pl r6
    bt      .L_06033682
.L_06033692:
    mov #0x6, r2
    .byte   0xD3, 0x7A    /* mov.l .L_pool_06033880, r3 */
    mov.b @r3, r3
    cmp/pl r3
    bt      .L_060336AA
    mov.l r0, @-r15
    mov #0x1, r0
    cmp/ge r4, r0
    mov.l @r15+, r0
    bf      .L_060336AA
    shll2 r4
    add r4, r2
.L_060336AA:
    mov.w r2, @-r1
