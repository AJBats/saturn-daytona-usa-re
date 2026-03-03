	.text
    .global best_lap_render
best_lap_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    mov.l   .L_pool_060327F8, r0
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    bra     .L_060327FC
    nop
    .short  0x0000
    .long  sym_06089EDC
    .long  sym_060623C8
    .long  sym_06026DBC
    .long  sym_06026E0C
    .long  0x00000010
    .long  0x00000014
    .long  0x00000018
    .long  sym_06026E2E
    .long  0x0000001E
    .long  mat_rot_y
    .long  0x0000001C
    .long  mat_rot_x
    .long  0x00000020
    .long  mat_rot_z
    .long  0x00000054
    .long  0x0000000C
    .long  0x00000022
    .long  0x00000026
    .long  0x00000024
.L_pool_060327F8:
    .long  0x00000084
.L_060327FC:
    .byte   0xD0, 0x9D    /* mov.l @cross-TU pool (render pipeline dispatch), r0 */
