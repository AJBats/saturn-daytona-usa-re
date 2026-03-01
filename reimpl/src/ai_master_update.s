
    .section .text.FUN_06036BA6


    .global ai_master_update
    .type ai_master_update, @function
ai_master_update:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x0B    /* mov.l .L_fn_input_proc_analog, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x75, r3
    mov.b r3, @r2
    mov.w   .L_periph_port_mask, r4
    .byte   0xD3, 0x09    /* mov.l .L_fn_smpc_intback, r3 */
    jsr @r3
    nop
    mov.w   .L_periph_port_mask, r4
    .byte   0xD3, 0x06    /* mov.l .L_fn_input_proc_buttons, r3 */
    jsr @r3
    mov r15, r5
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov r0, r4
.L_periph_port_mask:
    .2byte  0x0200
    .4byte  0x00FFFFFF
    .4byte  smpc_secondary_proc
.L_fn_input_proc_analog:
    .4byte  input_proc_analog
.L_fn_input_proc_buttons:
    .4byte  input_proc_buttons
.L_fn_smpc_intback:
    .4byte  sym_06035C92

    .global sym_06036BE4
sym_06036BE4:
    tst r0, r0
    mov.l r2, @-r15
    bt      .L_smod_by_zero
    mov.l r3, @-r15
    mov #0x0, r2
    mov.l r4, @-r15
    div0s r2, r1
    .word 0x0429
    subc r3, r3
    subc r2, r1
    div0s r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    rotcl r1
    div1 r0, r3
    div0s r2, r3
    .word 0x0229
    xor r4, r2
    rotcr r2
    bf      .L_smod_no_correct
    div0s r0, r3
    shar r3
    div1 r0, r3
.L_smod_no_correct:
    add r4, r3
    mov r3, r0
    mov.l @r15+, r4
    mov.l @r15+, r3
    rts
    mov.l @r15+, r2
.L_smod_by_zero:
    .byte   0xD1, 0x03    /* mov.l .L_ptr_smod_error, r1 */
    .byte   0xD2, 0x03    /* mov.l .L_smod_error_code, r2 */
    mov #0x0, r0
    mov.l r2, @r1
    rts
    mov.l @r15+, r2
    .2byte  0x0009
.L_ptr_smod_error:
    .4byte  sym_060A246C
.L_smod_error_code:
    .4byte  0x0000044E
    .4byte  0x2F362F46

    .global sym_06036CB0
sym_06036CB0:
    mov.l r5, @-r15
    mov.l r6, @-r15
    mov r0, r3
    mov.l @r1+, r4
    mov #0x0, r6
.L_strcpy_word_loop:
    cmp/str r4, r6
    mov.l @r1+, r5
    bt      .L_strcpy_tail
    mov.l r4, @r0
    cmp/str r5, r6
    mov.l @r1+, r4
    bt      .L_strcpy_tail_plus4
    mov.l r5, @(4, r0)
    cmp/str r4, r6
    mov.l @r1+, r5
    bt      .L_strcpy_tail_plus8
    mov.l r4, @(8, r0)
    cmp/str r5, r6
    mov.l @r1+, r4
    bt      .L_strcpy_tail_plus12
    mov.l r5, @(12, r0)
    bra     .L_strcpy_word_loop
    add #0x10, r0
.L_strcpy_tail_plus4:
    bra     .L_strcpy_tail
    add #0x4, r0
.L_strcpy_tail_plus8:
    bra     .L_strcpy_tail
    add #0x8, r0
.L_strcpy_tail_plus12:
    add #0xC, r0
.L_strcpy_tail:
    add #-0x8, r1
    mov r0, r6
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @r6
    bt      .L_strcpy_done
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(1, r6)
    bt      .L_strcpy_done
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(2, r6)
    bt      .L_strcpy_done
    mov.b @r1+, r0
    mov.b r0, @(3, r6)
.L_strcpy_done:
    mov.l @r15+, r6
    mov r3, r0
    mov.l @r15+, r5
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3

    .global sym_06036D14
sym_06036D14:
    mov.l r3, @-r15
    mov.l r4, @-r15
    mov #0x3, r3
    mov r0, r4
    and r3, r4
    and r1, r3
    or r4, r3
    tst r3, r3
    bt      .L_strcmp_aligned
    mov.l r5, @-r15
    mov.b @r0+, r3
    mov #0x0, r5
    mov.b @r1+, r4
.L_strcmp_byte_loop:
    cmp/eq r5, r3
    bt      .L_strcmp_diff
    cmp/eq r3, r4
    bf      .L_strcmp_diff
    mov.b @r0+, r3
    mov.b @r1+, r4
    cmp/eq r5, r3
    bt      .L_strcmp_diff
    cmp/eq r3, r4
    bf      .L_strcmp_diff
    mov.b @r0+, r3
    mov.b @r1+, r4
    cmp/eq r5, r3
    bt      .L_strcmp_diff
    cmp/eq r3, r4
    bf      .L_strcmp_diff
    mov.b @r0+, r3
    mov.b @r1+, r4
    cmp/eq r5, r3
    bt      .L_strcmp_diff
    cmp/eq r3, r4
    bf      .L_strcmp_diff
    mov.b @r0+, r3
    bra     .L_strcmp_byte_loop
    mov.b @r1+, r4
.L_strcmp_diff:
    sub r4, r3
    mov.l @r15+, r5
    mov r3, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_strcmp_aligned:
    .byte   0xD3, 0x01    /* mov.l .L_fn_strcmp_word, r3 */
    jmp @r3
    nop
    .2byte  0x0009
.L_fn_strcmp_word:
    .4byte  palette_regs_config

    .global sym_06036D78
sym_06036D78:
    mov #0x0, r7
    mov r7, r3
    cmp/hs r6, r3
    bt/s    .L_memset_done
    mov r4, r0
.L_memset_loop:
    extu.b r5, r2
    add #0x1, r7
    mov.b r2, @r0
    cmp/hs r6, r7
    bf/s    .L_memset_loop
    add #0x1, r0
.L_memset_done:
    rts
    mov r4, r0
    .2byte  0x0000

    .global sym_06036D94
sym_06036D94:
    tst r6, r6
    bf/s    .L_memcmp_start
    mov r5, r7
    rts
    mov #0x0, r0
.L_memcmp_start:
    mov #0x0, r5
    mov r5, r3
    cmp/hs r6, r3
    bt      .L_memcmp_result
.L_memcmp_loop:
    mov.b @r4+, r2
    mov.b @r7+, r1
    extu.b r2, r2
    extu.b r1, r1
    cmp/eq r1, r2
    bf      .L_memcmp_result
    mov r4, r2
    add #-0x1, r2
    mov.b @r2, r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_memcmp_continue
    bra     .L_memcmp_result
    nop
.L_memcmp_continue:
    add #0x1, r5
    cmp/hs r6, r5
    bf      .L_memcmp_loop
.L_memcmp_result:
    mov r4, r0
    add #-0x1, r0
    mov.b @r0, r0
    extu.b r0, r0
    add #-0x1, r7
    mov.b @r7, r3
    extu.b r3, r3
    sub r3, r0
    rts
    nop
