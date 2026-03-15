
    .section .text.FUN_06041826


    .global FUN_06041826
    .type FUN_06041826, @function
FUN_06041826:
    mov.l r14, @-r15
    mov r5, r14
    bra     .L_06041860
    mov r4, r0
.L_0604182E:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_060418BE - 4
    .2byte 0xA000    /* bra FUN_060418BE (linker-resolved) */
    mov.l @r15+, r14
.L_06041834:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041AA0 - 4
    .2byte 0xA000    /* bra FUN_06041AA0 (linker-resolved) */
    mov.l @r15+, r14
.L_0604183A:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041B3C - 4
    .2byte 0xA000    /* bra FUN_06041B3C (linker-resolved) */
    mov.l @r15+, r14
.L_06041840:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041CC8 - 4
    .2byte 0xA000    /* bra FUN_06041CC8 (linker-resolved) */
    mov.l @r15+, r14
.L_06041846:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041D6C - 4
    .2byte 0xA000    /* bra FUN_06041D6C (linker-resolved) */
    mov.l @r15+, r14
.L_0604184C:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06041EE8 - 4
    .2byte 0xA000    /* bra FUN_06041EE8 (linker-resolved) */
    mov.l @r15+, r14
.L_06041852:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06042134 - 4
    .2byte 0xA000    /* bra FUN_06042134 (linker-resolved) */
    mov.l @r15+, r14
.L_06041858:
    mov r14, r4
    .reloc ., R_SH_IND12W, FUN_06042088 - 4
    .2byte 0xA000    /* bra FUN_06042088 (linker-resolved) */
    mov.l @r15+, r14
    .2byte  0x0360
.L_06041860:
    cmp/eq #0x0, r0
    bt      .L_0604182E
    cmp/eq #0x1, r0
    bt      .L_06041834
    cmp/eq #0x2, r0
    bt      .L_0604183A
    cmp/eq #0x3, r0
    bt      .L_06041840
    cmp/eq #0x4, r0
    bt      .L_06041846
    cmp/eq #0x5, r0
    bt      .L_0604184C
    cmp/eq #0x6, r0
    bt      .L_06041852
    cmp/eq #0x7, r0
    bt      .L_06041858
    rts
    mov.l @r15+, r14

    .global sym_06041884
sym_06041884:
    .byte   0xD3, 0x08    /* mov.l .L_pool_060418A8, r3 */
    mov.l @r3, r3
    rts
    mov.l r4, @(60, r3)
