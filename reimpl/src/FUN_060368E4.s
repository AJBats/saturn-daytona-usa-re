
    .section .text.FUN_060368E4


    .global FUN_060368E4
    .type FUN_060368E4, @function
FUN_060368E4:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06036974, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x64, r3
    extu.b r14, r14
    extu.w r13, r13
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(4, r2)
    mov r13, r0
    mov.w r0, @(6, r3)
    .byte   0x94, 0x34    /* mov.w .L_wpool_06036970, r4 */
    mov.l   .L_06036978, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06036918
    .type FUN_06036918, @function
FUN_06036918:
    mov.l r14, @-r15
    mov r7, r14
    mov.l r13, @-r15
    mov r4, r13
    mov.l r12, @-r15
    mov r6, r12
    mov.l r11, @-r15
    mov r5, r11

    .global FUN_06036928
    .type FUN_06036928, @function
FUN_06036928:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06036974, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x65, r3
    extu.b r14, r14
    extu.w r11, r11
    extu.b r13, r13
    extu.w r12, r12
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r11, r0
    mov.w r0, @(2, r3)
    mov r15, r3
    mov r13, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r12, r0
    mov.w r0, @(6, r3)
    mov.w   .L_06036972, r4
    mov.l   .L_06036978, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x0080
.L_06036972:
    .2byte  0x0100                      /* [MEDIUM] command parameter mask — 0x100 (cf. 0x0080 in FUN_06036890, 0x0200 in FUN_06036BA6) */
.L_06036974:
    .4byte  FUN_06035E90
.L_06036978:
    .4byte  FUN_06035EC8          /* [HIGH] fn ptr: SMPC digital button reader / command dispatcher */
