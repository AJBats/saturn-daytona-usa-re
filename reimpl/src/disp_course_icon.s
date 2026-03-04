
    .section .text.FUN_060337AE


    .global disp_course_icon
    .type disp_course_icon, @function
disp_course_icon:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033520 - 4
    .2byte 0xB000    /* bsr FUN_06033520 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0E    /* mov.l .L_pool_060337F0, r4 */
    .byte   0xD5, 0x0E    /* mov.l .L_pool_060337F4, r5 */
    mov.l @r5, r5
    .byte   0xD0, 0x0E    /* mov.l .L_pool_060337F8, r0 */
