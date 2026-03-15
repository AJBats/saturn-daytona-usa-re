
    .section .text.FUN_060361BC


    .global FUN_060361BC
    .type FUN_060361BC, @function
FUN_060361BC:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_060361F4, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x32, r3
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    add #0x8, r5
    mov.b r3, @r2
    mov.l   .L_060361F8, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.b @(4, r2), r0
    mov r0, r3
    extu.b r3, r3
    mov r4, r0
    mov.l r3, @r14
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_060361F4:
    .4byte  FUN_06035E90
.L_060361F8:
    .4byte  FUN_06035EA2
