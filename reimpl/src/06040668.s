
    .section .text.FUN_06040668


    .global sys_timer_init
    .type sys_timer_init, @function
sys_timer_init:
    sts.l pr, @-r15
    .byte   0xBF, 0xA5    /* bsr 0x060405B8 (external) */
    mov r5, r4
    tst r0, r0
    bf      .L_06040678
    lds.l @r15+, pr
    rts
    mov #0x1, r0
.L_06040678:
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop
