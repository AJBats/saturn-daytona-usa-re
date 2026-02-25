/* obj_setup_decomp -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0604077C - 0x0604087C
 *
 * obj_setup_decomp: Initialise an object descriptor from caller-supplied
 * parameters, then acquire the three resource slots (direct, zone, buffer)
 * the object needs before it can participate in road-segment tracking.
 *
 * Called from save_serialize with an already-allocated object block:
 *   r4  = obj_ptr  — pointer to the object descriptor to fill
 *   r5  = data_ptr — pointer to the source data word to store at obj[+0]
 *   r6  = extra    — 32-bit value stored at obj[+12]
 *   r7  = flags    — byte flags; low byte stored at obj[+0x18]
 *   @(sp+0x1F)     — 5th arg byte stored at obj[+0x24] (extra slot param)
 *
 * Return: r0 = obj_ptr on success, 0 on any failure.
 *
 * Failure paths (all return r0=0):
 *   - slot_alloc_direct (sym_06040EEC) returns non-zero
 *   - slot_alloc_zone   (sym_06040E88) returns non-zero (also calls evt_reg_save)
 *   - buffer_slot_alloc returns non-zero
 *   - track_segment_interp (sym in next TU) returns non-zero
 *   - state_field_read     (sym in next TU) returns non-zero
 *
 * Calls (all via constant pool):
 *   sym_06035228   = memcpy_byte(r0=count, r1=dst, r2=src)
 *   sym_06040EEC   = slot_alloc_direct(r4=out_ptr) -> r0
 *   sym_06040E88   = slot_alloc_zone(r4=out_ptr) -> r0
 *   evt_reg_save   (on slot_alloc_zone failure, r4=slot index to release)
 *   buffer_slot_alloc(r4=out_ptr) -> r0
 *   + two cross-section pool loads (wpool + 2 lpool) that reach into the
 *     following TU (watchdog_timer_reset / DAT_0604089c area).
 *
 * Stack frame: 0x10 bytes of local storage
 *   sp+0x00 : ptr result from slot_alloc_direct (written by callee)
 *   sp+0x04 : ptr result from slot_alloc_zone   (written by callee)
 *   sp+0x08 : local copy of obj[+0x18] (flags byte)  — 6-byte struct
 *   sp+0x0F : 5th arg byte (r7 copy, before add) at sp+0x1F relative to entry
 */

    .section .text.FUN_0604077C


    .global obj_setup_decomp
    .type obj_setup_decomp, @function
obj_setup_decomp:
    mov.l r14, @-r15                    ! push r14 (callee-save)
    mov.l r13, @-r15                    ! push r13 (callee-save)
    sts.l pr, @-r15                     ! push return address
    add #-0x10, r15                     ! allocate 16-byte local frame
    mov r4, r14                         ! r14 = obj_ptr (saved across calls)
    mov.l r5, @r14                      ! obj[+0] = data_ptr
    mov #0x0, r13                       ! r13 = 0 (constant zero, callee-save)
    mov.l r13, @(8, r14)                ! obj[+8] = 0 (clear field)
    extu.b r7, r7                       ! zero-extend flags byte
    mov #0x18, r0                       ! r0 = 0x18 (offset of flags byte in obj)
    mov.b r7, @(r0, r14)                ! obj[+0x18] = flags (low byte of r7)
    mov.l r6, @(12, r14)               ! obj[+12] = extra arg (r6)
    mov.l r13, @(16, r14)              ! obj[+16] = 0
    mov #0x1, r3                        ! r3 = 1
    mov.l r3, @(32, r14)               ! obj[+32] = 1 (initial ref count or type)
    mov #0x19, r0                       ! r0 = 0x19
    mov.b r13, @(r0, r14)              ! obj[+0x19] = 0
    mov #0x1A, r0                       ! r0 = 0x1A
    mov.b r13, @(r0, r14)              ! obj[+0x1A] = 0
    mov #0x1B, r0                       ! r0 = 0x1B
    mov.b r13, @(r0, r14)              ! obj[+0x1B] = 0
    mov #0x1F, r0                       ! r0 = 0x1F (offset of 5th arg on entry stack)
    mov.b @(r0, r15), r3               ! r3 = *(sp+0x1F) = 5th arg byte
    extu.b r3, r3                       ! zero-extend 5th arg byte
    mov.l r3, @(36, r14)               ! obj[+36] = 5th arg (zero-extended)
    ! --- build 6-byte local struct at sp+8 for memcpy_byte ---
    mov r15, r3                         ! r3 -> sp
    add #0x8, r3                        ! r3 -> sp+8 (local struct base)
    mov #0x18, r0                       ! r0 = 0x18 (flags offset in obj)
    mov.b @(r0, r14), r2               ! r2 = obj[+0x18] (flags byte)
    mov.b r2, @r3                       ! local[0] = flags byte
    mov r15, r3                         ! r3 -> sp
    add #0x8, r3                        ! r3 -> sp+8
    mov #0x19, r0                       ! r0 = 0x19
    extu.b r13, r2                      ! r2 = 0 (zero-extended)
    mov r14, r1                         ! r1 = obj_ptr (used below)
    mov.b @(r0, r14), r0               ! r0 = obj[+0x19]
    add #0x18, r1                       ! r1 = &obj[+0x18] (src for memcpy_byte)
    mov.b r0, @(1, r3)                 ! local[1] = obj[+0x19]
    mov r15, r3                         ! r3 -> sp
    extu.b r13, r0                      ! r0 = 0
    add #0x8, r3                        ! r3 -> sp+8
    mov.b r0, @(2, r3)                 ! local[2] = 0
    mov r15, r3                         ! r3 -> sp
    extu.b r13, r0                      ! r0 = 0
    add #0x8, r3                        ! r3 -> sp+8
    mov.b r0, @(3, r3)                 ! local[3] = 0
    mov r15, r3                         ! r3 -> sp
    extu.b r13, r0                      ! r0 = 0
    add #0x8, r3                        ! r3 -> sp+8
    mov.b r0, @(4, r3)                 ! local[4] = 0
    mov r15, r3                         ! r3 -> sp
    mov r2, r0                          ! r0 = 0 (r2 was zero from extu.b above)
    add #0x8, r3                        ! r3 -> sp+8
    mov r15, r2                         ! r2 -> sp
    mov.b r0, @(5, r3)                 ! local[5] = 0
    add #0x8, r2                        ! r2 = sp+8 (src pointer for memcpy_byte)
    ! --- call memcpy_byte(r0=6, r1=&obj[+0x18], r2=sp+8) ---
    mov.l   _pool_memcpy_byte, r3      ! r3 -> memcpy_byte (sym_06035228)
    jsr @r3                             ! call memcpy_byte
    mov #0x6, r0                        ! delay: r0 = 6 (byte count)
    ! --- call slot_alloc_direct(r4=sp) -> r0 ---
    mov #-0x1, r2                       ! r2 = -1 (sentinel for obj[+40])
    mov r15, r4                         ! r4 -> sp (output pointer for slot index)
    mov.l r2, @(40, r14)               ! obj[+40] = -1 (pre-init direct slot field)
    mov.l   _pool_slot_alloc_direct, r3 ! r3 -> slot_alloc_direct (sym_06040EEC)
    jsr @r3                             ! call slot_alloc_direct(sp)
    add #0x4, r4                        ! delay: r4 = sp+4 (but jsr uses r4=sp)
    tst r0, r0                          ! slot_alloc_direct succeeded?
    bt      .Lslot_direct_ok            ! yes -> branch
    bra     .Lreturn_fail               ! no  -> return failure
    mov #0x0, r0                        ! delay: r0 = 0 (return value on fail path)
.Lslot_direct_ok:
    mov.l @(4, r15), r3                ! r3 = direct slot index (written by callee at sp+4?)
    mov.l r3, @(4, r14)               ! obj[+4] = direct slot index
    ! --- call slot_alloc_zone(r4=sp) -> r0 ---
    mov.l   _pool_slot_alloc_zone, r3  ! r3 -> slot_alloc_zone (sym_06040E88)
    jsr @r3                             ! call slot_alloc_zone(sp)
    mov r15, r4                         ! delay: r4 = sp (output pointer)
    tst r0, r0                          ! succeeded?
    bt      .Lslot_zone_ok             ! yes -> proceed
    ! --- slot_alloc_zone failed: release direct slot then fail ---
    mov.l   _pool_evt_reg_save, r3     ! r3 -> evt_reg_save
    jsr @r3                             ! call evt_reg_save(r4=direct slot index)
    mov.l @(4, r15), r4                ! delay: r4 = direct slot index to release
    bra     .Lreturn_fail               ! -> return failure
    mov #0x0, r0                        ! delay: r0 = 0 (return value)
.Lslot_zone_ok:
    mov r13, r7                         ! r7 = 0 (zero arg)
    mov.l @r15, r2                      ! r2 = *(sp+0) = zone slot index
    mov.l r2, @(20, r14)               ! obj[+20] = zone slot index
    mov.l r13, @-r15                    ! push 0 (extra arg for buffer_slot_alloc)
    mov r15, r6                         ! r6 -> sp (now adjusted)
    mov.l @(32, r14), r5               ! r5 = obj[+32] (ref count / type)
    mov.l   _pool_buffer_slot_alloc, r3 ! r3 -> buffer_slot_alloc
    add #0xC, r6                        ! r6 = sp+12 (adjusted output pointer)
    jsr @r3                             ! call buffer_slot_alloc(r4=?, r5, r6, r7=0)
    mov.l @(4, r15), r4                ! delay: r4 = direct slot index
    tst r0, r0                          ! buffer_slot_alloc succeeded?
    bt/s    .Lbuffer_slot_ok           ! yes -> proceed (delay slot executes)
    add #0x4, r15                       ! delay: pop extra push
    bra     .Lreturn_fail               ! no  -> return failure
    mov #0x0, r0                        ! delay: r0 = 0
    ! ------- constant pool (5 entries, addresses resolved by linker) ----------
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
    ! ---- code continues; pool loads below reach into next TU's data -----------
.Lbuffer_slot_ok:
    .byte   0x96, 0x24    /* mov.w .L_wpool_0604089C, r6 */  ! r6 = 0x00FF (mask from DAT_0604089c)
    mov.l @(4, r15), r5                ! r5 = direct slot index
    .byte   0xD3, 0x12    /* mov.l .L_pool_060408A0, r3 */   ! r3 -> track_segment_interp
    jsr @r3                             ! call track_segment_interp(r4, r5, r6)
    mov.l @r15, r4                      ! delay: r4 = zone slot index
    tst r0, r0                          ! succeeded?
    bt      .Ltrack_seg_ok             ! yes -> proceed
    bra     .Lreturn_fail               ! no  -> return failure
    mov #0x0, r0                        ! delay: r0 = 0
.Ltrack_seg_ok:
    .byte   0xD3, 0x10    /* mov.l .L_pool_060408A4, r3 */   ! r3 -> state_field_read
    jsr @r3                             ! call state_field_read()
    nop                                 ! delay
    tst r0, r0                          ! succeeded?
    bt      .Lreturn_obj               ! yes -> return obj_ptr
    bra     .Lreturn_fail               ! no  -> return failure
    mov #0x0, r0                        ! delay: r0 = 0
.Lreturn_obj:
    mov r14, r0                         ! r0 = obj_ptr (success return)
.Lreturn_fail:
    add #0x10, r15                      ! release local frame
    lds.l @r15+, pr                     ! pop return address
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return (r0 = obj_ptr or 0)
    mov.l @r15+, r14                    ! delay: restore r14
