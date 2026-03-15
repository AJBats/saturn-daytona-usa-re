

    .section .text.FUN_06018EAC
    .global FUN_06018EAC
    .type FUN_06018EAC, @function

FUN_06018EAC:
    sts.l   pr, @-r15
    add     #-12, r15
    mov.l   .L_06018ED8, r3
    jsr     @r3
    mov     r15, r4
    mov     r15, r0
    mov     #31, r4
    mov.b   @r0, r0
    add     #12, r15
    extu.b  r0, r0
    lds.l   @r15+, pr
    and     r0, r4
    rts
    mov     r4, r0

    .global FUN_06018EC8
    .type FUN_06018EC8, @function

FUN_06018EC8:
    mov.w   .L_06018ED6, r4
    mov.l   .L_06018EDC, r2
    extu.b  r4, r3
    mov.b   r3, @r2
    mov.l   .L_06018EE0, r3
    rts
    mov.b   r4, @r3

    .align 1
.L_06018ED6:
    .word   0x00E0

    .align 2
.L_06018ED8:
    .4byte  FUN_060349C4
.L_06018EDC:
    .4byte  0x25B00217
.L_06018EE0:
    .4byte  0x25B00237
