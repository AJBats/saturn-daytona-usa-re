
    .section .text.FUN_06016A1C


    .global small_number_render
    .type small_number_render, @function
small_number_render:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov.b @r15, r14
    .byte   0xD2, 0x2C    /* mov.l .L_pool_06016AD8, r2 */
    mov.b @r15, r4
    extu.b r14, r14
    mov r14, r3
    shll2 r14
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r14
    exts.w r14, r14
    add r2, r14
    mov.b @(r0, r14), r5
    extu.b r5, r5
    .reloc ., R_SH_IND12W, track_seg_init - 4
    .2byte 0xB000    /* bsr track_seg_init (linker-resolved) */
    extu.b r4, r4
    .byte   0xD2, 0x26    /* mov.l .L_pool_06016ADC, r2 */
    mov.l r2, @(12, r14)
    .byte   0xD3, 0x26    /* mov.l .L_pool_06016AE0, r3 */
    mov.l r3, @(24, r14)
    .byte   0xD2, 0x26    /* mov.l .L_pool_06016AE4, r2 */
    mov.l r2, @(36, r14)
    mov.b @(2, r14), r0
    mov r0, r3
    add #0x1, r3
    mov r3, r0
    mov.b r0, @(2, r14)
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
