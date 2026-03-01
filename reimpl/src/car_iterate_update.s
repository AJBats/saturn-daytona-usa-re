
    .section .text.FUN_0600D8A4


    .global car_iterate_update
    .type car_iterate_update, @function
car_iterate_update:
    mov.l r14, @-r15
    mov #0x0, r5
    mov.l r13, @-r15
    mov r5, r14
    mov.l r12, @-r15
    mov #0x1, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_other_car_ptr, r8
    mov.l   .L_current_car_ptr, r9
    mov.l   .L_result_flag, r10
    mov.l   .L_course_data_ptr, r11
    mov.l @r11, r12
    mov.l @r12, r12
    tst r4, r4
    .word 0x0029
    cmp/hs r12, r5
    bt/s    .L_epilogue
    mov.l r0, @r15
.L_loop_top:
    mov r14, r3
    mov.l @r9, r1
    mov.l @r11, r0
    shll2 r3
    mov.l @(4, r0), r2
    mov.w   .L_wpool_0600D91A, r0
    add r2, r3
    mov.l @r3, r3
    mov.l @(r0, r1), r2
    cmp/eq r2, r3
    bf      .L_next_car
    mov.l @r15, r0
    tst r0, r0
    bt      .L_next_car
    mov r14, r4
    .byte   0xB0, 0x64    /* bsr 0x0600D9BC (external) */
    add #0x1, r4
    mov.l @r8, r2
    mov r2, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    bt      .L_next_car
    mov.l r13, @r10
.L_next_car:
    add #0x1, r14
    cmp/hs r12, r14
    bf      .L_loop_top
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_0600D91A:
    .2byte  0x01EC                      /* [HIGH] car struct offset: checkpoint parameter */
.L_other_car_ptr:
    .4byte  sym_0607E944
.L_current_car_ptr:
    .4byte  sym_0607E940
.L_result_flag:
    .4byte  sym_060786AC
.L_course_data_ptr:
    .4byte  sym_06063F3C
