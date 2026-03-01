
    .section .text.FUN_06036F0C


    .global vdp_init_master
    .type vdp_init_master, @function
vdp_init_master:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.w   DAT_06036fba, r10
    mov.l   _pool_screen_width, r12
    mov.l   _pool_screen_height, r13
    mov.l   _pool_display_state, r14
    mov.l   _pool_bios_tv_flag_ptr, r7
    mov.l @r7, r7
    mov.l   _pool_mask_clear_vlines, r3
    mov.w @r14, r2
    and r3, r2
    mov.w r2, @r14
    bra     .L_06036F4C
    extu.b r5, r0

.L_06036F30:
    mov.w   DAT_06036fbc, r2
    bra     .L_06036F58
    mov.w r2, @r13

.L_06036F36:
    mov.w   DAT_06036fbe, r2
    mov.w r2, @r13
    mov.w @r14, r0
    bra     .L_06036F48
    or #0x10, r0

.L_06036F40:
    mov.w   DAT_06036fc0, r2
    mov.w r2, @r13
    mov.w @r14, r0
    or #0x20, r0
.L_06036F48:
    bra     .L_06036F58
    mov.w r0, @r14

.L_06036F4C:
    cmp/eq #0x0, r0
    bt      .L_06036F30
    cmp/eq #0x1, r0
    bt      .L_06036F36
    cmp/eq #0x2, r0
    bt      .L_06036F40

.L_06036F58:
    mov.l   _pool_mask_clear_interlace, r2
    mov.w @r14, r3
    and r2, r3
    mov.w r3, @r14
    bra     .L_06036F7A
    extu.b r4, r0

.L_06036F64:
    mov.w @r14, r0
    bra     .L_06036F76
    or #0x80, r0

.L_06036F6A:
    mov.w @r13, r2
    mov.w @r13, r3
    add r2, r3
    mov.w r3, @r13
    mov.w @r14, r0
    or #0xC0, r0
.L_06036F76:
    bra     .L_06036F86
    mov.w r0, @r14

.L_06036F7A:
    cmp/eq #0x0, r0
    bt      .L_06036F86
    cmp/eq #0x2, r0
    bt      .L_06036F64
    cmp/eq #0x3, r0
    bt      .L_06036F6A

.L_06036F86:
    mov.l   _pool_mask_clear_res, r2
    mov.w @r14, r3
    and r2, r3
    mov.w r3, @r14
    mov.l   _pool_bios_tvmode_fn, r11
    bra     .L_06037080
    extu.b r6, r0

.L_06036F94:
    tst r7, r7
    bt      .L_06036F9E
    mov.l @r11, r3
    jsr @r3
    mov #0x0, r4
.L_06036F9E:
    mov.w   DAT_06036fc2, r2
    bra     .L_060370A0
    mov.w r2, @r12

.L_06036FA4:
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_06036FB0
    mov.l @r11, r3
    jsr @r3
    mov #0x1, r4
.L_06036FB0:
    mov.w   _wpool_width_352, r2
    mov.w r2, @r12
    mov.w @r14, r0
    bra     .L_06037074
    or #0x1, r0

    .global DAT_06036fba
DAT_06036fba:
    .2byte  0x01E0

    .global DAT_06036fbc
DAT_06036fbc:
    .2byte  0x00E0

    .global DAT_06036fbe
DAT_06036fbe:
    .2byte  0x00F0

    .global DAT_06036fc0
DAT_06036fc0:
    .2byte  0x0100

    .global DAT_06036fc2
DAT_06036fc2:
    .2byte  0x0140
_wpool_width_352:
    .2byte  0x0160
    .2byte  0xFFFF
_pool_screen_width:
    .4byte  sym_060635AE
_pool_screen_height:
    .4byte  sym_060635B0
_pool_display_state:
    .4byte  sym_060A3D88
_pool_bios_tv_flag_ptr:
    .4byte  sym_06000324
_pool_mask_clear_vlines:
    .4byte  0x0000FFCF
_pool_mask_clear_interlace:
    .4byte  0x0000FF3F
_pool_mask_clear_res:
    .4byte  0x0000FFF0
_pool_bios_tvmode_fn:
    .4byte  sym_06000320

.L_06036FE8:
    tst r7, r7
    bt      .L_06036FF2
    mov.l @r11, r3
    jsr @r3
    mov #0x0, r4
.L_06036FF2:
    mov.w   DAT_06037078, r2
    mov.w r2, @r12
    mov.w @r14, r0
    bra     .L_06037074
    or #0x2, r0

.L_06036FFC:
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_06037008
    mov.l @r11, r3
    jsr @r3
    mov #0x1, r4
.L_06037008:
    mov.w   DAT_0603707a, r2
    mov.w r2, @r12
    mov.w @r14, r0
    bra     .L_06037074
    or #0x3, r0

.L_06037012:
    tst r7, r7
    bt      .L_0603701C
    mov.l @r11, r3
    jsr @r3
    mov #0x0, r4
.L_0603701C:
    mov.w   DAT_0603707c, r2
    mov.w r2, @r12
    extu.w r10, r3
    mov.w r3, @r13
    mov.w @r14, r0
    bra     .L_06037074
    or #0x4, r0

.L_0603702A:
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_06037036
    mov.l @r11, r3
    jsr @r3
    mov #0x1, r4
.L_06037036:
    mov.w   DAT_0603707e, r2
    mov.w r2, @r12
    extu.w r10, r3
    mov.w r3, @r13
    mov.w @r14, r0
    bra     .L_06037074
    or #0x5, r0

.L_06037044:
    tst r7, r7
    bt      .L_0603704E
    mov.l @r11, r3
    jsr @r3
    mov #0x0, r4
.L_0603704E:
    mov.w   DAT_06037078, r2
    mov.w r2, @r12
    extu.w r10, r3
    mov.w r3, @r13
    mov.w @r14, r0
    bra     .L_06037074
    or #0x6, r0

.L_0603705C:
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_06037068
    mov.l @r11, r3
    jsr @r3
    mov #0x1, r4
.L_06037068:
    mov.w   DAT_0603707a, r2
    mov.w r2, @r12
    extu.w r10, r3
    mov.w r3, @r13
    mov.w @r14, r0
    or #0x7, r0
.L_06037074:
    bra     .L_060370A0
    mov.w r0, @r14

    .global DAT_06037078
DAT_06037078:
    .2byte  0x0280

    .global DAT_0603707a
DAT_0603707a:
    .2byte  0x02C0

    .global DAT_0603707c
DAT_0603707c:
    .2byte  0x0140

    .global DAT_0603707e
DAT_0603707e:
    .2byte  0x0160

.L_06037080:
    cmp/eq #0x0, r0
    bt      .L_06036F94
    cmp/eq #0x1, r0
    bt      .L_06036FA4
    cmp/eq #0x2, r0
    bt      .L_06036FE8
    cmp/eq #0x3, r0
    bt      .L_06036FFC
    cmp/eq #0x4, r0
    bt      .L_06037012
    cmp/eq #0x5, r0
    bt      .L_0603702A
    cmp/eq #0x6, r0
    bt      .L_06037044
    cmp/eq #0x7, r0
    bt      .L_0603705C

.L_060370A0:
    mov.l   _pool_cmd_ready_flag, r4
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_060370AE
    mov #0x1, r3
    mov.w r3, @r4
.L_060370AE:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_cmd_ready_flag:
    .4byte  sym_060635AC

    .global sym_060370C0
    .type sym_060370C0, @function
sym_060370C0:
    mov #0x0, r5
    extu.b r5, r0
    mov.l r5, @r4
    mov.l r5, @(4, r4)
    mov.b r0, @(8, r4)
    extu.b r5, r0
    mov.b r0, @(9, r4)
    extu.b r5, r0
    mov.b r0, @(10, r4)
    extu.b r5, r0
    mov.b r0, @(11, r4)
    extu.b r5, r0
    mov.b r0, @(12, r4)
    extu.b r5, r0
    mov.b r0, @(13, r4)
    extu.b r5, r0
    rts
    mov.b r0, @(14, r4)
