
    .section .text.FUN_0601198C


    .global split_screen_layout
    .type split_screen_layout, @function
split_screen_layout:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.w r7, @r15
    mov.l   .L_fn_swap_sign_ext, r12
    mov.l   .L_hud_record_base, r13
    mov.l   .L_hud_record_count, r14

    mov.l @r11, r4
    mov.w @r14, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0x8, r8
    jsr @r12
    add r10, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(4, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0xA, r8
    jsr @r12
    add r9, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(8, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0xC, r8
    jsr @r12
    add r10, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(12, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0xE, r8
    jsr @r12
    add r9, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(16, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0x10, r8
    jsr @r12
    add r10, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(20, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0x12, r8
    jsr @r12
    add r9, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(24, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0x14, r8
    jsr @r12
    add r10, r4
    mov.w r0, @r8

    mov.w @r14, r3
    mov.l @(28, r11), r4
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov r3, r8
    add #0x16, r8
    jsr @r12
    add r9, r4
    exts.w r0, r0
    mov.w r0, @r8


    mov.w @r14, r3
    mov.w @r15, r0
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.w r0, @(6, r3)

    mov.w @r14, r3
    mov #0x0, r0
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r3
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.b r0, @(4, r3)

    mov.w @r14, r3
    mov r3, r2
    shll2 r3
    shll r3
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov #0x1, r0
    mov.b r0, @(5, r3)

    mov.w @r14, r3
    add #0x1, r3
    mov.w r3, @r14
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_swap_sign_ext:
    .4byte  swap_sign_ext               /* extract int16 from 16.16 fixed-point */
.L_hud_record_base:
    .4byte  sym_060786CC                /* HUD record array base (24 bytes per entry) */
.L_hud_record_count:
    .4byte  sym_0605AAA0                /* HUD record count/index (16-bit) */
