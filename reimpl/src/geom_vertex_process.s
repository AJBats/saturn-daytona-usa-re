
    .section .text.FUN_0601E958


    .global geom_vertex_process
    .type geom_vertex_process, @function
geom_vertex_process:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x8, r11
    mov.l r9, @-r15
    mov #0x10, r10
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0601E9F4, r9
    mov.l   .L_pool_0601E9F8, r12
    mov.l   .L_pool_0601E9FC, r13
    mov.l   .L_pool_0601EA00, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_0601E980
    mov #0x0, r8
    bra     .L_0601EA8E
    mov.b r8, @r13
.L_0601E980:
    .byte   0xBC, 0x98    /* bsr 0x0601E2B4 (hud_overlay_render) */
    nop
    mov.l   .L_pool_0601EA04, r14
    mov.l   .L_pool_0601EA08, r2
    mov.b @r14, r4
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll r3
    add r3, r4
    .byte   0xBD, 0x9D    /* bsr 0x0601E4D4 (hud_state_machine) */
    add r2, r4
    extu.b r0, r4
    mov #0x7, r2
    cmp/ge r2, r4
    bf      .L_0601E9BA
    .byte   0xB0, 0xE5    /* bsr 0x0601EB70 (geom_normal_compute) */
    nop
    mov.b @r14, r2
    mov.l   .L_pool_0601EA0C, r3
    extu.b r2, r2
    add r3, r2
    mov.b r8, @r2
    mov #0x4, r2
    jsr @r12
    mov.b r2, @r13
    bra     .L_0601EA8E
    nop
.L_0601E9BA:
    mov #0x1, r1
    mov.b @r14, r2
    mov.l   .L_pool_0601EA0C, r3
    extu.b r2, r2
    add r3, r2
    mov.b r1, @r2
    mov #0x3, r3
    cmp/ge r3, r4
    bf      .L_0601EA14
    add #-0x3, r4
    mov.b @r14, r3
    mov.l   .L_pool_0601EA10, r2
    extu.b r4, r4
    extu.b r3, r3
    add r2, r3
    mov.b r4, @r3
    .byte   0xB0, 0xC9    /* bsr 0x0601EB70 (geom_normal_compute) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA5, 0x0E    /* bra 0x0601F40C (geom_output_handler) */
    mov.l @r15+, r14
    .4byte  0x2010001F
.L_pool_0601E9F4:
    .4byte  sym_0605E098
.L_pool_0601E9F8:
    .4byte  sym_0601F8BC
.L_pool_0601E9FC:
    .4byte  sym_0605E05C
.L_pool_0601EA00:
    .4byte  sym_0605E05D
.L_pool_0601EA04:
    .4byte  sym_060877D8
.L_pool_0601EA08:
    .4byte  sym_0604A57C
.L_pool_0601EA0C:
    .4byte  sym_060877DD
.L_pool_0601EA10:
    .4byte  sym_060877D9
.L_0601EA14:
    mov.b @r14, r2
    .byte   0xD3, 0x2F    /* mov.l @(0xBC,PC), r3 */
    extu.b r2, r2
    add r3, r2
    mov.b r4, @r2
    mov.l @r9, r6
    mov.b @r14, r5
    .byte   0xD2, 0x2D    /* mov.l @(0xB4,PC), r2 */
    mov.b @r14, r4
    extu.b r5, r5
    extu.b r4, r4
    mov r5, r3
    shll2 r5
    shll2 r3
    shll r3
    add r3, r5
    add r2, r5
    .byte   0xD3, 0x27    /* mov.l @(0x9C,PC), r3 */
    add r3, r4
    mov.b @r4, r4
    .byte   0xBE, 0x92    /* bsr 0x0601E764 (hud_render_stage) */
    extu.b r4, r4
    mov r0, r4
    tst r4, r4
    bt      .L_0601EA4E
    jsr @r12
    mov.b r11, @r13
    bra     .L_0601EA8E
    nop
.L_0601EA4E:
    .byte   0xD2, 0x23    /* mov.l @(0x8C,PC), r2 */
    mov.b @r2, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_0601EA8E
    mov r8, r4
.L_0601EA5A:
    mov.l @r9, r3
    add r4, r3
    mov.b @r3, r2
    .byte   0xD3, 0x1F    /* mov.l @(0x7C,PC), r3 */
    extu.b r2, r2
    add r4, r3
    mov.b @r3, r1
    extu.b r1, r1
    cmp/eq r1, r2
    bt      .L_0601EA76
    jsr @r12
    mov.b r11, @r13
    bra     .L_0601EA8E
    nop
.L_0601EA76:
    add #0x1, r4
    cmp/ge r10, r4
    bf      .L_0601EA5A
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xA0, 0xA6    /* bra 0x0601EBDA (geom_vertex_compute) */
    mov.l @r15+, r14
.L_0601EA8E:
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
