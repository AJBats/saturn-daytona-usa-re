
    .section .text.FUN_06005A22


    .global input_event_handler
    .type input_event_handler, @function
input_event_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD4, 0x26    /* mov.l _pool_lap_disp_timer, r4 */
    mov.l @r4, r3
    cmp/pl r3
    bf      .L_epilogue
    mov.l @r4, r3
    add #-0x1, r3
    mov r3, r0
    tst #0x1, r0
    bt/s    .L_even_frame
    mov.l r3, @r4
    .byte   0xD0, 0x22    /* mov.l _pool_2p_mode_flag, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_1p_index
    mov.w   _wpool_2p_elem_index, r14
    bra     .L_index_selected
    nop
.L_1p_index:
    mov #0x21, r14
.L_index_selected:
    .byte   0xD0, 0x1F    /* mov.l _pool_anim_countdown, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_anim_zero
    mov r14, r7
    shll2 r7
    shll r7
    .byte   0xD3, 0x1D    /* mov.l _pool_car_obj_table, r3 */
    add r3, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06005abc, r3
    add r3, r7
    mov.w   DAT_06005abe, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x18    /* mov.l _pool_dlist_loader, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_anim_zero:
    mov r14, r7
    shll2 r7
    shll r7
    .byte   0xD3, 0x14    /* mov.l _pool_car_obj_table, r3 */
    add r3, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06005abc, r3
    add r3, r7
    mov.w   DAT_06005ac0, r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x0F    /* mov.l _pool_dlist_loader, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_even_frame:
    .byte   0xD7, 0x0E    /* mov.l _pool_static_data, r7 */
    mov.w   _wpool_static_size, r6
    mov.w   DAT_06005abe, r5
    .byte   0xD3, 0x0E    /* mov.l _pool_geom_dispatch, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD7, 0x0B    /* mov.l _pool_static_data, r7 */
    mov.w   _wpool_static_size, r6
    mov.w   DAT_06005ac0, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x09    /* mov.l _pool_geom_dispatch, r3 */
    jmp @r3
    mov.l @r15+, r14


_wpool_2p_elem_index:
    .2byte  0x00B0                            /* 2P mode display element index (176) */

    .global DAT_06005abc
DAT_06005abc:
    .2byte  0x5000                            /* VRAM offset for car object table entry */

    .global DAT_06005abe
DAT_06005abe:
    .2byte  0x049C                            /* element size A (anim active / first elem) */

    .global DAT_06005ac0
DAT_06005ac0:
    .2byte  0x059C                            /* element size B (anim idle / second elem) */

_wpool_static_size:
    .2byte  0x0090                            /* static element size */


_pool_lap_disp_timer:
    .4byte  sym_0607EABC                      /* -> lap display timer (32-bit countdown) */
_pool_2p_mode_flag:
    .4byte  sym_06085FF4                      /* -> 2-player mode flag (byte) */
_pool_anim_countdown:
    .4byte  sym_0607EAC0                      /* -> anim countdown timer (32-bit) */
_pool_car_obj_table:
    .4byte  sym_06063750                      /* -> car object table base (8 bytes/entry) */
_pool_dlist_loader:
    .4byte  sym_06028400                      /* -> display_list_loader function */
_pool_static_data:
    .4byte  sym_0605ACDD                      /* -> static rendering data pointer */
_pool_geom_dispatch:
    .4byte  sym_060284AE                      /* -> geom_dispatch_final function */


.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
