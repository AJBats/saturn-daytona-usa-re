	.text
    .global sound_channel_mgr
sound_channel_mgr:
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
    .short  0x007C
    .long  cos_lookup
    .long  sin_lookup
.L_pool_06030EBB:
    .long  0x0000DEB8
.L_pool_06030EBF:
    .long  0x0000FAE1
.L_06030EC0:
    .byte   0xD4, 0x06    /* mov.l .L_pool_06030EE0, r4 */
.L_06030EC2:
    dmuls.l r3, r4
    sts mach, r3
    sts macl, r4
    xtrct r3, r4
    mov.l r4, @(12, r14)
    mov.l @r15+, r10
    mov.l @r15+, r9
    mov.l @r15+, r8
    lds.l @r15+, pr
    mov.l @r15+, r14
    mov.l @r15+, r13
    rts
    mov.l @r15+, r12
.L_pool_06030EE0:
    .long  0x0000C000

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
    .short  0x0150
    .short  0x0000
.L_pool_06030EFD:
    .long  sym_0607E940
    .long  0x2FC62F06                  /* mov.l r12, @-r15 / mov.l r0, @-r15 */
    .long  0x4F22DC04                  /* sts.l pr, @-r15 / mov.l @(PC+16), r12 = sound_cmd_dispatch */
    .long  0xD5044C0B                  /* mov.l @(PC+16), r5 = 0xAE1102FF / jsr @r12 */
    .long  0xE4004F26                  /* mov #0, r4 / lds.l @r15+, pr */
    .long  0x60F6000B                  /* mov.l @r15+, r0 / rts */
    .long  0x6CF60000                  /* mov.l @r15+, r12 / padding */
    .long  sound_cmd_dispatch
    .long  0xAE1102FF                  /* pool: sound command ID (sound effect trigger) */

    .global sym_06030F1C
sym_06030F1C:
    .long  loc_060307E8
    .long  loc_060307B8
    .long  loc_06030788
    .long  loc_06030758
    .long  0x01220122
    .long  0x012C0140
    .long  0x01400140
    .long  0x01400140
    .long  0x01400140
    .long  0x01400140
    .long  0x01400140
    .long  0x01400140
    .long  0x01400140
    .long  0x01180118
    .long  0x012C0136
    .long  0x01360136
    .long  0x01360136
    .long  0x01360136
    .long  0x01360136
    .long  0x01360136
    .long  0x01360136
    .long  0x01360136

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
