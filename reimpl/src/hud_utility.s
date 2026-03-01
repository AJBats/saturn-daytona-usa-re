
    .section .text.FUN_0601E6A4


    .global hud_utility
    .type hud_utility, @function
hud_utility:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov #0xA, r12
    mov.l   .L_pool_0601E6DC, r13
    mov.l r4, @r15
    mov #0x0, r14
.L_poll_loop:
    mov.l @r13, r3
    mov.l @(8, r3), r2
    jsr @r2
    mov.l @r15, r4
    mov r0, r4
    tst r4, r4
    bf      .L_retry
    bra     .L_epilogue
    mov #0x0, r0
.L_retry:
    add #0x1, r14
    cmp/ge r12, r14
    bf      .L_poll_loop
    mov r4, r0
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_0601E6DC:
    .4byte  sym_06000354
