
    .section .text.FUN_06008B04


    .global FUN_06008B04
    .type FUN_06008B04, @function
FUN_06008B04:
    sts.l pr, @-r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_06008B54, r3 */
    jsr @r3
    nop
    mov #0x7, r2
    .byte   0xD3, 0x12    /* mov.l .L_pool_06008B58, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x12    /* mov.l .L_pool_06008B5C, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l .L_pool_06008B60, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x11    /* mov.l .L_pool_06008B64, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x10    /* mov.l .L_pool_06008B68, r3 */
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06008B6C, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3


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
