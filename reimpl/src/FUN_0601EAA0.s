
    .section .text.FUN_0601EAA0


    .global FUN_0601EAA0
    .type FUN_0601EAA0, @function
FUN_0601EAA0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov #0x0, r13
    mov.l   .L_pool_0601EAE4, r14
    mov.l   .L_pool_0601EAD8, r2
    mov.b @r14, r4
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r3
    add r3, r4
    .reloc ., R_SH_IND12W, FUN_0601E4D4 - 4
    .2byte 0xB000    /* bsr FUN_0601E4D4 (linker-resolved) */
    add r2, r4
    extu.b r0, r4
    mov.l   .L_pool_0601EAE8, r6
    mov #0x7, r2
    cmp/ge r2, r4
    bf      .L_0601EAEC
    mov.b @r14, r0
    extu.b r0, r0
    mov #0x0, r3
    mov.b r3, @(r0, r6)
    bra     .L_0601EB12
    nop
    .4byte  sym_060877D9
.L_pool_0601EAD8:
    .4byte  sym_0604A57C
    .4byte  sym_06087080
    .4byte  sym_0604A5AC
.L_pool_0601EAE4:
    .4byte  sym_060877D8
.L_pool_0601EAE8:
    .4byte  sym_060877DD
.L_0601EAEC:
    mov #0x1, r5
    mov #0x3, r2
    mov.b @r14, r0
    extu.b r0, r0
    mov.b r5, @(r0, r6)
    .byte   0xD6, 0x19    /* mov.l .L_pool_0601EB5C, r6 */
    cmp/ge r2, r4
    bf      .L_0601EB08
    mov.b @r14, r0
    extu.b r0, r0
    add #-0x3, r4
    extu.b r4, r4
    bra     .L_0601EB12
    mov.b r4, @(r0, r6)
.L_0601EB08:
    mov.b @r14, r0
    extu.b r0, r0
    extu.b r4, r4
    mov.b r4, @(r0, r6)
    extu.b r5, r13
.L_0601EB12:
    mov r13, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
