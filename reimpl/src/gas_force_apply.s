/* gas_force_apply -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060081F4 - 0x06008318
 *
 * Per-frame gas/throttle force application. Called once per car from the
 * physics pipeline (car_frame_update stage 2). When the force timer is
 * active, looks up a signed force value from a pre-authored table (gas or
 * brake variant, selected by car flags bit 6) and writes it to the car's
 * applied-force field, decrementing the timer each frame. When the timer
 * expires and the car has been running for >= 20 frames with no active
 * force, checks collision (bit 4) and brake (bit 5) flags to start a new
 * 48-entry force sequence, optionally playing a collision sound. Finally
 * clears two bitfield flags via the bitfield write utility.
 *
 * Car struct offsets:
 *   +0x00  byte  flags (bit 6=gas, bit 5=brake, bit 4=collision)
 *   +0x08  int   frame counter (elapsed ticks)
 *   +0x0C  int   speed (reduced by constant each frame during force)
 *   +0xB8  int   force duration timer (counts down to 0)
 *   +0xBC  int   secondary force timer
 *   +0x1D8 int   speed direction (sign determines force polarity)
 *   +0x1DC int   force table index (negated + 0x30 bias)
 *
 * Globals:
 *   sym_0607E944  car array base pointer (iterated per-car)
 *   sym_0607EBD4  force timer reset value (set to 0x46 = 70 frames)
 *   sym_0607EBC4  master flags (bit 17 = 0x00020000 = sound enable)
 *   sym_0604540C  gas force lookup table (96 signed 16-bit entries)
 *   sym_0604546C  brake force lookup table (96 signed 16-bit entries)
 */

    .section .text.FUN_060081F4


    .global gas_force_apply
    .type gas_force_apply, @function
gas_force_apply:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    sts.l pr, @-r15                        ! save return address
    mov.l   _pool_car_array_base, r14      ! r14 = &car_array_base_ptr
    mov.w   _wpool_off_force_timer, r0     ! r0 = 0x00B8 (car+0xB8 force timer offset)
    mov.l @r14, r3                         ! r3 = car struct base
    mov.l @(r0, r3), r0                    ! r0 = car[+0xB8] (force duration timer)
    tst r0, r0                             ! timer == 0?
    bt      .L_timer_expired               ! yes -> handle expiry path
    ! --- Force timer active: apply force from lookup table ---
    mov #0x46, r3                          ! r3 = 70 (force timer reset value)
    mov.l   _pool_force_timer_reset, r2    ! r2 = &global_force_timer_reset
    mov.l r3, @r2                          ! global_force_timer_reset = 70
    mov.l @r14, r5                         ! r5 = car struct base
    mov.w   _wpool_off_force_timer, r0     ! r0 = 0x00B8 (force timer offset)
    mov.l @r14, r3                         ! r3 = car struct base
    mov.l @(r0, r5), r5                    ! r5 = car[+0xB8] (force timer, reused as index)
    mov.l @(r0, r3), r2                    ! r2 = car[+0xB8] (force timer value)
    neg r5, r5                             ! r5 = -force_timer (negate for table index)
    add #-0x1, r2                          ! r2 = timer - 1 (decrement)
    mov.l r2, @(r0, r3)                    ! car[+0xB8] = decremented timer
    mov.l @r14, r2                         ! r2 = car struct base
    mov r2, r0                             ! r0 = car base (for byte read)
    mov.b @r0, r0                          ! r0 = car[+0x00] flags byte
    tst #0x40, r0                          ! test bit 6 (gas flag)
    bt/s    .L_use_brake_table             ! gas flag clear -> use brake table
    add #0x30, r5                          ! r5 = -timer + 48 (biased table index) [delay]
    ! --- Gas flag set: use gas force table ---
    mov r5, r4                             ! r4 = biased index
    mov.l   _pool_gas_force_table, r3      ! r3 = &gas_force_table (sym_0604540C)
    bra     .L_apply_table_force           ! -> look up force
    shll r4                                ! r4 = index * 2 (word stride) [delay]
.L_use_brake_table:
    mov r5, r4                             ! r4 = biased index
    shll r4                                ! r4 = index * 2 (word stride)
    mov.l   _pool_brake_force_table, r3    ! r3 = &brake_force_table (sym_0604546C)
.L_apply_table_force:
    add r3, r4                             ! r4 = &table[index] (word pointer)
    mov.l @r14, r2                         ! r2 = car struct base
    mov.w   DAT_060082ac, r0               ! r0 = 0x01DC (force table index offset)
    mov r2, r1                             ! r1 = car struct base (alias)
    mov.l @(r0, r1), r3                    ! r3 = car[+0x1DC] (speed direction)
    cmp/pz r3                              ! speed direction >= 0?
    bt/s    .L_speed_positive              ! yes -> negate force
    mov.w @r4, r4                          ! r4 = table[index] (signed 16-bit force) [delay]
    ! --- Speed negative: use force value as-is ---
    bra     .L_store_force                 ! -> store result
    exts.w r4, r3                          ! r3 = sign-extend force to 32-bit [delay]
.L_speed_positive:
    ! --- Speed positive: negate force value ---
    exts.w r4, r1                          ! r1 = sign-extend force to 32-bit
    neg r1, r3                             ! r3 = -force (oppose positive speed)
.L_store_force:
    mov.w   _wpool_off_force_applied, r0   ! r0 = 0x01D8 (applied force offset)
    mov.l r3, @(r0, r2)                    ! car[+0x1D8] = computed force value
    mov.l @r14, r3                         ! r3 = car struct base
    mov.w   _wpool_speed_decay_const, r2   ! r2 = 0x00E3 (speed decay constant = 227)
    mov.l @(12, r3), r1                    ! r1 = car[+0x0C] (current speed)
    sub r2, r1                             ! r1 = speed - 227 (reduce speed)
    mov.l r1, @(12, r3)                    ! car[+0x0C] = reduced speed
    mov.l @r14, r0                         ! r0 = car struct base
    mov.w   _wpool_off_force_timer, r1     ! r1 = 0x00B8 (force timer offset)
    mov.l @(r0, r1), r0                    ! r0 = car[+0xB8] (force timer, now decremented)
    bra     .L_cleanup_exit                ! -> cleanup and return
    cmp/eq #0x50, r0                       ! timer == 80? (sets T bit for caller) [delay]
.L_timer_expired:
    ! --- Force timer expired: check if new force sequence should start ---
    mov.l @r14, r2                         ! r2 = car struct base
    mov.l @(8, r2), r3                     ! r3 = car[+0x08] (frame counter)
    mov #0x14, r2                          ! r2 = 20 (minimum frame threshold)
    cmp/ge r2, r3                          ! frames >= 20?
    bf      .L_cleanup_exit                ! no -> exit (too early for new force)
    mov.l @r14, r2                         ! r2 = car struct base
    mov.w   DAT_060082b2, r0               ! r0 = 0x00BC (secondary timer offset)
    mov.l @(r0, r2), r0                    ! r0 = car[+0xBC] (secondary force timer)
    tst r0, r0                             ! secondary timer == 0?
    bf      .L_cleanup_exit                ! no -> already has active force, exit
    ! --- Conditions met: prepare new force sequence ---
    mov.l   _pool_master_flags, r6         ! r6 = &master_flags (sym_0607EBC4)
    mov.l   _pool_sound_enable_mask, r5    ! r5 = 0x00020000 (sound enable bitmask)
    mov.l @r14, r2                         ! r2 = car struct base
    mov r2, r0                             ! r0 = car base (for byte read)
    mov.b @r0, r0                          ! r0 = car[+0x00] flags byte
    tst #0x10, r0                          ! test bit 4 (collision flag)
    bt/s    .L_check_brake_flag            ! collision not set -> check brake flag
    mov #0x30, r4                          ! r4 = 48 (force magnitude) [delay]
    ! --- Collision flag set: start force with direction = -1 ---
    mov.l @r14, r3                         ! r3 = car struct base
    mov #-0x1, r2                          ! r2 = -1 (reverse direction)
    mov.w   _wpool_off_force_timer, r0     ! r0 = 0x00B8 (force timer offset)
    mov.l r4, @(r0, r3)                    ! car[+0xB8] = 48 (start 48-frame force)
    mov.l @r14, r3                         ! r3 = car struct base
    mov.w   DAT_060082ac, r0               ! r0 = 0x01DC (force index offset)
    mov.l r2, @(r0, r3)                    ! car[+0x1DC] = -1 (initial direction)
    mov.l @r6, r3                          ! r3 = master_flags value
    and r3, r5                             ! r5 = flags & 0x00020000 (sound bit)
    tst r5, r5                             ! sound enabled?
    bt      .L_cleanup_exit                ! no -> skip sound, exit
    ! --- Play collision sound ---
    mov.l   _pool_collision_sound_id, r5   ! r5 = 0xAE111BFF (collision sound ID)
    mov.l   _pool_fn_sound_cmd, r3         ! r3 = &sound_cmd_dispatch
    jsr @r3                                ! sound_cmd_dispatch(channel=0, id=0xAE111BFF)
    mov #0x0, r4                           ! r4 = 0 (sound channel 0) [delay]
    bra     .L_cleanup_exit                ! -> cleanup and return
    nop                                    ! [delay]
_wpool_off_force_timer:
    .2byte  0x00B8

    .global DAT_060082ac
DAT_060082ac:
    .2byte  0x01DC
_wpool_off_force_applied:
    .2byte  0x01D8
_wpool_speed_decay_const:
    .2byte  0x00E3

    .global DAT_060082b2
DAT_060082b2:
    .2byte  0x00BC
_pool_car_array_base:
    .4byte  sym_0607E944
_pool_force_timer_reset:
    .4byte  sym_0607EBD4
_pool_gas_force_table:
    .4byte  sym_0604540C
_pool_brake_force_table:
    .4byte  sym_0604546C
_pool_master_flags:
    .4byte  sym_0607EBC4
_pool_sound_enable_mask:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
_pool_collision_sound_id:
    .4byte  0xAE111BFF
_pool_fn_sound_cmd:
    .4byte  sound_cmd_dispatch
.L_check_brake_flag:
    mov.l @r14, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x20, r0
    bt      .L_cleanup_exit
    mov.l @r14, r3
    mov #0x1, r2
    .byte   0x90, 0x39    /* mov.w .L_wpool_06008358, r0 */
    mov.l r4, @(r0, r3)
    mov.l @r14, r3
    .byte   0x90, 0x37    /* mov.w .L_wpool_0600835A, r0 */
    mov.l r2, @(r0, r3)
    mov.l @r6, r3
    and r3, r5
    tst r5, r5
    bt      .L_cleanup_exit
    .byte   0xD5, 0x1B    /* mov.l .L_pool_06008364, r5 */
    .byte   0xD3, 0x1C    /* mov.l .L_pool_06008368, r3 */
    jsr @r3
    mov #0x0, r4
.L_cleanup_exit:
    mov #0x0, r4
    mov.l @r14, r2
    .byte   0x91, 0x2C    /* mov.w .L_wpool_0600835C, r1 */
    .byte   0xD3, 0x1A    /* mov.l .L_pool_0600836C, r3 */
    jsr @r3
    mov r4, r0
    mov.l @r14, r2
    .byte   0x91, 0x28    /* mov.w .L_wpool_0600835E, r1 */
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600836C, r3 */
    jsr @r3
    mov r4, r0
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
