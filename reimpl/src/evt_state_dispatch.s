
    .section .text.FUN_06040C10


    .global evt_state_dispatch
    .type evt_state_dispatch, @function
evt_state_dispatch:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r4, @(4, r15)
    mov.l r5, @r15
    mov.l @(4, r15), r6
    mov.l @(16, r5), r5
    mov.l @r15, r4
    mov.l   .L_pool_06040C54, r3
    mov.l @(12, r6), r6
    jsr @r3
    mov.l @(4, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_update_ok
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov #0x0, r0
.L_update_ok:
    mov.l   .L_pool_06040C58, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_poll_done
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov #0x0, r0
.L_poll_done:
    mov #0x1, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop

    .global sym_06040C50
sym_06040C50:
    rts
    mov #0x0, r0
.L_pool_06040C54:
    .4byte  evt_field_update
.L_pool_06040C58:
    .4byte  state_field_read
