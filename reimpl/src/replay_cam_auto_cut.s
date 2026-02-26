/* replay_cam_auto_cut -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601AF1E - 0x0601AF8C
 *
 * replay_cam_auto_cut (0x0601AF1E, 110 bytes)
 *
 * Performs a single replay camera auto-cut: loads the course display list
 * descriptor, submits a display list entry via the display list loader
 * (sym_06028400) at offset 0x96 with mode 8, then calls the camera display
 * list submit helper (0x0601B09A) passing the attract frame counter and
 * render/race-end state values. After the cut, advances the attract frame
 * counter by 5, resets the phase countdown timer to 0xA (10 frames), and
 * increments the current phase index.
 *
 * Inputs:
 *   None (reads all state from globals)
 *
 * Side effects:
 *   - Submits a display list entry for the new camera position
 *   - attract_frame_counter += 5
 *   - phase_countdown_timer = 0xA
 *   - phase_index += 1
 *
 * Calls:
 *   sym_06028400 = display_list_loader(r4=mode, r5=dlist_base, r6=offset, r7=tex_data)
 *   0x0601B09A  = cam_display_list_submit (byte blob in course_setup_handler TU)
 */

    .section .text.FUN_0601AF1E


    .global replay_cam_auto_cut
    .type replay_cam_auto_cut, @function
replay_cam_auto_cut:
    mov.l r14, @-r15                            ! save r14
    sts.l pr, @-r15                             ! save return address
    add #-0x4, r15                              ! allocate 4 bytes of local stack
    .byte   0xD3, 0x13    /* mov.l .L_p_course_dlist_desc, r3 */  ! r3 = &course_dlist_descriptor
    mov.l r3, @r15                              ! local[0] = course_dlist_descriptor ptr
    mov r3, r7                                  ! r7 = course_dlist_descriptor (tex_data arg)
    mov.w   .L_wpool_0601AF6A, r6               ! r6 = 0x96 (display list source offset)
    mov.l @r15, r5                              ! r5 = course_dlist_descriptor (dlist_base arg)
    mov.l @(4, r7), r7                          ! r7 = dlist_descriptor[1] (display list pointer)
    .byte   0xD3, 0x11    /* mov.l .L_dlist_offset_0xC000, r3 */  ! r3 = 0xC000 (display list offset)
    mov.l @r5, r5                               ! r5 = *course_dlist_descriptor (base addr)
    add r3, r7                                  ! r7 = dlist_ptr + 0xC000 (texture data region)
    .byte   0xD3, 0x11    /* mov.l .L_p_display_list_loader, r3 */  ! r3 = &display_list_loader
    jsr @r3                                     ! call display_list_loader(mode=8, dlist, 0x96, tex)
    mov #0x8, r4                                ! r4 = 8 (display mode, delay slot)
    .byte   0xDE, 0x10    /* mov.l .L_p_attract_frame_ctr, r14 */  ! r14 = &attract_frame_counter
    .byte   0xD5, 0x11    /* mov.l .L_p_render_state, r5 */  ! r5 = &render_state
    .byte   0xD4, 0x11    /* mov.l .L_p_race_end_state, r4 */  ! r4 = &race_end_state
    mov.b @r14, r6                              ! r6 = attract_frame_counter (byte)
    mov.l @r5, r5                               ! r5 = render_state value
    mov.l @r4, r4                               ! r4 = race_end_state value
    exts.b r5, r5                               ! r5 = sign-extend render_state to 32 bits
    .byte   0xB0, 0xA6    /* bsr 0x0601B09A (external) */  ! call cam_display_list_submit
    exts.b r4, r4                               ! r4 = sign-extend race_end_state (delay slot)
    mov #0xA, r3                                ! r3 = 0xA (new phase countdown = 10 frames)
    mov.b @r14, r2                              ! r2 = attract_frame_counter (current value)
    add #0x5, r2                                ! r2 = attract_frame_counter + 5
    mov.b r2, @r14                              ! attract_frame_counter += 5
    .byte   0xD2, 0x05    /* mov.l .L_p_phase_countdown, r2 */  ! r2 = &phase_countdown_timer
    mov.b r3, @r2                               ! phase_countdown_timer = 0xA
    .byte   0xD4, 0x05    /* mov.l .L_p_phase_index, r4 */  ! r4 = &phase_index
    mov.b @r4, r3                               ! r3 = current phase_index
    add #0x1, r3                                ! r3 = phase_index + 1
    mov.b r3, @r4                               ! phase_index += 1
    add #0x4, r15                               ! deallocate local stack
    lds.l @r15+, pr                             ! restore return address
    rts                                         ! return
    mov.l @r15+, r14                            ! restore r14 (delay slot)
.L_wpool_0601AF6A:
    .2byte  0x0096
.L_p_phase_countdown:
    .4byte  sym_0608600F
.L_p_phase_index:
    .4byte  sym_06086011
.L_p_course_dlist_desc:
    .4byte  sym_060638C8
.L_dlist_offset_0xC000:
    .4byte  0x0000C000                  /* bits 15:14 mask */
.L_p_display_list_loader:
    .4byte  sym_06028400
.L_p_attract_frame_ctr:
    .4byte  sym_06086010
.L_p_render_state:
    .4byte  sym_0605AD00
.L_p_race_end_state:
    .4byte  sym_0607EAD8
