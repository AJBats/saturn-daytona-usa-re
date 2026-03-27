
    .section .text.FUN_0602E714


    .global FUN_0602E714
    .type FUN_0602E714, @function
FUN_0602E714:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov r0, r7
    mov.l @r15+, r4
    sub r6, r4
    mov r4, r5
    mov.l   .L_pool_0602E75C, r13


    .global FUN_0602E726
    .type FUN_0602E726, @function
FUN_0602E726:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    add r0, r7
    cmp/pz r7
    .byte   0x89, 0x17    /* bt 0x0602E764 (external) */
    mov r7, r4
    shlr2 r4
    mov.l   .L_pool_0602E760, r13

    .global FUN_0602E73A
    .type FUN_0602E73A, @function
FUN_0602E73A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E770 - 4
    .2byte 0xA000    /* bra FUN_0602E770 (linker-resolved) */
    shll r0
    .2byte  0x0000
    .4byte  DAT_06083264
    .4byte  0x0000023C
    .4byte  0x00000008
    .4byte  0x00000010
    .4byte  0x00000018
.L_pool_0602E75C:
    .4byte  FUN_06027552
.L_pool_0602E760:
    .4byte  FUN_06027476
    .4byte  0x6473DD07
