
    .section .text.FUN_060204B4


    .global FUN_060204B4
    .type FUN_060204B4, @function
FUN_060204B4:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06020514, r3 */
    jsr @r3
    mov.b r4, @r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06020518, r3 */
    jsr @r3
    nop
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_06020DEE - 4
    .2byte 0xA000    /* bra FUN_06020DEE (linker-resolved) */
    lds.l @r15+, pr

    .global sym_060204CE
sym_060204CE:
    mov #0x0, r5


    .global FUN_060204D0
    .type FUN_060204D0, @function
FUN_060204D0:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_pool_0602051C, r14
    mov.l   .L_pool_06020520, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov r3, r6
    mov.l   .L_pool_06020524, r3
    jsr @r3
    mov #0x20, r4
    mov.l @r14, r2
    mov.l   .L_pool_06020528, r3
    cmp/gt r3, r2
    bf      .L_06020508
    mov.b @r15, r4
    .reloc ., R_SH_IND12W, FUN_06020DEE - 4
    .2byte 0xB000    /* bsr FUN_06020DEE (linker-resolved) */
    extu.b r4, r4
    mov.l   .L_pool_06020528, r6
    mov #0x0, r5
    mov #0x20, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_06020524, r3
    jmp @r3
    mov.l @r15+, r14
.L_06020508:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global FUN_06020510
FUN_06020510:
    rts
    nop
    .4byte  sym_06028560
    .4byte  FUN_060032D4
.L_pool_0602051C:
    .4byte  sym_06087814
.L_pool_06020520:
    .4byte  0x00180000
.L_pool_06020524:
    .4byte  FUN_06014884
.L_pool_06020528:
    .4byte  0x00980000
