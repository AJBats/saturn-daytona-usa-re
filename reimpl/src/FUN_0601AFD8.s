
    .section .text.FUN_0601AFD8


    .global FUN_0601AFD8
    .type FUN_0601AFD8, @function
FUN_0601AFD8:
    mov.l r14, @-r15
    mov #0x0, r7
    mov #0x30, r6


    .global FUN_0601AFDE
    .type FUN_0601AFDE, @function
FUN_0601AFDE:
    sts.l pr, @-r15
    mov r6, r5
    mov.l   .L_0601B064, r14
    mov.w   .L_0601B05E, r3
    mov.l r3, @-r15
    mov.w   .L_0601B060, r2
    mov.l r2, @-r15
    mov.l @r14, r3
    mov #0x1, r2
    extu.w r3, r3
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l   .L_0601B068, r3
    jsr @r3
    mov r7, r4
    mov.l @r14, r2
    add #0x2, r2
    mov.l r2, @r14
    mov r2, r3
    mov.w   .L_0601B05E, r2
    cmp/hs r2, r3
    bf/s    .L_0601B01A
    add #0x10, r15
    mov.l   .L_0601B06C, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    mov #0x28, r3
    mov.l   .L_0601B070, r2
    mov.b r3, @r2
.L_0601B01A:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14


    .global FUN_0601B020
    .type FUN_0601B020, @function
FUN_0601B020:
    mov.l r14, @-r15
    mov #0x0, r7

    .global FUN_0601B024
    .type FUN_0601B024, @function
FUN_0601B024:
    sts.l pr, @-r15
    mov #0x30, r14
    mov.l   .L_0601B064, r3
    mov r14, r6
    mov r14, r5
    mov.l r14, @r3
    mov.w   .L_0601B05E, r2
    mov.l r2, @-r15
    mov.w   .L_0601B060, r3
    extu.w r14, r2
    mov.l r3, @-r15
    mov #0x1, r3
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l   .L_0601B068, r3
    jsr @r3
    mov r7, r4
    .reloc ., R_SH_IND12W, FUN_0601B0D8 - 4
    .2byte 0xB000    /* bsr FUN_0601B0D8 (linker-resolved) */
    add #0x10, r15
    mov #0x14, r2
    mov.l   .L_0601B070, r3
    mov.b r2, @r3
    mov.l   .L_0601B06C, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601B05E:
    .2byte  0x00A7
.L_0601B060:
    .2byte  0x0160
    .2byte  0xFFFF
.L_0601B064:
    .4byte  sym_06086014
.L_0601B068:
    .4byte  FUN_06039100
.L_0601B06C:
    .4byte  sym_06086011
.L_0601B070:
    .4byte  sym_0608600F
