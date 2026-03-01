
    .section .text.FUN_0602E18A


    .global draw_priority_resolve
    .type draw_priority_resolve, @function
draw_priority_resolve:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD0, 0x07    /* mov.l _pool_car_struct_ptr, r0 */  ! r0 = &car_struct_ptr (sym_0607E940)
    mov.l @r0, r0
    .byte   0xD1, 0x08    /* mov.l _pool_priority_field_off, r1 */  ! r1 = 0x0244 (priority count offset)
    mov.l @(r0, r1), r3
    .byte   0xD1, 0x08    /* mov.l _pool_priority_threshold, r1 */  ! r1 = 7 (priority count threshold)
    cmp/ge r1, r3
    bf      .L_below_threshold
    .byte   0xA0, 0xFD    /* bra 0x0602E3A0 (external) */  ! else jump to high-priority continuation
    nop
    .2byte  0x0000
    .4byte  sym_0608325C
    .4byte  sym_0602EC54
    .4byte  sym_06083258
_pool_car_struct_ptr:
    .4byte  sym_0607E940
    .4byte  sym_0600DB64
_pool_priority_field_off:
    .4byte  0x00000244
_pool_priority_threshold:
    .4byte  0x00000007
.L_below_threshold:
    .byte   0xD3, 0x34    /* mov.l _pool_pipeline_counter, r3 */  ! r3 = &pipeline_counter (sym_0607EAC8)
    mov.l @r3, r3
    .byte   0xD1, 0x34    /* mov.l _pool_const_one, r1 */  ! r1 = 1
    sub r1, r3
    .byte   0xD4, 0x34    /* mov.l _pool_const_40, r4 */  ! r4 = 0x28 (40)
    cmp/eq r3, r4
    bf      .L_store_counter
    .byte   0x91, 0x57    /* mov.w .L_wpool_0602E284, r1 */  ! r1 = 0x0214 (VDP priority field offset)
    mov.l @(r0, r1), r3
    .byte   0x92, 0x56    /* mov.w .L_wpool_0602E286, r2 */  ! r2 = 0x0088 (priority mask: bits 7,3)
    not r2, r2
    and r2, r3
    .byte   0x92, 0x54    /* mov.w .L_wpool_0602E288, r2 */  ! r2 = 0x0044 (priority mask: bits 6,2)
    not r2, r2
    and r2, r3
    .byte   0x92, 0x52    /* mov.w .L_wpool_0602E28A, r2 */  ! r2 = 0x0022 (priority mask: bits 5,1)
    not r2, r2
    and r2, r3
    .byte   0x92, 0x50    /* mov.w .L_wpool_0602E28C, r2 */  ! r2 = 0x0011 (priority mask: bits 4,0)
    not r2, r2
    and r2, r3
    mov.l r3, @(r0, r1)
    .byte   0xD1, 0x29    /* mov.l _pool_pipeline_counter, r1 */  ! r1 = &pipeline_counter (sym_0607EAC8)
    mov.l @r1, r3
    .byte   0xD2, 0x29    /* mov.l _pool_const_one, r2 */  ! r2 = 1
    sub r2, r3
.L_store_counter:
    .byte   0xD1, 0x27    /* mov.l _pool_pipeline_counter, r1 */  ! r1 = &pipeline_counter (sym_0607EAC8)
    mov.l r3, @r1
    .byte   0x91, 0x47    /* mov.w .L_wpool_0602E28E, r1 */  ! r1 = 0x0208 (effect countdown offset)
    mov.l @(r0, r1), r3
    .byte   0xD2, 0x28    /* mov.l _pool_const_zero, r2 */  ! r2 = 0
    cmp/eq r2, r3
    bt      .L_clear_and_chain
    .byte   0xD2, 0x25    /* mov.l _pool_const_one, r2 */  ! r2 = 1
    sub r2, r3
    mov.l r3, @(r0, r1)
.L_clear_and_chain:
    .byte   0xD3, 0x25    /* mov.l _pool_const_zero, r3 */  ! r3 = 0
    .byte   0xD1, 0x26    /* mov.l _pool_clear_field_off, r1 */  ! r1 = 0xC0 (clear target offset)
    mov.l r3, @(r0, r1)
    .byte   0xDD, 0x26    /* mov.l _pool_next_dispatch, r13 */  ! r13 = damage_mac_core (next dispatch fn)
