
    .section .text.FUN_0603B392


    .global menu_toggle_switch
    .type menu_toggle_switch, @function
menu_toggle_switch:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l r4, @r15
    .byte   0xB2, 0xD0    /* bsr 0x0603B93C (external) */
    mov #0x0, r4
    mov.l @r15, r2
    mov #0x12, r0
    mov.b @(r0, r2), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0603B3BC
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov #0x1, r0
    .4byte  sym_0603F9DA
    .4byte  sym_0603EF54
    .4byte  race_timer_sync
.L_0603B3BC:
    mov #0x0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
    .2byte  0xE300
    .2byte  0xE012
