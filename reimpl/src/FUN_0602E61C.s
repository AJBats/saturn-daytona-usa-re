
    .section .text.FUN_0602E61C


    .global FUN_0602E61C
    .type FUN_0602E61C, @function
FUN_0602E61C:
    mov.l r14, @-r15
    mov.l   .L_pool_0602E639, r9
    mov.l @r9, r9
    mov.l   .L_pool_0602E63D, r0
    mov.l @(r0, r9), r7
    mov.l   .L_pool_0602E641, r0
    mov.l @(r0, r9), r10
    mov.l   .L_pool_0602E645, r3
    mov.l @r3, r3
    cmp/eq r10, r3
    bf      .L_0602E648
    .reloc ., R_SH_IND12W, FUN_0602E78C - 4
    .2byte 0xA000    /* bra FUN_0602E78C (linker-resolved) */
    nop
    .2byte  0x0000
.L_pool_0602E639:
    .4byte  sym_0607E944
.L_pool_0602E63D:
    .4byte  0x00000008
.L_pool_0602E641:
    .4byte  0x00000238
.L_pool_0602E645:
    .4byte  DAT_06083264
.L_0602E648:
    mov.l   .L_pool_0602E655, r3
    mov.l @r3, r3
    cmp/eq r10, r3
    bt      .L_0602E658
    .reloc ., R_SH_IND12W, FUN_0602E6E8 - 4
    .2byte 0xA000    /* bra FUN_0602E6E8 (linker-resolved) */
    nop
.L_pool_0602E655:
    .4byte  DAT_06083268
.L_0602E658:
    .byte   0xD0, 0x14    /* mov.l .L_pool_0602E6AC, r0 */
    mov.l @(r0, r10), r8
    sub r7, r8
    cmp/pz r8
    bt      .L_0602E664
    neg r8, r8
.L_0602E664:
    .byte   0xD0, 0x12    /* mov.l .L_pool_0602E6B0, r0 */
    mov.l @(r0, r9), r3
    mov.l @(r0, r10), r5
    .byte   0xD0, 0x12    /* mov.l .L_pool_0602E6B4, r0 */
    mov.l @(r0, r9), r6
    mov.l @(r0, r10), r4
    mov.l r4, @-r15
    sub r3, r5
    mov r5, r4
    .byte   0xDD, 0x10    /* mov.l .L_pool_0602E6B8, r13 */


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
