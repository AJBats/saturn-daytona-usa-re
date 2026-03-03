	.text
    .global course_setup_handler
course_setup_handler:
    sts.l pr, @-r15
    mov #0x0, r7
    mov #0x30, r6
    mov.w   .L_0601B0C6, r3
    mov r6, r5
    mov.l r3, @-r15
    mov.w   .L_0601B0C8, r2
    mov.l r2, @-r15
    mov.l r3, @-r15
    mov.l r2, @-r15
    mov.l   .L_0601B0CC, r3
    jsr @r3
    mov r7, r4
    add #0x10, r15
    lds.l @r15+, pr
    rts
    nop

    .global loc_0601B096
loc_0601B096:
    rts
    nop
    .short  0x644E
    .long  0x655E7FFC
    .long  0x63432F60
    .long  0x44004308
    .long  0x343C4500
    .long  0x345CD208
    .long  0x6220622C
    .long  0x342C4408
    .long  0xD306343C
    .long  0x6442E606
    .long  0x65F0A583
    .short  0x7F04
.L_0601B0C6:
    .short  0x0100
.L_0601B0C8:
    .short  0x0160
    .short  0xFFFF
.L_0601B0CC:
    .long  color_transform_calc
    .long  sym_0605D4F7
    .long  sym_0605DD6C
