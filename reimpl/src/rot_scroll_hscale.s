
    .section .text.FUN_0602E578


    .global rot_scroll_hscale
    .type rot_scroll_hscale, @function
rot_scroll_hscale:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.w   .L_wpool_0602E5A8, r1
    mov.l @(r0, r1), r4
    exts.w r4, r4
    mov r5, r3
    sub r4, r3
    mov.l   _pool_hscale_bias, r6
    add r6, r3
    exts.w r3, r3
    mov.l   _pool_hscale_range_lo, r1
    cmp/ge r1, r3
    bf      .L_0602E5D4
    mov.l   _pool_hscale_range_hi, r6
    cmp/gt r6, r3
    bt      .L_0602E5D4
    rts
    nop

    .global DAT_0602e5a2
DAT_0602e5a2:
    mov.b r9, @(r0, r1)

    .global DAT_0602e5a4
DAT_0602e5a4:
    mov.b @(r0, r0), r0
    .word 0x0010
.L_wpool_0602E5A8:
    .2byte  0x025C                         /* car struct offset: heading reference */
    .2byte  0x0000                         /* padding */
    .4byte  0x00000100                     /* constant 256 */
    .4byte  0x00000030                     /* constant 48 */
    .4byte  0x00000028                     /* constant 40 */
    .4byte  0x00000008                     /* constant 8 */
    .4byte  0x0000038E                     /* constant 910 */
    .4byte  sym_0608325C                   /* countdown/race state */
    .4byte  sym_0602CCD0                   /* function pointer (scene handler) */
_pool_hscale_bias:
    .4byte  0x00003FFF                     /* half-range bias for unsigned check */
_pool_hscale_range_lo:
    .4byte  0x00000000                     /* lower bound (0) */
_pool_hscale_range_hi:
    .4byte  0x00007FFF                     /* upper bound (full range) */
.L_0602E5D4:
    mov.l   _pool_clamp_count_offset, r1
    mov.l @(r0, r1), r3
    add #0x1, r3
    mov.l r3, @(r0, r1)
    rts
    nop
_pool_clamp_count_offset:
    .4byte  0x00000244                     /* car struct offset: hscale clamp counter */

    .global sym_0602E5E4
sym_0602E5E4:
    mov.l   _pool_car_array_base, r2
    mov.l @r2, r2
    mov.l   _pool_scroll_param_a_offset, r0
    mov.l @(r0, r2), r1
    mov.l   _pool_scroll_param_a_dst, r0
    mov.l r1, @r0
    mov.l   _pool_scroll_param_b_offset, r0
    mov.l @(r0, r2), r1
    mov.l   _pool_scroll_param_b_dst, r0
    mov.l r1, @r0
    rts
    nop
_pool_car_array_base:
    .4byte  sym_0607E944                   /* car array base pointer */
_pool_scroll_param_a_offset:
    .4byte  0x00000238                     /* car struct offset: scroll param A */
_pool_scroll_param_a_dst:
    .4byte  DAT_06083264                   /* global dest: scroll param A */
_pool_scroll_param_b_offset:
    .4byte  0x0000023C                     /* car struct offset: scroll param B */
_pool_scroll_param_b_dst:
    .4byte  DAT_06083268                   /* global dest: scroll param B */

    .global sym_0602E610
sym_0602E610:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
