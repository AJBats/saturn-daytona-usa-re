	.text
    .global input_proc_complete
input_proc_complete:
    tst r0, r0
    mov.l r2, @-r15
    bt      .L_06035FD6
    mov #0x0, r2
    div0u
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    div1 r0, r2
    rotcl r1
    mov r1, r0
    rts
    mov.l @r15+, r2
.L_06035FD6:
    mov.l   .L_06035FE4, r2
    mov.l   .L_06035FE8, r1
    mov #0x0, r0
    mov.l r1, @r2
    rts
    mov.l @r15+, r2
    .short  0x0009
.L_06035FE4:
    .long  sym_060A246C
.L_06035FE8:
    .long  0x0000044E

    .global sym_06035FEC
sym_06035FEC:
    mov.l r3, @-r15
    mov.l r4, @-r15
    mov #0x3, r3
    mov r0, r4
    and r3, r4
    and r1, r3
    or r4, r3
    tst r3, r3
    bt      .L_06036030
    mov r0, r4
    mov.b @r1+, r0
    mov r4, r3
.L_06036004:
    cmp/eq #0x0, r0
    mov.b r0, @r3
    bt      .L_06036028
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(1, r3)
    bt      .L_06036028
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(2, r3)
    bt      .L_06036028
    mov.b @r1+, r0
    cmp/eq #0x0, r0
    mov.b r0, @(3, r3)
    bt      .L_06036028
    mov.b @r1+, r0
    bra     .L_06036004
    add #0x4, r3
.L_06036028:
    mov r4, r0
    mov.l @r15+, r4
    rts
    mov.l @r15+, r3
.L_06036030:
    mov.l   .L_06036038, r3
    jmp @r3
    nop
    .short  0x0009
.L_06036038:
    .long  sym_06036CB0

    .global sym_0603603C
sym_0603603C:
    mov.b @(r0, r0), r14
    .word 0x0A08
    .long  loc_06040200
    .long  0x201E1C1A
    .long  0x18161412
    .long  0x3432302E
    .long  0x2C2A2826
    .long  0x403E3C3A
    .long  0x4856626C
    .long  0x2F264111
    .long  0x8F18E220
    .long  0x3123890B

    .global sym_06036068
sym_06036068:
    mov.l   .L_0603607C, r2
    add r1, r2
    mov.b @r2, r2
    mov.l   .L_06036078, r1
    add r2, r1
    jmp @r1
    nop
    .short  0x0009
.L_06036078:
    .long  sym_06036086
.L_0603607C:
    .long  sym_0603603C
    .long  0xE000000B
    .short  0x62F6

    .global sym_06036086
sym_06036086:
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    shlr r0
    rts
    mov.l @r15+, r2
    .long  0x40014001
    .long  0x40014001
    .long  0x40014001
    .long  0x40014019
    .long  0x000B62F6
    .long  0x40014001
    .long  0x40014001
    .long  0x40014001
    .long  0x40014029
    .long  0x000B62F6
    .long  0x40014001
    .long  0x40014019
    .long  0x4029000B
    .long  0x62F64004
    .long  0x40044004
    .long  0x4004C90F
    .long  0x000B62F6
    .long  0x40044004
    .long  0x4004C907
    .long  0x000B62F6
    .long  0x40044004
    .long  0xC903000B
    .long  0x62F64004
    .long  0xC901000B
    .long  0x62F60000

    .global sym_060360FC
sym_060360FC:
    mov.l r13, @-r15
    cmp/eq r5, r4
    bt      .L_0603613E
    cmp/hs r5, r4
    bt.s    .L_06036124
    mov #0x0, r7
    mov r4, r13
    mov r5, r0
    cmp/hs r6, r7
    bt.s    .L_0603613E
    mov r7, r5
.L_06036112:
    mov r13, r2
    mov.b @r0+, r1
    add #0x1, r5
    add #0x1, r13
    cmp/hs r6, r5
    bf.s    .L_06036112
    mov.b r1, @r2
    bra     .L_0603613E
    nop
.L_06036124:
    mov r4, r13
    mov r5, r0
    add r6, r13
    add r6, r0
    cmp/hs r6, r7
    bt.s    .L_0603613E
    mov r7, r5
.L_06036132:
    add #-0x1, r0
    add #0x1, r5
    mov.b @r0, r3
    cmp/hs r6, r5
    bf.s    .L_06036132
    mov.b r3, @-r13
.L_0603613E:
    mov r4, r0
    rts
    mov.l @r15+, r13
