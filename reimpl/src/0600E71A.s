	.text
    .global FUN_0600E71A
FUN_0600E71A:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    .byte   0xDE, 0x21    /* mov.l .L_0600E7A8, r14 */
    .byte   0xD3, 0x22    /* mov.l .L_0600E7AC, r3 */
    jsr @r3
    mov.l @r14, r14
    .byte   0xD3, 0x21    /* mov.l .L_0600E7B0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x21    /* mov.l .L_0600E7B4, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_0600E7B8, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_0600E7BC, r3 */
    jsr @r3
    nop
    mov.w   DAT_0600e79c, r0
    mov.l @(r0, r14), r2
    cmp/pl r2
    bf      .L_0600E778
    mov.w   DAT_0600e79c, r0
    mov.l @(r0, r14), r2
    add #-0x1, r2
    mov.l r2, @(r0, r14)
    tst r2, r2
    bf      .L_0600E778
    mov.w   DAT_0600e79e, r0
    mov.l @(r0, r14), r4
    mov r4, r3
    shll2 r4
    shll r4
    shll2 r3
    shll2 r3
    add r3, r4
    add #-0x4, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w   .L_0600E7A0, r0
    mov.l r3, @(r0, r14)
    mov.w   .L_0600E7A2, r3
    add #0xC, r0
    mov.l r3, @(r0, r14)
.L_0600E778:
    .byte   0xD3, 0x11    /* mov.l .L_0600E7C0, r3 */
    jsr @r3
    nop
    mov.w   .L_0600E7A4, r0
    .byte   0xD3, 0x10    /* mov.l .L_0600E7C4, r3 */
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    mov.l r2, @(r0, r14)
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600e79c
DAT_0600e79c:
    .short  0x0208

    .global DAT_0600e79e
DAT_0600e79e:
    .short  0x01E4
.L_0600E7A0:
    .short  0x01F8
.L_0600E7A2:
    .short  0x0400
.L_0600E7A4:
    .short  0x0228
    .short  0xFFFF
.L_0600E7A8:
    .long  sym_0607E940
.L_0600E7AC:
    .long  FUN_06008318
.L_0600E7B0:
    .long  sym_06008640
.L_0600E7B4:
    .long  FUN_0600D26A
.L_0600E7B8:
    .long  FUN_0600C4F8
.L_0600E7BC:
    .long  FUN_0600C5D6
.L_0600E7C0:
    .long  FUN_0600CEBA
.L_0600E7C4:
    .long  sym_0607EA9C
