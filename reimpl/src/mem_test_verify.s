
    .section .text.FUN_0604053A


    .global mem_test_verify
    .type mem_test_verify, @function
mem_test_verify:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    .byte   0xDE, 0x19    /* mov.l .L_pool_060405AD, r14 */  ! r14 = &sym_060A4D14 (global state pointer)
    tst r5, r5
    bt/s    .L_check_boundary
    mov.l @(24, r4), r13
    mov #0x0, r1
    mov.w   .L_validation_counter_offset, r0
    mov r15, r4
    mov.l @r14, r3
    mov r3, r2
    mov.l r1, @(r0, r2)
    mov r1, r2
    add #-0x4, r0
    mov #0x3, r2
    mov.l r1, @(r0, r3)
    mov r15, r3
    add #0x4, r3
    mov.l r2, @r3
    mov.l @(40, r13), r5
    .byte   0xD3, 0x11    /* mov.l .L_fn_ai_section_check, r3 */  ! r3 = &ai_section_check
    jsr @r3
    add #0x4, r4
.L_check_boundary:
    .byte   0xD3, 0x10    /* mov.l .L_fn_evt_boundary_active, r3 */  ! r3 = &sym_06041014 (boundary active check)
    jsr @r3
    mov.l @(40, r13), r4
    tst r0, r0
    bt      .L_epilogue
    .byte   0xD3, 0x0F    /* mov.l .L_fn_evt_boundary_release, r3 */  ! r3 = &sym_06040FEA (release lock)
    jsr @r3
    mov.l @(40, r13), r4
    mov #0x0, r5
    .byte   0xB0, 0x1B    /* bsr 0x060405B8 (external) */  ! evt_validate_multi(r4=&stack_buf, r5=0)
    mov r15, r4
    mov.l @r14, r2
    mov.w   .L_validation_counter_offset, r0
    mov.l @(r0, r2), r3
    mov.l @r15, r2
    cmp/gt r2, r3
    bt      .L_epilogue
    mov.l @r14, r2
    mov r2, r3
    mov.w   .L_validation_counter_offset, r0
    mov.l @(r0, r3), r1
    add #-0x4, r0
    mov.l r1, @(r0, r2)
.L_epilogue:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_validation_counter_offset:
    .2byte  0x00B0                           /* [HIGH] offset to validation counter in state struct */
    .2byte  0xFFFF                           /* alignment padding */
.L_pool_060405AD:
    .4byte  sym_060A4D14
.L_fn_ai_section_check:
    .4byte  ai_section_check
.L_fn_evt_boundary_active:
    .4byte  sym_06041014
.L_fn_evt_boundary_release:
    .4byte  sym_06040FEA
