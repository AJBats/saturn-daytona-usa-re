
    .section .text.FUN_06036AF8


    .global shadow_color_alpha
    .type shadow_color_alpha, @function
shadow_color_alpha:
    sts.l pr, @-r15
    mov r5, r13
    add #-0x14, r15
    mov r15, r4
    mov.l   .L_pool_06036B38, r3
    jsr @r3
    add #0xC, r4
    mov r15, r2
    mov #0x73, r3
    mov r15, r6
    mov r15, r5
    add #0xC, r2
    add #0x4, r6
    add #0xC, r5
    mov.b r3, @r2
    mov r15, r2
    mov r15, r3
    add #0xC, r2
    add #0xC, r3
    mov.l r14, @(4, r2)
    mov #0x0, r2
    mov r2, r0
    mov.b r0, @(4, r3)
    mov.l   .L_pool_06036B3C, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    tst r4, r4
    bt      .L_digital_zero
    bra     .L_epilogue
    mov r4, r0
    .2byte  0xFFFF
.L_pool_06036B38:
    .4byte  input_proc_analog
.L_pool_06036B3C:
    .4byte  input_proc_digital
.L_pool_06036B40:
    .4byte  0x00FFFFFF
.L_digital_zero:
    mov r15, r3
    mov r13, r5
    add #0x4, r3
    mov.l @r3, r2
    .byte   0xD3, 0x20    /* mov.l .L_pool_06036BD0, r3 */  ! r3 = 0x00FFFFFF (RGB mask, cross-TU pool)
    and r3, r2
    mov.l r2, @r15
    .byte   0xD3, 0x20    /* mov.l .L_pool_06036BD4, r3 */  ! r3 = cross-TU dispatch function address
    jsr @r3
    mov r2, r4
    mov r0, r4
.L_epilogue:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
