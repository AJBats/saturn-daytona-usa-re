	.text
    .global display_mode_switch
display_mode_switch:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032FE8, r13
    mov.l @r13, r13
    rts
    nop
    .long  sym_06026DBC
.L_pool_06032FE8:
    .long  sym_06089EDC
    .long  0x00000000
    .long  0x00000004
    .long  0x00000008
    .long  sym_06026E2E
    .long  0x0000000C
    .long  mat_rot_y
    .long  0x0000000E
    .long  sym_060624C8
    .long  mat_rot_z
    .long  camera_pos_calc
    .long  sym_06026DF8
    .long  0x00000010
    .long  camera_push_save
