
    .section .text.FUN_06036A24


    .global FUN_06036A24
    .type FUN_06036A24, @function
FUN_06036A24:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06036A90, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x70, r3
    extu.b r13, r13
    mov.b r3, @r2
    mov r13, r0
    mov r15, r2
    mov r15, r3
    mov.l r14, @(4, r2)
    mov.b r0, @(4, r3)
    mov.w   .L_06036A8C, r4
    mov.l   .L_06036A94, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06036A54
    .type FUN_06036A54, @function
FUN_06036A54:
    mov.l r14, @-r15
    mov r5, r14
    mov.l r13, @-r15
    mov r4, r13

    .global FUN_06036A5C
    .type FUN_06036A5C, @function
FUN_06036A5C:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06036A90, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x71, r3
    extu.b r13, r13
    mov.b r3, @r2
    mov r13, r0
    mov r15, r2
    mov r15, r3
    mov.l r14, @(4, r2)
    mov.b r0, @(4, r3)
    mov.w   .L_06036A8C, r4
    mov.l   .L_06036A94, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06036A8C:
    .2byte  0x0200
    .2byte  0xFFFF                      /* alignment padding between word and longword pools */
.L_06036A90:
    .4byte  FUN_06035E90           /* [HIGH] -> SMPC analog axis reader / command struct initializer */
.L_06036A94:
    .4byte  FUN_06035EC8          /* [HIGH] -> SMPC digital button reader / command dispatcher */
