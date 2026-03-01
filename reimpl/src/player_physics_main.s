/* VERIFIED: runs every physics frame during racing, 3x more often during steering
 * Method: call-trace differential — 5 frames idle vs 5 frames with LEFT/RIGHT in race
 *   LEFT:  117 calls (baseline 39, +78) — 3x increase
 *   RIGHT: 117 calls (baseline 39, +78) — identical response
 *   All 6 sub-functions (gear_shift_handler, engine_force, friction_stub,
 *   accel_response, player_collision, track_segment_advance) show the same +78 delta,
 *   confirming they are called as a batch from this function's physics pipeline.
 * Date: 2026-02-28
 */

    .section .text.FUN_0600E71A


    .global player_physics_main
    .type player_physics_main, @function
player_physics_main:
    mov.l r14, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    .byte   0xDE, 0x21    /* mov.l .L_0600E7A8, r14 */
    .byte   0xD3, 0x22    /* mov.l .L_0600E7AC, r3 */
    jsr @r3
    mov.l @r14, r14
    .byte   0xD3, 0x21    /* mov.l .L_0600E7B0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x21    /* mov.l .L_0600E7B4, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_0600E7B8, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x20    /* mov.l .L_0600E7BC, r3 */
    jsr @r3
    nop
    mov.w   DAT_0600e79c, r0
    mov.l @(r0, r14), r2
    cmp/pl r2
    bf      .L_0600E778
    mov.w   DAT_0600e79c, r0
    mov.l @(r0, r14), r2
    add #-0x1, r2
    mov.l r2, @(r0, r14)
    tst r2, r2
    bf      .L_0600E778
    mov.w   DAT_0600e79e, r0
    mov.l @(r0, r14), r4
    mov r4, r3
    shll2 r4
    shll r4
    shll2 r3
    shll2 r3
    add r3, r4
    add #-0x4, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.w @(20, r4), r0
    mov r0, r3
    mov.w   .L_0600E7A0, r0
    mov.l r3, @(r0, r14)
    mov.w   .L_0600E7A2, r3
    add #0xC, r0
    mov.l r3, @(r0, r14)
.L_0600E778:
    .byte   0xD3, 0x11    /* mov.l .L_0600E7C0, r3 */
    jsr @r3
    nop
    mov.w   .L_0600E7A4, r0
    .byte   0xD3, 0x10    /* mov.l .L_0600E7C4, r3 */
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    mov.l r2, @(r0, r14)
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600e79c
DAT_0600e79c:
    .2byte  0x0208

    .global DAT_0600e79e
DAT_0600e79e:
    .2byte  0x01E4
.L_0600E7A0:
    .2byte  0x01F8
.L_0600E7A2:
    .2byte  0x0400
.L_0600E7A4:
    .2byte  0x0228
    .2byte  0xFFFF
.L_0600E7A8:
    .4byte  sym_0607E940
.L_0600E7AC:
    .4byte  gear_shift_handler
.L_0600E7B0:
    .4byte  sym_06008640
.L_0600E7B4:
    .4byte  friction_stub
.L_0600E7B8:
    .4byte  accel_response
.L_0600E7BC:
    .4byte  player_collision
.L_0600E7C0:
    .4byte  track_segment_advance
.L_0600E7C4:
    .4byte  sym_0607EA9C
