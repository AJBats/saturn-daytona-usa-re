
    .section .text.FUN_0601B644


    .global texture_file_loader
    .type texture_file_loader, @function
texture_file_loader:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l   .L_0601B6CC, r13
    mov.l   .L_0601B6D0, r14
    mov.l   .L_0601B6D4, r4
    mov.w   .L_0601B6C4, r2
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_0601B664
    mov #0x0, r5
    mov.l   .L_0601B6D8, r3
    bra     .L_0601B6BE
    mov.b r5, @r3
.L_0601B664:
    mov.w @(2, r4), r0
    mov.w   .L_0601B6C6, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601B692
    mov.b @r14, r3
    add #0x5, r3
    mov.b r3, @r14
    mov #0x14, r3
    mov.b @r14, r2
    cmp/ge r3, r2
    bf      .L_0601B684
    exts.b r5, r5
    mov.b r5, @r14
.L_0601B684:
    mov.b @r14, r6
    mov.b @(1, r13), r0
    mov r0, r5
    mov.b @r13, r4
    mov.l @r15+, r13
    .byte   0xA1, 0xDF    /* bra 0x0601BA50 (external) */
    mov.l @r15+, r14
.L_0601B692:
    mov.w @(2, r4), r0
    mov.w   .L_0601B6C8, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601B6BE
    mov.b @r14, r3
    add #-0x5, r3
    mov.b r3, @r14
    mov.b @r14, r2
    cmp/pz r2
    bt      .L_0601B6B0
    mov #0xF, r2
    mov.b r2, @r14
.L_0601B6B0:
    mov.b @r14, r6
    mov.b @(1, r13), r0
    mov r0, r5
    mov.b @r13, r4
    mov.l @r15+, r13
    .byte   0xA1, 0xC9    /* bra 0x0601BA50 (external) */
    mov.l @r15+, r14
.L_0601B6BE:
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601B6C4:
    .2byte  0x0F00                              /* bits 8-11: D-pad / abort button mask */
.L_0601B6C6:
    .2byte  0x2000                              /* bit 13: file index increment button */
.L_0601B6C8:
    .2byte  0x1000                              /* bit 12: file index decrement button */
    .2byte  0xFFFF                              /* alignment padding */
.L_0601B6CC:
    .4byte  sym_0605D4F4                        /* scroll parameter base (+0=A, +1=B) */
.L_0601B6D0:
    .4byte  sym_0605D4FA                        /* texture file index / course state A */
.L_0601B6D4:
    .4byte  g_pad_state                        /* input button state struct (+2=flags) */
.L_0601B6D8:
    .4byte  sym_0608600D                        /* course state flag B (cleared on abort) */
