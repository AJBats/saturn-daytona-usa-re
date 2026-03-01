
    .section .text.FUN_06041258


    .global ai_brake_handler
    .type ai_brake_handler, @function
ai_brake_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_pool_06041290, r14
    mov.l @r14, r3
    mov.l @(52, r3), r0
    tst r0, r0
    bf      .L_brake_zone_active
    mov #-0x7, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_brake_zone_active:
    mov.l   .L_pool_06041294, r3
    jsr @r3
    nop
    mov r0, r4
    mov #0x0, r3
    mov.l @r14, r2
    tst r4, r4
    bt/s    .L_brake_calc
    mov.l r3, @(52, r2)
    mov #-0xA, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x0328
.L_pool_06041290:
    .4byte  sym_060A5400
.L_pool_06041294:
    .4byte  ai_brake_zone_main
.L_brake_calc:
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06041308, r3 */
    jsr @r3
    mov r15, r4
    mov.l @r14, r2
    mov r15, r3
    mov.b @r3, r1
    mov #0x40, r0
    mov.b r1, @(r0, r2)
    mov #0x0, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
