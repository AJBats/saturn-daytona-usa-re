
    .section .text.FUN_060333F4


    .global FUN_060333F4
    .type FUN_060333F4, @function
FUN_060333F4:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033550 - 4
    .2byte 0xB000    /* bsr FUN_06033550 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD1, 0x17    /* mov.l .L_pool_0603345C, r1 */
    mov #0x8, r2
    mov.w r2, @r1


    .global FUN_06033402
    .type FUN_06033402, @function
FUN_06033402:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033648 - 4
    .2byte 0xB000    /* bsr FUN_06033648 (linker-resolved) */
    nop
    lds.l @r15+, pr

    .global FUN_0603340A
    .type FUN_0603340A, @function
FUN_0603340A:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033470 - 4
    .2byte 0xB000    /* bsr FUN_06033470 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x13    /* mov.l .L_pool_06033460, r0 */
    mov.l @r0, r0
    mov.b @r0, r0
    cmp/pl r0
    bt      .L_06033426
    .byte   0xD0, 0x11    /* mov.l .L_pool_06033464, r0 */
    mov.l @r0, r0
    mov.l @r0, r0
    cmp/pl r0
    .byte   0x89, 0x04    /* bt 0x06033430 (external) */
.L_06033426:
    .byte   0xD6, 0x10    /* mov.l .L_pool_06033468, r6 */
