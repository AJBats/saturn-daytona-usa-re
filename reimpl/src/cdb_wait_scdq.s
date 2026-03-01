
    .section .text.FUN_060423CC


    .global cdb_wait_scdq
    .type cdb_wait_scdq, @function
cdb_wait_scdq:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_scdq_ack, r11
    mov.l   .L_pool_read_hirq, r12
    mov.l   .L_pool_scdq_clear_mask, r13
    mov.w   .L_wpool_scdq_bit_mask, r14
.L_poll_hirq:
    jsr @r12
    nop
    extu.w r0, r0
    and r14, r0
    tst r0, r0
    bt      .L_scdq_not_ready
    jsr @r11
    extu.w r13, r4
    bra     .L_epilogue
    nop
.L_scdq_not_ready:
    bra     .L_poll_hirq
    nop
.L_wpool_scdq_bit_mask:
    .2byte  0x0400                      /* [HIGH] SCDQ bit mask (HIRQ bit 10) */
    .4byte  ai_checkpoint_validate      /* [HIGH] adjacent pool: fn ptr (not used by this TU) */
    .4byte  sym_060A5400                /* [HIGH] adjacent pool: AI/game state base ptr (not used by this TU) */
.L_pool_scdq_ack:
    .4byte  smpc_cmd_helper_b
.L_pool_read_hirq:
    .4byte  sym_06035C4E
.L_pool_scdq_clear_mask:
    .4byte  0x0000FBFF
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
