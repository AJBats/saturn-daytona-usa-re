
    .section .text.FUN_0600DF66


    .global FUN_0600DF66
    .type FUN_0600DF66, @function
FUN_0600DF66:
    sts.l pr, @-r15
    .byte   0xD3, 0x12    /* mov.l .L_pool_0600DFB7, r3 */
    mov.l @r3, r3
    shar r3
    exts.w r3, r3
    .byte   0xD2, 0x11    /* mov.l .L_pool_0600DFBB, r2 */
    mov.w r3, @r2
    .byte   0xD0, 0x11    /* mov.l .L_pool_0600DFBF, r0 */
    bra     .L_0600DFC0
    mov.b @r0, r0

.L_0600DF7A:
    .reloc ., R_SH_IND12W, FUN_0600E410 - 4
    .2byte 0xB000    /* bsr FUN_0600E410 (linker-resolved) */
    nop
    bra     .L_0600DFCC
    nop

.L_0600DF82:
    .reloc ., R_SH_IND12W, FUN_0600E47C - 4
    .2byte 0xB000    /* bsr FUN_0600E47C (linker-resolved) */
    nop
    bra     .L_0600DFCC
    nop

.L_0600DF8A:
    .reloc ., R_SH_IND12W, FUN_0600E47C - 4
    .2byte 0xB000    /* bsr FUN_0600E47C (linker-resolved) */
    nop
    bra     .L_0600DFCC
    nop

    .2byte  0xFFFF
    .4byte  sym_06078635
    .4byte  sym_06063EF0
    .4byte  sym_06078634
    .4byte  sym_0600A8BC
    .4byte  sym_06083255
    .4byte  FUN_06034900
    .4byte  FUN_0602F7EA
    .4byte  FUN_0602F99C

.L_pool_0600DFB7:
    .4byte  sym_0607EA98
.L_pool_0600DFBB:
    .4byte  sym_060786CA
.L_pool_0600DFBF:
    .4byte  sym_06083261

.L_0600DFC0:
    cmp/eq #0x0, r0
    bt      .L_0600DF7A
    cmp/eq #0x1, r0
    bt      .L_0600DF82
    cmp/eq #0x2, r0
    bt      .L_0600DF8A

.L_0600DFCC:
    .reloc ., R_SH_IND12W, FUN_0600E0C0 - 4
    .2byte 0xA000    /* bra FUN_0600E0C0 (linker-resolved) */
    lds.l @r15+, pr
