
    .section .text.FUN_0600CC38


    .global heading_correct
    .type heading_correct, @function
heading_correct:
    mov.l r14, @-r15
    mov.l r11, @-r15
    sts.l macl, @-r15
    add #-0x4, r15
    mov.l   .L_p_car_struct, r6
    mov.w   DAT_0600ccf6, r0
    mov.l @r6, r6
    mov.l @(r0, r6), r7
    add #0x4, r0
    mov.l @(r0, r6), r3
    sub r3, r7
    mov #0x8, r3
    cmp/ge r3, r7
    bt      .L_outside_deadzone
    mov #-0x8, r3
    cmp/gt r3, r7
    bf      .L_outside_deadzone

    mov.w   DAT_0600ccf6, r0
    mov.l @(r0, r6), r3
    add #0x4, r0
    mov.l r3, @(r0, r6)
    bra     .L_do_lookup
    nop

.L_outside_deadzone:
    cmp/pl r7
    bf      .L_adjust_negative

    mov.w   DAT_0600ccf8, r0
    mov.l @(r0, r6), r3
    add #0x8, r3
    mov.l r3, @(r0, r6)
    bra     .L_do_lookup
    nop

.L_adjust_negative:
    mov.w   DAT_0600ccf8, r0
    mov.l @(r0, r6), r2
    add #-0x8, r2
    mov.l r2, @(r0, r6)

.L_do_lookup:
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w   DAT_0600ccf6, r0
    mov.l r3, @(r0, r6)
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w r3, @r15
    mov.w @r15, r7
    mov.w @r15, r0
    mov.l   .L_p_seg_data_table, r11
    extu.w r7, r7
    and #0xFF, r0
    extu.w r0, r14
    shlr2 r14
    shlr2 r14
    shlr2 r14
    tst r14, r14
    bt/s    .L_direct_lookup
    shlr8 r7

    mov #0x7, r3
    cmp/ge r3, r7
    bt      .L_direct_lookup

    mov #0x4, r1
    mov.w   DAT_0600ccfa, r0
    sub r14, r1
    mov.l @(r0, r6), r3
    shll2 r3
    shll r3
    add r3, r7
    mov r7, r0
    mov.l @r11, r3
    mov r7, r6
    shll2 r0
    add #0x1, r6
    shll2 r0
    shll2 r6
    add r3, r0
    shll2 r6
    mov.l @r0, r2
    add r3, r6

    mul.l r1, r2
    mov.l @r6, r3
    sts macl, r2
    mul.l r14, r3
    sts macl, r3
    add r3, r2
    shar r2
    shar r2
    mov.l r2, @r5

    mov.l @(4, r0), r2
    mul.l r1, r2
    sts macl, r1
    mov.l @(4, r6), r3
    mul.l r14, r3
    sts macl, r14
    add r14, r1
    shar r1
    shar r1
    bra     .L_copy_angles
    mov.l r1, @(8, r5)

    .global DAT_0600ccf6
DAT_0600ccf6:
    .2byte  0x01F8

    .global DAT_0600ccf8
DAT_0600ccf8:
    .2byte  0x01FC

    .global DAT_0600ccfa
DAT_0600ccfa:
    .2byte  0x01EC
.L_p_car_struct:
    .4byte  sym_0607E940
.L_p_seg_data_table:
    .4byte  sym_0607EB88

.L_direct_lookup:
    .byte   0x90, 0x5A    /* mov.w .L_wpool_0600CDBC, r0 */
    mov.l @(r0, r6), r2
    shll2 r2
    shll r2
    add r2, r7
    mov r7, r6
    shll2 r6
    shll2 r6
    mov.l @r11, r3
    add r3, r6
    mov.l @r6, r2
    mov.l r2, @r5
    mov.l @(4, r6), r3
    mov.l r3, @(8, r5)

.L_copy_angles:
    mov.w @(12, r4), r0
    mov.w r0, @(12, r5)
    mov.w @(14, r4), r0
    mov r0, r3
    shll2 r3
    exts.w r3, r0
    mov.w r0, @(14, r5)
    mov.w @(16, r4), r0
    mov.w r0, @(16, r5)
    mov.w @(18, r4), r0
    mov.w r0, @(18, r5)
    add #0x4, r15
    lds.l @r15+, macl
    mov.l @r15+, r11
    rts
    mov.l @r15+, r14
