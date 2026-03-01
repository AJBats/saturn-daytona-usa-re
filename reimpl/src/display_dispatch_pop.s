
    .section .text.FUN_060322B6


    .global display_dispatch_pop
    .type display_dispatch_pop, @function
display_dispatch_pop:
    sts.l pr, @-r15
    bsr     check_cmd_state
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

check_cmd_state:
    .byte   0xD0, 0x04    /* mov.l _pool_cmd_state_byte, r0 */
    mov.b @r0, r1
    tst r1, r1
    bt      .L_cmd_state_zero
    .byte   0xD0, 0x03    /* mov.l _pool_cmd_counter, r0 */
    mov.l @r0, r1
    add #0x1, r1
    mov.l r1, @r0
.L_cmd_state_zero:
    rts
    nop
_pool_cmd_state_byte:
    .4byte  sym_06082A24
_pool_cmd_counter:
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
    .byte   0xD0, 0x04    /* mov.l _pool_ctrl_word_offset_a, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x04    /* mov.l _pool_hscroll_set_bit, r2 */
    or r2, r1
    .byte   0xD2, 0x04    /* mov.l _pool_vscroll_clear_bit, r2 */
    not r2, r2
    and r2, r1
    mov.w r1, @(r0, r14)
    bra     .L_check_element_idx
    nop
_pool_ctrl_word_offset_a:
    .4byte  0x0000000E
_pool_hscroll_set_bit:
    .4byte  0x00000002
_pool_vscroll_clear_bit:
    .4byte  0x00000001

    .global loc_0603239C
loc_0603239C:
    .byte   0xD0, 0x08    /* mov.l _pool_ctrl_word_offset_b, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x08    /* mov.l _pool_hscroll_clear_bit, r2 */
    not r2, r2
    and r2, r1
    mov.w r1, @(r0, r14)

.L_check_element_idx:
    .byte   0xD0, 0x07    /* mov.l _pool_element_idx_offset, r0 */
    mov.l @(r0, r14), r2
    cmp/eq r7, r2
    .byte   0x89, 0x04    /* bt 0x060323BA (external) */
    mov r7, r4
