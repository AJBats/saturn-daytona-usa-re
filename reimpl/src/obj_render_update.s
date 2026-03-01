
    .section .text.FUN_060210F6


    .global obj_render_update
    .type obj_render_update, @function
obj_render_update:
    sts.l pr, @-r15
    .byte   0xD3, 0x07    /* mov.l .L_pool_06021118, r3 */
    jsr @r3
    mov #0x8, r4
    mov #0x0, r2
    .byte   0xD3, 0x08    /* mov.l .L_pool_06021124, r3 */
    mov.b r2, @r3
    .byte   0xD4, 0x03    /* mov.l .L_pool_06021114, r4 */
    .byte   0xD3, 0x05    /* mov.l .L_pool_0602111C, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x04    /* mov.l .L_pool_06021120, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x1810
.L_pool_06021119:
    .4byte  sym_06087C84                /* scene config struct base */
.L_pool_0602111D:
    .4byte  sym_0603850C                /* cmd_slot_write function */
.L_pool_06021121:
    .4byte  scene_buffer_init           /* scene_buffer_init function */
.L_pool_06021125:
    .4byte  sym_06038520                /* cmd_queue_commit function */
.L_pool_06021129:
    .4byte  sym_06087C87                /* channel_flag_D config byte */
