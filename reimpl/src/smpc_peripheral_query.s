
    .section .text.FUN_06035D5A

    .global smpc_peripheral_query
    .type smpc_peripheral_query, @function
smpc_peripheral_query:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r5, r13
    mov.l r12, @-r15
    mov r4, r12
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x4, r15

    .byte   0xDE, 0x09    /* mov.l .L_hirq_status_cache, r14 */
    .byte   0xD3, 0x09    /* mov.l .L_cd_hirq_reg, r3 */
    mov.w @r14, r2
    mov.w @r3, r3
    extu.w r3, r3
    or r3, r2
    mov.w r2, @r14

    mov.w @r14, r3
    extu.w r3, r3
    and r12, r3
    cmp/eq r12, r3
    bt/s    .L_hirq_bits_ready
    mov r6, r11
    bra     .L_epilogue_return
    mov #-0x1, r0

    .4byte  0xFF0FFFFF
    .4byte  ai_brake_zone_main
.L_hirq_status_cache:
    .4byte  sym_06063590
.L_cd_hirq_reg:
    .4byte  0x25890008

.L_hirq_bits_ready:
    mov.w @r14, r0
    extu.w r0, r0
    tst #0x1, r0
    bf      .L_not_busy
    bra     .L_epilogue_return
    mov #-0x2, r0

.L_not_busy:
    mov #0x1, r4
    or r12, r4
    not r4, r4
    .byte   0xBF, 0x60    /* bsr sym_06035C6E (smpc_cmd_helper_b: write HIRQ) */
    extu.w r4, r4

    mov #-0x2, r2
    mov.w @r14, r3
    and r2, r3
    mov.w r3, @r14

    .byte   0xB0, 0x41    /* bsr 0x06035E3C (CD command issue helper) */
    mov r13, r4

    mov r15, r5
    .byte   0xB0, 0x20    /* bsr input_proc_init (poll HIRQ for response) */
    mov #0x1, r4

    mov r0, r13
    tst r13, r13
    bt      .L_validate_response
    bra     .L_epilogue_return
    mov r13, r0

.L_validate_response:
    .byte   0xB0, 0x48    /* bsr sym_06035E5E (read CD command registers into buffer) */
    mov r11, r4

    mov.b @r11, r4
    .byte   0x93, 0x27    /* mov.w .L_wpool_06035E22, r3 */
    extu.b r4, r2
    cmp/eq r3, r2
    bf      .L_check_error_bit
    bra     .L_check_clear_hirq
    mov #-0x5, r13

.L_check_error_bit:
    extu.b r4, r0
    tst #0x80, r0
    bt      .L_check_clear_hirq
    mov #-0x6, r13

.L_check_clear_hirq:
    tst r13, r13
    bf      .L_set_return_value
    not r12, r12
    mov.w @r14, r3
    and r12, r3
    mov.w r3, @r14

.L_set_return_value:
    mov r13, r0
.L_epilogue_return:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
