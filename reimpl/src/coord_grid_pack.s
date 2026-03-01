
    .section .text.FUN_060067C8


    .global coord_grid_pack
    .type coord_grid_pack, @function
coord_grid_pack:
    sts.l pr, @-r15
    mov.l   .L_pool_0600681C, r3
    jsr @r3
    nop
    extu.w r0, r5
    mov.l   .L_pool_06006820, r4
    mov.l   .L_pool_06006824, r3
    jsr @r3
    mov.b @r4, r4
    mov.l   .L_pool_06006828, r7
    mov.l   .L_pool_0600682C, r6
    mov.w   DAT_06006804, r5
    mov.l   .L_fp_half, r4
    mov.l   .L_pool_06006834, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_swapped_axes
    extu.w r5, r5
    mov.w r5, @r6
    extu.w r4, r4
    bra     .L_grid_write_done
    mov.w r4, @r7
.L_swapped_axes:
    extu.w r4, r4
    mov.w r4, @r6
    extu.w r5, r5
    mov.w r5, @r7
.L_grid_write_done:
    lds.l @r15+, pr
    rts
    nop

    .global DAT_06006802
DAT_06006802:
    mov.l r9, @(36, r9)

    .global DAT_06006804
DAT_06006804:
    .2byte  0x4000              /* half-grid X bias constant (0x4000) */
    .2byte  0xFFFF              /* padding / sentinel */
    .4byte  fpmul               /* pointer: fpmul (16.16 fixed-point multiply) */
    .4byte  sym_06063F04        /* pointer: sym_06063F04 (camera/physics data ptr A) */
    .4byte  sym_06063F08        /* pointer: sym_06063F08 (camera/physics data ptr B) */
    .4byte  sym_06059F30        /* pointer: sym_06059F30 (split-screen / 2P enable flag) */
    .4byte  sym_06063E20        /* pointer: sym_06063E20 (race state flag B) */
.L_pool_0600681C:
    .4byte  sym_0601A5F8        /* pointer: sym_0601A5F8 (car data utility fn) */
.L_pool_06006820:
    .4byte  sym_0605D240        /* pointer: sym_0605D240 (sprite parameter table base) */
.L_pool_06006824:
    .4byte  sprite_pair_render  /* pointer: sprite_pair_render (VDP1 sprite pair draw fn) */
.L_pool_06006828:
    .4byte  sym_06063F4A        /* pointer: sym_06063F4A (grid Z output word) */
.L_pool_0600682C:
    .4byte  sym_06063F48        /* pointer: sym_06063F48 (grid X output word) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_06006834:
    .4byte  sym_06078663        /* pointer: sym_06078663 (display mode / camera flip byte flag) */

    .global sym_06006838
sym_06006838:
    mov.l   .L_pool_06006860, r3
    mov.l   .L_pool_06006864, r2
    sub r5, r3
    add r2, r4
    mov r3, r5
    shlr16 r4
    shlr16 r5
    shlr2 r4
    shlr2 r5
    shlr2 r4
    shlr2 r5
    shlr r4
    shlr r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov r5, r0
    rts
    add r4, r0
    .2byte  0xFFFF              /* padding */
.L_pool_06006860:
    .4byte  0x03FFFFFF          /* world Z-axis upper bound (for axis inversion) */
.L_pool_06006864:
    .4byte  0x04000000          /* world X-axis bias (shifts X origin to positive range) */
