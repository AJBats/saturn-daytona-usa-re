
    .section .text.FUN_060198E0


    .global car_select_setup
    .type car_select_setup, @function
car_select_setup:
    sts.l pr, @-r15
    mov.l   .L_06019910, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_06019914, r3
    jsr @r3
    nop
    mov #0x1, r4
    mov.l   .L_06019918, r3
    mov #-0x1, r1
    mov.b r4, @r3
    extu.b r4, r4
    mov.l   .L_0601991C, r3
    mov.b r4, @r3
    mov.l   .L_06019920, r3
    mov.b r1, @r3
    .reloc ., R_SH_IND12W, FUN_06019928 - 4
    .2byte 0xB000    /* bsr FUN_06019928 (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, course_data_rom_load - 4
    .2byte 0xB000    /* bsr course_data_rom_load (linker-resolved) */
    nop
    mov.l   .L_06019924, r3
    jmp @r3
    lds.l @r15+, pr
    .2byte  0xFFFF
.L_06019910:
    .4byte  sym_0602853E
.L_06019914:
    .4byte  sym_06028560
.L_06019918:
    .4byte  sym_06085FF1
.L_0601991C:
    .4byte  sym_06085FF6
.L_06019920:
    .4byte  sym_06085FF7
.L_06019924:
    .4byte  course_init_pipeline
