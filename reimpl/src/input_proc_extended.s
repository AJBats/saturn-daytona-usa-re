
    .section .text.FUN_06035F04


    .global input_proc_extended
    .type input_proc_extended, @function
input_proc_extended:
    sts.l pr, @-r15
    mov r4, r1
    mov.l   .L_06035F38, r2
    mov.l   .L_06035F3C, r3
    jsr @r3
    mov #0xC, r0
    lds.l @r15+, pr
    rts
    nop

    .global sym_06035F16
sym_06035F16:
    mov.b @r4, r3
    mov.b r3, @r5
    mov.b @(1, r4), r0
    mov r0, r2
    mov.b r0, @(4, r5)
    mov.b @(2, r4), r0
    mov.b r0, @(5, r5)
    mov.b @(3, r4), r0
    mov.b r0, @(6, r5)
    mov.b @(4, r4), r0
    mov.b r0, @(7, r5)
    mov.l @(4, r4), r3
    mov.l   .L_06035F40, r2
    and r2, r3
    rts
    mov.l r3, @(8, r5)
    .2byte  0xFFFF
.L_06035F38:
    .4byte  sym_06063594                /* [HIGH] global extended input data buffer (12 bytes, BSS) */
.L_06035F3C:
    .4byte  sym_06035168                /* [HIGH] data copy function — memcpy-like (r0=count, r1=src, r2=dst) */
.L_06035F40:
    .4byte  0x00FFFFFF                  /* [HIGH] low 24-bit mask — strips peripheral ID from extension long */
