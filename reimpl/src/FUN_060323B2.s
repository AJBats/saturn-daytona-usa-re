
    .section .text.FUN_060323B2


    .global FUN_060323B2
    .type FUN_060323B2, @function
FUN_060323B2:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032E18 - 4
    .2byte 0xB000    /* bsr FUN_06032E18 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    nop
    .2byte  0x0000
    .4byte  0x0000000E
    .4byte  0x00000003
    .4byte  0x000002D0

    .global FUN_060323CC
FUN_060323CC:
    .byte   0xD0, 0x03    /* mov.l .L_pool_060323DC, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x03    /* mov.l .L_pool_060323E0, r2 */
    or r2, r1
    mov.w r1, @(r0, r14)
    .reloc ., R_SH_IND12W, FUN_0603230A - 4
    .2byte 0xA000    /* bra FUN_0603230A (linker-resolved) */
    nop
    .2byte  0x0000
.L_pool_060323DC:
    .4byte  0x0000000E
.L_pool_060323E0:
    .4byte  0x00000001
