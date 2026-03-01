
    .section .text.FUN_06026518


    .global mat_multiply_basic
    .type mat_multiply_basic, @function
mat_multiply_basic:
    sts.l pr, @-r15
    extu.w r4, r0
    add #-0x4, r15
    tst #0x4, r0
    bt      .L_dlist_struct_path
    mov.l   .L_pool_blank_text, r7
    mov.w   .L_wpool_elem_size, r6
    mov.w   .L_wpool_layer_d_param, r5
    mov.l   .L_pool_geom_dispatch_final, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_blank_text, r7
    mov.w   .L_wpool_elem_size, r6
    mov.w   DAT_06026576, r5
    mov #0x8, r4
    add #0x4, r15
    mov.l   .L_pool_geom_dispatch_final, r3
    jmp @r3
    lds.l @r15+, pr
.L_dlist_struct_path:
    mov.l   .L_pool_dlist_entry_layer_d, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_06026578, r3
    mov.w   .L_wpool_layer_d_param, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_display_list_loader, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_dlist_entry_layer_e, r2
    mov.l r2, @r15
    mov r2, r7
    mov.l @(4, r7), r7
    mov.w   DAT_06026578, r3
    add r3, r7
    mov.w   DAT_06026576, r6
    mov r2, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    mov.l   .L_pool_display_list_loader, r3
    jmp @r3
    lds.l @r15+, pr
.L_wpool_elem_size:
    .2byte  0x0090                          /* [MEDIUM] display list element size (0x0090 = 144 bytes) */
.L_wpool_layer_d_param:
    .2byte  0x02A0                          /* [MEDIUM] layer D geometry offset (VDP display list slot) */

    .global DAT_06026576
DAT_06026576:
    .2byte  0x02B4

    .global DAT_06026578
DAT_06026578:
    .2byte  0x7000
    .2byte  0xFFFF
.L_pool_blank_text:
    .4byte  sym_06059128                    /* [HIGH] blank text "  " — static texture data for geom_dispatch_final */
.L_pool_geom_dispatch_final:
    .4byte  sym_060284AE                    /* [HIGH] geom_dispatch_final — VDP geometry/text renderer */
.L_pool_dlist_entry_layer_d:
    .4byte  sym_06063B80                    /* [HIGH] display list entry struct — layer D (render_fn + frame_data) */
.L_pool_display_list_loader:
    .4byte  sym_06028400                    /* [HIGH] display_list_loader — DMA transfer from dlist to VDP */
.L_pool_dlist_entry_layer_e:
    .4byte  sym_06063B88                    /* [HIGH] display list entry struct — layer E (render_fn + frame_data) */
