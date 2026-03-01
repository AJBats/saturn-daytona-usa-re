
    .section .text.FUN_06030E72


    .global sound_channel_mgr
    .type sound_channel_mgr, @function
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
    .2byte  0x007C                      /* struct offset to mode word */
    .4byte  cos_lookup                  /* pointer to cosine lookup function */
    .4byte  sin_lookup                  /* pointer to sine lookup function */
.L_pool_06030EBB:
    .4byte  0x0000DEB8                  /* 16.16 fixed-point ~0.87 (moderate damping) */
.L_pool_06030EBF:
    .4byte  0x0000FAE1                  /* 16.16 fixed-point ~0.98 (light damping) */
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
    .4byte  0x0000C000                  /* 16.16 fixed-point 0.75 (strong damping) */

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
    .2byte  0x0150                      /* [HIGH] offset +0x150: countdown timer field in car struct */
    .2byte  0x0000                      /* alignment padding */
.L_pool_06030EFD:
    .4byte  sym_0607E940                /* pointer to current car struct */
    .4byte  0x2FC62F06                  /* mov.l r12, @-r15 / mov.l r0, @-r15 */
    .4byte  0x4F22DC04                  /* sts.l pr, @-r15 / mov.l @(PC+16), r12 = sound_cmd_dispatch */
    .4byte  0xD5044C0B                  /* mov.l @(PC+16), r5 = 0xAE1102FF / jsr @r12 */
    .4byte  0xE4004F26                  /* mov #0, r4 / lds.l @r15+, pr */
    .4byte  0x60F6000B                  /* mov.l @r15+, r0 / rts */
    .4byte  0x6CF60000                  /* mov.l @r15+, r12 / padding */
    .4byte  sound_cmd_dispatch          /* pool: sound_cmd_dispatch function pointer */
    .4byte  0xAE1102FF                  /* pool: sound command ID (sound effect trigger) */

    .global sym_06030F1C
sym_06030F1C:
    .4byte  loc_060307E8                /* channel 3 handler (lowest priority) */
    .4byte  loc_060307B8                /* channel 2 handler */
    .4byte  loc_06030788                /* channel 1 handler */
    .4byte  loc_06030758                /* channel 0 handler (highest priority) */
    .4byte  0x01220122                  /* front offsets [0]: 0x122, 0x122 */
    .4byte  0x012C0140                  /* front offsets [1]: 0x12C, 0x140 */
    .4byte  0x01400140                  /* front offsets [2]: 0x140, 0x140 */
    .4byte  0x01400140                  /* front offsets [3]: 0x140, 0x140 */
    .4byte  0x01400140                  /* front offsets [4]: 0x140, 0x140 */
    .4byte  0x01400140                  /* front offsets [5]: 0x140, 0x140 */
    .4byte  0x01400140                  /* front offsets [6]: 0x140, 0x140 */
    .4byte  0x01400140                  /* front offsets [7]: 0x140, 0x140 */
    .4byte  0x01400140                  /* front offsets [8]: 0x140, 0x140 */
    .4byte  0x01180118                  /* rear offsets [0]: 0x118, 0x118 */
    .4byte  0x012C0136                  /* rear offsets [1]: 0x12C, 0x136 */
    .4byte  0x01360136                  /* rear offsets [2]: 0x136, 0x136 */
    .4byte  0x01360136                  /* rear offsets [3]: 0x136, 0x136 */
    .4byte  0x01360136                  /* rear offsets [4]: 0x136, 0x136 */
    .4byte  0x01360136                  /* rear offsets [5]: 0x136, 0x136 */
    .4byte  0x01360136                  /* rear offsets [6]: 0x136, 0x136 */
    .4byte  0x01360136                  /* rear offsets [7]: 0x136, 0x136 */
    .4byte  0x01360136                  /* rear offsets [8]: 0x136, 0x136 */

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
