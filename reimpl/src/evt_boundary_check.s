
    .section .text.FUN_06040F82


    .global evt_boundary_check
    .type evt_boundary_check, @function
evt_boundary_check:
    sts.l pr, @-r15
    add #-0x4, r15
    mov r15, r5
    .byte   0xD3, 0x09    /* mov.l .L_fn_mesh_boundary, r3 */
    jsr @r3
    mov #0x0, r4
    mov r15, r5
    mov r15, r4
    .byte   0xD3, 0x07    /* mov.l .L_fn_mesh_boundary, r3 */
    mov.b @r4, r4
    jsr @r3
    extu.b r4, r4
    mov r15, r0
    .byte   0xD3, 0x05    /* mov.l .L_mask_24bit, r3 */
    mov.l @r0, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    and r3, r0
    .4byte  0x0000FFFF
    .4byte  0x00008000
.L_fn_mesh_boundary:
    .4byte  mesh_boundary_check           /* mesh boundary validator */
.L_mask_24bit:
    .4byte  0x00FFFFFF                  /* low 24-bit mask */

    .global sym_06040FB8
sym_06040FB8:
    .byte   0xD4, 0x15    /* mov.l .L_ptr_lock_state, r4 */
    mov.l @r4, r0
    mov.l @(48, r0), r0
    cmp/eq #0x1, r0
    bf      .L_not_locked
    rts
    mov #-0x5, r0
.L_not_locked:
    mov #0x1, r3
    mov.l @r4, r2
    mov.l r3, @(48, r2)
    mov.l @r4, r2
    mov.l @(56, r2), r3
    add #0x1, r3
    mov.l r3, @(56, r2)
    mov.l @r4, r2
    mov.l @(56, r2), r3
    cmp/pz r3
    bt      .L_seq_nonneg
    mov.l @r4, r3
    mov #0x0, r2
    mov.l r2, @(56, r3)
.L_seq_nonneg:
    mov.l @r4, r0
    mov.l @(56, r0), r0
    rts
    nop

    .global sym_06040FEA
sym_06040FEA:
    .byte   0xD5, 0x09    /* mov.l .L_ptr_lock_state, r5 */
    mov.l @r5, r3
    mov.l @(48, r3), r0
    tst r0, r0
    bf      .L_is_locked
    rts
    mov #-0x7, r0
.L_is_locked:
    mov.l @r5, r3
    mov.l @(56, r3), r2
    cmp/eq r4, r2
    bt      .L_seq_match
    rts
    mov #-0x9, r0
.L_seq_match:
    mov #0x0, r4
    mov.l @r5, r2
    mov.l r4, @(48, r2)
    mov r4, r0
    rts
    nop
.L_ptr_lock_state:
    .4byte  sym_060A5400                  /* event boundary lock state */

    .global sym_06041014
sym_06041014:
    .byte   0xD5, 0x11    /* mov.l .L_ptr_lock_state, r5 */
    mov.l @r5, r3
    mov.l @(48, r3), r0
    tst r0, r0
    bf      .L_check_active
    rts
    mov #0x0, r0
.L_check_active:
    mov.l @r5, r0
    mov.l @(56, r0), r3
    cmp/eq r4, r3
    bf      .L_no_match
    bra     .L_return
    mov #0x1, r0
.L_no_match:
    mov #0x0, r0
.L_return:
    rts
    nop
