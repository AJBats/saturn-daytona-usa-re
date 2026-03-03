	.text
    .global display_dispatch_pop
display_dispatch_pop:
    sts.l pr, @-r15
    bsr     .L_060322E8
    nop
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .long  0x00000000
    .long  0x00000001
    .long  0x00000002
    .long  0x00000003
    .long  0x00000004
    .long  0x00000005

.L_060322E8:
    .byte   0xD0, 0x04    /* mov.l .L_pool_060322FC, r0 */
    mov.b @r0, r1
    tst r1, r1
    bt      .L_060322F8
    .byte   0xD0, 0x03    /* mov.l .L_pool_06032300, r0 */
    mov.l @r0, r1
    add #0x1, r1
    mov.l r1, @r0
.L_060322F8:
    rts
    nop
.L_pool_060322FC:
    .long  sym_06082A24
.L_pool_06032300:
    .long  sym_06082A20
    .long  0xD0074408
    .long  0x0E4ED007
    .long  0x01EE6516
    .long  0x66166716
    .long  0xD0056202
    .long  0x35208B09
    .long  0xD002A023
    .long  0x0E160000
    .long  sym_060623B0
    .long  0x000002D8
    .long  sym_06082A20
    .long  0xA0D00009

    .global sym_06032334
sym_06032334:
    .long  loc_0603239C
    .long  loc_060323CC
    .long  display_cmd_vscroll
    .long  loc_0603237C
    .long  loc_060323F0
    .long  loc_06032404
    .long  loc_06032414
    .long  loc_06032424
    .long  loc_0603243C
    .long  loc_0603245C
    .long  loc_06032474
    .long  loc_0603248C
    .long  loc_060324A0
    .long  0x6163D002
    .long  0x4108001E
    .long  0x402B0009
    .long  sym_06032334
    .long  0xAFC70009

    .global loc_0603237C
loc_0603237C:
    .byte   0xD0, 0x04    /* mov.l .L_pool_06032390, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x04    /* mov.l .L_pool_06032394, r2 */
    or r2, r1
    .byte   0xD2, 0x04    /* mov.l .L_pool_06032398, r2 */
    not r2, r2
    and r2, r1
    mov.w r1, @(r0, r14)
    bra     .L_060323A8
    nop
.L_pool_06032390:
    .long  0x0000000E
.L_pool_06032394:
    .long  0x00000002
.L_pool_06032398:
    .long  0x00000001

    .global loc_0603239C
loc_0603239C:
    .byte   0xD0, 0x08    /* mov.l .L_pool_060323C0, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x08    /* mov.l .L_pool_060323C4, r2 */
    not r2, r2
    and r2, r1
    mov.w r1, @(r0, r14)

.L_060323A8:
    .byte   0xD0, 0x07    /* mov.l .L_pool_060323C8, r0 */
    mov.l @(r0, r14), r2
    cmp/eq r7, r2
    .byte   0x89, 0x04    /* bt 0x060323BA (external) */
    mov r7, r4
