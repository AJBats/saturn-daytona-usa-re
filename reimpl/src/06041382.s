	.text
    .global error_trap_handler
error_trap_handler:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xDE, 0x1A    /* mov.l .L_pool_060413F5, r14 */
    mov.l @r14, r3
    add #0x18, r3
    mov.l r3, @(4, r15)
    add r4, r3
    mov.b @r3, r3
    tst r3, r3
    bt      .L_060413A2
    mov.l @(4, r15), r3
    add r5, r3
    mov.b @r3, r3
    tst r3, r3
    bf      .L_060413AC
.L_060413A2:
    mov #-0x7, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060413AC:
    mov.l @r14, r3
    mov.w   .L_060413EE, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_060413C0
    mov #-0x1, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060413C0:
    mov.l @r14, r3
    mov #0x1, r2
    mov.w   .L_060413EE, r0
    mov.l r2, @(r0, r3)
    mov.l @r14, r3
    add #0x4, r0
    mov.l r4, @(r0, r3)
    add #0x4, r0
    mov.l @r14, r3
    mov.l r5, @(r0, r3)
    mov.l @r14, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
    add #0x4, r0
    mov.l @r14, r3
    mov.l r7, @(r0, r3)
    .byte   0xB5, 0x82    /* bsr 0x06041EE8 (external) */
    mov r15, r4
    mov #0x0, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_060413EE:
    .short  0x0348
    .long  ai_recovery_handler
.L_pool_060413F5:
    .long  sym_060A5400
    .long  0xD3149026
    .long  0x6332003E
    .long  0x20088901
    .long  0x000BE000
    .long  0xE001000B
    .short  0x0009
