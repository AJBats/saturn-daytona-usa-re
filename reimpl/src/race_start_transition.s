
    .section .text.FUN_0601A578


    .global race_start_transition
    .type race_start_transition, @function
race_start_transition:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0601A60C, r3
    mov.l r14, @r3
    mov.l   .L_pool_0601A610, r4
    mov.l   .L_pool_0601A614, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_pool_0601A618, r3
    jsr @r3
    nop
    mov.l   .L_pool_0601A618, r3
    jsr @r3
    nop
    mov #0x9, r7
    mov.l   .L_pool_0601A61C, r5
    mov.l   .L_pool_0601A620, r4
    mov.l   .L_pool_0601A624, r3
    jsr @r3
    mov r14, r6
    mov #0x8, r7
    mov.l   .L_pool_0601A628, r5
    mov.l   .L_pool_0601A62C, r4
    mov.l   .L_pool_0601A624, r3
    jsr @r3
    mov r14, r6
    mov r14, r6
    mov.l   .L_pool_0601A630, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.l   .L_pool_0601A634, r3
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_0601A638, r3
    jsr @r3
    mov #0x4, r4
    mov #0x1, r2
    mov.l   .L_pool_0601A63C, r3
    mov.b r2, @r3
    .byte   0xB9, 0xAC    /* bsr 0x06019928 (track_seg_phys_init) */
    nop
    .byte   0xB0, 0x45    /* bsr 0x0601A65E (car_init_handler) */
    nop
    .byte   0xB1, 0x1A    /* bsr 0x0601A80C (course_data_rom_load) */
    nop
    .byte   0xB1, 0xB2    /* bsr 0x0601A940 (course_init_pipeline) */
    nop
    mov.l   .L_pool_0601A640, r3
    mov.b r14, @r3
    mov.l   .L_pool_0601A644, r3
    mov.b r14, @r3
    mov.l   .L_pool_0601A648, r3
    mov.b r14, @r3
    mov.l   .L_pool_0601A64C, r3
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_pool_0601A650, r3
    jmp @r3
    mov.l @r15+, r14

    .global sym_0601A5F8
sym_0601A5F8:
    mov.l   .L_pool_0601A654, r0
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x10, r0
    bf      .L_0601A658
    mov.w   .L_wpool_0601A608, r0
    rts
    nop
.L_wpool_0601A608:
    .2byte  0x00A8
    .2byte  0xFFFF
.L_pool_0601A60C:
    .4byte  sym_06059F44
.L_pool_0601A610:
    .4byte  sym_0605B6D8
.L_pool_0601A614:
    .4byte  0x80000000
.L_pool_0601A618:
    .4byte  sym_06026CE0
.L_pool_0601A61C:
    .4byte  0x00014000
.L_pool_0601A620:
    .4byte  0x25E76174
.L_pool_0601A624:
    .4byte  sym_0600511E
.L_pool_0601A628:
    .4byte  0x00017700
.L_pool_0601A62C:
    .4byte  0x25E761FC
.L_pool_0601A630:
    .4byte  sym_06063AF8
.L_pool_0601A634:
    .4byte  0x0000A000
.L_pool_0601A638:
    .4byte  sym_06028400
.L_pool_0601A63C:
    .4byte  sym_06085FF1
.L_pool_0601A640:
    .4byte  sym_06085FF2
.L_pool_0601A644:
    .4byte  sym_06085FF3
.L_pool_0601A648:
    .4byte  sym_0605D245
.L_pool_0601A64C:
    .4byte  race_data_handler
.L_pool_0601A650:
    .4byte  palette_frame_effects
.L_pool_0601A654:
    .4byte  sym_06063D9E
.L_0601A658:
    .byte   0x90, 0x40    /* mov.w .L_wpool_0601A6DC, r0 (cross-TU word pool) */
    rts
    nop
