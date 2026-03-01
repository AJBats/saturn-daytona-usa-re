
    .section .text.FUN_0603B93C


    .global save_checksum_calc
    .type save_checksum_calc, @function
save_checksum_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r13
    mov.l   .L_pool_game_state_ptr, r14
    mov.w   .L_wpool_notify_struct_offset, r3
    mov.l @r14, r14
    add r3, r14
    tst r13, r13
    bt/s    .L_epilogue
    mov.l r4, @(8, r14)
    mov.l @r14, r0
    tst r0, r0
    bt      .L_epilogue
    mov r13, r5
    mov.l @r14, r3
    jsr @r3
    mov.l @(4, r14), r4
.L_epilogue:
    mov r13, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xD607
    .4byte  0x66627634
    .4byte  0xA00DE500
    .4byte  0x62536363
    .4byte  0x4208323C
    .4byte  0x62223420
    .4byte  0x8B04A008
    .2byte  0x0009
.L_wpool_notify_struct_offset:
    .2byte  0x00B8                      /* [HIGH] notification sub-struct offset within game state */
.L_pool_game_state_ptr:
    .4byte  sym_060A4D14
    .4byte  0x7501E060
    .4byte  0x026E3523
    .4byte  0x8BEEE060
    .4byte  0x026E3520
    .4byte  0x8B00E5FF
    .4byte  0x000B6053
