
    .section .text.FUN_06008B34


    .global FUN_06008B34
    .type FUN_06008B34, @function
FUN_06008B34:
    sts.l pr, @-r15
    mov.l   .L_pool_06008B70, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008B74, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008B64, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008B68, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .2byte  0xFFFF
    .4byte  FUN_06018E70
    .4byte  FUN_0605ACC4
    .4byte  FUN_060193F4
    .4byte  FUN_060210F6
.L_pool_06008B64:
    .4byte  sym_06026CE0
.L_pool_06008B68:
    .4byte  sym_06059F44
    .4byte  sym_0605A016
.L_pool_06008B70:
    .4byte  FUN_060196A4
.L_pool_06008B74:
    .4byte  FUN_0601950C
