
    .section .text.FUN_0601B024


    .global disc_sector_read
    .type disc_sector_read, @function
disc_sector_read:
    sts.l pr, @-r15
    mov #0x30, r14
    mov.l   .L_attract_color_state, r3
    mov r14, r6
    mov r14, r5
    mov.l r14, @r3
    mov.w   .L_const_color_offset, r2
    mov.l r2, @-r15
    mov.w   .L_const_color_component, r3
    extu.w r14, r2
    mov.l r3, @-r15
    mov #0x1, r3
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l   .L_fn_color_transform, r3
    jsr @r3
    mov r7, r4
    .byte   0xB0, 0x47    /* bsr 0x0601B0D8 (external) */  ! call course_state_setup
    add #0x10, r15
    mov #0x14, r2
    mov.l   .L_phase_timer, r3
    mov.b r2, @r3
    mov.l   .L_phase_index, r4
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_const_color_offset:
    .2byte  0x00A7                               /* color offset value (167) */
.L_const_color_component:
    .2byte  0x0160                               /* color component value (352) */
    .2byte  0xFFFF                               /* alignment padding */
.L_attract_color_state:
    .4byte  sym_06086014                         /* attract color state word (byte/long) */
.L_fn_color_transform:
    .4byte  color_transform_calc                 /* VDP2 color transform calculator */
.L_phase_index:
    .4byte  sym_06086011                         /* current attract phase index (byte) */
.L_phase_timer:
    .4byte  sym_0608600F                         /* phase countdown timer (byte) */
