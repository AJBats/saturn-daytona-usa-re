
    .section .text.FUN_0603BC86


    .global save_serialize
    .type save_serialize, @function
save_serialize:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov r4, r12
    add #-0x8, r15
    mov r12, r4
    mov.l r5, @r15
    mov r7, r5
    mov.l r7, @(4, r15)
    .byte   0xD3, 0x0F    /* mov.l .L_pool_0603BCDA, r3 */  ! r3 = obj_init_validate
    jsr @r3
    add #0x14, r4
    mov r0, r14
    tst r14, r14
    bf      .L_init_ok
    bra     .L_epilogue
    mov #0x0, r0
.L_init_ok:
    mov #0x1C, r0
    mov r14, r5
    mov.l @r15, r3
    mov.l r14, @r3
    mov #0x0, r3
    mov.b @(r0, r14), r7
    extu.b r7, r7
    mov.l r3, @-r15
    mov.l @(12, r14), r6
    mov.w   .L_wpool_0603BCD2, r4
    .byte   0xD3, 0x07    /* mov.l .L_pool_0603BCDE, r3 */  ! r3 = obj_setup_decomp
    jsr @r3
    add r12, r4
    mov r0, r13
    tst r13, r13
    bf/s    .L_decomp_ok
    add #0x4, r15
    bra     .L_epilogue
    mov #0x0, r0
.L_wpool_0603BCD2:
    .2byte  0x00A8                      /* offset 0xA8 within block (descriptor area) */
    .2byte  0xFFFF                      /* padding */
.L_pool_0603BCD6:
    .4byte  scene_frame_render          /* unreferenced pool filler (alignment artifact) */
.L_pool_0603BCDA:
    .4byte  obj_init_validate           /* init road-segment object */
.L_pool_0603BCDE:
    .4byte  obj_setup_decomp            /* decompose object into resource slots */
.L_decomp_ok:
    mov r13, r5
    .byte   0xD3, 0x21    /* mov.l .L_pool_obj_field24_setter, r3 */  ! r3 = sym_060401E4 (obj[+24] setter)
    jsr @r3
    mov r14, r4
    .byte   0xD2, 0x20    /* mov.l .L_pool_nop_stub_evt, r2 */  ! r2 = nop_stub_evt (6th descriptor field)
    mov r13, r5
    mov r12, r4
    mov.l r2, @-r15
    .byte   0xD3, 0x1F    /* mov.l .L_pool_ret_zero_stub, r3 */  ! r3 = sym_06040C50 (5th descriptor field)
    mov.l r3, @-r15
    .byte   0xD2, 0x1F    /* mov.l .L_pool_event_priority_set, r2 */  ! r2 = event_priority_set (4th descriptor field)
    mov.l r2, @-r15
    .byte   0xD7, 0x1F    /* mov.l .L_pool_evt_status_flag_set, r7 */  ! r7 = evt_status_flag_set (descriptor field 2)
    .byte   0xD6, 0x20    /* mov.l .L_pool_evt_cmd_enqueue, r6 */  ! r6 = evt_cmd_enqueue (descriptor field 1)
    .byte   0xD3, 0x20    /* mov.l .L_pool_cmd_desc_init, r3 */  ! r3 = sym_0603F8B8 (cmd_desc_init)
    jsr @r3
    add #0x78, r4
    add #0xC, r15
    mov r0, r4
    mov.l @r15, r2
    mov #0x0, r3
    mov #0x10, r0
    mov.b r3, @(r0, r2)
    mov r4, r0
.L_epilogue:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
