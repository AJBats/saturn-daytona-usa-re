
    .section .text.FUN_0601FE20


    .global geom_display_handler
    .type geom_display_handler, @function
geom_display_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_0601FE98, r9
    mov.l   .L_0601FE9C, r10
    mov.l   .L_0601FEA0, r11
    mov.w   .L_0601FE96, r12
    mov.l   .L_0601FEA4, r14
    mov.l   .L_0601FEA8, r2
    mov.l @r14, r14
    mov.l @(4, r14), r3
    mov.l r3, @r2
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r11
    mov.l   .L_0601FEAC, r3
    jsr @r3
    mov.l @(8, r14), r4
    mov.l @(12, r14), r13
    mov #0x0, r4
    extu.w r4, r2
    mov.l   .L_0601FEB0, r3
    mov.w r2, @r3
    extu.w r4, r1
    mov.l   .L_0601FEB4, r3
    mov.w r1, @r3
    bra     .L_0601FE72
    mov r4, r14
.L_0601FE62:
    mul.l r12, r14
    sts macl, r2
    add r10, r2
    mov.l r2, @r9
    .byte   0xB0, 0x29    /* bsr 0x0601FEC0 (external) */
    mov r13, r4
    add #0x8, r13
    add #0x1, r14
.L_0601FE72:
    mov.l @r11, r2
    cmp/hi r2, r14
    bf      .L_0601FE62
    mov.l   .L_0601FEB8, r3
    jsr @r3
    nop
    mov #0x2, r2
    mov.l   .L_0601FEBC, r3
    mov.w r2, @r3
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601FE96:
    .2byte  0x0268                         /* car struct stride (616 bytes) */
.L_0601FE98:
    .4byte  sym_0607E940                   /* &current_car_ptr (active car) */
.L_0601FE9C:
    .4byte  sym_06078900                   /* car struct array base address */
.L_0601FEA0:
    .4byte  sym_0607EA98                   /* &car_count_store (loop bound) */
.L_0601FEA4:
    .4byte  sym_060877F4                   /* &display_list_desc_ptr (indirect) */
.L_0601FEA8:
    .4byte  sym_060877FC                   /* &display_data_word (from descriptor) */
.L_0601FEAC:
    .4byte  sym_060054EA                   /* obj_list_state_reset function */
.L_0601FEB0:
    .4byte  sym_06087800                   /* entry count (16-bit) */
.L_0601FEB4:
    .4byte  sym_06087802                   /* iteration counter (16-bit) */
.L_0601FEB8:
    .4byte  sym_0600D280                   /* car_ptr_list_init function */
.L_0601FEBC:
    .4byte  sym_06087804                   /* handler mode (16-bit) */
