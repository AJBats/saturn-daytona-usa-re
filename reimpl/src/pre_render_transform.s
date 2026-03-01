
    .section .text.FUN_060061C8


    .global pre_render_transform
    .type pre_render_transform, @function
pre_render_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   _pool_car_struct_ptr, r11
    mov.l   _pool_fn_render_init, r3
    mov.l @r11, r11
    mov.l @(16, r11), r14
    mov.l @(20, r11), r13
    jsr @r3
    mov.l @(24, r11), r12
    mov.l   _pool_fn_render_push, r3
    jsr @r3
    nop
    mov.l   _pool_fn_mat_rot_y, r3
    jsr @r3
    mov.l @(48, r11), r4
    mov.l   _pool_fn_mat_vec_xform, r11
    mov.l   _pool_geom_ch0_out, r5
    mov.l   _pool_geom_ch0_src, r4
    jsr @r11
    nop
    mov.l   _pool_geom_ch1_out, r5
    mov.l   _pool_geom_ch1_src, r4
    jsr @r11
    nop
    mov.l   _pool_geom_ch2_out, r5
    mov.l   _pool_geom_ch2_src, r4
    jsr @r11
    nop
    mov.l   _pool_geom_ch3_out, r5
    mov.l   _pool_geom_ch3_src, r4
    jsr @r11
    nop
    mov.l   _pool_geom_ch0_out, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   _pool_geom_ch1_out, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   _pool_geom_ch2_out, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   _pool_geom_ch3_out, r4
    mov.l @r4, r2
    add r14, r2
    mov.l r2, @r4
    mov.l r13, @(4, r4)
    mov.l @(8, r4), r3
    add r12, r3
    mov.l r3, @(8, r4)
    mov.l   _pool_render_budget, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
_pool_car_struct_ptr:
    .4byte  sym_0607E940
_pool_fn_render_init:
    .4byte  sym_06026DBC
_pool_fn_render_push:
    .4byte  sym_06026E0C
_pool_fn_mat_rot_y:
    .4byte  mat_rot_y
_pool_fn_mat_vec_xform:
    .4byte  mat_vec_transform
_pool_geom_ch0_out:
    .4byte  sym_06063E9C
_pool_geom_ch0_src:
    .4byte  sym_0604464C
_pool_geom_ch1_out:
    .4byte  sym_06063EB0
_pool_geom_ch1_src:
    .4byte  sym_06044640
_pool_geom_ch2_out:
    .4byte  sym_06063ED8
_pool_geom_ch2_src:
    .4byte  sym_06044658
_pool_geom_ch3_out:
    .4byte  sym_06063EC4
_pool_geom_ch3_src:
    .4byte  sym_06044664
_pool_render_budget:
    .4byte  sym_06089EDC
