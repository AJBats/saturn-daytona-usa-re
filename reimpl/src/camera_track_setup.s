
    .section .text.FUN_0600AFB2


    .global camera_track_setup
    .type camera_track_setup, @function
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
    .2byte  0xFFFF                        /* alignment padding */
    .4byte  sym_06083258               /* (adjacent fn pool: camera LOD offset base) */
    .4byte  sym_060621D8               /* (adjacent fn pool: chain A source table) */
    .4byte  sym_0606212C               /* (adjacent fn pool: chain A parameter table) */
    .4byte  sym_06031D8C               /* (adjacent fn pool: vec_copy_a fn) */
    .4byte  sym_06062180               /* (adjacent fn pool: chain B source table) */
    .4byte  sym_06089E44               /* (adjacent fn pool: rotation scale factor) */
    .4byte  sym_060620D8               /* (adjacent fn pool: chain B parameter table) */
    .4byte  sym_06031A28               /* (adjacent fn pool: vec_copy_b fn) */
.L_0600B02C:
    .4byte  sym_0607EBC4               /* game mode flags (32-bit) */
    .4byte  0x20020000                 /* (adjacent fn pool: cache-through const) */
    .4byte  replay_playback            /* (adjacent fn pool: replay playback fn) */
    .4byte  sym_06089EDC               /* (adjacent fn pool: frame counter) */
.L_0600B03C:
    .4byte  sym_06063F46               /* camera mode index (16-bit) */
.L_0600B040:
    .4byte  mat_rot_xz_b              /* XZ rotation transform */
.L_0600B044:
    .4byte  sym_0607E944               /* car array base pointer */
.L_0600B048:
    .4byte  sym_0607E940               /* current car struct pointer */
.L_0600B04C:
    .4byte  sym_06027080               /* camera state initialization */
.L_0600B050:
    .4byte  sym_060270F2               /* set camera base position */
.L_0600B054:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) / 180 degrees */
.L_0600B058:
    .4byte  mat_rot_xy_b              /* XY rotation (yaw) */
.L_0600B05C:
    .4byte  mat_rot_yz_b              /* YZ rotation (pitch) */
.L_0600B060:
    .4byte  0x00800008                 /* special camera mode flag mask */
.L_0600B064:
    .4byte  sym_0605BDCC               /* per-mode bank angle offset table */
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
    bt/s    .L_0600B148
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
    .2byte  0x01D8                        /* car offset: camera yaw */

    .global DAT_0600b102
DAT_0600b102:
    .2byte  0x01B4                        /* car offset: camera roll */

    .global DAT_0600b104
DAT_0600b104:
    .2byte  0x01D0                        /* car offset: camera pitch A */

    .global DAT_0600b106
DAT_0600b106:
    .2byte  0x01C8                        /* car offset: camera pitch B */
.L_0600B108:
    .4byte  sym_06078668               /* camera height offset value */
.L_0600B10C:
    .4byte  sym_0605BDCC               /* bank angle table (dup for reach) */
.L_0600B110:
    .4byte  mat_rot_xy_b              /* XY rotation (dup for reach) */
.L_0600B114:
    .4byte  sym_06059F30               /* camera follow mode flag */
.L_0600B118:
    .4byte  sym_060621E8               /* rotation source vector A (ptr) */
.L_0600B11C:
    .4byte  sym_0606213C               /* rotation dest vector A (ptr) */
.L_0600B120:
    .4byte  sym_06032158               /* vector matrix transform */
.L_0600B124:
    .4byte  sym_06062190               /* rotation source vector B (ptr) */
.L_0600B128:
    .4byte  sym_06089E44               /* rotation scale factor B (16-bit) */
.L_0600B12C:
    .4byte  sym_060620E8               /* rotation dest vector B (ptr) */
.L_0600B130:
    .4byte  sym_06031DF4               /* scaled vector transform */
.L_0600B134:
    .4byte  sym_060270F2               /* camera position (dup for reach) */
.L_0600B138:
    .4byte  mat_rot_yz_b              /* YZ rotation (dup for reach) */
.L_0600B13C:
    .4byte  sym_06082A25               /* camera shake flags byte */
.L_0600B140:
    .4byte  sym_06044740               /* per-mode LOD lookup table */
.L_0600B144:
    .4byte  sym_06083258               /* camera LOD offset base (ptr) */
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
