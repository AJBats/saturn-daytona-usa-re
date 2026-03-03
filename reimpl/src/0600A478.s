
    .section .text.FUN_0600A478


    .global camera_dist_clamp
    .type camera_dist_clamp, @function
camera_dist_clamp:
    sts.l pr, @-r15
    shll2 r14
    add #-0x4, r15
    mov.l r4, @r15
    .byte   0xD5, 0x22    /* mov.l .L_pool_0600A50C, r5 */
    .byte   0xD4, 0x23    /* mov.l .L_pool_0600A510, r4 */
    .byte   0xD3, 0x23    /* mov.l .L_pool_0600A514, r3 */
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x21    /* mov.l .L_pool_0600A518, r6 */
    add r14, r6
    mov.l @r6, r6
    .byte   0xD5, 0x21    /* mov.l .L_pool_0600A51C, r5 */
    mov.w @r5, r5
    .byte   0xD4, 0x21    /* mov.l .L_pool_0600A520, r4 */
    add r14, r4
    mov.l @r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x1F    /* mov.l .L_pool_0600A524, r3 */
    jmp @r3
    mov.l @r15+, r14
