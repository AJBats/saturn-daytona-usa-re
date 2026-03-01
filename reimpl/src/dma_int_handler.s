
    .section .text.FUN_060416A8


    .global dma_int_handler
    .type dma_int_handler, @function
dma_int_handler:
    sts.l pr, @-r15
    mov #0x0, r9
    add #-0x14, r15
    mov.l   .L_state_base_ptr, r13
    mov.l r9, @r15
    mov.l @r13, r3
    mov.l @(60, r3), r0
    tst r0, r0
    bt/s    .L_check_cd_status
    mov r9, r12
    mov.l @r13, r3
    mov.l @(60, r3), r2
    add #-0x1, r2
    mov.l r2, @(60, r3)
    cmp/pl r2
    bt      .L_check_cd_status
    .byte   0xB6, 0x29    /* bsr 0x0604231E (external) */
    nop
    bra     .L_epilogue
    mov #0x3, r0
.L_check_cd_status:
    mov.w   .L_csct_bit_mask, r2
    mov.l   .L_fn_read_cd_status, r3
    jsr @r3
    mov.l r2, @(4, r15)
    mov r0, r4
    mov.l @(4, r15), r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_csct_not_set
    bra     .L_csct_is_set
    mov #0x1, r5
.L_csct_not_set:
    mov #0x0, r5
.L_csct_is_set:
    mov r5, r0
    cmp/eq #0x1, r0
    bf      .L_no_csct_path
    mov.l   .L_csct_ack_mask, r4
    mov.l   .L_fn_ack_cd_irq, r3
    jsr @r3
    nop
    mov r15, r4
    mov.l   .L_fn_checkpoint_section, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov.l   .L_fn_memcpy_long, r3
    mov.l @r13, r1
    add #0x8, r2
    add #0x40, r1
    jsr @r3
    mov #0xC, r0
    mov.l @r13, r2
    mov #0x4C, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_begin_event_loop
    mov.l @r13, r3
    mov #0x4C, r0
    mov r3, r4
    mov.l @(r0, r3), r2
    mov #0x50, r0
    jsr @r2
    mov.l @(r0, r4), r4
    bra     .L_begin_event_loop
    nop
.L_csct_bit_mask:
    .2byte  0x0400
    .4byte  ai_checkpoint_validate
.L_state_base_ptr:
    .4byte  sym_060A5400
.L_fn_read_cd_status:
    .4byte  sym_06035C4E
.L_csct_ack_mask:
    .4byte  0x0000FBFF
.L_fn_ack_cd_irq:
    .4byte  smpc_cmd_helper_b
.L_fn_checkpoint_section:
    .4byte  ai_checkpoint_section
.L_fn_memcpy_long:
    .4byte  sym_06035168
.L_no_csct_path:
    mov r15, r4
    mov.l   .L_fn_section_transition, r3
    jsr @r3
    add #0x8, r4
    mov r0, r4
    tst r4, r4
    bf      .L_begin_event_loop
    mov.l @r13, r1
    mov r15, r2
    mov.l   .L_fn_memcpy_long_2, r3
    add #0x40, r1
    add #0x8, r2
    jsr @r3
    mov #0xC, r0
.L_begin_event_loop:
    bra     .L_event_loop_test
    mov r9, r14
.L_event_loop_body:
    bsr     .L_resolve_event_channel
    mov r14, r4
    tst r0, r0
    bt      .L_dispatch_callback
    bra     .L_next_channel
    nop
.L_dispatch_callback:
    mov r15, r5
    .byte   0xB0, 0x56    /* bsr 0x06041826 (external) */
    mov r14, r4
    add r0, r12
    mov.l @r15, r2
    cmp/gt r10, r2
    bf      .L_next_channel
    bra     .L_epilogue
    mov #0x1, r0
.L_next_channel:
    add #0x1, r14
.L_event_loop_test:
    cmp/ge r11, r14
    bf      .L_event_loop_body
    cmp/pl r12
    bf      .L_no_events
    bra     .L_epilogue
    mov #0x1, r0
.L_no_events:
    mov #0x0, r0
.L_epilogue:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_resolve_event_channel:
    mov.l   .L_state_base_ptr_2, r5
    bra     .L_switch_index
    mov r4, r0
.L_case_0:
    mov.l @r5, r4
    bra     .L_load_callback_ptr
    mov #0x58, r0
.L_case_1:
    mov.w   DAT_060417d8, r0
    bra     .L_load_callback_ptr
    mov.l @r5, r4
.L_case_2:
    mov.w   DAT_060417da, r0
    bra     .L_load_callback_ptr
    mov.l @r5, r4
.L_case_3:
    mov.w   .L_off_chan3, r0
    bra     .L_load_callback_ptr
    mov.l @r5, r4
.L_case_4:
    mov.w   .L_off_chan4, r0
    bra     .L_load_callback_ptr
    mov.l @r5, r4
.L_case_5:
    mov.w   .L_off_chan5, r0
    bra     .L_load_callback_ptr
    mov.l @r5, r4
.L_case_6:
    mov.w   .L_off_chan6, r0
    bra     .L_load_callback_ptr
    mov.l @r5, r4

    .global DAT_060417d8
DAT_060417d8:
    .2byte  0x0304

    .global DAT_060417da
DAT_060417da:
    .2byte  0x030C
.L_off_chan3:
    .2byte  0x0328
.L_off_chan4:
    .2byte  0x0338
.L_off_chan5:
    .2byte  0x0348
.L_off_chan6:
    .2byte  0x01E0
.L_fn_section_transition:
    .4byte  cd_block_read_safe
.L_fn_memcpy_long_2:
    .4byte  sym_06035168
.L_state_base_ptr_2:
    .4byte  sym_060A5400
.L_case_7:
    mov.l @r5, r4
    .byte   0x90, 0x34    /* mov.w .L_wpool_0604185E, r0 */
.L_load_callback_ptr:
    bra     .L_check_null
    mov.l @(r0, r4), r4
.L_switch_index:
    cmp/eq #0x0, r0
    bt      .L_case_0
    cmp/eq #0x1, r0
    bt      .L_case_1
    cmp/eq #0x2, r0
    bt      .L_case_2
    cmp/eq #0x3, r0
    bt      .L_case_3
    cmp/eq #0x4, r0
    bt      .L_case_4
    cmp/eq #0x5, r0
    bt      .L_case_5
    cmp/eq #0x6, r0
    bt      .L_case_6
    cmp/eq #0x7, r0
    bt      .L_case_7
.L_check_null:
    tst r4, r4
    bf      .L_has_callback
    bra     .L_resolve_return
    mov #0x1, r0
.L_has_callback:
    mov #0x0, r0
.L_resolve_return:
    rts
    nop
