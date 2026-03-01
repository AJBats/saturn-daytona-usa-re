
    .section .text.FUN_060325AE


    .global disp_digit_pair_render
    .type disp_digit_pair_render, @function
disp_digit_pair_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD1, 0x0C    /* mov.l .L_pool_060325EC, r1 */
    .byte   0xD0, 0x0C    /* mov.l .L_pool_060325F0, r0 */
    mov.b @(r0, r14), r0
    .byte   0xD2, 0x0C    /* mov.l .L_pool_060325F4, r2 */
    tst r2, r0
    bf      .L_060325F8
    .byte   0xD0, 0x0C    /* mov.l .L_pool_060325F8, r0 */
    bra     .L_060325FA
    add r0, r1
    .4byte  sym_06026DBC                    /* pre-transform setup function */
    .4byte  sym_06089EDC                    /* global rendering budget counter */
    .4byte  0x00000000                      /* constant 0 (adjacent pool padding) */
    .4byte  0x00000004                      /* constant 4 (adjacent pool) */
    .4byte  0x00000008                      /* constant 8 (adjacent pool) */
    .4byte  sym_06026E2E                    /* transform dispatch function */
    .4byte  0x0000000C                      /* constant 12 (adjacent pool) */
    .4byte  mat_rot_y                       /* Y-axis rotation matrix function */
.L_pool_060325EC:
    .4byte  0x00000054                      /* offset into struct for data source base */
.L_pool_060325F0:
    .4byte  0x000002DC                      /* offset into struct for flags byte */
.L_pool_060325F4:
    .4byte  0xFFFFFFFC                      /* mask: upper flag bits (all except bit 0-1) */
.L_pool_060325F8:
    .4byte  sym_06081898                    /* global digit data table base address */
.L_060325F8:
    add r14, r1
.L_060325FA:
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032668, r0 */
    mov.l r1, @(r0, r14)
    .byte   0xD7, 0x1B    /* mov.l .L_pool_0603266C, r7 */
    mov.l r7, @-r15
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032670, r0 */
