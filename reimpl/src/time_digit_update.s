
    .section .text.FUN_06015CAC


    .global time_digit_update
    .type time_digit_update, @function
time_digit_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    add #-0x4, r15
    mov.w   .L_wpool_06015D24, r11
    mov #0x8, r12
    mov.l   .L_pool_06015D28, r13
    mov #0x0, r14
    mov.b r4, @r15
    extu.b r14, r6
    extu.b r14, r4
.L_digit_loop:
    extu.b r4, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r13, r5
    mov.l @(48, r5), r2
    add r11, r2
    mov r2, r3
    mov.l r2, @(48, r5)
    cmp/pz r3
    bf      .L_digit_not_done
    extu.b r4, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r13, r3
    mov.l r14, @(48, r3)
    add #0x1, r6
.L_digit_not_done:
    add #0x1, r4
    extu.b r4, r3
    cmp/ge r12, r3
    bf      .L_digit_loop
    extu.b r6, r0
    cmp/eq #0x8, r0
    bf      .L_not_all_done
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_06015D2C, r3
    jmp @r3
    mov.l @r15+, r14
.L_not_all_done:
    add #0x4, r15
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_06015D24:
    .2byte  0x0800
    .2byte  0xFFFF
.L_pool_06015D28:
    .4byte  sym_06084FC8                    /* [HIGH] HUD digit element array base — 68-byte structs */
.L_pool_06015D2C:
    .4byte  sym_060172E4                    /* [HIGH] clear VDP2 registers — confirmed in track_geometry.s */
