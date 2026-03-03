	.text
    .global replay_cam_auto_cut
replay_cam_auto_cut:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x13    /* mov.l .L_0601AF74, r3 */
    mov.l r3, @r15
    mov r3, r7
    mov.w   .L_0601AF6A, r6
    mov.l @r15, r5
    mov.l @(4, r7), r7
    .byte   0xD3, 0x11    /* mov.l .L_0601AF78, r3 */
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x11    /* mov.l .L_0601AF7C, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xDE, 0x10    /* mov.l .L_0601AF80, r14 */
    .byte   0xD5, 0x11    /* mov.l .L_0601AF84, r5 */
    .byte   0xD4, 0x11    /* mov.l .L_0601AF88, r4 */
    mov.b @r14, r6
    mov.l @r5, r5
    mov.l @r4, r4
    exts.b r5, r5
    .byte   0xB0, 0xA6    /* bsr 0x0601B09A (external) */
    exts.b r4, r4
    mov #0xA, r3
    mov.b @r14, r2
    add #0x5, r2
    mov.b r2, @r14
    .byte   0xD2, 0x05    /* mov.l .L_0601AF6C, r2 */
    mov.b r3, @r2
    .byte   0xD4, 0x05    /* mov.l .L_0601AF70, r4 */
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_0601AF6A:
    .short  0x0096
.L_0601AF6C:
    .long  sym_0608600F
.L_0601AF70:
    .long  sym_06086011
.L_0601AF74:
    .long  sym_060638C8
.L_0601AF78:
    .long  0x0000C000
.L_0601AF7C:
    .long  sym_06028400
.L_0601AF80:
    .long  sym_06086010
.L_0601AF84:
    .long  sym_0605AD00
.L_0601AF88:
    .long  sym_0607EAD8
