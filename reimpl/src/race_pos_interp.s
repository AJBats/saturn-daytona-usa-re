
    .section .text.FUN_0600CB90


    .global race_pos_interp
    .type race_pos_interp, @function
race_pos_interp:
    mov.l r14, @-r15
    extu.w r5, r0
    mov.l   .L_p_seg_data_array, r14
    mov.l   .L_p_car_struct, r7
    tst #0x1, r0
    bt/s    .L_even_index
    mov.l @r7, r7
    extu.w r5, r6
    mov.l   .L_p_section_count, r3
    shlr r6
    mov.l @r3, r3
    add #0x1, r6
    cmp/hi r3, r6
    bf      .L_no_wrap
    mov #0x0, r6
.L_no_wrap:
    extu.w r5, r5
    shll2 r6
    mov.w   .L_w_seg_table_off, r0
    mov.l @r14, r3
    shlr r5
    shll r6
    mov.l @(r0, r7), r1
    shll2 r5
    shlr8 r1
    shll r5
    mov r1, r7
    add r5, r7
    add r6, r1
    mov r7, r5
    mov r1, r6
    shll2 r5
    shll2 r6
    shll2 r5
    shll2 r6
    add r3, r5
    add r3, r6
    mov.l @r5, r2
    mov.l @r6, r3
    add r3, r2
    shar r2
    mov.l r2, @r4
    mov.l @(4, r5), r2
    mov.l @(4, r6), r3
    add r3, r2
    shar r2
    bra     .L_write_angles
    mov.l r2, @(8, r4)
.L_even_index:
    extu.w r5, r5
    mov.w   .L_w_seg_table_off, r0
    shlr r5
    mov.l @(r0, r7), r6
    shll2 r5
    shlr8 r6
    shll r5
    add r5, r6
    mov r6, r5
    shll2 r5
    shll2 r5
    mov.l @r14, r3
    add r3, r5
    mov.l @r5, r2
    mov.l r2, @r4
    mov.l @(4, r5), r3
    mov.l r3, @(8, r4)
.L_write_angles:
    mov.w @(8, r5), r0
    mov.w r0, @(12, r4)
    mov.w @(10, r5), r0
    mov r0, r3
    shll2 r3
    exts.w r3, r0
    mov.w r0, @(14, r4)
    mov.w @(12, r5), r0
    mov.w r0, @(16, r4)
    mov #0x0, r0
    mov.w r0, @(18, r4)
    rts
    mov.l @r15+, r14
.L_w_seg_table_off:
    .2byte  0x01F8                     /* [HIGH] car struct offset: segment table base (+0x1F8) */
.L_p_seg_data_array:
    .4byte  sym_0607EB88               /* [HIGH] course segment data array ptr */
.L_p_car_struct:
    .4byte  sym_0607E940               /* [HIGH] current car struct pointer (player) */
.L_p_section_count:
    .4byte  sym_0607EA9C               /* [HIGH] track section count (wrap limit) */
