
    .section .text.FUN_0601B074


    .global FUN_0601B074
    .type FUN_0601B074, @function
FUN_0601B074:
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

    .global FUN_0601B096
FUN_0601B096:
    rts
    nop
    .global FUN_0601B09A
FUN_0601B09A:
    .2byte  0x644E
    .4byte  0x655E7FFC
    .4byte  0x63432F60
    .4byte  0x44004308
    .4byte  0x343C4500
    .4byte  0x345CD208
    .4byte  0x6220622C
    .4byte  0x342C4408
    .4byte  0xD306343C
    .4byte  0x6442E606
    .4byte  0x65F0A583
    .2byte  0x7F04
.L_0601B0C6:
    .2byte  0x0100
.L_0601B0C8:
    .2byte  0x0160
    .2byte  0xFFFF
.L_0601B0CC:
    .4byte  FUN_06039100
    .4byte  sym_0605D4F7
    .4byte  sym_0605DD6C
