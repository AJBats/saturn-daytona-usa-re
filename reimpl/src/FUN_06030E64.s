
    .section .text.FUN_06030E64


    .global FUN_06030E64
    .type FUN_06030E64, @function
FUN_06030E64:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r8
    mov r10, r4
    .byte   0xD0, 0x10    /* mov.l .L_pool_06030EB4, r0 */


    /* THEORY: speed_damping — multiplies car speed by a friction factor.
       Evidence: watchpoint on player car[+0x0C] during wall collision (hold RIGHT+A).
       PC=0x06030ECE writes speed via dmuls.l + xtrct (fixed-point multiply).
       Damping factor selected by car[+0x7C]: <6 → 0.75x, 6-7 → 0.87x, ≥8 → 0.98x.
       During wall impact, aggressive 0.75x factor causes 260K→0 in ~15 frames.
       Called ONLY during collision — not every frame. Caller is FUN_06030548
       (player_collision_response_chain) at PR=0x06030DBE.
       Previously misnamed "sound_channel_mgr" — no relation to sound. */
    .global FUN_06030E72
    .type FUN_06030E72, @function
FUN_06030E72:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    dmuls.l r0, r3
    sts mach, r0
    sts macl, r3
    xtrct r0, r3
    add r3, r5
    mov.l r5, @(16, r14)
    dmuls.l r8, r9
    sts mach, r8
    sts macl, r9
    xtrct r8, r9
    add r9, r6
    mov.l r6, @(24, r14)
    mov.l @(12, r14), r3
    mov.w   DAT_06030eae, r10
    .byte   0xD4, 0x08    /* mov.l .L_pool_06030EBB, r4 */
    add r14, r10
    mov.w @r10, r9
    mov #0x8, r8
    cmp/ge r8, r9
    bt      .L_06030EC0
    add #-0x2, r8
    cmp/ge r8, r9
    bf      .L_06030EC2
    .byte   0xD4, 0x04    /* mov.l .L_pool_06030EBF, r4 */
    bra     .L_06030EC2
    nop

    .global DAT_06030eae
DAT_06030eae:
    .2byte  0x007C
    .4byte  FUN_06027344
    .4byte  FUN_06027348
.L_pool_06030EBB:
    .4byte  0x0000DEB8
.L_pool_06030EBF:
    .4byte  0x0000FAE1
.L_06030EC0:
    .byte   0xD4, 0x06    /* mov.l .L_pool_06030EE0, r4 */
.L_06030EC2:
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.l r4, @(12, r14)
    .global FUN_06030ECC
FUN_06030ECC:
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    rts
    mov.l @r15+, r12
.L_pool_06030EE0:
    .4byte  0x0000C000

    .global sym_06030EE0
sym_06030EE0:
    mov.w   .L_wpool_06030EF9, r0
    .byte   0xD1, 0x05    /* mov.l .L_pool_06030EFD, r1 */
    mov.l @r1, r3
    mov.w @(r0, r3), r2
    cmp/pl r2
    bf      .L_06030EF0
    add #-0x1, r2
    mov.w r2, @(r0, r3)
.L_06030EF0:
    rts
    nop
.L_wpool_06030EF9:
    .2byte  0x0150
    .2byte  0x0000
.L_pool_06030EFD:
    .4byte  sym_0607E940
    .4byte  0x2FC62F06                  /* mov.l r12, @-r15 / mov.l r0, @-r15 */
    .4byte  0x4F22DC04                  /* sts.l pr, @-r15 / mov.l @(PC+16), r12 = FUN_0601D5F4 */
    .4byte  0xD5044C0B                  /* mov.l @(PC+16), r5 = 0xAE1102FF / jsr @r12 */
    .4byte  0xE4004F26                  /* mov #0, r4 / lds.l @r15+, pr */
    .4byte  0x60F6000B                  /* mov.l @r15+, r0 / rts */
    .4byte  0x6CF60000                  /* mov.l @r15+, r12 / padding */
    .4byte  FUN_0601D5F4
    .4byte  0xAE1102FF                  /* pool: sound command ID (sound effect trigger) */

    .global sym_06030F1C
sym_06030F1C:
    .4byte  FUN_060307E8
    .4byte  FUN_060307B8
    .4byte  FUN_06030788
    .4byte  FUN_06030758
    .4byte  0x01220122
    .4byte  0x012C0140
    .4byte  0x01400140
    .4byte  0x01400140
    .4byte  0x01400140
    .4byte  0x01400140
    .4byte  0x01400140
    .4byte  0x01400140
    .4byte  0x01400140
    .4byte  0x01180118
    .4byte  0x012C0136
    .4byte  0x01360136
    .4byte  0x01360136
    .4byte  0x01360136
    .4byte  0x01360136
    .4byte  0x01360136
    .4byte  0x01360136
    .4byte  0x01360136

    .global sym_06030F74
sym_06030F74:
    mov.w @(r0, r1), r1
    stc vbr, r1
    mov.b @(r0, r2), r1
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)
    mov.l r3, @(r0, r1)

    .global sym_06030F98
sym_06030F98:
    .word 0x0113
    .word 0x0118
    stc vbr, r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1
    mov.b @(r0, r2), r1

    .global sym_06030FBC
sym_06030FBC:
    .word 0x0000

    .global sym_06030FBE
sym_06030FBE:
    .word 0x0000

    .global sym_06030FC0
sym_06030FC0:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
