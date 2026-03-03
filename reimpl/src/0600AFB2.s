	.text
    .global camera_track_setup
camera_track_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    .byte   0xDB, 0x1F    /* mov.l .L_0600B03C, r11 */
    .byte   0xDD, 0x20    /* mov.l .L_0600B040, r13 */
    .byte   0xDE, 0x20    /* mov.l .L_0600B044, r14 */
    .byte   0xD3, 0x21    /* mov.l .L_0600B048, r3 */
    mov.l @r14, r14
    mov.l r14, @r3
    .byte   0xD3, 0x20    /* mov.l .L_0600B04C, r3 */
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    .byte   0xD3, 0x1F    /* mov.l .L_0600B050, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    mov.l @(32, r14), r4
    .byte   0xD2, 0x1E    /* mov.l .L_0600B054, r2 */
    .byte   0xD3, 0x1E    /* mov.l .L_0600B058, r3 */
    jsr @r3
    add r2, r4
    mov.l @(36, r14), r4
    .byte   0xD3, 0x1D    /* mov.l .L_0600B05C, r3 */
    jsr @r3
    neg r4, r4
    .byte   0xD2, 0x10    /* mov.l .L_0600B02C, r2 */
    .byte   0xD3, 0x1C    /* mov.l .L_0600B060, r3 */
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600B068
    mov.l @(28, r14), r4
    neg r4, r4
    mov.w @r11, r3
    extu.w r3, r2
    shll2 r2
    .byte   0xD3, 0x18    /* mov.l .L_0600B064, r3 */
    add r2, r3
    mov.l @r3, r2
    bra     .L_0600B080
    add r2, r4
    .short  0xFFFF
    .long  sym_06083258
    .long  sym_060621D8
    .long  sym_0606212C
    .long  sym_06031D8C
    .long  sym_06062180
    .long  sym_06089E44
    .long  sym_060620D8
    .long  sym_06031A28
.L_0600B02C:
    .long  sym_0607EBC4
    .long  0x20020000
    .long  replay_playback
    .long  sym_06089EDC
.L_0600B03C:
    .long  sym_06063F46
.L_0600B040:
    .long  mat_rot_xz_b
.L_0600B044:
    .long  sym_0607E944
.L_0600B048:
    .long  sym_0607E940
.L_0600B04C:
    .long  sym_06027080
.L_0600B050:
    .long  sym_060270F2
.L_0600B054:
    .long  0x00008000
.L_0600B058:
    .long  mat_rot_xy_b
.L_0600B05C:
    .long  mat_rot_yz_b
.L_0600B060:
    .long  0x00800008
.L_0600B064:
    .long  sym_0605BDCC
.L_0600B068:
    mov.l @(28, r14), r4
    neg r4, r4
    .byte   0xD3, 0x26    /* mov.l .L_0600B108, r3 */
    mov.l @r3, r3
    add r3, r4
    mov.w @r11, r2
    extu.w r2, r1
    shll2 r1
    .byte   0xD2, 0x24    /* mov.l .L_0600B10C, r2 */
    add r1, r2
    mov.l @r2, r1
    add r1, r4
.L_0600B080:
    jsr @r13
    nop
    mov.w   DAT_0600b100, r0
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r3
    add r3, r4
    .byte   0xD3, 0x20    /* mov.l .L_0600B110, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x1F    /* mov.l .L_0600B114, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B17A
    .byte   0xD5, 0x1E    /* mov.l .L_0600B118, r5 */
    .byte   0xD4, 0x1F    /* mov.l .L_0600B11C, r4 */
    .byte   0xD3, 0x1F    /* mov.l .L_0600B120, r3 */
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x1E    /* mov.l .L_0600B124, r6 */
    .byte   0xD5, 0x1F    /* mov.l .L_0600B128, r5 */
    .byte   0xD4, 0x1F    /* mov.l .L_0600B12C, r4 */
    .byte   0xD3, 0x20    /* mov.l .L_0600B130, r3 */
    mov.l @r6, r6
    mov.w @r5, r5
    extu.w r5, r5
    jsr @r3
    mov.l @r4, r4
    mov #0x0, r6
    mov.w   DAT_0600b102, r0
    .byte   0xD3, 0x1D    /* mov.l .L_0600B134, r3 */
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   DAT_0600b104, r0
    .byte   0xD3, 0x1B    /* mov.l .L_0600B138, r3 */
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   DAT_0600b106, r0
    jsr @r13
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x19    /* mov.l .L_0600B13C, r0 */
    mov.b @r0, r0
    tst #0x2, r0
    bf      .L_0600B0E2
    mov #0x0, r5
    .byte   0xBD, 0xB1    /* bsr render_obj_absolute (external 0x0600AC44) */
    mov r14, r4
.L_0600B0E2:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x1, r0
    bt.s    .L_0600B148
    mov #0x0, r12
    mov #0xD, r12
    mov.w @r11, r4
    extu.w r4, r4
    .byte   0xD3, 0x13    /* mov.l .L_0600B140, r3 */
    add r3, r4
    mov.b @r4, r4
    .byte   0xD2, 0x12    /* mov.l .L_0600B144, r2 */
    mov.l @r2, r2
    bra     .L_0600B14C
    add r2, r4

    .global DAT_0600b100
DAT_0600b100:
    .short  0x01D8

    .global DAT_0600b102
DAT_0600b102:
    .short  0x01B4

    .global DAT_0600b104
DAT_0600b104:
    .short  0x01D0

    .global DAT_0600b106
DAT_0600b106:
    .short  0x01C8
.L_0600B108:
    .long  sym_06078668
.L_0600B10C:
    .long  sym_0605BDCC
.L_0600B110:
    .long  mat_rot_xy_b
.L_0600B114:
    .long  sym_06059F30
.L_0600B118:
    .long  sym_060621E8
.L_0600B11C:
    .long  sym_0606213C
.L_0600B120:
    .long  sym_06032158
.L_0600B124:
    .long  sym_06062190
.L_0600B128:
    .long  sym_06089E44
.L_0600B12C:
    .long  sym_060620E8
.L_0600B130:
    .long  sym_06031DF4
.L_0600B134:
    .long  sym_060270F2
.L_0600B138:
    .long  mat_rot_yz_b
.L_0600B13C:
    .long  sym_06082A25
.L_0600B140:
    .long  sym_06044740
.L_0600B144:
    .long  sym_06083258
.L_0600B148:
    .byte   0xD4, 0x23    /* mov.l .L_0600B148_base, r4 */
    mov.l @r4, r4
.L_0600B14C:
    jsr @r13
    nop
    extu.w r12, r14
    .byte   0xD5, 0x22    /* mov.l .L_chain_src_a, r5 */
    .byte   0xD4, 0x22    /* mov.l .L_chain_dst_a, r4 */
    .byte   0xD3, 0x23    /* mov.l .L_fn_chain_a, r3 */
    shll2 r14
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x20    /* mov.l .L_chain_src_b, r6 */
    .byte   0xD5, 0x21    /* mov.l .L_chain_scale_b, r5 */
    .byte   0xD4, 0x21    /* mov.l .L_chain_dst_b, r4 */
    .byte   0xD3, 0x22    /* mov.l .L_fn_chain_b, r3 */
    add r14, r6
    mov.w @r5, r5
    add r14, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r3
    mov.l @r4, r4
.L_0600B17A:
    .byte   0xD2, 0x1F    /* mov.l .L_0600B02C_2, r2 */
    .byte   0xD3, 0x1F    /* mov.l .L_flag_mask_2, r3 */
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600B18C
    .byte   0xD3, 0x1E    /* mov.l .L_fn_adjust, r3 */
    jsr @r3
    nop
.L_0600B18C:
    .byte   0xD4, 0x1D    /* mov.l .L_camera_counter, r4 */
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
