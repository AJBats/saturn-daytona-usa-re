
    .section .text.FUN_0602DC30


    .global FUN_0602DC30
    .type FUN_0602DC30, @function
FUN_0602DC30:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E16C - 4
    .2byte 0xA000    /* bra FUN_0602E16C (linker-resolved) */
    nop
    .4byte  sym_06082A30
    .4byte  sym_0602DC44

    .global sym_0602DC44
sym_0602DC44:
    .4byte  FUN_0602DC58
    .4byte  FUN_0602DD10
    .4byte  FUN_0602DE60
    .4byte  FUN_0602E078
    .4byte  FUN_0602E108

    .global FUN_0602DC58
FUN_0602DC58:
    .byte   0xD1, 0x10    /* mov.l .L_pool_0602DC9C, r1 */
    mov.l @r1, r3
    add #0x1, r3
    mov.l r3, @r1
    .byte   0xD4, 0x0F    /* mov.l .L_pool_0602DCA0, r4 */
    cmp/eq r3, r4
    .byte   0x8B, 0x08    /* bf 0x0602DC78 (external) */
    .byte   0xDD, 0x0F    /* mov.l .L_pool_0602DCA4, r13 */
