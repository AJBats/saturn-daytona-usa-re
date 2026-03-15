
    .section .text.FUN_060333A4


    .global FUN_060333A4
    .type FUN_060333A4, @function
FUN_060333A4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    rts
    nop
    .4byte  0x07E00000
    .4byte  sym_060338DC
    .4byte  sym_06033868
    .4byte  sym_060338E8
    .4byte  sym_06062D95
    .4byte  sym_060338F4
    .4byte  sym_060430CE
    .4byte  sym_060629AC
    .4byte  FUN_0602761E
    .4byte  0x25E03700

    .global sym_060333D8
sym_060333D8:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
