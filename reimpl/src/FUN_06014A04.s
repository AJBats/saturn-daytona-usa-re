
    .section .text.FUN_06014A04


    .global FUN_06014A04
    .type FUN_06014A04, @function
FUN_06014A04:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06014A50, r3
    mov.l r3, @r15
    mov.l   .L_pool_06014A54, r5
    mov.l   .L_pool_06014A58, r4
    mov.w   .L_pool_06014A4E, r2
    mov.l @r4, r4
    shll2 r4
    shll r4
    add r3, r4
    add r2, r4
    mov.l   .L_pool_06014A5C, r2
    jsr @r2
    mov #0x20, r6
    mov.l   .L_pool_06014A60, r3
    jsr @r3
    nop
    mov.l   .L_pool_06014A64, r5
    mov #0x1, r4
    mov #0x0, r3
    mov.l @r5, r2
    or r4, r2
    mov.l r2, @r5
    mov.l   .L_pool_06014A68, r2
    mov.w r3, @r2
    mov.l   .L_pool_06014A6C, r3
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.w r4, @r3


    .global FUN_06014A42
    .type FUN_06014A42, @function
FUN_06014A42:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06014F34 - 4
    .2byte 0xB000    /* bsr FUN_06014F34 (linker-resolved) */
    nop
    mov.l   .L_pool_06014A71, r3
    jmp @r3
    lds.l @r15+, pr
.L_pool_06014A4E:
    .2byte  0x0260
.L_pool_06014A50:
    .4byte  0x25C00000
.L_pool_06014A54:
    .4byte  sym_06044B64
.L_pool_06014A58:
    .4byte  sym_06059FFC
.L_pool_06014A5C:
    .4byte  FUN_0602761E
.L_pool_06014A60:
    .4byte  FUN_060172BC
.L_pool_06014A64:
    .4byte  sym_0607EBF4
.L_pool_06014A68:
    .4byte  sym_06085F90
.L_pool_06014A6C:
    .4byte  sym_06085F94
.L_pool_06014A71:
    .4byte  FUN_0601712C
