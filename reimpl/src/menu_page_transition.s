
    .section .text.FUN_0603B53C


    .global menu_page_transition
    .type menu_page_transition, @function
menu_page_transition:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r4, r12
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0603B564, r13
    mov.l @r13, r13
    add #0x34, r13
    mov.l @(r0, r13), r0
    tst r0, r0
    bf/s    .L_page_exists
    mov #0x0, r11
    mov.l r11, @r12
    bra     .L_epilogue
    mov r11, r14
    .4byte  sym_0603F9F2
    .4byte  sym_0603F9F6
.L_pool_0603B564:
    .4byte  sym_060A4D14
.L_page_exists:
    mov.l @r13, r2
    mov.l r2, @r12
    .byte   0xBF, 0x5A    /* bsr 0x0603B424 (external) */  ! call cmd_dispatch_main(r4=page_entry)
    mov r2, r4
    mov r0, r14
    tst r14, r14
    bf      .L_epilogue
    mov #0x60, r0
    mov.l @(r0, r13), r0
    tst r0, r0
    bf      .L_has_next_page
    mov.l r11, @r12
    bra     .L_epilogue
    mov r11, r14
.L_has_next_page:
    mov #0x1, r14
.L_epilogue:
    .byte   0xB1, 0xD9    /* bsr 0x0603B93C (external) */  ! call save_checksum_calc(r4=0)
    mov #0x0, r4
    mov r14, r0
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
