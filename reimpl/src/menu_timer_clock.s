
    .section .text.FUN_0603B634


    .global menu_timer_clock
    .type menu_timer_clock, @function
menu_timer_clock:
    sts.l pr, @-r15
    mov r4, r14
    mov.l @r14, r0
    mov.b @(r0, r1), r0
    extu.b r0, r0
    tst #0x60, r0
    bf      .L_timer_inactive
    bra     .L_run_timer
    nop
.L_run_timer:
    .byte   0xBD, 0x07    /* bsr 0x0603B058 (external) */  ! call menu_element_dispatch
    mov r14, r4
    mov r0, r5
    .byte   0xD3, 0x13    /* mov.l .L_pool_0603B69C, r3 */ ! r3 = timer_stub address
    jsr @r3
    mov.l @r14, r4
    tst r0, r0
    bf      .L_timer_done
    mov #-0x14, r4
    lds.l @r15+, pr
    .byte   0xA1, 0x6F    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc with error
    mov.l @r15+, r14
.L_timer_done:
    .byte   0xD2, 0x10    /* mov.l .L_pool_0603B6A0, r2 */ ! r2 = &sym_060A4D14 (global state ptr)
    mov.l @r2, r2
    .byte   0x90, 0x19    /* mov.w .L_wpool_0603B698, r0 */ ! r0 = 0x00B8 (timer element offset)
    mov.l r14, @(r0, r2)
.L_timer_inactive:
    mov #0x0, r4
    lds.l @r15+, pr
    .byte   0xA1, 0x67    /* bra 0x0603B93C (external) */  ! tail-call save_checksum_calc with success
    mov.l @r15+, r14
    .2byte  0xD60C
    .4byte  0x63629012
    .4byte  0x03466362
    .4byte  0x70040356
    .4byte  0xA15EE400
