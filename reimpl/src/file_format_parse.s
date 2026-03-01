/* file_format_parse -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06012454 - 0x0601250C
 *
 * 3D object render setup — performs pre-transform initialization, computes
 * a fixed-point rotation angle via the memory store helper, applies the
 * transform matrix, then dispatches both transform chains (A for object
 * geometry, B for display submission) before tail-calling post-render
 * cleanup to pop the matrix frame.
 *
 * Flow:
 *   1. Pre-transform setup (sym_06026DBC)
 *   2. Matrix entry init (sym_06026E0C)
 *   3. Load position vector (XYZ) from R14 struct + dispatch transform (sym_06026E2E)
 *   4. Compute rotation angle: result * 0x60000 + 0x1000 via mem_store_helper
 *   5. Apply mat_rot_x with computed angle
 *   6. Dispatch transform chain A (sym_06031D8C) — object transform, indexed by counter-1
 *   7. Dispatch transform chain B (sym_06031A28) — display transform, indexed by counter-1
 *   8. Tail-call post-render cleanup (sym_06026DF8)
 *
 * R4 = position struct ptr (passed through to sub-calls via R14)
 * R5 = render mode byte (saved on stack, passed to mem_store_helper)
 */

    .section .text.FUN_06012454


    .global file_format_parse
    .type file_format_parse, @function
file_format_parse:
    sts.l pr, @-r15                        ! save return address
    add #-0x4, r15                         ! allocate 4 bytes on stack for local
    mov.l   .L_fn_pre_transform, r3        ! r3 = pre-transform setup fn
    jsr @r3                                ! call pre-transform setup
    mov.b r5, @r15                         ! (delay) save render mode byte to stack
    mov.l   .L_fn_matrix_init, r3          ! r3 = matrix entry init fn
    jsr @r3                                ! call matrix entry init
    nop                                    ! (delay)
    mov.l @(8, r14), r6                    ! r6 = position Z from struct[+8]
    mov.l @(4, r14), r5                    ! r5 = position Y from struct[+4]
    mov.l   .L_fn_transform_dispatch, r3   ! r3 = transform dispatch fn
    jsr @r3                                ! call transform dispatch(X, Y, Z)
    mov.l @r14, r4                         ! (delay) r4 = position X from struct[+0]
    mov.b @r15, r1                         ! r1 = reload saved render mode byte
    mov.l   .L_fn_mem_store_helper, r3     ! r3 = mem_store_helper fn
    extu.b r1, r1                          ! zero-extend render mode to 32 bits
    jsr @r3                                ! call mem_store_helper(r0=0x2, r1=mode)
    mov #0x2, r0                           ! (delay) r0 = 0x2 (store command)
    mov r0, r4                             ! r4 = result from mem_store_helper
    mov r0, r3                             ! r3 = same result (for parallel shift)
    mov.w   .L_angle_offset, r2            ! r2 = 0x1000 (fixed-point angle bias)
    shll8 r4                               ! r4 <<= 8 (result * 0x100)
    shll8 r3                               ! r3 <<= 8 (result * 0x100)
    shll2 r4                               ! r4 <<= 2 (result * 0x400)
    shll2 r3                               ! r3 <<= 2 (result * 0x400)
    shll2 r4                               ! r4 <<= 2 (result * 0x1000)
    shll2 r3                               ! r3 <<= 2 (result * 0x1000)
    shll2 r4                               ! r4 <<= 2 (result * 0x4000) = result << 18
    shll2 r3                               ! r3 <<= 2 (result * 0x4000)
    shll r3                                ! r3 <<= 1 = result << 17
    add r3, r4                             ! r4 = (result << 18) + (result << 17) = result * 0x60000
    mov.l   .L_fn_transform_mat, r3        ! r3 = mat_rot_x fn
    jsr @r3                                ! call mat_rot_x(angle)
    add r2, r4                             ! (delay) r4 += 0x1000 (add angle bias)
    mov.l   .L_chain_a_src, r5             ! r5 = &chain_a_source_param
    mov.l   .L_obj_counter, r4             ! r4 = &object_counter
    mov.l   .L_chain_a_table, r3           ! r3 = chain A lookup table base
    mov.l   .L_fn_chain_a, r2              ! r2 = transform chain A dispatch fn
    mov.l @r5, r5                          ! r5 = chain A source param value (0x4)
    mov.l @r4, r4                          ! r4 = object counter value
    add #-0x1, r4                          ! r4 = counter - 1 (zero-based index)
    shll2 r4                               ! r4 *= 4 (dword offset into table)
    add r3, r4                             ! r4 = &table[counter - 1]
    jsr @r2                                ! call chain A dispatch(r4=entry, r5=src)
    mov.l @r4, r4                          ! (delay) r4 = table[counter - 1] entry
    mov.l   .L_chain_b_src, r6             ! r6 = &chain_b_source_param
    mov.l   .L_disp_mode, r5               ! r5 = &display_mode_selector
    mov.l   .L_obj_counter, r4             ! r4 = &object_counter (reload)
    mov.l   .L_chain_b_table, r3           ! r3 = chain B lookup table base
    mov.l   .L_fn_chain_b, r2              ! r2 = transform chain B dispatch fn
    mov.l @r6, r6                          ! r6 = chain B source param value (0x1)
    mov.w @r5, r5                          ! r5 = display mode selector (16-bit)
    mov.l @r4, r4                          ! r4 = object counter value
    add #-0x1, r4                          ! r4 = counter - 1 (zero-based index)
    shll2 r4                               ! r4 *= 4 (dword offset into table)
    add r3, r4                             ! r4 = &table[counter - 1]
    jsr @r2                                ! call chain B dispatch(r4=entry, r5=mode, r6=src)
    mov.l @r4, r4                          ! (delay) r4 = table[counter - 1] entry
    add #0x4, r15                          ! free stack local
    lds.l @r15+, pr                        ! restore return address
    mov.l   .L_fn_post_cleanup, r3         ! r3 = post-render cleanup fn
    jmp @r3                                ! tail-call post-render cleanup (pops matrix frame)
    mov.l @r15+, r14                       ! (delay) restore r14 (callee-saved)
.L_angle_offset:
    .2byte  0x1000                         /* 0x1000 fixed-point angle bias */
.L_fn_pre_transform:
    .4byte  sym_06026DBC                   /* pre-transform setup */
.L_fn_matrix_init:
    .4byte  sym_06026E0C                   /* matrix entry init */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E                   /* position transform dispatch */
.L_fn_mem_store_helper:
    .4byte  sym_06035C2C                   /* memory store helper (writes to 0xFF00 area) */
.L_fn_transform_mat:
    .4byte  mat_rot_x               /* transform matrix application */
.L_chain_a_src:
    .4byte  sym_06063570                   /* chain A source param (dword: 0x4) */
.L_obj_counter:
    .4byte  sym_0607EAD8                   /* object/car counter (dword) */
.L_chain_a_table:
    .4byte  sym_06063564                   /* chain A lookup table (object transforms) */
.L_fn_chain_a:
    .4byte  sym_06031D8C                   /* transform chain dispatch A */
.L_chain_b_src:
    .4byte  sym_0606356C                   /* chain B source param (dword: 0x1) */
.L_disp_mode:
    .4byte  sym_06089EA0                   /* display mode selector (16-bit) */
.L_chain_b_table:
    .4byte  sym_0606355C                   /* chain B lookup table (display transforms) */
.L_fn_chain_b:
    .4byte  sym_06031A28                   /* transform chain dispatch B */
.L_fn_post_cleanup:
    .4byte  sym_06026DF8                   /* post-render cleanup (pop matrix frame) */
