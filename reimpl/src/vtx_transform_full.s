
    .section .text.FUN_0602D934


    .global vtx_transform_full
    .type vtx_transform_full, @function
vtx_transform_full:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov r14, r0
    mov.l @(0, r0), r10
    mov.l   .L_0602D958, r11
    tst r10, r11
    bt      .L_0602D95C
    add r1, r5
    bra     .L_0602D95E
    nop
    .2byte  0x024C
    .4byte  0x0000000F
    .4byte  sym_0602ECCC
.L_0602D958:
    .4byte  0x00000300
.L_0602D95C:
    sub r1, r5
.L_0602D95E:
    mov.l r5, @(48, r0)
    mov.l r5, @(32, r0)
    mov.w   .L_0602D9D0, r1
    mov.l @(r0, r1), r4
    mov.l r4, @(40, r0)
    neg r4, r4
    mov.w   .L_0602D9D2, r1
    mov.w @(r0, r1), r2
    mov.l   .L_0602D9D4, r3
    shll2 r2
    add r2, r3
    mov.l @r3, r5
    mov.l @(12, r0), r2
    dmuls.l r2, r5
    mov.l @(8, r0), r7
    sts mach, r2
    sts macl, r5
    xtrct r2, r5
    mov.l r5, @(12, r0)
    mov #0x28, r2
    cmp/gt r2, r7
    bt      .L_0602D98C
    mov.l   .L_0602D9D8, r5
.L_0602D98C:
    mov.l @(16, r0), r6
    mov.l @(24, r0), r7
    mov.l r6, @(56, r0)
    mov.l r7, @(60, r0)
    mov r4, r9
    mov r5, r1
    mov.l   .L_0602D9DC, r0
    jsr @r0
    nop
    mov r0, r8
    mov r9, r4
    mov.l   .L_0602D9E0, r0
    jsr @r0
    nop
    dmuls.l r0, r5
    mov r14, r0
    mov.l   .L_0602D9E4, r10
    sts mach, r11
    sts macl, r5
    xtrct r11, r5
    mov.l r5, @(r0, r10)
    add r5, r6
    mov.l r6, @(16, r0)
    dmuls.l r8, r1
    mov.l   .L_0602D9E8, r10
    sts mach, r8
    sts macl, r1
    xtrct r8, r1
    mov.l r1, @(r0, r10)
    add r1, r7
    mov.l r7, @(24, r0)
    lds.l @r15+, pr
    rts
    nop
.L_0602D9D0:
    .2byte  0x0248                  /* car struct +0x248: angular velocity */
.L_0602D9D2:
    .2byte  0x0250                  /* car struct +0x250: scene table index */
.L_0602D9D4:
    .4byte  sym_0602E8B8            /* scene scale lookup table (main_scene_render) */
.L_0602D9D8:
    .4byte  0x00006AAA              /* default scale when frame_count <= 0x28 */
.L_0602D9DC:
    .4byte  cos_lookup              /* cosine lookup function */
.L_0602D9E0:
    .4byte  sin_lookup              /* sine lookup function */
.L_0602D9E4:
    .4byte  0x0000018C              /* car struct +0x18C: X rotation delta */
.L_0602D9E8:
    .4byte  0x00000190              /* car struct +0x190: Z rotation delta */
    .4byte  0x000B0009              /* (padding / out-of-TU data) */

    .global sym_0602D9F0
sym_0602D9F0:
    mov.l   .L_0602DAB0, r0
    mov.l @r0, r0
    mov.l   .L_0602DAB4, r3
    mov.l @r3, r3
    add #-0x1, r3
    mov.l   .L_0602DAB8, r4
    mov.l @(r0, r4), r4
    cmp/ge r3, r4
    bt      .L_0602DA8E
    mov.l   .L_0602DABC, r3
    mov.l @r3, r3
    mov.l   .L_0602DAC0, r4
    cmp/eq r4, r3
    bf      .L_0602DA16
    mov.l   .L_0602DAC4, r1
    mov.l @(r0, r1), r3
    mov.l   .L_0602DAC8, r4
    cmp/ge r4, r3
    bt      .L_0602DA8E
.L_0602DA16:
    mov.l   .L_0602DACC, r1
    mov.l @(r0, r1), r1
    mov.l   .L_0602DAD0, r3
    cmp/eq r3, r1
    bf      .L_0602DA8E
    mov.w   .L_0602DA98, r1
    mov.w @(r0, r1), r3
    mov.w   .L_0602DA9A, r1
    mov.w @(r0, r1), r4
    mov.w   .L_0602DA9C, r1
    mov.l @(r0, r1), r5
    or r3, r4
    or r4, r5
    tst r5, r5
    bf      .L_0602DA8E
    mov.w   .L_0602DA9E, r1
    add r0, r1
    mov.l @(0, r1), r2
    mov.l @(4, r1), r3
    mov.l @(8, r1), r4
    mov.l @(12, r1), r5
    mov.w   .L_0602DAA0, r6
    and r2, r3
    and r4, r5
    and r3, r5
    cmp/eq r5, r6
    bf      .L_0602DA8E
    mov.l   .L_0602DAD4, r0
    mov.l @r0, r0
    mov.w   .L_0602DAA2, r1
    mov.l @(r0, r1), r4
    mov.l @(40, r0), r3
    sub r4, r3
    exts.w r3, r3
    mov.w   .L_0602DAA4, r5
    add r5, r3
    mov.w   .L_0602DAA6, r5
    cmp/ge r3, r5
    bt      .L_0602DA8E
    mov.w   .L_0602DAA8, r5
    cmp/ge r3, r5
    bf      .L_0602DA8E
    mov.l @(0, r0), r2
    mov.l   .L_0602DAD8, r3
    tst r3, r2
    bf      .L_0602DAEC
    mov.l   .L_0602DADC, r1
    mov.b @r1, r1
    tst r1, r1
    bf      .L_0602DAEC
    mov.l @(0, r0), r2
    mov.l   .L_0602DAE0, r3
    or r3, r2
    mov.l r2, @(0, r0)
    mov.l   .L_0602DAE4, r1
    mov.w   .L_0602DAAA, r2
    mov.l r2, @r1
    mov.l   .L_0602DAE8, r1
    mov.w   .L_0602DAAC, r2
    mov.l r2, @r1
.L_0602DA8E:
    mov.l   .L_0602DADC, r1
    mov.l   .L_0602DAD0, r2
    mov.b r2, @r1
    rts
    nop
.L_0602DA98:
    .2byte  0x0150                  /* car struct +0x150: clip flags A */
.L_0602DA9A:
    .2byte  0x0250                  /* car struct +0x250: clip flags B */
.L_0602DA9C:
    .2byte  0x00B8                  /* car struct +0xB8: visibility flags */
.L_0602DA9E:
    .2byte  0x0120                  /* car struct +0x120: vertex bounding box */
.L_0602DAA0:
    .2byte  0x0041                  /* required AND result for all-in-view */
.L_0602DAA2:
    .2byte  0x025C                  /* car struct +0x25C: track section Z */
.L_0602DAA4:
    .2byte  0x3FFF                  /* bias to shift signed delta positive */
.L_0602DAA6:
    .2byte  0x2800                  /* minimum biased Z distance */
.L_0602DAA8:
    .2byte  0x47FF                  /* maximum biased Z distance */
.L_0602DAAA:
    .2byte  0x003C                  /* 60 (checkpoint timer frames) */
.L_0602DAAC:
    .2byte  0x0001                  /* 1 (race complete flag value) */
    .2byte  0x0000                  /* (alignment padding) */
.L_0602DAB0:
    .4byte  sym_0607E944            /* car array base pointer */
.L_0602DAB4:
    .4byte  sym_06063F28            /* maximum lap count for current race */
.L_0602DAB8:
    .4byte  0x00000228              /* car struct +0x228: current lap */
.L_0602DABC:
    .4byte  sym_0607EAD8            /* race end state (0/1/2) */
.L_0602DAC0:
    .4byte  0x00000001              /* constant 1 */
.L_0602DAC4:
    .4byte  0x00000018              /* car struct +0x18: Z position */
.L_0602DAC8:
    .4byte  0xFF000000              /* upper byte mask (Z out-of-range guard) */
.L_0602DACC:
    .4byte  0x000001BC              /* car struct +0x1BC: terrain type */
.L_0602DAD0:
    .4byte  0x00000000              /* constant 0 */
.L_0602DAD4:
    .4byte  sym_0607E940            /* current car struct pointer */
.L_0602DAD8:
    .4byte  0x00000008              /* bit 3 flag mask */
.L_0602DADC:
    .4byte  sym_06083260            /* race mode byte */
.L_0602DAE0:
    .4byte  0x00020000              /* bit 17 flag (0x20000) */
.L_0602DAE4:
    .4byte  sym_0607EAC8            /* checkpoint counter (32-bit) */
.L_0602DAE8:
    .4byte  sym_0605A1C4            /* race complete flag (32-bit) */
.L_0602DAEC:
    mov.l   .L_0602DAF8, r1
    mov.l   .L_0602DAFC, r2
    mov.b r2, @r1
    rts
    nop
    .2byte  0x0000                  /* (alignment padding) */
.L_0602DAF8:
    .4byte  sym_06083260            /* race mode byte (duplicate ref) */
.L_0602DAFC:
    .4byte  0xFFFFFFFF              /* -1 (byte-stored as 0xFF) */

    .global sym_0602DB00
sym_0602DB00:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
