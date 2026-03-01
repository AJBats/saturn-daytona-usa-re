
    .section .text.FUN_0603D43C


    .global name_entry_state
    .type name_entry_state, @function
name_entry_state:
    sts.l pr, @-r15
    mov r6, r0
    mov.l   .L_mask_byte1, r7
    mov.l   .L_pool_config_byte, r5
    mov.l   .L_pool_scroll_cfg_b, r4
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r7, r2
    mov.w r2, @r4
    mov.w   DAT_0603d500, r14
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov r6, r0
    mov.w @r4, r2
    extu.w r2, r2
    and r14, r2
    mov.w r2, @r4
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov.w @(2, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(2, r4)
    mov r6, r0
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov.w @(6, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    extu.w r2, r0
    mov.w r0, @(6, r4)
    mov r6, r0
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    mov.w @(4, r4), r0
    mov r0, r2
    extu.w r2, r2
    and r14, r2
    extu.w r2, r0
    mov.w r0, @(4, r4)
    mov r6, r0
    mov.w   .L_w_chan3_field1_desc, r1
    mov.l   .L_pool_bitfield_rmw, r3
    jsr @r3
    mov r5, r2
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_w_chan3_field1_desc:
    .2byte  0x0301                     /* [HIGH] chan 3 field 1 descriptor */

    .global DAT_0603d500
DAT_0603d500:
    .2byte  0x00FF
    .2byte  0xFFFF
.L_mask_byte1:
    .4byte  0x0000FF00                 /* [HIGH] byte 1 mask */
.L_pool_config_byte:
    .4byte  sym_060A4D58               /* [MEDIUM] scroll config byte ptr */
.L_pool_scroll_cfg_b:
    .4byte  sym_060A4D36               /* [MEDIUM] scroll config block B base */
.L_pool_bitfield_rmw:
    .4byte  sym_06034F78               /* [HIGH] bitfield read-modify-write utility */
