
    .section .text.FUN_06032530


    .global FUN_06032530
    .type FUN_06032530, @function
FUN_06032530:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032EA4 - 4
    .2byte 0xB000    /* bsr FUN_06032EA4 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .global FUN_06032538
FUN_06032538:
    rts
    nop
    .global FUN_0603253C
FUN_0603253C:
    .4byte  0xD0026100
    .4byte  0x21188B03
    .4byte  0x000B0009
    .4byte  sym_06082A24
    .4byte  0xD00707ED
    .4byte  0xD607D208
    .4byte  0x27288900
    .4byte  0xD607D205
    .4byte  0x27288900
    .4byte  0xD606D007
    .4byte  0x01EE316C
    .4byte  0x000B0E16
    .4byte  0x0000000E
    .4byte  0x00000001
    .4byte  0x00000002
    .4byte  0xFFFFFFFF
    .4byte  0x00000000
    .4byte  0x000002C4
    .global FUN_06032584
FUN_06032584:
    .2byte  0xD010


    .global FUN_06032586
    .type FUN_06032586, @function
FUN_06032586:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x0F    /* mov.l .L_pool_060325CC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D0, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D4, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D8, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325DC, r0 */
