
    .section .text.FUN_06041B3C


    .global track_surface_validate
    .type track_surface_validate, @function
track_surface_validate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l   _pool_fn_checkpoint, r11
    mov.l   _pool_car_state_base, r14
    mov.w   DAT_06041bc8, r1
    mov.l @r14, r0
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf/s    .L_06041BFC
    mov r4, r12
    mov r15, r5
    mov.l @r14, r4
    mov.w   _wpool_off_surface_param, r0
    mov.l   _pool_fn_surface_type_c, r3
    jsr @r3
    mov.l @(r0, r4), r4
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov.l @r14, r2
    mov r15, r3
    mov #0x40, r0
    add #0x8, r3
    mov.b @r3, r1
    mov.b r1, @(r0, r2)
    mov.l @r12, r3
    add #0x1, r3
    mov.l r3, @r12
    mov.l @r14, r2
    mov.w   DAT_06041bcc, r0
    mov.l @(r0, r2), r3
    mov.l @r15, r2
    sub r3, r2
    mov.l r2, @r15
    mov.l @r14, r4
    mov.w   _wpool_off_max_dist, r0
    mov.l @(r0, r4), r4
    cmp/ge r4, r2
    bt      .L_06041B98
    bra     .L_06041B9A
    nop
.L_06041B98:
    mov.l r4, @r15
.L_06041B9A:
    mov.l @r14, r2
    mov.w   _wpool_off_result_ptr, r0
    mov.l @(r0, r2), r3
    mov.l @r15, r2
    mov.l r2, @r3
    mov.l @r15, r3
    cmp/pl r3
    bt      .L_06041BE0
    mov.l @r14, r2
    mov.w   DAT_06041bc8, r0
    mov.l r13, @(r0, r2)
    add #0x18, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_06041BC2
    mov.l @r14, r3
    mov.w   DAT_06041bd2, r0
    mov.l @(r0, r3), r2
    mov.l r13, @r2
.L_06041BC2:
    bra     .L_06041CBA
    mov #0x0, r0

    .global DAT_06041bc6
DAT_06041bc6:
    mov.b r0, @(r0, r3)

    .global DAT_06041bc8
DAT_06041bc8:
    .2byte  0x030C               /* car state offset: state machine phase */
_wpool_off_surface_param:
    .2byte  0x0310               /* car state offset: surface query param A */

    .global DAT_06041bcc
DAT_06041bcc:
    .2byte  0x0314               /* car state offset: distance base value */
_wpool_off_max_dist:
    .2byte  0x0318               /* car state offset: max distance threshold */
_wpool_off_result_ptr:
    .2byte  0x0320               /* car state offset: distance result pointer */

    .global DAT_06041bd2
DAT_06041bd2:
    .2byte  0x0324               /* car state offset: completion callback ptr */
_pool_fn_checkpoint:
    .4byte  ai_checkpoint_validate  /* checkpoint validation function */
_pool_car_state_base:
    .4byte  sym_060A5400            /* AI/game state base pointer (indirect) */
_pool_fn_surface_type_c:
    .4byte  track_surface_type_c    /* surface type query variant C */
.L_06041BE0:
    mov.l @r14, r3
    mov.w   DAT_06041ca8, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_06041BF4
    mov.l @r14, r3
    mov.w   DAT_06041caa, r0
    mov.l r13, @(r0, r3)
    bra     .L_06041CBA
    mov r13, r0
.L_06041BF4:
    mov.l @r14, r3
    mov #0x2, r2
    mov.w   DAT_06041caa, r0
    mov.l r2, @(r0, r3)
.L_06041BFC:
    mov.l @r14, r0
    mov.w   DAT_06041caa, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x2, r0
    bf      .L_06041C5A
    mov.l @r14, r0
    mov.l @(52, r0), r0
    cmp/eq #0x1, r0
    bf      .L_06041C12
    bra     .L_06041CBA
    mov #0x2, r0
.L_06041C12:
    mov #0x1, r3
    mov.l @r14, r2
    mov.l r3, @(52, r2)
    mov.l @r14, r6
    mov.w   _wpool_off_result_ptr_b, r0
    mov.l @r14, r5
    mov.l @r14, r4
    mov.l   _pool_fn_surface_type_d, r3
    mov.l @(r0, r6), r6
    add #-0xC, r0
    mov.l @r6, r6
    mov.l @(r0, r5), r5
    add #-0x4, r0
    jsr @r3
    mov.l @(r0, r4), r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041C3A
    bra     .L_06041CBA
    mov #0x2, r0
.L_06041C3A:
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov.l @r14, r3
    mov r15, r2
    add #0x8, r2
    mov.b @r2, r1
    mov #0x40, r0
    mov.b r1, @(r0, r3)
    mov.l @r12, r3
    add #0x1, r3
    mov.l r3, @r12
    mov.l @r14, r2
    mov #0x3, r3
    mov.w   DAT_06041caa, r0
    mov.l r3, @(r0, r2)
.L_06041C5A:
    mov.l @r14, r0
    mov.w   DAT_06041caa, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x3, r0
    bf      .L_06041CB8
    mov r15, r4
    mov.l   _pool_fn_distance_calc, r3
    jsr @r3
    add #0x4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06041C76
    bra     .L_06041CBA
    mov #0x1, r0
.L_06041C76:
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov.l @r14, r3
    mov r15, r2
    mov #0x40, r0
    add #0x8, r2
    mov.b @r2, r1
    mov.b r1, @(r0, r3)
    mov.l @r12, r3
    add #0x1, r3
    mov.l r3, @r12
    mov.l @r14, r2
    mov.w   DAT_06041caa, r0
    mov.l r13, @(r0, r2)
    mov.l @r14, r3
    add #0x18, r0
    mov.l @(r0, r3), r2
    mov.l @(4, r15), r3
    shll r3
    mov.l r3, @r2
    mov.l @r14, r3
    mov.l r13, @(52, r3)
    bra     .L_06041CBA
    mov r13, r0

    .global DAT_06041ca8
DAT_06041ca8:
    .2byte  0x0324               /* car state offset: completion callback ptr (dup) */

    .global DAT_06041caa
DAT_06041caa:
    .2byte  0x030C               /* car state offset: state machine phase (dup) */
_wpool_off_result_ptr_b:
    .2byte  0x0320               /* car state offset: result pointer (dup for reach) */
    .2byte  0xFFFF               /* alignment padding */
_pool_fn_surface_type_d:
    .4byte  track_surface_type_d    /* surface type query variant D */
_pool_fn_distance_calc:
    .4byte  track_distance_calc     /* track distance computation */
.L_06041CB8:
    mov #0x1, r0
.L_06041CBA:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
