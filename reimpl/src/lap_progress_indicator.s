
    .section .text.FUN_060111E2


    .global lap_progress_indicator
    .type lap_progress_indicator, @function
lap_progress_indicator:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    .byte   0xD0, 0x09    /* mov.l .L_06011214, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0xB, r0
    bf/s    .L_0601121E
    mov #0x3, r13
    .byte   0xD0, 0x07    /* mov.l .L_06011218, r0 */
    mov.l @r0, r0
    tst #0x1, r0
    bt      .L_0601121C
    bra     .L_0601121E
    nop

    .global DAT_06011206
DAT_06011206:
    mov.l @(r0, r9), r2
    .word 0x04A8
    .word 0x02BA
    mov.b r12, @(r0, r4)
    .word 0xFFFF
    .4byte  sym_06078644               /* (adjacent data) */
.L_06011214:
    .4byte  sym_0607887F               /* game mode byte (0xB = variant) */
.L_06011218:
    .4byte  sym_0607EBC8               /* mode configuration flags (bit 0 = lap count) */
.L_0601121C:
    mov #0x4, r13
.L_0601121E:
    .byte   0xDC, 0x32    /* mov.l .L_060112E8, r12 */
    .byte   0xDE, 0x32    /* mov.l .L_060112EC, r14 */
    .byte   0xD0, 0x33    /* mov.l .L_060112F0, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06011280
    .byte   0xDA, 0x32    /* mov.l .L_060112F4, r10 */
    mov r13, r11
    mov.w   .L_060112E2, r6
    .byte   0xD5, 0x31    /* mov.l .L_060112F8, r5 */
    mov.l @(4, r10), r7
    add #0x2, r11
    shll8 r11
    shll2 r11
    shll2 r11
    add r11, r7
    jsr @r14
    mov #0x4, r4
    mov.l @(4, r10), r7
    mov.w   .L_060112E4, r6
    mov.l @r12, r0
    tst r0, r0
    bt/s    .L_06011252
    add r11, r7
    bra     .L_06011254
    mov #0x1, r0
.L_06011252:
    mov #0x0, r0
.L_06011254:
    shll2 r0
    .byte   0xD5, 0x29    /* mov.l .L_060112FC, r5 */
    .byte   0xD3, 0x29    /* mov.l .L_06011300, r3 */
    mov.l @r5, r5
    shll2 r5
    shll r5
    add r3, r5
    mov.l @(r0, r5), r5
    jsr @r14
    mov #0x4, r4
    mov.l @(4, r10), r7
    mov.w   DAT_060112e6, r6
    mov.l @r12, r0
    tst r0, r0
    bt/s    .L_0601127A
    add r11, r7
    .byte   0xD5, 0x23    /* mov.l .L_06011304, r5 */
    bra     .L_060112D0
    nop
.L_0601127A:
    .byte   0xD5, 0x23    /* mov.l .L_06011308, r5 */
    bra     .L_060112D0
    nop
.L_06011280:
    .byte   0xDA, 0x1C    /* mov.l .L_060112F4, r10 */
    mov r13, r11
    mov.w   .L_060112E2, r6
    .byte   0xD5, 0x21    /* mov.l .L_0601130C, r5 */
    mov.l @(4, r10), r7
    shll8 r11
    shll2 r11
    shll2 r11
    add r11, r7
    jsr @r14
    mov #0x4, r4
    mov.l @(4, r10), r7
    mov.w   .L_060112E4, r6
    mov.l @r12, r0
    tst r0, r0
    bt/s    .L_060112A6
    add r11, r7
    bra     .L_060112A8
    mov #0x1, r0
.L_060112A6:
    mov #0x0, r0
.L_060112A8:
    shll2 r0
    .byte   0xD5, 0x14    /* mov.l .L_060112FC, r5 */
    .byte   0xD3, 0x14    /* mov.l .L_06011300, r3 */
    mov.l @r5, r5
    shll2 r5
    shll r5
    add r3, r5
    mov.l @(r0, r5), r5
    jsr @r14
    mov #0x4, r4
    mov.l @(4, r10), r7
    mov.w   DAT_060112e6, r6
    mov.l @r12, r0
    tst r0, r0
    bt/s    .L_060112CE
    add r11, r7
    .byte   0xD5, 0x0E    /* mov.l .L_06011304, r5 */
    bra     .L_060112D0
    nop
.L_060112CE:
    .byte   0xD5, 0x0E    /* mov.l .L_06011308, r5 */
.L_060112D0:
    jsr @r14
    mov #0x4, r4
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060112E2:
    .2byte  0x02A0                        /* VDP1 cmd offset: position/lap icon */
.L_060112E4:
    .2byte  0x0530                        /* VDP1 cmd offset: lap count digit */

    .global DAT_060112e6
DAT_060112e6:
    .2byte  0x0534                        /* VDP1 cmd offset: lap indicator border */
.L_060112E8:
    .4byte  sym_06078644               /* lap state flag (nonzero = lap in progress) */
.L_060112EC:
    .4byte  sym_06028400               /* HUD element draw function */
.L_060112F0:
    .4byte  sym_0607EAB8               /* race active flag (nonzero = racing) */
.L_060112F4:
    .4byte  sym_06063828               /* display structure (VDP1 base at +4) */
.L_060112F8:
    .4byte  sym_0605A8B6               /* position sprite data (race active) */
.L_060112FC:
    .4byte  sym_06078868               /* car/player index for sprite lookup */
.L_06011300:
    .4byte  sym_0605ABBC               /* sprite lookup table (8 bytes per car) */
.L_06011304:
    .4byte  sym_0605A9B0               /* active state sprite (lap in progress) */
.L_06011308:
    .4byte  sym_0605A9B8               /* inactive state sprite (no lap) */
.L_0601130C:
    .4byte  sym_0605A7FC               /* position sprite data (race inactive) */
