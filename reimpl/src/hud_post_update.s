    .section .text.FUN_06010A5C
    .global hud_post_update
    .type hud_post_update, @function
/* hud_post_update(r4=index) — HUD post-update dispatch.
 * Computes display list pointer from index, then jumps to a handler.
 * All pool references reach into adjacent TU's pool.
 */
hud_post_update:
    add #-0x4, r15
    mov r4, r5
    mov.l r4, @r15
    shll2 r5
    .byte 0x96, 0x30              /* mov.w @(pool), r6 [cross-TU] */
    .byte 0xD3, 0x1A              /* mov.l @(pool), r3 [cross-TU] */
    .byte 0xD4, 0x1A              /* mov.l @(pool), r4 [cross-TU] */
    add r3, r5
    mov.l @r4, r4
    mov.l @r5, r5
    shll2 r4
    shll r4
    .byte 0xD2, 0x18              /* mov.l @(pool), r2 [cross-TU] */
    mov.l @r2, r2
    add r2, r4
    mov r6, r1
    add #0x40, r1
    add r1, r4
    .byte 0xD1, 0x16              /* mov.l @(pool), r1 -- handler addr [cross-TU] */
    jmp @r1
    add #0x4, r15                 /* restore stack (delay slot) */
    .global sym_06010A86
sym_06010A86:
    extu.w r4, r4
    .byte 0x93, 0x1F              /* mov.w @(pool), r3 -- mask [cross-TU] */
    and r3, r4
    tst r4, r4
    bt .L_06010A9A
    mov #0x1, r3
    .byte 0xD2, 0x13              /* mov.l @(pool), r2 -- flag addr [cross-TU] */
    mov.l r3, @r2
    .byte 0xA0, 0x03              /* bra .L_06010AA0 [cross-TU range] */
    nop
.L_06010A9A:
    mov #0x0, r3
    .byte 0xD2, 0x10              /* mov.l @(pool), r2 -- flag addr [cross-TU] */
    mov.l r3, @r2
.L_06010AA0:
    rts
    nop
