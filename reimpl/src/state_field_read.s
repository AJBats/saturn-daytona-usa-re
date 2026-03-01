
    .section .text.FUN_0604188C


    .global state_field_read
    .type state_field_read, @function
state_field_read:
    sts.l pr, @-r15
    mov.l   .L_pool_060418AC, r4
    mov.l   .L_pool_060418A8, r3
    mov.l @r3, r3
    mov.l r4, @(60, r3)
.L_poll_loop:
    .byte   0xBE, 0xFF    /* bsr 0x06041698 (external) */ ! call large_prologue_save -> dma_int_handler
    nop
    cmp/eq #0x1, r0
    bt/s    .L_poll_again
    mov r0, r4
    bra     .L_clear_counter
    nop
.L_poll_again:
    bra     .L_poll_loop
    nop
.L_pool_060418A8:
    .4byte  sym_060A5400
.L_pool_060418AC:
    .4byte  0x00008000
.L_clear_counter:
    mov #0x0, r5
    .byte   0xD2, 0x2A    /* mov.l .L_pool_0604195C, r2 */ ! r2 = &sym_060A5400 (cross-TU pool ref)
    mov.l @r2, r2
    mov.l r5, @(60, r2)
    lds.l @r15+, pr
    rts
    mov r4, r0
