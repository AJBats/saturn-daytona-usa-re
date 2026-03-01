
    .section .text.FUN_0604077C


    .global obj_setup_decomp
    .type obj_setup_decomp, @function
obj_setup_decomp:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov r4, r14
    mov.l r5, @r14
    mov #0x0, r13
    mov.l r13, @(8, r14)
    extu.b r7, r7
    mov #0x18, r0
    mov.b r7, @(r0, r14)
    mov.l r6, @(12, r14)
    mov.l r13, @(16, r14)
    mov #0x1, r3
    mov.l r3, @(32, r14)
    mov #0x19, r0
    mov.b r13, @(r0, r14)
    mov #0x1A, r0
    mov.b r13, @(r0, r14)
    mov #0x1B, r0
    mov.b r13, @(r0, r14)
    mov #0x1F, r0
    mov.b @(r0, r15), r3
    extu.b r3, r3
    mov.l r3, @(36, r14)
    mov r15, r3
    add #0x8, r3
    mov #0x18, r0
    mov.b @(r0, r14), r2
    mov.b r2, @r3
    mov r15, r3
    add #0x8, r3
    mov #0x19, r0
    extu.b r13, r2
    mov r14, r1
    mov.b @(r0, r14), r0
    add #0x18, r1
    mov.b r0, @(1, r3)
    mov r15, r3
    extu.b r13, r0
    add #0x8, r3
    mov.b r0, @(2, r3)
    mov r15, r3
    extu.b r13, r0
    add #0x8, r3
    mov.b r0, @(3, r3)
    mov r15, r3
    extu.b r13, r0
    add #0x8, r3
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r2, r0
    add #0x8, r3
    mov r15, r2
    mov.b r0, @(5, r3)
    add #0x8, r2
    mov.l   _pool_memcpy_byte, r3
    jsr @r3
    mov #0x6, r0
    mov #-0x1, r2
    mov r15, r4
    mov.l r2, @(40, r14)
    mov.l   _pool_slot_alloc_direct, r3
    jsr @r3
    add #0x4, r4
    tst r0, r0
    bt      .Lslot_direct_ok
    bra     .Lreturn_fail
    mov #0x0, r0
.Lslot_direct_ok:
    mov.l @(4, r15), r3
    mov.l r3, @(4, r14)
    mov.l   _pool_slot_alloc_zone, r3
    jsr @r3
    mov r15, r4
    tst r0, r0
    bt      .Lslot_zone_ok
    mov.l   _pool_evt_reg_save, r3
    jsr @r3
    mov.l @(4, r15), r4
    bra     .Lreturn_fail
    mov #0x0, r0
.Lslot_zone_ok:
    mov r13, r7
    mov.l @r15, r2
    mov.l r2, @(20, r14)
    mov.l r13, @-r15
    mov r15, r6
    mov.l @(32, r14), r5
    mov.l   _pool_buffer_slot_alloc, r3
    add #0xC, r6
    jsr @r3
    mov.l @(4, r15), r4
    tst r0, r0
    bt/s    .Lbuffer_slot_ok
    add #0x4, r15
    bra     .Lreturn_fail
    mov #0x0, r0
_pool_memcpy_byte:
    .4byte  sym_06035228
_pool_slot_alloc_direct:
    .4byte  sym_06040EEC
_pool_slot_alloc_zone:
    .4byte  sym_06040E88
_pool_evt_reg_save:
    .4byte  evt_reg_save
_pool_buffer_slot_alloc:
    .4byte  buffer_slot_alloc
.Lbuffer_slot_ok:
    .byte   0x96, 0x24    /* mov.w .L_wpool_0604089C, r6 */
    mov.l @(4, r15), r5
    .byte   0xD3, 0x12    /* mov.l .L_pool_060408A0, r3 */
    jsr @r3
    mov.l @r15, r4
    tst r0, r0
    bt      .Ltrack_seg_ok
    bra     .Lreturn_fail
    mov #0x0, r0
.Ltrack_seg_ok:
    .byte   0xD3, 0x10    /* mov.l .L_pool_060408A4, r3 */
    jsr @r3
    nop
    tst r0, r0
    bt      .Lreturn_obj
    bra     .Lreturn_fail
    mov #0x0, r0
.Lreturn_obj:
    mov r14, r0
.Lreturn_fail:
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
