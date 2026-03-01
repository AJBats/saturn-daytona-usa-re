
    .section .text.FUN_0602834A


    .global hud_number_display
    .type hud_number_display, @function
hud_number_display:
    sts.l pr, @-r15
    .byte   0xD0, 0x05    /* mov.l .L_06028364, r0 */
    mov.l @(r0, r4), r2
    mov.l @r2, r2
    add r2, r5
    .byte   0xBF, 0xB4    /* bsr 0x060282C0 (external) */
    mov r7, r4
    mov r0, r1
    mov #0x6, r7
    add #0x8, r1
    .byte   0xA0, 0x1B    /* bra 0x06028398 (external) */
    mov #0x0, r0
    .2byte  0x0000
.L_06028364:
    .4byte  sym_06028614                   /* [MEDIUM] effect dispatch table base */
