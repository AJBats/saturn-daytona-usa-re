
    .section .text.FUN_06005120


    .global hw_render_dispatch
    .type hw_render_dispatch, @function
hw_render_dispatch:
    mov.l r14, @-r15
    and r7, r3
    add #-0x8, r15
    mov.l r4, @r15
    mov.l r6, @(4, r15)
    tst r3, r3
    bf      .L_06005134
    mov.l   .L_06005164, r14
    bra     .L_06005136
    nop
.L_06005134:
    mov.l   .L_06005168, r14
.L_06005136:
    mov #0x8, r2
    and r2, r7
    tst r7, r7
    bt/s    .L_0600514C
    add r5, r14
    mov r14, r5
    mov.l @r15, r4
    add #0x8, r15
    mov.l   .L_0600516C, r3
    jmp @r3
    mov.l @r15+, r14
.L_0600514C:
    mov.l @(4, r15), r6
    mov.l @r15, r5
    mov r14, r4
    add #0x8, r15
    mov.l   .L_06005170, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF                          /* padding to align constant pool */
    .4byte  sym_06063750                    /* car object table base (cross-TU pool ref) */
    .4byte  sym_06059F10                    /* display state table (cross-TU pool ref) */
.L_06005164:
    .4byte  0x25E00000                      /* VDP2 VRAM bank 0 base address */
.L_06005168:
    .4byte  0x25E20000                      /* VDP2 VRAM bank 1 base address (+0x20000) */
.L_0600516C:
    .4byte  dma_memory_transfer             /* hardware DMA transfer function */
.L_06005170:
    .4byte  memcpy_long_idx                 /* CPU long-word indexed copy function */

    .global sym_06005174
sym_06005174:
    .byte   0xD5, 0x2A    /* mov.l .L_pool_06005220, r5 */
    mov #0x0, r4
    mov.w r4, @r5
    extu.w r4, r0
    mov.w r0, @(2, r5)
    extu.w r4, r0
    mov.w r0, @(4, r5)
    extu.w r4, r0
    mov.w r0, @(6, r5)
    add #0x8, r5
    extu.w r4, r0
    mov.w r4, @r5
    mov.w r0, @(2, r5)
    extu.w r4, r0
    mov.w r0, @(4, r5)
    extu.w r4, r0
    rts
    mov.w r0, @(6, r5)
