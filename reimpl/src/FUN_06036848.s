
    .section .text.FUN_06036848


    .global FUN_06036848
    .type FUN_06036848, @function
FUN_06036848:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x21    /* mov.l .L_pool_060368D4, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x62, r3
    extu.w r14, r14
    extu.b r12, r12
    extu.w r13, r13
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r13, r0
    mov.w r0, @(6, r3)
    .byte   0x94, 0x2E    /* mov.w .L_wpool_060368D0, r4 */
    .byte   0xD3, 0x19    /* mov.l .L_pool_060368D8, r3 */
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06036886
    .type FUN_06036886, @function
FUN_06036886:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r14
    mov.l r12, @-r15
    mov r6, r13


    .global FUN_06036890
    .type FUN_06036890, @function
FUN_06036890:
    sts.l pr, @-r15
    mov r4, r12
    add #-0x8, r15
    mov.l   .L_060368D4, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x63, r3
    extu.w r14, r14
    extu.b r12, r12
    extu.w r13, r13
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r13, r0
    mov.w r0, @(6, r3)
    mov.w   .L_060368D0, r4
    mov.l   .L_060368D8, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060368D0:
    .2byte  0x0080
    .2byte  0xFFFF
.L_060368D4:
    .4byte  FUN_06035E90
.L_060368D8:
    .4byte  FUN_06035EC8
