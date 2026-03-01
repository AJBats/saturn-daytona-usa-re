
    .section .text.FUN_0600330A


    .global vdp_init_advanced
    .type vdp_init_advanced, @function
vdp_init_advanced:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDD, 0x1C    /* mov.l _pool_scene_table, r13 */
    .byte   0xDE, 0x1C    /* mov.l _pool_dlist_loader, r14 */
    mov.w   _w_tbl_offset_0, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   _w_vram_dest_0, r3
    mov.w   _w_xfer_size_0, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0xC, r4
    mov.w   _w_tbl_offset_1, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   _w_vram_dest_1, r3
    mov.w   _w_xfer_size_1, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0xC, r4
    mov.w   _w_tbl_offset_2, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   _w_vram_dest_2, r3
    mov.w   _w_xfer_size_2, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0x0D00
    .2byte  0x0D80

    .global DAT_06003366
_w_tbl_offset_0:
DAT_06003366:
    .2byte  0x0368

    .global DAT_06003368
_w_vram_dest_0:
DAT_06003368:
    .2byte  0x3000
_w_xfer_size_0:
    .2byte  0x0BC8

    .global DAT_0600336c
_w_tbl_offset_1:
DAT_0600336c:
    .2byte  0x0378

    .global DAT_0600336e
_w_vram_dest_1:
DAT_0600336e:
    .2byte  0x4000

    .global DAT_06003370
_w_xfer_size_1:
DAT_06003370:
    .2byte  0x00C6

    .global DAT_06003372
_w_tbl_offset_2:
DAT_06003372:
    .2byte  0x0370

    .global DAT_06003374
_w_vram_dest_2:
DAT_06003374:
    .2byte  0x5000

    .global DAT_06003376
_w_xfer_size_2:
DAT_06003376:
    .2byte  0x0C02
    .4byte  sym_06059ECE
    .4byte  sym_060283E0
    .4byte  0x0000F000
_pool_scene_table:
    .4byte  sym_06063750
_pool_dlist_loader:
    .4byte  sym_06028400

    .global sym_0600338C
sym_0600338C:
    add #-0x8, r15
    mov #0x4, r3
    mov.l r5, @r15
    and r3, r4
    tst r4, r4
    bt      .L_060033CA
    .byte   0xD3, 0x1D    /* mov.l _pool_adv_display_status, r3 */
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   _w_interlace_mask, r3
    and r3, r2
    tst r2, r2
    bf      .L_060033E2
    .byte   0xD3, 0x1B    /* mov.l _pool_slot_struct_base, r3 */
    mov.l r3, @(4, r15)
    mov r3, r7
    mov.l @r15, r6
    mov.l @(4, r7), r7
    mov.w   _w_slot_vram_offset, r3
    shll2 r6
    add r3, r7
    shll2 r6
    shll2 r6
    add #0xB, r6
    shll r6
    mov.l @(4, r15), r5
    mov.l @r5, r5
    mov #0xC, r4
    .byte   0xD3, 0x14    /* mov.l _pool_fn_dlist_loader, r3 */
    jmp @r3
    add #0x8, r15
.L_060033CA:
    mov #0x60, r6
    mov.l @r15, r5
    .byte   0xD7, 0x13    /* mov.l _pool_static_elem_data, r7 */
    shll2 r5
    shll2 r5
    shll2 r5
    add #0xB, r5
    shll r5
    mov #0xC, r4
    .byte   0xD3, 0x10    /* mov.l _pool_fn_geom_dispatch, r3 */
    jmp @r3
    add #0x8, r15
.L_060033E2:
    rts
    add #0x8, r15

    .global sym_060033E6
sym_060033E6:
    .byte   0xD0, 0x0F    /* mov.l _pool_env_flags, r0 */
    mov.l @r0, r0
    tst #0x4, r0
    bt      .L_060033FA
    .byte   0xD7, 0x0E    /* mov.l _pool_replay_string, r7 */
    mov.w   _w_text_size, r6
    mov.w   _w_text_vram_dest, r5
    .byte   0xD3, 0x0A    /* mov.l _pool_fn_geom_dispatch, r3 */
    jmp @r3
    mov #0x8, r4
.L_060033FA:
    .byte   0xD7, 0x0C    /* mov.l _pool_alt_text_data, r7 */
    mov.w   _w_text_size, r6
    mov.w   _w_text_vram_dest, r5
    .byte   0xD3, 0x07    /* mov.l _pool_fn_geom_dispatch, r3 */
    jmp @r3
    mov #0x8, r4

    .global DAT_06003406
_w_interlace_mask:
DAT_06003406:
    .2byte  0x0200

    .global DAT_06003408
_w_slot_vram_offset:
DAT_06003408:
    .2byte  0x5000
_w_text_size:
    .2byte  0x0090

    .global DAT_0600340c
_w_text_vram_dest:
DAT_0600340c:
    .2byte  0x0C04
    .2byte  0xFFFF
_pool_adv_display_status:
    .4byte  sym_06063DA0
_pool_slot_struct_base:
    .4byte  sym_06063AD0
_pool_fn_dlist_loader:
    .4byte  sym_06028400
_pool_static_elem_data:
    .4byte  sym_0605ACDD
_pool_fn_geom_dispatch:
    .4byte  sym_060284AE
_pool_env_flags:
    .4byte  sym_0607EBC8
_pool_replay_string:
    .4byte  sym_06044638
_pool_alt_text_data:
    .4byte  sym_0605ACF0

    .global sym_06003430
sym_06003430:
    add #-0x4, r15
    .byte   0xD3, 0x1B    /* mov.l .L_pool_060034A0, r3 */
    mov.b @r3, r3
    tst r3, r3
    bf      .L_06003450
    .byte   0xD3, 0x1A    /* mov.l .L_pool_060034A4, r3 */
    mov.l r3, @r15
    mov r3, r7
    mov.l @(4, r7), r7
    .byte   0x96, 0x29    /* mov.w .L_wpool_06003498, r6 */
    mov r3, r5
    mov.l @r5, r5
    mov #0x4, r4
    .byte   0xD3, 0x17    /* mov.l .L_pool_060034A8, r3 */
    jmp @r3
    add #0x4, r15
.L_06003450:
    .byte   0xD2, 0x16    /* mov.l .L_pool_060034AC, r2 */
    mov.l r2, @r15
    mov r2, r7
    mov.l @(4, r7), r7
    .byte   0x96, 0x1F    /* mov.w .L_wpool_0600349A, r6 */
    mov r2, r5
    mov.l @r5, r5
    mov #0x4, r4
    .byte   0xD3, 0x11    /* mov.l .L_pool_060034A8, r3 */
    jmp @r3
    add #0x4, r15
