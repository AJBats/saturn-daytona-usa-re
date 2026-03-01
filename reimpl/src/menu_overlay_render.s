
    .section .text.FUN_060268B0


    .global menu_overlay_render
    .type menu_overlay_render, @function
menu_overlay_render:
    mov.l r14, @-r15
    exts.w r4, r4
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.w   DAT_06026922, r8
    mov.l   .L_fn_disp_cmd_write, r9
    mov.l   .L_overlay_active_flag, r10
    mov.l   .L_global_tick_counter, r11
    mov.l   .L_anim_substep, r13
    mov.l   .L_anim_phase, r14
    tst r4, r4
    bt/s    .L_run_animation
    mov #0x0, r12
    mov.w r12, @r10
    exts.w r12, r2
    mov.w r2, @r13
    mov.w r2, @r14
    mov.l   .L_anim_done_flag, r2
    mov.w r12, @r2
    bra     .L_epilogue
    mov.l r12, @r11
.L_run_animation:
    mov.l   .L_course_type, r0
    bra     .L_dispatch_course
    mov.l @r0, r0
.L_course0_handler:
    mov.w @r14, r2
    mov #0x36, r3
    cmp/ge r3, r2
    bt      .L_c0_check_last_phase
    mov.w @r14, r3
    mov.l   .L_timing_tbl_c0, r2
    mov.l @r11, r0
    shll r3
    add r2, r3
    mov.w @r3, r3
    mov r3, r1
    shll r3
    add r1, r3
    cmp/hs r3, r0
    bf      .L_c0_write_active_cmd
    mov r8, r5
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.w r12, @r13
    mov.l   .L_cmd_data_c0, r7
    mov.l   .L_mask_nibble3, r6
    jsr @r9
    mov #0xC, r4
    mov #0x1, r2
    bra     .L_c0_write_active_cmd
    mov.w r2, @r10

    .global DAT_06026922
DAT_06026922:
    .2byte  0x0C04
.L_fn_disp_cmd_write:
    .4byte  sym_060283E0              /* display command writer function */
.L_overlay_active_flag:
    .4byte  sym_0606123C              /* overlay active flag (word) */
.L_global_tick_counter:
    .4byte  sym_0607864C              /* global tick counter (dword) */
.L_anim_substep:
    .4byte  sym_0606123A              /* animation substep index (word) */
.L_anim_phase:
    .4byte  sym_06061238              /* animation phase counter (word) */
.L_anim_done_flag:
    .4byte  sym_0606123E              /* animation-done flag (word) */
.L_course_type:
    .4byte  sym_0607EAD8              /* course type selector (0/1/2) */
.L_timing_tbl_c0:
    .4byte  sym_060597B8              /* course 0 frame timing table (16-bit) */
.L_cmd_data_c0:
    .4byte  sym_06059826              /* course 0 display cmd data */
.L_mask_nibble3:
    .4byte  0x0000F000                /* VDP priority nibble mask */
.L_c0_check_last_phase:
    mov.w @r14, r0
    cmp/eq #0x36, r0
    bf      .L_c0_write_active_cmd
    mov.w @r14, r2
    mov.l   .L_timing_tbl_c0_b, r3
    mov.l   .L_global_tick_counter_b, r0
    shll r2
    mov.l @r0, r0
    add r3, r2
    mov.w @r2, r2
    mov r2, r1
    shll r2
    add r1, r2
    cmp/hs r2, r0
    bf      .L_c0_write_active_cmd
    mov r8, r5
    mov.l   .L_cmd_data_final, r7
    mov.l   .L_mask_nibble3_b, r6
    jsr @r9
    mov #0xC, r4
    exts.w r12, r3
    mov.w r3, @r14
    exts.w r12, r2
    mov.w r2, @r13
    mov #0x1, r3
    mov.l   .L_anim_done_flag_b, r2
    mov.w r3, @r2
.L_c0_write_active_cmd:
    mov.w @r10, r0
    tst r0, r0
    bt      .L_c0_clear_active
    mov r8, r5
    mov.w @r14, r7
    mov.l   .L_seq_index_tbl_c0, r3
    mov.l   .L_cmd_ptr_tbl_c0, r2
    mov.l   .L_mask_nibble3_b, r6
    add #-0x1, r7
    add r3, r7
    mov.b @r7, r7
    shll2 r7
    add r2, r7
    mov.l @r7, r7
    jsr @r9
    mov #0xC, r4
.L_c0_clear_active:
    exts.w r12, r3
    mov.w r3, @r10
    mov.w @r14, r2
    cmp/pl r2
    bt      .L_c0_enter_substep_loop
    bra     .L_check_anim_done
    nop
.L_c0_enter_substep_loop:
    bra     .L_c0_substep_iter
    nop
.L_c0_substep_check:
    mov.w @r13, r2
    mov #0x20, r3
    cmp/ge r3, r2
    bf      .L_c0_write_reg_block
    bra     .L_c0_substep_done
    nop
.L_c0_write_reg_block:
    mov.w @r13, r5
    mov.w @r14, r4
    mov.l   .L_seq_index_tbl_c0, r3
    mov.l   .L_cmd_ptr_tbl_c0, r2
    add #-0x1, r4
    add r3, r4
    mov.b @r4, r4
    shll2 r4
    add r2, r4
    bsr     vdp2_reg_block_setup
    mov.l @r4, r4
    mov.w @r13, r3
    add #0x1, r3
    mov.w r3, @r13
.L_c0_substep_iter:
    mov.w @r14, r0
    mov.l   .L_seq_index_tbl_c0, r3
    mov.l   .L_anim_step_tbl_c0, r2
    mov.w @r13, r4
    mov.w @r14, r1
    add #-0x1, r0
    add #-0x1, r1
    mov.b @(r0, r3), r0
    shll r1
    shll2 r0
    shll2 r0
    shll r0
    add r2, r0
    mov.b @(r0, r4), r4
    mov.l   .L_timing_tbl_c0_b, r0
    mov.w @(r0, r1), r3
    add r4, r3
    mov r3, r1
    shll r3
    add r1, r3
    mov.l @r11, r1
    cmp/hs r3, r1
    bf      .L_c0_substep_done
    mov r4, r0
    cmp/eq #-0x1, r0
    bf      .L_c0_substep_check
.L_c0_substep_done:
    bra     .L_check_anim_done
    nop
.L_course1_handler:
    mov.w @r14, r2
    mov #0x3A, r3
    cmp/ge r3, r2
    bt      .L_c1_check_last_phase
    mov.w @r14, r3
    mov.l   .L_timing_tbl_c1, r2
    mov.l @r11, r0
    shll r3
    add r2, r3
    mov.w @r3, r3
    mov r3, r1
    shll r3
    add r1, r3
    cmp/hs r3, r0
    bf      .L_c1_write_active_cmd
    mov r8, r5
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.w r12, @r13
    mov.l   .L_cmd_data_final, r7
    mov.l   .L_mask_nibble3_b, r6
    jsr @r9
    mov #0xC, r4
    mov #0x1, r2
    bra     .L_c1_write_active_cmd
    mov.w r2, @r10
.L_c1_check_last_phase:
    mov.w @r14, r0
    cmp/eq #0x3A, r0
    bf      .L_c1_write_active_cmd
    mov.w @r14, r2
    mov.l   .L_timing_tbl_c1, r3
    mov.l   .L_global_tick_counter_b, r0
    shll r2
    mov.l @r0, r0
    add r3, r2
    mov.w @r2, r2
    mov r2, r1
    shll r2
    add r1, r2
    cmp/hs r2, r0
    bf      .L_c1_write_active_cmd
    mov.l   .L_cmd_data_final, r7
    mov r8, r5
    mov.l   .L_mask_nibble3_b, r6
    jsr @r9
    mov #0xC, r4
    exts.w r12, r3
    mov.w r3, @r14
    exts.w r12, r2
    mov.w r2, @r13
    mov #0x1, r3
    mov.l   .L_anim_done_flag_b, r2
    mov.w r3, @r2
.L_c1_write_active_cmd:
    mov.w @r10, r0
    tst r0, r0
    bt      .L_c1_clear_active
    mov.w @r14, r7
    mov r8, r5
    mov.l   .L_seq_index_tbl_c1, r3
    mov.l   .L_cmd_ptr_tbl_c1, r2
    mov.l   .L_mask_nibble3_b, r6
    add #-0x1, r7
    add r3, r7
    mov.b @r7, r7
    shll2 r7
    add r2, r7
    mov.l @r7, r7
    jsr @r9
    mov #0xC, r4
.L_c1_clear_active:
    exts.w r12, r3
    mov.w r3, @r10
    mov.w @r14, r2
    cmp/pl r2
    bt      .L_c1_enter_substep_loop
    bra     .L_check_anim_done
    nop
.L_c1_enter_substep_loop:
    bra     .L_c1_substep_iter
    nop
.L_c1_substep_check:
    mov #0x24, r3
    mov.w @r13, r2
    cmp/ge r3, r2
    bf      .L_c1_write_reg_block
    bra     .L_c1_substep_done
    nop
.L_c1_write_reg_block:
    mov.w @r13, r5
    mov.w @r14, r4
    mov.l   .L_seq_index_tbl_c1, r3
    mov.l   .L_cmd_ptr_tbl_c1, r2
    add #-0x1, r4
    add r3, r4
    mov.b @r4, r4
    shll2 r4
    add r2, r4
    bsr     vdp2_reg_block_setup
    mov.l @r4, r4
    mov.w @r13, r3
    add #0x1, r3
    mov.w r3, @r13
.L_c1_substep_iter:
    mov.w @r14, r0
    mov.l   .L_seq_index_tbl_c1, r3
    mov.l   .L_anim_step_tbl_c1, r1
    mov.w @r13, r4
    add #-0x1, r0
    mov.b @(r0, r3), r0
    mov r0, r2
    shll2 r0
    shll2 r2
    shll2 r2
    shll r2
    add r2, r0
    exts.w r0, r0
    mov.w @r14, r2
    add r1, r0
    add #-0x1, r2
    mov.b @(r0, r4), r4
    shll r2
    mov.l   .L_timing_tbl_c1, r0
    mov.w @(r0, r2), r3
    add r4, r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l @r11, r2
    cmp/hs r3, r2
    bf      .L_c1_substep_done
    mov r4, r0
    cmp/eq #-0x1, r0
    bf      .L_c1_substep_check
.L_c1_substep_done:
    bra     .L_check_anim_done
    nop
    .2byte  0xFFFF
.L_timing_tbl_c0_b:
    .4byte  sym_060597B8              /* course 0 timing table (dup) */
.L_global_tick_counter_b:
    .4byte  sym_0607864C              /* global tick counter (dup) */
.L_cmd_data_final:
    .4byte  sym_06059826              /* final-frame display cmd data */
.L_mask_nibble3_b:
    .4byte  0x0000F000                /* VDP priority nibble mask (dup) */
.L_anim_done_flag_b:
    .4byte  sym_0606123E              /* animation-done flag (dup) */
.L_seq_index_tbl_c0:
    .4byte  sym_060591BA              /* course 0 sequence index byte table */
.L_cmd_ptr_tbl_c0:
    .4byte  sym_060611FC              /* course 0 cmd pointer table (dword) */
.L_anim_step_tbl_c0:
    .4byte  sym_060595D8              /* course 0 anim step sizes (2D byte) */
.L_timing_tbl_c1:
    .4byte  sym_060591F0              /* course 1 frame timing table (16-bit) */
.L_seq_index_tbl_c1:
    .4byte  sym_0605914C              /* course 1 sequence index byte table */
.L_cmd_ptr_tbl_c1:
    .4byte  sym_0606119C              /* course 1 cmd pointer table (dword) */
.L_anim_step_tbl_c1:
    .4byte  sym_06059266              /* course 1 anim step sizes (2D byte) */
.L_course2_handler:
    mov.w @r14, r2
    mov #0x34, r3
    cmp/ge r3, r2
    bt      .L_c2_check_last_phase
    mov.w @r14, r3
    mov.l   .L_timing_tbl_c2, r2
    mov.l @r11, r0
    shll r3
    add r2, r3
    mov.w @r3, r3
    mov r3, r1
    shll r3
    add r1, r3
    cmp/hs r3, r0
    bf      .L_c2_write_active_cmd
    mov r8, r5
    mov.w @r14, r2
    add #0x1, r2
    mov.w r2, @r14
    mov.w r12, @r13
    mov.l   .L_cmd_data_c2, r7
    mov.l   .L_mask_nibble3_c, r6
    jsr @r9
    mov #0xC, r4
    mov #0x1, r2
    bra     .L_c2_write_active_cmd
    mov.w r2, @r10
.L_c2_check_last_phase:
    mov.w @r14, r0
    cmp/eq #0x34, r0
    bf      .L_c2_write_active_cmd
    mov.w @r14, r2
    mov.l   .L_timing_tbl_c2, r3
    mov.l   .L_global_tick_counter_c, r0
    shll r2
    mov.l @r0, r0
    add r3, r2
    mov.w @r2, r2
    mov r2, r1
    shll r2
    add r1, r2
    cmp/hs r2, r0
    bf      .L_c2_write_active_cmd
    mov.l   .L_cmd_data_c2, r7
    mov r8, r5
    mov.l   .L_mask_nibble3_c, r6
    jsr @r9
    mov #0xC, r4
    exts.w r12, r3
    mov.w r3, @r14
    exts.w r12, r2
    mov.w r2, @r13
    mov #0x1, r3
    mov.l   .L_anim_done_flag_c, r2
    mov.w r3, @r2
.L_c2_write_active_cmd:
    mov.w @r10, r0
    tst r0, r0
    bt      .L_c2_clear_active
    mov.w @r14, r7
    mov r8, r5
    mov.l   .L_seq_index_tbl_c2, r3
    mov.l   .L_cmd_ptr_tbl_c2, r2
    mov.l   .L_mask_nibble3_c, r6
    add #-0x1, r7
    add r3, r7
    mov.b @r7, r7
    shll2 r7
    add r2, r7
    mov.l @r7, r7
    jsr @r9
    mov #0xC, r4
.L_c2_clear_active:
    exts.w r12, r3
    mov.w r3, @r10
    mov.w @r14, r2
    cmp/pl r2
    bf      .L_check_anim_done
    bra     .L_c2_substep_iter
    nop
.L_c2_substep_check:
    mov #0x19, r3
    mov.w @r13, r2
    cmp/ge r3, r2
    bf      .L_c2_write_reg_block
    bra     .L_c2_substep_done
    nop
.L_c2_write_reg_block:
    mov.w @r13, r5
    mov.w @r14, r4
    mov.l   .L_seq_index_tbl_c2, r3
    mov.l   .L_cmd_ptr_tbl_c2, r2
    add #-0x1, r4
    add r3, r4
    mov.b @r4, r4
    shll2 r4
    add r2, r4
    bsr     vdp2_reg_block_setup
    mov.l @r4, r4
    mov.w @r13, r3
    add #0x1, r3
    mov.w r3, @r13
.L_c2_substep_iter:
    mov #0x19, r2
    mov.l   .L_anim_step_tbl_c2, r1
    mov.w @r14, r0
    mov.l   .L_seq_index_tbl_c2, r3
    mov.w @r13, r4
    add #-0x1, r0
    mov.b @(r0, r3), r0
    mulu.w r2, r0
    mov.w @r14, r2
    sts macl, r0
    add #-0x1, r2
    extu.b r0, r0
    shll r2
    add r1, r0
    mov.b @(r0, r4), r4
    mov.l   .L_timing_tbl_c2, r0
    mov.w @(r0, r2), r3
    add r4, r3
    mov r3, r2
    shll r3
    add r2, r3
    mov.l @r11, r2
    cmp/hs r3, r2
    bf      .L_c2_substep_done
    mov r4, r0
    cmp/eq #-0x1, r0
    bf      .L_c2_substep_check
.L_c2_substep_done:
    bra     .L_check_anim_done
    nop
.L_dispatch_course:
    cmp/eq #0x0, r0
    bf      .L_try_course1
    bra     .L_course0_handler
    nop
.L_try_course1:
    cmp/eq #0x1, r0
    bf      .L_try_course2
    bra     .L_course1_handler
    nop
.L_try_course2:
    cmp/eq #0x2, r0
    bf      .L_check_anim_done
    bra     .L_course2_handler
    nop
.L_check_anim_done:
    mov.l   .L_anim_done_flag_c, r0
    mov.w @r0, r0
    tst r0, r0
    bt      .L_epilogue
    mov.l r12, @r11
    exts.w r12, r3
    mov.l   .L_anim_done_flag_c, r2
    mov.w r3, @r2
.L_epilogue:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_timing_tbl_c2:
    .4byte  sym_0605956E              /* course 2 frame timing table (16-bit) */
.L_cmd_data_c2:
    .4byte  sym_06059826              /* course 2 display cmd data */
.L_mask_nibble3_c:
    .4byte  0x0000F000                /* VDP priority nibble mask (dup) */
.L_global_tick_counter_c:
    .4byte  sym_0607864C              /* global tick counter (dup) */
.L_anim_done_flag_c:
    .4byte  sym_0606123E              /* animation-done flag (dup) */
.L_seq_index_tbl_c2:
    .4byte  sym_06059186              /* course 2 sequence index byte table */
.L_cmd_ptr_tbl_c2:
    .4byte  sym_060611DC              /* course 2 cmd pointer table (dword) */
.L_anim_step_tbl_c2:
    .4byte  sym_060594A6              /* course 2 anim step sizes (stride=25) */

    .global vdp2_reg_block_setup
    .type vdp2_reg_block_setup, @function
vdp2_reg_block_setup:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov r15, r14
    mov.w r5, @r15
    add #0x4, r14
    mov.w @r15, r0
    mov r14, r7
    mov.b @(r0, r4), r3
    mov #0x0, r0
    mov.b r3, @r14
    mov.b r0, @(1, r14)
    mov.l   .L_mask_0xE000, r6
    mov.w @r15, r5
    mov.w   .L_reg_base_offset, r3
    add r3, r5
    shll r5
    mov.l   .L_fn_disp_cmd_write_2, r3
    jsr @r3
    mov #0xC, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_reg_base_offset:
    .2byte  0x0602                    /* VDP2 register base offset */
    .2byte  0xFFFF                    /* padding */
.L_mask_0xE000:
    .4byte  0x0000E000                /* VDP2 scroll priority mask */
.L_fn_disp_cmd_write_2:
    .4byte  sym_060283E0              /* display command writer (dup) */

    .global sym_06026CE0
sym_06026CE0:
    mov.l   .L_delay_countdown_reg, r1
    mov #0x1, r2
    mov.l   .L_delay_result_store, r3
    mov #0x0, r4
    mov.l r2, @r1
    nop
.L_delay_loop:
    mov.l @r1, r0
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    dt r0
    bt/s    .L_delay_loop
    add #0x1, r4
    rts
    mov.l r4, @r3
    .2byte  0x0009                    /* alignment padding (nop) */
.L_delay_countdown_reg:
    .4byte  sym_060635C4              /* game state active flag (countdown) */
.L_delay_result_store:
    .4byte  sym_0605A010              /* delay iteration count result */
    .4byte  0xD217E000
    .4byte  0xE1010215
    .4byte  0xE002E100
    .4byte  0x0215E006
    .4byte  0xE1000215
    .4byte  0xE00CE100
    .4byte  0x0215E00E
    .4byte  0x911C0215
    .4byte  0xE020E100
    .4byte  0x0215E028
    .4byte  0xE1000215
    .4byte  0xE02A9114
    .4byte  0x0215E030
    .4byte  0x91120215
    .4byte  0xE032910F
    .4byte  0x0215E034
    .4byte  0x910C0215
    .4byte  0xE0369109
    .4byte  0x0215E038
    .4byte  0xE1000215
    .4byte  0xE03AE100
    .4byte  0x000B0215
    .4byte  0x13631022
    .4byte  0xC0000000
    .4byte  0x25F80000
    .4byte  0xE100D006
    .4byte  0xD2064010
    .4byte  0x8FFD2216
    .4byte  0xD005D206
    .4byte  0x40108FFD
    .4byte  0x2216000B
    .4byte  0x00090000
    .4byte  0x00060000
    .4byte  0x25F80000
    .4byte  0x00030000
    .4byte  0x25CC0000

    .global sym_06026DBC
sym_06026DBC:
    .byte   0xD3, 0xAA    /* mov.l .L_pool_06027068, r3 */
    mov.l @r3, r0
    mov #0x30, r1
    add r0, r1
    mov.l r1, @r3
    mov.l @(0, r0), r2
    mov.l @(4, r0), r3
    mov.l r2, @(0, r1)
    mov.l r3, @(4, r1)
    mov.l @(8, r0), r2
    mov.l @(12, r0), r3
    mov.l r2, @(8, r1)
    mov.l r3, @(12, r1)
    mov.l @(16, r0), r2
    mov.l @(20, r0), r3
    mov.l r2, @(16, r1)
    mov.l r3, @(20, r1)
    mov.l @(24, r0), r2
    mov.l @(28, r0), r3
    mov.l r2, @(24, r1)
    mov.l r3, @(28, r1)
    mov.l @(32, r0), r2
    mov.l @(36, r0), r3
    mov.l r2, @(32, r1)
    mov.l r3, @(36, r1)
    mov.l @(40, r0), r2
    mov.l @(44, r0), r3
    mov.l r2, @(40, r1)
    rts
    mov.l r3, @(44, r1)

    .global sym_06026DF8
sym_06026DF8:
    .byte   0xD1, 0x9B    /* mov.l .L_pool_06027068, r1 */
    mov.l @r1, r0
    add #-0x30, r0
    rts
    mov.l r0, @r1

    .global sym_06026E02
sym_06026E02:
    .byte   0xD0, 0x9A    /* mov.l .L_pool_0602706C, r0 */
    .byte   0xD1, 0x98    /* mov.l .L_pool_06027068, r1 */
    mov #0x0, r2
    bra     .L_fill_identity
    mov.l r0, @r1

    .global sym_06026E0C
sym_06026E0C:
    .byte   0xD0, 0x96    /* mov.l .L_pool_06027068, r0 */
    mov #0x0, r2
    mov.l @r0, r0
.L_fill_identity:
    .byte   0xD1, 0x9A    /* mov.l .L_pool_0602707C, r1 — fixed-point 1.0 */
    mov.l r2, @(4, r0)
    mov.l r1, @(0, r0)
    mov.l r2, @(8, r0)
    mov.l r2, @(12, r0)
    mov.l r1, @(16, r0)
    mov.l r2, @(20, r0)
    mov.l r2, @(24, r0)
    mov.l r2, @(28, r0)
    mov.l r1, @(32, r0)
    mov.l r2, @(36, r0)
    mov.l r2, @(40, r0)
    rts
    mov.l r2, @(44, r0)

    .global sym_06026E2E
sym_06026E2E:
    .byte   0xD0, 0x90    /* mov.l .L_pool_06027070, r0 — temp vector storage */
    .byte   0xD1, 0x8D    /* mov.l .L_pool_06027068, r1 — matrix stack ptr */
    mov.l r4, @(0, r0)
    mov.l r5, @(4, r0)
    mov.l r6, @(8, r0)
    mov.l @r1, r4
    mov #0x3, r3
    mov r4, r5
    add #0x24, r5
.L_mac_row_loop:
    clrmac
    mac.l @r4+, @r0+
    mac.l @r4+, @r0+
    mac.l @r4+, @r0+
    mov.l @r5, r6
    add #-0xC, r0
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    add r6, r2
    mov.l r2, @r5
    bf/s    .L_mac_row_loop
    add #0x4, r5
    rts
    nop
