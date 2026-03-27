
    .section .text.FUN_0600AC44


    .global FUN_0600AC44
    .type FUN_0600AC44, @function
FUN_0600AC44:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov r5, r13
    mov.l r11, @-r15
    shll2 r13
    mov.l r10, @-r15
    mov r4, r10
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov.l   .L_0600AD38, r3
    add r3, r13
    mov.b @(3, r13), r0
    mov r0, r2
    extu.b r2, r2
    mov #0x48, r0
    mov.l r2, @(8, r15)
    mov.l @(r0, r10), r3
    mov #0x40, r0
    neg r3, r3
    mov.l r3, @(4, r15)
    mov.l @(r0, r10), r3
    shll r3
    mov.l r3, @r15
    mov.b @r13, r2
    mov.l   .L_0600AD3C, r1
    extu.b r2, r2
    jsr @r1
    mov.l r2, @(12, r15)
    mov.l   .L_0600AD40, r14
    mov.l   .L_0600AD44, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    neg r6, r6
    jsr @r3
    mov.l @r14, r4
    mov.l   .L_0600AD48, r3
    jsr @r3
    mov.l @r15, r4
    mov.l   .L_0600AD4C, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l   .L_0600AD50, r11
    mov.l @(12, r15), r14
    mov.l   .L_0600AD54, r5
    mov.l   .L_0600AD58, r3
    shll2 r14
    add r14, r5
    mov r14, r4
    mov.l @r5, r5
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov r14, r4
    mov.l   .L_0600AD68, r2
    mov.l   .L_0600AD5C, r8
    mov.l   .L_0600AD60, r6
    mov.l @(8, r15), r9
    mov.l   .L_0600AD64, r3
    add r8, r4
    add r14, r6
    shll r9
    mov.l @r6, r6
    add r3, r9
    mov.w @r9, r5
    extu.w r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l   .L_0600AD6C, r14
    mov.l @r14, r3
    add #-0x30, r3
    mov.l r3, @r14
    mov.b @(1, r13), r0
    mov.l   .L_0600AD3C, r3
    mov r0, r2
    extu.b r2, r2
    jsr @r3
    mov.l r2, @(8, r15)
    mov.l   .L_0600AD70, r12
    mov.l   .L_0600AD44, r3
    mov.l @(8, r12), r6
    mov.l @(4, r12), r5
    neg r6, r6
    jsr @r3
    mov.l @r12, r4
    mov.l   .L_0600AD48, r3
    jsr @r3
    mov.l @r15, r4
    mov.l   .L_0600AD4C, r3
    jsr @r3
    mov.l @(4, r15), r4
    mov.l @(8, r15), r12
    mov.l   .L_0600AD54, r5
    mov.l   .L_0600AD58, r3
    shll2 r12
    add r12, r5
    mov r12, r4
    mov.l @r5, r5
    add r11, r4
    jsr @r3
    mov.l @r4, r4
    mov r12, r4
    mov.l   .L_0600AD68, r3
    mov.l   .L_0600AD60, r6
    mov.w @r9, r5
    add r8, r4
    add r12, r6
    extu.w r5, r5
    mov.l @r6, r6
    jsr @r3
    mov.l @r4, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
    mov #0x50, r0
    mov.l @(r0, r10), r3
    neg r3, r3
    bra     .L_0600AD74
    nop
    .2byte  0xFFFF
.L_0600AD38:
    .4byte  sym_0605A1D5
.L_0600AD3C:
    .4byte  sym_06027080
.L_0600AD40:
    .4byte  sym_06044640
.L_0600AD44:
    .4byte  sym_060270F2
.L_0600AD48:
    .4byte  FUN_060271A2
.L_0600AD4C:
    .4byte  FUN_06027158
.L_0600AD50:
    .4byte  sym_0606212C
.L_0600AD54:
    .4byte  sym_060621D8
.L_0600AD58:
    .4byte  sym_06032158
.L_0600AD5C:
    .4byte  sym_060620D8
.L_0600AD60:
    .4byte  sym_06062180
.L_0600AD64:
    .4byte  sym_06089E44
.L_0600AD68:
    .4byte  sym_06031DF4
.L_0600AD6C:
    .4byte  sym_0608A52C
.L_0600AD70:
    .4byte  sym_0604464C
.L_0600AD74:
    mov.l r3, @r15
    mov.b @(2, r13), r0
    mov.l   .L_pool_0600AE2C, r1
    mov r0, r2
    extu.b r2, r2
    jsr @r1
    mov.l r2, @(4, r15)
    mov.l   .L_pool_0600AE30, r13
    mov.l   .L_pool_0600AE34, r3
    mov.l @(8, r13), r6
    mov.l @(4, r13), r5
    neg r6, r6
    jsr @r3
    mov.l @r13, r4
    mov.l   .L_pool_0600AE38, r3
    jsr @r3
    mov.l @r15, r4
    mov.l @(4, r15), r13
    mov.l   .L_pool_0600AE3C, r5
    mov.l   .L_pool_0600AE40, r3
    shll2 r13
    add r13, r5
    add r13, r11
    mov.l @r5, r5
    jsr @r3
    mov.l @r11, r4
    mov.l   .L_pool_0600AE44, r6
    add r13, r8
    mov.l   .L_pool_0600AE48, r3
    mov.w @r9, r5
    add r13, r6
    extu.w r5, r5
    mov.l @r6, r6
    jsr @r3
    mov.l @r8, r4
    mov.l @r14, r2
    add #-0x30, r2
    mov.l r2, @r14
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


   .global FUN_0600ADD4
   .type FUN_0600ADD4, @function
FUN_0600ADD4:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600AE4C, r11
    mov.l   .L_0600AE50, r13
    mov.l   .L_0600AE54, r14
    mov.l   .L_0600AE58, r3
    mov.l @r14, r14
    mov.l r14, @r3
    mov.l   .L_0600AE5C, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_0600AE60, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l @(32, r14), r4
    mov.l   .L_0600AE64, r2
    mov.l   .L_0600AE68, r3
    jsr @r3
    add r2, r4
    mov.l @(36, r14), r4
    mov.l   .L_0600AE6C, r3
    jsr @r3
    neg r4, r4
    mov.l   .L_0600AE70, r2
    mov.l   .L_0600AE74, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600AE7C
    mov.l @(28, r14), r4
    neg r4, r4
    mov.w @r11, r3
    extu.w r3, r2
    shll2 r2
    mov.l   .L_0600AE78, r3
    add r2, r3
    mov.l @r3, r2
    bra     .L_0600AE94
    add r2, r4
.L_pool_0600AE2C:
    .4byte  sym_06027080
.L_pool_0600AE30:
    .4byte  sym_06044670
.L_pool_0600AE34:
    .4byte  sym_060270F2
.L_pool_0600AE38:
    .4byte  FUN_06027158
.L_pool_0600AE3C:
    .4byte  sym_060621D8
.L_pool_0600AE40:
    .4byte  sym_06032158
.L_pool_0600AE44:
    .4byte  sym_06062180
.L_pool_0600AE48:
    .4byte  sym_06031DF4
.L_0600AE4C:
    .4byte  sym_06063F46
.L_0600AE50:
    .4byte  FUN_06026E94
.L_0600AE54:
    .4byte  sym_0607E944
.L_0600AE58:
    .4byte  sym_0607E940
.L_0600AE5C:
    .4byte  sym_06026DBC
.L_0600AE60:
    .4byte  sym_06026E2E
.L_0600AE64:
    .4byte  0x00008000
.L_0600AE68:
    .4byte  FUN_06026EDE
.L_0600AE6C:
    .4byte  FUN_06026F2A
.L_0600AE70:
    .4byte  sym_0607EBC4
.L_0600AE74:
    .4byte  0x00800008
.L_0600AE78:
    .4byte  sym_0605BDCC
.L_0600AE7C:
    mov.l @(28, r14), r4
    neg r4, r4
    mov.l   .L_0600AF1C, r3
    mov.l @r3, r3
    add r3, r4
    mov.w @r11, r2
    extu.w r2, r1
    shll2 r1
    mov.l   .L_0600AF20, r2
    add r1, r2
    mov.l @r2, r1
    add r1, r4
.L_0600AE94:
    jsr @r13
    nop
    mov.w   .L_0600AF12, r0
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.l   .L_0600AF24, r3
    jsr @r3
    nop
    mov.l   .L_0600AF28, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600AF8C
    mov.l   .L_0600AF2C, r5
    mov.l   .L_0600AF30, r4
    mov.l   .L_0600AF34, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_0600AF38, r6
    mov.l   .L_0600AF3C, r5
    mov.l   .L_0600AF40, r4
    mov.l   .L_0600AF44, r3
    mov.l @r6, r6
    mov.w @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov #0x0, r6
    mov.w   .L_0600AF14, r0
    mov.l   .L_0600AF48, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   .L_0600AF16, r0
    mov.l   .L_0600AF4C, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_0600AF18, r0
    jsr @r13
    mov.l @(r0, r14), r4
    mov.l   .L_0600AF50, r0
    mov.b @r0, r0
    tst #0x2, r0
    bf      .L_0600AEF4
    mov #0x0, r5
    .byte   0xBD, 0xD2    /* bsr FUN_0600AA98 (external) */
    mov r14, r4
.L_0600AEF4:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x1, r0
    bt/s    .L_0600AF5C
    mov #0x0, r12
    mov #0xD, r12
    mov.w @r11, r4
    extu.w r4, r4
    mov.l   .L_0600AF54, r3
    add r3, r4
    mov.b @r4, r4
    mov.l   .L_0600AF58, r2
    mov.l @r2, r2
    bra     .L_0600AF60
    add r2, r4
.L_0600AF12:
    .2byte  0x01D8
.L_0600AF14:
    .2byte  0x01B4
.L_0600AF16:
    .2byte  0x01D0
.L_0600AF18:
    .2byte  0x01C8
    .2byte  0xFFFF
.L_0600AF1C:
    .4byte  sym_06078668
.L_0600AF20:
    .4byte  sym_0605BDCC
.L_0600AF24:
    .4byte  FUN_06026EDE
.L_0600AF28:
    .4byte  sym_06059F30
.L_0600AF2C:
    .4byte  sym_060621E8
.L_0600AF30:
    .4byte  sym_0606213C
.L_0600AF34:
    .4byte  sym_06031D8C
.L_0600AF38:
    .4byte  sym_06062190
.L_0600AF3C:
    .4byte  sym_06089E44
.L_0600AF40:
    .4byte  sym_060620E8
.L_0600AF44:
    .4byte  sym_06031A28
.L_0600AF48:
    .4byte  sym_06026E2E
.L_0600AF4C:
    .4byte  FUN_06026F2A
.L_0600AF50:
    .4byte  sym_06082A25
.L_0600AF54:
    .4byte  sym_06044740
.L_0600AF58:
    .4byte  sym_06083258
.L_0600AF5C:
    mov.l   .L_pool_0600B00C, r4
    mov.l @r4, r4
.L_0600AF60:
    jsr @r13
    nop
    extu.w r12, r14
    mov.l   .L_pool_0600B010, r5
    mov.l   .L_pool_0600B014, r4
    mov.l   .L_pool_0600B018, r3
    shll2 r14
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_pool_0600B01C, r6
    mov.l   .L_pool_0600B020, r5
    mov.l   .L_pool_0600B024, r4
    mov.l   .L_pool_0600B028, r3
    add r14, r6
    mov.w @r5, r5
    add r14, r4
    mov.l @r6, r6
    jsr @r3
    mov.l @r4, r4
.L_0600AF8C:
    mov.l   .L_0600B02C, r2
    mov.l   .L_pool_0600B030, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600AF9E
    mov.l   .L_pool_0600B034, r3
    jsr @r3
    nop
.L_0600AF9E:
    mov.l   .L_pool_0600B038, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0600AFB2
    .type FUN_0600AFB2, @function
FUN_0600AFB2:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_0600B03C, r11
    mov.l   .L_0600B040, r13
    mov.l   .L_0600B044, r14
    mov.l   .L_0600B048, r3
    mov.l @r14, r14
    mov.l r14, @r3
    mov.l   .L_0600B04C, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_0600B050, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l @(32, r14), r4
    mov.l   .L_0600B054, r2
    mov.l   .L_0600B058, r3
    jsr @r3
    add r2, r4
    mov.l @(36, r14), r4
    mov.l   .L_0600B05C, r3
    jsr @r3
    neg r4, r4
    mov.l   .L_0600B02C, r2
    mov.l   .L_0600B060, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600B068
    mov.l @(28, r14), r4
    neg r4, r4
    mov.w @r11, r3
    extu.w r3, r2
    shll2 r2
    mov.l   .L_0600B064, r3
    add r2, r3
    mov.l @r3, r2
    bra     .L_0600B080
    add r2, r4
    .2byte  0xFFFF
.L_pool_0600B00C:
    .4byte  sym_06083258
.L_pool_0600B010:
    .4byte  sym_060621D8
.L_pool_0600B014:
    .4byte  sym_0606212C
.L_pool_0600B018:
    .4byte  sym_06031D8C
.L_pool_0600B01C:
    .4byte  sym_06062180
.L_pool_0600B020:
    .4byte  sym_06089E44
.L_pool_0600B024:
    .4byte  sym_060620D8
.L_pool_0600B028:
    .4byte  sym_06031A28
.L_0600B02C:
    .4byte  sym_0607EBC4
.L_pool_0600B030:
    .4byte  0x20020000
.L_pool_0600B034:
    .4byte  FUN_0601BE64
.L_pool_0600B038:
    .4byte  sym_06089EDC
.L_0600B03C:
    .4byte  sym_06063F46
.L_0600B040:
    .4byte  FUN_06027158
.L_0600B044:
    .4byte  sym_0607E944
.L_0600B048:
    .4byte  sym_0607E940
.L_0600B04C:
    .4byte  sym_06027080
.L_0600B050:
    .4byte  sym_060270F2
.L_0600B054:
    .4byte  0x00008000
.L_0600B058:
    .4byte  FUN_060271A2
.L_0600B05C:
    .4byte  FUN_060271EE
.L_0600B060:
    .4byte  0x00800008
.L_0600B064:
    .4byte  sym_0605BDCC
.L_0600B068:
    mov.l @(28, r14), r4
    neg r4, r4
    mov.l   .L_0600B108, r3
    mov.l @r3, r3
    add r3, r4
    mov.w @r11, r2
    extu.w r2, r1
    shll2 r1
    mov.l   .L_0600B10C, r2
    add r1, r2
    mov.l @r2, r1
    add r1, r4
.L_0600B080:
    jsr @r13
    nop
    mov.w   DAT_0600b100, r0
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r3
    add r3, r4
    mov.l   .L_0600B110, r3
    jsr @r3
    nop
    mov.l   .L_0600B114, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B17A
    mov.l   .L_0600B118, r5
    mov.l   .L_0600B11C, r4
    mov.l   .L_0600B120, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_0600B124, r6
    mov.l   .L_0600B128, r5
    mov.l   .L_0600B12C, r4
    mov.l   .L_0600B130, r3
    mov.l @r6, r6
    mov.w @r5, r5
    extu.w r5, r5
    jsr @r3
    mov.l @r4, r4
    mov #0x0, r6
    mov.w   DAT_0600b102, r0
    mov.l   .L_0600B134, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   DAT_0600b104, r0
    mov.l   .L_0600B138, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   DAT_0600b106, r0
    jsr @r13
    mov.l @(r0, r14), r4
    mov.l   .L_0600B13C, r0
    mov.b @r0, r0
    tst #0x2, r0
    bf      .L_0600B0E2
    mov #0x0, r5
    .byte   0xBD, 0xB1    /* bsr FUN_0600AC44 (external 0x0600AC44) */
    mov r14, r4
.L_0600B0E2:
    mov r14, r0
    mov.b @(1, r0), r0
    tst #0x1, r0
    bt/s    .L_0600B148
    mov #0x0, r12
    mov #0xD, r12
    mov.w @r11, r4
    extu.w r4, r4
    mov.l   .L_0600B140, r3
    add r3, r4
    mov.b @r4, r4
    mov.l   .L_0600B144, r2
    mov.l @r2, r2
    bra     .L_0600B14C
    add r2, r4

    .global DAT_0600b100
DAT_0600b100:
    .2byte  0x01D8

    .global DAT_0600b102
DAT_0600b102:
    .2byte  0x01B4

    .global DAT_0600b104
DAT_0600b104:
    .2byte  0x01D0

    .global DAT_0600b106
DAT_0600b106:
    .2byte  0x01C8
.L_0600B108:
    .4byte  sym_06078668
.L_0600B10C:
    .4byte  sym_0605BDCC
.L_0600B110:
    .4byte  FUN_060271A2
.L_0600B114:
    .4byte  sym_06059F30
.L_0600B118:
    .4byte  sym_060621E8
.L_0600B11C:
    .4byte  sym_0606213C
.L_0600B120:
    .4byte  sym_06032158
.L_0600B124:
    .4byte  sym_06062190
.L_0600B128:
    .4byte  sym_06089E44
.L_0600B12C:
    .4byte  sym_060620E8
.L_0600B130:
    .4byte  sym_06031DF4
.L_0600B134:
    .4byte  sym_060270F2
.L_0600B138:
    .4byte  FUN_060271EE
.L_0600B13C:
    .4byte  sym_06082A25
.L_0600B140:
    .4byte  sym_06044740
.L_0600B144:
    .4byte  sym_06083258
.L_0600B148:
    mov.l   .L_pool_0600B1D8, r4
    mov.l @r4, r4
.L_0600B14C:
    jsr @r13
    nop
    extu.w r12, r14
    mov.l   .L_pool_0600B1DC, r5
    mov.l   .L_pool_0600B1E0, r4
    mov.l   .L_pool_0600B1E4, r3
    shll2 r14
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    mov.l   .L_pool_0600B1E8, r6
    mov.l   .L_pool_0600B1EC, r5
    mov.l   .L_pool_0600B1F0, r4
    mov.l   .L_pool_0600B1F4, r3
    add r14, r6
    mov.w @r5, r5
    add r14, r4
    mov.l @r6, r6
    extu.w r5, r5
    jsr @r3
    mov.l @r4, r4
.L_0600B17A:
    mov.l   .L_pool_0600B1F8, r2
    mov.l   .L_pool_0600B1FC, r3
    mov.l @r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0600B18C
    mov.l   .L_pool_0600B200, r3
    jsr @r3
    nop
.L_0600B18C:
    mov.l   .L_pool_0600B204, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global FUN_0600B1A0
    .type FUN_0600B1A0, @function
FUN_0600B1A0:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_0600B208, r11
    mov.l @r11, r11
    mov.l   .L_0600B20C, r14
    mov.l @r14, r14
    mov.l   .L_0600B210, r3
    mov.l r14, @r3
    mov.l   .L_0600B214, r0
    bra     .L_0600B230
    mov.l @r0, r0
.L_0600B1BE:
    mov.l   .L_0600B218, r13
    mov.l   .L_0600B21C, r12
    bra     .L_0600B23C
    nop
.L_0600B1C6:
    mov.l   .L_0600B220, r13
    mov.l   .L_0600B224, r12
    bra     .L_0600B23C
    nop
.L_0600B1CE:
    mov.l   .L_0600B228, r13
    mov.l   .L_0600B22C, r12
    bra     .L_0600B23C
    nop
    .2byte  0xFFFF
.L_pool_0600B1D8:
    .4byte  sym_06083258
.L_pool_0600B1DC:
    .4byte  sym_060621D8
.L_pool_0600B1E0:
    .4byte  sym_0606212C
.L_pool_0600B1E4:
    .4byte  sym_06032158
.L_pool_0600B1E8:
    .4byte  sym_06062180
.L_pool_0600B1EC:
    .4byte  sym_06089E44
.L_pool_0600B1F0:
    .4byte  sym_060620D8
.L_pool_0600B1F4:
    .4byte  sym_06031DF4
.L_pool_0600B1F8:
    .4byte  sym_0607EBC4
.L_pool_0600B1FC:
    .4byte  0x20020000
.L_pool_0600B200:
    .4byte  FUN_0601C3E4
.L_pool_0600B204:
    .4byte  sym_0608A52C
.L_0600B208:
    .4byte  sym_0607EB8C
.L_0600B20C:
    .4byte  sym_0607E944
.L_0600B210:
    .4byte  sym_0607E940
.L_0600B214:
    .4byte  sym_0607EAD8
.L_0600B218:
    .4byte  sym_06063488
.L_0600B21C:
    .4byte  sym_06063434
.L_0600B220:
    .4byte  sym_060634A4
.L_0600B224:
    .4byte  sym_06063450
.L_0600B228:
    .4byte  sym_060634C0
.L_0600B22C:
    .4byte  sym_0606346C
.L_0600B230:
    cmp/eq #0x0, r0
    bt      .L_0600B1BE
    cmp/eq #0x1, r0
    bt      .L_0600B1C6
    cmp/eq #0x2, r0
    bt      .L_0600B1CE
.L_0600B23C:
    mov.l   .L_0600B304, r3
    jsr @r3
    nop
    mov.l @(24, r14), r6
    mov.l @(20, r14), r5
    mov.l   .L_0600B308, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov.l   .L_0600B30C, r3
    jsr @r3
    mov.l @(32, r14), r4
    mov.l   .L_0600B310, r3
    jsr @r3
    mov.l @(36, r14), r4
    mov.l   .L_0600B314, r3
    jsr @r3
    mov.l @(28, r14), r4
    mov.w   .L_0600B2FC, r0
    mov.l   .L_0600B30C, r3
    mov.l @(r0, r14), r4
    add #-0xC, r0
    mov.l @(r0, r14), r2
    jsr @r3
    add r2, r4
    mov.l   .L_0600B318, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600B2E6
    mov.l   .L_0600B31C, r5
    mov.l   .L_0600B320, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @(24, r13), r4
    mov.l   .L_0600B324, r6
    mov.l   .L_0600B328, r2
    mov.l @r6, r6
    mov r2, r5
    mov.l r2, @(4, r15)
    mov.w @r5, r5
    mov.l   .L_0600B32C, r3
    jsr @r3
    mov.l @(24, r12), r4
    mov #0x0, r6
    mov.w   .L_0600B2FE, r0
    mov.l   .L_0600B308, r3
    mov.l @(r0, r14), r5
    jsr @r3
    mov r6, r4
    mov.w   .L_0600B300, r0
    mov.l   .L_0600B310, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   .L_0600B302, r0
    mov.l   .L_0600B330, r2
    mov.l   .L_0600B314, r3
    mov.l @(r0, r14), r4
    mov.l @r2, r2
    jsr @r3
    add r2, r4
    mov.l @(12, r11), r5
    shll2 r5
    mov.l r5, @r15
    mov.l   .L_0600B334, r3
    mov.l @r15, r4
    mov.l   .L_0600B320, r2
    add r3, r5
    add r13, r4
    mov.l @r5, r5
    jsr @r2
    mov.l @r4, r4
    mov.l @(12, r11), r6
    shll2 r6
    mov.l r6, @r15
    mov.l   .L_0600B338, r3
    mov.l @(4, r15), r5
    mov.l @r15, r4
    mov.l   .L_0600B32C, r2
    add r3, r6
    mov.w @r5, r5
    add r12, r4
    mov.l @r6, r6
    jsr @r2
    mov.l @r4, r4
    .byte   0xB9, 0x97    /* bsr FUN_0600A614 (dual-obj renderer) */
    nop
.L_0600B2E6:
    mov.l   .L_0600B33C, r4
    mov.l @r4, r2
    add #-0x30, r2
    mov.l r2, @r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_0600B2FC:
    .2byte  0x01D8
.L_0600B2FE:
    .2byte  0x01B4
.L_0600B300:
    .2byte  0x01D0
.L_0600B302:
    .2byte  0x01C8
.L_0600B304:
    .4byte  sym_06026DBC
.L_0600B308:
    .4byte  sym_06026E2E
.L_0600B30C:
    .4byte  FUN_06026EDE
.L_0600B310:
    .4byte  FUN_06026F2A
.L_0600B314:
    .4byte  FUN_06026E94
.L_0600B318:
    .4byte  sym_06059F30
.L_0600B31C:
    .4byte  sym_06063510
.L_0600B320:
    .4byte  sym_06031D8C
.L_0600B324:
    .4byte  sym_060634F4
.L_0600B328:
    .4byte  sym_06089E98
.L_0600B32C:
    .4byte  sym_06031A28
.L_0600B330:
    .4byte  sym_06083258
.L_0600B334:
    .4byte  sym_060634F8
.L_0600B338:
    .4byte  sym_060634DC
.L_0600B33C:
    .4byte  sym_06089EDC
