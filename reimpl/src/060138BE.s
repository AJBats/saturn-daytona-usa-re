	.text
    .global race_timer_format
race_timer_format:
    mov.l r14, @-r15
    .byte   0xD3, 0x17    /* mov.l .L_06013920, r3 */
    mov.l r3, @-r15
    .byte   0xD5, 0x17    /* mov.l .L_pool_06013928, r5 */
    .byte   0xD3, 0x18    /* mov.l .L_pool_0601392C, r3 */
    jsr @r3
    mov r2, r4
    add #0xC, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x16    /* mov.l .L_pool_06013930, r3 */
    jmp @r3
    mov.l @r15+, r14

    .global DAT_060138d6
DAT_060138d6:
    .word 0x04B0

    .global DAT_060138d8
DAT_060138d8:
    mov.b @(r0, r13), r5

    .global DAT_060138da
DAT_060138da:
    mov.b @(r0, r0), r2
    .long  sym_06084B0C
    .long  sym_06084B18
    .long  sym_06084B20
    .long  sym_06084AF0
    .long  sym_0607EBCC
    .long  sym_06084AF2
    .long  sym_06084B14
    .long  sym_0605AD5C
    .long  sym_06084AF8
    .long  sym_06084AFC
    .long  sym_0605AAA0
    .long  0xAB1100FF
    .long  sound_cmd_dispatch
    .long  sym_060149CC
    .long  sym_06026CE0
    .long  sym_0605B6B8
    .long  0x00010000
.L_06013920:
    .long  0x00008000
.L_pool_06013928:
    .long  0x00960000
.L_pool_0601392C:
    .long  rigid_body_transform
.L_pool_06013930:
    .long  frame_end_commit

    .global loc_06013930
loc_06013930:
    mov #0x1, r3
    .byte   0xD2, 0x03    /* mov.l .L_pool_06013946, r2 */
    mov.b r3, @r2
    mov #0x20, r3
    .byte   0xD2, 0x02    /* mov.l .L_pool_0601394A, r2 */
    mov.w r3, @r2
    .byte   0xA0, 0x04    /* bra 0x06013948 (external) */
    nop
.L_pool_06013946:
    .long  sym_06084AF2
.L_pool_0601394A:
    .long  sym_06084AF4
