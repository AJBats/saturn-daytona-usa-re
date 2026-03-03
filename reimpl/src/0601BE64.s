	.text
    .global replay_playback
replay_playback:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r13
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601BEC8, r8
    mov.l   .L_0601BECC, r9
    mov.l   .L_0601BED0, r11
    mov.l   .L_0601BED4, r12
    mov.l   .L_0601BED8, r14
    mov.l   .L_0601BEDC, r0
    mov.l @r0, r0
    tst r0, r0
    bt.s    .L_0601BE94
    mov.l @r14, r14
    mov.l   .L_0601BEE0, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601BEE8
.L_0601BE94:
    mov r13, r0
    mov.w   .L_0601BEC0, r1
    mov.l   .L_0601BEE4, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_0601BEC2, r1
    mov.l   .L_0601BEE4, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_0601BEC4, r1
    mov.l   .L_0601BEE4, r3
    jsr @r3
    mov r14, r2
    mov r13, r0
    mov.w   .L_0601BEC6, r1
    mov.l   .L_0601BEE4, r3
    jsr @r3
    mov r14, r2
    bra     .L_0601C392
    nop
.L_0601BEC0:
    .short  0x1901
.L_0601BEC2:
    .short  0x1801
.L_0601BEC4:
    .short  0x1701
.L_0601BEC6:
    .short  0x1601
.L_0601BEC8:
    .long  0x00008000
.L_0601BECC:
    .long  sym_06089EDC
.L_0601BED0:
    .long  sym_0605DF57
.L_0601BED4:
    .long  sym_0605DF56
.L_0601BED8:
    .long  sym_0607E944
.L_0601BEDC:
    .long  sym_06063E1C
.L_0601BEE0:
    .long  sym_06063E20
.L_0601BEE4:
    .long  sym_06034F78
.L_0601BEE8:
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x40, r0
    bt      .L_0601BF00
    mov #0x8, r3
    mov.l   .L_0601BF8C, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601BF82, r1
    mov.l   .L_0601BF90, r3
    jsr @r3
    mov r14, r2
.L_0601BF00:
    mov r14, r0
    mov.b @(3, r0), r0
    tst #0x80, r0
    bt      .L_0601BF18
    mov #0x8, r3
    mov.l   .L_0601BF94, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601BF84, r1
    mov.l   .L_0601BF90, r3
    jsr @r3
    mov r14, r2
.L_0601BF18:
    mov r14, r0
    mov.b @(2, r0), r0
    tst #0x1, r0
    bt      .L_0601BF30
    mov #0x8, r3
    mov.l   .L_0601BF98, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601BF86, r1
    mov.l   .L_0601BF90, r3
    jsr @r3
    mov r14, r2
.L_0601BF30:
    mov r14, r0
    mov.b @(2, r0), r0
    tst #0x2, r0
    bt      .L_0601BF48
    mov #0x8, r3
    mov.l   .L_0601BF9C, r2
    mov r13, r0
    mov.w r3, @r2
    mov.w   .L_0601BF88, r1
    mov.l   .L_0601BF90, r3
    jsr @r3
    mov r14, r2
.L_0601BF48:
    mov.w   .L_0601BF8A, r10
    mov.l   .L_0601BF8C, r2
    mov.w @r2, r2
    extu.w r2, r2
    cmp/pl r2
    bf      .L_0601C032
    mov.l   .L_0601BFA0, r3
    jsr @r3
    nop
    mov.l   .L_0601BFA4, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601BFBC
    mov.l   .L_0601BFA8, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601BFBC
    mov.l   .L_0601BFAC, r6
    mov.l   .L_0601BFB0, r4
    mov.l   .L_0601BFB4, r3
    jsr @r3
    mov r8, r5
    mov r10, r6
    mov r10, r5
    mov.l   .L_0601BFB8, r3
    jsr @r3
    mov r10, r4
    bra     .L_0601BFC6
    nop
.L_0601BF82:
    .short  0x1901
.L_0601BF84:
    .short  0x1801
.L_0601BF86:
    .short  0x1701
.L_0601BF88:
    .short  0x1601
.L_0601BF8A:
    .short  0x6666
.L_0601BF8C:
    .long  sym_0605DF4E
.L_0601BF90:
    .long  sym_06034F78
.L_0601BF94:
    .long  sym_0605DF50
.L_0601BF98:
    .long  sym_0605DF52
.L_0601BF9C:
    .long  sym_0605DF54
.L_0601BFA0:
    .long  sym_06026DBC
.L_0601BFA4:
    .long  sym_06063E1C
.L_0601BFA8:
    .long  sym_06063E20
.L_0601BFAC:
    .long  0xFFFE4000
.L_0601BFB0:
    .long  0x00014872
.L_0601BFB4:
    .long  sym_06026E2E
.L_0601BFB8:
    .long  mat_scale_columns
.L_0601BFBC:
    mov.w   .L_0601C06E, r6
    mov.l   .L_0601C074, r4
    mov.l   .L_0601C078, r3
    jsr @r3
    mov r8, r5
.L_0601BFC6:
    mov.w   .L_0601C070, r4
    mov.l   .L_0601C07C, r3
    jsr @r3
    nop
    mov.b @r12, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C080, r3
    mov.l @r15, r4
    mov.l   .L_0601C084, r2
    mov.l   .L_0601C088, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r12, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C08C, r3
    mov.l   .L_0601C090, r5
    mov.l @r15, r4
    mov.l   .L_0601C094, r2
    mov.l   .L_0601C098, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l @r9, r3
    add #-0x30, r3
    mov.l r3, @r9
    mov.b @r12, r2
    add #0x1, r2
    mov.b r2, @r12
    mov #0x3, r2
    mov.b @r12, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C024
    extu.b r13, r2
    mov.b r2, @r12
.L_0601C024:
    mov.l   .L_0601C09C, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C09C, r2
    mov.w r3, @r2
    bra     .L_0601C2B0
    nop
.L_0601C032:
    mov.l   .L_0601C0A0, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bt      .L_0601C040
    bra     .L_0601C164
    nop
.L_0601C040:
    mov.l   .L_0601C0A4, r3
    jsr @r3
    nop
    mov.l   .L_0601C0A8, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601C0BC
    mov.l   .L_0601C0AC, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601C0BC
    mov.l   .L_0601C0B0, r6
    mov.l   .L_0601C0B4, r4
    mov.l   .L_0601C078, r3
    jsr @r3
    mov r8, r5
    mov r10, r6
    mov r10, r5
    mov.l   .L_0601C0B8, r3
    jsr @r3
    mov r10, r4
    bra     .L_0601C0C6
    nop
.L_0601C06E:
    .short  0x228F
.L_0601C070:
    .short  0x1000
    .short  0xFFFF
.L_0601C074:
    .long  0x00014872
.L_0601C078:
    .long  sym_06026E2E
.L_0601C07C:
    .long  mat_rot_y
.L_0601C080:
    .long  sym_060621D8
.L_0601C084:
    .long  sym_0606212C
.L_0601C088:
    .long  sym_06031D8C
.L_0601C08C:
    .long  sym_06062180
.L_0601C090:
    .long  sym_06089E9C
.L_0601C094:
    .long  sym_060620D8
.L_0601C098:
    .long  sym_06031A28
.L_0601C09C:
    .long  sym_0605DF4E
.L_0601C0A0:
    .long  sym_0605DF50
.L_0601C0A4:
    .long  sym_06026DBC
.L_0601C0A8:
    .long  sym_06063E1C
.L_0601C0AC:
    .long  sym_06063E20
.L_0601C0B0:
    .long  0xFFFE4000
.L_0601C0B4:
    .long  0xFFFEB78E
.L_0601C0B8:
    .long  mat_scale_columns
.L_0601C0BC:
    mov.w   .L_0601C132, r6
    mov.l   .L_0601C138, r4
    mov.l   .L_0601C13C, r3
    jsr @r3
    mov r8, r5
.L_0601C0C6:
    mov.w   .L_0601C134, r4
    mov.l   .L_0601C140, r3
    jsr @r3
    nop
    mov.b @r11, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C144, r3
    mov.l @r15, r4
    mov.l   .L_0601C148, r2
    mov.l   .L_0601C14C, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r11, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C150, r3
    mov.l   .L_0601C154, r5
    mov.l @r15, r4
    mov.l   .L_0601C158, r2
    mov.l   .L_0601C15C, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l @r9, r3
    add #-0x30, r3
    mov.l r3, @r9
    mov.b @r11, r2
    add #0x1, r2
    mov.b r2, @r11
    mov #0x3, r2
    mov.b @r11, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C124
    extu.b r13, r2
    mov.b r2, @r11
.L_0601C124:
    mov.l   .L_0601C160, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C160, r2
    mov.w r3, @r2
    bra     .L_0601C2B0
    nop
.L_0601C132:
    .short  0x228F
.L_0601C134:
    .short  0x7000
    .short  0xFFFF
.L_0601C138:
    .long  0xFFFEB78E
.L_0601C13C:
    .long  sym_06026E2E
.L_0601C140:
    .long  mat_rot_y
.L_0601C144:
    .long  sym_060621D8
.L_0601C148:
    .long  sym_0606212C
.L_0601C14C:
    .long  sym_06031D8C
.L_0601C150:
    .long  sym_06062180
.L_0601C154:
    .long  sym_06089E9C
.L_0601C158:
    .long  sym_060620D8
.L_0601C15C:
    .long  sym_06031A28
.L_0601C160:
    .long  sym_0605DF50
.L_0601C164:
    mov.l   .L_0601C1F4, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bf      .L_0601C224
    mov r10, r6
    mov r10, r5
    mov.l   .L_0601C1F8, r3
    jsr @r3
    mov r10, r4
    mov.w   .L_0601C1EE, r6
    mov.l   .L_0601C1FC, r4
    mov.l   .L_0601C200, r3
    jsr @r3
    mov r8, r5
    mov.w   .L_0601C1F0, r4
    mov.l   .L_0601C204, r3
    jsr @r3
    nop
    mov.b @r12, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C208, r3
    mov.l @r15, r4
    mov.l   .L_0601C20C, r2
    mov.l   .L_0601C210, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r12, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C214, r3
    mov.l   .L_0601C218, r5
    mov.l @r15, r4
    mov.l   .L_0601C21C, r2
    mov.l   .L_0601C220, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l @r9, r3
    add #-0x30, r3
    mov.l r3, @r9
    mov.b @r12, r2
    add #0x1, r2
    mov.b r2, @r12
    mov.b @r12, r3
    mov #0x3, r2
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C1E0
    extu.b r13, r2
    mov.b r2, @r12
.L_0601C1E0:
    mov.l   .L_0601C1F4, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C1F4, r2
    mov.w r3, @r2
    bra     .L_0601C2B0
    nop
.L_0601C1EE:
    .short  0xDD71
.L_0601C1F0:
    .short  0x1000
    .short  0xFFFF
.L_0601C1F4:
    .long  sym_0605DF52
.L_0601C1F8:
    .long  mat_scale_columns
.L_0601C1FC:
    .long  0x00014872
.L_0601C200:
    .long  sym_06026E2E
.L_0601C204:
    .long  mat_rot_y
.L_0601C208:
    .long  sym_060621D8
.L_0601C20C:
    .long  sym_0606212C
.L_0601C210:
    .long  sym_06031D8C
.L_0601C214:
    .long  sym_06062180
.L_0601C218:
    .long  sym_06089E9C
.L_0601C21C:
    .long  sym_060620D8
.L_0601C220:
    .long  sym_06031A28
.L_0601C224:
    mov.l   .L_0601C2C0, r3
    mov.w @r3, r3
    extu.w r3, r3
    cmp/pl r3
    bf      .L_0601C2B0
    mov.l   .L_0601C2C4, r3
    jsr @r3
    nop
    mov r10, r6
    mov r10, r5
    mov.l   .L_0601C2C8, r3
    jsr @r3
    mov r10, r4
    mov.w   .L_0601C2BC, r6
    mov.l   .L_0601C2CC, r4
    mov.l   .L_0601C2D0, r3
    jsr @r3
    mov r8, r5
    mov.w   .L_0601C2BE, r4
    mov.l   .L_0601C2D4, r3
    jsr @r3
    nop
    mov.b @r11, r5
    extu.b r5, r5
    add #0x12, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C2D8, r3
    mov.l @r15, r4
    mov.l   .L_0601C2DC, r2
    mov.l   .L_0601C2E0, r1
    add r3, r5
    add r2, r4
    mov.l @r5, r5
    jsr @r1
    mov.l @r4, r4
    mov.b @r11, r6
    extu.b r6, r6
    add #0x12, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C2E4, r3
    mov.l   .L_0601C2E8, r5
    mov.l @r15, r4
    mov.l   .L_0601C2EC, r2
    mov.l   .L_0601C2F0, r1
    add r3, r6
    mov.w @r5, r5
    add r2, r4
    mov.l @r6, r6
    jsr @r1
    mov.l @r4, r4
    mov.l @r9, r3
    add #-0x30, r3
    mov.l r3, @r9
    mov.b @r11, r2
    add #0x1, r2
    mov.b r2, @r11
    mov #0x3, r2
    mov.b @r11, r3
    extu.b r3, r3
    cmp/ge r2, r3
    bf      .L_0601C2A6
    extu.b r13, r2
    mov.b r2, @r11
.L_0601C2A6:
    mov.l   .L_0601C2C0, r3
    mov.w @r3, r3
    add #-0x1, r3
    mov.l   .L_0601C2C0, r2
    mov.w r3, @r2
.L_0601C2B0:
    mov.l   .L_0601C2F4, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601C2F8
    bra     .L_0601C392
    nop
.L_0601C2BC:
    .short  0xDD71
.L_0601C2BE:
    .short  0x7000
.L_0601C2C0:
    .long  sym_0605DF54
.L_0601C2C4:
    .long  sym_06026DBC
.L_0601C2C8:
    .long  mat_scale_columns
.L_0601C2CC:
    .long  0xFFFEB78E
.L_0601C2D0:
    .long  sym_06026E2E
.L_0601C2D4:
    .long  mat_rot_y
.L_0601C2D8:
    .long  sym_060621D8
.L_0601C2DC:
    .long  sym_0606212C
.L_0601C2E0:
    .long  sym_06031D8C
.L_0601C2E4:
    .long  sym_06062180
.L_0601C2E8:
    .long  sym_06089E9C
.L_0601C2EC:
    .long  sym_060620D8
.L_0601C2F0:
    .long  sym_06031A28
.L_0601C2F4:
    .long  sym_06059F30
.L_0601C2F8:
    mov.w   .L_0601C3A6, r0
    mov.w @(r0, r14), r3
    tst r3, r3
    bf      .L_0601C30E
    mov.w   .L_0601C3A8, r0
    mov.w @(r0, r14), r3
    tst r3, r3
    bf      .L_0601C30E
    exts.w r13, r3
    mov.l   .L_0601C3AC, r2
    mov.w r3, @r2
.L_0601C30E:
    mov.w   .L_0601C3A6, r0
    mov.w @(r0, r14), r0
    tst r0, r0
    bf      .L_0601C31E
    mov.w   .L_0601C3A8, r0
    mov.w @(r0, r14), r0
    tst r0, r0
    bt      .L_0601C392
.L_0601C31E:
    mov.l   .L_0601C3B0, r3
    jsr @r3
    nop
    mov.l   .L_0601C3B4, r10
    mov.l   .L_0601C3B8, r3
    mov.w   .L_0601C3AA, r2
    mov.l @(8, r10), r6
    mov.l @(4, r10), r5
    neg r6, r6
    add r2, r5
    add r3, r6
    mov.l   .L_0601C3BC, r3
    jsr @r3
    mov.l @r10, r4
    mov.l   .L_0601C3C0, r3
    jsr @r3
    mov r8, r4
    mov.w   .L_0601C3A6, r0
    mov.l   .L_0601C3C4, r3
    mov.w @(r0, r14), r5
    shll r5
    add r3, r5
    mov.w @r5, r5
    add #0xE, r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0601C3C8, r2
    mov.l @r15, r4
    mov.l   .L_0601C3CC, r1
    mov.l   .L_0601C3D0, r3
    add r2, r5
    add r1, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.w   .L_0601C3A6, r0
    mov.l   .L_0601C3C4, r3
    mov.w @(r0, r14), r6
    shll r6
    add r3, r6
    mov.w @r6, r6
    add #0xE, r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0601C3D4, r2
    mov.l   .L_0601C3D8, r5
    mov.l @r15, r4
    mov.l   .L_0601C3DC, r1
    mov.l   .L_0601C3E0, r3
    add r2, r6
    mov.w @r5, r5
    add r1, r4
    mov.l @r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l @r9, r2
    add #-0x30, r2
    mov.l r2, @r9
.L_0601C392:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0601C3A6:
    .short  0x0166
.L_0601C3A8:
    .short  0x0152
.L_0601C3AA:
    .short  0xCCCD
.L_0601C3AC:
    .long  sym_0605DF44
.L_0601C3B0:
    .long  sym_06026DBC
.L_0601C3B4:
    .long  sym_06044670
.L_0601C3B8:
    .long  0xFFFF6000
.L_0601C3BC:
    .long  sym_06026E2E
.L_0601C3C0:
    .long  mat_rot_y
.L_0601C3C4:
    .long  sym_0605DF46
.L_0601C3C8:
    .long  sym_060621D8
.L_0601C3CC:
    .long  sym_0606212C
.L_0601C3D0:
    .long  sym_06031D8C
.L_0601C3D4:
    .long  sym_06062180
.L_0601C3D8:
    .long  sym_06089E9C
.L_0601C3DC:
    .long  sym_060620D8
.L_0601C3E0:
    .long  sym_06031A28
