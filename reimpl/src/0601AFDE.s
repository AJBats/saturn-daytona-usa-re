
    .section .text.FUN_0601AFDE


    .global replay_cam_cleanup
    .type replay_cam_cleanup, @function
replay_cam_cleanup:
    sts.l pr, @-r15
    mov r6, r5
    .byte   0xDE, 0x20    /* mov.l .L_pool_0601B064, r14 */
    .byte   0x93, 0x3B    /* mov.w .L_wpool_0601B05E, r3 */
    mov.l r3, @-r15
    .byte   0x92, 0x3A    /* mov.w .L_wpool_0601B060, r2 */
    mov.l r2, @-r15
    mov.l @r14, r3
    mov #0x1, r2
    extu.w r3, r3
    mov.l r3, @-r15
    mov.l r2, @-r15
    .byte   0xD3, 0x1C    /* mov.l .L_pool_0601B068, r3 */
    jsr @r3
    mov r7, r4
    mov.l @r14, r2
    add #0x2, r2
    mov.l r2, @r14
    mov r2, r3
    .byte   0x92, 0x2B    /* mov.w .L_wpool_0601B05E, r2 */
    cmp/hs r2, r3
    bf/s    .L_0601B01A
    add #0x10, r15
    .byte   0xD4, 0x17    /* mov.l .L_pool_0601B06C, r4 */
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    mov #0x28, r3
    .byte   0xD2, 0x16    /* mov.l .L_pool_0601B070, r2 */
    mov.b r3, @r2
.L_0601B01A:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
