
    .section .text.FUN_0602E18A


    .global draw_priority_resolve
    .type draw_priority_resolve, @function
draw_priority_resolve:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD0, 0x07    /* mov.l .L_pool_0602E1B4, r0 */
    mov.l @r0, r0
    .byte   0xD1, 0x08    /* mov.l .L_pool_0602E1BC, r1 */
    mov.l @(r0, r1), r3
    .byte   0xD1, 0x08    /* mov.l .L_pool_0602E1C0, r1 */
    cmp/ge r1, r3
    bf      .L_0602E1C4
    .byte   0xA0, 0xFD    /* bra 0x0602E3A0 (external) */
    nop
    .2byte  0x0000
    .4byte  sym_0608325C
    .4byte  sym_0602EC54
    .4byte  sym_06083258
.L_pool_0602E1B4:
    .4byte  sym_0607E940
    .4byte  sym_0600DB64
.L_pool_0602E1BC:
    .4byte  0x00000244
.L_pool_0602E1C0:
    .4byte  0x00000007
.L_0602E1C4:
    .byte   0xD3, 0x34    /* mov.l _pool_pipeline_counter, r3 */
    mov.l @r3, r3
    .byte   0xD1, 0x34    /* mov.l _pool_const_one, r1 */
    sub r1, r3
    .byte   0xD4, 0x34    /* mov.l _pool_const_40, r4 */
    cmp/eq r3, r4
    bf      .L_0602E1F8
    .byte   0x91, 0x57    /* mov.w .L_wpool_0602E284, r1 */
    mov.l @(r0, r1), r3
    .byte   0x92, 0x56    /* mov.w .L_wpool_0602E286, r2 */
    not r2, r2
    and r2, r3
    .byte   0x92, 0x54    /* mov.w .L_wpool_0602E288, r2 */
    not r2, r2
    and r2, r3
    .byte   0x92, 0x52    /* mov.w .L_wpool_0602E28A, r2 */
    not r2, r2
    and r2, r3
    .byte   0x92, 0x50    /* mov.w .L_wpool_0602E28C, r2 */
    not r2, r2
    and r2, r3
    mov.l r3, @(r0, r1)
    .byte   0xD1, 0x29    /* mov.l _pool_pipeline_counter, r1 */
    mov.l @r1, r3
    .byte   0xD2, 0x29    /* mov.l _pool_const_one, r2 */
    sub r2, r3
.L_0602E1F8:
    .byte   0xD1, 0x27    /* mov.l _pool_pipeline_counter, r1 */
    mov.l r3, @r1
    .byte   0x91, 0x47    /* mov.w .L_wpool_0602E28E, r1 */
    mov.l @(r0, r1), r3
    .byte   0xD2, 0x28    /* mov.l _pool_const_zero, r2 */
    cmp/eq r2, r3
    bt      .L_0602E20C
    .byte   0xD2, 0x25    /* mov.l _pool_const_one, r2 */
    sub r2, r3
    mov.l r3, @(r0, r1)
.L_0602E20C:
    .byte   0xD3, 0x25    /* mov.l _pool_const_zero, r3 */
    .byte   0xD1, 0x26    /* mov.l _pool_clear_field_off, r1 */
    mov.l r3, @(r0, r1)
    .byte   0xDD, 0x26    /* mov.l _pool_next_dispatch, r13 */
