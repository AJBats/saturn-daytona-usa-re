	.text
    .global camera_attract_init
camera_attract_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l   .L_06033BF0, r0
    mov.l @r0, r0
    mov.l   .L_06033BF4, r1
    mov.l @(r0, r1), r1
    mov.l   .L_06033BF8, r0
    cmp/ge r0, r1
    bf      .L_06033C00
    mov.l   .L_06033BFC, r0
    cmp/gt r0, r1
    bt      .L_06033C00
    bra     .L_06033C02
    sett
    .short  0x0000
.L_06033BF0:
    .long  sym_0607E944
.L_06033BF4:
    .long  0x000001EC
.L_06033BF8:
    .long  0x000000DC
.L_06033BFC:
    .long  0x000000EC
.L_06033C00:
    clrt
.L_06033C02:
    bf      .L_06033C30
    mov #0x0, r4
    mov.l   .L_06033C2C, r0

    .global disp_timeext_digit_0
disp_timeext_digit_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov #0x1, r4
    mov.l   .L_06033C2C, r0

    .global disp_timeext_digit_1
disp_timeext_digit_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov #0x2, r4
    mov.l   .L_06033C2C, r0

    .global disp_timeext_digit_2
disp_timeext_digit_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    bra     .L_06033C3A
    nop
.L_06033C2C:
    .long  sym_06033F54
.L_06033C30:
    mov.l   .L_06033C54, r0

    .global time_extend_digits
time_extend_digits:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
.L_06033C3A:
    mov.l   .L_06033C58, r0
    mov.l @r0, r0
    mov.l   .L_06033C5C, r1
    mov.l @(r0, r1), r1
    mov.l   .L_06033C60, r0
    cmp/ge r0, r1
    bf      .L_06033C68
    mov.l   .L_06033C64, r0
    cmp/gt r0, r1
    bt      .L_06033C68
    bra     .L_06033C6A
    sett
    .short  0x0000
.L_06033C54:
    .long  sym_0603446C
.L_06033C58:
    .long  sym_0607E944
.L_06033C5C:
    .long  0x000001EC
.L_06033C60:
    .long  0x000000ED
.L_06033C64:
    .long  0x00000104
.L_06033C68:
    clrt
.L_06033C6A:
    bf      .L_06033D34
    mov #0x5, r4

    .global disp_sel_thunk_00
disp_sel_thunk_00:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x6, r4

    .global disp_sel_thunk_01
disp_sel_thunk_01:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x7, r4

    .global disp_sel_thunk_02
disp_sel_thunk_02:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x8, r4

    .global disp_sel_thunk_03
disp_sel_thunk_03:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x9, r4

    .global disp_sel_thunk_04
disp_sel_thunk_04:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0xA, r4

    .global disp_sel_thunk_05
disp_sel_thunk_05:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0xB, r4

    .global disp_sel_thunk_06
disp_sel_thunk_06:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0xC, r4

    .global disp_sel_thunk_07
disp_sel_thunk_07:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0xD, r4

    .global disp_sel_thunk_08
disp_sel_thunk_08:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0xE, r4

    .global disp_sel_thunk_09
disp_sel_thunk_09:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0xF, r4

    .global disp_sel_thunk_10
disp_sel_thunk_10:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x10, r4

    .global disp_sel_thunk_11
disp_sel_thunk_11:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x11, r4

    .global disp_sel_thunk_12
disp_sel_thunk_12:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x12, r4

    .global disp_sel_thunk_13
disp_sel_thunk_13:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x13, r4

    .global disp_sel_thunk_14
disp_sel_thunk_14:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x14, r4

    .global disp_sel_thunk_15
disp_sel_thunk_15:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x15, r4

    .global disp_sel_thunk_16
disp_sel_thunk_16:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x16, r4

    .global disp_sel_thunk_17
disp_sel_thunk_17:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x17, r4

    .global disp_sel_thunk_18
disp_sel_thunk_18:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x18, r4

    .global selector_group_render
selector_group_render:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
.L_06033D34:
    mov.l   .L_06033D4C, r0
    mov.l @r0, r0
    mov.l   .L_06033D50, r1
    mov.l @(r0, r1), r1
    mov.l   .L_06033D54, r0
    cmp/ge r0, r1
    bf      .L_06033D5C
    mov.l   .L_06033D58, r0
    cmp/gt r0, r1
    bt      .L_06033D5C
    bra     .L_06033D5E
    sett
.L_06033D4C:
    .long  sym_0607E944
.L_06033D50:
    .long  0x000001EC
.L_06033D54:
    .long  0x000001B8
.L_06033D58:
    .long  0x000001E0
.L_06033D5C:
    clrt
.L_06033D5E:
    bt      .L_06033D64
    bra     .L_06033E8C
    nop
.L_06033D64:
    mov.l   .L_06033D70, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06033D74
    bra     .L_06033E92
    nop
.L_06033D70:
    .long  sym_0607EAE0
.L_06033D74:
    mov.l   .L_06033E64, r4

    .global disp_selext_thunk_00
disp_selext_thunk_00:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l   .L_06033E68, r0
    mov.l @r0, r13
    mov.l   .L_06033E6C, r0
    cmp/ge r0, r13
    bf      .L_06033E52
    mov.l   .L_06033E70, r4

    .global disp_selext_thunk_01
disp_selext_thunk_01:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l   .L_06033E74, r4

    .global disp_selext_thunk_02
disp_selext_thunk_02:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l   .L_06033E78, r4

    .global disp_selext_thunk_03
disp_selext_thunk_03:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l   .L_06033E7C, r4

    .global disp_selext_thunk_04
disp_selext_thunk_04:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l   .L_06033E80, r0
    cmp/ge r0, r13
    bf      .L_06033E52
    mov #0x1E, r4

    .global disp_selext_thunk_05
disp_selext_thunk_05:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x1F, r4

    .global disp_selext_thunk_06
disp_selext_thunk_06:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x20, r4

    .global disp_selext_thunk_07
disp_selext_thunk_07:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x21, r4

    .global disp_selext_thunk_08
disp_selext_thunk_08:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x22, r4

    .global disp_selext_thunk_09
disp_selext_thunk_09:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l   .L_06033E84, r0
    cmp/ge r0, r13
    bf      .L_06033E52
    mov #0x23, r4

    .global disp_selext_thunk_10
disp_selext_thunk_10:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x24, r4

    .global disp_selext_thunk_11
disp_selext_thunk_11:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x25, r4

    .global disp_selext_thunk_12
disp_selext_thunk_12:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x26, r4

    .global disp_selext_thunk_13
disp_selext_thunk_13:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x27, r4

    .global disp_selext_thunk_14
disp_selext_thunk_14:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x28, r4

    .global disp_selext_thunk_15
disp_selext_thunk_15:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x29, r4

    .global disp_selext_thunk_16
disp_selext_thunk_16:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x2A, r4

    .global disp_selext_thunk_17
disp_selext_thunk_17:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x2B, r4

    .global disp_selext_thunk_18
disp_selext_thunk_18:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov #0x2C, r4

    .global score_display_render
score_display_render:
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
.L_06033E52:
    mov.l   .L_06033E68, r1
    mov.l @r1, r0
    add #0x1, r0
    mov.l   .L_06033E88, r2
    cmp/ge r2, r0
    bf      .L_06033E60
    mov.l   .L_06033E88, r0
.L_06033E60:
    bra     .L_06033E92
    mov.l r0, @r1
.L_06033E64:
    .long  0x00000019
.L_06033E68:
    .long  sym_06083250
.L_06033E6C:
    .long  0x0000013B
.L_06033E70:
    .long  0x0000001A
.L_06033E74:
    .long  0x0000001B
.L_06033E78:
    .long  0x0000001C
.L_06033E7C:
    .long  0x0000001D
.L_06033E80:
    .long  0x00000276
.L_06033E84:
    .long  0x000003B1
.L_06033E88:
    .long  0x00000EC4
.L_06033E8C:
    xor r0, r0
    mov.l   .L_06033EA4, r1
    mov.l r0, @r1
.L_06033E92:
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
.L_06033EA4:
    .long  sym_06083250

    .global disp_score_renderer
disp_score_renderer:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l   .L_06033F30, r0
    mov.w @r0, r0
    cmp/eq #0x1, r0
    bf      .L_06033EC6
    mov.l   .L_06033F34, r1
    mov.b @r1, r0
    add #0x1, r0
    mov.b r0, @r1
.L_06033EC6:
    mov.l   .L_06033F34, r0
    mov.b @r0, r0
    cmp/eq #0x1, r0
    bf      .L_06033EFE
    mov.l   .L_06033F38, r4
    mov.l   .L_06033F3C, r0

    .global disp_score_digit_0
disp_score_digit_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06033F40, r4
    mov.l   .L_06033F3C, r0

    .global disp_score_digit_1
disp_score_digit_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06033F44, r4
    mov.l   .L_06033F3C, r0

    .global disp_score_digit_2
disp_score_digit_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06033F48, r4
    mov.l   .L_06033F3C, r0

    .global bonus_points_display
bonus_points_display:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
.L_06033EFE:
    mov.l   .L_06033F34, r0
    mov.b @r0, r0
    cmp/eq #0x2, r0
    bf      .L_06033F1C
    mov.l   .L_06033F4C, r4
.L_06033F08:
    mov.l r4, @-r15
    sts.l pr, @-r15
    bsr     sym_06033F54
    nop
    lds.l @r15+, pr
    mov.l @r15+, r4
    add #0x1, r4
    mov.l   .L_06033F50, r0
    cmp/ge r0, r4
    bf      .L_06033F08
.L_06033F1C:
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .short  0x0000
.L_06033F30:
    .long  sym_06063E08
.L_06033F34:
    .long  sym_06083254
.L_06033F38:
    .long  0x00000000
.L_06033F3C:
    .long  sym_06033F54
.L_06033F40:
    .long  0x00000001
.L_06033F44:
    .long  0x00000002
.L_06033F48:
    .long  0x00000004
.L_06033F4C:
    .long  0x00000006
.L_06033F50:
    .long  0x00000019

    .global sym_06033F54
sym_06033F54:
    mov.l r13, @-r15
    mov.l   .L_06033F9C, r1
    mulu r4, r1
    sts macl, r0
    mov.l   .L_06033FA0, r14
    add r0, r14
    mov.l   .L_06033FA4, r0
    mov.l @r0, r10
    mov.l   .L_06033FA8, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x1, r0
    bt      disp_end_stub_0
    cmp/eq #0x4, r0
    bt      disp_end_stub_0
    mov.l   .L_06033FAC, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x0, r0
    bt      disp_end_stub_2
    cmp/eq #0x1, r0
    bt      disp_end_stub_6
    cmp/eq #0x2, r0
    bt      disp_end_stub_7

    .global disp_end_stub_0
disp_end_stub_0:
    sts.l pr, @-r15
    bsr     .L_06034000
    nop
    lds.l @r15+, pr

    .global disp_end_stub_1
disp_end_stub_1:
    sts.l pr, @-r15
    bsr     .L_06034168
    nop
    lds.l @r15+, pr

    .global display_frame_mgr
display_frame_mgr:
    sts.l pr, @-r15
    bsr     .L_060346C0
    nop
    lds.l @r15+, pr
    bra     .L_06033FFC
    nop
.L_06033F9C:
    .long  0x0000002C
.L_06033FA0:
    .long  DAT_06082A7C
.L_06033FA4:
    .long  sym_0607E944
.L_06033FA8:
    .long  0x00000001
.L_06033FAC:
    .long  0x00000026

    .global disp_end_stub_2
disp_end_stub_2:
    sts.l pr, @-r15
    bsr     .L_0603449C
    nop
    lds.l @r15+, pr

    .global disp_end_stub_3
disp_end_stub_3:
    sts.l pr, @-r15
    bsr     .L_06034000
    nop
    lds.l @r15+, pr

    .global disp_end_stub_4
disp_end_stub_4:
    sts.l pr, @-r15
    bsr     .L_06034168
    nop
    lds.l @r15+, pr

    .global disp_end_stub_5
disp_end_stub_5:
    sts.l pr, @-r15
    bsr     .L_060346C0
    nop
    lds.l @r15+, pr
    bra     .L_06033FFC
    nop

    .global disp_end_stub_6
disp_end_stub_6:
    sts.l pr, @-r15
    bsr     .L_06034560
    nop
    lds.l @r15+, pr

    .global disp_end_stub_7
disp_end_stub_7:
    sts.l pr, @-r15
    bsr     .L_0603449C
    nop
    lds.l @r15+, pr

    .global disp_end_stub_8
disp_end_stub_8:
    sts.l pr, @-r15
    bsr     .L_0603458C
    nop
    lds.l @r15+, pr

    .global disp_end_stub_9
disp_end_stub_9:
    sts.l pr, @-r15
    bsr     .L_06034640
    nop
    lds.l @r15+, pr

    .global display_frame_flush
display_frame_flush:
    sts.l pr, @-r15
    bsr     .L_060346C0
    nop
    lds.l @r15+, pr
.L_06033FFC:
    rts
    mov.l @r15+, r13
.L_06034000:
    mov.l   .L_06034018, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x3, r0
    bf      .L_06034024
    mov.l   .L_0603401C, r0
    mov.w @(r0, r14), r1
    exts.w r1, r1
    mov.l   .L_06034020, r0
    mov.l @(r0, r14), r2
    add r1, r2
    rts
    mov.l r2, @(r0, r14)
.L_06034018:
    .long  0x00000001
.L_0603401C:
    .long  0x00000012
.L_06034020:
    .long  0x0000001C
.L_06034024:
    mov.l   .L_06034088, r0
    mov.w @(r0, r14), r2
    mov.l   .L_0603408C, r0
    mov.w @(r0, r14), r1
    add r2, r1
    mov.w r1, @(r0, r14)
    mov r1, r13
    mov r13, r4
    mov.l   .L_06034090, r0

    .global phys_position_load
phys_position_load:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r12
    mov.l   .L_06034094, r0
    mov.l @(r0, r14), r11
    dmuls.l r12, r11
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l   .L_06034098, r0
    mov.l @(r0, r14), r0
    add r0, r1
    mov.l   .L_0603409C, r0
    mov.l r1, @(r0, r14)
    mov r13, r4
    mov.l   .L_060340A0, r0

    .global phys_velocity_integrate
phys_velocity_integrate:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    dmuls.l r0, r11
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l   .L_060340A4, r0
    mov.l @(r0, r14), r0
    add r0, r1
    mov.l   .L_060340A8, r0
    mov.l r1, @(r0, r14)
    mov.l   .L_060340AC, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x2, r0
    bt      .L_0603410C
    mov.l   .L_060340B0, r0
    mov.w @(r0, r14), r1
    tst r1, r1
    bf      .L_060340B4
    bra     .L_060340EC
    xor r2, r2
.L_06034088:
    .long  0x00000012
.L_0603408C:
    .long  0x00000002
.L_06034090:
    .long  cos_lookup
.L_06034094:
    .long  0x00000020
.L_06034098:
    .long  0x00000014
.L_0603409C:
    .long  0x00000004
.L_060340A0:
    .long  sin_lookup
.L_060340A4:
    .long  0x0000001C
.L_060340A8:
    .long  0x0000000C
.L_060340AC:
    .long  0x00000001
.L_060340B0:
    .long  0x00000024
.L_060340B4:
    dmuls.l r12, r1
    sts mach, r0
    sts macl, r10
    xtrct r0, r10
    mov r10, r4
    mov.l   .L_060340F8, r0

    .global phys_result_store
phys_result_store:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r9
    mov r10, r4
    mov.l   .L_060340FC, r0

    .global phys_perspective
phys_perspective:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r5
    mov r9, r4
    mov.l   .L_06034100, r0

    .global phys_final_integrate
phys_final_integrate:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    dmuls.l r0, r11
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
.L_060340EC:
    mov.l   .L_06034104, r0
    mov.l @(r0, r14), r1
    add r1, r2
    mov.l   .L_06034108, r0
    bra     .L_0603413E
    mov.l r2, @(r0, r14)
.L_060340F8:
    .long  sin_lookup
.L_060340FC:
    .long  cos_lookup
.L_06034100:
    .long  fpdiv_setup
.L_06034104:
    .long  0x00000018
.L_06034108:
    .long  0x00000008
.L_0603410C:
    mov.l   .L_06034144, r0
    mov.l @(r0, r14), r4
    mov.l   .L_06034148, r0
    mov.l r4, @r0
    mov.l   .L_0603414C, r0
    mov.l @(r0, r14), r5
    mov.l   .L_06034150, r0
    mov.l r5, @r0
    mov.l   .L_06034154, r0

    .global phys_lighting_setup
phys_lighting_setup:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r4
    mov.l   .L_06034148, r5
    mov.l   .L_06034158, r6
    mov.l   .L_0603415C, r0

    .global ai_steering_response
ai_steering_response:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034160, r0
    mov.l @r0, r1
    mov.l   .L_06034164, r0
    mov.l r1, @(r0, r14)
.L_0603413E:
    rts
    nop
    .short  0x0000
.L_06034144:
    .long  0x00000004
.L_06034148:
    .long  sym_06083238
.L_0603414C:
    .long  0x0000000C
.L_06034150:
    .long  sym_06083240
.L_06034154:
    .long  sym_06006838
.L_06034158:
    .long  sym_06083244
.L_0603415C:
    .long  scene_render_alt
.L_06034160:
    .long  sym_0608323C
.L_06034164:
    .long  0x00000008
.L_06034168:
    mov.l   .L_060341C4, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x1, r0
    bf      .L_060341F4
    mov.l   .L_060341C8, r0

    .global ai_vel_x_entry
ai_vel_x_entry:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060341CC, r13
    mov.l @r13, r13
    mov.l   .L_060341D0, r0
    mov.l @(r0, r14), r4
    mov.l   .L_060341D4, r0
    mov.l @(r0, r14), r5
    mov.l   .L_060341D8, r0
    mov.l @(r0, r14), r6
    mov.l   .L_060341DC, r0

    .global ai_vel_x_step_a
ai_vel_x_step_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060341E0, r0
    mov.w @(r0, r14), r4
    mov.l   .L_060341E4, r0

    .global ai_vel_x_step_b
ai_vel_x_step_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060341E8, r0
    mov.b @(r0, r14), r4
    mov.l   .L_060341EC, r0

    .global ai_vel_x_step_c
ai_vel_x_step_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060341F0, r0

    .global xaxis_integrate_damp
xaxis_integrate_damp:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060341CC, r13
    mov.l @r13, r13
    bra     .L_06034468
    nop
    .short  0x0000
.L_060341C4:
    .long  0x00000001
.L_060341C8:
    .long  sym_06026DBC
.L_060341CC:
    .long  sym_06089EDC
.L_060341D0:
    .long  0x00000004
.L_060341D4:
    .long  0x00000008
.L_060341D8:
    .long  0x0000000C
.L_060341DC:
    .long  sym_06026E2E
.L_060341E0:
    .long  0x00000002
.L_060341E4:
    .long  mat_rot_y
.L_060341E8:
    .long  0x00000011
.L_060341EC:
    .long  camera_param_load
.L_060341F0:
    .long  sym_06026DF8
.L_060341F4:
    cmp/eq #0x2, r0
    bf      .L_06034280
    mov.l   .L_06034250, r0

    .global ai_vel_x_cleanup_entry
ai_vel_x_cleanup_entry:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034254, r13
    mov.l @r13, r13
    mov.l   .L_06034258, r0
    mov.l @(r0, r14), r4
    mov.l   .L_0603425C, r0
    mov.l @(r0, r14), r5
    mov.l   .L_06034260, r0
    mov.l @(r0, r14), r6
    mov.l   .L_06034264, r0

    .global ai_vel_x_cleanup_a
ai_vel_x_cleanup_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034268, r0
    mov.w @(r0, r14), r4
    mov.l   .L_0603426C, r0
    add r0, r4
    exts.w r4, r4
    mov.l   .L_06034270, r0

    .global ai_vel_x_cleanup_b
ai_vel_x_cleanup_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034274, r0
    mov.b @(r0, r14), r4
    mov.l   .L_06034278, r0

    .global ai_vel_x_cleanup_c
ai_vel_x_cleanup_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_0603427C, r0

    .global yaxis_integrate
yaxis_integrate:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034254, r13
    mov.l @r13, r13
    bra     .L_06034468
    nop
.L_06034250:
    .long  sym_06026DBC
.L_06034254:
    .long  sym_06089EDC
.L_06034258:
    .long  0x00000004
.L_0603425C:
    .long  0x00000008
.L_06034260:
    .long  0x0000000C
.L_06034264:
    .long  sym_06026E2E
.L_06034268:
    .long  0x00000002
.L_0603426C:
    .long  0x00008000
.L_06034270:
    .long  mat_rot_y
.L_06034274:
    .long  0x00000011
.L_06034278:
    .long  camera_scene_setup
.L_0603427C:
    .long  sym_06026DF8
.L_06034280:
    cmp/eq #0x3, r0
    bf      .L_06034304
    mov.l   .L_060342D8, r0

    .global ai_vel_y_entry
ai_vel_y_entry:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060342DC, r13
    mov.l @r13, r13
    mov.l   .L_060342E0, r0
    mov.l @(r0, r14), r4
    mov.l   .L_060342E4, r0
    mov.l @(r0, r14), r5
    mov.l   .L_060342E8, r0
    mov.l @(r0, r14), r6
    mov.l   .L_060342EC, r0

    .global ai_vel_y_step_a
ai_vel_y_step_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060342F0, r0
    mov.w @(r0, r14), r4
    mov.l   .L_060342F4, r0

    .global ai_vel_y_step_b
ai_vel_y_step_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060342F8, r0
    mov.b @(r0, r14), r4
    mov.l   .L_060342FC, r0

    .global ai_vel_y_step_c
ai_vel_y_step_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034300, r0

    .global zaxis_integrate
zaxis_integrate:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060342DC, r13
    mov.l @r13, r13
    bra     .L_06034468
    nop
    .short  0x0000
.L_060342D8:
    .long  sym_06026DBC
.L_060342DC:
    .long  sym_06089EDC
.L_060342E0:
    .long  0x00000014
.L_060342E4:
    .long  0x00000018
.L_060342E8:
    .long  0x0000001C
.L_060342EC:
    .long  sym_06026E2E
.L_060342F0:
    .long  0x00000002
.L_060342F4:
    .long  mat_rot_y
.L_060342F8:
    .long  0x00000011
.L_060342FC:
    .long  camera_scene_setup
.L_06034300:
    .long  sym_06026DF8
.L_06034304:
    cmp/eq #0x4, r0
    bt      .L_0603430C
    bra     .L_06034468
    nop
.L_0603430C:
    mov.l   .L_06034420, r0

    .global ai_vel_z_entry
ai_vel_z_entry:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034424, r13
    mov.l @r13, r13
    mov.l   .L_06034428, r0
    mov.l @(r0, r14), r4
    mov.l   .L_0603442C, r0
    mov.l @(r0, r14), r5
    mov.l   .L_06034430, r0
    mov.l @(r0, r14), r6
    mov.l   .L_06034434, r0

    .global ai_vel_z_step_a
ai_vel_z_step_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034438, r0
    mov.w @(r0, r14), r4
    mov.l   .L_0603443C, r0

    .global ai_vel_z_step_b
ai_vel_z_step_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034440, r0
    mov.b @(r0, r14), r4
    mov.l   .L_06034444, r0

    .global ai_vel_z_step_c
ai_vel_z_step_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034448, r0

    .global ai_rot_a_entry
ai_rot_a_entry:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034424, r13
    mov.l @r13, r13
    mov.l   .L_0603444C, r0
    mov.l @r0, r1
    mov.l   .L_06034450, r0
    cmp/ge r0, r1
    bf      .L_0603441C
    mov.l   .L_06034420, r0

    .global ai_rot_a_step
ai_rot_a_step:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034424, r13
    mov.l @r13, r13
    mov.l   .L_06034428, r0
    mov.l @(r0, r14), r4
    mov.l   .L_06034454, r0
    sub r0, r4
    mov.l   .L_0603442C, r0
    mov.l @(r0, r14), r5
    mov.l   .L_06034430, r0
    mov.l @(r0, r14), r6
    mov.l   .L_06034458, r0
    sub r0, r6
    mov.l   .L_06034434, r0

    .global ai_rot_a_fix_a
ai_rot_a_fix_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034438, r0
    mov.w @(r0, r14), r4
    mov.l   .L_0603443C, r0

    .global ai_rot_a_fix_b
ai_rot_a_fix_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034440, r0
    mov.b @(r0, r14), r4
    mov.l   .L_06034444, r0

    .global ai_rot_a_fix_c
ai_rot_a_fix_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034448, r0

    .global ai_rot_b_entry
ai_rot_b_entry:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034424, r13
    mov.l @r13, r13
    mov.l   .L_0603444C, r0
    mov.l @r0, r1
    mov.l   .L_0603445C, r0
    cmp/ge r0, r1
    bf      .L_0603441C
    mov.l   .L_06034420, r0

    .global ai_rot_b_step
ai_rot_b_step:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034424, r13
    mov.l @r13, r13
    mov.l   .L_06034428, r0
    mov.l @(r0, r14), r4
    mov.l   .L_06034460, r0
    sub r0, r4
    mov.l   .L_0603442C, r0
    mov.l @(r0, r14), r5
    mov.l   .L_06034430, r0
    mov.l @(r0, r14), r6
    mov.l   .L_06034464, r0
    sub r0, r6
    mov.l   .L_06034434, r0

    .global ai_rot_b_fix_a
ai_rot_b_fix_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034438, r0
    mov.w @(r0, r14), r4
    add r0, r4
    mov.l   .L_0603443C, r0

    .global ai_rot_b_fix_b
ai_rot_b_fix_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034440, r0
    mov.b @(r0, r14), r4
    mov.l   .L_06034444, r0

    .global ai_rot_b_fix_c
ai_rot_b_fix_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034448, r0

    .global ai_decision_dispatch
ai_decision_dispatch:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034424, r13
    mov.l @r13, r13
.L_0603441C:
    bra     .L_06034468
    nop
.L_06034420:
    .long  sym_06026DBC
.L_06034424:
    .long  sym_06089EDC
.L_06034428:
    .long  0x00000004
.L_0603442C:
    .long  0x00000008
.L_06034430:
    .long  0x0000000C
.L_06034434:
    .long  sym_06026E2E
.L_06034438:
    .long  0x00000002
.L_0603443C:
    .long  mat_rot_y
.L_06034440:
    .long  0x00000011
.L_06034444:
    .long  camera_param_load
.L_06034448:
    .long  sym_06026DF8
.L_0603444C:
    .long  sym_06083250
.L_06034450:
    .long  0x000004EC
.L_06034454:
    .long  0x00280000
.L_06034458:
    .long  0x003E0000
.L_0603445C:
    .long  0x00000627
.L_06034460:
    .long  0x00190000
.L_06034464:
    .long  0x001C0000
.L_06034468:
    rts
    nop

    .global sym_0603446C
sym_0603446C:
    xor r7, r7
.L_0603446E:
    mov.l   .L_0603448C, r1
    mulu r7, r1
    sts macl, r0
    mov.l   .L_06034490, r14
    add r0, r14
    xor r1, r1
    mov.l   .L_06034494, r0
    mov.b r1, @(r0, r14)
    add #0x1, r7
    mov.l   .L_06034498, r0
    cmp/ge r0, r7
    bf      .L_0603446E
    rts
    nop
    .short  0x0000
.L_0603448C:
    .long  0x0000002C
.L_06034490:
    .long  DAT_06082A7C
.L_06034494:
    .long  0x00000026
.L_06034498:
    .long  0x00000005
.L_0603449C:
    mov.l   .L_06034508, r0
    mov.b @(r0, r14), r0
    cmp/eq #0x2, r0
    bf      .L_0603454A
    mov.l   .L_0603450C, r0
    mov.l @(r0, r14), r3
    mov.l   .L_06034510, r0
    mov.l @(r0, r14), r4
    mov.l   .L_06034514, r0
    mov.l @(r0, r10), r5
    mov.l   .L_06034518, r0
    mov.l @(r0, r10), r6
    mov.l r13, @-r15
    mov.l r1, @-r15
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r4, @-r15
    mov.l r5, @-r15
    mov.l   .L_0603451C, r13
    mov.l r3, @(0, r13)
    mov.l r4, @(4, r13)
    mov.l r5, @(8, r13)
    mov.l r6, @(12, r13)
    mov.l @(0, r13), r1
    mov.l @(8, r13), r0
    sub r1, r0
    mov r0, r4
    mov r0, r5
    dmuls.l r4, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l r1, @(16, r13)
    mov.l @(4, r13), r1
    mov.l @(12, r13), r0
    sub r1, r0
    mov r0, r4
    mov r0, r5
    dmuls.l r4, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    mov.l @(16, r13), r4
    add r1, r4
    cmp/pz r4
    bt      .L_06034524
    shlr2 r4
    mov.l   .L_06034520, r0

    .global ai_speed_limit
ai_speed_limit:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    bra     .L_0603452E
    shll r0
.L_06034508:
    .long  0x00000001
.L_0603450C:
    .long  0x00000004
.L_06034510:
    .long  0x0000000C
.L_06034514:
    .long  0x00000010
.L_06034518:
    .long  0x00000018
.L_0603451C:
    .long  sym_06083238
.L_06034520:
    .long  isqrt
.L_06034524:
    mov.l   .L_06034550, r0

    .global ai_waypoint_follower
ai_waypoint_follower:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
.L_0603452E:
    mov.l @r15+, r5
    mov.l @r15+, r4
    mov.l @r15+, r3
    mov.l @r15+, r2
    mov.l @r15+, r1
    mov.l @r15+, r13
    mov r0, r2
    mov r2, r8
    mov.l   .L_06034554, r0
    cmp/ge r0, r2
    bt      .L_0603454A
    mov.l   .L_06034558, r1
    mov.l   .L_0603455C, r0
    mov.b r1, @(r0, r14)
.L_0603454A:
    rts
    nop
    .short  0x0000
.L_06034550:
    .long  isqrt
.L_06034554:
    .long  0x00080000
.L_06034558:
    .long  0x00000001
.L_0603455C:
    .long  0x00000026
.L_06034560:
    mov.l   .L_0603457C, r0
    mov.l @(r0, r10), r1
    mov.l   .L_06034580, r0
    mov.w r1, @(r0, r14)
    mov.l   .L_06034584, r0
    mov.l @(r0, r10), r4
    shal r4
    mov.l   .L_0603457C, r0
    mov.l r4, @(r0, r14)
    mov.l   .L_06034588, r0
    mov #0x2, r1
    mov.b r1, @(r0, r14)
    rts
    nop
.L_0603457C:
    .long  0x00000028
.L_06034580:
    .long  0x00000002
.L_06034584:
    .long  0x0000000C
.L_06034588:
    .long  0x00000026
.L_0603458C:
    mov.l   .L_06034608, r0
    mov.w @(r0, r14), r9
    mov.l   .L_0603460C, r1
    add r1, r9
    mov.l   .L_06034610, r0
    mov.l @(r0, r14), r8
    mov r9, r4
    mov.l   .L_06034614, r0

    .global ai_collision_trigger
ai_collision_trigger:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    dmuls.l r0, r8
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    mov.l   .L_06034618, r0
    mov.l @(r0, r14), r1
    add r3, r1
    mov.l r1, @(r0, r14)
    mov r9, r4
    mov.l   .L_0603461C, r0

    .global ai_collision_response
ai_collision_response:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    dmuls.l r0, r8
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    mov.l   .L_06034620, r0
    mov.l @(r0, r14), r1
    add r3, r1
    mov.l r1, @(r0, r14)
    mov.l   .L_06034618, r0
    mov.l @(r0, r14), r4
    mov.l   .L_06034624, r0
    mov.l r4, @r0
    mov.l   .L_06034620, r0
    mov.l @(r0, r14), r5
    mov.l   .L_06034628, r0
    mov.l r5, @r0
    mov.l   .L_0603462C, r0

    .global ai_reset_stub
ai_reset_stub:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r4
    mov.l   .L_06034624, r5
    mov.l   .L_06034630, r6
    mov.l   .L_06034634, r0

    .global ai_car_pos_init
ai_car_pos_init:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034638, r0
    mov.l @r0, r1
    mov.l   .L_0603463C, r0
    mov.l r1, @(r0, r14)
    rts
    nop
    .short  0x0000
.L_06034608:
    .long  0x00000002
.L_0603460C:
    .long  0x00004000
.L_06034610:
    .long  0x00000028
.L_06034614:
    .long  cos_lookup
.L_06034618:
    .long  0x00000004
.L_0603461C:
    .long  sin_lookup
.L_06034620:
    .long  0x0000000C
.L_06034624:
    .long  sym_06083238
.L_06034628:
    .long  sym_06083240
.L_0603462C:
    .long  sym_06006838
.L_06034630:
    .long  sym_06083244
.L_06034634:
    .long  scene_render_alt
.L_06034638:
    .long  sym_0608323C
.L_0603463C:
    .long  0x00000008
.L_06034640:
    mov.l   .L_06034694, r0

    .global ai_spawn_helper_a
ai_spawn_helper_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034698, r13
    mov.l @r13, r13
    mov.l   .L_0603469C, r0
    mov.l @(r0, r14), r4
    mov.l   .L_060346A0, r0
    mov.l @(r0, r14), r5
    mov.l   .L_060346A4, r0
    mov.l @(r0, r14), r6
    mov.l   .L_060346A8, r0

    .global ai_spawn_helper_b
ai_spawn_helper_b:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060346AC, r0
    mov.w @(r0, r14), r4
    mov.l   .L_060346B0, r0

    .global ai_spawn_helper_c
ai_spawn_helper_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060346B4, r0
    mov.b @(r0, r14), r4
    mov.l   .L_060346B8, r0

    .global ai_spawn_helper_d
ai_spawn_helper_d:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_060346BC, r0

    .global ai_car_full_init
ai_car_full_init:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06034698, r13
    mov.l @r13, r13
    rts
    nop
    .short  0x0000
.L_06034694:
    .long  sym_06026DBC
.L_06034698:
    .long  sym_06089EDC
.L_0603469C:
    .long  0x00000004
.L_060346A0:
    .long  0x00000008
.L_060346A4:
    .long  0x0000000C
.L_060346A8:
    .long  sym_06026E2E
.L_060346AC:
    .long  0x00000002
.L_060346B0:
    .long  mat_rot_y
.L_060346B4:
    .long  0x00000011
.L_060346B8:
    .long  camera_scene_setup
.L_060346BC:
    .long  sym_06026DF8
.L_060346C0:
    mov.l   .L_060346F0, r0
    mov.b @(r0, r14), r0
    add #-0x1, r0
    mov.l   .L_060346F4, r1
    mov.b @(r0, r1), r2
    mov.l   .L_060346F8, r1
    mov.b @(r0, r1), r3
    mov.l   .L_060346FC, r0
    mov.b @(r0, r14), r1
    add #0x1, r1
    mov.b r1, @(r0, r14)
    cmp/ge r2, r1
    bf      .L_060346EC
    xor r2, r2
    mov.b r2, @(r0, r14)
    mov.l   .L_06034700, r0
    mov.b @(r0, r14), r1
    add #0x1, r1
    cmp/ge r3, r1
    bf      .L_060346EA
    mov.l   .L_06034704, r1
.L_060346EA:
    mov.b r1, @(r0, r14)
.L_060346EC:
    rts
    nop
.L_060346F0:
    .long  0x00000001
.L_060346F4:
    .long  sym_060631B4
.L_060346F8:
    .long  sym_060631B8
.L_060346FC:
    .long  0x00000010
.L_06034700:
    .long  0x00000011
.L_06034704:
    .long  0x00000000

    .global vblank_handler
vblank_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov r4, r14
    mov.l   .L_0603474C, r0
    mov.l @(r0, r14), r2
    mov.l   .L_06034750, r0
    mov.l r2, @(r0, r14)

    .global ai_rank_stub_a
ai_rank_stub_a:
    sts.l pr, @-r15
    bsr     .L_06034754
    nop
    lds.l @r15+, pr

    .global ai_rank_stub_b
ai_rank_stub_b:
    sts.l pr, @-r15
    bsr     .L_060347A8
    nop
    lds.l @r15+, pr

    .global position_calc_current
position_calc_current:
    sts.l pr, @-r15
    bsr     .L_06034848
    nop
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .short  0x0000
.L_0603474C:
    .long  0x0000000C
.L_06034750:
    .long  0x00000010
.L_06034754:
    mov.l   .L_0603478C, r0
    mov.l @r0, r1
    mov.l   .L_06034790, r0
    mov.l   .L_06034794, r5
    mov.l @(r0, r1), r4
    shll16 r4
    mov.l   .L_06034798, r0

    .global ranking_system_full
ranking_system_full:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r2
    mov.l   .L_06034790, r0
    mov.l @(r0, r14), r1
    add r2, r1
    mov.l   .L_0603479C, r3
    cmp/ge r3, r1
    bf      .L_0603477A
    xor r1, r1
.L_0603477A:
    mov.l r1, @(r0, r14)
    mov r1, r2
    shlr16 r2
    mov.l   .L_060347A0, r0
    and r0, r2
    mov.l   .L_060347A4, r0
    mov.l r2, @(r0, r14)
    rts
    nop
.L_0603478C:
    .long  sym_0607E944
.L_06034790:
    .long  0x00000008
.L_06034794:
    .long  0x012C0000
.L_06034798:
    .long  fpdiv_setup
.L_0603479C:
    .long  0x00060000
.L_060347A0:
    .long  0x00000007
.L_060347A4:
    .long  0x0000000C
.L_060347A8:
    mov.l   .L_06034824, r0
    mov.l @(r0, r14), r1
    mov #0x1, r3
    cmp/eq r3, r1
    bf      .L_060347C8
    mov.l   .L_06034828, r0
    mov.l @(r0, r14), r0
    xor r1, r0
    tst r0, r0
    bt      .L_060347C8
    mov.l   .L_0603482C, r0
    mov.l   .L_06034830, r1
    mov.b r1, @(r0, r14)
    mov.l   .L_06034834, r0
    xor r1, r1
    mov.b r1, @(r0, r14)
.L_060347C8:
    mov.l   .L_06034824, r0
    mov.l @(r0, r14), r1
    mov #0x5, r3
    cmp/eq r3, r1
    bf      .L_060347E8
    mov.l   .L_06034828, r0
    mov.l @(r0, r14), r0
    xor r1, r0
    tst r0, r0
    bt      .L_060347E8
    mov.l   .L_06034838, r0
    mov.l   .L_06034830, r1
    mov.b r1, @(r0, r14)
    mov.l   .L_0603483C, r0
    xor r1, r1
    mov.b r1, @(r0, r14)
.L_060347E8:
    mov.l   .L_06034834, r0
    mov.b @(r0, r14), r1
    add #0x1, r1
    mov.b r1, @(r0, r14)
    mov #0x3, r2
    and r2, r1
    mov.l   .L_06034840, r0
    mov.b r1, @(r0, r14)
    mov #0x3, r2
    cmp/eq r2, r1
    bf      .L_06034804
    mov.l   .L_0603482C, r0
    xor r1, r1
    mov.b r1, @(r0, r14)
.L_06034804:
    mov.l   .L_0603483C, r0
    mov.b @(r0, r14), r1
    add #0x1, r1
    mov.b r1, @(r0, r14)
    mov #0x3, r2
    and r2, r1
    mov.l   .L_06034844, r0
    mov.b r1, @(r0, r14)
    mov #0x3, r2
    cmp/eq r2, r1
    bf      .L_06034820
    mov.l   .L_06034838, r0
    xor r1, r1
    mov.b r1, @(r0, r14)
.L_06034820:
    rts
    nop
.L_06034824:
    .long  0x0000000C
.L_06034828:
    .long  0x00000010
.L_0603482C:
    .long  0x00000001
.L_06034830:
    .long  0xFFFFFFFF
.L_06034834:
    .long  0x00000002
.L_06034838:
    .long  0x00000004
.L_0603483C:
    .long  0x00000005
.L_06034840:
    .long  0x00000000
.L_06034844:
    .long  0x00000003
.L_06034848:
    mov.l   .L_06034860, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060348EE
    mov.l   .L_06034864, r0
    mov.l @r0, r0
    mov.l   .L_06034868, r1
    tst r1, r0
    bf      .L_0603486C
    bra     .L_060348EE
    nop
    .short  0x0000
.L_06034860:
    .long  sym_06083255
.L_06034864:
    .long  sym_0607EBC4
.L_06034868:
    .long  0x00028000
.L_0603486C:
    mov.l   .L_060348A0, r0
    mov.l @(r0, r14), r1
    mov.l   .L_060348A4, r0
    mov.l @(r0, r14), r0
    cmp/eq r1, r0
    bt      .L_060348EE
    mov.l   .L_060348A8, r0
    mov.l @r0, r1
    mov.l   .L_060348AC, r0
    mov.l @(r0, r1), r1
    mov.w   DAT_0603489e, r0
    cmp/ge r0, r1
    bt      .L_060348B0
    mov.l   .L_060348A4, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x0, r0
    bt      .L_060348E0
    cmp/eq #0x3, r0
    bt      .L_060348C8
    cmp/eq #0x4, r0
    bt      .L_060348D4
    cmp/eq #0x5, r0
    bt      .L_060348E0
    bra     .L_060348EE
    nop

    .global DAT_0603489e
DAT_0603489e:
    .short  0x0104
.L_060348A0:
    .long  0x00000010
.L_060348A4:
    .long  0x0000000C
.L_060348A8:
    .long  sym_0607E944
.L_060348AC:
    .long  0x00000008
.L_060348B0:
    mov.l   .L_060348C4, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x0, r0
    bt      .L_060348E0
    cmp/eq #0x3, r0
    bt      .L_060348C8
    cmp/eq #0x4, r0
    bt      .L_060348D4
    bra     .L_060348EE
    nop
.L_060348C4:
    .long  0x0000000C
.L_060348C8:
    mov.l   .L_060348D0, r5
    bra     .L_060348E2
    nop
    .short  0x0000
.L_060348D0:
    .long  0xAE113BFF
.L_060348D4:
    mov.l   .L_060348DC, r5
    bra     .L_060348E2
    nop
    .short  0x0000
.L_060348DC:
    .long  0xAE113CFF
.L_060348E0:
    mov.l   .L_060348F4, r5
.L_060348E2:
    mov.l   .L_060348F8, r4
    mov.l   .L_060348FC, r0

    .global lap_complete_check
lap_complete_check:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
.L_060348EE:
    rts
    nop
    .short  0x0000
.L_060348F4:
    .long  0xAE113DFF
.L_060348F8:
    .long  0x00000000
.L_060348FC:
    .long  sound_cmd_dispatch

    .global terrain_data_lookup
terrain_data_lookup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    mov.l   .L_06034928, r1
    mov.l @r1, r14
    mov.l   .L_0603492C, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x2C, r0
    bt      .L_06034934
    mov.l   .L_06034930, r0
    mov.l @(r0, r14), r0
    cmp/eq #0x28, r0
    bt      .L_06034934
    bra     .L_06034942
    nop
    .short  0x0000
.L_06034928:
    .long  sym_0607E944
.L_0603492C:
    .long  0x000000B8
.L_06034930:
    .long  0x000001BC
.L_06034934:
    mov.l   .L_06034978, r4
    mov.l   .L_0603497C, r5
    mov.l   .L_06034980, r0

    .global checkpoint_validate
checkpoint_validate:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
.L_06034942:
    mov.w   DAT_06034976, r0
    mov.l @(r0, r14), r5
    cmp/pz r5
    bt      .L_0603494C
    neg r5, r5
.L_0603494C:
    shlr8 r5
    mov #0x7, r3
    shlr2 r5
    cmp/ge r5, r3
    bt      .L_06034958
    mov #0x7, r5
.L_06034958:
    mov #0x2, r4
    mov.l   .L_06034980, r0

    .global section_transition
section_transition:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop

    .global DAT_06034976
DAT_06034976:
    .short  0x005C
.L_06034978:
    .long  0x00000000
.L_0603497C:
    .long  0xAE1128FF
.L_06034980:
    .long  sound_cmd_dispatch

    .global ai_checkpoint_section
ai_checkpoint_section:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r13
    add #-0x8, r15
    mov.l   .L_060349DC, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x0, r3
    mov r15, r5
    mov.b r3, @r2
    mov.l   .L_060349E0, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r14
    mov.l   .L_060349E4, r3
    jsr @r3
    mov r13, r4
    mov r14, r0
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global ai_checkpoint_validate
ai_checkpoint_validate:
    sts.l pr, @-r15
    mov.l   .L_060349E4, r3
    jsr @r3
    nop
    lds.l @r15+, pr
    rts
    mov #0x0, r0

/* VERIFIED: reads CD Block status registers CR1-CR4 (0x25890018-0x25890024)
 * with interrupt-masked double-read for consistency. Not AI-related.
 * Method: code audit — hardware register addresses are definitive.
 * Date: 2026-02-28
 */
    .global cd_block_read_safe
cd_block_read_safe:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r13
    add #-0x8, r15
    bsr     cd_block_read_atomic
    mov r15, r4
    mov r0, r14
    tst r14, r14
    bt      .L_060349E8
    bra     .L_06034A06
    mov r14, r0
.L_060349DC:
    .long  input_proc_analog
.L_060349E0:
    .long  input_proc_buttons
.L_060349E4:
    .long  input_proc_extended
.L_060349E8:
    mov r13, r5
    mov.l   .L_06034A94, r3
    jsr @r3
    mov r15, r4
    mov.b @r13, r4
    mov.w   DAT_06034a8e, r2
    extu.b r4, r4
    cmp/eq r2, r4
    bt      .L_06034A02
    mov #0x20, r2
    and r4, r2
    tst r2, r2
    bf      .L_06034A04
.L_06034A02:
    mov #-0x8, r14
.L_06034A04:
    mov r14, r0
.L_06034A06:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

/* VERIFIED: inner double-read helper. Saves/restores IMASK, reads CD Block
 * registers twice for consistency check. Part of cd_block_read_safe family.
 * Method: code audit — same CD Block register addresses as cd_block_read_safe.
 * Date: 2026-02-28
 */
    .global cd_block_read_atomic
cd_block_read_atomic:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov #0x0, r12
    mov.l   .L_06034A98, r14
    mov r4, r11
    mov #-0x3, r10
    mov r12, r13
.L_06034A2A:
    stc sr, r0
    shlr2 r0
    shlr2 r0
    and #0xF, r0
    mov r0, r9
    stc sr, r0
    mov.w   .L_06034A90, r3
    and r3, r0
    or #0xF0, r0
    ldc r0, sr
    jsr @r14
    mov r11, r4
    jsr @r14
    mov r15, r4
    mov r9, r0
    and #0xF, r0
    shll2 r0
    shll2 r0
    stc sr, r2
    mov.w   .L_06034A90, r3
    and r3, r2
    or r2, r0
    ldc r0, sr
    mov r11, r4
    mov r15, r2
    mov.l @r4, r3
    mov.l @r2, r2
    cmp/eq r2, r3
    bf      .L_06034A72
    mov r15, r2
    mov.l @(4, r4), r3
    mov.l @(4, r2), r2
    cmp/eq r2, r3
    bf      .L_06034A72
    bra     .L_06034A7A
    mov r12, r10
.L_06034A72:
    add #0x1, r13
    mov #0x64, r2
    cmp/ge r2, r13
    bf      .L_06034A2A
.L_06034A7A:
    mov r10, r0
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06034a8e
DAT_06034a8e:
    .short  0x00FF
.L_06034A90:
    .short  0xFF0F
    .short  0xFFFF
.L_06034A94:
    .long  sym_06035F16
.L_06034A98:
    .long  sym_06035E5E

    .global ai_nop_stub
ai_nop_stub:
    mov.l r14, @-r15
    mov r4, r14

    .global ai_pit_stop_logic
ai_pit_stop_logic:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_06034B44, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x1, r3
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    add #0x8, r5
    mov.b r3, @r2
    mov.l   .L_06034B48, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.b @(2, r2), r0
    mov r0, r3
    mov.b r3, @r14
    mov r15, r3
    mov.b @(3, r3), r0
    mov r15, r3
    mov.b r0, @(1, r14)
    mov.b @(5, r3), r0
    mov r15, r3
    mov.b r0, @(2, r14)
    mov.b @(6, r3), r0
    mov r15, r3
    mov.b r0, @(3, r14)
    mov.b @(7, r3), r0
    mov r0, r2
    mov.b r0, @(4, r14)
    mov r4, r0
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global track_intersect_test
track_intersect_test:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x14, r15
    mov r15, r4
    mov.l   .L_06034B44, r3
    jsr @r3
    add #0xC, r4
    mov r15, r2
    mov #0x2, r3
    mov r15, r6
    mov r15, r5
    add #0xC, r2
    add #0x4, r6
    add #0xC, r5
    mov.b r3, @r2
    mov.l   .L_06034B48, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06034B24
    mov r4, r0
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06034B24:
    mov r15, r3
    mov r14, r5
    add #0x4, r3
    mov.l @r3, r2
    mov.l   .L_06034B4C, r3
    and r3, r2
    mov.l r2, @r15
    mov.l   .L_06034B50, r3
    jsr @r3
    mov r2, r4
    mov r0, r4
    add #0x14, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0xFFFF
.L_06034B44:
    .long  input_proc_analog
.L_06034B48:
    .long  input_proc_digital
.L_06034B4C:
    .long  0x00FFFFFF
.L_06034B50:
    .long  smpc_secondary_proc

    .global mesh_boundary_check
mesh_boundary_check:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov r5, r13

    .global ai_crash_recovery
ai_crash_recovery:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_06034BF8, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x3, r3
    extu.b r14, r14
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r14, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    add #0x8, r2
    mov.b r0, @(1, r2)
    mov.l   .L_06034BFC, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov r4, r0
    mov.l @(4, r2), r3
    mov.l r3, @r13
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global road_segment_query
road_segment_query:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    mov r6, r13
    mov.l r11, @-r15
    mov r7, r12

    .global ai_drafting_calc
ai_drafting_calc:
    sts.l pr, @-r15
    mov r5, r11
    add #-0xC, r15
    mov r15, r4
    mov.l   .L_06034BF8, r3
    jsr @r3
    add #0x4, r4
    mov r15, r2
    mov #0x4, r3
    extu.w r11, r11
    extu.b r13, r13
    extu.b r12, r12
    add #0x4, r2
    mov.b r3, @r2
    mov r15, r2
    extu.b r14, r3
    add #0x4, r2
    mov r3, r0
    mov.b r0, @(1, r2)
    mov r15, r3
    mov r11, r0
    add #0x4, r3
    mov.w r0, @(2, r3)
    mov r15, r3
    mov r13, r0
    add #0x4, r3
    mov.b r0, @(6, r3)
    mov r15, r3
    mov r12, r0
    add #0x4, r3
    mov.b r0, @(7, r3)
    mov.w   .L_06034BF4, r0
    and r14, r0
    cmp/eq #0x1, r0
    bf      .L_06034C2C
    mov.w   .L_06034BF6, r2
    bra     .L_06034C04
    nop
.L_06034BF4:
    .short  0x0081
.L_06034BF6:
    .short  0x0DAC
.L_06034BF8:
    .long  input_proc_analog
.L_06034BFC:
    .long  input_proc_digital
.L_06034C00:
    mov.l @r15, r2
    add #-0x1, r2
.L_06034C04:
    mov.l r2, @r15
    mov.l @r15, r3
    cmp/pl r3
    bt      .L_06034C00
    mov.l   .L_06034C7C, r3
    jsr @r3
    mov #0x41, r4
    mov r15, r5
    mov.l   .L_06034C80, r3
    add #0x4, r5
    jsr @r3
    mov #0x40, r4
    mov r0, r14
    tst r14, r14
    bf      .L_06034C38
    mov.l   .L_06034C84, r3
    jsr @r3
    nop
    bra     .L_06034C38
    nop
.L_06034C2C:
    mov r15, r5
    mov.l   .L_06034C80, r3
    add #0x4, r5
    jsr @r3
    mov #0x0, r4
    mov r0, r14
.L_06034C38:
    mov r14, r0
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global ai_brake_zone_calc
ai_brake_zone_calc:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06034C88, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x5, r3
    mov r15, r5
    mov.b r3, @r2
    mov.l   .L_06034C80, r3
    jsr @r3
    mov #0x0, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov r0, r4

    .global ai_brake_zone_adjust
ai_brake_zone_adjust:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov r4, r13
    add #-0x8, r15
    tst r13, r13
    bf      .L_06034C8C
    bra     .L_06034C8E
    mov #0x2, r4
    .short  0xFFFF
.L_06034C7C:
    .long  sym_06035C92
.L_06034C80:
    .long  input_proc_buttons
.L_06034C84:
    .long  smpc_cmd_helper_c
.L_06034C88:
    .long  input_proc_analog
.L_06034C8C:
    mov.w   .L_06034D02, r4
.L_06034C8E:
    mov.l   .L_06034D04, r3
    jsr @r3
    mov r15, r5
    mov r0, r14
    mov r13, r0
    cmp/eq #0x1, r0
    bf      .L_06034CAA
    tst r14, r14
    bf      .L_06034CAA
    mov.w @r15, r0
    extu.w r0, r0
    tst #0x80, r0
    bt      .L_06034CAA
    mov #-0x4, r14
.L_06034CAA:
    tst r14, r14
    bt      .L_06034CB4
    mov r15, r4
    bsr     ai_brake_zone_main
    add #0x4, r4
.L_06034CB4:
    mov.l   .L_06034D08, r4
    mov.l   .L_06034D0C, r3
    jsr @r3
    nop
    mov r14, r0
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global ai_brake_zone_main
ai_brake_zone_main:
    mov.l r14, @-r15
    mov r4, r14

    .global ai_brake_zone
ai_brake_zone:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_06034D10, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x6, r3
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    add #0x8, r5
    mov.b r3, @r2
    mov.l   .L_06034D14, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov r4, r0
    mov.l @r2, r3
    mov.l   .L_06034D18, r2
    and r2, r3
    mov.l r3, @r14
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06034D02:
    .short  0x0082
.L_06034D04:
    .long  input_proc_init
.L_06034D08:
    .long  0x0000FFFD
.L_06034D0C:
    .long  sym_06035C6E
.L_06034D10:
    .long  input_proc_analog
.L_06034D14:
    .long  input_proc_digital
.L_06034D18:
    .long  0x00FFFFFF

    .global ai_throttle_modulate
ai_throttle_modulate:
    mov.l r14, @-r15
    mov r4, r14

    .global ai_throttle_mod
ai_throttle_mod:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06034DBC, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x10, r3
    mov r15, r5
    mov.b r3, @r2
    add #0x1, r5
    bsr     ai_throttle_adjust
    mov r14, r4
    mov r15, r2
    mov #0x10, r0
    mov r15, r5
    mov r14, r4
    mov.b @(r0, r14), r3
    add #0x5, r5
    mov r3, r0
    mov.b r0, @(4, r2)
    bsr     ai_throttle_adjust
    add #0x8, r4
    mov r15, r5
    mov.l   .L_06034DC0, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global ai_throttle_adjust
ai_throttle_adjust:
    sts.l pr, @-r15
    bra     .L_06034DD0
    mov.l @r4, r0
.L_06034D64:
    mov #0x0, r2
    mov.b r2, @r5
    mov.b @(4, r4), r0
    mov r0, r3
    mov.b r0, @(1, r5)
    mov.b @(5, r4), r0
    mov r0, r3
    bra     .L_06034D9A
    nop
.L_06034D76:
    mov r4, r0
    add #0x4, r0
    mov.b @(1, r0), r0
    extu.b r0, r0
    or #0x80, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov r4, r3
    add #0x4, r3
    mov.b @(2, r3), r0
    mov r0, r2
    mov r2, r0
    mov.b r0, @(1, r5)
    mov r4, r3
    add #0x4, r3
    mov.b @(3, r3), r0
    mov r0, r2
    mov r2, r0
.L_06034D9A:
    bra     .L_06034DE4
    mov.b r0, @(2, r5)
.L_06034D9E:
    mov r5, r1
    mov.l   .L_06034DC4, r2
    mov.l   .L_06034DC8, r3
    jsr @r3
    mov #0x3, r0
    bra     .L_06034DE4
    nop
.L_06034DAC:
    mov r5, r1
    mov.l   .L_06034DCC, r2
    mov.l   .L_06034DC8, r3
    jsr @r3
    mov #0x3, r0
    bra     .L_06034DE4
    nop
    .short  0xFFFF
.L_06034DBC:
    .long  input_proc_analog
.L_06034DC0:
    .long  input_proc_buttons
.L_06034DC4:
    .long  sym_06059CA7
.L_06034DC8:
    .long  sym_06035228
.L_06034DCC:
    .long  sym_06059CA4
.L_06034DD0:
    cmp/eq #0x0, r0
    bt      .L_06034DAC
    cmp/eq #0x1, r0
    bt      .L_06034D76
    cmp/eq #0x2, r0
    bt      .L_06034D64
    cmp/eq #0x3, r0
    bt      .L_06034D9E
    bra     .L_06034DAC
    nop
.L_06034DE4:
    lds.l @r15+, pr
    rts
    nop

    .global ai_recovery_handler
ai_recovery_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x8, r15
    mov.l   .L_06034E18, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x11, r3
    mov r15, r5
    mov.b r3, @r2
    add #0x1, r5
    bsr     ai_throttle_adjust
    mov r14, r4
    mov r15, r5
    mov.l   .L_06034E1C, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_06034E18:
    .long  input_proc_analog
.L_06034E1C:
    .long  input_proc_buttons
