
    .section .text.FUN_06033578


    .global disp_course_thunk_0
    .type disp_course_thunk_0, @function
disp_course_thunk_0:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_060335F4 - 4
    .2byte 0xB000    /* bsr FUN_060335F4 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD2, 0x19    /* mov.l .L_pool_060335E8, r2 */
    mov.l @(r0, r2), r3
    .byte   0xD2, 0x19    /* mov.l .L_pool_060335EC, r2 */
    mov.l @(r0, r2), r2
    mov r3, r4
    mov r8, r5
    .byte   0xD0, 0x18    /* mov.l .L_pool_060335F0, r0 */
