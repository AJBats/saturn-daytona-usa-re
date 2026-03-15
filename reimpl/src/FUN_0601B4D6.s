
    .section .text.FUN_0601B4D6


    .global FUN_0601B4D6
    .type FUN_0601B4D6, @function
FUN_0601B4D6:
    sts.l pr, @-r15
    .byte   0xD3, 0x12    /* mov.l .L_0601B524, r3 */
    mov.w @r3, r2
    mov.w   .L_0601B4F4, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601B530
    mov #0x1, r3
    .byte   0xD2, 0x0F    /* mov.l .L_0601B528, r2 */
    mov.b r3, @r2
    .byte   0xD3, 0x0F    /* mov.l .L_0601B52C, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x0080
.L_0601B4F4:
    .2byte  0x0100
    .2byte  0xFFFF
    .4byte  sym_060485EC
    .4byte  0x25F00020
    .4byte  FUN_0602761E
    .4byte  sym_060485CC
    .4byte  0x25F00180
    .4byte  sym_06028560
    .4byte  sym_0602853E
    .4byte  sym_060638C8
    .4byte  0x0000C000
    .4byte  sym_06028400
    .4byte  sym_0608600D
.L_0601B524:
    .4byte  sym_06063D9A
.L_0601B528:
    .4byte  sym_0608600C
.L_0601B52C:
    .4byte  FUN_06018E70
.L_0601B530:
    .reloc ., R_SH_IND12W, FUN_0601B7F4 - 4
    .2byte 0xB000    /* bsr FUN_0601B7F4 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, FUN_0601B6DC - 4
    .2byte 0xB000    /* bsr FUN_0601B6DC (linker-resolved) */
    nop
    .byte   0xD2, 0x0D    /* mov.l .L_0601B570, r2 */
    mov.w @r2, r3
    mov.w   .L_0601B56E, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601B560
    .byte   0xD0, 0x0B    /* mov.l .L_0601B574, r0 */
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bf      .L_0601B55A
    mov #0x1, r2
    .byte   0xD3, 0x09    /* mov.l .L_0601B578, r3 */
    mov.b r2, @r3
    .byte   0xD3, 0x09    /* mov.l .L_0601B57C, r3 */
    jmp @r3
    lds.l @r15+, pr
.L_0601B55A:
    mov #0x2, r2
    .byte   0xD3, 0x08    /* mov.l .L_0601B580, r3 */
    mov.b r2, @r3
.L_0601B560:
    lds.l @r15+, pr
    rts
    nop

    .global FUN_0601B566
FUN_0601B566:
    mov #0x3, r3
    .byte   0xD2, 0x05    /* mov.l .L_0601B580, r2 */
    rts
    mov.b r3, @r2
.L_0601B56E:
    .2byte  0x0E00
.L_0601B570:
    .4byte  sym_06063D9A
.L_0601B574:
    .4byte  sym_0608600E
.L_0601B578:
    .4byte  sym_0608600C
.L_0601B57C:
    .4byte  FUN_06018E70
.L_0601B580:
    .4byte  sym_0608600D
