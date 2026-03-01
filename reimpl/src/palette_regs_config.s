
    .section .text.FUN_06036E1C


    .global palette_regs_config
    .type palette_regs_config, @function
palette_regs_config:
    mov.l r5, @-r15
    mov.l @r0+, r3
    mov #0x0, r5
    mov.l @r1+, r4
.L_06036E24:
    cmp/str r5, r4
    bt      .L_06036E56
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.l @r1+, r4
    cmp/str r5, r4
    bt/s    .L_06036E56
    mov.l @r0+, r3
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.l @r1+, r4
    cmp/str r5, r4
    bt/s    .L_06036E56
    mov.l @r0+, r3
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.l @r1+, r4
    cmp/str r5, r4
    bt/s    .L_06036E56
    mov.l @r0+, r3
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.l @r0+, r3
    bra     .L_06036E24
    mov.l @r1+, r4
.L_06036E56:
    add #-0x4, r0
    add #-0x4, r1
    mov.b @r0+, r3
    mov.b @r1+, r4
    cmp/eq r5, r4
    bt      .L_06036E82
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.b @r0+, r3
    mov.b @r1+, r4
    cmp/eq r5, r4
    bt      .L_06036E82
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.b @r0+, r3
    mov.b @r1+, r4
    cmp/eq r5, r4
    bt      .L_06036E82
    cmp/eq r3, r4
    bf      .L_06036E82
    mov.b @r0+, r3
    mov.b @r1+, r4
.L_06036E82:
    sub r4, r3
    mov.l @r15+, r5
    mov r3, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
    .2byte  0x0000
