
    .section .text.FUN_0600E99C


    .global pre_update_setup
    .type pre_update_setup, @function
pre_update_setup:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600EA08, r14
    .byte   0xBF, 0xB0    /* bsr 0x0600E906 (external) */
    mov.l @r14, r14
    mov.l   .L_0600EA0C, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600E9C6
    mov.l   .L_0600EA10, r5
    mov.l   .L_0600E9FC, r3
    jsr @r3
    mov.l @(12, r14), r4
    shlr16 r0
    exts.w r0, r0
    mov.w   DAT_0600e9e8, r1
    add r14, r1
    mov.l r0, @r1
    mov.w   DAT_0600e9ea, r1
    add r14, r1
    mov.l r0, @r1
.L_0600E9C6:
    mov.w   .L_wpool_0600E9EC, r0
    mov.l @(r0, r14), r0
    tst r0, r0
    bf      .L_0600E9DC
    mov #0x0, r4
    mov.l   .L_0600EA14, r3
    mov.l r4, @r3
    mov.w   .L_wpool_0600E9E2, r0
    mov.l r4, @(r0, r14)
    add #-0xC, r0
    mov.l r4, @(r0, r14)
.L_0600E9DC:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0600E9E2:
    .2byte  0x0228                     /* [HIGH] car offset: camera target A — per_car_loop.s:276 confirms +0x228 */

    .global DAT_0600e9e4
DAT_0600e9e4:
    mov.b @(r0, r1), r2
    .word 0x0200

    .global DAT_0600e9e8
DAT_0600e9e8:
    .2byte  0x00E4

    .global DAT_0600e9ea
DAT_0600e9ea:
    .2byte  0x00E0
.L_wpool_0600E9EC:
    .2byte  0x01EC                     /* [MEDIUM] car offset: active-state field — per_car_loop.s:250, gates cleanup path */
    .2byte  0xFFFF
    .4byte  friction_stub
    .4byte  ai_orchestrator
    .4byte  0x00480000
.L_0600E9FC:
    .4byte  fpmul                      /* [HIGH] fixed-point multiply: (r4*r5)>>16 */
    .4byte  track_segment_advance
    .4byte  sym_0607EA9C
.L_0600EA08:
    .4byte  sym_0607E944               /* [HIGH] ptr to current car struct (primary) — object_management.s:87 */
.L_0600EA0C:
    .4byte  sym_0607EAD8               /* [MEDIUM] player mode (0=single, nonzero=versus) — object_management.s:89, race_states.s:84 disagree on semantics */
.L_0600EA10:
    .4byte  0x066505B3                 /* [HIGH] fixed-point Y projection scalar — per_car_loop.s:269 confirms 0x066505B3 */
.L_0600EA14:
    .4byte  sym_0607EAD0               /* [HIGH] race-end flag (nonzero=finished) — race_states.s:83, used in states 15/17/28/29 */
    .4byte  0x7FF4952C
    .4byte  0x354C5351
    .4byte  0x2F325352
    .4byte  0x1F3266F2
    .4byte  0x5753263B
    .4byte  0x267B6352
    .4byte  0x1F31263B
    .4byte  0x273952F2
    .4byte  0x61F22729
    .4byte  0x27192F72
    .4byte  0xD50E2668
    .4byte  0x8D03E700
    .4byte  0x60F2C880
    .4byte  0x89022572
    .4byte  0xA0167F0C
    .4byte  0xE2332629
    .4byte  0x26688901
    .4byte  0xA0092572
    .4byte  0x62527201
    .4byte  0x25229307
    .4byte  0x32338B02
    .4byte  0x2572A007
    .4byte  0x7F0C000B
    .2byte  0x7F0C

    .global DAT_0600ea76
DAT_0600ea76:
    .2byte  0x0120
    .4byte  0x00A0FFFF
    .4byte  sym_0605A228
    .4byte  0x903BD31F
    .4byte  0x5244054E
    .4byte  0x63324508
    .4byte  0x45007503
    .4byte  0x45084508
    .4byte  0x353C6652
    .4byte  0x57515346
    .4byte  0x85553628
    .4byte  0x37386203
    .4byte  0x4621534C
    .4byte  0x42084621
    .4byte  0x32384621
    .4byte  0x652FD314
    .4byte  0xE2102322
    .4byte  0x4621D313
    .4byte  0x23624721
    .4byte  0xD3124521
    .4byte  0x47214521
    .4byte  0x47214521
    .4byte  0x47214521
    .4byte  0x2372655F
    .4byte  0xD30E2351
    .4byte  0xE5001453
    .4byte  0x1452900D
    .4byte  0x04567004
    .4byte  0x0456E501
    .4byte  0x703C0456
    .4byte  0x70040456
    .4byte  0x70040456
    .4byte  0x7004000B
    .2byte  0x0456

    .global DAT_0600eafa
DAT_0600eafa:
    .2byte  0x01EC
    .4byte  0x00E0FFFF
    .4byte  sym_0607EB88
    .4byte  sym_060786BC
    .4byte  sym_060786C0
    .4byte  sym_060786C4
    .4byte  sym_060786C8
