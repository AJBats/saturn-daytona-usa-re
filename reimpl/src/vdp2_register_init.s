
    .section .text.FUN_06003578


    .global vdp2_register_init
    .type vdp2_register_init, @function
vdp2_register_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_vdp2_vram_0x20000, r10
    mov.l   .L_fn_memcpy_word, r12
    mov.l   .L_fn_memcpy_long, r13
    mov.w   .L_cram_copy_size, r6
    mov.l   .L_color_palette_src, r5
    mov.l   .L_vdp2_cram_0x800, r4
    jsr @r12
    mov #0x0, r11
    mov.w   DAT_06003620, r6
    mov.l   .L_vram_base_tilemap, r5
    mov.l   .L_vdp2_vram_0x00000, r4
    jsr @r13
    nop
    mov #0x8, r4
.L_clear_vram_loop:
    add #-0x2, r4
    tst r4, r4
    bf/s    .L_clear_vram_loop
    mov.l r11, @r10
    mov.w   DAT_06003622, r6
    mov.l   .L_cdrom_base, r14
    mov.l   .L_tile_src_1, r5
    mov.l   .L_vdp2_vram_0x4363C, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003624, r6
    mov.l   .L_tile_src_2, r5
    mov.l   .L_vdp2_vram_0x497E4, r4
    jsr @r13
    add r14, r5
    mov.l   .L_tile_size_3, r6
    mov.l   .L_tile_src_3, r5
    mov.l   .L_vdp2_vram_0x4EFEC, r4
    jsr @r13
    add r14, r5
    mov.w   .L_tile_size_4, r6
    mov.l   .L_tile_src_4, r5
    mov.l   .L_vdp2_vram_0x40000, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003628, r6
    mov.l   .L_tile_src_5, r5
    mov.l   .L_vdp2_vram_0x407F0, r4
    jsr @r13
    add r14, r5
    mov.w   .L_tile_size_6, r6
    mov.l   .L_tile_src_6, r5
    mov.l   .L_vdp2_vram_0x4108C, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600362c, r6
    mov.l   .L_tile_src_7, r5
    mov.l   .L_vdp2_vram_0x41A24, r4
    jsr @r13
    add r14, r5
    mov.w   .L_tile_size_8, r6
    mov.l   .L_tile_src_8, r5
    mov.l   .L_vdp2_vram_0x42300, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003630, r6
    mov.l   .L_tile_src_9, r5
    mov.l   .L_vdp2_vram_0x42C78, r4
    jsr @r13
    add r14, r5
    mov.w   .L_tile_size_10, r6
    mov.l   .L_tile_src_10, r5
    mov.l   .L_vdp2_vram_0x61CEC, r4
    jsr @r13
    add r14, r5
    mov.w   .L_tile_size_11, r6
    mov.l   .L_tile_src_11, r5
    mov.l   .L_vdp2_vram_0x665D4, r4
    jsr @r13
    add r14, r5
    bra     .L_pattern_batch
    nop
.L_cram_copy_size:
    .2byte  0x0240

    .global DAT_06003620
DAT_06003620:
    .2byte  0x1000

    .global DAT_06003622
DAT_06003622:
    .2byte  0x61A8

    .global DAT_06003624
DAT_06003624:
    .2byte  0x5808
.L_tile_size_4:
    .2byte  0x07F0

    .global DAT_06003628
DAT_06003628:
    .2byte  0x089C
.L_tile_size_6:
    .2byte  0x0998

    .global DAT_0600362c
DAT_0600362c:
    .2byte  0x08DC
.L_tile_size_8:
    .2byte  0x0978

    .global DAT_06003630
DAT_06003630:
    .2byte  0x09C4
.L_tile_size_10:
    .2byte  0x48E8
.L_tile_size_11:
    .2byte  0x43F8
    .2byte  0xFFFF
.L_vdp2_vram_0x20000:
    .4byte  0x25E20000                  /* VDP2 VRAM +0x20000 */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx
.L_fn_memcpy_long:
    .4byte  memcpy_long_idx
.L_color_palette_src:
    .4byte  sym_060481AC
.L_vdp2_cram_0x800:
    .4byte  0x25F00800                  /* VDP2 color RAM +0x800 */
.L_vram_base_tilemap:
    .4byte  0x002CF108
.L_vdp2_vram_0x00000:
    .4byte  0x25E00000                  /* VDP2 VRAM +0x00000 */
.L_cdrom_base:
    .4byte  0x002A0000
.L_tile_src_1:
    .4byte  0x00031498
.L_vdp2_vram_0x4363C:
    .4byte  0x25E4363C                  /* VDP2 VRAM +0x4363C */
.L_tile_src_2:
    .4byte  0x00037640
.L_vdp2_vram_0x497E4:
    .4byte  0x25E497E4                  /* VDP2 VRAM +0x497E4 */
.L_tile_size_3:
    .4byte  0x00008094
.L_tile_src_3:
    .4byte  0x0003CE44
.L_vdp2_vram_0x4EFEC:
    .4byte  0x25E4EFEC                  /* VDP2 VRAM +0x4EFEC */
.L_tile_src_4:
    .4byte  0x00044ED8
.L_vdp2_vram_0x40000:
    .4byte  0x25E40000                  /* VDP2 VRAM +0x40000 */
.L_tile_src_5:
    .4byte  0x000456C8
.L_vdp2_vram_0x407F0:
    .4byte  0x25E407F0                  /* VDP2 VRAM +0x407F0 */
.L_tile_src_6:
    .4byte  0x00045F64
.L_vdp2_vram_0x4108C:
    .4byte  0x25E4108C                  /* VDP2 VRAM +0x4108C */
.L_tile_src_7:
    .4byte  0x000468FC
.L_vdp2_vram_0x41A24:
    .4byte  0x25E41A24                  /* VDP2 VRAM +0x41A24 */
.L_tile_src_8:
    .4byte  0x000471D8
.L_vdp2_vram_0x42300:
    .4byte  0x25E42300                  /* VDP2 VRAM +0x42300 */
.L_tile_src_9:
    .4byte  0x00047B50
.L_vdp2_vram_0x42C78:
    .4byte  0x25E42C78                  /* VDP2 VRAM +0x42C78 */
.L_tile_src_10:
    .4byte  0x0001F370
.L_vdp2_vram_0x61CEC:
    .4byte  0x25E61CEC                  /* VDP2 VRAM +0x61CEC */
.L_tile_src_11:
    .4byte  0x00023C58
.L_vdp2_vram_0x665D4:
    .4byte  0x25E665D4                  /* VDP2 VRAM +0x665D4 */
.L_pattern_batch:
    mov.w   .L_pattern_size_1, r6
    mov.l   .L_pattern_src_1, r5
    mov.l   .L_vdp2_vram_0x6A9CC, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003774, r9
    mov.l   .L_pattern_src_2, r5
    mov.l   .L_vdp2_vram_0x60000, r4
    mov r9, r6
    jsr @r13
    add r14, r5
    mov r9, r6
    mov.l   .L_pattern_src_3, r5
    mov.l   .L_vdp2_vram_0x609A4, r4
    jsr @r13
    add r14, r5
    mov r9, r6
    mov.l   .L_pattern_src_4, r5
    mov.l   .L_vdp2_vram_0x61348, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003776, r6
    mov.w   DAT_06003778, r5
    mov.l   .L_vdp2_vram_0x6F9C4, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600377a, r6
    mov.w   DAT_0600377c, r5
    mov.l   .L_vdp2_vram_0x70E40, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600377e, r6
    mov.l   .L_pattern_src_5, r5
    mov.l   .L_vdp2_vram_0x72194, r4
    jsr @r13
    add r14, r5
    mov.w   .L_pattern_size_6, r6
    mov.l   .L_pattern_src_6, r5
    mov.l   .L_vdp2_vram_0x73B98, r4
    jsr @r13
    add r14, r5
    mov r9, r6
    mov.l   .L_pattern_src_7, r5
    mov.l   .L_vdp2_vram_0x74158, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003782, r6
    mov.l   .L_pattern_src_8, r5
    mov.l   .L_vdp2_vram_0x74AFC, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_06003784, r6
    mov.l   .L_pattern_src_9, r5
    mov.l   .L_vdp2_vram_0x75730, r4
    jsr @r13
    add r14, r5
    mov.w   .L_pattern_size_10, r6
    mov.l   .L_pattern_src_10, r5
    mov.l   .L_vdp2_vram_0x759EC, r4
    jsr @r12
    add r14, r5
    mov.w   .L_pattern_size_10, r6
    mov.l   .L_pattern_src_11, r5
    mov.l   .L_vdp2_vram_0x75DDC, r4
    jsr @r12
    add r14, r5
    mov.w   .L_pattern_size_12, r6
    mov.l   .L_pattern_src_12, r5
    mov.l   .L_vdp2_vram_0x76174, r4
    jsr @r13
    add r14, r5
    mov.w   .L_pattern_size_13, r6
    mov.l   .L_pattern_src_13, r5
    mov.l   .L_vdp2_vram_0x761FC, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600378c, r6
    mov.l   .L_pattern_src_14, r5
    mov.l   .L_vdp2_vram_0x76EFC, r4
    jsr @r13
    add r14, r5
    mov.w   DAT_0600378e, r6
    mov.l   .L_pattern_src_15, r5
    mov.l   .L_vdp2_vram_0x77B18, r4
    jsr @r13
    add r14, r5
    mov.w   .L_anim_copy_size, r9
    mov.l   .L_anim_pal_src_1, r5
    mov.l   .L_anim_pal_dest_a, r4
    mov r9, r6
    jsr @r12
    add r14, r5
    mov r9, r6
    bra     .L_anim_palette_load
    nop
.L_pattern_size_1:
    .2byte  0x4FF8

    .global DAT_06003774
DAT_06003774:
    .2byte  0x09A4

    .global DAT_06003776
DAT_06003776:
    .2byte  0x147C

    .global DAT_06003778
DAT_06003778:
    .2byte  0x0400

    .global DAT_0600377a
DAT_0600377a:
    .2byte  0x1354

    .global DAT_0600377c
DAT_0600377c:
    .2byte  0x187C

    .global DAT_0600377e
DAT_0600377e:
    .2byte  0x1A04
.L_pattern_size_6:
    .2byte  0x05C0

    .global DAT_06003782
DAT_06003782:
    .2byte  0x0C34

    .global DAT_06003784
DAT_06003784:
    .2byte  0x02BC
.L_pattern_size_10:
    .2byte  0x03F0
.L_pattern_size_12:
    .2byte  0x0088
.L_pattern_size_13:
    .2byte  0x0D00

    .global DAT_0600378c
DAT_0600378c:
    .2byte  0x0C1C

    .global DAT_0600378e
DAT_0600378e:
    .2byte  0x3650
.L_anim_copy_size:
    .2byte  0x04D4
    .2byte  0xFFFF
.L_pattern_src_1:
    .4byte  0x00028050
.L_vdp2_vram_0x6A9CC:
    .4byte  0x25E6A9CC                  /* VDP2 VRAM +0x6A9CC */
.L_pattern_src_2:
    .4byte  0x0002D41C
.L_vdp2_vram_0x60000:
    .4byte  0x25E60000                  /* VDP2 VRAM +0x60000 */
.L_pattern_src_3:
    .4byte  0x0002DDC0
.L_vdp2_vram_0x609A4:
    .4byte  0x25E609A4                  /* VDP2 VRAM +0x609A4 */
.L_pattern_src_4:
    .4byte  0x0002E764
.L_vdp2_vram_0x61348:
    .4byte  0x25E61348                  /* VDP2 VRAM +0x61348 */
.L_vdp2_vram_0x6F9C4:
    .4byte  0x25E6F9C4                  /* VDP2 VRAM +0x6F9C4 */
.L_vdp2_vram_0x70E40:
    .4byte  0x25E70E40                  /* VDP2 VRAM +0x70E40 */
.L_pattern_src_5:
    .4byte  0x0000EAB0
.L_vdp2_vram_0x72194:
    .4byte  0x25E72194                  /* VDP2 VRAM +0x72194 */
.L_pattern_src_6:
    .4byte  0x00017114
.L_vdp2_vram_0x73B98:
    .4byte  0x25E73B98                  /* VDP2 VRAM +0x73B98 */
.L_pattern_src_7:
    .4byte  0x000176D0
.L_vdp2_vram_0x74158:
    .4byte  0x25E74158                  /* VDP2 VRAM +0x74158 */
.L_pattern_src_8:
    .4byte  0x00018074
.L_vdp2_vram_0x74AFC:
    .4byte  0x25E74AFC                  /* VDP2 VRAM +0x74AFC */
.L_pattern_src_9:
    .4byte  0x00018B10
.L_vdp2_vram_0x75730:
    .4byte  0x25E75730                  /* VDP2 VRAM +0x75730 */
.L_pattern_src_10:
    .4byte  0x00008F84
.L_vdp2_vram_0x759EC:
    .4byte  0x25E759EC                  /* VDP2 VRAM +0x759EC */
.L_pattern_src_11:
    .4byte  0x00009374
.L_vdp2_vram_0x75DDC:
    .4byte  0x25E75DDC                  /* VDP2 VRAM +0x75DDC */
.L_pattern_src_12:
    .4byte  0x00048514
.L_vdp2_vram_0x76174:
    .4byte  0x25E76174                  /* VDP2 VRAM +0x76174 */
.L_pattern_src_13:
    .4byte  0x0004859C
.L_vdp2_vram_0x761FC:
    .4byte  0x25E761FC                  /* VDP2 VRAM +0x761FC */
.L_pattern_src_14:
    .4byte  0x0004929C
.L_vdp2_vram_0x76EFC:
    .4byte  0x25E76EFC                  /* VDP2 VRAM +0x76EFC */
.L_pattern_src_15:
    .4byte  0x00049EB8
.L_vdp2_vram_0x77B18:
    .4byte  0x25E77B18                  /* VDP2 VRAM +0x77B18 */
.L_anim_pal_src_1:
    .4byte  0x0000AA54
.L_anim_pal_dest_a:
    .4byte  sym_060EE300
.L_anim_palette_load:
    mov.l   .L_anim_pal_src_2, r5
    mov.l   .L_anim_pal_dest_b, r4
    jsr @r12
    add r14, r5
    mov r9, r6
    mov.l   .L_anim_pal_src_3, r5
    mov.l   .L_anim_pal_dest_c, r4
    jsr @r12
    add r14, r5
    mov r9, r6
    mov.l   .L_anim_pal_src_4, r5
    .2byte  0xD41C
    .4byte  0x4C0B35EC
    .4byte  0x6693D51B
    .4byte  0xD41B4C0B
    .4byte  0x35EC961F
    .4byte  0xD51AD41B
    .4byte  0x4C0B35EC
    .4byte  0x961BD51A
    .4byte  0xD41A4D0B
    .4byte  0x35EC9617
    .4byte  0xD519D41A
    .4byte  0x4D0B35EC
    .4byte  0x9613D519
    .4byte  0xD4194D0B
    .4byte  0x35EC960F
    .4byte  0x950FD418
    .4byte  0x4D0B35EC
    .4byte  0x4F2669F6
    .4byte  0x6AF66BF6
    .4byte  0x6CF66DF6
    .4byte  0x000B6EF6

    .global DAT_06003884
DAT_06003884:
    .4byte  0x03D40528
    .2byte  0x0228

    .global DAT_0600388a
DAT_0600388a:
    .2byte  0x014C

    .global DAT_0600388c
DAT_0600388c:
    .2byte  0x0834

    .global DAT_0600388e
DAT_0600388e:
    .2byte  0x7EC4
.L_anim_pal_src_2:
    .4byte  0x0000AF28
.L_anim_pal_dest_b:
    .4byte  sym_060EE7D4
.L_anim_pal_src_3:
    .4byte  0x0000B3FC
.L_anim_pal_dest_c:
    .4byte  sym_060EECA8
.L_anim_pal_src_4:
    .4byte  0x0000B8D0
    .4byte  sym_060EF17C
    .4byte  0x0000BDA4
    .4byte  sym_060EF650
    .4byte  0x0002D048
    .4byte  sym_060EFB24
    .4byte  0x00019BC4
    .4byte  0x25E33AD8
    .4byte  0x0001A0EC
    .4byte  0x25E33764
    .4byte  0x0004FEEC
    .4byte  0x25E3398C
    .4byte  0x25E7B168
