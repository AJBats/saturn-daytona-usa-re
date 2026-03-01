
    .section .text.FUN_060039C8


    .global dma_config_dispatch
    .type dma_config_dispatch, @function
dma_config_dispatch:
    mov.l   .L_pool_06003A20, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_secondary_path
    mov.l   .L_pool_06003A24, r5
    mov.l @r5, r5
    shll2 r5
    mov.l   .L_pool_06003A28, r3
    add r3, r5
    bra     .L_common_dispatch
    mov #0x20, r6
.L_secondary_path:
    mov #0x60, r6
    mov.l   .L_pool_06003A2C, r5
    mov.l @r5, r5
    shll2 r5
    mov.l   .L_pool_06003A30, r3
    add r3, r5
.L_common_dispatch:
    mov.l   .L_vdp2_cram_0x400, r4
    mov.l   .L_pool_06003A38, r2
    jmp @r2
    mov.l @r5, r5

    .global sym_060039F2
sym_060039F2:
    mov.l   .L_pool_06003A20, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_secondary_path_b
    mov.l   .L_pool_06003A24, r5
    mov.l @r5, r5
    add #0x2, r5
    shll2 r5
    mov.l   .L_pool_06003A28, r3
    add r3, r5
    bra     .L_common_dispatch_b
    mov #0x20, r6
.L_secondary_path_b:
    mov #0x60, r6
    mov.l   .L_pool_06003A2C, r5
    mov.l @r5, r5
    add #0xA, r5
    shll2 r5
    mov.l   .L_pool_06003A30, r3
    add r3, r5
.L_common_dispatch_b:
    mov.l   .L_vdp2_cram_0x400, r4
    mov.l   .L_pool_06003A38, r2
    jmp @r2
    mov.l @r5, r5
.L_pool_06003A20:
    .4byte  sym_06083255
.L_pool_06003A24:
    .4byte  sym_0607EAB8
.L_pool_06003A28:
    .4byte  sym_0605CA4C
.L_pool_06003A2C:
    .4byte  sym_06078868
.L_pool_06003A30:
    .4byte  sym_0605C97C
.L_vdp2_cram_0x400:
    .4byte  0x25F00400                  /* VDP2 color RAM +0x400 */
.L_pool_06003A38:
    .4byte  dma_transfer
