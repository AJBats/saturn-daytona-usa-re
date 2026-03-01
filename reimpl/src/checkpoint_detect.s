
    .section .text.FUN_0600D780


    .global checkpoint_detect
    .type checkpoint_detect, @function

checkpoint_detect:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_car_struct_ptr, r4
    mov.w   DAT_0600d82a, r0
    mov.l @r4, r4
    mov.l @(r0, r4), r5
    add #0x4, r0
    mov.l @(r0, r4), r3
    sub r3, r5
    tst r5, r5
    bt      .L_epilogue
    mov.l   .L_section_store, r7
    mov #-0x1, r3
    mov.l   .L_section_count, r6
    cmp/ge r3, r5
    bt/s    .L_small_or_forward
    mov #0x0, r13
    mov.w   .L_off_crossing_counter, r0
    mov.l @(r0, r4), r3
    add #0x1, r3
    mov.l r3, @(r0, r4)
    add #-0x40, r0
    mov.l @r6, r2
    mov.l @(r0, r4), r3
    cmp/eq r2, r3
    bf      .L_epilogue
    tst r14, r14
    bf      .L_epilogue
    mov.w   DAT_0600d82e, r0
    mov.l r13, @(r0, r4)
    mov.l   .L_section_value, r3
    mov.l @r3, r3
    mov.l r3, @r7
    .byte   0xB0, 0xF9    /* bsr 0x0600D9BC (external) */
    mov #0x0, r4
    .byte   0xB0, 0xAF    /* bsr 0x0600D92C (external) */
    nop
    extu.b r13, r13
    mov.l   .L_crossing_direction, r3
    mov.b r13, @r3
    bra     .L_epilogue
    nop

.L_small_or_forward:
    mov #0x1, r2
    cmp/gt r2, r5
    bf      .L_small_movement
    mov.w   .L_off_crossing_counter, r0
    mov.l @(r0, r4), r2
    add #-0x1, r2
    mov.l r2, @(r0, r4)
    mov.l @r6, r3
    mov #0x0, r2
    add #-0x40, r0
    cmp/gt r3, r2
    mov.l @(r0, r4), r1
    addc r2, r3
    shar r3
    cmp/ge r3, r1
    bf      .L_epilogue
    tst r14, r14
    bf      .L_epilogue
    mov.w   DAT_0600d82e, r0
    mov.l r13, @(r0, r4)
    mov.l   .L_section_value, r3
    mov.l @r3, r3
    mov.l r3, @r7
    .byte   0xB0, 0xD9    /* bsr 0x0600D9BC (external) */
    mov #0x0, r4
    .byte   0xB0, 0x8F    /* bsr 0x0600D92C (external) */
    nop
    mov #0x1, r2
    mov.l   .L_crossing_direction, r3
    mov.b r2, @r3
    bra     .L_epilogue
    nop

.L_small_movement:
    tst r14, r14
    bf      .L_epilogue
    bsr     .L_position_validate
    nop
    mov r14, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xA0, 0x3D    /* bra 0x0600D8A4 (external) */
    mov.l @r15+, r14

    .global DAT_0600d82a
DAT_0600d82a:
    .2byte  0x01EC                        /* car offset: current track position */
.L_off_crossing_counter:
    .2byte  0x0228                        /* car offset: crossing counter */

    .global DAT_0600d82e
DAT_0600d82e:
    .2byte  0x01E8                        /* car offset: validated track position */
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* current car struct pointer */
.L_section_store:
    .4byte  sym_06063F1C               /* section boundary store (written on crossing) */
.L_section_count:
    .4byte  sym_0607EA9C               /* total section count for current track */
.L_section_value:
    .4byte  sym_06063F18               /* section identifier value */
.L_crossing_direction:
    .4byte  sym_0605DE3C               /* crossing direction flag (0=backward, 1=forward) */

.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_position_validate:
    mov.l   .L_car_struct_ptr_2, r4
    mov.w   DAT_0600d894, r0
    mov.l @r4, r4
    mov.l @(r0, r4), r5
    add #-0x4, r0
    mov r5, r6
    mov.l @(r0, r4), r3
    sub r3, r6
    cmp/pl r6
    bf      .L_midpoint_check
    mov #0x10, r2
    cmp/ge r2, r6
    bt      .L_midpoint_check
    mov.w   .L_off_validated_pos, r0
    bra     .L_validate_return
    mov.l r5, @(r0, r4)

.L_midpoint_check:
    mov.l   .L_section_count_2, r6
    mov #0x0, r2
    mov.l @r6, r6
    cmp/gt r6, r2
    addc r2, r6
    shar r6
    cmp/eq r6, r5
    bt      .L_at_midpoint
    mov r6, r2
    add #0x2, r2
    cmp/eq r2, r5
    bf      .L_validate_return

.L_at_midpoint:
    mov.w   .L_off_validated_pos, r0
    mov.l r5, @(r0, r4)
    add #0x40, r0
    mov.l @(r0, r4), r3
    mov.l   .L_section_boundary, r2
    mov.l r3, @r2

.L_validate_return:
    rts
    nop

    .global DAT_0600d894
DAT_0600d894:
    .2byte  0x01EC                        /* car offset: current track position */
.L_off_validated_pos:
    .2byte  0x01E8                        /* car offset: validated track position */
.L_car_struct_ptr_2:
    .4byte  sym_0607E940               /* car struct pointer (dup for reach) */
.L_section_count_2:
    .4byte  sym_0607EA9C               /* section count (dup for reach) */
.L_section_boundary:
    .4byte  sym_06063F20               /* section boundary crossing counter store */
