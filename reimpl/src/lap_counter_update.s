
    .section .text.FUN_060158DE


    .global lap_counter_update
    .type lap_counter_update, @function
lap_counter_update:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD0, 0x15    /* mov.l .L_0601593C, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt/s    .L_060158F8
    mov #0x1, r4
    exts.w r4, r4
    .byte   0xD3, 0x13    /* mov.l .L_06015940, r3 */
    mov.w r4, @r3
    bra     .L_06015926
    nop
.L_060158F8:
    mov.b @r15, r2
    extu.b r4, r0
    .byte   0xD1, 0x0D    /* mov.l .L_06015934, r1 */
    extu.b r2, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r1, r2
    mov.b r0, @(1, r2)
    .byte   0xD5, 0x0C    /* mov.l .L_06015944, r5 */
    mov.w   .L_06015932, r0
    .byte   0xD3, 0x0C    /* mov.l .L_06015948, r3 */
    .byte   0xD2, 0x0C    /* mov.l .L_0601594C, r2 */
    mov.l @(r0, r5), r5
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r2
    mov #0x0, r4
.L_06015926:
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xD3, 0x08    /* mov.l .L_06015950, r3 */
    jmp @r3
    lds.l @r15+, pr
.L_06015932:
    .2byte  0x0224                      /* car struct offset: sound ID for this car */
.L_06015934:
    .4byte  sym_06084FC8               /* base of lap slot array (20 bytes per car) */
    .4byte  sym_0605B8A4               /* (adjacent data) */
.L_0601593C:
    .4byte  sym_0607EAE0               /* race end flag (32-bit, nonzero = ended) */
.L_06015940:
    .4byte  sym_06085F94               /* final lap completion flag (16-bit) */
.L_06015944:
    .4byte  sym_06078900               /* car struct array base */
.L_06015948:
    .4byte  sym_06044BD8               /* lap completion sound table (4 bytes per entry) */
.L_0601594C:
    .4byte  sound_cmd_dispatch         /* sound command dispatch */
.L_06015950:
    .4byte  sym_060172E4               /* lap display handler */
