/* mega_render_func -- 3x3 matrix interpolation and dual-pass vertex transform
 * Translation unit: 0x06029740 - 0x0602A840  (4352 bytes, 3 functions + 10 helpers)
 *
 * Functions:
 *   mega_render_func (0x06029740) -- Matrix interpolation state machine.
 *       Blends 3x3 fixed-point matrices using weights 0xE666 (0.9) and
 *       0x1999 (0.1). Four control words at r5[0..6] select which of 3 axes
 *       are still active; 8 code paths handle all combinations of
 *       (row0/row1/row2) x (modeA=fwd/modeB=rev/modeC=cross/modeD=diag).
 *       Each path: dmuls.l + xtrct for 16.16 fixed-point multiply-accumulate,
 *       threshold check against far-plane clip distance. Loop until all axes
 *       converge (all control words reach zero).
 *
 *   sym_06029BF4 (0x06029BF4) -- Pass A vertex transform pipeline.
 *       Iterates over polygon entries (24 bytes each, up to 81 per frame).
 *       For each quad: transform 4 vertices through 3x3 camera matrix
 *       using MAC.L, backface cull via dot-product sign test, clip against
 *       screen bounds (X: -176..+400, Y: -300..+400), 4-plane frustum reject,
 *       perspective-project to screen coords, dispatch through depth-sort
 *       handler table, emit to VDP1 sprite command list.
 *
 *   sym_0602A214 (0x0602A214) -- Pass B vertex transform pipeline.
 *       Identical structure to Pass A but uses separate vertex output
 *       buffers (sym_0608A7A0 vs sym_0608A70C), separate camera matrix
 *       (sym_0608A52C vs sym_06089EDC), and writes to a second sprite
 *       commit counter (sym_060620D4 vs sym_060620D0). Used for the
 *       secondary viewport or split-screen rendering.
 *
 * Depth sort helpers (5 per pass, 10 total):
 *   loc_0602A134/loc_0602A754 -- Average of 4 Z values
 *   loc_0602A140/loc_0602A760 -- Minimum Z (>=)
 *   loc_0602A156/loc_0602A776 -- Minimum Z (>)
 *   loc_0602A16C/loc_0602A78C -- Minimum Z + depth bias (0xB8000)
 *   loc_0602A188/loc_0602A7A8 -- Minimum Z + 1.0 offset (0x10000)
 *
 * Data tables at end:
 *   sym_0602A1E0/sym_0602A800 -- Pipeline dispatch tables (fn ptrs + params)
 *   sym_0602A1F0/sym_0602A810 -- Clip handler dispatch tables
 *   sym_0602A200/sym_0602A820 -- Depth sort mode dispatch tables
 */

    .section .text.FUN_06029740


    .global mega_render_func
    .type mega_render_func, @function
mega_render_func:
    mov.l r14, @-r15                        ! save r14
    mov.l r12, @-r15                        ! save r12
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save return address
    add #-0x8, r15                          ! allocate 8 bytes on stack
    mov.l   .L_fp_interp_high, r1    ! r1 = 0xE666 = 0.9 (high blend weight)
    mov.l   .L_fp_interp_low, r2      ! r2 = 0x1999 = 0.1 (low blend weight)
    mov.l   .L_clip_threshold_ptr, r14  ! r14 = ptr to far-plane clip threshold
    mov.l @r14, r14                         ! dereference: r14 = *clip_threshold
    mov r5, r12                             ! r12 = control word array base
    mov.w @(2, r12), r0                     ! load next axis control word
    mov.w r0, @(2, r15)                     ! cache control word on stack
    mov.w @(4, r12), r0                     ! load next axis control word
    mov.w r0, @(4, r15)                     ! cache control word on stack
    mov.w @(6, r12), r0                     ! load next axis control word
    mov.w r0, @(6, r15)                     ! cache control word on stack
    mov.w @r12, r0                          ! load control word 0
    mov.w r0, @r15                          ! cache control word 0 on stack
.L_interp_loop:
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_mode_a_dispatch
    bra     .L_modeB_dispatch
    mov.w @(2, r15), r0                     ! reload cached control word
.L_fp_interp_high:
    .4byte  0x0000E666
.L_fp_interp_low:
    .4byte  0x00001999
.L_clip_threshold_ptr:
    .4byte  sym_06063F08
.L_mode_a_dispatch:
    mov.w @(2, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeA_axis1_done
    mov.l @(0, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(12, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(16, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(20, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeA_axis1_done
    mov.w r0, @(2, r12)                     ! clear control word (axis converged)
.L_modeA_axis1_done:
    mov.w @(4, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeA_axis2_done
    mov.l @(0, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(24, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(28, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(32, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeA_axis2_done
    mov.w r0, @(4, r12)                     ! clear control word (axis converged)
.L_modeA_axis2_done:
    mov.w @(6, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bf      .L_modeA_blend_axis3
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeA_blend_axis3:
    mov.l @(0, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(4, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(36, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(8, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(40, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(44, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bt      .L_modeA_axis3_converged
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeA_axis3_converged:
    mov #0x0, r0
    mov.w r0, @(6, r12)                     ! clear control word (axis converged)
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeB_dispatch:
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeB_entry
    bra     .L_modeC_dispatch
    mov.w @(4, r15), r0                     ! reload cached control word
.L_modeB_entry:
    mov.w @(0, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeB_axis0_done
    mov.l @(12, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(0, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(0, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(4, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(8, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeB_axis0_done
    mov.w r0, @(0, r12)                     ! clear control word (axis converged)
.L_modeB_axis0_done:
    mov.w @(4, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeB_axis1_done
    mov.l @(12, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(24, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(28, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(32, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeB_axis1_done
    mov.w r0, @(4, r12)                     ! clear control word (axis converged)
.L_modeB_axis1_done:
    mov.w @(6, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bf      .L_modeB_blend_axis2
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeB_blend_axis2:
    mov.l @(12, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(16, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(36, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(20, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(40, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(44, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bt      .L_modeB_axis2_converged
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeB_axis2_converged:
    mov #0x0, r0
    mov.w r0, @(6, r12)                     ! clear control word (axis converged)
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeC_dispatch:
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeC_entry
    bra     .L_modeD_entry
    mov.w @(0, r12), r0                     ! load next axis control word
.L_modeC_entry:
    mov.w @(0, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeC_axis0_done
    mov.l @(24, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(0, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(0, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(4, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(8, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeC_axis0_done
    mov.w r0, @(0, r12)                     ! clear control word (axis converged)
.L_modeC_axis0_done:
    mov.w @(2, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeC_axis1_done
    mov.l @(24, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(12, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(16, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(20, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeC_axis1_done
    mov.w r0, @(2, r12)                     ! clear control word (axis converged)
.L_modeC_axis1_done:
    mov.w @(6, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bf      .L_modeC_blend_axis2
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeC_blend_axis2:
    mov.l @(24, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(36, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(28, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(36, r4)
    mov.l @(40, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(32, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(40, r4)
    mov.l @(44, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(44, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bt      .L_modeC_axis2_converged
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeC_axis2_converged:
    mov #0x0, r0
    mov.w r0, @(6, r12)                     ! clear control word (axis converged)
    bra     .L_interp_done
    nop                                     ! (delay slot)
.L_modeD_entry:
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeD_axis0_done
    mov.l @(36, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(0, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(0, r4)
    mov.l @(4, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(4, r4)
    mov.l @(8, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(8, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeD_axis0_done
    mov.w r0, @(0, r12)                     ! clear control word (axis converged)
.L_modeD_axis0_done:
    mov.w @(2, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_modeD_axis1_done
    mov.l @(36, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(12, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(12, r4)
    mov.l @(16, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(16, r4)
    mov.l @(20, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(20, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_modeD_axis1_done
    mov.w r0, @(2, r12)                     ! clear control word (axis converged)
.L_modeD_axis1_done:
    mov.w @(4, r12), r0                     ! load next axis control word
    cmp/eq #0x0, r0                         ! control word == 0? (axis inactive)
    bt      .L_interp_done
    mov.l @(36, r4), r7
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    mov.l @(24, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(40, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(24, r4)
    mov.l @(28, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov.l @(44, r4), r7
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    dmuls.l r7, r2                          ! multiply by 0.1 weight (low blend)
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    mov.l r9, @(28, r4)
    mov.l @(32, r4), r6
    sts mach, r7
    sts macl, r8
    dmuls.l r6, r1                          ! multiply by 0.9 weight (high blend)
    xtrct r7, r8                            ! extract middle 32 bits of 64-bit product
    mov #0x0, r0
    sts mach, r6
    sts macl, r9
    xtrct r6, r9                            ! extract middle 32 bits of 64-bit product
    add r8, r9                              ! accumulate: result = low*0.1 + high*0.9
    add #0x4, r9                            ! add rounding bias
    mov.l r9, @(32, r4)
    cmp/gt r14, r9                          ! blended value > clip threshold?
    bf      .L_interp_done
    mov.w r0, @(4, r12)                     ! clear control word (axis converged)
.L_interp_done:
    mov.w @r12, r7                          ! r7 = control word 0 for sum
    mov.w @(2, r12), r0                     ! load next axis control word
    add r0, r7                              ! accumulate active word sum
    mov.w @(4, r12), r0                     ! load next axis control word
    add r0, r7                              ! accumulate active word sum
    mov.w @(6, r12), r0                     ! load next axis control word
    add r7, r0                              ! accumulate active word sum
    cmp/eq #0x0, r0                         ! all control words zero? (all axes converged)
    bt      .L_return_interp
    bra     .L_interp_loop
    mov.w @r15, r0                          ! reload cached control word
.L_return_interp:
    add #0x8, r15                           ! deallocate 8 bytes from stack
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r12                        ! restore r12
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14

    .global sym_06029BF4
sym_06029BF4:
    mov.l r8, @-r15                         ! save r8
    mov.l r9, @-r15                         ! save r9
    mov.l r10, @-r15                        ! save r10
    mov.l r11, @-r15                        ! save r11
    mov.l r12, @-r15                        ! save r12
    mov.l r13, @-r15                        ! save r13
    sts.l pr, @-r15                         ! save return address
    mov r4, r8                              ! r8 = polygon data base
    mov.l   .L_clip_threshold_a, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0                            ! poly_count * sizeof(poly_entry)
    mov r5, r3                              ! r3 = vertex buffer base
    mov r6, r13                             ! r13 = render pass ID
    sts macl, r0
    add r0, r8                              ! r8 = end of polygon array
.L_transform_loop_a:
    mov.l r3, @-r15                         ! push r3 (loop variable)
    mov.l r7, @-r15                         ! push r7 (loop variable)
    add #-0x18, r8                          ! step to previous polygon (24 bytes back)
    mov.l   .L_render_enable_flag, r12
    mov.w @r12, r0
    cmp/eq #0x0, r0                         ! no vertices clipped?
    bt      .L_begin_transform_a
    mov.w @(14, r8), r0
    mov.w   DAT_06029c2e, r1
    cmp/eq r0, r1
    bf      .L_begin_transform_a
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)

    .global DAT_06029c2e
DAT_06029c2e:
    .2byte  0x0097
.L_clip_threshold_a:
    .4byte  sym_06063F08
.L_render_enable_flag:
    .4byte  sym_0605BE36
.L_begin_transform_a:
    mov.w @(16, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_a, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_camera_matrix, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    mov.l   .L_depth_result_a, r11
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @r11
    mov.w @(12, r8), r0
    tst #0x8, r0                            ! bit 3 set? (backface cull flag)
    bf      .L_passA_backface_ok
    mov.l   .L_backface_scratch_a, r5
    mov r8, r4
    mov.l   .L_camera_matrix, r0
    clrmac                                  ! clear MAC for matrix multiply
    mov.l @r0, r2
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l   .L_vertex_out_a, r4
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r5+                        ! dot(transformed, normal) for backface test
    mac.l @r4+, @r5+                        ! dot(transformed, normal) for backface test
    mac.l @r4+, @r5+                        ! dot(transformed, normal) for backface test
    sts mach, r1
    sts macl, r0
    xtrct r1, r0                            ! extract 32-bit result from 64-bit MAC
    cmp/pl r0                               ! dot > 0? (front-facing)
    bt      .L_passA_backface_ok
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)
    .2byte  0x0000
.L_vertex_out_a:
    .4byte  sym_0608A70C
.L_camera_matrix:
    .4byte  sym_06089EDC
.L_depth_result_a:
    .4byte  sym_0608A704
.L_backface_scratch_a:
    .4byte  sym_0608A73C
.L_passA_backface_ok:
    mov.w @(18, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_b, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_camera_matrix_b, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(2, r11)
    mov.w @(20, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_c, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_camera_matrix_b, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(4, r11)
    mov.w @(22, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_d, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_camera_matrix_b, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(6, r11)
    mov.w @r11+, r2
    mov.w @r11+, r3
    mov.w @r11+, r1
    add r2, r3
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    add r3, r0
    cmp/eq #0x0, r0                         ! no vertices clipped?
    bt      .L_passA_write_sprite
    cmp/eq #0x4, r0                         ! all 4 vertices clipped?
    bf      .L_passA_clip_dispatch
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)
    .2byte  0x0000
.L_vertex_out_b:
    .4byte  sym_0608A718
.L_camera_matrix_b:
    .4byte  sym_06089EDC
.L_vertex_out_c:
    .4byte  sym_0608A724
.L_vertex_out_d:
    .4byte  sym_0608A730
.L_passA_clip_dispatch:
    mov.l   .L_pipeline_a_table, r1
    shll2 r0                                ! index * 4 (table offset)
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    mov.l @r0, r0
    mov.l   .L_vertex_data_a, r4
    mov.l   .L_depth_data_a, r5
    jsr @r0                                 ! call clip/dispatch handler
    nop                                     ! (delay slot)
.L_passA_write_sprite:
    mov.l   .L_commit_count, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_sprite_data_table, r2
    mov.l   .L_poly_params_a, r11
    sts macl, r9
    add r2, r9
    mov.l   .L_vertex_data_a, r4
    mov r11, r5                             ! r5 = poly_params output
    mov.w   DAT_06029ea4, r1
    mov.w   DAT_06029ea6, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov.l   .L_render_state_a, r12
    mov #0x0, r0
    mov.w r0, @r12
    mov.w   .L_screen_width_a, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passA_v0_chk_left
    mov #0x1, r0
    bra     .L_passA_v0_bounds_done
    mov.w r0, @r12

    .global DAT_06029ea4
DAT_06029ea4:
    .2byte  0xFF00

    .global DAT_06029ea6
DAT_06029ea6:
    .2byte  0x00A0
.L_screen_width_a:
    .2byte  0x0190
    .2byte  0x0000
.L_pipeline_a_table:
    .4byte  sym_0602A1E0
.L_vertex_data_a:
    .4byte  sym_0608A70C
.L_depth_data_a:
    .4byte  sym_0608A704
.L_commit_count:
    .4byte  sym_060620D0
.L_sprite_data_table:
    .4byte  sym_0608AC20
.L_poly_params_a:
    .4byte  sym_0608A76C
.L_render_state_a:
    .4byte  sym_0608A6FC
.L_passA_v0_chk_left:
    mov.w   DAT_06029ed4, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passA_v0_chk_top
    mov #0x1, r0
    bra     .L_passA_v0_bounds_done
    mov.w r0, @r12

    .global DAT_06029ed4
DAT_06029ed4:
    .2byte  0xFE70
.L_passA_v0_chk_top:
    mov.w   DAT_06029ee2, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passA_v0_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v0_bounds_done
    mov.w r0, @r12

    .global DAT_06029ee2
DAT_06029ee2:
    .2byte  0x012C
.L_passA_v0_chk_bottom:
    mov.w   DAT_06029f2a, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passA_v0_bounds_done
    mov #0x1, r0
    mov.w r0, @r12
.L_passA_v0_bounds_done:
    mov r11, r5                             ! r5 = poly_params output
    add #0xC, r4
    add #0x8, r5
    mov.w   DAT_06029f2c, r1
    mov.w   DAT_06029f2e, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(2, r12)
    mov.w   DAT_06029f30, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passA_v1_chk_left
    mov #0x1, r0
    bra     .L_passA_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_06029f2a
DAT_06029f2a:
    .2byte  0xFE70

    .global DAT_06029f2c
DAT_06029f2c:
    .2byte  0xFF00

    .global DAT_06029f2e
DAT_06029f2e:
    .2byte  0x00A0

    .global DAT_06029f30
DAT_06029f30:
    .2byte  0x0190
.L_passA_v1_chk_left:
    mov.w   DAT_06029f3e, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passA_v1_chk_top
    mov #0x1, r0
    bra     .L_passA_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_06029f3e
DAT_06029f3e:
    .2byte  0xFE70
.L_passA_v1_chk_top:
    mov.w   DAT_06029f4c, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passA_v1_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_06029f4c
DAT_06029f4c:
    .2byte  0x012C
.L_passA_v1_chk_bottom:
    mov.w   DAT_06029f94, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passA_v1_bounds_done
    mov #0x1, r0
    mov.w r0, @(2, r12)
.L_passA_v1_bounds_done:
    mov r11, r5                             ! r5 = poly_params output
    add #0xC, r4
    add #0x10, r5
    mov.w   DAT_06029f96, r1
    mov.w   DAT_06029f98, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(4, r12)
    mov.w   DAT_06029f9a, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passA_v2_chk_left
    mov #0x1, r0
    bra     .L_passA_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_06029f94
DAT_06029f94:
    .2byte  0xFE70

    .global DAT_06029f96
DAT_06029f96:
    .2byte  0xFF00

    .global DAT_06029f98
DAT_06029f98:
    .2byte  0x00A0

    .global DAT_06029f9a
DAT_06029f9a:
    .2byte  0x0190
.L_passA_v2_chk_left:
    mov.w   DAT_06029fa8, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passA_v2_chk_top
    mov #0x1, r0
    bra     .L_passA_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_06029fa8
DAT_06029fa8:
    .2byte  0xFE70
.L_passA_v2_chk_top:
    mov.w   DAT_06029fb6, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passA_v2_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_06029fb6
DAT_06029fb6:
    .2byte  0x012C
.L_passA_v2_chk_bottom:
    mov.w   DAT_06029ffe, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passA_v2_bounds_done
    mov #0x1, r0
    mov.w r0, @(4, r12)
.L_passA_v2_bounds_done:
    mov r11, r5                             ! r5 = poly_params output
    add #0xC, r4
    add #0x18, r5
    mov.w   DAT_0602a000, r1
    mov.w   DAT_0602a002, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(6, r12)
    mov.w   DAT_0602a004, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passA_v3_chk_left
    mov #0x1, r0
    bra     .L_passA_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_06029ffe
DAT_06029ffe:
    .2byte  0xFE70

    .global DAT_0602a000
DAT_0602a000:
    .2byte  0xFF00

    .global DAT_0602a002
DAT_0602a002:
    .2byte  0x00A0

    .global DAT_0602a004
DAT_0602a004:
    .2byte  0x0190
.L_passA_v3_chk_left:
    mov.w   DAT_0602a012, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passA_v3_chk_top
    mov #0x1, r0
    bra     .L_passA_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a012
DAT_0602a012:
    .2byte  0xFE70
.L_passA_v3_chk_top:
    mov.w   DAT_0602a020, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passA_v3_chk_bottom
    mov #0x1, r0
    bra     .L_passA_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a020
DAT_0602a020:
    .2byte  0x012C
.L_passA_v3_chk_bottom:
    mov.w   DAT_0602a050, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passA_v3_bounds_done
    mov #0x1, r0
    mov.w r0, @(6, r12)
.L_passA_v3_bounds_done:
    mov.l   .L_sh2_periph_0x150, r4
    mov.l   .L_scale_constant_a, r5
    mov.l   .L_sh2_periph_0x181, r6
    mov.l   .L_poly_limit_a, r7
    mov.l @r11, r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passA_frustum_right
    mov.l @(8, r11), r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passA_frustum_right
    mov.l @(16, r11), r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passA_frustum_right
    mov.l @(24, r11), r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passA_frustum_right
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)

    .global DAT_0602a050
DAT_0602a050:
    .2byte  0xFE70
    .2byte  0x0000
.L_sh2_periph_0x150:
    .4byte  0xFFFFFF50                  /* SH-2 peripheral +0x150 */
.L_scale_constant_a:
    .4byte  0x000000B0
.L_sh2_periph_0x181:
    .4byte  0xFFFFFF81                  /* SH-2 peripheral +0x181 */
.L_poly_limit_a:
    .4byte  0x00000051
.L_passA_frustum_right:
    mov.l @r11, r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passA_frustum_top
    mov.l @(8, r11), r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passA_frustum_top
    mov.l @(16, r11), r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passA_frustum_top
    mov.l @(24, r11), r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passA_frustum_top
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)
.L_passA_frustum_top:
    mov.l @(4, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passA_frustum_bottom
    mov.l @(12, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passA_frustum_bottom
    mov.l @(20, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passA_frustum_bottom
    mov.l @(28, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passA_frustum_bottom
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)
.L_passA_frustum_bottom:
    mov.l @(4, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passA_frustum_pass
    mov.l @(12, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passA_frustum_pass
    mov.l @(20, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passA_frustum_pass
    mov.l @(28, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passA_frustum_pass
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)
.L_passA_frustum_pass:
    mov.w @r12, r1                          ! r1 = clip flag for vertex 0
    mov.w @(2, r12), r0                     ! r0 = clip flag for vertex 1
    add r0, r1                              ! accumulate clip flags
    mov.w @(4, r12), r0                     ! r0 = clip flag for vertex 2
    add r0, r1                              ! accumulate clip flags
    mov.w @(6, r12), r0                     ! r0 = clip flag for vertex 3
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    cmp/eq #0x4, r0                         ! all 4 vertices clipped?
    bf      .L_passA_partial_clip
    bra     .L_skip_polygon_a
    nop                                     ! (delay slot)
.L_passA_partial_clip:
    cmp/eq #0x0, r0                         ! no vertices clipped?
    bt      .L_passA_emit_quad
    mov r11, r4                             ! r4 = poly_params (for clip handler)
    shll2 r0                                ! index * 4 (table offset)
    mov.l   .L_pipeline_a_sub, r1
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    mov.l @r0, r0
    jsr @r0                                 ! call clip/dispatch handler
    mov r12, r5                             ! r5 = clip flags (for clip handler)
.L_passA_emit_quad:
    mov.l @r11, r0
    mov.w r0, @(8, r9)                      ! write to sprite entry
    mov.l @(4, r11), r0
    mov.w r0, @(10, r9)                     ! write to sprite entry
    mov.l @(8, r11), r0
    mov.w r0, @(12, r9)                     ! write to sprite entry
    mov.l @(12, r11), r0
    mov.w r0, @(14, r9)                     ! write to sprite entry
    mov.l @(16, r11), r0
    mov.w r0, @(16, r9)                     ! write to sprite entry
    mov.l @(20, r11), r0
    mov.w r0, @(18, r9)                     ! write to sprite entry
    mov.l @(24, r11), r0
    mov.w r0, @(20, r9)                     ! write to sprite entry
    mov.l @(28, r11), r0
    mov.w r0, @(22, r9)                     ! write to sprite entry
    mov.w @(14, r8), r0
    mov.w r0, @(6, r9)                      ! write to sprite entry
    mov.w @(12, r8), r0
    shlr2 r0                                ! shift right by 2
    shlr2 r0                                ! shift right by 2
    and #0xF, r0                            ! mask to 4-bit render mode
    mov.b r0, @(4, r9)                      ! write render flags
    mov r13, r0                             ! r0 = render pass ID
    mov.b r0, @(5, r9)                      ! write pass ID
    mov.w @(12, r8), r0
    mov.l   .L_pipeline_a_sub2, r1
    and #0x7, r0                            ! mask to 3-bit depth sort mode
    shll2 r0                                ! index * 4 (table offset)
    mov.l @(r0, r1), r0                     ! load handler from dispatch table
    mov.l   .L_vertex_data_a2, r1
    mov.l @(8, r1), r3
    mov.l @(20, r1), r4
    mov.l @(32, r1), r5
    jmp @r0                                 ! tail-call depth sort handler
    mov.l @(44, r1), r6
.L_pipeline_a_sub:
    .4byte  sym_0602A1F0
.L_pipeline_a_sub2:
    .4byte  sym_0602A200
.L_vertex_data_a2:
    .4byte  sym_0608A70C

    .global loc_0602A134
loc_0602A134:
    add r4, r3                              ! sum: z0 + z1
    add r5, r6                              ! sum: z2 + z3
    add r6, r3                              ! sum all 4 depths
    shlr2 r3                                ! divide by 4 (average depth)
    bra     .L_passA_zsort_commit
    nop                                     ! (delay slot)

    .global loc_0602A140
loc_0602A140:
    cmp/ge r3, r4                           ! compare against current min (>=)
    bt      .L_depthA_min_ge_1
    mov r4, r3                              ! update min depth
.L_depthA_min_ge_1:
    cmp/ge r3, r5                           ! compare against current min (>=)
    bt      .L_depthA_min_ge_2
    mov r5, r3                              ! update min depth
.L_depthA_min_ge_2:
    cmp/ge r3, r6                           ! compare against current min (>=)
    bt      .L_depthA_min_ge_done
    mov r6, r3                              ! update min depth
.L_depthA_min_ge_done:
    bra     .L_passA_zsort_commit
    nop                                     ! (delay slot)

    .global loc_0602A156
loc_0602A156:
    cmp/gt r3, r4                           ! compare against current min (>)
    bf      .L_depthA_min_gt_1
    mov r4, r3                              ! update min depth
.L_depthA_min_gt_1:
    cmp/gt r3, r5                           ! compare against current min (>)
    bf      .L_depthA_min_gt_2
    mov r5, r3                              ! update min depth
.L_depthA_min_gt_2:
    cmp/gt r3, r6                           ! compare against current min (>)
    bf      .L_depthA_min_gt_done
    mov r6, r3                              ! update min depth
.L_depthA_min_gt_done:
    bra     .L_passA_zsort_commit
    nop                                     ! (delay slot)

    .global loc_0602A16C
loc_0602A16C:
    mov.l   .L_fp_depth_bias_a, r0
    cmp/gt r3, r4                           ! compare against current min (>)
    bf      .L_depthA_bias_min_1
    mov r4, r3                              ! update min depth
.L_depthA_bias_min_1:
    cmp/gt r3, r5                           ! compare against current min (>)
    bf      .L_depthA_bias_min_2
    mov r5, r3                              ! update min depth
.L_depthA_bias_min_2:
    cmp/gt r3, r6                           ! compare against current min (>)
    bf      .L_depthA_bias_min_done
    mov r6, r3                              ! update min depth
.L_depthA_bias_min_done:
    bra     .L_passA_zsort_commit
    add r0, r3                              ! add depth bias
.L_fp_depth_bias_a:
    .4byte  0x000B8000

    .global loc_0602A188
loc_0602A188:
    mov.l   .L_fp_one, r0
    cmp/gt r3, r4                           ! compare against current min (>)
    bf      .L_depthA_offset_min_1
    mov r4, r3                              ! update min depth
.L_depthA_offset_min_1:
    cmp/gt r3, r5                           ! compare against current min (>)
    bf      .L_depthA_offset_min_2
    mov r5, r3                              ! update min depth
.L_depthA_offset_min_2:
    cmp/gt r3, r6                           ! compare against current min (>)
    bf      .L_depthA_offset_min_done
    mov r6, r3                              ! update min depth
.L_depthA_offset_min_done:
    add r0, r3                              ! add depth bias
.L_passA_zsort_commit:
    mov.l   .L_commit_count_2, r2
    neg r3, r3                              ! negate depth for sort key (farther = higher key)
    mov.l   .L_sprite_index_table, r1
    shlr8 r3                                ! depth >> 8 (coarse sort bucket)
    mov.l @r2, r0
    shlr2 r3                                ! depth >> 2 (fine sort adjustment)
    shlr2 r3                                ! depth >> 2 (fine sort adjustment)
    shll r0                                 ! count * 2 (word index into sort table)
    mov.w r3, @(r0, r1)                     ! write sort key to sprite index table
    shar r0                                 ! restore count from word index
    add #0x1, r0                            ! increment committed sprite count
    mov.l r0, @r2
.L_skip_polygon_a:
    mov.l @r15+, r7                         ! pop r7 (loop variable)
    mov.l @r15+, r3                         ! pop r3 (loop variable)
    dt r7
    bt      .L_passA_epilogue
    bra     .L_transform_loop_a
    nop                                     ! (delay slot)
    .2byte  0x0000
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_commit_count_2:
    .4byte  sym_060620D0
.L_sprite_index_table:
    .4byte  sym_0606A4F8
.L_passA_epilogue:
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r9                         ! restore r9
    rts                                     ! return
    mov.l @r15+, r8                         ! restore r8

    .global sym_0602A1E0
sym_0602A1E0:
    .word 0x0000 /* UNKNOWN */
    .word 0x0000 /* UNKNOWN */
    .4byte  spring_damper
    .4byte  transform_pipeline
    .4byte  mega_render_func

    .global sym_0602A1F0
sym_0602A1F0:
    .word 0x0000 /* UNKNOWN */
    .word 0x0000 /* UNKNOWN */
    .4byte  vblank_frame_handler
    .4byte  render_list_builder
    .4byte  render_obj_processor

    .global sym_0602A200
sym_0602A200:
    .4byte  loc_0602A134
    .4byte  loc_0602A140
    .4byte  loc_0602A156
    .4byte  loc_0602A188
    .4byte  loc_0602A16C

    .global sym_0602A214
sym_0602A214:
    mov.l r8, @-r15                         ! save r8
    mov.l r9, @-r15                         ! save r9
    mov.l r10, @-r15                        ! save r10
    mov.l r11, @-r15                        ! save r11
    mov.l r12, @-r15                        ! save r12
    mov.l r13, @-r15                        ! save r13
    sts.l pr, @-r15                         ! save return address
    mov r4, r8                              ! r8 = polygon data base
    mov.l   .L_clip_threshold_b, r10
    mov.l @r10, r10
    mov #0x18, r0
    mul.l r7, r0                            ! poly_count * sizeof(poly_entry)
    mov r5, r3                              ! r3 = vertex buffer base
    mov r6, r13                             ! r13 = render pass ID
    sts macl, r0
    add r0, r8                              ! r8 = end of polygon array
.L_transform_loop_b:
    mov.l r3, @-r15                         ! push r3 (loop variable)
    mov.l r7, @-r15                         ! push r7 (loop variable)
    add #-0x18, r8                          ! step to previous polygon (24 bytes back)
    mov.l   .L_render_enable_b, r12
    mov.w @r12, r0
    cmp/eq #0x0, r0                         ! no vertices clipped?
    bt      .L_passB_begin_transform
    mov.w @(14, r8), r0
    mov.w   DAT_0602a24e, r1
    cmp/eq r0, r1
    bf      .L_passB_begin_transform
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)

    .global DAT_0602a24e
DAT_0602a24e:
    .2byte  0x0097
.L_clip_threshold_b:
    .4byte  sym_06063F08
.L_render_enable_b:
    .4byte  sym_0605BE36
.L_passB_begin_transform:
    mov.w @(16, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_e, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_render_budget_a, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    mov.l   .L_depth_result_b, r11
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @r11
    mov.w @(12, r8), r0
    tst #0x8, r0                            ! bit 3 set? (backface cull flag)
    bf      .L_passB_backface_ok
    mov.l   .L_backface_scratch_b, r5
    mov r8, r4
    mov.l   .L_render_budget_a, r0
    clrmac                                  ! clear MAC for matrix multiply
    mov.l @r0, r2
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    mac.l @r4+, @r2+                        ! MAC += normal[i] * matrix[i] (backface)
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l   .L_vertex_out_e, r4
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r5+                        ! dot(transformed, normal) for backface test
    mac.l @r4+, @r5+                        ! dot(transformed, normal) for backface test
    mac.l @r4+, @r5+                        ! dot(transformed, normal) for backface test
    sts mach, r1
    sts macl, r0
    xtrct r1, r0                            ! extract 32-bit result from 64-bit MAC
    cmp/pl r0                               ! dot > 0? (front-facing)
    bt      .L_passB_backface_ok
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)
    .2byte  0x0000
.L_vertex_out_e:
    .4byte  sym_0608A7A0
.L_render_budget_a:
    .4byte  sym_0608A52C
.L_depth_result_b:
    .4byte  sym_0608A798
.L_backface_scratch_b:
    .4byte  sym_0608A7D0
.L_passB_backface_ok:
    mov.w @(18, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_f, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_render_budget_b, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(2, r11)
    mov.w @(20, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_g, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_render_budget_b, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(4, r11)
    mov.w @(22, r8), r0
    mov #0xC, r1
    extu.w r0, r4                           ! zero-extend vertex index
    mul.l r1, r4                            ! vertex_index * 12 (sizeof vertex XYZ)
    mov.l   .L_vertex_out_h, r5
    sts macl, r4
    add r3, r4                              ! r4 = &vertex_buffer[index]
    mov.l   .L_render_budget_b, r0
    mov #0x24, r7                           ! r7 = 0x24 (translation vector offset)
    mov.l @r0, r6
    add r6, r7                              ! r7 = &matrix.translation
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @r5                           ! store transformed X
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    add #-0xC, r4                           ! rewind vertex pointer (3 longs = 12 bytes)
    sts mach, r0
    sts macl, r1
    clrmac                                  ! clear MAC for matrix multiply
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l r1, @(4, r5)                      ! store transformed Y
    mac.l @r4+, @r6+                        ! MAC += vertex[i] * matrix[i]
    mov.l @r7+, r2
    sts mach, r0
    sts macl, r1
    xtrct r0, r1                            ! extract 32-bit result from 64-bit MAC
    add r2, r1                              ! add translation component
    mov.l r1, @(8, r5)                      ! store transformed Z
    mov.l @(8, r5), r0
    cmp/ge r0, r10                          ! Z >= far clip plane?
    .word 0x0029 /* UNKNOWN */
    mov.w r0, @(6, r11)
    mov.w @r11+, r2
    mov.w @r11+, r3
    mov.w @r11+, r1
    add r2, r3
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    add r3, r0
    cmp/eq #0x0, r0                         ! no vertices clipped?
    bt      .L_passB_write_sprite
    cmp/eq #0x4, r0                         ! all 4 vertices clipped?
    bf      .L_passB_clip_dispatch
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)
    .2byte  0x0000
.L_vertex_out_f:
    .4byte  sym_0608A7AC
.L_render_budget_b:
    .4byte  sym_0608A52C
.L_vertex_out_g:
    .4byte  sym_0608A7B8
.L_vertex_out_h:
    .4byte  sym_0608A7C4
.L_passB_clip_dispatch:
    mov.l   .L_pipeline_b_table, r1
    shll2 r0                                ! index * 4 (table offset)
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    mov.l @r0, r0
    mov.l   .L_vertex_data_e, r4
    mov.l   .L_depth_data_b, r5
    jsr @r0                                 ! call clip/dispatch handler
    nop                                     ! (delay slot)
.L_passB_write_sprite:
    mov.l   .L_frame_counter, r0
    mov #0x18, r1
    mov.l @r0, r0
    mul.l r0, r1
    mov.l   .L_sprite_data_b, r2
    mov.l   .L_poly_params_b, r11
    sts macl, r9
    add r2, r9
    mov.l   .L_vertex_data_e, r4
    mov r11, r5                             ! r5 = poly_params output
    mov.w   DAT_0602a4c4, r1
    mov.w   DAT_0602a4c6, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov.l   .L_render_state_b, r12
    mov #0x0, r0
    mov.w r0, @r12
    mov.w   .L_screen_width_b, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passB_v0_chk_left
    mov #0x1, r0
    bra     .L_passB_v0_bounds_done
    mov.w r0, @r12

    .global DAT_0602a4c4
DAT_0602a4c4:
    .2byte  0xFF00

    .global DAT_0602a4c6
DAT_0602a4c6:
    .2byte  0x00A0
.L_screen_width_b:
    .2byte  0x0190
    .2byte  0x0000
.L_pipeline_b_table:
    .4byte  sym_0602A800
.L_vertex_data_e:
    .4byte  sym_0608A7A0
.L_depth_data_b:
    .4byte  sym_0608A798
.L_frame_counter:
    .4byte  sym_060620D4
.L_sprite_data_b:
    .4byte  sym_0608AC20
.L_poly_params_b:
    .4byte  sym_0608A800
.L_render_state_b:
    .4byte  sym_0608A790
.L_passB_v0_chk_left:
    mov.w   DAT_0602a4f4, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passB_v0_chk_top
    mov #0x1, r0
    bra     .L_passB_v0_bounds_done
    mov.w r0, @r12

    .global DAT_0602a4f4
DAT_0602a4f4:
    .2byte  0xFE70
.L_passB_v0_chk_top:
    mov.w   DAT_0602a502, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passB_v0_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v0_bounds_done
    mov.w r0, @r12

    .global DAT_0602a502
DAT_0602a502:
    .2byte  0x012C
.L_passB_v0_chk_bottom:
    mov.w   DAT_0602a54a, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passB_v0_bounds_done
    mov #0x1, r0
    mov.w r0, @r12
.L_passB_v0_bounds_done:
    mov r11, r5                             ! r5 = poly_params output
    add #0xC, r4
    add #0x8, r5
    mov.w   DAT_0602a54c, r1
    mov.w   DAT_0602a54e, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(2, r12)
    mov.w   DAT_0602a550, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passB_v1_chk_left
    mov #0x1, r0
    bra     .L_passB_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_0602a54a
DAT_0602a54a:
    .2byte  0xFE70

    .global DAT_0602a54c
DAT_0602a54c:
    .2byte  0xFF00

    .global DAT_0602a54e
DAT_0602a54e:
    .2byte  0x00A0

    .global DAT_0602a550
DAT_0602a550:
    .2byte  0x0190
.L_passB_v1_chk_left:
    mov.w   DAT_0602a55e, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passB_v1_chk_top
    mov #0x1, r0
    bra     .L_passB_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_0602a55e
DAT_0602a55e:
    .2byte  0xFE70
.L_passB_v1_chk_top:
    mov.w   DAT_0602a56c, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passB_v1_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v1_bounds_done
    mov.w r0, @(2, r12)

    .global DAT_0602a56c
DAT_0602a56c:
    .2byte  0x012C
.L_passB_v1_chk_bottom:
    mov.w   DAT_0602a5b4, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passB_v1_bounds_done
    mov #0x1, r0
    mov.w r0, @(2, r12)
.L_passB_v1_bounds_done:
    mov r11, r5                             ! r5 = poly_params output
    add #0xC, r4
    add #0x10, r5
    mov.w   DAT_0602a5b6, r1
    mov.w   DAT_0602a5b8, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(4, r12)
    mov.w   DAT_0602a5ba, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passB_v2_chk_left
    mov #0x1, r0
    bra     .L_passB_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_0602a5b4
DAT_0602a5b4:
    .2byte  0xFE70

    .global DAT_0602a5b6
DAT_0602a5b6:
    .2byte  0xFF00

    .global DAT_0602a5b8
DAT_0602a5b8:
    .2byte  0x00A0

    .global DAT_0602a5ba
DAT_0602a5ba:
    .2byte  0x0190
.L_passB_v2_chk_left:
    mov.w   DAT_0602a5c8, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passB_v2_chk_top
    mov #0x1, r0
    bra     .L_passB_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_0602a5c8
DAT_0602a5c8:
    .2byte  0xFE70
.L_passB_v2_chk_top:
    mov.w   DAT_0602a5d6, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passB_v2_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v2_bounds_done
    mov.w r0, @(4, r12)

    .global DAT_0602a5d6
DAT_0602a5d6:
    .2byte  0x012C
.L_passB_v2_chk_bottom:
    mov.w   DAT_0602a61e, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passB_v2_bounds_done
    mov #0x1, r0
    mov.w r0, @(4, r12)
.L_passB_v2_bounds_done:
    mov r11, r5                             ! r5 = poly_params output
    add #0xC, r4
    add #0x18, r5
    mov.w   DAT_0602a620, r1
    mov.w   DAT_0602a622, r0
    mov.l @(8, r4), r2
    mov.l r0, @(16, r1)
    mov.l r2, @(0, r1)
    mov #0x0, r0
    mov.l r0, @(20, r1)
    mov.l @(4, r4), r3
    mov.l @r4, r2
    mov.l @(28, r1), r0
    dmuls.l r2, r0                          ! perspective: X * (1/Z)
    neg r3, r3                              ! negate Y for screen coords
    sts mach, r1
    dmuls.l r3, r0                          ! perspective: -Y * (1/Z)
    mov.l r1, @r5                           ! store transformed X
    sts mach, r2
    mov.l r2, @(4, r5)
    mov.l @r5, r1
    mov.l @(4, r5), r2
    mov #0x0, r0
    mov.w r0, @(6, r12)
    mov.w   DAT_0602a624, r3
    cmp/gt r3, r1                           ! screen bounds check
    bf      .L_passB_v3_chk_left
    mov #0x1, r0
    bra     .L_passB_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a61e
DAT_0602a61e:
    .2byte  0xFE70

    .global DAT_0602a620
DAT_0602a620:
    .2byte  0xFF00

    .global DAT_0602a622
DAT_0602a622:
    .2byte  0x00A0

    .global DAT_0602a624
DAT_0602a624:
    .2byte  0x0190
.L_passB_v3_chk_left:
    mov.w   DAT_0602a632, r3
    cmp/gt r1, r3                           ! screen bounds check
    bf      .L_passB_v3_chk_top
    mov #0x1, r0
    bra     .L_passB_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a632
DAT_0602a632:
    .2byte  0xFE70
.L_passB_v3_chk_top:
    mov.w   DAT_0602a640, r3
    cmp/gt r3, r2                           ! screen bounds check
    bf      .L_passB_v3_chk_bottom
    mov #0x1, r0
    bra     .L_passB_v3_bounds_done
    mov.w r0, @(6, r12)

    .global DAT_0602a640
DAT_0602a640:
    .2byte  0x012C
.L_passB_v3_chk_bottom:
    mov.w   DAT_0602a670, r3
    cmp/gt r2, r3                           ! screen bounds check
    bf      .L_passB_v3_bounds_done
    mov #0x1, r0
    mov.w r0, @(6, r12)
.L_passB_v3_bounds_done:
    mov.l   .L_sh2_periph_0x150_0602A674, r4
    mov.l   .L_scale_constant_b, r5
    mov.l   .L_sh2_periph_0x181_0602A67C, r6
    mov.l   .L_poly_limit_b, r7
    mov.l @r11, r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passB_frustum_right
    mov.l @(8, r11), r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passB_frustum_right
    mov.l @(16, r11), r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passB_frustum_right
    mov.l @(24, r11), r0
    cmp/gt r0, r4                           ! all verts left of frustum?
    bf      .L_passB_frustum_right
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)

    .global DAT_0602a670
DAT_0602a670:
    .2byte  0xFE70
    .2byte  0x0000
.L_sh2_periph_0x150_0602A674:
    .4byte  0xFFFFFF50                  /* SH-2 peripheral +0x150 */
.L_scale_constant_b:
    .4byte  0x000000B0
.L_sh2_periph_0x181_0602A67C:
    .4byte  0xFFFFFF81                  /* SH-2 peripheral +0x181 */
.L_poly_limit_b:
    .4byte  0x00000051
.L_passB_frustum_right:
    mov.l @r11, r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passB_frustum_top
    mov.l @(8, r11), r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passB_frustum_top
    mov.l @(16, r11), r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passB_frustum_top
    mov.l @(24, r11), r0
    cmp/gt r0, r5                           ! all verts right of frustum?
    bt      .L_passB_frustum_top
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)
.L_passB_frustum_top:
    mov.l @(4, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passB_frustum_bottom
    mov.l @(12, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passB_frustum_bottom
    mov.l @(20, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passB_frustum_bottom
    mov.l @(28, r11), r0
    cmp/gt r0, r6                           ! all verts above frustum?
    bf      .L_passB_frustum_bottom
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)
.L_passB_frustum_bottom:
    mov.l @(4, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passB_frustum_pass
    mov.l @(12, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passB_frustum_pass
    mov.l @(20, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passB_frustum_pass
    mov.l @(28, r11), r0
    cmp/gt r0, r7                           ! all verts below frustum?
    bt      .L_passB_frustum_pass
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)
.L_passB_frustum_pass:
    mov.w @r12, r1                          ! r1 = clip flag for vertex 0
    mov.w @(2, r12), r0                     ! r0 = clip flag for vertex 1
    add r0, r1                              ! accumulate clip flags
    mov.w @(4, r12), r0                     ! r0 = clip flag for vertex 2
    add r0, r1                              ! accumulate clip flags
    mov.w @(6, r12), r0                     ! r0 = clip flag for vertex 3
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    cmp/eq #0x4, r0                         ! all 4 vertices clipped?
    bf      .L_passB_partial_clip
    bra     .L_skip_polygon_b
    nop                                     ! (delay slot)
.L_passB_partial_clip:
    cmp/eq #0x0, r0                         ! no vertices clipped?
    bt      .L_passB_emit_quad
    mov r11, r4                             ! r4 = poly_params (for clip handler)
    shll2 r0                                ! index * 4 (table offset)
    mov.l   .L_pipeline_b_sub, r1
    add r1, r0                              ! r0 = &dispatch_table[clip_count]
    mov.l @r0, r0
    jsr @r0                                 ! call clip/dispatch handler
    mov r12, r5                             ! r5 = clip flags (for clip handler)
.L_passB_emit_quad:
    mov.l @r11, r0
    mov.w r0, @(8, r9)                      ! write to sprite entry
    mov.l @(4, r11), r0
    mov.w r0, @(10, r9)                     ! write to sprite entry
    mov.l @(8, r11), r0
    mov.w r0, @(12, r9)                     ! write to sprite entry
    mov.l @(12, r11), r0
    mov.w r0, @(14, r9)                     ! write to sprite entry
    mov.l @(16, r11), r0
    mov.w r0, @(16, r9)                     ! write to sprite entry
    mov.l @(20, r11), r0
    mov.w r0, @(18, r9)                     ! write to sprite entry
    mov.l @(24, r11), r0
    mov.w r0, @(20, r9)                     ! write to sprite entry
    mov.l @(28, r11), r0
    mov.w r0, @(22, r9)                     ! write to sprite entry
    mov.w @(14, r8), r0
    mov.w r0, @(6, r9)                      ! write to sprite entry
    mov.w @(12, r8), r0
    shlr2 r0                                ! shift right by 2
    shlr2 r0                                ! shift right by 2
    and #0xF, r0                            ! mask to 4-bit render mode
    mov.b r0, @(4, r9)                      ! write render flags
    mov r13, r0                             ! r0 = render pass ID
    mov.b r0, @(5, r9)                      ! write pass ID
    mov.w @(12, r8), r0
    mov.l   .L_pipeline_b_sub2, r1
    and #0x7, r0                            ! mask to 3-bit depth sort mode
    shll2 r0                                ! index * 4 (table offset)
    mov.l @(r0, r1), r0                     ! load handler from dispatch table
    mov.l   .L_vertex_data_e2, r1
    mov.l @(8, r1), r3
    mov.l @(20, r1), r4
    mov.l @(32, r1), r5
    jmp @r0                                 ! tail-call depth sort handler
    mov.l @(44, r1), r6
.L_pipeline_b_sub:
    .4byte  sym_0602A810
.L_pipeline_b_sub2:
    .4byte  sym_0602A820
.L_vertex_data_e2:
    .4byte  sym_0608A7A0

    .global loc_0602A754
loc_0602A754:
    add r4, r3                              ! sum: z0 + z1
    add r5, r6                              ! sum: z2 + z3
    add r6, r3                              ! sum all 4 depths
    shlr2 r3                                ! divide by 4 (average depth)
    bra     .L_passB_zsort_commit
    nop                                     ! (delay slot)

    .global loc_0602A760
loc_0602A760:
    cmp/ge r3, r4                           ! compare against current min (>=)
    bt      .L_depthB_min_ge_1
    mov r4, r3                              ! update min depth
.L_depthB_min_ge_1:
    cmp/ge r3, r5                           ! compare against current min (>=)
    bt      .L_depthB_min_ge_2
    mov r5, r3                              ! update min depth
.L_depthB_min_ge_2:
    cmp/ge r3, r6                           ! compare against current min (>=)
    bt      .L_depthB_min_ge_done
    mov r6, r3                              ! update min depth
.L_depthB_min_ge_done:
    bra     .L_passB_zsort_commit
    nop                                     ! (delay slot)

    .global loc_0602A776
loc_0602A776:
    cmp/gt r3, r4                           ! compare against current min (>)
    bf      .L_depthB_min_gt_1
    mov r4, r3                              ! update min depth
.L_depthB_min_gt_1:
    cmp/gt r3, r5                           ! compare against current min (>)
    bf      .L_depthB_min_gt_2
    mov r5, r3                              ! update min depth
.L_depthB_min_gt_2:
    cmp/gt r3, r6                           ! compare against current min (>)
    bf      .L_depthB_min_gt_done
    mov r6, r3                              ! update min depth
.L_depthB_min_gt_done:
    bra     .L_passB_zsort_commit
    nop                                     ! (delay slot)

    .global loc_0602A78C
loc_0602A78C:
    mov.l   .L_fp_depth_bias_b, r0
    cmp/gt r3, r4                           ! compare against current min (>)
    bf      .L_depthB_bias_min_1
    mov r4, r3                              ! update min depth
.L_depthB_bias_min_1:
    cmp/gt r3, r5                           ! compare against current min (>)
    bf      .L_depthB_bias_min_2
    mov r5, r3                              ! update min depth
.L_depthB_bias_min_2:
    cmp/gt r3, r6                           ! compare against current min (>)
    bf      .L_depthB_bias_min_done
    mov r6, r3                              ! update min depth
.L_depthB_bias_min_done:
    bra     .L_passB_zsort_commit
    add r0, r3                              ! add depth bias
.L_fp_depth_bias_b:
    .4byte  0x000B8000

    .global loc_0602A7A8
loc_0602A7A8:
    mov.l   .L_fp_one_0602A7E4, r0
    cmp/gt r3, r4                           ! compare against current min (>)
    bf      .L_depthB_offset_min_1
    mov r4, r3                              ! update min depth
.L_depthB_offset_min_1:
    cmp/gt r3, r5                           ! compare against current min (>)
    bf      .L_depthB_offset_min_2
    mov r5, r3                              ! update min depth
.L_depthB_offset_min_2:
    cmp/gt r3, r6                           ! compare against current min (>)
    bf      .L_depthB_offset_min_done
    mov r6, r3                              ! update min depth
.L_depthB_offset_min_done:
    add r0, r3                              ! add depth bias
.L_passB_zsort_commit:
    mov.l   .L_frame_counter_2, r2
    neg r3, r3                              ! negate depth for sort key (farther = higher key)
    mov.l   .L_sprite_idx_b, r1
    shlr8 r3                                ! depth >> 8 (coarse sort bucket)
    mov.l @r2, r0
    shlr2 r3                                ! depth >> 2 (fine sort adjustment)
    shlr2 r3                                ! depth >> 2 (fine sort adjustment)
    shll r0                                 ! count * 2 (word index into sort table)
    mov.w r3, @(r0, r1)                     ! write sort key to sprite index table
    shar r0                                 ! restore count from word index
    add #0x1, r0                            ! increment committed sprite count
    mov.l r0, @r2
.L_skip_polygon_b:
    mov.l @r15+, r7                         ! pop r7 (loop variable)
    mov.l @r15+, r3                         ! pop r3 (loop variable)
    dt r7
    bt      .L_return_transform
    bra     .L_transform_loop_b
    nop                                     ! (delay slot)
    .2byte  0x0000
.L_fp_one_0602A7E4:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_frame_counter_2:
    .4byte  sym_060620D4
.L_sprite_idx_b:
    .4byte  sym_0606A4F8
.L_return_transform:
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r13                        ! restore r13
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r9                         ! restore r9
    rts                                     ! return
    mov.l @r15+, r8                         ! restore r8

    .global sym_0602A800
sym_0602A800:
    .word 0x0000 /* UNKNOWN */
    .word 0x0000 /* UNKNOWN */
    .4byte  spring_damper
    .4byte  transform_pipeline
    .4byte  mega_render_func

    .global sym_0602A810
sym_0602A810:
    .word 0x0000 /* UNKNOWN */
    .word 0x0000 /* UNKNOWN */
    .4byte  vblank_frame_handler
    .4byte  render_list_builder
    .4byte  render_obj_processor

    .global sym_0602A820
sym_0602A820:
    .4byte  loc_0602A754
    .4byte  loc_0602A760
    .4byte  loc_0602A776
    .4byte  loc_0602A7A8
    .4byte  loc_0602A78C

    .global sym_0602A834
sym_0602A834:
    mov.l r8, @-r15                         ! save r8
    mov.l r9, @-r15                         ! save r9
    mov.l r10, @-r15                        ! save r10
    mov.l r11, @-r15                        ! save r11
    mov.l r12, @-r15                        ! save r12
    mov.l r13, @-r15                        ! save r13
