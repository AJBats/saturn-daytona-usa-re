
    .section .text.FUN_060191E4


    .global transition_multi_step
    .type transition_multi_step, @function
transition_multi_step:
    sts.l pr, @-r15
    mov.l   .L_06019224, r14
    mov.l   .L_06019228, r2
    mov.l r3, @r2
    mov.l   .L_0601922C, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_06019230, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0x76    /* bsr 0x060192E8 (external) */
    nop
    mov.l   .L_06019228, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06019216
    mov.l   .L_06019234, r6
    mov.l   .L_06019238, r5
    mov.l   .L_0601923C, r4
    mov.l   .L_06019240, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_06019244, r3
    mov.w r2, @r3
.L_06019216:
    mov.l   .L_0601922C, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_06019224:
    .4byte  sound_cmd_dispatch
.L_06019228:
    .4byte  sym_06086050
.L_0601922C:
    .4byte  0xAE0001FF
.L_06019230:
    .4byte  0xAE0005FF
.L_06019234:
    .4byte  0x0006D000
.L_06019238:
    .4byte  0x00200000
.L_0601923C:
    .4byte  0x25A03000
.L_06019240:
    .4byte  memcpy_byte_idx
.L_06019244:
    .4byte  0x25A02DBE
