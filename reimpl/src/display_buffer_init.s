
    .section .text.FUN_06036DDC


    .global display_buffer_init
    .type display_buffer_init, @function
display_buffer_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov #0x0, r14
    mov r4, r7
    mov r5, r13
    bra     .L_copy_test
    mov r14, r5
.L_copy_byte:
    mov r7, r2
    add #0x1, r7
    mov.b @r13+, r1
    mov.b r1, @r2
    add #0x1, r5
.L_copy_test:
    cmp/hs r6, r5
    bt      .L_pad_check
    mov.b @r13, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_copy_byte
.L_pad_check:
    cmp/hs r6, r5
    bt      .L_done
.L_pad_loop:
    extu.b r14, r3
    add #0x1, r5
    mov.b r3, @r7
    cmp/hs r6, r5
    bf/s    .L_pad_loop
    add #0x1, r7
.L_done:
    mov r4, r0
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .4byte  0x2F362F46
