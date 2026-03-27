
    .section .text.FUN_06033428


    .global FUN_06033428
    .type FUN_06033428, @function
FUN_06033428:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033700 - 4
    .2byte 0xB000    /* bsr FUN_06033700 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD6, 0x0E    /* mov.l .L_pool_0603346C, r6 */


    .global FUN_06033432
    .type FUN_06033432, @function
FUN_06033432:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033700 - 4
    .2byte 0xB000    /* bsr FUN_06033700 (linker-resolved) */
    nop
    lds.l @r15+, pr

    .global FUN_0603343A
    .type FUN_0603343A, @function
FUN_0603343A:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603307C - 4
    .2byte 0xB000    /* bsr FUN_0603307C (linker-resolved) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    rts
    nop
    .4byte  sym_06033870
    .4byte  sym_060629AA
    .4byte  sym_0606299A
    .4byte  sym_06033880
    .4byte  sym_06033864
    .4byte  sym_0606298C
    .4byte  sym_0606299C
    .global FUN_06033470
FUN_06033470:
    .4byte  0xD31DE100
    .4byte  0xD01D6002
    .4byte  0x61024108
    .4byte  0x4100331C
    .4byte  0x61356235
    .4byte  0xD41AE000
    .4byte  0x14007001
    .4byte  0x8044D019
    .4byte  0x60026002
    .4byte  0x40094009
    .4byte  0x40098045
    .4byte  0xE00E8143
    .4byte  0x60136535
    .4byte  0x351CD614
    .4byte  0x66626660
    .4byte  0x46158B01
    .4byte  0x60536513
    .4byte  0x8144814A
    .4byte  0x60538146
    .4byte  0x81486023
    .4byte  0x81458147
    .4byte  0x6035302C
    .4byte  0x8149814B
    .4byte  0xD50B6552
    .2byte  0xD00B

    .global FUN_060334D2
    .type FUN_060334D2, @function
FUN_060334D2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr

    .global FUN_060334DA
    .type FUN_060334DA, @function
FUN_060334DA:
    sts.l pr, @-r15
    bsr     .L_06033504
    nop
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0000
    .4byte  sym_060338C4
    .4byte  sym_06033874
    .4byte  sym_06062970
    .4byte  sym_0603387C
    .4byte  sym_06033884
    .4byte  sym_060785FC
    .4byte  sym_060280F8
    .global FUN_06033504
FUN_06033504:
.L_06033504:
    mov.l   .L_pool_0603351A, r0
    mov.l @r0, r1
    add #0x1, r1
    mov.l r1, @r0
    mov.l   .L_pool_0603351E, r2
    mov.l @r2, r1
    add #0x20, r1
    mov.l r1, @r2
    rts
    nop
.L_pool_0603351A:
    .4byte  sym_0605A008
.L_pool_0603351E:
    .4byte  sym_060785FC
    .global FUN_06033520
FUN_06033520:
    .4byte  0x2F06D409
    .4byte  0x60238143
    .4byte  0xD0081400
    .4byte  0x70018044
    .4byte  0xD0D26002
    .4byte  0x40094009
    .4byte  0x40098045
    .4byte  0xE016340C
    .4byte  0x60F6A15B
    .4byte  0x00090000
    .4byte  sym_06062970
    .4byte  0x00000000
    .global FUN_06033550
FUN_06033550:
    .4byte  0x2F06D0C8
    .4byte  0x60024008
    .4byte  0xD51F350C
    .4byte  0x655260F6
    .4byte  0x2F06D21E
    .4byte  0x032ED21E
    .4byte  0x042E334C
    .4byte  0xD21D042E
    .4byte  0x334C623B
    .4byte  0x325C2126
