
    .section .text.FUN_06026518


    .global mat_multiply_basic
    .type mat_multiply_basic, @function
mat_multiply_basic:
    sts.l pr, @-r15
    extu.w r4, r0
    add #-0x4, r15
    tst #0x4, r0
    bt      .L_dlist_struct_path
    mov.l   .L_pool_0602657C, r7
    mov.w   .L_wpool_06026572, r6
    mov.w   .L_wpool_06026574, r5
    mov.l   .L_pool_06026580, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_0602657C, r7
    mov.w   .L_wpool_06026572, r6
    mov.w   DAT_06026576, r5
    mov #0x8, r4
    add #0x4, r15
    mov.l   .L_pool_06026580, r3
    jmp @r3
    lds.l @r15+, pr
.L_dlist_struct_path:
    mov.l   .L_pool_06026584, r2
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    mov.w   DAT_06026578, r3
    mov.w   .L_wpool_06026574, r6
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    mov.l   .L_pool_06026588, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_0602658C, r2
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
    mov.l   .L_pool_06026588, r3
    jmp @r3
    lds.l @r15+, pr
.L_wpool_06026572:
    .2byte  0x0090                          /* [MEDIUM] display list element size (0x0090 = 144 bytes) */
.L_wpool_06026574:
    .2byte  0x02A0                          /* [MEDIUM] layer D geometry offset (VDP display list slot) */

    .global DAT_06026576
DAT_06026576:
    .2byte  0x02B4

    .global DAT_06026578
DAT_06026578:
    .2byte  0x7000
    .2byte  0xFFFF
.L_pool_0602657C:
    .4byte  sym_06059128                    /* [HIGH] blank text "  " — static texture data for geom_dispatch_final */
.L_pool_06026580:
    .4byte  sym_060284AE                    /* [HIGH] geom_dispatch_final — VDP geometry/text renderer */
.L_pool_06026584:
    .4byte  sym_06063B80                    /* [HIGH] display list entry struct — layer D (render_fn + frame_data) */
.L_pool_06026588:
    .4byte  sym_06028400                    /* [HIGH] display_list_loader — DMA transfer from dlist to VDP */
.L_pool_0602658C:
    .4byte  sym_06063B88                    /* [HIGH] display list entry struct — layer E (render_fn + frame_data) */
