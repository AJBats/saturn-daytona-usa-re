/* rot_scroll_hscale -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0602E578 - 0x0602E61C
 *
 * VDP2 rotation scroll horizontal scale check and scroll parameter loader.
 *
 * Three entry points:
 *
 *   rot_scroll_hscale (0x0602E578):
 *     Final stage of the rotation scroll pipeline (commit -> interp -> vscale -> hscale).
 *     Invokes a callback via r13, then reads the car heading reference at
 *     struct offset +0x025C and computes a horizontal delta against r5. Biases
 *     the delta by +0x3FFF and checks whether it falls in [0, 0x7FFF].
 *     If in range, the scale is valid and returns immediately.
 *     If out of range, increments a counter at struct offset +0x0244
 *     (tracks how many frames the scale was clamped).
 *
 *   scroll_param_load (sym_0602E5E4):
 *     Called during car_array_init as "scroll_setup". Loads the car array base
 *     pointer from sym_0607E944, reads two scroll parameter words from
 *     car struct offsets +0x238 and +0x23C, and stores them to global
 *     variables DAT_06083264 and DAT_06083268 (used by palette/lighting code).
 *
 *   scroll_render_prologue (sym_0602E610):
 *     Prologue for state-17 special rendering — saves callee-saved registers
 *     r8–r13. The function body continues in the next TU (palette_fade_calc).
 */

    .section .text.FUN_0602E578


    .global rot_scroll_hscale
    .type rot_scroll_hscale, @function
rot_scroll_hscale:
    sts.l pr, @-r15                        ! save PR (return address)
    jsr @r13                               ! call pipeline callback (passed in r13)
    nop                                    ! delay slot
    lds.l @r15+, pr                        ! restore PR
    nop                                    ! (padding)
    mov.w   .L_wpool_heading_ref_offset, r1 ! r1 = 0x025C (heading ref offset in car struct)
    mov.l @(r0, r1), r4                    ! r4 = car[+0x025C] (heading reference)
    exts.w r4, r4                          ! sign-extend heading to 32-bit
    mov r5, r3                             ! r3 = r5 (current hscale value)
    sub r4, r3                             ! r3 = hscale - heading_ref (delta)
    mov.l   _pool_hscale_bias, r6          ! r6 = 0x3FFF (half-range bias)
    add r6, r3                             ! r3 = delta + 0x3FFF (bias to unsigned)
    exts.w r3, r3                          ! sign-extend biased delta
    mov.l   _pool_hscale_range_lo, r1      ! r1 = 0 (lower bound)
    cmp/ge r1, r3                          ! T = (r3 >= 0)?
    bf      .L_out_of_range                ! if below range, clamp
    mov.l   _pool_hscale_range_hi, r6      ! r6 = 0x7FFF (upper bound)
    cmp/gt r6, r3                          ! T = (r3 > 0x7FFF)?
    bt      .L_out_of_range                ! if above range, clamp
    rts                                    ! scale is valid — return
    nop                                    ! delay slot

    .global DAT_0602e5a2
DAT_0602e5a2:                              /* data — referenced by other TUs */
    mov.b r9, @(r0, r1)

    .global DAT_0602e5a4
DAT_0602e5a4:                              /* data — referenced by other TUs */
    mov.b @(r0, r0), r0
    .word 0x0010                           /* padding / data */
.L_wpool_heading_ref_offset:
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
.L_out_of_range:
    mov.l   _pool_clamp_count_offset, r1   ! r1 = 0x0244 (clamp counter offset)
    mov.l @(r0, r1), r3                    ! r3 = car[+0x0244] (clamp frame count)
    add #0x1, r3                           ! r3++ (one more frame clamped)
    mov.l r3, @(r0, r1)                    ! store updated count
    rts                                    ! return
    nop                                    ! delay slot
_pool_clamp_count_offset:
    .4byte  0x00000244                     /* car struct offset: hscale clamp counter */

    .global sym_0602E5E4
sym_0602E5E4:                              /* scroll_param_load */
    mov.l   _pool_car_array_base, r2       ! r2 = &car_array_base_ptr
    mov.l @r2, r2                          ! r2 = car_array_base (deref)
    mov.l   _pool_scroll_param_a_offset, r0 ! r0 = 0x0238 (scroll param A offset)
    mov.l @(r0, r2), r1                    ! r1 = car[+0x0238] (scroll param A)
    mov.l   _pool_scroll_param_a_dst, r0   ! r0 = &DAT_06083264
    mov.l r1, @r0                          ! DAT_06083264 = scroll param A
    mov.l   _pool_scroll_param_b_offset, r0 ! r0 = 0x023C (scroll param B offset)
    mov.l @(r0, r2), r1                    ! r1 = car[+0x023C] (scroll param B)
    mov.l   _pool_scroll_param_b_dst, r0   ! r0 = &DAT_06083268
    mov.l r1, @r0                          ! DAT_06083268 = scroll param B
    rts                                    ! return
    nop                                    ! delay slot
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
sym_0602E610:                              /* scroll_render_prologue */
    mov.l r8, @-r15                        ! save r8
    mov.l r9, @-r15                        ! save r9
    mov.l r10, @-r15                       ! save r10
    mov.l r11, @-r15                       ! save r11
    mov.l r12, @-r15                       ! save r12
    mov.l r13, @-r15                       ! save r13 (continues into palette_fade_calc)
