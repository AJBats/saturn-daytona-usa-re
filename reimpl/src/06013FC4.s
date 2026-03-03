	.text
    .global bg_obj_render_loop
bg_obj_render_loop:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x8, r15
    mov.l   .L_pool_06014088, r8
    mov.l   .L_pool_0601408C, r9
    mov.l   .L_pool_06014090, r10
    mov.l   .L_pool_06014094, r13
    mov.l   .L_pool_06014098, r3
    jsr @r3
    nop
    mov #0x0, r5
    mov r5, r11
    mov.l   .L_pool_0601409C, r4
    mov r4, r14
    add r5, r14
    mov.w   DAT_06014080, r2
    add r2, r4
    mov.l r4, @(4, r15)
    mov.l   .L_pool_060140A0, r3
    mov.l r3, @r15
.L_06013FFA:
    mov.l   .L_pool_060140A4, r3
    jsr @r3
    mov r14, r12
    mov r13, r6
    mov.w   DAT_06014082, r5
    jsr @r10
    mov #0x0, r4
    mov.w @(24, r12), r0
    jsr @r8
    mov r0, r4
    mov #0x0, r6
    mov.l @r12, r5
    jsr @r10
    mov r6, r4
    mov.w @(24, r12), r0
    mov r0, r4
    jsr @r8
    neg r4, r4
    mov.l   .L_pool_060140A8, r5
    mov.w   DAT_06014084, r4
    mov.l   .L_pool_060140AC, r3
    mov.w @r5, r5
    extu.w r5, r5
    mul.l r13, r5
    jsr @r3
    sts macl, r5
    mov.w   DAT_06014086, r12
    mov.l   .L_pool_060140B0, r3
    add r0, r12
    mov r12, r6
    mov r12, r5
    jsr @r3
    mov r12, r4
    mov #0x4, r5
    mov r11, r12
    mov.l   .L_pool_060140B4, r4
    mov.l   .L_pool_060140B8, r3
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov #0x1, r6
    mov.l @r15, r5
    mov.l   .L_pool_060140BC, r4
    mov.l   .L_pool_060140C0, r3
    mov.w @r5, r5
    add r12, r4
    jsr @r3
    mov.l @r4, r4
    add #0x20, r14
    mov.l @r9, r2
    add #-0x30, r2
    mov.l r2, @r9
    mov.l @(4, r15), r3
    cmp/hs r3, r14
    bf.s    .L_06013FFA
    add #0x4, r11
    add #0x8, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06014080
DAT_06014080:
    .short  0x03A0

    .global DAT_06014082
DAT_06014082:
    .short  0x8000

    .global DAT_06014084
DAT_06014084:
    .short  0x03D7

    .global DAT_06014086
DAT_06014086:
    .short  0xB334
.L_pool_06014088:
    .long  mat_rot_z
.L_pool_0601408C:
    .long  sym_06089EDC
.L_pool_06014090:
    .long  sym_06026E2E
.L_pool_06014094:
    .long  0x00010000
.L_pool_06014098:
    .long  sym_06026E0C
.L_pool_0601409C:
    .long  sym_0605AD5C
.L_pool_060140A0:
    .long  sym_06089E4A
.L_pool_060140A4:
    .long  sym_06026DBC
.L_pool_060140A8:
    .long  sym_06084AF6
.L_pool_060140AC:
    .long  fpmul
.L_pool_060140B0:
    .long  mat_scale_columns
.L_pool_060140B4:
    .long  sym_06062338
.L_pool_060140B8:
    .long  sym_06031D8C
.L_pool_060140BC:
    .long  sym_060622C0
.L_pool_060140C0:
    .long  sym_06031A28
