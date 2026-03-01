
    .section .text.FUN_06005DD4


    .global anim_frame_transform
    .type anim_frame_transform, @function
anim_frame_transform:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    add #-0x8, r15
    mov.l   .L_pool_digit_buf, r5
    mov.l r4, @r15
    mov #0xA, r12
    mov.w   .L_divu_DVDNT, r14
    mov r14, r7
    add #0x4, r7
    mov.w   .L_divu_DVSR, r6
    mov #0x0, r4

    mov.l r12, @r6
    mov.l r4, @r7
    mov.l @r15, r3
    mov.l r3, @r14
    extu.b r4, r0
    mov.b r0, @(8, r5)
    mov.w   .L_divu_DVDNTH_S, r13
    mov.l @r13, r3
    extu.b r3, r3
    mov.b r3, @r15
    mov.w   .L_divu_DVDNTL_S, r1
    mov.l @r1, r2
    mov.l r2, @(4, r15)

    mov.l r12, @r6
    mov.l r4, @r7
    mov.l @(4, r15), r3
    mov.l r3, @r14
    mov.b @r15, r3
    extu.b r3, r3
    add #0x1, r3
    extu.b r3, r0
    mov.b r0, @(7, r5)
    mov.l @r13, r3
    extu.b r3, r3
    mov.b r3, @r15
    mov.l @r1, r2
    mov.l r2, @(4, r15)

    mov.l r12, @r6
    mov.l r4, @r7
    mov.l @(4, r15), r3
    mov.l r3, @r14
    mov.b @r15, r3
    extu.b r3, r3
    add #0x1, r3
    extu.b r3, r0
    mov.b r0, @(6, r5)
    mov.l @r13, r3
    extu.b r3, r3
    mov.b r3, @r15
    mov.l @r1, r2
    mov.l r2, @(4, r15)

    mov #0x6, r2
    mov.l r2, @r6
    mov.l r4, @r7
    mov.l @(4, r15), r3
    mov.l r3, @r14
    mov #0xD, r3
    mov r3, r0
    mov.b r0, @(5, r5)
    mov.b @r15, r3
    extu.b r3, r3
    add #0x1, r3
    extu.b r3, r0
    mov.b r0, @(4, r5)
    mov.l @r13, r3
    extu.b r3, r3
    mov r3, r0
    mov.b r0, @(4, r15)
    mov.l @r1, r2
    mov.l r2, @r15

    mov.l r12, @r6
    mov.l r4, @r7
    mov.l @r15, r3
    mov.l r3, @r14
    mov.b @(4, r15), r0
    mov r0, r3
    extu.b r3, r3
    add #0x1, r3
    extu.b r3, r0
    mov.b r0, @(3, r5)
    mov.l @r13, r3
    extu.b r3, r3
    mov.b r3, @r15
    mov.l @r1, r2
    mov.l r2, @(4, r15)

    mov.l r12, @r6
    mov.l r4, @r7
    mov.l @(4, r15), r3
    mov.l r3, @r14
    mov #0xC, r3
    mov r3, r0
    mov.b r0, @(2, r5)
    mov.b @r15, r3
    extu.b r3, r3
    add #0x1, r3
    extu.b r3, r3
    mov r3, r0
    mov.b r0, @(1, r5)
    mov.l @r13, r4
    extu.b r4, r4
    tst r4, r4
    bt      .L_tens_min_blank
    extu.b r4, r3
    add #0x1, r3
    extu.b r3, r4
    bra     .L_store_tens_min
    nop

.L_divu_DVDNT:
    .2byte  0xFF04                  /* 0xFFFFFF04 = DVDNT — dividend reg, triggers 32/32 div [HIGH] */
.L_divu_DVSR:
    .2byte  0xFF00                  /* 0xFFFFFF00 = DVSR — divisor register [HIGH] */
.L_divu_DVDNTH_S:
    .2byte  0xFF18                  /* 0xFFFFFF18 = DVDNTH_S — remainder after 32/32 division [HIGH] */
.L_divu_DVDNTL_S:
    .2byte  0xFF1C                  /* 0xFFFFFF1C = DVDNTL_S — quotient after 32/32 division [HIGH] */
    .2byte  0xFFFF                  /* pool alignment padding */

.L_pool_digit_buf:
    .4byte  sym_06063E14            /* &digit_buffer — 9-byte HUD time display buffer [HIGH] */

.L_tens_min_blank:
    mov #0xB, r4
.L_store_tens_min:
    mov r5, r0
    mov.b r4, @r5
    add #0x8, r15
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
