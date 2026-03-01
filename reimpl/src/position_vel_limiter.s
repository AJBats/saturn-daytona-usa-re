
    .section .text.FUN_060122F4


    .global position_vel_limiter
    .type position_vel_limiter, @function

position_vel_limiter:
    mov.l   .L_06012334, r4
    mov.w   .L_06012326, r3
    mov.l @(4, r4), r2
    sub r3, r2
    mov.l r2, @(4, r4)
    mov.w   .L_06012328, r3
    mov.l @(8, r4), r2
    sub r3, r2
    mov.l r2, @(8, r4)
    mov.l   .L_06012338, r5
    mov.l @(4, r4), r3
    cmp/ge r5, r3
    bt      .L_06012310
    mov.l r5, @(4, r4)
.L_06012310:
    mov.l   .L_0601233C, r5
    mov.l @(8, r4), r3
    cmp/ge r5, r3
    bt      .L_0601231A
    mov.l r5, @(8, r4)
.L_0601231A:
    mov.l   .L_06012340, r5
    mov.w   .L_0601232A, r3
    mov.w @r5, r2
    add r3, r2
    rts
    mov.w r2, @r5
.L_06012326:
    .2byte  0x2999                      /* [HIGH] Y velocity decrement per frame (16.16 fixed ~0.163) */
.L_06012328:
    .2byte  0x4000                      /* [HIGH] Z velocity decrement per frame (16.16 fixed = 0.25) */
.L_0601232A:
    .2byte  0x1800                      /* [HIGH] rotation angle increment per frame (0x1800 = ~33.75 deg) */
.L_0601232C:
    .4byte  g_game_state                /* [HIGH] game state variable (0-31 state machine index) — unreferenced in this TU */
.L_06012330:
    .4byte  sym_06078636                /* [HIGH] display mode byte (controls car display) — unreferenced in this TU */
.L_06012334:
    .4byte  sym_060788B4                /* [HIGH] position vector base (XYZ triplet, 16.16 fixed-point) */
.L_06012338:
    .4byte  0x00020000                  /* [HIGH] 2.0 (16.16 fixed-point) — Y position floor */
.L_0601233C:
    .4byte  0x0004CCCC                  /* [HIGH] ~4.8 (16.16 fixed-point) — Z position floor */
.L_06012340:
    .4byte  sym_060788B2                /* [HIGH] Z rotation angle state (16-bit, WRAM High) */
