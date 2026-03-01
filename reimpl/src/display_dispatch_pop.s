
    .section .text.FUN_060322B6


    .global display_dispatch_pop
    .type display_dispatch_pop, @function
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
    .4byte  0x00000000
    .4byte  0x00000001
    .4byte  0x00000002
    .4byte  0x00000003
    .4byte  0x00000004
    .4byte  0x00000005

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
    .4byte  sym_06082A24
.L_pool_06032300:
    .4byte  sym_06082A20
    .4byte  0xD0074408
    .4byte  0x0E4ED007
    .4byte  0x01EE6516
    .4byte  0x66166716
    .4byte  0xD0056202
    .4byte  0x35208B09
    .4byte  0xD002A023
    .4byte  0x0E160000
    .4byte  sym_060623B0
    .4byte  0x000002D8
    .4byte  sym_06082A20
    .4byte  0xA0D00009

    .global sym_06032334
sym_06032334:
    .4byte  loc_0603239C
    .4byte  loc_060323CC
    .4byte  display_cmd_vscroll
    .4byte  loc_0603237C
    .4byte  loc_060323F0
    .4byte  loc_06032404
    .4byte  loc_06032414
    .4byte  loc_06032424
    .4byte  loc_0603243C
    .4byte  loc_0603245C
    .4byte  loc_06032474
    .4byte  loc_0603248C
    .4byte  loc_060324A0
    .4byte  0x6163D002
    .4byte  0x4108001E
    .4byte  0x402B0009
    .4byte  sym_06032334
    .4byte  0xAFC70009

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
    .4byte  0x0000000E
.L_pool_06032394:
    .4byte  0x00000002
.L_pool_06032398:
    .4byte  0x00000001

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
