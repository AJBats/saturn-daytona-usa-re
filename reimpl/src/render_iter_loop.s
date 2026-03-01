
    .section .text.FUN_060140C8


    .global render_iter_loop
    .type render_iter_loop, @function
render_iter_loop:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06014138, r4
    mov.l @r4, r3
    cmp/hi r2, r3
    bt      .L_0601412E
    mov.l @r4, r2
    mov.l   .L_pool_0601413C, r3
    shll2 r2
    add r3, r2
    mov.l @r2, r1
    mov.l   .L_pool_06014140, r2
    jsr @r2
    mov.l r1, @r15
    mov.l   .L_pool_06014144, r14
    mov.w   .L_wpool_06014136, r5
    mov.l   .L_pool_06014148, r3
    mov r14, r6
    jsr @r3
    mov.l @r15, r4
    mov r14, r6
    mov r14, r5
    mov.l   .L_pool_0601414C, r3
    jsr @r3
    mov r14, r4
    .byte   0xBE, 0x8A    /* bsr 0x06013E12 (external) */
    nop
    mov #0x4, r5
    mov.l   .L_pool_06014150, r4
    mov.l   .L_pool_06014154, r3
    mov.l   .L_pool_06014158, r2
    mov.l @r4, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov #0x1, r6
    mov.l   .L_pool_0601415C, r5
    mov.l   .L_pool_06014150, r4
    mov.l   .L_pool_06014160, r3
    mov.l   .L_pool_06014164, r2
    mov.w @r5, r5
    mov.l @r4, r4
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_pool_06014168, r4
    mov.l @r4, r3
    add #-0x30, r3
    mov.l r3, @r4
.L_0601412E:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_06014136:
    .2byte  0xCCCD                               /* ~-0.2 (16.16 fixed-point, sign-extended) */
.L_pool_06014138:
    .4byte  sym_06084B18                         /* object iteration counter */
.L_pool_0601413C:
    .4byte  sym_0605AD4C                         /* object pointer array base */
.L_pool_06014140:
    .4byte  sym_06026DBC                         /* pre-transform setup function */
.L_pool_06014144:
    .4byte  0x00010000                           /* 1.0 (16.16 fixed-point) */
.L_pool_06014148:
    .4byte  sym_06026E2E                         /* position transform dispatch */
.L_pool_0601414C:
    .4byte  mat_scale_columns                    /* matrix column scaling */
.L_pool_06014150:
    .4byte  sym_06084B08                         /* active car slot index */
.L_pool_06014154:
    .4byte  sym_06062338                         /* object transform table A */
.L_pool_06014158:
    .4byte  sym_06031D8C                         /* transform chain dispatch A */
.L_pool_0601415C:
    .4byte  sym_06089E4A                         /* display mode selector (16-bit) */
.L_pool_06014160:
    .4byte  sym_060622C0                         /* display transform table B */
.L_pool_06014164:
    .4byte  sym_06031A28                         /* transform chain dispatch B */
.L_pool_06014168:
    .4byte  sym_06089EDC                         /* render budget counter (dec by 0x30/obj) */
