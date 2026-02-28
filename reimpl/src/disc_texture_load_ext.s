/* disc_texture_load_ext -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601B7F4 - 0x0601BA50
 *
 * Disc texture loading — extended asset pipeline.
 *
 * Called from disc_error_handler's parent TU after a disc load completes.
 * Copies texture scroll parameters from ROM tables into RAM work area,
 * then iterates over 3 car slots (r13=3) to issue texture DMA transfers.
 *
 * Flow:
 *   1. Copy 4 parameter blocks from ROM (sym_0605DFxx) into stack locals
 *      using memcpy_byte and memcpy_long helpers.
 *   2. Read CD status flags (g_pad_state+2) to decide scroll direction:
 *      - Bit 14 set: decrement scroll parameter at [disc_type + scroll_base]
 *      - Bit 15 set: increment scroll parameter, wrapping at max
 *   3. Loop 1 (slots 0x30..0x32): For each car slot, compute a VDP1
 *      texture VRAM offset from the car's object table (sym_06063750)
 *      and call the display list loader (sym_06028400) with DMA mode 8.
 *   4. Loop 2 (slots 0x33..0x35): Same as loop 1 but uses scroll_param_b
 *      (sym_0605D4F5) and a different stack-local pointer (+0x21).
 *
 * Key symbols:
 *   sym_06063750  — car object table base (per-car struct array)
 *   g_pad_state  — CD block status / texture scroll flags (word at +2)
 *   sym_0608600E  — disc type flag (byte): 2 = game disc
 *   sym_0605D4F4  — scroll parameter A (byte, per-slot index)
 *   sym_0605D4F5  — scroll parameter B (byte, per-slot index)
 *   sym_0605D4F8  — texture load state flags (word)
 *   sym_06028400  — display list loader / texture DMA dispatch
 *   sym_06035228  — memcpy_byte(r0=count, r1=dst, r2=src)
 *   sym_06035168  — memcpy_long(r0=count, r1=dst, r2=src)
 *   rigid_body_transform — coordinate transform for texture placement
 */

    .section .text.FUN_0601B7F4


    .global disc_texture_load_ext
    .type disc_texture_load_ext, @function
disc_texture_load_ext:
    mov.l r14, @-r15                        ! save r14
    mov #0x4, r14                           ! r14 = default frame count (4)
    mov.l r13, @-r15                        ! save r13
    mov #0x3, r13                           ! r13 = num car slots per group (3)
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov #0x8, r11                           ! r11 = DMA-active bitmask (bit 3)
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save return address
    add #-0x24, r15                         ! allocate 0x24 bytes of stack locals
    mov.l   .L_car_obj_table, r8            ! r8 = car object table base (persists)
    mov r15, r10                            ! r10 = sp (base for param buffer)
    mov r15, r1                             ! r1 = sp (dst pointer for copy)
    mov.l   .L_tex_param_src_a, r2          ! r2 = src: texture param table A
    mov.l   .L_fn_memcpy_byte, r3           ! r3 = memcpy_byte
    add #0x10, r10                          ! r10 = &locals[0x10] (param buffer C)
    add #0x20, r1                           ! dst = &locals[0x20]
    jsr @r3                                 ! memcpy_byte(2, sp+0x20, src_a)
    mov #0x2, r0                            ! count = 2 bytes (delay slot)
    mov r15, r1                             ! r1 = sp
    mov.l   .L_tex_param_src_b, r2          ! r2 = src: texture param table B
    mov.l   .L_fn_memcpy_long, r3           ! r3 = memcpy_long
    add #0x14, r1                           ! dst = &locals[0x14]
    jsr @r3                                 ! memcpy_long(0xC, sp+0x14, src_b)
    mov #0xC, r0                            ! count = 0xC bytes (delay slot)
    mov r15, r1                             ! r1 = sp
    mov.l   .L_tex_param_src_c, r2          ! r2 = src: texture param table C
    mov.l   .L_fn_memcpy_byte, r3           ! r3 = memcpy_byte
    add #0x10, r1                           ! dst = &locals[0x10]
    jsr @r3                                 ! memcpy_byte(3, sp+0x10, src_c)
    mov r13, r0                             ! count = 3 bytes (delay slot)
    mov r15, r5                             ! r5 = sp
    mov r15, r1                             ! r1 = sp
    mov.l   .L_tex_param_src_d, r2          ! r2 = src: texture param table D
    mov.l   .L_fn_memcpy_byte, r3           ! r3 = memcpy_byte
    add #0xC, r5                            ! r5 = &locals[0x0C] (max count table)
    add #0xC, r1                            ! dst = &locals[0x0C]
    jsr @r3                                 ! memcpy_byte(3, sp+0x0C, src_d)
    mov r13, r0                             ! count = 3 bytes (delay slot)
    mov.l   .L_cd_status_base, r6           ! r6 = &cd_status struct
    mov.l   .L_disc_type_flag, r4           ! r4 = &disc_type_flag
    mov.w   DAT_0601b87e, r3               ! r3 = 0x4000 (bit 14 mask)
    mov.w @(2, r6), r0                      ! r0 = cd_status[+2] (scroll flags word)
    mov r0, r2                              ! r2 = flags copy
    extu.w r2, r2                           ! zero-extend to 32 bits
    and r3, r2                              ! isolate bit 14 (scroll-down flag)
    tst r2, r2                              ! bit 14 set?
    bt      .L_check_scroll_up              ! bit 14 clear -> check bit 15
    mov.b @r4, r3                           ! r3 = disc_type index
    mov.l   .L_scroll_param_a, r2           ! r2 = scroll_param_a base
    add r2, r3                              ! r3 = &scroll_param_a[disc_type]
    mov.b @r3, r1                           ! r1 = current scroll value
    add #-0x1, r1                           ! decrement scroll
    mov.b r1, @r3                           ! store decremented value
    exts.b r1, r1                           ! sign-extend for comparison
    cmp/pz r1                               ! scroll >= 0?
    bt      .L_scroll_done                  ! yes -> done
    mov.b @r4, r6                           ! underflow: r6 = disc_type
    mov.l   .L_scroll_param_a, r2           ! r2 = scroll_param_a base
    add r6, r2                              ! r2 = &scroll_param_a[disc_type]
    add r6, r5                              ! r5 = &max_count[disc_type]
    mov.b @r5, r3                           ! r3 = max count for this slot
    add #-0x1, r3                           ! wrap to max - 1
    exts.b r3, r3                           ! sign-extend
    mov.b r3, @r2                           ! store wrapped value
    bra     .L_scroll_done                  ! done
    nop                                     ! (delay slot)

    .global DAT_0601b87e
DAT_0601b87e:
    .2byte  0x4000                          /* bit 14 mask -- scroll-down flag */
.L_car_obj_table:
    .4byte  sym_06063750
.L_tex_param_src_a:
    .4byte  sym_0605DF26
.L_fn_memcpy_byte:
    .4byte  sym_06035228
.L_tex_param_src_b:
    .4byte  sym_0605DF28
.L_fn_memcpy_long:
    .4byte  sym_06035168
.L_tex_param_src_c:
    .4byte  sym_0605DF34
.L_tex_param_src_d:
    .4byte  sym_0605DF37
.L_cd_status_base:
    .4byte  g_pad_state
.L_disc_type_flag:
    .4byte  sym_0608600E
.L_scroll_param_a:
    .4byte  sym_0605D4F4
.L_check_scroll_up:                         ! --- bit 14 was clear, try bit 15 ---
    mov.w @(2, r6), r0                      ! re-read cd_status[+2]
    mov.l   .L_fp_half, r3                  ! r3 = 0x8000 (bit 15 mask)
    mov r0, r2                              ! r2 = flags copy
    extu.w r2, r2                           ! zero-extend
    and r3, r2                              ! isolate bit 15 (scroll-up flag)
    tst r2, r2                              ! bit 15 set?
    bt      .L_scroll_done                  ! bit 15 clear -> no scroll change
    mov.b @r4, r3                           ! r3 = disc_type index
    mov.l   .L_scroll_param_a_2, r2         ! r2 = scroll_param_a base
    add r2, r3                              ! r3 = &scroll_param_a[disc_type]
    mov.b @r3, r1                           ! r1 = current scroll value
    add #0x1, r1                            ! increment scroll
    mov.b r1, @r3                           ! store incremented value
    exts.b r1, r1                           ! sign-extend for comparison
    mov.b @r4, r0                           ! r0 = disc_type index
    mov.b @(r0, r5), r3                     ! r3 = max_count[disc_type]
    cmp/ge r3, r1                           ! scroll >= max?
    bf      .L_scroll_done                  ! no -> done
    mov.b @r4, r3                           ! overflow: r3 = disc_type
    mov.l   .L_scroll_param_a_2, r2         ! r2 = scroll_param_a base
    add r2, r3                              ! r3 = &scroll_param_a[disc_type]
    mov #0x0, r1                            ! r1 = 0
    mov.b r1, @r3                           ! reset scroll to 0
.L_scroll_done:                             ! --- scroll update complete ---
    mov #0x0, r12                           ! r12 = loop counter = 0
    mov.l   .L_scroll_param_a_2, r3         ! r3 = &scroll_param_a
    mov.l r3, @r15                          ! sp[0x00] = &scroll_param_a
    mov r15, r3                             ! r3 = sp
    add #0x20, r3                           ! r3 = &locals[0x20]
    mov.l r3, @(8, r15)                     ! sp[0x08] = &locals[0x20] (tex index ptr A)
.L_loop1_top:                               ! --- loop 1: car slots 0x30..0x32 ---
    extu.b r12, r2                          ! r2 = current slot index (0..2)
    mov.l @r15, r3                          ! r3 = &scroll_param_a
    mov.b @r3, r3                           ! r3 = active scroll slot index
    cmp/eq r2, r3                           ! is this the active slot?
    bf      .L_loop1_not_active             ! no -> use default frame count
    bra     .L_loop1_setup_dma              ! yes -> use frame = 1
    mov #0x1, r9                            ! r9 = 1 (active slot frame count)
.L_loop1_not_active:
    extu.b r14, r9                          ! r9 = 4 (default frame count)
.L_loop1_setup_dma:                         ! --- compute DMA params for this slot ---
    extu.b r12, r2                          ! r2 = slot index
    extu.b r9, r9                           ! r9 = frame count (clean)
    extu.b r12, r4                          ! r4 = slot index (for struct offset)
    mov.l r2, @(4, r15)                     ! sp[0x04] = slot index (save for later)
    shll2 r4                                ! r4 = slot_idx * 4
    add r9, r2                              ! r2 = slot_idx + frame_count
    mov.w   .L_slot_base_offset, r3         ! r3 = 0x100 (VRAM slot base offset)
    add r3, r2                              ! r2 = slot_idx + frame + 0x100
    mov.l r2, @-r15                         ! push texture ID arg
    mov.l   .L_fp_one, r2                   ! r2 = 1.0 (16.16 fixed-point)
    mov.l r2, @-r15                         ! push scale arg
    mov.l   .L_fp_half, r3                  ! r3 = 0.5 (16.16 fixed-point)
    mov.l r3, @-r15                         ! push half-scale arg
    mov.l   .L_fp_x_offset, r7             ! r7 = 0x1C0000 (X offset, 16.16 FP)
    mov r15, r3                             ! r3 = sp (after 3 pushes)
    mov.l   .L_fn_rigid_body_transform, r2  ! r2 = rigid_body_transform
    mov.l   .L_fp_y_offset, r6             ! r6 = 0x2F0000 (Y offset, 16.16 FP)
    mov.l   .L_fp_z_offset, r5             ! r5 = 0xFFD40000 (Z offset, signed 16.16)
    add #0x20, r3                           ! r3 = sp + 0x20 (locals base from pre-push)
    add r3, r4                              ! r4 = &locals[slot_idx*4] (obj struct ptr)
    jsr @r2                                 ! rigid_body_transform(...)
    mov.l @r4, r4                           ! r4 = locals[slot_idx*4] (delay slot)
    add #0xC, r15                           ! pop 3 pushed args
    mov.l @r15, r3                          ! r3 = &scroll_param_a (sp[0x00])
    mov.l @(4, r15), r2                     ! r2 = saved slot index (sp[0x04])
    mov.b @r3, r3                           ! r3 = active scroll slot
    cmp/eq r2, r3                           ! still the active slot after transform?
    bf      .L_loop1_skip_check             ! no -> skip flag check
    mov.l   .L_tex_load_flags, r2           ! r2 = &tex_load_flags
    mov.w @r2, r2                           ! r2 = tex_load_flags (word)
    extu.w r2, r2                           ! zero-extend
    and r11, r2                             ! isolate bit 3 (DMA active)
    tst r2, r2                              ! DMA active?
    bf      .L_loop1_use_3_slots            ! yes -> use 3 slots
    mov.l   .L_disc_type_flag_2, r3         ! r3 = &disc_type_flag
    mov.b @r3, r3                           ! r3 = disc_type
    tst r3, r3                              ! disc_type == 0?
    bt      .L_loop1_use_4_slots            ! yes -> use 4 slots
.L_loop1_use_3_slots:
    bra     .L_loop1_compute_vram           ! use r13 (3) as slot count
    extu.b r13, r9                          ! r9 = 3 (delay slot)
.L_loop1_use_4_slots:
    bra     .L_loop1_compute_vram           ! use r14 (4) as slot count
    extu.b r14, r9                          ! r9 = 4 (delay slot)
.L_slot_base_offset:
    .2byte  0x0100
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_scroll_param_a_2:
    .4byte  sym_0605D4F4
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fp_x_offset:
    .4byte  0x001C0000
.L_fp_y_offset:
    .4byte  0x002F0000
.L_fp_z_offset:
    .4byte  0xFFD40000
.L_fn_rigid_body_transform:
    .4byte  rigid_body_transform
.L_tex_load_flags:
    .4byte  sym_0605D4F8
.L_disc_type_flag_2:
    .4byte  sym_0608600E
.L_loop1_skip_check:                        ! --- not active slot: default frame ---
    extu.b r14, r9                          ! r9 = 4 (default frame count)
.L_loop1_compute_vram:                      ! --- compute VRAM addr and issue DMA ---
    extu.b r9, r7                           ! r7 = frame count (clean byte)
    extu.b r12, r2                          ! r2 = slot index
    extu.b r12, r0                          ! r0 = slot index (for param lookup)
    shll8 r7                                ! r7 <<= 8 (frame * 0x100)
    add #0x30, r2                           ! r2 = slot_idx + 0x30 (slot ID for group 1)
    shll2 r7                                ! r7 <<= 2 (frame * 0x400)
    mov r2, r3                              ! r3 = slot ID
    shll2 r7                                ! r7 <<= 2 (frame * 0x1000)
    shll2 r3                                ! r3 = slot_ID * 4
    shll r3                                 ! r3 = slot_ID * 8 (struct stride)
    mov r3, r2                              ! r2 = struct offset
    add r8, r2                              ! r2 = &car_obj_table[slot_ID]
    mov.l r2, @(4, r15)                     ! sp[0x04] = &car_obj[slot_ID]
    mov.l @(4, r2), r3                      ! r3 = car_obj[slot_ID].vram_base
    mov.b @(r0, r10), r6                    ! r6 = param_buf_c[slot_idx]
    mov.l @(4, r15), r5                     ! r5 = &car_obj[slot_ID]
    add r3, r7                              ! r7 = vram_base + frame_offset
    extu.b r6, r6                           ! zero-extend param byte
    mov.l @r5, r5                           ! r5 = car_obj[slot_ID].tex_src_addr
    mov.l @(8, r15), r3                     ! r3 = &locals[0x20] (tex index ptr A)
    mov.b @r3, r3                           ! r3 = tex_index_a
    extu.b r3, r2                           ! r2 = tex_index (clean byte)
    shll2 r2                                ! r2 <<= 2
    mov.l   .L_fn_dlist_loader, r3          ! r3 = display list loader function
    shll2 r2                                ! r2 <<= 2
    shll2 r2                                ! r2 <<= 2 (total: * 64)
    add r2, r6                              ! r6 = param + tex_index * 64
    shll r6                                 ! r6 <<= 1 (word offset -> byte offset)
    jsr @r3                                 ! dlist_loader(r4=8, r5=src, r6=offset, r7=dst)
    mov #0x8, r4                            ! r4 = DMA mode 8 (delay slot)
    add #0x1, r12                           ! r12++ (next slot)
    extu.b r12, r2                          ! r2 = slot counter (clean)
    cmp/ge r13, r2                          ! done all 3 slots?
    bf      .L_loop1_top                    ! no -> next iteration
    mov #0x0, r12                           ! r12 = 0 (reset for loop 2)
    mov.l   .L_scroll_param_b, r2           ! r2 = &scroll_param_b
    mov.l r2, @(8, r15)                     ! sp[0x08] = &scroll_param_b
    mov r15, r3                             ! r3 = sp
    add #0x21, r3                           ! r3 = &locals[0x21] (tex index ptr B)
    mov.l r3, @r15                          ! sp[0x00] = &locals[0x21]
.L_loop2_top:                               ! --- loop 2: car slots 0x33..0x35 ---
    extu.b r12, r2                          ! r2 = current slot index (0..2)
    mov.l @(8, r15), r3                     ! r3 = &scroll_param_b
    mov.b @r3, r3                           ! r3 = active scroll slot for group B
    cmp/eq r2, r3                           ! is this the active slot?
    bf      .L_loop2_skip_check             ! no -> use default
    mov.l   .L_tex_load_flags_2, r2         ! r2 = &tex_load_flags
    mov.w @r2, r2                           ! r2 = tex_load_flags (word)
    extu.w r2, r2                           ! zero-extend
    and r11, r2                             ! isolate bit 3 (DMA active)
    tst r2, r2                              ! DMA active?
    bf      .L_loop2_use_3_slots            ! yes -> use 3 slots
    mov.l   .L_disc_type_flag_3, r0         ! r0 = &disc_type_flag
    mov.b @r0, r0                           ! r0 = disc_type
    cmp/eq #0x1, r0                         ! disc_type == 1?
    bt      .L_loop2_use_4_slots            ! yes -> use 4 slots
.L_loop2_use_3_slots:
    bra     .L_loop2_compute_vram           ! use r13 (3) as slot count
    extu.b r13, r9                          ! r9 = 3 (delay slot)
.L_loop2_use_4_slots:
    bra     .L_loop2_compute_vram           ! use r14 (4) as slot count
    extu.b r14, r9                          ! r9 = 4 (delay slot)
.L_loop2_skip_check:                        ! --- not active slot: default frame ---
    extu.b r14, r9                          ! r9 = 4 (default frame count)
.L_loop2_compute_vram:                      ! --- compute VRAM addr and issue DMA ---
    extu.b r9, r7                           ! r7 = frame count (clean byte)
    extu.b r12, r2                          ! r2 = slot index
    extu.b r12, r0                          ! r0 = slot index (for param lookup)
    shll8 r7                                ! r7 <<= 8 (frame * 0x100)
    add #0x33, r2                           ! r2 = slot_idx + 0x33 (slot ID for group 2)
    shll2 r7                                ! r7 <<= 2 (frame * 0x400)
    mov r2, r3                              ! r3 = slot ID
    shll2 r7                                ! r7 <<= 2 (frame * 0x1000)
    shll2 r3                                ! r3 = slot_ID * 4
    shll r3                                 ! r3 = slot_ID * 8 (struct stride)
    mov r3, r2                              ! r2 = struct offset
    add r8, r2                              ! r2 = &car_obj_table[slot_ID]
    mov.l r2, @(4, r15)                     ! sp[0x04] = &car_obj[slot_ID]
    mov.l @(4, r2), r3                      ! r3 = car_obj[slot_ID].vram_base
    mov.b @(r0, r10), r6                    ! r6 = param_buf_c[slot_idx]
    mov.l @(4, r15), r5                     ! r5 = &car_obj[slot_ID]
    add r3, r7                              ! r7 = vram_base + frame_offset
    extu.b r6, r6                           ! zero-extend param byte
    mov.l @r5, r5                           ! r5 = car_obj[slot_ID].tex_src_addr
    mov.l @r15, r3                          ! r3 = &locals[0x21] (tex index ptr B)
    mov.b @r3, r3                           ! r3 = tex_index_b
    extu.b r3, r2                           ! r2 = tex_index (clean byte)
    shll2 r2                                ! r2 <<= 2
    mov.l   .L_fn_dlist_loader, r3          ! r3 = display list loader function
    shll2 r2                                ! r2 <<= 2
    shll2 r2                                ! r2 <<= 2 (total: * 64)
    add r2, r6                              ! r6 = param + tex_index * 64
    shll r6                                 ! r6 <<= 1 (word offset -> byte offset)
    jsr @r3                                 ! dlist_loader(r4=8, r5=src, r6=offset, r7=dst)
    mov #0x8, r4                            ! r4 = DMA mode 8 (delay slot)
    add #0x1, r12                           ! r12++ (next slot)
    extu.b r12, r2                          ! r2 = slot counter (clean)
    cmp/ge r13, r2                          ! done all 3 slots?
    bf      .L_loop2_top                    ! no -> next iteration
    add #0x24, r15                          ! deallocate stack locals
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)
    .2byte  0xFFFF
.L_fn_dlist_loader:
    .4byte  sym_06028400
.L_scroll_param_b:
    .4byte  sym_0605D4F5
.L_tex_load_flags_2:
    .4byte  sym_0605D4F8
.L_disc_type_flag_3:
    .4byte  sym_0608600E
