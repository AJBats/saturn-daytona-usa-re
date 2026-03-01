
    .section .text.FUN_06035F44


    .global input_proc_complete
    .type input_proc_complete, @function
input_proc_complete:
    tst r0, r0
    mov.l r2, @-r15
    bt      .L_udiv_by_zero
    mov #0x0, r2
    div0u
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    mov r1, r0
    rts
    mov.l @r15+, r2
.L_udiv_by_zero:
    mov.l   .L_ptr_udiv_error, r2
    mov.l   .L_udiv_error_code, r1
    mov #0x0, r0
    mov.l r1, @r2
    rts
    mov.l @r15+, r2
    .2byte  0x0009
.L_ptr_udiv_error:
    .4byte  sym_060A246C
.L_udiv_error_code:
    .4byte  0x0000044E

    .global sym_06035FEC
sym_06035FEC:
    mov.l r3, @-r15
    mov.l r4, @-r15
    mov #0x3, r3
    mov r0, r4
    and r3, r4
    and r1, r3
    or r4, r3
    tst r3, r3
    bt      .L_strcpy_both_aligned
    mov r0, r4
    mov.b @r1+, r0
    mov r4, r3
.L_strcpy_byte_loop:
    cmp/eq #0x0, r0
    mov.b r0, @r3
    bt      .L_strcpy_return
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(1, r3)
    bt      .L_strcpy_return
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(2, r3)
    bt      .L_strcpy_return
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(3, r3)
    bt      .L_strcpy_return
    mov.b @r1+, r0
    bra     .L_strcpy_byte_loop
    add #0x4, r3
.L_strcpy_return:
    mov r4, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_strcpy_both_aligned:
    mov.l   .L_ptr_strcpy_fast, r3
    jmp @r3
    nop
    .2byte  0x0009
.L_ptr_strcpy_fast:
    .4byte  sym_06036CB0

    .global sym_0603603C
sym_0603603C:
    mov.b @(r0, r0), r14
    .word 0x0A08
    .4byte  loc_06040200
    .4byte  0x201E1C1A
    .4byte  0x18161412
    .4byte  0x3432302E
    .4byte  0x2C2A2826
    .4byte  0x403E3C3A
    .4byte  0x4856626C
    .4byte  0x2F264111
    .4byte  0x8F18E220
    .4byte  0x3123890B

    .global sym_06036068
sym_06036068:
    mov.l   .L_ptr_lshr_jump_table, r2
    add r1, r2
    mov.b @r2, r2
    mov.l   .L_ptr_lshr_base, r1
    add r2, r1
    jmp @r1
    nop
    .2byte  0x0009
.L_ptr_lshr_base:
    .4byte  sym_06036086
.L_ptr_lshr_jump_table:
    .4byte  sym_0603603C
    .4byte  0xE000000B
    .2byte  0x62F6

    .global sym_06036086
sym_06036086:
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    rts
    mov.l @r15+, r2
    .4byte  0x40014001
    .4byte  0x40014001
    .4byte  0x40014001
    .4byte  0x40014019
    .4byte  0x000B62F6
    .4byte  0x40014001
    .4byte  0x40014001
    .4byte  0x40014001
    .4byte  0x40014029
    .4byte  0x000B62F6
    .4byte  0x40014001
    .4byte  0x40014019
    .4byte  0x4029000B
    .4byte  0x62F64004
    .4byte  0x40044004
    .4byte  0x4004C90F
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0x4004C907
    .4byte  0x000B62F6
    .4byte  0x40044004
    .4byte  0xC903000B
    .4byte  0x62F64004
    .4byte  0xC901000B
    .4byte  0x62F60000

    .global sym_060360FC
sym_060360FC:
    mov.l r13, @-r15
    cmp/eq r5, r4
    bt      .L_memmove_return
    cmp/hs r5, r4
    bt/s    .L_memmove_backward
    mov #0x0, r7
    mov r4, r13
    mov r5, r0
    cmp/hs r6, r7
    bt/s    .L_memmove_return
    mov r7, r5
.L_memmove_fwd_loop:
    mov r13, r2
    mov.b @r0+, r1
    add #0x1, r5
    add #0x1, r13
    cmp/hs r6, r5
    bf/s    .L_memmove_fwd_loop
    mov.b r1, @r2
    bra     .L_memmove_return
    nop
.L_memmove_backward:
    mov r4, r13
    mov r5, r0
    add r6, r13
    add r6, r0
    cmp/hs r6, r7
    bt/s    .L_memmove_return
    mov r7, r5
.L_memmove_bwd_loop:
    add #-0x1, r0
    add #0x1, r5
    mov.b @r0, r3
    cmp/hs r6, r5
    bf/s    .L_memmove_bwd_loop
    mov.b r3, @-r13
.L_memmove_return:
    mov r4, r0
    rts
    mov.l @r15+, r13
