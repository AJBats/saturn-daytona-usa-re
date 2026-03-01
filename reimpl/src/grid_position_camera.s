
    .section .text.FUN_0601A0F0


    .global grid_position_camera
    .type grid_position_camera, @function
grid_position_camera:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l   .L_pool_0601A198, r13
    mov.l   .L_pool_0601A19C, r14
    mov.w @r13, r0
    extu.w r0, r0
    tst #0x1, r0
    bt/s    .L_mode_b
    mov #0x0, r12
    bra     .L_mode_selected
    mov #0x6, r5
.L_mode_b:
    mov #0x19, r5
.L_mode_selected:
    mov.l   .L_up_btn_mask, r7
    mov.l   .L_pool_0601A1A4, r4
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_check_new_down
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_clamp
    mov.b r2, @r4
.L_check_new_down:
    mov.w   .L_down_btn_mask, r6
    mov.w @(2, r13), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_check_held_up
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_clamp
    mov.b r2, @r4
.L_check_held_up:
    mov.w @r13, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_check_held_down
    mov.b @r4, r3
    extu.b r5, r5
    cmp/eq r5, r3
    bf      .L_clamp
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    bra     .L_clamp
    mov.b r2, @r4
.L_check_held_down:
    mov.w @r13, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_clamp
    extu.b r5, r5
    mov.b @r4, r3
    cmp/eq r5, r3
    bf      .L_clamp
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r12, r2
    mov.b r2, @r4
.L_clamp:
    mov #0x5, r2
    mov.l @r14, r3
    cmp/ge r2, r3
    bf      .L_check_lower_clamp
    mov #0x4, r2
    mov.l r2, @r14
.L_check_lower_clamp:
    mov.l @r14, r3
    cmp/pz r3
    bt      .L_epilogue
    mov.l r12, @r14
.L_epilogue:
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xAF, 0x0E    /* bra 0x06019FB2 (external) */
    mov.l @r15+, r14
.L_down_btn_mask:
    .2byte  0x4000                          /* Down button bit mask (bit 14) */
.L_pool_0601A198:
    .4byte  g_pad_state                    /* &input_state (+0=held, +2=newly pressed) */
.L_pool_0601A19C:
    .4byte  sym_0605AD04                    /* &grid_slot_counter (32-bit) */
.L_up_btn_mask:
    .4byte  0x00008000                      /* Up button bit mask (bit 15, 32-bit for AND) */
.L_pool_0601A1A4:
    .4byte  sym_0605D243                    /* &grid_slot_byte (byte output) */

    .global loc_0601A1A8
loc_0601A1A8:
    .byte   0xD3, 0x25    /* mov.l .L_pool_0601A240, r3 */
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    .byte   0xD2, 0x24    /* mov.l .L_pool_0601A244, r2 */
    add r2, r3
    mov.l @r3, r3
    jmp @r3
    nop
