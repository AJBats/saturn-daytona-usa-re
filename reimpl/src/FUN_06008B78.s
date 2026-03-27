
    .section .text.FUN_06008B78


    .global FUN_06008B78
    .type FUN_06008B78, @function
FUN_06008B78:
    sts.l pr, @-r15
    mov #0x9, r3
    .byte   0xD2, 0x0F    /* mov.l .L_pool_06008BBC, r2 */
    mov.l r3, @r2
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06008BC0, r3 */
    jsr @r3
    nop
    mov.l   .L_pool_06008BC4, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008BC8, r3
    mov.l r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0D    /* mov.l .L_pool_06008BCC, r3 */
    lds.l @r15+, pr
    rts
    mov.w r2, @r3


    .global FUN_06008B9C
    .type FUN_06008B9C, @function
FUN_06008B9C:
    sts.l pr, @-r15
    mov.l   .L_pool_06008BD0, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008BD4, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008BC4, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008BC8, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3
    .2byte  0xFFFF
    .4byte  FUN_0605ACC4
    .4byte  FUN_060198E0
.L_pool_06008BC4:
    .4byte  sym_06026CE0
.L_pool_06008BC8:
    .4byte  sym_06059F44
    .4byte  sym_0605A016
.L_pool_06008BD0:
    .4byte  FUN_06019A48
.L_pool_06008BD4:
    .4byte  FUN_06019928
