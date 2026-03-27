
    .section .text.FUN_0600C010


    .global FUN_0600C010
    .type FUN_0600C010, @function
FUN_0600C010:
    sts.l pr, @-r15
    mov.l   .L_pool_0600C094, r8
    mov.w   .L_wpool_0600C090, r10
    mov.l   .L_pool_0600C098, r12
    mov.l   .L_pool_0600C09C, r13
    mov.l   .L_pool_0600C0A0, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_0600C02C
    mov #0x0, r9
    mov.l   .L_pool_0600C0A4, r4
    mov.l   .L_pool_0600C0A8, r3
    jsr @r3
    mov.l @r4, r4
.L_0600C02C:
    mov.l @r8, r2
    mov.l   .L_pool_0600C0AC, r3
    and r3, r2
    tst r2, r2
    bf      .L_0600C050
    mov.l   .L_pool_0600C0B0, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0600C04A
    mov.l   .L_pool_0600C0B4, r3
    jsr @r3
    nop
    bra     .L_0600C050
    nop
.L_0600C04A:
    mov.l   .L_pool_0600C0B8, r3
    jsr @r3
    nop
.L_0600C050:
    mov.l @r8, r2
    mov.l   .L_pool_0600C0BC, r3
    cmp/eq r3, r2
    bf      .L_0600C066
    mov.l   .L_pool_0600C0C0, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600C066
    mov.l   .L_pool_0600C0C4, r3
    jsr @r3
    nop
.L_0600C066:
    mov #0x30, r6
    mov.l @r12, r2
    add #0x30, r2
    mov.l r2, @r12
    mov.l   .L_pool_0600C0C8, r5
    mov.l   .L_pool_0600C0CC, r3
    mov.l @r5, r5
    jsr @r3
    mov r2, r4
    mov.l   .L_pool_0600C0D0, r4
    mov.l   .L_pool_0600C0D4, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600C0DC
    mov.l   .L_pool_0600C0D8, r3
    mov.l @r3, r3
    shar r3
    exts.w r3, r3
    mov.w r3, @r4
    bra     .L_0600C0E2
    nop
.L_wpool_0600C090:
    .2byte  0xFE11
    .2byte  0xFFFF
.L_pool_0600C094:
    .4byte  sym_0607EBC4
.L_pool_0600C098:
    .4byte  sym_0608A52C
.L_pool_0600C09C:
    .4byte  sym_0605A1DD
.L_pool_0600C0A0:
    .4byte  sym_06083255
.L_pool_0600C0A4:
    .4byte  sym_0607EB8C
.L_pool_0600C0A8:
    .4byte  FUN_06034708
.L_pool_0600C0AC:
    .4byte  0x02000000
.L_pool_0600C0B0:
    .4byte  sym_06078635
.L_pool_0600C0B4:
    .4byte  sym_0600D336
.L_pool_0600C0B8:
    .4byte  FUN_0600D31C
.L_pool_0600C0BC:
    .4byte  0x00020000
.L_pool_0600C0C0:
    .4byte  sym_0607EAE0
.L_pool_0600C0C4:
    .4byte  sym_0602E610
.L_pool_0600C0C8:
    .4byte  sym_06089EDC
.L_pool_0600C0CC:
    .4byte  FUN_06027630
.L_pool_0600C0D0:
    .4byte  sym_06078664
.L_pool_0600C0D4:
    .4byte  sym_06059F30
.L_pool_0600C0D8:
    .4byte  sym_0607EA98
.L_0600C0DC:
    mov.b @r13, r2
    extu.b r2, r2
    mov.w r2, @r4
.L_0600C0E2:
    mov.l   .L_pool_0600C188, r3
    mov.l   .L_pool_0600C18C, r2
    mov.l r3, @r2
    mov.l   .L_pool_0600C190, r3
    mov.l   .L_pool_0600C194, r2
    mov.w r3, @r2
    mov.l @r8, r3
    mov.l   .L_pool_0600C198, r2
    and r2, r3
    tst r3, r3
    bf      .L_0600C0FE
    mov.l   .L_pool_0600C19C, r3
    jsr @r3
    nop
.L_0600C0FE:
    mov.l   .L_pool_0600C1A0, r3
    jsr @r3
    nop
    .reloc ., R_SH_IND12W, FUN_0600B6A0 - 4
    .2byte 0xB000    /* bsr FUN_0600B6A0 (linker-resolved) */
    nop
    mov.l @r8, r2
    mov.l   .L_pool_0600C1A4, r3
    cmp/eq r3, r2
    bt      .L_0600C11C
    mov.l   .L_pool_0600C1A8, r3
    jsr @r3
    nop
    bra     .L_0600C11C
    nop
.L_0600C11A:
    mov r11, r9
.L_0600C11C:
    mov.b @r10, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bf      .L_0600C11A
    mov.b @r10, r0
    and #0xF, r0
    mov.b r0, @r10
    tst r9, r9
    bt      .L_0600C144
    mov.b @r13, r3
    mov.l   .L_pool_0600C1AC, r2
    extu.b r3, r3
    mov.l @r2, r2
    cmp/ge r2, r3
    bt      .L_0600C152
    mov.b @r13, r2
    add #0x1, r2
    bra     .L_0600C152
    mov.b r2, @r13
.L_0600C144:
    mov.b @r13, r2
    extu.b r2, r2
    cmp/gt r11, r2
    bf      .L_0600C152
    mov.b @r13, r2
    add #-0x1, r2
    mov.b r2, @r13
.L_0600C152:
    mov.l   .L_0600C1B0, r3
    jsr @r3
    nop
    mov.l @r12, r2
    add #-0x30, r2
    mov.l r2, @r12
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0600C170
    .type FUN_0600C170, @function
FUN_0600C170:
    sts.l pr, @-r15
    mov.l   .L_0600C1B0, r3
    jsr @r3
    nop
    mov.l   .L_0600C1B4, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600C1B8
    .reloc ., R_SH_IND12W, FUN_0600B340 - 4
    .2byte 0xB000    /* bsr FUN_0600B340 (linker-resolved) */
    nop
    bra     .L_0600C1BE
    nop
.L_pool_0600C188:
    .4byte  FUN_0600C170
.L_pool_0600C18C:
    .4byte  sym_06063574
.L_pool_0600C190:
    .4byte  0x0000FFFF
.L_pool_0600C194:
    .4byte  0x21000000
.L_pool_0600C198:
    .4byte  0x02800008
.L_pool_0600C19C:
    .4byte  FUN_060058FA
.L_pool_0600C1A0:
    .4byte  FUN_06006868
.L_pool_0600C1A4:
    .4byte  0x02000000
.L_pool_0600C1A8:
    .4byte  FUN_0601BDEC
.L_pool_0600C1AC:
    .4byte  sym_0607EA98
.L_0600C1B0:
    .4byte  sym_0603C000
.L_0600C1B4:
    .4byte  sym_06083255
.L_0600C1B8:
    mov.l   .L_0600C1F4, r3
    jsr @r3
    nop
.L_0600C1BE:
    .reloc ., R_SH_IND12W, FUN_0600B914 - 4
    .2byte 0xB000    /* bsr FUN_0600B914 (linker-resolved) */
    nop
    mov.l   .L_0600C1F8, r0
    mov.l   .L_0600C1FC, r3
    mov.l @r0, r0
    mov.l @r3, r3
    add r3, r0
    cmp/eq #0x8, r0
    bf      .L_0600C1DA
    mov.l   .L_0600C200, r3
    jsr @r3
    nop
    bra     .L_0600C1E0
    nop
.L_0600C1DA:
    mov.l   .L_0600C204, r3
    jsr @r3
    nop
.L_0600C1E0:
    mov.l   .L_0600C208, r2
    mov.l   .L_0600C20C, r3
    mov.l @r2, r2
    mov.l r2, @r3
    mov.l   .L_0600C210, r2
    mov.l   .L_0600C214, r3
    lds.l @r15+, pr
    rts
    mov.w r2, @r3
    .2byte  0xFFFF
.L_0600C1F4:
    .4byte  FUN_0600AFB2
.L_0600C1F8:
    .4byte  sym_06063E1C
.L_0600C1FC:
    .4byte  sym_06063E20
.L_0600C200:
    .4byte  FUN_06006A9C
.L_0600C204:
    .4byte  FUN_06006CDC
.L_0600C208:
    .4byte  sym_06059F40
.L_0600C20C:
    .4byte  sym_06059F4C
.L_0600C210:
    .4byte  0x0000FFFF
.L_0600C214:
    .4byte  0x21800000
