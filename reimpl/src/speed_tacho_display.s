
    .section .text.FUN_06031E00


    .global speed_tacho_display
    .type speed_tacho_display, @function
speed_tacho_display:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov #0x18, r0
    mul.l r6, r0
    mov r4, r8
    mov r5, r10
    mov r6, r14
    sts macl, r0
    add r0, r8
    mov.l   .L_pool_06031E34, r13
    mov.l   .L_pool_06031E38, r11
.L_element_loop:
    add #-0x18, r8
    mov.w @(16, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.w   DAT_06031e30, r12
    mov.l   .L_pool_06031E3C, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    cmp/pl r3
    bt      .L_elem_visible
    bra     .L_next_element
    nop

    .global DAT_06031e30
DAT_06031e30:
    .2byte  0xFF00
    .2byte  0x0000
.L_pool_06031E34:
    .4byte  sym_06032128
.L_pool_06031E38:
    .4byte  sym_06032108
.L_pool_06031E3C:
    .4byte  sym_060961A8
.L_elem_visible:
    mov.w   .L_wpool_06031EA8, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    mov.l r3, @r13
    mov.w @(12, r8), r0
    mov r8, r4
    tst #0x8, r0
    bf      .L_setup_axis1
    mov.l   .L_pool_06031EAC, r5
    mov.l   .L_pool_06031EB0, r0
    mov.l @r0, r9
    clrmac
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r9+
    xtrct r0, r1
    mov.l r1, @r5
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r9+
    xtrct r0, r1
    mov.l r1, @(4, r5)
    mac.l @r4+, @r9+
    mac.l @r4+, @r9+
    add #-0x24, r9
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @(8, r5)
    mov r7, r4
    clrmac
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    mac.l @r4+, @r5+
    sts mach, r1
    sts macl, r0
    xtrct r1, r0
    cmp/pl r0
    bt      .L_setup_axis1
    bra     .L_next_element
    nop
.L_wpool_06031EA8:
    .2byte  0x00A0
    .2byte  0x0000
.L_pool_06031EAC:
    .4byte  sym_06032138
.L_pool_06031EB0:
    .4byte  sym_0608A52C
.L_setup_axis1:
    mov r11, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    mov.w @(18, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.l   .L_pool_06031EF0, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    mov.w   DAT_06031eee, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_bounds_check
    nop
    cmp/pl r3
    bt      .L_axis1_passed
    bra     .L_next_element
    nop

    .global DAT_06031eee
DAT_06031eee:
    .2byte  0x00A0
.L_pool_06031EF0:
    .4byte  sym_060961A8
.L_axis1_passed:
    mov.l r3, @(4, r13)
    add #0x8, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    mov.w @(20, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.l   .L_pool_06031F34, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    mov.w   .L_wpool_06031F30, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_bounds_check
    nop
    cmp/pl r3
    bt      .L_axis2_passed
    bra     .L_next_element
    nop
.L_wpool_06031F30:
    .2byte  0x00A0
    .2byte  0x0000
.L_pool_06031F34:
    .4byte  sym_060961A8
.L_axis2_passed:
    mov.l r3, @(8, r13)
    add #0x8, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    mov.w @(22, r8), r0
    mov #0xC, r3
    mulu.w r0, r3
    mov.l   .L_pool_06031F78, r3
    sts macl, r7
    add r3, r7
    mov.l @(8, r7), r3
    mov.w   .L_wpool_06031F74, r0
    mov.l r0, @(16, r12)
    mov.l r3, @(0, r12)
    mov #0x0, r0
    mov.l r0, @(20, r12)
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_bounds_check
    nop
    cmp/pl r3
    bt      .L_axis3_passed
    bra     .L_next_element
    nop
.L_wpool_06031F74:
    .2byte  0x00A0
    .2byte  0x0000
.L_pool_06031F78:
    .4byte  sym_060961A8
.L_axis3_passed:
    mov.l r3, @(12, r13)
    add #0x8, r5
    mov.l @(4, r7), r2
    mov.l @r7, r1
    mov.l @(28, r12), r4
    dmuls.l r1, r4
    neg r2, r2
    sts mach, r1
    dmuls.l r2, r4
    mov.l r1, @r5
    sts mach, r2
    mov.l r2, @(4, r5)
    bsr     .L_bounds_check
    nop
    mov.l   .L_pool_06031FC8, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_pool_06031FCC, r2
    sts macl, r9
    add r2, r9
    mov.w   .L_wpool_06031FC4, r12
    mov.l @(0, r11), r0
    mov.l @(8, r11), r2
    mov.l @(16, r11), r4
    mov.l @(24, r11), r6
    cmp/gt r0, r12
    bf      .L_check_right_bound
    cmp/gt r2, r12
    bf      .L_check_right_bound
    cmp/gt r4, r12
    bf      .L_check_right_bound
    cmp/gt r6, r12
    bf      .L_check_right_bound
    bra     .L_next_element
    nop
.L_wpool_06031FC4:
    .2byte  0xFF50
    .2byte  0x0000
.L_pool_06031FC8:
    .4byte  sym_060620D4
.L_pool_06031FCC:
    .4byte  sym_0608AC20
.L_check_right_bound:
    mov.w   .L_wpool_06032048, r12
    cmp/gt r0, r12
    bt      .L_check_y_bounds
    cmp/gt r2, r12
    bt      .L_check_y_bounds
    cmp/gt r4, r12
    bt      .L_check_y_bounds
    cmp/gt r6, r12
    bt      .L_next_element
.L_check_y_bounds:
    mov.w   .L_wpool_0603204A, r12
    mov.l @(4, r11), r1
    mov.l @(12, r11), r3
    mov.l @(20, r11), r5
    mov.l @(28, r11), r7
    cmp/gt r1, r12
    bf      .L_check_y_lower
    cmp/gt r3, r12
    bf      .L_check_y_lower
    cmp/gt r5, r12
    bf      .L_check_y_lower
    cmp/gt r7, r12
    bt      .L_next_element
.L_check_y_lower:
    mov.w   .L_wpool_0603204C, r12
    cmp/gt r1, r12
    bt      .L_write_sprite_entry
    cmp/gt r3, r12
    bt      .L_write_sprite_entry
    cmp/gt r5, r12
    bt      .L_write_sprite_entry
    cmp/gt r7, r12
    bf      .L_next_element
.L_write_sprite_entry:
    mov r9, r12
    add #0x18, r12
    mov.w r7, @-r12
    mov.w r6, @-r12
    mov.w r5, @-r12
    mov.w r4, @-r12
    mov.w r3, @-r12
    mov.w r2, @-r12
    mov.w r1, @-r12
    mov.w r0, @-r12
    mov.w @(14, r8), r0
    mov.w r0, @(6, r9)
    mov.w @(12, r8), r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov.b r0, @(4, r9)
    mov r10, r0
    mov.b r0, @(5, r9)
    mov.w @(12, r8), r0
    mov.l   .L_pool_06032050, r1
    and #0x7, r0
    shll2 r0
    mov.l @(r0, r1), r0
    mov.l @(0, r13), r3
    mov.l @(4, r13), r4
    mov.l @(8, r13), r5
    jmp @r0
    mov.l @(12, r13), r6
.L_wpool_06032048:
    .2byte  0x00B0
.L_wpool_0603204A:
    .2byte  0xFF81
.L_wpool_0603204C:
    .2byte  0x0051
    .2byte  0x0000
.L_pool_06032050:
    .4byte  sym_06032144

    .global loc_06032054
loc_06032054:
    add r4, r3
    add r5, r6
    add r6, r3
    bra     .L_store_sprite_result
    shlr2 r3

    .global loc_0603205E
loc_0603205E:
    cmp/ge r3, r4
    bt      .L_min_skip_1
    mov r4, r3
.L_min_skip_1:
    cmp/ge r3, r5
    bt      .L_min_skip_2
    mov r5, r3
.L_min_skip_2:
    cmp/ge r3, r6
    bt      .L_min_done
    mov r6, r3
.L_min_done:
    bra     .L_store_sprite_result
    nop

    .global loc_06032074
loc_06032074:
    cmp/gt r3, r4
    bf      .L_max_skip_1
    mov r4, r3
.L_max_skip_1:
    cmp/gt r3, r5
    bf      .L_max_skip_2
    mov r5, r3
.L_max_skip_2:
    cmp/gt r3, r6
    bf      .L_max_done
    mov r6, r3
.L_max_done:
    bra     .L_store_sprite_result
    nop

    .global loc_0603208A
loc_0603208A:
    mov #0x20, r0
    bra     .L_maxofs_body
    shll16 r0

    .global loc_06032090
loc_06032090:
    mov.l   .L_pool_060320C8, r0
.L_maxofs_body:
    cmp/gt r3, r4
    bf      .L_maxofs_skip_1
    mov r4, r3
.L_maxofs_skip_1:
    cmp/gt r3, r5
    bf      .L_maxofs_skip_2
    mov r5, r3
.L_maxofs_skip_2:
    cmp/gt r3, r6
    bf      .L_maxofs_add
    mov r6, r3
.L_maxofs_add:
    add r0, r3
.L_store_sprite_result:
    mov.l   .L_pool_060320CC, r2
    neg r3, r3
    mov.l   .L_pool_060320D0, r1
    shlr8 r3
    mov.l @r2, r0
    shlr2 r3
    shlr2 r3
    shll r0
    mov.w r3, @(r0, r1)
    shar r0
    add #0x1, r0
    mov.l r0, @r2
.L_next_element:
    dt r14
    bt      .L_epilogue
    bra     .L_element_loop
    nop
    .2byte  0x0000
.L_pool_060320C8:
    .4byte  0x00400000
.L_pool_060320CC:
    .4byte  sym_060620D4
.L_pool_060320D0:
    .4byte  sym_0606A4F8
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+, r9
    rts
    mov.l @r15+, r8
.L_bounds_check:
    mov.w   DAT_06032102, r0
    cmp/gt r0, r1
    bt      .L_next_element
    mov.w   DAT_06032104, r0
    cmp/gt r1, r0
    bt      .L_next_element
    mov.w   DAT_06032106, r0
    cmp/gt r0, r2
    bt      .L_next_element
    mov.w   DAT_06032104, r0
    cmp/gt r2, r0
    bt      .L_next_element
    rts
    nop

    .global DAT_06032102
DAT_06032102:
    .2byte  0x0190

    .global DAT_06032104
DAT_06032104:
    .2byte  0xFE70

    .global DAT_06032106
DAT_06032106:
    .2byte  0x00C8

    .global sym_06032108
sym_06032108:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_06032128
sym_06032128:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_06032138
sym_06032138:
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF
    .word 0xFFFF

    .global sym_06032144
sym_06032144:
    .4byte  loc_06032054
    .4byte  loc_0603205E
    .4byte  loc_06032074
    .4byte  loc_0603208A
    .4byte  loc_06032090

    .global sym_06032158
sym_06032158:
    mov.l   .L_pool_060321B8, r0
    mov.l   .L_pool_060321BC, r3
    mov.l @r0, r6
    mov #0x24, r7
    add r6, r7
    add #-0x8, r15
.L_xform_loop:
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7, r2
    mac.l @r4+, @r6+
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    clrmac
    mac.l @r4+, @r6+
    xtrct r0, r1
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @r15
    mac.l @r4+, @r6+
    mov.l @(4, r7), r2
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r4+, @r6+
    add r2, r1
    mac.l @r4+, @r6+
    mov.l r1, @(4, r15)
    mov.l @(8, r7), r2
    dt r5
    mac.l @r4+, @r6+
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @(8, r3)
    mov.l @r15, r0
    mov.l @(4, r15), r1
    mov.l r0, @r3
    mov.l r1, @(4, r3)
    add #-0x24, r6
    bf/s    .L_xform_loop
    add #0xC, r3
    rts
    add #0x8, r15
.L_pool_060321B8:
    .4byte  sym_0608A52C
.L_pool_060321BC:
    .4byte  sym_060961A8
