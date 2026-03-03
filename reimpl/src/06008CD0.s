	.text
    .global state_mode_select_setup
state_mode_select_setup:
    sts.l pr, @-r15
    mov.l   .L_pool_06008D3C, r3
    mov.l r14, @r3
    mov.l   .L_pool_06008D40, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008D44, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008D48, r3
    mov.l r14, @r3
    mov.l   .L_pool_06008D4C, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008D50, r3
    jsr @r3
    nop
    mov.w   .L_wpool_06008D38, r2
    mov.l   .L_pool_06008D54, r3
    mov.l r2, @r3
    mov.l   .L_pool_06008D58, r3
    mov #0x5, r2
    mov.l r14, @r3
    mov.l   .L_pool_06008D5C, r3
    mov.l r2, @r3
    mov.l   .L_pool_06008D60, r4
    mov.l   .L_pool_06008D64, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_pool_06008D44, r3
    jsr @r3
    nop
    mov #0x3, r2
    mov.l   .L_pool_06008D48, r3
    mov.l r14, @r3
    mov.l   .L_pool_06008D68, r3
    mov.w r2, @r3
    mov.l   .L_pool_06008D6C, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06008D32
    mov.l   .L_pool_06008D70, r3
    jsr @r3
    nop
    extu.b r14, r14
    mov.l   .L_pool_06008D6C, r3
    mov.b r14, @r3
.L_06008D32:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_06008D38:
    .short  0x0258
    .short  0xFFFF
.L_pool_06008D3C:
    .long  sym_06078644
.L_pool_06008D40:
    .long  sym_060149E0
.L_pool_06008D44:
    .long  sym_06026CE0
.L_pool_06008D48:
    .long  sym_06059F44
.L_pool_06008D4C:
    .long  render_coord_transform
.L_pool_06008D50:
    .long  course_setup_handler
.L_pool_06008D54:
    .long  sym_0607EBCC
.L_pool_06008D58:
    .long  sym_06086024
.L_pool_06008D5C:
    .long  g_game_state
.L_pool_06008D60:
    .long  sym_0605B6D8
.L_pool_06008D64:
    .long  0x40000000
.L_pool_06008D68:
    .long  sym_0605A016
.L_pool_06008D6C:
    .long  sym_0607864B
.L_pool_06008D70:
    .long  race_state_pair_1
