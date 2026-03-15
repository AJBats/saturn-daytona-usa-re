
    .section .text.FUN_0604188C


    .global FUN_0604188C
    .type FUN_0604188C, @function
FUN_0604188C:
    sts.l pr, @-r15
    mov.l   .L_pool_060418AC, r4
    mov.l   .L_pool_060418A8, r3
    mov.l @r3, r3
    mov.l r4, @(60, r3)
.L_06041896:
    .reloc ., R_SH_IND12W, FUN_06041698 - 4
    .2byte 0xB000    /* bsr FUN_06041698 (linker-resolved) */
    nop
    cmp/eq #0x1, r0
    bt/s    .L_060418A4
    mov r0, r4
    bra     .L_060418B0
    nop
.L_060418A4:
    bra     .L_06041896
    nop
.L_pool_060418A8:
    .4byte  sym_060A5400
.L_pool_060418AC:
    .4byte  0x00008000
.L_060418B0:
    mov #0x0, r5
    .byte   0xD2, 0x2A    /* mov.l .L_pool_0604195C, r2 */
    mov.l @r2, r2
    mov.l r5, @(60, r2)
    lds.l @r15+, pr
    rts
    mov r4, r0
