
    .section .text.FUN_0600A4AA


    .global camera_pos_calc
    .type camera_pos_calc, @function
camera_pos_calc:
    sts.l pr, @-r15
    .byte   0xD5, 0x1E    /* mov.l .L_pool_0600A528, r5 */
    .byte   0xD4, 0x1F    /* mov.l .L_pool_0600A52C, r4 */
    .byte   0xD3, 0x18    /* mov.l .L_pool_0600A514, r3 */
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x1D    /* mov.l .L_pool_0600A530, r6 */
    mov.l @r6, r6
    .byte   0xD5, 0x1D    /* mov.l .L_pool_0600A534, r5 */
    mov.w @r5, r5
    .byte   0xD4, 0x1D    /* mov.l .L_pool_0600A538, r4 */
    mov.l @r4, r4
    .byte   0xD3, 0x17    /* mov.l .L_pool_0600A524, r3 */
    jmp @r3
    lds.l @r15+, pr
