
    .section .text.FUN_0600C7D8


    .global ai_steering_update
    .type ai_steering_update, @function
ai_steering_update:
    sts.l pr, @-r15

    mov.l @(32, r14), r3
    mov.w   DAT_0600c8b6, r0
    mov.l r3, @(r0, r14)

    mov.l @(40, r14), r4
    mov.l @(32, r14), r3
    mov.l @(8, r14), r2
    extu.w r4, r4
    neg r3, r3
    extu.w r3, r3
    add r3, r4

    mov.w   .L_wpool_speed_thresh_heavy, r3
    cmp/gt r3, r2
    bf/s    .check_speed_250
    exts.w r4, r4
    shar r4
    shar r4
    bra     .apply_heading
    shar r4

.check_speed_250:
    mov.l @(8, r14), r2
    mov.w   .L_wpool_speed_thresh_medium, r3
    cmp/gt r3, r2
    bf      .check_speed_220
    shar r4
    bra     .apply_heading
    shar r4

.check_speed_220:
    mov.l @(8, r14), r2
    mov.w   DAT_0600c8bc, r3
    cmp/gt r3, r2
    bf      .apply_heading
    shar r4

.apply_heading:
    extu.w r4, r4
    mov.l @(32, r14), r3
    extu.w r3, r3
    add r4, r3
    exts.w r3, r3
    mov.l r3, @(32, r14)

    mov r3, r2
    mov.w   DAT_0600c8be, r0
    extu.w r2, r2
    mov.l @(r0, r14), r3
    neg r3, r3
    mov.w @(18, r5), r0
    extu.w r3, r3
    add r3, r2
    mov r0, r3
    neg r3, r3
    extu.w r3, r3
    add r3, r2
    exts.w r2, r2
    mov.l r2, @(48, r14)

    mov.w @(12, r5), r0
    mov.l @(28, r14), r2
    mov r0, r3
    extu.w r2, r2
    extu.w r3, r3
    add r2, r3
    exts.w r3, r3
    shar r3
    mov.l r3, @(28, r14)

    mov.w @(16, r5), r0
    mov.l @(36, r14), r2
    mov r0, r3
    extu.w r2, r2
    extu.w r3, r3
    add r2, r3
    exts.w r3, r3
    shar r3
    mov.l r3, @(36, r14)

    mov.l @(16, r14), r3
    mov.l r3, @(56, r14)
    mov.l @(24, r14), r2
    mov.l r2, @(60, r14)

    mov.l @(32, r14), r3
    mov.w @(18, r5), r0
    extu.w r3, r3
    mov r0, r2
    neg r2, r2
    shar r2
    shar r2
    extu.w r2, r2
    add r2, r3
    exts.w r3, r3
    mov.l r3, @(32, r14)

    mov.w   DAT_0600c8c0, r6
    mov.w   DAT_0600c8c2, r5
    mov.l @(40, r14), r4
    mov.l   .pool_sincos_pair, r3
    add r14, r6
    add r14, r5
    jsr @r3
    neg r4, r4

    mov.w   DAT_0600c8c2, r0
    mov.l   .pool_fpmul, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov.l @(12, r14), r4

    mov.l @(16, r14), r2
    add r0, r2
    mov.l r2, @(16, r14)

    mov.w   DAT_0600c8c0, r0
    mov.l   .pool_fpmul, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov.l @(12, r14), r4

    mov.l @(24, r14), r2
    add r0, r2
    mov.l r2, @(24, r14)

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600c8b6
DAT_0600c8b6:
    .2byte  0x01B0
.L_wpool_speed_thresh_heavy:
    .2byte  0x0118                         /* [HIGH] speed threshold: 280 (heavy damping) */
.L_wpool_speed_thresh_medium:
    .2byte  0x00FA                         /* [HIGH] speed threshold: 250 (medium damping) */

    .global DAT_0600c8bc
DAT_0600c8bc:
    .2byte  0x00DC

    .global DAT_0600c8be
DAT_0600c8be:
    .2byte  0x01D8

    .global DAT_0600c8c0
DAT_0600c8c0:
    .2byte  0x0190

    .global DAT_0600c8c2
DAT_0600c8c2:
    .2byte  0x018C
.pool_sincos_pair:
    .4byte  sincos_pair
.pool_fpmul:
    .4byte  fpmul
