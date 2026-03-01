
    .section .text.FUN_0603D3A8


    .global bus_lock_table_ctrl
    .type bus_lock_table_ctrl, @function
bus_lock_table_ctrl:
    sts.l pr, @-r15
    mov #0x1, r5
    mov.l   .L_pool_mask_hi_byte, r7
    mov.l   .L_pool_cfg_final, r6
    mov.l   .L_pool_cfg_array_b, r4
    mov.w   .L_wpool_field_descriptor, r1
    mov.l   .L_pool_bitfield_rmw, r3
    mov r5, r0
    jsr @r3
    mov r6, r2
    mov.w @r4, r0
    extu.w r0, r0
    and r7, r0
    or #0x3, r0
    mov.w r0, @r4
    mov r5, r0
    mov.w   .L_wpool_field_descriptor, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r6, r2
    mov.w @r4, r0
    mov.w   DAT_0603d426, r3
    extu.w r0, r0
    and #0xFF, r0
    or r3, r0
    mov.w r0, @r4
    mov r5, r0
    mov.w   .L_wpool_field_descriptor, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r6, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    or r5, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r5, r0
    mov.w   .L_wpool_field_descriptor, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r6, r2
    mov.w @(2, r4), r0
    extu.w r0, r0
    and #0xFF, r0
    mov.w r0, @(2, r4)
    mov r5, r0
    mov.w   .L_wpool_field_descriptor, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r6, r2
    mov #0x4, r0
    mov.w r0, @(4, r4)
    mov r5, r0
    mov.w   .L_wpool_field_descriptor, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r6, r2
    lds.l @r15+, pr
    rts
    nop
.L_wpool_field_descriptor:
    .2byte  0x0201                      /* field descriptor: array B bitfield RMW param */

    .global DAT_0603d426
DAT_0603d426:
    .2byte  0x0200                      /* high byte OR value: 0x0200 */
.L_pool_mask_hi_byte:
    .4byte  0x0000FF00                  /* mask: keep high byte, clear low byte */
.L_pool_cfg_final:
    .4byte  sym_060A4D58                /* &cfg_final: target struct for bitfield RMW */
.L_pool_cfg_array_b:
    .4byte  sym_060A4D30                /* &cfg_array_b: config word array B (3 words) */
.L_pool_bitfield_rmw:
    .4byte  sym_06034F78                /* &bitfield_rmw: read-modify-write utility */
