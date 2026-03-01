
    .section .text.FUN_0601AF1E


    .global replay_cam_auto_cut
    .type replay_cam_auto_cut, @function
replay_cam_auto_cut:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x13    /* mov.l .L_p_course_dlist_desc, r3 */  ! r3 = &course_dlist_descriptor
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_w_dlist_src_offset, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    .byte   0xD3, 0x11    /* mov.l .L_dlist_offset_0xC000, r3 */  ! r3 = 0xC000 (display list offset)
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x11    /* mov.l .L_p_display_list_loader, r3 */  ! r3 = &display_list_loader
    jsr @r3
    mov #0x8, r4
    .byte   0xDE, 0x10    /* mov.l .L_p_attract_frame_ctr, r14 */  ! r14 = &attract_frame_counter
    .byte   0xD5, 0x11    /* mov.l .L_p_render_state, r5 */  ! r5 = &render_state
    .byte   0xD4, 0x11    /* mov.l .L_p_race_end_state, r4 */  ! r4 = &race_end_state
    mov.b @r14, r6
    mov.l @r5, r5
    mov.l @r4, r4
    exts.b r5, r5
    .byte   0xB0, 0xA6    /* bsr 0x0601B09A (external) */  ! call cam_display_list_submit
    exts.b r4, r4
    mov #0xA, r3
    mov.b @r14, r2
    add #0x5, r2
    mov.b r2, @r14
    .byte   0xD2, 0x05    /* mov.l .L_p_phase_countdown, r2 */  ! r2 = &phase_countdown_timer
    mov.b r3, @r2
    .byte   0xD4, 0x05    /* mov.l .L_p_phase_index, r4 */  ! r4 = &phase_index
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_w_dlist_src_offset:
    .2byte  0x0096                     /* [HIGH] display list source offset */
.L_p_phase_countdown:
    .4byte  sym_0608600F               /* [MEDIUM] phase countdown timer (byte) */
.L_p_phase_index:
    .4byte  sym_06086011               /* [MEDIUM] phase index (byte) */
.L_p_course_dlist_desc:
    .4byte  sym_060638C8               /* [MEDIUM] course display list descriptor ptr */
.L_dlist_offset_0xC000:
    .4byte  0x0000C000                 /* [MEDIUM] display list texture region offset */
.L_p_display_list_loader:
    .4byte  sym_06028400               /* [HIGH] display_list_loader fn */
.L_p_attract_frame_ctr:
    .4byte  sym_06086010               /* [MEDIUM] attract frame counter (byte) */
.L_p_render_state:
    .4byte  sym_0605AD00               /* [MEDIUM] race/render state variable */
.L_p_race_end_state:
    .4byte  sym_0607EAD8               /* [HIGH] car object / race end state ptr */
