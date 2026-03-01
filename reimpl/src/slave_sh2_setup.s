
    .section .text.FUN_0603F148


    .global slave_sh2_setup
    .type slave_sh2_setup, @function
slave_sh2_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r4, r13
    mov.l r11, @-r15
    mov r5, r12
    mov.l r10, @-r15
    mov r6, r10
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_ptr_memcmp, r9
    mov.w   .L_flag_mask, r11
    mov.l   .L_ptr_str_dot, r0
    mov.l   .L_ptr_strcmp, r3
    jsr @r3
    mov r5, r1
    tst r0, r0
    bf      .L_dot_no_match
    bra     .L_return
    mov #0x0, r0
.L_dot_no_match:
    mov.l   .L_ptr_str_dotdot, r0
    mov.l   .L_ptr_strcmp, r3
    jsr @r3
    mov r12, r1
    tst r0, r0
    bf      .L_search_entries
    bra     .L_return
    mov #0x1, r0
.L_flag_mask:
    .2byte  0x0080
    .2byte  0xFFFF
    .4byte  cmd_dispatch_main
    .4byte  menu_state_handler
.L_ptr_memcmp:
    .4byte  sym_06036D94
.L_ptr_str_dot:
    .4byte  sym_06059CB8
.L_ptr_strcmp:
    .4byte  sym_06036D14
.L_ptr_str_dotdot:
    .4byte  sym_06059CBC
.L_search_entries:
    mov #0x2, r14
    cmp/ge r10, r14
    bt/s    .L_not_found
    add #0x30, r13
.L_compare_entry:
    mov #0xC, r6
    mov r13, r5
    add #0xC, r5
    jsr @r9
    mov r12, r4
    tst r0, r0
    bf      .L_check_end_flag
    bra     .L_return
    mov r14, r0
.L_check_end_flag:
    mov.b @(11, r13), r0
    mov r0, r3
    extu.b r3, r3
    and r11, r3
    tst r3, r3
    bt      .L_next_entry
    bra     .L_not_found
    nop
.L_next_entry:
    add #0x1, r14
    cmp/ge r10, r14
    bf/s    .L_compare_entry
    add #0x18, r13
.L_not_found:
    mov #-0x1, r0
.L_return:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global sym_0603F1E0
sym_0603F1E0:
    mov r4, r0
    mov r4, r3
    shll2 r0
    shll2 r3
    shll r3
    add r3, r0
    rts
    add r5, r0

    .global sym_0603F1F0
sym_0603F1F0:
    mov r4, r0
    mov r4, r3
    shll2 r0
    shll2 r3
    shll r0
    shll2 r3
    add r3, r0
    rts
    add r5, r0
