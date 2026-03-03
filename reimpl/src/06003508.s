	.text
    .global vdp2_course2_init
vdp2_course2_init:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.w   .L_06003540, r6
    mov.l   .L_06003568, r5
    mov.l   .L_06003548, r4
    mov.l   .L_0600354C, r3
    jsr @r3
    nop
    mov.l   .L_06003550, r14
    mov.l   .L_06003554, r5
    mov.l   .L_0600356C, r4
    jsr @r14
    nop
    mov.l   .L_0600355C, r5
    mov.l   .L_06003570, r4
    jsr @r14
    mov.l @r5, r5
    mov.l   .L_0600355C, r5
    mov.w   .L_0600353E, r2
    mov.l   .L_06003574, r4
    mov.l @r5, r5
    jsr @r14
    add r2, r5
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0x00E0
.L_0600353E:
    .short  0x2000
.L_06003540:
    .short  0x0100
    .short  0xFFFF
    .long  0x25F00860
.L_06003548:
    .long  0x25F00200
.L_0600354C:
    .long  memcpy_word_idx
.L_06003550:
    .long  dma_memory_transfer
.L_06003554:
    .long  0x25E34000
    .long  0x25E497E4
.L_0600355C:
    .long  sym_060612AC
    .long  0x25E4108C
    .long  0x25E41A24
.L_06003568:
    .long  0x25F00940
.L_0600356C:
    .long  0x25E4EFEC
.L_06003570:
    .long  0x25E42300
.L_06003574:
    .long  0x25E42C78
