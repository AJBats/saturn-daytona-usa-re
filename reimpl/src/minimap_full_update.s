
    .section .text.FUN_06015754


    .global minimap_full_update
    .type minimap_full_update, @function
minimap_full_update:
    sts.l pr, @-r15
    mov r4, r3
    mov.l   .L_slot_data_base, r13
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(16, r4), r2
    mov.l @(4, r4), r3
    add r2, r3
    mov.l r3, @(4, r4)
    mov.l @(20, r4), r2
    mov.l @(8, r4), r3
    add r2, r3
    mov.l r3, @(8, r4)
    mov.l @(24, r4), r2
    mov.l @(12, r4), r3
    add r2, r3
    mov.l r3, @(12, r4)
    extu.b r14, r4
    mov r4, r0
    cmp/eq #0x1, r0
    .word 0x0029
    mov r0, r3
    mov r4, r0
    cmp/eq #0x3, r0
    .word 0x0129
    or r1, r3
    tst r3, r3
    bt      .L_decay_clamp
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/ge r3, r2
    bf      .L_clamp_x_done
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    bra     .L_clamp_x_done
    mov.l r2, @(4, r4)
.L_slot_data_base:
    .4byte  sym_06084FC8
.L_decay_clamp:
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(4, r4), r2
    mov.l @(52, r4), r3
    cmp/gt r3, r2
    bt      .L_clamp_x_done
    extu.b r14, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.l @(52, r4), r2
    mov.l r2, @(4, r4)
.L_clamp_x_done:
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(8, r3), r3
    cmp/pz r3
    bf      .L_clamp_y_done
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov #0x0, r1
    mov.l r1, @(8, r3)
.L_clamp_y_done:
    extu.b r14, r3
    mov.l   .L_fp_one, r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l @(12, r3), r3
    cmp/ge r4, r3
    bf      .L_clamp_z_done
    extu.b r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l r4, @(12, r3)
.L_clamp_z_done:
    mov.l   .L_track_vtx_builder, r3
    jsr @r3
    extu.b r14, r4
    extu.b r14, r4
    mov #0x41, r0
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r13, r4
    mov.b @(r0, r4), r2
    add #-0x1, r2
    mov.b r2, @(r0, r4)
    mov.b @(r0, r4), r3
    extu.b r3, r3
    cmp/pl r3
    bt      .L_epilogue
    extu.b r14, r14
    mov r14, r2
    shll2 r14
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r14
    exts.w r14, r14
    add r13, r14
    mov.b @(2, r14), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r14)
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global loc_060158A4
loc_060158A4:
    rts
    nop
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_track_vtx_builder:
    .4byte  track_vtx_builder

    .global loc_060158B0
loc_060158B0:
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    .byte   0xD1, 0x1B    /* mov.l .L_pool_06015934, r1 */  ! r1 = sym_06084FC8 (slot array base, cross-TU pool)
    add r1, r3
    mov.b @(2, r3), r0
    mov r0, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x19    /* mov.l .L_pool_06015938, r2 */  ! r2 = handler table base (cross-TU pool)
    add r2, r3
    mov.l @r3, r3
    mov.b @r15, r4
    jmp @r3
    add #0x4, r15
