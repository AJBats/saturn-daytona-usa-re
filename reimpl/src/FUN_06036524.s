
    .section .text.FUN_06036524


    .global FUN_06036524
    .type FUN_06036524, @function
FUN_06036524:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    .byte   0xD3, 0x24    /* mov.l .L_pool_060365BC, r3 */
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x50, r3
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    add #0x8, r5
    mov.b r3, @r2
    .byte   0xD3, 0x20    /* mov.l .L_pool_060365C0, r3 */
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.w @(2, r2), r0
    mov r0, r3
    extu.w r3, r3
    mov.l r3, @r14
    mov r15, r3
    mov.b @(4, r3), r0
    mov r15, r3
    mov r0, r2
    extu.b r2, r2
    mov.l r2, @r12
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    mov r4, r0
    mov.l r2, @r13
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06036572
    .type FUN_06036572, @function
FUN_06036572:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14


    .global FUN_06036578
    .type FUN_06036578, @function
FUN_06036578:
    sts.l pr, @-r15
    mov r5, r13
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_060365BC, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x51, r3
    extu.b r14, r14
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r14, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    add #0x8, r2
    mov.b r0, @(4, r2)
    mov.l   .L_060365C0, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    mov r4, r0
    mov.l r3, @r13
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060365BC:
    .4byte  FUN_06035E90
.L_060365C0:
    .4byte  FUN_06035EA2
