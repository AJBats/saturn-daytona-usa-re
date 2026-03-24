
    .section .text.FUN_0602E678


    .global FUN_0602E678
    .type FUN_0602E678, @function
FUN_0602E678:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    mov r0, r7
    mov.l @r15+, r4
    sub r6, r4
    mov r4, r5
    .byte   0xDD, 0x0B    /* mov.l .L_pool_0602E6B8, r13 */


    .global FUN_0602E68A
    .type FUN_0602E68A, @function
FUN_0602E68A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    add r0, r7
    cmp/pz r7
    .byte   0x89, 0x13    /* bt 0x0602E6C0 (external) */
    mov r7, r4
    shlr2 r4
    .byte   0xDD, 0x07    /* mov.l .L_pool_0602E6BC, r13 */

    .global FUN_0602E69E
    .type FUN_0602E69E, @function
FUN_0602E69E:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E6CC - 4
    .2byte 0xA000    /* bra FUN_0602E6CC (linker-resolved) */
    shll r0
    .2byte  0x0000
    .4byte  0x00000008
    .4byte  0x00000010
    .4byte  0x00000018
    .4byte  FUN_06027552
    .4byte  FUN_06027476
    .4byte  0x6473DD07
