/* VERIFIED: called every physics frame during racing (part of player_physics_main pipeline)
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT in race
 *   117 calls during LEFT (baseline 39, +78) — same delta as player_physics_main
 * Date: 2026-02-28
 */

    .section .text.FUN_0600CEBA


    .global track_segment_advance
    .type track_segment_advance, @function
track_segment_advance:
    sts.l pr, @-r15
    .byte   0xD4, 0x22    /* mov.l .L_0600CF48, r4 */
    mov.w   DAT_0600cf3a, r0
    .byte   0xD3, 0x20    /* mov.l .L_0600CF44, r3 */
    mov.l @r4, r4
    mov.l @r3, r3
    mov.l @(r0, r4), r5
    add #0x68, r0
    shll2 r5
    mov.l @(r0, r4), r2
    add r3, r5
    add #0x4, r0
    mov.l r2, @(r0, r4)
    mov.w @r5, r3
    add #-0x4, r0
    extu.w r3, r3
    mov.l r3, @(r0, r4)
    mov.w   .L_0600CF3C, r1
    mov.w   .L_0600CF3E, r2
    .byte   0xD3, 0x1A    /* mov.l .L_0600CF4C, r3 */
    add r4, r1
    add r4, r2
    jsr @r3
    mov #0x2, r0
    mov r5, r2
    .byte   0xD3, 0x17    /* mov.l .L_0600CF4C, r3 */
    mov.w   .L_0600CF3E, r1
    add #0x2, r2
    add r4, r1
    jsr @r3
    mov #0x2, r0
    mov.w   DAT_0600cf40, r0
    mov.l @(r0, r4), r6
    add #-0x4, r0
    mov.l @(r0, r4), r3
    sub r3, r6
    exts.w r6, r6
    exts.w r6, r5
    cmp/pl r5
    bf      .L_0600CF34
    .byte   0xD2, 0x11    /* mov.l .L_0600CF50, r2 */
    mov.l @r2, r2
    add #-0x10, r2
    cmp/gt r2, r5
    bf      .L_0600CF34
    mov.w   .L_0600CF42, r0
    mov.l @(r0, r4), r2
    add #0x1, r2
    mov.l r2, @(r0, r4)
    add #-0xC, r0
    mov.l r2, @(r0, r4)
    .byte   0xD5, 0x0C    /* mov.l .L_0600CF54, r5 */
    mov.l @r5, r3
    add #0x10, r0
    mov.l @(r0, r4), r2
    sub r2, r3
    add #-0xC, r0
    mov.l r3, @(r0, r4)
    mov.l @r5, r3
    add #0xC, r0
    mov.l r3, @(r0, r4)
.L_0600CF34:
    lds.l @r15+, pr
    rts
    nop

    .global DAT_0600cf3a
DAT_0600cf3a:
    .2byte  0x0184
.L_0600CF3C:
    .2byte  0x0162                              /* car[+0x162]: previous heading component [HIGH] */
.L_0600CF3E:
    .2byte  0x0160                              /* car[+0x160]: current heading component [HIGH] */

    .global DAT_0600cf40
DAT_0600cf40:
    .2byte  0x01F0
.L_0600CF42:
    .2byte  0x0228                              /* car[+0x228]: segment crossing counter [HIGH] */
.L_0600CF44:
    .4byte  sym_0607EB84
.L_0600CF48:
    .4byte  sym_0607E940
.L_0600CF4C:
    .4byte  sym_06035228
.L_0600CF50:
    .4byte  sym_0607EA9C
.L_0600CF54:
    .4byte  sym_0607EBD0
