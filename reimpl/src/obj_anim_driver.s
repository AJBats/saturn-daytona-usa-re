/* obj_anim_driver -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060209AC - 0x06020B58
 *
 * Object animation driver — advances VDP2 rotation-scroll coefficient
 * tables for animated background/scenery objects each frame.
 *
 * On first call (init_once_flag == 0): triggers a sound command
 * (0xAB1129FF) via sound_cmd_dispatch and sets the one-shot flag.
 *
 * Each frame:
 *   1. Programs VDP2 coefficient table base register (reg +0x0A4)
 *      and scroll mode register (reg +0x09A).
 *   2. Increments the anim_frame_counter word at sym_06087828.
 *   3. Loops 0x100 iterations: for each index, calls mem_store_helper
 *      (sym_06035C2C) to compute a coefficient value, multiplies by
 *      the frame counter, and writes the result to VDP2 VRAM +0x5F800.
 *   4. Once frame_counter >= 10 and race_state / demo / display flags
 *      are all set: copies three display-list segments via
 *      display_list_copy (sym_06028400) from the course object table
 *      (sym_06063750) at offsets 0x568, 0x570, 0x578.
 *   5. BSR to obj_lod_level, clears init flag, restores caller arg,
 *      and tail-jumps to obj_anim_clear (0x06020DEE).
 *
 * The raw .4byte block at the end (0x06020B20-0x06020B58) is an
 * inlined helper — display_list_copy_inline — that copies word-sized
 * entries from a source list into VDP2 VRAM command slots. Its own
 * constant pool is embedded in the trailing bytes.
 */

    .section .text.FUN_060209AC


    .global obj_anim_driver
    .type obj_anim_driver, @function
obj_anim_driver:
    mov.l r14, @-r15             ! save r14
    mov r4, r0                   ! r0 = caller arg (obj index)
    mov.l r13, @-r15             ! save r13
    mov.l r12, @-r15             ! save r12
    mov.l r11, @-r15             ! save r11
    mov.l r10, @-r15             ! save r10
    mov.l r9, @-r15              ! save r9
    mov.l r8, @-r15              ! save r8
    sts.l pr, @-r15              ! save pr (return address)
    sts.l macl, @-r15            ! save macl (multiply accumulator)
    add #-0x8, r15               ! allocate 8 bytes on stack
    mov.l   .L_p_init_once_flag, r9  ! r9 = &init_once_flag (sym_0605F586)
    mov.w   .L_w_loop_count, r13     ! r13 = 0x100 (loop iteration count)
    mov.l   .L_p_anim_frame_counter, r14 ! r14 = &anim_frame_counter (sym_06087828)
    mov.b r0, @(4, r15)         ! stack[4] = obj index (preserve arg)
    mov.l   .L_wram_low, r12    ! r12 = 0x00200000 (Work RAM Low base)
    mov.b @r9, r3               ! r3 = init_once_flag
    extu.b r3, r3               ! zero-extend flag byte
    tst r3, r3                  ! test if flag == 0
    bf      .L_init_done        ! if already initialized, skip sound
    mov.l   .L_p_sound_id, r5   ! r5 = 0xAB1129FF (sound ID)
    mov.l   .L_p_sound_cmd_dispatch, r3 ! r3 = &sound_cmd_dispatch
    jsr @r3                     ! call sound_cmd_dispatch(r4=0, r5=sound_id)
    mov #0x0, r4                ! r4 = 0 (delay slot: channel 0)
    mov #0x1, r2                ! r2 = 1
    mov.b r2, @r9               ! init_once_flag = 1 (mark initialized)
.L_init_done:
    mov.l   .L_p_coeff_table_base, r3  ! r3 = 0x12F2FC00 (coeff table base addr)
    mov.l   .L_vdp2_reg_0x0A4, r2     ! r2 = 0x25F800A4 (VDP2 KTCTL reg)
    mov.l r3, @r2               ! VDP2[0x0A4] = coeff table base
    mov.w   .L_w_scroll_mode, r3 ! r3 = 0x0200 (scroll mode bits)
    add #-0xA, r2               ! r2 = 0x25F8009A (VDP2 RPMD reg)
    mov.w r3, @r2               ! VDP2[0x09A] = 0x0200 (rotation mode)
    mov.w @r14, r3              ! r3 = anim_frame_counter (current)
    add #0x1, r3                ! r3++ (advance frame)
    mov.w r3, @r14              ! store updated frame counter
    mov.l   .L_vdp2_vram_0x5F800, r5 ! r5 = 0x25E5F800 (VDP2 VRAM dest base)
    mov #0x0, r4                ! r4 = 0 (loop index)
.L_coeff_loop:
    extu.w r4, r0               ! r0 = index (zero-extended word)
    extu.w r4, r1               ! r1 = index (for mem_store_helper arg)
    mov.l   .L_p_mem_store_helper, r3 ! r3 = &mem_store_helper (sym_06035C2C)
    shll2 r0                    ! r0 = index * 4 (byte offset)
    mov r0, r8                  ! r8 = byte offset
    add r5, r8                  ! r8 = VRAM dest + offset (write target)
    jsr @r3                     ! call mem_store_helper(r0=2, r1=index)
    mov #0x2, r0                ! r0 = 2 (delay slot: function selector)
    tst r0, r0                  ! test return value (r0)
    bt      .L_use_neg_scale    ! if r0 == 0: use negative scale factor
    bra     .L_store_coeff      ! else: use WRAM Low as scale
    mov r12, r3                 ! r3 = 0x00200000 (delay slot: WRAM Low)
.L_w_loop_count:
    .2byte  0x0100                      /* 256 coefficient entries */
.L_w_scroll_mode:
    .2byte  0x0200                      /* VDP2 rotation scroll mode */
    .2byte  0xFFFF                      /* pool alignment padding */
.L_p_init_once_flag:
    .4byte  sym_0605F586                /* &init_once_flag (byte) */
.L_p_anim_frame_counter:
    .4byte  sym_06087828                /* &anim_frame_counter (word) */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_p_sound_id:
    .4byte  0xAB1129FF                  /* sound command ID */
.L_p_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch          /* sound command dispatch function */
.L_p_coeff_table_base:
    .4byte  0x12F2FC00                  /* VDP2 coefficient table base value */
.L_vdp2_reg_0x0A4:
    .4byte  0x25F800A4                  /* VDP2 KTCTL register (+0x0A4) */
.L_vdp2_vram_0x5F800:
    .4byte  0x25E5F800                  /* VDP2 VRAM +0x5F800 (coeff dest) */
.L_p_mem_store_helper:
    .4byte  sym_06035C2C                /* mem_store_helper function */
.L_use_neg_scale:
    mov.l   .L_p_neg_scale, r3  ! r3 = 0xFFE00000 (negative scale factor)
.L_store_coeff:
    add #0x1, r4                ! index++
    mov.w @r14, r1              ! r1 = anim_frame_counter
    extu.w r1, r1               ! zero-extend to 32-bit
    mul.l r1, r3                ! macl = frame_counter * scale_factor
    sts macl, r3                ! r3 = multiplication result
    mov.l r3, @r8               ! VRAM[dest + index*4] = coefficient
    extu.w r4, r3               ! r3 = index (zero-extended)
    cmp/ge r13, r3              ! test index >= 0x100
    bf      .L_coeff_loop       ! loop until all 256 entries written
    mov #0xA, r2                ! r2 = 10 (frame threshold)
    mov.w @r14, r3              ! r3 = anim_frame_counter
    extu.w r3, r3               ! zero-extend
    cmp/ge r2, r3               ! test frame_counter >= 10
    bf      .L_early_exit       ! if < 10 frames: skip display list copy
    mov.l   .L_p_race_state, r0 ! r0 = &race_state (sym_0605AD04)
    mov.l @r0, r0               ! r0 = race_state value
    cmp/eq #0x4, r0             ! test race_state == 4 (racing)
    .word 0x0029 /* movt r0 */  ! r0 = T (1 if racing, 0 otherwise)
    mov.l   .L_p_demo_flag, r3  ! r3 = &demo_flag (sym_06078637)
    mov.b @r3, r3               ! r3 = demo_flag byte
    tst r3, r3                  ! test demo_flag == 0
    .word 0x0129 /* movt r1 */  ! r1 = T (1 if not demo, 0 if demo)
    and r1, r0                  ! r0 = racing & not_demo
    mov.l   .L_p_anim_state_b, r3 ! r3 = &anim_state_b (sym_06087824)
    mov.l   .L_p_display_flags, r2 ! r2 = &display_flags (sym_06085FF4)
    mov.b @r3, r3               ! r3 = anim_state_b byte
    mov.b @r2, r2               ! r2 = display_flags byte
    and r3, r0                  ! r0 &= anim_state_b
    and r2, r0                  ! r0 &= display_flags
    tst r0, r0                  ! test combined condition == 0
    bt      .L_skip_list_copy   ! if all flags not set: skip list copy
    mov.w   .L_w_vram_offset, r10 ! r10 = 0x3000 (VRAM dest offset)
    mov.l   .L_p_course_obj_table, r11 ! r11 = &course_obj_table (sym_06063750)
    mov.l   .L_p_display_list_copy, r12 ! r12 = &display_list_copy (sym_06028400)
    /* --- Copy segment A (offset 0x568, size 0x498) --- */
    mov.w   .L_w_list_offset_a, r7 ! r7 = 0x568 (struct offset A)
    add r11, r7                 ! r7 = &course_obj_table + 0x568
    mov.l r7, @r15              ! stack[0] = struct entry ptr
    mov.l @(4, r7), r7          ! r7 = struct[0x568].field4 (src base)
    mov.w   .L_w_size_a, r6     ! r6 = 0x498 (copy size A)
    mov.l @r15, r5              ! r5 = struct entry ptr
    add r10, r7                 ! r7 = src base + 0x3000 (VRAM offset)
    mov.l @r5, r5               ! r5 = struct[0x568].field0 (src ptr)
    jsr @r12                    ! call display_list_copy(r4=8, r5, r6, r7)
    mov #0x8, r4                ! r4 = 8 (delay slot: copy mode)
    /* --- Copy segment B (offset 0x570, size 0x69C) --- */
    mov.w   .L_w_list_offset_b, r7 ! r7 = 0x570 (struct offset B)
    add r11, r7                 ! r7 = &course_obj_table + 0x570
    mov.l r7, @r15              ! stack[0] = struct entry ptr
    mov.l @(4, r7), r7          ! r7 = struct[0x570].field4 (src base)
    mov.w   .L_w_size_b, r6     ! r6 = 0x69C (copy size B)
    mov.l @r15, r5              ! r5 = struct entry ptr
    add r10, r7                 ! r7 = src base + 0x3000
    mov.l @r5, r5               ! r5 = struct[0x570].field0 (src ptr)
    jsr @r12                    ! call display_list_copy(r4=8, r5, r6, r7)
    mov #0x8, r4                ! r4 = 8 (delay slot: copy mode)
    /* --- Copy segment C (offset 0x578, size 0xB1E) --- */
    mov.w   .L_w_list_offset_c, r7 ! r7 = 0x578 (struct offset C)
    add r11, r7                 ! r7 = &course_obj_table + 0x578
    mov.l r7, @r15              ! stack[0] = struct entry ptr
    mov.l @(4, r7), r7          ! r7 = struct[0x578].field4 (src base)
    mov.w   .L_w_size_c, r6     ! r6 = 0xB1E (copy size C)
    mov.l @r15, r5              ! r5 = struct entry ptr
    add r10, r7                 ! r7 = src base + 0x3000
    mov.l @r5, r5               ! r5 = struct[0x578].field0 (src ptr)
    jsr @r12                    ! call display_list_copy(r4=8, r5, r6, r7)
    mov #0x8, r4                ! r4 = 8 (delay slot: copy mode)
.L_skip_list_copy:
    .byte   0xBF, 0x44    /* bsr obj_lod_level (0x06020946) */
    nop                         ! delay slot (no-op)
    mov #0x0, r2                ! r2 = 0
    mov.b r2, @r9               ! init_once_flag = 0 (reset for next call)
    mov.b @(4, r15), r0         ! r0 = saved obj index from stack
    mov r0, r4                  ! r4 = obj index (restore arg)
    extu.b r4, r4               ! zero-extend obj index
    add #0x8, r15               ! deallocate stack frame
    lds.l @r15+, macl           ! restore macl
    lds.l @r15+, pr             ! restore pr
    mov.l @r15+, r8             ! restore r8
    mov.l @r15+, r9             ! restore r9
    mov.l @r15+, r10            ! restore r10
    mov.l @r15+, r11            ! restore r11
    mov.l @r15+, r12            ! restore r12
    mov.l @r15+, r13            ! restore r13
    .byte   0xA1, 0x88    /* bra obj_anim_clear (0x06020DEE) — tail-jump */
    mov.l @r15+, r14            ! restore r14 (delay slot)
.L_early_exit:
    add #0x8, r15               ! deallocate stack frame
    lds.l @r15+, macl           ! restore macl
    lds.l @r15+, pr             ! restore pr
    mov.l @r15+, r8             ! restore r8
    mov.l @r15+, r9             ! restore r9
    mov.l @r15+, r10            ! restore r10
    mov.l @r15+, r11            ! restore r11
    mov.l @r15+, r12            ! restore r12
    mov.l @r15+, r13            ! restore r13
    rts                         ! return (frame_counter < 10 path)
    mov.l @r15+, r14            ! restore r14 (delay slot)
.L_w_vram_offset:
    .2byte  0x3000                      /* VRAM destination offset */
.L_w_list_offset_a:
    .2byte  0x0568                      /* course struct offset A */
.L_w_size_a:
    .2byte  0x0498                      /* copy size A (bytes) */
.L_w_list_offset_b:
    .2byte  0x0570                      /* course struct offset B */
.L_w_size_b:
    .2byte  0x069C                      /* copy size B (bytes) */
.L_w_list_offset_c:
    .2byte  0x0578                      /* course struct offset C */
.L_w_size_c:
    .2byte  0x0B1E                      /* copy size C (bytes) */
    .2byte  0xFFFF                      /* pool alignment padding */
.L_p_neg_scale:
    .4byte  0xFFE00000                  /* negative scale (-2M, 14.18 fixed) */
.L_p_race_state:
    .4byte  sym_0605AD04                /* &race_state variable */
.L_p_demo_flag:
    .4byte  sym_06078637                /* &demo_flag byte */
.L_p_anim_state_b:
    .4byte  sym_06087824                /* &anim_state_b byte */
.L_p_display_flags:
    .4byte  sym_06085FF4                /* &display_flags byte */
.L_p_course_obj_table:
    .4byte  sym_06063750                /* &course_obj_table base */
.L_p_display_list_copy:
    .4byte  sym_06028400                /* display_list_copy function */
    /* --- Inlined helper: display_list_copy_inline (0x06020B20-0x06020B58) ---
     * Copies word-sized palette/coefficient entries from source into
     * VDP2 VRAM. Embedded as raw bytes because it shares the pool area
     * and the L3 generator cannot split it from the parent function.
     * Its own constant pool (VDP2 VRAM addr, coeff base, KTCTL reg)
     * occupies the trailing 12 bytes.
     */
    .4byte  0x9611E500                  /* mov.w @(0x22,PC),r6 / mov #0x0,r5 */
    .4byte  0xD709D30A                  /* mov.l @(0x24,PC),r7 / mov.l @(0x28,PC),r3 */
    .4byte  0xD20A2232                  /* mov.l @(0x28,PC),r2 / mov.l r3,@r2 */
    .4byte  0x930C72F6                  /* mov.w @(0x18,PC),r3 / add #-0xA,r2 */
    .4byte  0x2231645D                  /* mov.w r3,@r2 / mov.b @r5,r4 (loop) */
    .4byte  0x604D4008                  /* extu.b r4,r0 / shll2 r0 */
    .4byte  0x7401634D                  /* add #0x1,r4 / extu.b r4,r3 */
    .4byte  0x33638FF9                  /* cmp/ge r6,r3 / bf loop */
    .4byte  0x0756000B                  /* div0s r5,r7 / rts */
    .4byte  0x00090100                  /* nop / 0x0100 (loop count) */
    .4byte  0x0200FFFF                  /* 0x0200 (scroll mode) / padding */
    .4byte  0x25E5F800                  /* VDP2 VRAM +0x5F800 */
    .4byte  0x12F2FC00                  /* coefficient table base */
    .4byte  0x25F800A4                  /* VDP2 KTCTL register (+0x0A4) */
