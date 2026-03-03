
    .section .text.FUN_0600FFD0


    .global hud_race_display
    .type hud_race_display, @function
hud_race_display:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.w   .L_wpool_06010042, r9
    mov #0x3, r10
    mov.l   .L_pool_06010048, r11
    mov #0x4, r12
    mov.l   .L_pool_0601004C, r14
    mov #0x0, r13
.L_0600FFEA:
    mov.b @r14, r3
    extu.b r3, r3
    cmp/ge r12, r3
    .byte   0xB0, 0x58    /* bsr 0x060100A4 (sprite_anim_render) */
    mov r13, r4
    add #0x1, r13
    extu.b r13, r2
    cmp/ge r10, r2
    bf      .L_0600FFEA
    mov.l   .L_pool_06010050, r4
    mov.l   .L_pool_06010054, r0
    mov.b @r0, r0
    tst r0, r0
    bf      .L_0601005C
    mov.l @r4, r0
    tst r0, r0
    bt      .L_06010012
    mov.l @r4, r3
    add #-0x1, r3
    mov.l r3, @r4
.L_06010012:
    mov.b @r14, r4
    extu.b r4, r4
    cmp/gt r12, r4
    bf      .L_06010020
    mov r4, r0
    cmp/eq #0x9, r0
    bf      .L_06010094
.L_06010020:
    mov.b @r14, r0
    extu.b r0, r0
    cmp/eq #0x9, r0
    bf      .L_06010032
    mov.l   .L_pool_06010058, r7
    mov r9, r6
    mov.w   DAT_06010044, r5
    bra     .L_0601003A
    mov #0xC, r4
.L_06010032:
    mov.l   .L_pool_06010058, r7
    mov r9, r6
    mov.w   DAT_06010046, r5
    mov #0x8, r4
.L_0601003A:
    jsr @r11
    nop
    bra     .L_06010094
    nop
.L_wpool_06010042:
    .2byte  0x0090

    .global DAT_06010044
DAT_06010044:
    .2byte  0x06A2

    .global DAT_06010046
DAT_06010046:
    .2byte  0x0B22
.L_pool_06010048:
    .4byte  sym_060284AE
.L_pool_0601004C:
    .4byte  sym_0607887F
.L_pool_06010050:
    .4byte  sym_0605AA98
.L_pool_06010054:
    .4byte  sym_06078663
.L_pool_06010058:
    .4byte  sym_0605ACE4
.L_0601005C:
    mov.l @r4, r0
    cmp/eq #0xC, r0
    bt      .L_06010068
    mov.l @r4, r3
    add #0x1, r3
    mov.l r3, @r4
.L_06010068:
    mov.b @r14, r4
    extu.b r4, r4
    cmp/gt r12, r4
    bf      .L_06010076
    mov r4, r0
    cmp/eq #0x9, r0
    bf      .L_06010094
.L_06010076:
    mov.b @r14, r0
    extu.b r0, r0
    cmp/eq #0x9, r0
    bf      .L_06010088
    .byte   0xD7, 0x1F    /* mov.l .L_pool_060100FC, r7 */
    mov r9, r6
    .byte   0x95, 0x36    /* mov.w .L_wpool_060100F2, r5 */
    bra     .L_06010090
    mov #0xC, r4
.L_06010088:
    .byte   0xD7, 0x1C    /* mov.l .L_pool_060100FC, r7 */
    mov r9, r6
    .byte   0x95, 0x32    /* mov.w .L_wpool_060100F4, r5 */
    mov #0x8, r4
.L_06010090:
    jsr @r11
    nop
.L_06010094:
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
