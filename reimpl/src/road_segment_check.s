
    .section .text.FUN_06040C98


    .global road_segment_check
    .type road_segment_check, @function
road_segment_check:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov #0x1, r10
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x14, r15
    mov.l   .L_06040D30, r11
    mov.w   DAT_06040d2c, r12
    mov.l   .L_06040D34, r14
    mov.l r5, @r15
    mov.l   .L_06040D38, r3
    jsr @r3
    mov.l r4, @r14
    mov.l @r15, r0
    tst r0, r0
    bt      .L_06040CD4
    mov.l @r14, r2
    add #0x17, r2
    mov.b r10, @r2
    mov.l @r14, r3
    add #0x2F, r3
    exts.b r10, r2
    mov.b r2, @r3
    bra     .L_06040CE2
    nop
.L_06040CD4:
    mov.l @r14, r3
    add #0x17, r3
    mov.b r13, @r3
    mov.l @r14, r2
    add #0x2F, r2
    exts.b r13, r3
    mov.b r3, @r2
.L_06040CE2:
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov r15, r0
    add #0x8, r0
    mov.b @r0, r0
    extu.b r0, r0
    bra     .L_06040D00
    and #0xF, r0
.L_06040CF4:
    bra     .L_06040E5E
    mov #-0xD, r0
.L_06040CF8:
    bra     .L_06040E5E
    mov #-0xE, r0
.L_06040CFC:
    bra     .L_06040E5E
    mov #-0xA, r0
.L_06040D00:
    cmp/eq #0x6, r0
    bt      .L_06040CF4
    cmp/eq #0x7, r0
    bt      .L_06040CF8
    cmp/eq #0x9, r0
    bt      .L_06040CFC
    cmp/eq #0xA, r0
    bt      .L_06040CFC
    mov r12, r7
    mov r12, r6
    mov.l   .L_06040D3C, r5
    mov.l   .L_06040D40, r3
    jsr @r3
    mov r12, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06040D26
    bra     .L_06040E5E
    mov #-0x2, r0
.L_06040D26:
    mov r13, r8
    bra     .L_06040DA4
    mov r13, r9

    .global DAT_06040d2c
DAT_06040d2c:
    .2byte  0x00FF                      /* byte mask constant loaded into r12 */
    .2byte  0xFFFF                      /* alignment padding */
.L_06040D30:
    .4byte  ai_checkpoint_section       /* checkpoint section reader */
.L_06040D34:
    .4byte  sym_060A5400                /* pointer to game state base structure */
.L_06040D38:
    .4byte  sym_0604231E               /* state initializer (zeros arrays) */
.L_06040D3C:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_06040D40:
    .4byte  road_segment_query          /* road segment geometry query */
.L_06040D44:
    mov.w   DAT_06040dc0, r2
    mov.l   .L_06040DC8, r3
    jsr @r3
    mov.l r2, @r15
    mov r0, r4
    mov.l @r15, r3
    exts.w r4, r5
    and r3, r5
    tst r5, r5
    bt      .L_06040D5C
    bra     .L_06040D5E
    mov #0x1, r5
.L_06040D5C:
    mov #0x0, r5
.L_06040D5E:
    tst r5, r5
    bf      .L_06040D66
    bra     .L_06040DA4
    nop
.L_06040D66:
    mov.l   .L_06040DCC, r4
    mov.l   .L_06040DD0, r3
    jsr @r3
    nop
    add #0x1, r8
    mov.w   DAT_06040dc2, r2
    cmp/gt r2, r8
    bf      .L_06040D7A
    bra     .L_06040E5E
    mov #-0x2, r0
.L_06040D7A:
    mov r15, r4
    jsr @r11
    add #0x8, r4
    mov r15, r0
    add #0x8, r0
    mov.b @r0, r0
    extu.b r0, r0
    bra     .L_06040D94
    and #0xF, r0
.L_06040D8C:
    bra     .L_06040E5E
    mov #-0xA, r0
.L_06040D90:
    bra     .L_06040DA4
    mov r10, r9
.L_06040D94:
    cmp/eq #0x1, r0
    bt      .L_06040D90
    cmp/eq #0x2, r0
    bt      .L_06040D90
    cmp/eq #0x9, r0
    bt      .L_06040D8C
    cmp/eq #0xA, r0
    bt      .L_06040D8C
.L_06040DA4:
    tst r9, r9
    bt      .L_06040D44
    mov.l   .L_06040DD4, r9
    mov.w   .L_06040DC4, r3
    mov.l @r9, r9
    add r3, r9
    mov.l   .L_06040DD8, r3
    jsr @r3
    mov r9, r4
    mov r0, r4
    tst r4, r4
    bt      .L_06040DDC
    bra     .L_06040E5E
    mov #-0x2, r0

    .global DAT_06040dc0
DAT_06040dc0:
    .2byte  0x0400                      /* CD status bit 10 mask */

    .global DAT_06040dc2
DAT_06040dc2:
    .2byte  0x0258                      /* 600 = max CD poll iterations */
.L_06040DC4:
    .2byte  0x043C                      /* offset to track geometry block */
    .2byte  0xFFFF                      /* alignment padding */
.L_06040DC8:
    .4byte  sym_06035C4E                /* SMPC status word reader */
.L_06040DCC:
    .4byte  0x0000FBFF                  /* ~0x0400: clears CD HIRQ bit 10 */
.L_06040DD0:
    .4byte  smpc_cmd_helper_b           /* CD HIRQ acknowledge helper */
.L_06040DD4:
    .4byte  sym_060A4D14                /* pointer to track data base */
.L_06040DD8:
    .4byte  track_intersect_test        /* track intersection geometry test */
.L_06040DDC:
    mov r15, r5
    mov.l   .L_06040E74, r3
    add #0x4, r5
    jsr @r3
    mov #0x0, r4
    mov r15, r5
    mov r15, r4
    mov.l   .L_06040E74, r3
    add #0x4, r5
    add #0x4, r4
    mov.b @r4, r4
    jsr @r3
    extu.b r4, r4
    mov r15, r0
    mov.l   .L_06040E78, r2
    add #0x4, r0
    mov.b @r0, r0
    extu.b r0, r0
    add #-0x1, r0
    shll2 r0
    mov.l @(r0, r9), r3
    and r2, r3
    tst r3, r3
    bf      .L_06040E10
    bra     .L_06040E5E
    mov #-0xF, r0
.L_06040E10:
    mov.w   DAT_06040e72, r4
    mov.l   .L_06040E7C, r3
    jsr @r3
    mov r12, r5
    mov.l @r14, r2
    mov.l   .L_06040E80, r3
    mov.l r3, @(60, r2)
    bra     .L_06040E32
    nop
.L_06040E22:
    mov.l @r14, r2
    mov.l @(60, r2), r3
    add #-0x1, r3
    tst r3, r3
    bf/s    .L_06040E32
    mov.l r3, @(60, r2)
    bra     .L_06040E5E
    mov #-0x2, r0
.L_06040E32:
    mov #0x40, r3
    mov.l r3, @r15
    mov.l   .L_06040E84, r3
    jsr @r3
    nop
    mov r0, r5
    mov.l @r15, r3
    exts.w r5, r4
    and r3, r4
    tst r4, r4
    bt      .L_06040E4C
    bra     .L_06040E4E
    mov #0x1, r4
.L_06040E4C:
    mov #0x0, r4
.L_06040E4E:
    tst r4, r4
    bt      .L_06040E22
    mov.l @r14, r3
    mov.l r13, @(60, r3)
    mov.l @r14, r4
    jsr @r11
    add #0x40, r4
    mov r13, r0
.L_06040E5E:
    add #0x14, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06040e72
DAT_06040e72:
    .2byte  0x00FC                      /* surface type query param (0xFC) */
.L_06040E74:
    .4byte  mesh_boundary_check         /* mesh boundary validator */
.L_06040E78:
    .4byte  0x40000000                  /* surface validity flag bit (bit 30) */
.L_06040E7C:
    .4byte  track_surface_type_a        /* surface type classification */
.L_06040E80:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) -- SMPC countdown init */
.L_06040E84:
    .4byte  sym_06035C4E                /* SMPC status word reader (same as above) */

    .global sym_06040E88
sym_06040E88:
    mov #0x1, r1
    mov #0x18, r7
    mov.l   .L_06040EE8, r6
    mov #0x0, r5
.L_06040E90:
    mov.l @r6, r3
    add #0x18, r3
    add r5, r3
    mov.b @r3, r2
    tst r2, r2
    bf      .L_06040EAA
    mov.l @r6, r3
    add #0x18, r3
    add r5, r3
    mov.b r1, @r3
    mov.l r5, @r4
    rts
    mov #0x0, r0
.L_06040EAA:
    add #0x1, r5
    cmp/ge r7, r5
    bf      .L_06040E90
    mov #-0x1, r2
    mov.l r2, @r4
    mov #-0x3, r0
    rts
    nop

    .global sym_06040EBA
sym_06040EBA:
    cmp/pz r4
    bf      .L_06040EC4
    mov #0x18, r2
    cmp/ge r2, r4
    bf      .L_06040EC8
.L_06040EC4:
    rts
    mov #-0x6, r0
.L_06040EC8:
    mov.l   .L_06040EE8, r5
    mov.l @r5, r0
    add #0x18, r0
    mov.b @(r0, r4), r0
    cmp/eq #0x1, r0
    bt      .L_06040ED8
    rts
    mov #-0x7, r0
.L_06040ED8:
    mov.l @r5, r3
    add #0x18, r3
    add r3, r4
    mov #0x0, r2
    mov.b r2, @r4
    mov r2, r0
    rts
    nop
.L_06040EE8:
    .4byte  sym_060A5400                /* pointer to game state base structure */

    .global sym_06040EEC
sym_06040EEC:
    mov #0x1, r1
    mov #0x18, r7
    .byte   0xD6, 0x12    /* mov.l .L_pool_06040F3C, r6 */
    mov #0x0, r5
.L_06040EF4:
    mov.l @r6, r0
    mov.b @(r0, r5), r3
    tst r3, r3
    bf      .L_06040F06
    mov.l @r6, r0
    mov.b r1, @(r0, r5)
    mov.l r5, @r4
    rts
    mov #0x0, r0
.L_06040F06:
    add #0x1, r5
    cmp/ge r7, r5
    bf      .L_06040EF4
    mov #-0x1, r3
    mov.l r3, @r4
    mov #-0x4, r0
    rts
    nop
