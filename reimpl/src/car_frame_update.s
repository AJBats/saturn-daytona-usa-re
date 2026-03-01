
   .section .text.FUN_0600E4F2


   .global car_frame_update
   .type car_frame_update, @function
car_frame_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    .byte   0xDD, 0x1C    /* mov.l .L_0600E570, r13 */
    .byte   0xD3, 0x1C    /* mov.l .L_0600E574, r3 */
    .byte   0xD1, 0x1D    /* mov.l .L_0600E578, r1 */
    mov.w @r3, r2
    mov.w r2, @r1
    .byte   0xDE, 0x06    /* mov.l .L_0600E524, r14 */
    .byte   0xD3, 0x07    /* mov.l .L_0600E528, r3 */
    mov.l @r14, r14
    mov.l r14, @r3
    .byte   0xD4, 0x1A    /* mov.l .L_0600E57C, r4 */
    mov.w   DAT_0600e522, r2
    .byte   0xD3, 0x1A    /* mov.l .L_0600E580, r3 */
    add r4, r2
    cmp/eq r4, r14
    bf/s    .L_0600E584
    mov.l r2, @r3
    bra     .L_0600E586
    mov #0x0, r12

    .global DAT_0600e522
DAT_0600e522:
    .2byte  0x0268                        /* car struct stride (616 bytes) */
.L_0600E524:
    .4byte  sym_0607E944               /* car array base pointer */
.L_0600E528:
    .4byte  sym_0607E940               /* current car struct pointer */
    .4byte  sym_0600A8BC               /* (adjacent pool: collision setup fn) */
    .4byte  gas_force_apply            /* (adjacent pool: gas force) */
    .4byte  brake_force_apply          /* (adjacent pool: brake force) */
    .4byte  sym_06030A06               /* (adjacent pool: physics fn A) */
    .4byte  sym_06030EE0               /* (adjacent pool: physics fn B) */
    .4byte  sym_06006838               /* (adjacent pool: atan2 function) */
    .4byte  sym_060786B8               /* (adjacent pool: atan2 result store) */
    .4byte  segment_position_track     /* (adjacent pool: segment tracker) */
    .4byte  scene_3d_processor         /* (adjacent pool: 3D scene processor) */
    .4byte  sym_06063EB0               /* (adjacent pool: geom channel 0) */
    .4byte  sym_06063E9C               /* (adjacent pool: geom channel 1) */
    .4byte  sym_06063ED8               /* (adjacent pool: geom channel 2) */
    .4byte  sym_06063EC4               /* (adjacent pool: geom channel 3) */
    .4byte  finish_proximity           /* (adjacent pool: finish line proximity) */
    .4byte  collision_detect_main      /* (adjacent pool: collision main) */
    .4byte  sym_0603053C               /* (adjacent pool: collision handler) */
    .4byte  checkpoint_detect          /* (adjacent pool: checkpoint detect) */
.L_0600E570:
    .4byte  sym_060786BC               /* scripted movement frame counter */
.L_0600E574:
    .4byte  sym_06063D9E               /* timing word source register */
.L_0600E578:
    .4byte  sym_06063F44               /* timing word destination */
.L_0600E57C:
    .4byte  sym_06078900               /* car array start address */
.L_0600E580:
    .4byte  sym_0607E948               /* car array end marker */
.L_0600E584:
    mov #0x1, r12
.L_0600E586:
    .byte   0xD3, 0x46    /* mov.l .L_0600E6A0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x45    /* mov.l .L_0600E6A4, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x45    /* mov.l .L_0600E6A8, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x44    /* mov.l .L_0600E6AC, r3 */
    jsr @r3
    nop
    mov.l @r13, r2
    cmp/pl r2
    bf      .L_0600E5F2
    .byte   0xD0, 0x42    /* mov.l .L_0600E6B0, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_0600E5F2
    mov.l @r13, r3
    add #-0x1, r3
    mov.l r3, @r13
    .byte   0xD2, 0x3F    /* mov.l .L_0600E6B4, r2 */
    mov.l @(16, r14), r3
    mov.l @r2, r2
    add r2, r3
    mov.l r3, @(16, r14)
    .byte   0xD2, 0x3E    /* mov.l .L_0600E6B8, r2 */
    mov.l @(24, r14), r3
    mov.l @r2, r2
    add r2, r3
    mov.l r3, @(24, r14)
    .byte   0xD2, 0x3C    /* mov.l .L_0600E6BC, r2 */
    mov.l @(32, r14), r3
    mov.w @r2, r2
    add r2, r3
    mov.l r3, @(32, r14)
    mov r3, r2
    mov.l r3, @(48, r14)
    mov.l r2, @(40, r14)
    .byte   0xD3, 0x39    /* mov.l .L_0600E6C0, r3 */
    mov.l r2, @r3
    mov.l @(24, r14), r5
    .byte   0xD3, 0x39    /* mov.l .L_0600E6C4, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x38    /* mov.l .L_0600E6C8, r3 */
    mov.l r0, @r3
    .byte   0xD3, 0x38    /* mov.l .L_0600E6CC, r3 */
    jsr @r3
    nop
    bra     .L_0600E624
    nop
.L_0600E5F2:
    .byte   0xD3, 0x37    /* mov.l .L_0600E6D0, r3 */
    jsr @r3
    nop
    mov.l @(24, r14), r5
    .byte   0xD3, 0x32    /* mov.l .L_0600E6C4, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    .byte   0xD3, 0x31    /* mov.l .L_0600E6C8, r3 */
    mov.l r0, @r3
    .byte   0xD3, 0x31    /* mov.l .L_0600E6CC, r3 */
    jsr @r3
    nop
    .byte   0xDB, 0x32    /* mov.l .L_0600E6D4, r11 */
    .byte   0xD4, 0x32    /* mov.l .L_0600E6D8, r4 */
    jsr @r11
    mov #0x0, r5
    .byte   0xD4, 0x32    /* mov.l .L_0600E6DC, r4 */
    jsr @r11
    mov #0x1, r5
    .byte   0xD4, 0x31    /* mov.l .L_0600E6E0, r4 */
    jsr @r11
    mov #0x2, r5
    .byte   0xD4, 0x31    /* mov.l .L_0600E6E4, r4 */
    jsr @r11
    mov #0x3, r5
.L_0600E624:
    mov.l @(32, r14), r2
    mov.w   DAT_0600e69c, r0
    mov.l r2, @(r0, r14)
    tst r12, r12
    bf      .L_0600E634
    .byte   0xD3, 0x2E    /* mov.l .L_0600E6E8, r3 */
    jsr @r3
    nop
.L_0600E634:
    .byte   0xD3, 0x2D    /* mov.l .L_0600E6EC, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x2D    /* mov.l .L_0600E6F0, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x2C    /* mov.l .L_0600E6F4, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x2C    /* mov.l .L_0600E6F8, r3 */
    jsr @r3
    mov r12, r4
    mov.w   .L_0600E69E, r0
    .byte   0xD3, 0x2B    /* mov.l .L_0600E6FC, r3 */
    mov.l @(r0, r14), r2
    mov.l @r3, r3
    add #-0x3C, r0
    mul.l r3, r2
    mov.l @(r0, r14), r3
    sts macl, r2
    add #0x8, r0
    add r3, r2
    .byte   0xD3, 0x27    /* mov.l .L_0600E700, r3 */
    jsr @r3
    mov.l r2, @(r0, r14)
    mov.l @r13, r2
    cmp/pl r2
    bt      .L_0600E67A
    .byte   0xD0, 0x10    /* mov.l .L_0600E6B0, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_0600E67A
    .byte   0xB1, 0xCF    /* bsr 0x0600EA18 (external) */
    mov r14, r4
.L_0600E67A:
    .byte   0xD0, 0x0D    /* mov.l .L_0600E6B0, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_0600E70C
    .byte   0xD3, 0x1F    /* mov.l .L_0600E704, r3 */
    mov.b @r3, r3
    tst r3, r3
    bf      .L_0600E70C
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x1C    /* mov.l .L_0600E708, r3 */
    jmp @r3
    mov.l @r15+, r14

    .global DAT_0600e69c
DAT_0600e69c:
    .2byte  0x01B0                        /* car offset: yaw angle copy */
.L_0600E69E:
    .2byte  0x0228                        /* car offset: crossing counter */
.L_0600E6A0:
    .4byte  gas_force_apply            /* throttle force application */
.L_0600E6A4:
    .4byte  brake_force_apply          /* brake force application */
.L_0600E6A8:
    .4byte  sym_06030A06               /* physics integration step A */
.L_0600E6AC:
    .4byte  sym_06030EE0               /* physics integration step B */
.L_0600E6B0:
    .4byte  sym_06078635               /* race result (0=in progress) */
.L_0600E6B4:
    .4byte  sym_060786C0               /* scripted X position offset */
.L_0600E6B8:
    .4byte  sym_060786C4               /* scripted Z position offset */
.L_0600E6BC:
    .4byte  sym_060786C8               /* scripted yaw angle offset (16-bit) */
.L_0600E6C0:
    .4byte  sym_06063EF0               /* global yaw angle store */
.L_0600E6C4:
    .4byte  sym_06006838               /* atan2(X, Z) function */
.L_0600E6C8:
    .4byte  sym_060786B8               /* atan2 result store */
.L_0600E6CC:
    .4byte  segment_position_track     /* segment position tracker */
.L_0600E6D0:
    .4byte  sym_0602ECF2               /* normal physics integration */
.L_0600E6D4:
    .4byte  scene_3d_processor         /* 3D scene geometry processor */
.L_0600E6D8:
    .4byte  sym_06063EB0               /* geometry channel 0 data */
.L_0600E6DC:
    .4byte  sym_06063E9C               /* geometry channel 1 data */
.L_0600E6E0:
    .4byte  sym_06063ED8               /* geometry channel 2 data */
.L_0600E6E4:
    .4byte  sym_06063EC4               /* geometry channel 3 data */
.L_0600E6E8:
    .4byte  sym_0600DB64               /* player-specific per-frame update */
.L_0600E6EC:
    .4byte  finish_proximity           /* finish line proximity check */
.L_0600E6F0:
    .4byte  collision_detect_main      /* collision detection main */
.L_0600E6F4:
    .4byte  sym_0603053C               /* collision response handler */
.L_0600E6F8:
    .4byte  checkpoint_detect          /* checkpoint crossing detection */
.L_0600E6FC:
    .4byte  sym_0607EA9C               /* track section count */
.L_0600E700:
    .4byte  track_position_calc        /* track position calculation */
.L_0600E704:
    .4byte  sym_06083255               /* terrain rendering mode flag */
.L_0600E708:
    .4byte  sym_0602D9F0               /* terrain physics update */
.L_0600E70C:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
