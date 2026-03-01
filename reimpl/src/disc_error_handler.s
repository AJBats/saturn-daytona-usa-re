
    .section .text.FUN_0601B4D6


    .global disc_error_handler
    .type disc_error_handler, @function
disc_error_handler:
    sts.l pr, @-r15
    .byte   0xD3, 0x12    /* mov.l .L_cd_status, r3 */
    mov.w @r3, r2
    mov.w   .L_err_mask_fatal, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_check_recoverable
    mov #0x1, r3
    .byte   0xD2, 0x0F    /* mov.l .L_error_flag, r2 */
    mov.b r3, @r2
    .byte   0xD3, 0x0F    /* mov.l .L_fn_init_reset, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x0080                      /* padding */
.L_err_mask_fatal:
    .2byte  0x0100                      /* CD status bit 8: fatal disc error */
    .2byte  0xFFFF
    .4byte  sym_060485EC
    .4byte  0x25F00020
    .4byte  memcpy_word_idx
    .4byte  sym_060485CC
    .4byte  0x25F00180
    .4byte  sym_06028560
    .4byte  sym_0602853E
    .4byte  sym_060638C8
    .4byte  0x0000C000
    .4byte  sym_06028400
    .4byte  sym_0608600D
.L_cd_status:
    .4byte  sym_06063D9A               /* CD block status word (16-bit) */
.L_error_flag:
    .4byte  sym_0608600C               /* disc error flag (byte) */
.L_fn_init_reset:
    .4byte  handler_init_reset         /* system reset handler */
.L_check_recoverable:
    .byte   0xB1, 0x60    /* bsr 0x0601B7F4 */
    nop
    .byte   0xB0, 0xD2    /* bsr 0x0601B6DC */
    nop
    .byte   0xD2, 0x0D    /* mov.l .L_cd_status_2, r2 */
    mov.w @r2, r3
    mov.w   .L_err_mask_recov, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_return
    .byte   0xD0, 0x0B    /* mov.l .L_disc_type, r0 */
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bf      .L_wrong_disc
    mov #0x1, r2
    .byte   0xD3, 0x09    /* mov.l .L_error_flag_2, r3 */
    mov.b r2, @r3
    .byte   0xD3, 0x09    /* mov.l .L_fn_init_reset_2, r3 */
    jmp @r3
    lds.l @r15+, pr
.L_wrong_disc:
    mov #0x2, r2
    .byte   0xD3, 0x08    /* mov.l .L_error_code, r3 */
    mov.b r2, @r3
.L_return:
    lds.l @r15+, pr
    rts
    nop

    .global loc_0601B566
loc_0601B566:
    mov #0x3, r3
    .byte   0xD2, 0x05    /* mov.l .L_error_code, r2 */
    rts
    mov.b r3, @r2
.L_err_mask_recov:
    .2byte  0x0E00                      /* CD status bits 11:9: recoverable errors */
.L_cd_status_2:
    .4byte  sym_06063D9A               /* CD block status word (16-bit) */
.L_disc_type:
    .4byte  sym_0608600E               /* disc type: 2 = game disc */
.L_error_flag_2:
    .4byte  sym_0608600C               /* disc error flag (byte) */
.L_fn_init_reset_2:
    .4byte  handler_init_reset         /* system reset handler */
.L_error_code:
    .4byte  sym_0608600D               /* error code: 0=none, 1=fatal, 2=wrong, 3=removed */
