
    .section .text.FUN_0603F9BC


    .global attract_demo_loader
    .type attract_demo_loader, @function
attract_demo_loader:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r5, @(4, r15)
    mov #-0x1, r5
    mov.l r6, @r15
    bsr     race_timer_sync
    mov r14, r4
    mov.l @(4, r15), r2
    mov.l r2, @r14
    mov.l @r15, r3
    mov.l r3, @(8, r14)
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_0603F9DA
sym_0603F9DA:
    mov #0x0, r3
    mov #0x34, r0
    mov #0x34, r1
    mov.l r5, @(20, r4)
    add r4, r1
    mov.l r3, @(24, r4)
    mov.b @(r0, r4), r0
    extu.b r0, r0
    and #0x80, r0
    extu.b r0, r0
    rts
    mov.b r0, @r1

    .global sym_0603F9F2
sym_0603F9F2:
    rts
    mov.l @(20, r4), r0

    .global sym_0603F9F6
sym_0603F9F6:
    rts
    mov.l @(24, r4), r0

    .global sym_0603F9FA
sym_0603F9FA:
    mov.l @(16, r4), r0
    rts
    mov.l r5, @(16, r4)

    .global sym_0603FA00
sym_0603FA00:
    mov #0x34, r0
    mov #0x34, r1
    mov.b @(r0, r4), r0
    add r4, r1
    or #0x80, r0
    rts
    mov.b r0, @r1
    .2byte  0xE034
    .4byte  0x9325024C
    .4byte  0x2239000B
    .2byte  0x0424

    .global race_timer_sync
    .type race_timer_sync, @function
race_timer_sync:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov #0x0, r10
    mov.l   .L_pool_0603FA64, r11
    mov.w   .L_wpool_0603FA5E, r12
    mov.l   .L_pool_0603FA68, r13
    mov r4, r14
    mov.l r5, @(4, r15)
    mov.l @r14, r3
    mov.l r3, @(8, r15)
    mov.l @(8, r14), r3
    mov.l r3, @(12, r15)
    mov.l @r11, r3
    mov.w   .L_wpool_0603FA60, r0
    mov.l r10, @(r0, r3)
    bra     .L_0603FA6C
    nop
.L_0603FA46:
    mov r15, r5
    bsr     scene_buffer_update
    mov r14, r4
    mov.l @r11, r2
    mov.w   .L_wpool_0603FA60, r0
    mov.l @(r0, r2), r3
    add #0x1, r3
    mov.l r3, @(r0, r2)
    cmp/gt r13, r3
    bf      .L_0603FA6C
    bra     .L_0603FA7E
    nop
.L_wpool_0603FA5E:
    .2byte  0xFF7F                      /* [HIGH] 0xFFFFFF7F sign-ext — AND mask clears bit 7 (active flag) */
.L_wpool_0603FA60:
    .2byte  0x00CC                      /* [HIGH] offset into game_state for sync frame counter */
    .2byte  0xFFFF
.L_pool_0603FA64:
    .4byte  sym_060A4D14                /* [HIGH] global game state struct pointer */
.L_pool_0603FA68:
    .4byte  0x01000000                  /* [HIGH] MINIT — primary SH-2 init comm threshold */
.L_0603FA6C:
    mov #0x34, r0
    mov.b @(r0, r14), r4
    extu.b r4, r4
    and r12, r4
    tst r4, r4
    bt      .L_0603FA7E
    mov r4, r0
    cmp/eq #0x5, r0
    bf      .L_0603FA46
.L_0603FA7E:
    mov.l @(4, r14), r0
    tst r0, r0
    bt      .L_0603FA9A
    mov.l @(4, r15), r6
    mov.l @(4, r14), r5
    .byte   0xD3, 0x27    /* mov.l .L_pool_0603FB28, r3 */
    jsr @r3
    mov.l @(8, r15), r4
    mov.l @(4, r14), r2
    mov.l @(12, r2), r3
    mov.l @(24, r14), r2
    add r3, r2
    mov.l r2, @(24, r14)
    mov.l r10, @(4, r14)
.L_0603FA9A:
    mov.l @(12, r14), r0
    tst r0, r0
    bt      .L_0603FAAC
    mov.l @(4, r15), r6
    mov.l @(12, r14), r5
    .byte   0xD3, 0x20    /* mov.l .L_pool_0603FB28, r3 */
    jsr @r3
    mov.l @(12, r15), r4
    mov.l r10, @(12, r14)
.L_0603FAAC:
    mov #0x34, r0
    mov #0x34, r1
    mov.b @(r0, r14), r0
    add r14, r1
    extu.b r0, r0
    and #0x80, r0
    or #0x5, r0
    extu.b r0, r0
    mov.b r0, @r1
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global scene_buffer_update
    .type scene_buffer_update, @function
scene_buffer_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r4, r14
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov #0x0, r11
    mov.l r9, @-r15
    mov r11, r12
    mov.l r8, @-r15
    mov r5, r8
