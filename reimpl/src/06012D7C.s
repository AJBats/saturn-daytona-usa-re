
    .section .text.FUN_06012D7C


    .global cd_course_loader
    .type cd_course_loader, @function
cd_course_loader:
    mov.l r14, @-r15
    mov r4, r0
    mov.l   .L_06012DA4, r14
    cmp/eq #0x1, r0
    bf      .L_06012D8E
    mov r14, r5
    mov.l   .L_pool_06012DA8, r4
    .byte   0xAF, 0x57    /* bra 0x06012C3C (external) */
    mov.l @r15+, r14
.L_06012D8E:
    mov r4, r0
    cmp/eq #0x2, r0
    bf      .L_06012D9C
    mov r14, r5
    mov.l   .L_pool_06012DAC, r4
    .byte   0xAF, 0x50    /* bra 0x06012C3C (external) */
    mov.l @r15+, r14
.L_06012D9C:
    mov r14, r5
    mov.l   .L_pool_06012DB0, r4
    .byte   0xAF, 0x4C    /* bra 0x06012C3C (external) */
    mov.l @r15+, r14
.L_06012DA4:
    .4byte  0x00200000
.L_pool_06012DA8:
    .4byte  sym_060448E8
.L_pool_06012DAC:
    .4byte  sym_060448F4
.L_pool_06012DB0:
    .4byte  sym_06044900
