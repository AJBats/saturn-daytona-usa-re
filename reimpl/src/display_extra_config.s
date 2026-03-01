
    .section .text.FUN_06038A64


    .global display_extra_config
    .type display_extra_config, @function
display_extra_config:
    mov.w   DAT_06038a9a, r6
    mov.l   .L_pool_06038AA0, r5
    bra     .L_06038AA4
    mov r4, r0
.L_06038A6C:
    mov.w @(14, r5), r0
    mov r0, r2
    extu.w r2, r2
    bra     .L_06038A92
    and r6, r2
.L_06038A76:
    mov.w @(14, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    mov.w   .L_wpool_06038A9C, r3
    or r3, r2
    bra     .L_06038A92
    nop
.L_06038A86:
    mov.w @(14, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    mov.w   DAT_06038a9e, r3
    or r3, r2
.L_06038A92:
    extu.w r2, r2
    mov r2, r0
    bra     .L_06038AB0
    mov.w r0, @(14, r5)

    .global DAT_06038a9a
DAT_06038a9a:
    .2byte  0x0FFF
.L_wpool_06038A9C:
    .2byte  0x1000                      /* [HIGH] bit 12 set mask (mode 1 — low-nibble channel select) */

    .global DAT_06038a9e
DAT_06038a9e:
    .2byte  0x2000
.L_pool_06038AA0:
    .4byte  sym_060A3D88
.L_06038AA4:
    cmp/eq #0x0, r0
    bt      .L_06038A6C
    cmp/eq #0x1, r0
    bt      .L_06038A76
    cmp/eq #0x2, r0
    bt      .L_06038A86
.L_06038AB0:
    mov.l   .L_pool_06038AC4, r4
    mov.w @r4, r2
    extu.w r2, r2
    tst r2, r2
    bf      .L_06038ABE
    mov #0x1, r3
    mov.w r3, @r4
.L_06038ABE:
    rts
    nop
    .2byte  0xFFFF
.L_pool_06038AC4:
    .4byte  sym_060635AC
