
    .section .text.FUN_0602DE62


    .global vdp1_distorted_sprite
    .type vdp1_distorted_sprite, @function
vdp1_distorted_sprite:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD2, 0x05    /* mov.l .L_ptr_vtx_update_timer, r2 */ ! r2 = &vtx_update_timer (sym_06082A40)
    mov.l @r2, r0
    tst r0, r0
    bf      .L_update_active
    bra     .L_no_update
    nop
    .4byte  sym_06082A30
    .4byte  0x00000002
    .4byte  sym_06082A3C
.L_ptr_vtx_update_timer:
    .4byte  sym_06082A40
    .4byte  sym_06082A54
    .4byte  sym_06082A58
    .4byte  sym_06082A44
    .4byte  sym_06082A48
    .4byte  sym_06082A50
    .4byte  0x00000010
    .4byte  sym_06082A70
    .4byte  sym_06034FFC
    .4byte  0x00000000
    .4byte  sym_06082A6C
    .4byte  0x00000008
    .4byte  sym_06082A78
    .4byte  sym_06082A74
    .4byte  0x00000004
    .4byte  sym_06063EEC
    .4byte  sym_06082A5C
    .4byte  sym_06063EF0
    .4byte  sym_06082A60
    .4byte  0x00000001
    .4byte  sym_06063E24
    .4byte  sym_06082A68
    .4byte  car_param_lookup
.L_update_active:
    add #-0x1, r0
    mov.l r0, @r2
    .byte   0xD2, 0x09    /* mov.l .L_ptr_dirty_flags, r2 */ ! r2 = &dirty_flags (sym_06082A3C)
    mov.l @r2, r4
    mov r4, r0
    .byte   0xD1, 0x09    /* mov.l .L_bit_ax, r1 */ ! r1 = 0x10 (AX channel bit)
    tst r1, r0
    bt      .L_ax_done
    .byte   0xD0, 0x08    /* mov.l .L_ptr_ax_src, r0 */ ! r0 = &vtx_ax_src (sym_06082A54)
    mov.l @r0, r3
    .byte   0xD1, 0x08    /* mov.l .L_ptr_ax_dst, r1 */ ! r1 = &vtx_ax_dst (sym_06082A70)
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_ax_src_ge_dst
    .byte   0xD0, 0x07    /* mov.l .L_ptr_ax_wrap, r0 */ ! r0 = &vtx_ax_wrap (sym_06082A6C)
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_ax_use_dst
    bra     .L_ax_use_src
    nop
    .2byte  0x0000
.L_ptr_dirty_flags:
    .4byte  sym_06082A3C
.L_bit_ax:
    .4byte  0x00000010
.L_ptr_ax_src:
    .4byte  sym_06082A54
.L_ptr_ax_dst:
    .4byte  sym_06082A70
.L_ptr_ax_wrap:
    .4byte  sym_06082A6C
.L_ax_src_ge_dst:
    .byte   0xD0, 0x03    /* mov.l .L_ptr_ax_wrap_2, r0 */ ! r0 = &vtx_ax_wrap
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_ax_use_dst
.L_ax_use_src:
    mov.l r3, @r1
    bra     .L_ax_done
    nop
.L_ptr_ax_wrap_2:
    .4byte  sym_06082A6C
.L_ax_use_dst:
    mov.l r2, @r1
.L_ax_done:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_bit_ay, r1 */ ! r1 = 0x8 (AY channel bit)
    tst r1, r0
    bt      .L_ay_done
    .byte   0xD0, 0x07    /* mov.l .L_ptr_ay_src, r0 */ ! r0 = &vtx_ay_src (sym_06082A58)
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_ptr_ay_dst, r1 */ ! r1 = &vtx_ay_dst (sym_06082A78)
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_ay_src_ge_dst
    .byte   0xD0, 0x06    /* mov.l .L_ptr_ay_wrap, r0 */ ! r0 = &vtx_ay_wrap (sym_06082A74)
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_ay_use_dst
    bra     .L_ay_use_src
    nop
.L_bit_ay:
    .4byte  0x00000008
.L_ptr_ay_src:
    .4byte  sym_06082A58
.L_ptr_ay_dst:
    .4byte  sym_06082A78
.L_ptr_ay_wrap:
    .4byte  sym_06082A74
.L_ay_src_ge_dst:
    .byte   0xD0, 0x03    /* mov.l .L_ptr_ay_wrap_2, r0 */ ! r0 = &vtx_ay_wrap
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_ay_use_dst
.L_ay_use_src:
    mov.l r3, @r1
    bra     .L_ay_done
    nop
.L_ptr_ay_wrap_2:
    .4byte  sym_06082A74
.L_ay_use_dst:
    mov.l r2, @r1
.L_ay_done:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_bit_bx, r1 */ ! r1 = 0x4 (BX channel bit)
    tst r1, r0
    bt      .L_bx_done
    .byte   0xD0, 0x07    /* mov.l .L_ptr_bx_src, r0 */ ! r0 = &vtx_bx_src (sym_06082A44)
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_ptr_bx_dst, r1 */ ! r1 = &camera_pitch (sym_06063EEC)
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_bx_src_ge_dst
    .byte   0xD0, 0x06    /* mov.l .L_ptr_bx_wrap, r0 */ ! r0 = &vtx_bx_wrap (sym_06082A5C)
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_bx_use_dst
    bra     .L_bx_use_src
    nop
.L_bit_bx:
    .4byte  0x00000004
.L_ptr_bx_src:
    .4byte  sym_06082A44
.L_ptr_bx_dst:
    .4byte  sym_06063EEC
.L_ptr_bx_wrap:
    .4byte  sym_06082A5C
.L_bx_src_ge_dst:
    .byte   0xD0, 0x03    /* mov.l .L_ptr_bx_wrap_2, r0 */ ! r0 = &vtx_bx_wrap
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_bx_use_dst
.L_bx_use_src:
    mov.l r3, @r1
    bra     .L_bx_done
    nop
.L_ptr_bx_wrap_2:
    .4byte  sym_06082A5C
.L_bx_use_dst:
    mov.l r2, @r1
.L_bx_done:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_bit_by, r1 */ ! r1 = 0x2 (BY channel bit)
    tst r1, r0
    bt      .L_by_done
    .byte   0xD0, 0x07    /* mov.l .L_ptr_by_src, r0 */ ! r0 = &vtx_by_src (sym_06082A48)
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_ptr_by_dst, r1 */ ! r1 = &camera_yaw_ext (sym_06063EF0)
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_by_src_ge_dst
    .byte   0xD0, 0x06    /* mov.l .L_ptr_by_wrap, r0 */ ! r0 = &vtx_by_wrap (sym_06082A60)
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_by_use_dst
    bra     .L_by_use_src
    nop
.L_bit_by:
    .4byte  0x00000002
.L_ptr_by_src:
    .4byte  sym_06082A48
.L_ptr_by_dst:
    .4byte  sym_06063EF0
.L_ptr_by_wrap:
    .4byte  sym_06082A60
.L_by_src_ge_dst:
    .byte   0xD0, 0x03    /* mov.l .L_ptr_by_wrap_2, r0 */ ! r0 = &vtx_by_wrap
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_by_use_dst
.L_by_use_src:
    mov.l r3, @r1
    bra     .L_by_done
    nop
.L_ptr_by_wrap_2:
    .4byte  sym_06082A60
.L_by_use_dst:
    mov.l r2, @r1
.L_by_done:
    mov r4, r0
    .byte   0xD1, 0x07    /* mov.l .L_bit_c, r1 */ ! r1 = 0x1 (C channel bit)
    tst r1, r0
    bt      .L_all_done
    .byte   0xD0, 0x07    /* mov.l .L_ptr_c_src, r0 */ ! r0 = &vtx_c_src (sym_06082A50)
    mov.l @r0, r3
    .byte   0xD1, 0x07    /* mov.l .L_ptr_c_dst, r1 */ ! r1 = &camera_eye_y (sym_06063E24)
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_c_src_ge_dst
    .byte   0xD0, 0x06    /* mov.l .L_ptr_c_wrap, r0 */ ! r0 = &vtx_c_wrap (sym_06082A68)
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_c_use_dst
    bra     .L_c_use_src
    nop
.L_bit_c:
    .4byte  0x00000001
.L_ptr_c_src:
    .4byte  sym_06082A50
.L_ptr_c_dst:
    .4byte  sym_06063E24
.L_ptr_c_wrap:
    .4byte  sym_06082A68
.L_c_src_ge_dst:
    .byte   0xD0, 0x03    /* mov.l .L_ptr_c_wrap_2, r0 */ ! r0 = &vtx_c_wrap
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_c_use_dst
.L_c_use_src:
    mov.l r3, @r1
    bra     .L_all_done
    nop
.L_ptr_c_wrap_2:
    .4byte  sym_06082A68
.L_c_use_dst:
    mov.l r2, @r1
.L_all_done:
    rts
    nop
.L_no_update:
    .byte   0xD1, 0x04    /* mov.l .L_ptr_aux_counter, r1 */ ! r1 = &aux_counter (sym_06082A38)
    mov.l @r1, r0
    add #0x1, r0
    mov.l r0, @r1
    .byte   0xD1, 0x03    /* mov.l .L_ptr_render_state, r1 */ ! r1 = &render_state (sym_06082A30)
    .byte   0xD0, 0x03    /* mov.l .L_const_one, r0 */ ! r0 = 0x1
    mov.l r0, @r1
    .byte   0xAE, 0x52    /* bra 0x0602DD10 (external) */ ! branch to VDP1 cmd list builder (loc_0602DD10)
    nop
.L_ptr_aux_counter:
    .4byte  sym_06082A38
.L_ptr_render_state:
    .4byte  sym_06082A30
.L_const_one:
    .4byte  0x00000001

    .global loc_0602E078
loc_0602E078:
    .byte   0xDD, 0x12    /* mov.l .L_pool_0602E0C4, r13 */ ! r13 = next cmd builder fn (from adjacent pool)
