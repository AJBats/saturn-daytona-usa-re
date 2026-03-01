
    .section .text.FUN_06003466


    .global vdp2_course0_init
    .type vdp2_course0_init, @function
vdp2_course0_init:
    mov.l r14, @-r15
    sts.l pr, @-r15

    .byte   0xD5, 0x11    /* mov.l .L_060034B0, r5 */
    .byte   0xD4, 0x11    /* mov.l .L_060034B4, r4 */
    .byte   0xD3, 0x12    /* mov.l .L_060034B8, r3 */
    jsr @r3
    mov #0x60, r6

    .byte   0xDE, 0x11    /* mov.l .L_060034BC, r14 */
    .byte   0xD5, 0x12    /* mov.l .L_060034C0, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_060034C4, r4 */
    jsr @r14
    nop

    .byte   0xD5, 0x12    /* mov.l .L_060034C8, r5 */
    .byte   0xD4, 0x12    /* mov.l .L_060034CC, r4 */
    jsr @r14
    mov.l @r5, r5

    .byte   0xD5, 0x10    /* mov.l .L_060034C8, r5 */
    mov.w   .L_0600349C, r2
    .byte   0xD4, 0x11    /* mov.l .L_060034D0, r4 */
    mov.l @r5, r5
    jsr @r14
    add r2, r5

    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  0x09000490
.L_0600349C:
    .2byte  0x2000
    .2byte  0xFFFF
    .4byte  sym_06083255
    .4byte  sym_06063798
    .4byte  sym_06028400
    .4byte  sym_06063790
.L_060034B0:
    .4byte  0x25F00800
.L_060034B4:
    .4byte  0x25F00200
.L_060034B8:
    .4byte  memcpy_word_idx
.L_060034BC:
    .4byte  dma_memory_transfer
.L_060034C0:
    .4byte  0x25E34000
.L_060034C4:
    .4byte  0x25E4363C
.L_060034C8:
    .4byte  sym_060612AC
.L_060034CC:
    .4byte  0x25E40000
.L_060034D0:
    .4byte  0x25E407F0
