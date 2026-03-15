
    .section .text.FUN_060088CC


    .global FUN_060088CC
    .type FUN_060088CC, @function
FUN_060088CC:
    sts.l pr, @-r15
    mov.l   .L_pool_06008910, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008914, r3
    jsr @r3
    nop
    mov #0x0, r6
    mov.l   .L_06008918, r5
    mov.l   .L_pool_0600891C, r3
    jsr @r3
    mov #0x4, r4
    mov #0x0, r6
    mov #0x2, r5
    mov.l   .L_pool_06008920, r3
    jsr @r3
    mov r5, r4
    mov.l   .L_pool_06008924, r3
    jsr @r3
    nop
    mov #0x1, r2
    mov.l   .L_pool_06008928, r3
    mov.l r2, @r3
    mov.l   .L_pool_0600892C, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06008930, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3

    .global FUN_0600890A
FUN_0600890A:
    mov.l   .L_pool_06008934, r3
    jmp @r3
    nop
.L_pool_06008910:
    .4byte  FUN_06018E70
.L_pool_06008914:
    .4byte  FUN_0601C978
.L_06008918:
    .4byte  0xFFFF0000
.L_pool_0600891C:
    .4byte  FUN_06014884
.L_pool_06008920:
    .4byte  FUN_06018DDC
.L_pool_06008924:
    .4byte  FUN_060210F6
.L_pool_06008928:
    .4byte  FUN_0605ACC4
.L_pool_0600892C:
    .4byte  sym_06026CE0
.L_pool_06008930:
    .4byte  sym_06059F44
.L_pool_06008934:
    .4byte  FUN_0601CAEE
