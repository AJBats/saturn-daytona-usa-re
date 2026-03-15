
    .section .text.FUN_06012DB4


    .global FUN_06012DB4
    .type FUN_06012DB4, @function
FUN_06012DB4:
    mov.l r14, @-r15
    mov r4, r0
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x17    /* mov.l .L_wram_low_base, r13 */
    .byte   0xDE, 0x18    /* mov.l .L_wram_low_course, r14 */
    cmp/eq #0x1, r0
    bf      .L_06012DD6
    .byte   0xD4, 0x17    /* mov.l .L_fn_cs1_line, r4 */
    .byte   0xBF, 0x39    /* bsr FUN_06012C3C */
    mov r13, r5
    mov r14, r5
    .byte   0xD4, 0x16    /* mov.l .L_fn_course1, r4 */
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xAF, 0x33    /* bra FUN_06012C3C */
    mov.l @r15+, r14
.L_06012DD6:
    mov r4, r0
    cmp/eq #0x2, r0
    bf      .L_06012DEE
    .byte   0xD4, 0x13    /* mov.l .L_fn_cs2_line, r4 */
    .byte   0xBF, 0x2D    /* bsr FUN_06012C3C */
    mov r13, r5
    mov r14, r5
    .byte   0xD4, 0x12    /* mov.l .L_fn_course2, r4 */
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xAF, 0x27    /* bra FUN_06012C3C */
    mov.l @r15+, r14
.L_06012DEE:
    .byte   0xD4, 0x11    /* mov.l .L_fn_cs0_line, r4 */
    .byte   0xBF, 0x24    /* bsr FUN_06012C3C */
    mov r13, r5
    mov r14, r5
    .byte   0xD4, 0x10    /* mov.l .L_fn_course0, r4 */
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xAF, 0x1E    /* bra FUN_06012C3C */
    mov.l @r15+, r14

    .global sym_06012E00
sym_06012E00:
    .byte   0xD5, 0x0E    /* mov.l .L_player_tex_dest, r5 */
    .byte   0xD4, 0x0F    /* mov.l .L_fn_tex_pl, r4 */
    .byte   0xAF, 0x1A    /* bra FUN_06012C3C */
    nop
