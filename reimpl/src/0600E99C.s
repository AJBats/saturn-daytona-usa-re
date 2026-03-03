	.text
    .global pre_update_setup
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
    .short  0x0228

    .global DAT_0600e9e4
DAT_0600e9e4:
    mov.b @(r0, r1), r2
    .word 0x0200

    .global DAT_0600e9e8
DAT_0600e9e8:
    .short  0x00E4

    .global DAT_0600e9ea
DAT_0600e9ea:
    .short  0x00E0
.L_wpool_0600E9EC:
    .short  0x01EC
    .short  0xFFFF
    .long  FUN_0600D26A
    .long  ai_orchestrator
    .long  0x00480000
.L_0600E9FC:
    .long  fpmul
    .long  FUN_0600CEBA
    .long  sym_0607EA9C
.L_0600EA08:
    .long  sym_0607E944
.L_0600EA0C:
    .long  sym_0607EAD8
.L_0600EA10:
    .long  0x066505B3
.L_0600EA14:
    .long  sym_0607EAD0
    .long  0x7FF4952C
    .long  0x354C5351
    .long  0x2F325352
    .long  0x1F3266F2
    .long  0x5753263B
    .long  0x267B6352
    .long  0x1F31263B
    .long  0x273952F2
    .long  0x61F22729
    .long  0x27192F72
    .long  0xD50E2668
    .long  0x8D03E700
    .long  0x60F2C880
    .long  0x89022572
    .long  0xA0167F0C
    .long  0xE2332629
    .long  0x26688901
    .long  0xA0092572
    .long  0x62527201
    .long  0x25229307
    .long  0x32338B02
    .long  0x2572A007
    .long  0x7F0C000B
    .short  0x7F0C

    .global DAT_0600ea76
DAT_0600ea76:
    .short  0x0120
    .long  0x00A0FFFF
    .long  sym_0605A228
    .long  0x903BD31F
    .long  0x5244054E
    .long  0x63324508
    .long  0x45007503
    .long  0x45084508
    .long  0x353C6652
    .long  0x57515346
    .long  0x85553628
    .long  0x37386203
    .long  0x4621534C
    .long  0x42084621
    .long  0x32384621
    .long  0x652FD314
    .long  0xE2102322
    .long  0x4621D313
    .long  0x23624721
    .long  0xD3124521
    .long  0x47214521
    .long  0x47214521
    .long  0x47214521
    .long  0x2372655F
    .long  0xD30E2351
    .long  0xE5001453
    .long  0x1452900D
    .long  0x04567004
    .long  0x0456E501
    .long  0x703C0456
    .long  0x70040456
    .long  0x70040456
    .long  0x7004000B
    .short  0x0456

    .global DAT_0600eafa
DAT_0600eafa:
    .short  0x01EC
    .long  0x00E0FFFF
    .long  sym_0607EB88
    .long  sym_060786BC
    .long  sym_060786C0
    .long  sym_060786C4
    .long  sym_060786C8
