
    .section .text.FUN_0602DC68


    .global vdp1_scaled_sprite
    .type vdp1_scaled_sprite, @function
vdp1_scaled_sprite:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602DCA8, r1
    mov.l   .L_0602DCAC, r0
    mov.b r0, @r1
    mov.l   .L_0602DCB0, r1
    mov.l   .L_0602DCB4, r2
    add r2, r1
    mov.l @r1, r2
    mov.l   .L_0602DCB8, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_0602DCBC, r0
    mov.l @(r0, r3), r0
    cmp/gt r2, r0
    bf      .L_0602DCC4
    mov.l   .L_0602DCC0, r3
    add r3, r2
    cmp/gt r2, r0
    bf      .L_0602DCC4
    mov.l r2, @r1
    bra     .L_0602DCC6
    nop
    .4byte  sym_06082A2C
    .4byte  0x00000028
    .4byte  disp_init_setup
.L_0602DCA8:
    .4byte  sym_06082A26
.L_0602DCAC:
    .4byte  0x00000001
.L_0602DCB0:
    .4byte  sym_06063EEC
.L_0602DCB4:
    .4byte  0x00000004
.L_0602DCB8:
    .4byte  sym_0607EAD8
.L_0602DCBC:
    .4byte  sym_0602ECAC
.L_0602DCC0:
    .4byte  0x00000100
.L_0602DCC4:
    mov.l r0, @r1
.L_0602DCC6:
    mov.l   .L_0602DCEC, r0
    mov.l @r0, r0
    mov.l   .L_0602DCF0, r1
    mov.l @(r0, r1), r4
    mov.l   .L_0602DCF4, r1
    cmp/eq r1, r4
    bf      .L_0602DCE6
    mov.l   .L_0602DCF8, r4
    mov.l   .L_0602DCFC, r1
    mov.b r1, @r4
    mov.l   .L_0602DD00, r4
    mov.l   .L_0602DD04, r1
    mov.b r1, @r4
    mov.l   .L_0602DD08, r4
    mov.l   .L_0602DD0C, r1
    mov.l r1, @r4
.L_0602DCE6:
    rts
    nop
    .2byte  0x0000
.L_0602DCEC:
    .4byte  sym_0607E940
.L_0602DCF0:
    .4byte  0x00000008
.L_0602DCF4:
    .4byte  0x00000000
.L_0602DCF8:
    .4byte  sym_06082A24
.L_0602DCFC:
    .4byte  0xFFFFFFFF
.L_0602DD00:
    .4byte  sym_06082A26
.L_0602DD04:
    .4byte  0x00000002
.L_0602DD08:
    .4byte  sym_06082A30
.L_0602DD0C:
    .4byte  0x00000001

    .global loc_0602DD10
loc_0602DD10:
    mov.l   .L_0602DD40, r3
    mov.l @r3, r3
    shll2 r3
    mov.l   .L_0602DD44, r0
    mov.l @(r0, r3), r1
    mov.l   .L_0602DD48, r0
    mov.l @r0, r0
    shll2 r0
    shll2 r0
    shll r0
    add r0, r1
    mov.l @r1+, r3
    mov.l   .L_0602DD4C, r0
    cmp/eq r0, r3
    bf      .L_0602DD5C
    mov.l   .L_0602DD48, r1
    mov.l   .L_0602DD50, r0
    mov.l r0, @r1
    mov.l   .L_0602DD54, r0
    mov.l   .L_0602DD58, r1
    mov.l r1, @r0
    rts
    nop
    .2byte  0x0000
.L_0602DD40:
    .4byte  sym_0607EAD8
.L_0602DD44:
    .4byte  sym_0602ECBC
.L_0602DD48:
    .4byte  sym_06082A38
.L_0602DD4C:
    .4byte  0xFFFFFFFF
.L_0602DD50:
    .4byte  0x00000000
.L_0602DD54:
    .4byte  sym_06082A30
.L_0602DD58:
    .4byte  0x00000003
.L_0602DD5C:
    .byte   0xD0, 0x46    /* mov.l .L_xpool_ptr_render_mode, r0 */
    .byte   0xD2, 0x47    /* mov.l .L_xpool_const_0x2, r2 */
    mov.l r2, @r0
    .byte   0xD2, 0x47    /* mov.l .L_xpool_ptr_dirty_flags, r2 */
    mov.l r3, @r2
    mov.l @r1+, r4
    .byte   0xD2, 0x46    /* mov.l .L_xpool_ptr_update_timer, r2 */
    mov.l r4, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x46    /* mov.l .L_xpool_ptr_vtx_ax_src, r2 */
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x45    /* mov.l .L_xpool_ptr_vtx_ay_src, r2 */
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x45    /* mov.l .L_xpool_ptr_vtx_bx_src, r2 */
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x44    /* mov.l .L_xpool_ptr_vtx_by_src, r2 */
    mov.l r0, @r2
    mov.l @r1+, r0
    .byte   0xD2, 0x44    /* mov.l .L_xpool_ptr_vtx_c_src, r2 */
    mov.l r0, @r2
    mov r3, r0
    .byte   0xD1, 0x43    /* mov.l .L_xpool_const_0x10, r1 */
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DDB4 (external) */
    .byte   0xD1, 0x3D    /* mov.l .L_xpool_ptr_vtx_ax_src, r1 */
    mov.l @r1, r1
    .byte   0xD0, 0x42    /* mov.l .L_xpool_ptr_vtx_ax_dst, r0 */
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    .byte   0xDC, 0x41    /* mov.l .L_xpool_fn_ptr_06034FFC, r12 */
