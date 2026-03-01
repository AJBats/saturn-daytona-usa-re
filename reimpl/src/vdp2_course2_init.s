
    .section .text.FUN_06003508


    .global vdp2_course2_init
    .type vdp2_course2_init, @function
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
    .2byte  0x00E0
.L_0600353E:
    .2byte  0x2000
.L_06003540:
    .2byte  0x0100
    .2byte  0xFFFF
    .4byte  0x25F00860
.L_06003548:
    .4byte  0x25F00200
.L_0600354C:
    .4byte  memcpy_word_idx
.L_06003550:
    .4byte  dma_memory_transfer
.L_06003554:
    .4byte  0x25E34000
    .4byte  0x25E497E4
.L_0600355C:
    .4byte  sym_060612AC
    .4byte  0x25E4108C
    .4byte  0x25E41A24
.L_06003568:
    .4byte  0x25F00940
.L_0600356C:
    .4byte  0x25E4EFEC
.L_06003570:
    .4byte  0x25E42300
.L_06003574:
    .4byte  0x25E42C78
