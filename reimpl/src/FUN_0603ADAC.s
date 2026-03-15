
    .section .text.FUN_0603ADAC


    .global FUN_0603ADAC
    .type FUN_0603ADAC, @function
FUN_0603ADAC:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603ADEC, r5
    mov.w   .L_0603ADDA, r3
    mov.l @r5, r14
    tst r4, r4
    bf/s    .L_0603ADF0
    add r3, r14
    mov.l @r5, r3
    mov.w   .L_0603ADDC, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_0603ADCE
    mov #-0x7, r4
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
.L_0603ADCE:
    mov #0x0, r4
    mov.l r4, @(8, r14)
    mov.l r4, @(12, r14)
    mov r4, r2
    bra     .L_0603AE00
    mov.l r4, @(4, r14)
.L_0603ADDA:
    .2byte  0x0098
.L_0603ADDC:
    .2byte  0x00A0
    .2byte  0x00F4
    .4byte  sym_0603F1E0
    .4byte  sym_0603F1F0
    .4byte  FUN_0603F0FC
.L_pool_0603ADEC:
    .4byte  sym_060A4D14
.L_0603ADF0:
    mov r14, r1
    mov r4, r2
    .byte   0xD3, 0x1C    /* mov.l pool_memcpy_long@0x0603AE68, r3 */
    jsr @r3
    mov #0xC, r0
    .reloc ., R_SH_IND12W, FUN_0603B7C0 - 4
    .2byte 0xB000    /* bsr FUN_0603B7C0 (linker-resolved) */
    nop
    mov.l r0, @(12, r14)
.L_0603AE00:
    mov #0x0, r4
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603B93C - 4
    .2byte 0xA000    /* bra FUN_0603B93C (linker-resolved) */
    mov.l @r15+, r14
