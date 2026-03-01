
    .section .text.FUN_06035CBC


    .global smpc_secondary_proc
    .type smpc_secondary_proc, @function
smpc_secondary_proc:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov r5, r12
    add #-0x4, r15
    mov.l   .L_pool_cd_fifo_addr, r13
    mov.l   .L_pool_fn_setup, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    tst r4, r4
    bt      .L_setup_ok
    bra     .L_epilogue
    mov r4, r0
    .4byte  0x2589000C
    .4byte  0x25818028
.L_pool_cd_fifo_addr:
    .4byte  0x25898000
.L_pool_fn_setup:
    .4byte  ai_brake_zone_adjust
.L_setup_ok:
    mov r12, r4
    cmp/pl r14
    bf/s    .L_copy_done
    mov #0x0, r5
.L_copy_loop:
    mov.w @r13, r2
    add #0x1, r5
    mov.w r2, @r4
    cmp/ge r14, r5
    bf/s    .L_copy_loop
    add #0x2, r4
.L_copy_done:
    .byte   0xD3, 0x22    /* mov.l .L_pool_06035D8C, r3 */  ! r3 = &ai_brake_zone_main (cross-TU pool)
    jsr @r3
    mov r15, r4
    mov r0, r4
    tst r4, r4
    bf      .L_return_result
    mov.l @r15, r3
    cmp/eq r3, r14
    bt      .L_return_result
    mov #-0x7, r4
.L_return_result:
    mov r4, r0
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
