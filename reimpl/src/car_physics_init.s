
    .section .text.FUN_0600EC78


    .global car_physics_init
    .type car_physics_init, @function
car_physics_init:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_fn_vdp1_init, r3
    jsr @r3
    nop
    mov.l   .L_car_struct_ptr_b, r4
    mov.l   .L_car_array_base, r14
    mov.l   .L_car_index, r5
    mov.l @r5, r5
    shll2 r5
    shll r5
    mov.l @r14, r3
    add r3, r5
    mov r5, r2
    add #0x40, r2
    mov.l r2, @r4
    mov.w   .L_car_struct_offset, r10
    mov r2, r3
    add r10, r3
    mov.l   .L_car_struct_ptr_a, r2
    mov.l r3, @r2
    mov.l   .L_car_struct_array, r4
    mov r4, r6
    mov.w   DAT_0600ed62, r1
    add r1, r5
    mov.l r5, @r6
    mov r6, r5
    add #0x4, r5
    mov.l @r6, r3
    add #0x20, r3
    mov.l r3, @r5
    mov r3, r2
    add #0x20, r2
    mov.l r2, @(8, r4)
    mov #0x0, r3
    mov.l   .L_race_state_a, r2
    mov.l r3, @r2
    mov.w   DAT_0600ed64, r3
    mov.l   .L_race_timer_init, r2
    mov.l r3, @r2
    mov.l   .L_fn_ptr_table, r3
    mov.w   .L_fn_tbl_cmd_a, r5
    mov.l @r3, r3
    jsr @r3
    mov #-0x1, r4
    mov.l   .L_fn_subsys_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_ptr_table, r2
    mov.w   .L_fn_tbl_cmd_b, r4
    mov.l @r2, r2
    jsr @r2
    mov #0x0, r5
    mov #0x60, r6
    mov.l   .L_dma_src_addr, r5
    mov.l   .L_fn_dma_transfer, r3
    jsr @r3
    mov.l @r14, r4
    mov #0x3, r2
    mov.l   .L_dma_config, r3
    mov #0x0, r11
    mov.l r2, @r3
    mov r11, r6
    mov.l @r14, r2
    mov.l   .L_fp_half, r3
    add #0x60, r2
    mov.w r3, @r2
    mov.l   .L_vdp1_config_word, r2
    mov.w r11, @r2
    mov.w   .L_spr_size_0x108, r12
    mov.l   .L_fn_vdp1_sprite, r14
    mov.l   .L_cdrom_base, r13
    mov.w   DAT_0600ed6c, r7
    mov r12, r5
    add r13, r7
    jsr @r14
    mov #0x1, r4
    mov.w   DAT_0600ed6e, r7
    mov r11, r6
    mov.w   .L_spr_size_0x810, r5
    add r13, r7
    jsr @r14
    mov #0x2, r4
    mov.w   DAT_0600ed72, r7
    mov r11, r6
    mov.w   DAT_0600ed74, r5
    add r13, r7
    jsr @r14
    mov #0x3, r4
    mov.w   DAT_0600ed76, r7
    mov r11, r6
    mov.w   DAT_0600ed78, r5
    add r13, r7
    jsr @r14
    mov #0x4, r4
    mov.w   DAT_0600ed7a, r7
    mov r11, r6
    mov.w   .L_spr_size_0x519, r5
    add r13, r7
    jsr @r14
    mov #0x5, r4
    mov.w   DAT_0600ed7e, r7
    mov r11, r6
    mov.w   DAT_0600ed80, r5
    add r13, r7
    jsr @r14
    mov #0x6, r4
    bra     .L_sprite_reg_phase2
    nop
.L_car_struct_offset:
    .2byte  0x00C0

    .global DAT_0600ed62
DAT_0600ed62:
    .2byte  0x03C0

    .global DAT_0600ed64
DAT_0600ed64:
    .2byte  0x20D8
.L_fn_tbl_cmd_a:
    .2byte  0x0083                      /* BIOS interrupt mask A: enable VBlank + timer */
.L_fn_tbl_cmd_b:
    .2byte  0xFF7C                      /* BIOS interrupt mask B: second config pattern */
.L_spr_size_0x108:
    .2byte  0x0108

    .global DAT_0600ed6c
DAT_0600ed6c:
    .2byte  0x299B                      /* cdrom offset: slot 1 sprite data */

    .global DAT_0600ed6e
DAT_0600ed6e:
    .2byte  0x29A3                      /* cdrom offset: slot 2 sprite data */
.L_spr_size_0x810:
    .2byte  0x0810

    .global DAT_0600ed72
DAT_0600ed72:
    .2byte  0x2A53

    .global DAT_0600ed74
DAT_0600ed74:
    .2byte  0x0512

    .global DAT_0600ed76
DAT_0600ed76:
    .2byte  0x2B27

    .global DAT_0600ed78
DAT_0600ed78:
    .2byte  0x083C

    .global DAT_0600ed7a
DAT_0600ed7a:
    .2byte  0x2E73
.L_spr_size_0x519:
    .2byte  0x0519

    .global DAT_0600ed7e
DAT_0600ed7e:
    .2byte  0x2F93

    .global DAT_0600ed80
DAT_0600ed80:
    .2byte  0x080F                      /* sprite size param for slot 6 */
    .2byte  0xFFFF                      /* alignment padding */
.L_fn_vdp1_init:
    .4byte  vdp1_init                   /* VDP1 sprite hardware reset */
.L_car_struct_ptr_b:
    .4byte  sym_06078884                /* &car_struct_ptr_b (computed at init) */
.L_car_array_base:
    .4byte  sym_06063F5C                /* &car_array_base (ptr to car data pool) */
.L_car_index:
    .4byte  sym_06059FFC                /* &car_index (active car selector) */
.L_car_struct_ptr_a:
    .4byte  sym_06078880                /* &car_struct_ptr_a (offset +0xC0 from ptr_b) */
.L_car_struct_array:
    .4byte  sym_06078888                /* car_struct_array[3] (3 x 32-byte slots) */
.L_race_state_a:
    .4byte  sym_0606A4F4                /* &race_state_a (disc/loading state) */
.L_race_timer_init:
    .4byte  sym_0606A4EC                /* &race_timer (init to 0x20D8) */
.L_fn_ptr_table:
    .4byte  sym_06000344                /* BIOS interrupt mask control fn ptr */
.L_fn_subsys_init:
    .4byte  sym_06012E00                /* subsystem init function */
.L_dma_src_addr:
    .4byte  sym_0605A018                /* phase display data base (DMA source) */
.L_fn_dma_transfer:
    .4byte  dma_transfer                /* SCU DMA transfer function */
.L_dma_config:
    .4byte  sym_0605A008                /* &frame_counter (set to 3 during init) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 in 16.16 fixed-point */
.L_vdp1_config_word:
    .4byte  sym_06089E44                /* &vdp1_sprite_index (word, cleared to 0) */
.L_fn_vdp1_sprite:
    .4byte  vdp1_sprite_render          /* sprite registration: r4=slot r5=size r6=flags r7=cdrom */
.L_cdrom_base:
    .4byte  0x002A0000                  /* CD-ROM data base address */
.L_sprite_reg_phase2:
    mov.w   DAT_0600eeba, r7
    mov #0x4, r6
    mov.w   .L_spr_size_0x738, r5
    add r13, r7
    jsr @r14
    mov #0x7, r4
    mov.w   DAT_0600eebe, r7
    mov #0x4, r6
    mov.w   .L_spr_size_0x738, r5
    add r13, r7
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_0600eec0, r7
    mov r11, r6
    mov.w   .L_spr_size_0x208, r5
    add r13, r7
    jsr @r14
    mov #0x9, r4
    mov.w   DAT_0600eec4, r7
    mov #0x3C, r6
    mov.w   .L_spr_size_0xA28, r5
    add r13, r7
    jsr @r14
    mov #0xA, r4
    mov.w   DAT_0600eec8, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0x228, r5
    add r13, r7
    jsr @r14
    mov #0x10, r4
    mov.w   DAT_0600eecc, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0x428, r5
    add r13, r7
    jsr @r14
    mov #0x11, r4
    mov.w   DAT_0600eed0, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0x418, r5
    add r13, r7
    jsr @r14
    mov #0x12, r4
    mov.w   DAT_0600eed4, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0x820, r5
    add r13, r7
    jsr @r14
    mov #0x13, r4
    mov.w   DAT_0600eed8, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0x518, r5
    add r13, r7
    jsr @r14
    mov #0x14, r4
    mov.w   DAT_0600eedc, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0x518, r5
    add r13, r7
    jsr @r14
    mov #0x15, r4
    mov.w   DAT_0600eede, r7
    mov #0xC, r6
    mov.w   .L_spr_size_0x508, r5
    add r13, r7
    jsr @r14
    mov #0x16, r4
    mov.w   DAT_0600eee2, r7
    mov #0x8, r6
    mov.w   .L_spr_size_0xD10, r5
    add r13, r7
    jsr @r14
    mov #0x17, r4
    mov.w   DAT_0600eee6, r7
    mov #0x1C, r6
    mov.w   DAT_0600eee8, r5
    add r13, r7
    jsr @r14
    mov #0x18, r4
    mov.w   .L_spr_size_0x348, r9
    mov #0x10, r6
    mov.w   DAT_0600eeec, r7
    mov r9, r5
    add r13, r7
    jsr @r14
    mov #0x19, r4
    mov #0x10, r6
    mov r9, r5
    mov.w   DAT_0600eeee, r7
    add r13, r7
    jsr @r14
    mov #0x1A, r4
    mov #0x10, r6
    mov r9, r5
    mov.w   DAT_0600eef0, r7
    add r13, r7
    jsr @r14
    mov #0x1B, r4
    mov #0x1C, r6
    mov.w   .L_spr_size_0x630, r5
    mov.w   DAT_0600eef2, r7
    add r13, r7
    jsr @r14
    mov r6, r4
    mov #0x10, r6
    mov.w   .L_spr_size_0xA28, r5
    mov.w   DAT_0600eef6, r7
    add r13, r7
    jsr @r14
    mov #0x1D, r4
    mov #0x18, r6
    mov.w   .L_spr_size_0xC08, r5
    mov.w   DAT_0600eef8, r7
    add r13, r7
    jsr @r14
    mov #0x1E, r4
    mov.w   DAT_0600eefc, r7
    add r13, r7
    mov #0x18, r6
    mov.w   .L_spr_size_0xC10, r5
    bra     .L_sprite_reg_phase3
    mov #0x1F, r4

    .global DAT_0600eeba
DAT_0600eeba:
    .2byte  0x3027
.L_spr_size_0x738:
    .2byte  0x0738

    .global DAT_0600eebe
DAT_0600eebe:
    .2byte  0x325B

    .global DAT_0600eec0
DAT_0600eec0:
    .2byte  0x3433
.L_spr_size_0x208:
    .2byte  0x0208

    .global DAT_0600eec4
DAT_0600eec4:
    .2byte  0x3457
.L_spr_size_0xA28:
    .2byte  0x0A28

    .global DAT_0600eec8
DAT_0600eec8:
    .2byte  0x0640
.L_spr_size_0x228:
    .2byte  0x0228

    .global DAT_0600eecc
DAT_0600eecc:
    .2byte  0x06AC
.L_spr_size_0x428:
    .2byte  0x0428

    .global DAT_0600eed0
DAT_0600eed0:
    .2byte  0x074C
.L_spr_size_0x418:
    .2byte  0x0418

    .global DAT_0600eed4
DAT_0600eed4:
    .2byte  0x07E4
.L_spr_size_0x820:
    .2byte  0x0820

    .global DAT_0600eed8
DAT_0600eed8:
    .2byte  0x09B4
.L_spr_size_0x518:
    .2byte  0x0518

    .global DAT_0600eedc
DAT_0600eedc:
    .2byte  0x0A34

    .global DAT_0600eede
DAT_0600eede:
    .2byte  0x0AA4
.L_spr_size_0x508:
    .2byte  0x0508

    .global DAT_0600eee2
DAT_0600eee2:
    .2byte  0x0AD8
.L_spr_size_0xD10:
    .2byte  0x0D10

    .global DAT_0600eee6
DAT_0600eee6:
    .2byte  0x0C14

    .global DAT_0600eee8
DAT_0600eee8:
    .2byte  0x041C
.L_spr_size_0x348:
    .2byte  0x0348

    .global DAT_0600eeec
DAT_0600eeec:
    .2byte  0x0D7C

    .global DAT_0600eeee
DAT_0600eeee:
    .2byte  0x0F58

    .global DAT_0600eef0
DAT_0600eef0:
    .2byte  0x1140

    .global DAT_0600eef2
DAT_0600eef2:
    .2byte  0x12F8
.L_spr_size_0x630:
    .2byte  0x0630

    .global DAT_0600eef6
DAT_0600eef6:
    .2byte  0x1484

    .global DAT_0600eef8
DAT_0600eef8:
    .2byte  0x1890
.L_spr_size_0xC08:
    .2byte  0x0C08

    .global DAT_0600eefc
DAT_0600eefc:
    .2byte  0x1908
.L_spr_size_0xC10:
    .2byte  0x0C10
.L_sprite_reg_phase3:
    jsr @r14
    nop
    mov.w   .L_spr_size_0x308, r9
    mov #0xC, r6
    mov.w   DAT_0600effe, r7
    mov r9, r5
    add r13, r7
    jsr @r14
    mov #0x20, r4
    mov #0xC, r6
    mov.w   .L_spr_size_0x410, r5
    mov.w   DAT_0600f000, r7
    add r13, r7
    jsr @r14
    mov #0x21, r4
    mov #0xC, r6
    mov r9, r5
    mov.w   DAT_0600f004, r7
    add r13, r7
    jsr @r14
    mov #0x22, r4
    mov #0xC, r6
    mov r9, r5
    mov.w   DAT_0600f006, r7
    add r13, r7
    jsr @r14
    mov #0x23, r4
    mov #0xC, r6
    mov.w   .L_spr_size_0x410, r5
    mov.w   DAT_0600f008, r7
    add r13, r7
    jsr @r14
    mov #0x24, r4
    mov #0x14, r6
    mov.w   DAT_0600f00c, r5
    mov.w   DAT_0600f00a, r7
    add r13, r7
    jsr @r14
    mov #0x25, r4
    mov #0x14, r6
    mov.w   DAT_0600f00c, r5
    mov.w   DAT_0600f00e, r7
    add r13, r7
    jsr @r14
    mov #0x26, r4
    mov #0xC, r6
    mov.w   .L_spr_size_0x610, r5
    mov.w   DAT_0600f010, r7
    add r13, r7
    jsr @r14
    mov #0x27, r4
    mov #0x14, r6
    mov.w   .L_spr_size_0x510, r5
    mov.w   DAT_0600f014, r7
    add r13, r7
    jsr @r14
    mov #0x28, r4
    mov #0x14, r6
    mov.w   .L_spr_size_0x310, r5
    mov.w   DAT_0600f018, r7
    add r13, r7
    jsr @r14
    mov #0x29, r4
    mov #0x14, r6
    mov.w   DAT_0600f01e, r5
    mov.w   DAT_0600f01c, r7
    add r13, r7
    jsr @r14
    mov #0x2A, r4
    mov #0x14, r6
    mov.w   DAT_0600f022, r5
    mov.w   DAT_0600f020, r7
    add r13, r7
    jsr @r14
    mov #0x2B, r4
    mov #0xC, r6
    mov.w   .L_spr_size_0x110, r5
    mov.w   DAT_0600f024, r7
    add r13, r7
    jsr @r14
    mov #0x2C, r4
    mov #0xC, r6
    mov.w   .L_spr_size_0x110, r5
    mov.w   DAT_0600f028, r7
    add r13, r7
    jsr @r14
    mov #0x2D, r4
    mov #0x14, r6
    mov.w   .L_spr_size_0x510, r5
    mov.w   DAT_0600f02a, r7
    add r13, r7
    jsr @r14
    mov #0x2E, r4
    mov #0x14, r6
    mov.w   .L_spr_size_0x310, r5
    mov.w   DAT_0600f02c, r7
    add r13, r7
    jsr @r14
    mov #0x2F, r4
    mov #0x14, r6
    mov.w   DAT_0600f01e, r5
    mov.w   DAT_0600f02e, r7
    add r13, r7
    jsr @r14
    mov #0x30, r4
    mov #0x14, r6
    mov.w   DAT_0600f022, r5
    mov.w   DAT_0600f030, r7
    add r13, r7
    jsr @r14
    mov #0x31, r4
    mov #0x14, r6
    mov r12, r5
    mov.w   DAT_0600f032, r7
    add r13, r7
    jsr @r14
    mov #0x32, r4
    mov #0x14, r6
    mov r12, r5
    mov.w   DAT_0600f034, r7
    add r13, r7
    jsr @r14
    mov #0x33, r4
    mov.w   DAT_0600f036, r7
    bra     .L_sprite_reg_phase4
    nop
.L_spr_size_0x308:
    .2byte  0x0308

    .global DAT_0600effe
DAT_0600effe:
    .2byte  0x1AC4

    .global DAT_0600f000
DAT_0600f000:
    .2byte  0x1B04
.L_spr_size_0x410:
    .2byte  0x0410

    .global DAT_0600f004
DAT_0600f004:
    .2byte  0x1B9C

    .global DAT_0600f006
DAT_0600f006:
    .2byte  0x1BC8

    .global DAT_0600f008
DAT_0600f008:
    .2byte  0x1C04

    .global DAT_0600f00a
DAT_0600f00a:
    .2byte  0x1CC8

    .global DAT_0600f00c
DAT_0600f00c:
    .2byte  0x060C

    .global DAT_0600f00e
DAT_0600f00e:
    .2byte  0x1D2C

    .global DAT_0600f010
DAT_0600f010:
    .2byte  0x1D84
.L_spr_size_0x610:
    .2byte  0x0610

    .global DAT_0600f014
DAT_0600f014:
    .2byte  0x1E20
.L_spr_size_0x510:
    .2byte  0x0510

    .global DAT_0600f018
DAT_0600f018:
    .2byte  0x1E8C
.L_spr_size_0x310:
    .2byte  0x0310

    .global DAT_0600f01c
DAT_0600f01c:
    .2byte  0x1EFC

    .global DAT_0600f01e
DAT_0600f01e:
    .2byte  0x090C

    .global DAT_0600f020
DAT_0600f020:
    .2byte  0x1FC8

    .global DAT_0600f022
DAT_0600f022:
    .2byte  0x080C

    .global DAT_0600f024
DAT_0600f024:
    .2byte  0x2060
.L_spr_size_0x110:
    .2byte  0x0110

    .global DAT_0600f028
DAT_0600f028:
    .2byte  0x2080

    .global DAT_0600f02a
DAT_0600f02a:
    .2byte  0x20A0

    .global DAT_0600f02c
DAT_0600f02c:
    .2byte  0x211C

    .global DAT_0600f02e
DAT_0600f02e:
    .2byte  0x2194

    .global DAT_0600f030
DAT_0600f030:
    .2byte  0x225C

    .global DAT_0600f032
DAT_0600f032:
    .2byte  0x22F4

    .global DAT_0600f034
DAT_0600f034:
    .2byte  0x22FC

    .global DAT_0600f036
DAT_0600f036:
    .2byte  0x2304
.L_sprite_reg_phase4:
    add r13, r7
    mov #0x14, r6
    mov r12, r5
    jsr @r14
    mov #0x34, r4
    mov #0x14, r6
    mov r12, r5
    mov.w   DAT_0600f14c, r7
    add r13, r7
    jsr @r14
    mov #0x35, r4
    mov #0x10, r6
    mov r12, r5
    mov.w   DAT_0600f14e, r7
    add r13, r7
    jsr @r14
    mov #0x36, r4
    mov #0x1C, r6
    mov r12, r5
    mov.w   DAT_0600f150, r7
    add r13, r7
    jsr @r14
    mov #0x37, r4
    mov #0x8, r6
    mov r12, r5
    mov.w   DAT_0600f152, r7
    add r13, r7
    jsr @r14
    mov #0x38, r4
    mov #0x10, r6
    mov r12, r5
    mov.w   .L_cdrom_off_last, r7
    add r13, r7
    jsr @r14
    mov #0x39, r4
    mov #0x1, r3
    mov r11, r6
    mov.l   .L_sprite_flag, r2
    mov r3, r5
    mov.w r3, @r2
    mov.l   .L_fn_obj_register, r12
    jsr @r12
    mov #0x41, r4
    mov r11, r6
    mov #0x2, r5
    jsr @r12
    mov #0x42, r4
    mov r11, r6
    mov #0x3, r5
    jsr @r12
    mov #0x43, r4
    mov r11, r6
    mov #0x4, r5
    jsr @r12
    mov #0x44, r4
    mov r11, r6
    mov #0x5, r5
    jsr @r12
    mov #0x45, r4
    mov r11, r6
    mov #0x6, r5
    jsr @r12
    mov #0x46, r4
    mov #0x4, r6
    mov #0x7, r5
    jsr @r12
    mov #0x47, r4
    mov #0x4, r6
    mov #0x8, r5
    jsr @r12
    mov #0x48, r4
    mov r11, r6
    mov #0x9, r5
    jsr @r12
    mov #0x49, r4
    mov #0x3C, r6
    mov #0xA, r5
    jsr @r12
    mov #0x4A, r4
    mov #0x20, r6
    mov #0x10, r5
    jsr @r12
    mov #0x50, r4
    mov #0x20, r6
    mov #0x11, r5
    jsr @r12
    mov #0x51, r4
    mov #0x20, r6
    mov #0x12, r5
    jsr @r12
    mov #0x52, r4
    mov #0x20, r6
    mov #0x13, r5
    jsr @r12
    mov #0x53, r4
    mov #0x20, r6
    mov #0x14, r5
    jsr @r12
    mov #0x54, r4
    mov #0x20, r6
    mov #0x15, r5
    jsr @r12
    mov #0x55, r4
    mov #0x24, r6
    mov #0x16, r5
    jsr @r12
    mov #0x56, r4
    mov #0x20, r6
    mov #0x17, r5
    jsr @r12
    mov #0x57, r4
    mov #0x34, r6
    mov #0x18, r5
    jsr @r12
    mov #0x58, r4
    mov #0x28, r6
    mov #0x19, r5
    jsr @r12
    mov #0x59, r4
    mov #0x28, r6
    mov #0x1A, r5
    jsr @r12
    mov #0x5A, r4
    mov #0x28, r6
    mov #0x1B, r5
    jsr @r12
    mov #0x5B, r4
    mov #0x34, r6
    mov #0x1C, r5
    jsr @r12
    mov #0x5C, r4
    mov #0x28, r6
    mov #0x1D, r5
    jsr @r12
    mov #0x5D, r4
    mov #0x30, r6
    bra     .L_obj_reg_phase2
    nop

    .global DAT_0600f14c
DAT_0600f14c:
    .2byte  0x230C

    .global DAT_0600f14e
DAT_0600f14e:
    .2byte  0x2314

    .global DAT_0600f150
DAT_0600f150:
    .2byte  0x231C

    .global DAT_0600f152
DAT_0600f152:
    .2byte  0x2324
.L_cdrom_off_last:
    .2byte  0x232C                      /* cdrom offset: slot 0x39 (last basic sprite) */
    .2byte  0xFFFF                      /* alignment padding */
.L_sprite_flag:
    .4byte  sym_06089E46                /* &sprite_ready_flag (word, set to 1) */
.L_fn_obj_register:
    .4byte  sym_06007540                /* object registration: r4=slot r5=obj_id r6=flags */
.L_obj_reg_phase2:
    mov #0x1E, r5
    jsr @r12
    mov #0x5E, r4
    mov #0x30, r6
    mov #0x1F, r5
    jsr @r12
    mov #0x5F, r4
    mov #0x24, r6
    mov #0x20, r5
    jsr @r12
    mov #0x60, r4
    mov #0x24, r6
    mov #0x21, r5
    jsr @r12
    mov #0x61, r4
    mov #0x24, r6
    mov #0x22, r5
    jsr @r12
    mov #0x62, r4
    mov #0x24, r6
    mov #0x23, r5
    jsr @r12
    mov #0x63, r4
    mov #0x24, r6
    mov r6, r5
    jsr @r12
    mov #0x64, r4
    mov #0x2C, r6
    mov #0x25, r5
    jsr @r12
    mov #0x65, r4
    mov #0x2C, r6
    mov #0x26, r5
    jsr @r12
    mov #0x66, r4
    mov #0x24, r6
    mov #0x27, r5
    jsr @r12
    mov #0x67, r4
    mov #0x2C, r6
    mov #0x28, r5
    jsr @r12
    mov #0x68, r4
    mov #0x2C, r6
    mov #0x29, r5
    jsr @r12
    mov #0x69, r4
    mov #0x2C, r6
    mov #0x2A, r5
    jsr @r12
    mov #0x6A, r4
    mov #0x2C, r6
    mov #0x2B, r5
    jsr @r12
    mov #0x6B, r4
    mov #0x24, r6
    mov #0x2C, r5
    jsr @r12
    mov #0x6C, r4
    mov #0x24, r6
    mov #0x2D, r5
    jsr @r12
    mov #0x6D, r4
    mov #0x2C, r6
    mov #0x2E, r5
    jsr @r12
    mov #0x6E, r4
    mov #0x2C, r6
    mov #0x2F, r5
    jsr @r12
    mov #0x6F, r4
    mov #0x2C, r6
    mov #0x30, r5
    jsr @r12
    mov #0x70, r4
    mov #0x2C, r6
    mov #0x31, r5
    jsr @r12
    mov #0x71, r4
    mov #0x2C, r6
    mov #0x32, r5
    jsr @r12
    mov #0x72, r4
    mov #0x2C, r6
    mov #0x33, r5
    jsr @r12
    mov #0x73, r4
    mov #0x2C, r6
    mov #0x34, r5
    jsr @r12
    mov #0x74, r4
    mov #0x2C, r6
    mov #0x35, r5
    jsr @r12
    mov #0x75, r4
    mov #0x28, r6
    mov #0x36, r5
    jsr @r12
    mov #0x76, r4
    mov #0x34, r6
    mov #0x37, r5
    jsr @r12
    mov #0x77, r4
    mov #0x20, r6
    mov #0x38, r5
    jsr @r12
    mov #0x78, r4
    mov #0x28, r6
    mov #0x39, r5
    jsr @r12
    mov #0x79, r4
    mov #0x78, r6
    mov.w   .L_slot_0x101, r4
    mov.w   .L_spr_size_0xB40, r8
    mov.w   DAT_0600f26c, r7
    add r13, r7
    jsr @r14
    mov r8, r5
    mov.w   DAT_0600f270, r7
    mov #0x7C, r6
    mov.w   DAT_0600f272, r4
    add r13, r7
    jsr @r14
    mov r8, r5
    mov.w   .L_flags_0x80, r9
    mov.w   DAT_0600f276, r7
    mov.w   .L_slot_0x103, r4
    mov r9, r6
    add r13, r7
    jsr @r14
    mov r8, r5
    bra     .L_obj_reg_final
    nop
.L_spr_size_0xB40:
    .2byte  0x0B40                      /* large sprite group size param */

    .global DAT_0600f26c
DAT_0600f26c:
    .2byte  0x4B46                      /* cdrom offset: slot 0x101 sprite data */
.L_slot_0x101:
    .2byte  0x0101                      /* extended VDP1 slot 0x101 */

    .global DAT_0600f270
DAT_0600f270:
    .2byte  0x5313                      /* cdrom offset: slot 0x102 sprite data */

    .global DAT_0600f272
DAT_0600f272:
    .2byte  0x0102                      /* extended VDP1 slot 0x102 */
.L_flags_0x80:
    .2byte  0x0080                      /* sprite flags: bit 7 set */

    .global DAT_0600f276
DAT_0600f276:
    .2byte  0x5B86                      /* cdrom offset: slot 0x103 sprite data */
.L_slot_0x103:
    .2byte  0x0103                      /* extended VDP1 slot 0x103 */
.L_obj_reg_final:
    mov.w   DAT_0600f342, r6
    mov.w   DAT_0600f344, r4
    mov r6, r5
    jsr @r12
    add #0x7D, r5
    mov.w   DAT_0600f346, r6
    mov.w   DAT_0600f348, r4
    mov r6, r5
    jsr @r12
    add #0x7A, r5
    mov.w   DAT_0600f34a, r6
    mov.w   .L_slot_0x106, r4
    mov r6, r5
    jsr @r12
    add #0x77, r5
    mov.l   .L_fp_half_0600F350, r2
    mov.l   .L_vdp1_mode_addr, r3
    mov.w r2, @r3
    mov r3, r6
    mov.l   .L_vdp2_cram_0xFFE, r4
    mov.l   .L_fn_tilemap_dma, r3
    jsr @r3
    mov #0x1, r5
    mov.l   .L_fn_subsys_b, r3
    jsr @r3
    nop
    mov.l   .L_fn_audio_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_render_coord, r3
    jsr @r3
    nop
    mov r10, r6
    mov.l   .L_pal_src_bg, r2
    mov.l   .L_fn_memcpy_word, r14
    mov.l r2, @r15
    mov.l   .L_vdp2_cram_0x060, r4
    jsr @r14
    mov r2, r5
    mov r10, r6
    mov.l   .L_vdp2_cram_0x460, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x20, r6
    mov.l   .L_pal_src_spr_a, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x520, r4
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    mov.l   .L_vdp2_cram_0x540, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x40, r6
    mov.l   .L_pal_src_obj, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x1A0, r4
    jsr @r14
    mov r3, r5
    mov #0x40, r6
    mov.l   .L_vdp2_cram_0x7A0, r4
    jsr @r14
    mov.l @r15, r5
    mov #0x20, r6
    mov.l   .L_pal_src_obj_b, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x1E0, r4
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    mov.l   .L_vdp2_cram_0x7E0, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_pal_src_effect, r5
    mov.l   .L_vdp2_cram_0x5A0, r4
    jsr @r14
    mov #0x40, r6
    mov #0x60, r6
    mov.l   .L_pal_src_base, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x000, r4
    jsr @r14
    mov r3, r5
    mov #0x60, r6
    mov.l   .L_vdp2_cram_0x600, r4
    jsr @r14
    mov.l @r15, r5
    mov.l   .L_pal_src_spr_b, r5
    mov.l   .L_vdp2_cram_0x6A0, r4
    jsr @r14
    mov #0x20, r6
    mov r9, r6
    mov.l   .L_pal_src_nbg, r3
    mov.l r3, @r15
    mov.l   .L_vdp2_cram_0x120, r4
    jsr @r14
    mov r3, r5
    mov r9, r6
    bra     .L_palette_and_cleanup
    mov.l @r15, r5

    .global DAT_0600f342
DAT_0600f342:
    .2byte  0x0084                      /* obj flags for slot 0x104 */

    .global DAT_0600f344
DAT_0600f344:
    .2byte  0x0104                      /* extended obj slot 0x104 */

    .global DAT_0600f346
DAT_0600f346:
    .2byte  0x0088                      /* obj flags for slot 0x105 */

    .global DAT_0600f348
DAT_0600f348:
    .2byte  0x0105                      /* extended obj slot 0x105 */

    .global DAT_0600f34a
DAT_0600f34a:
    .2byte  0x008C                      /* obj flags for slot 0x106 */
.L_slot_0x106:
    .2byte  0x0106                      /* extended VDP1 slot 0x106 */
    .2byte  0xFFFF                      /* alignment padding */
.L_fp_half_0600F350:
    .4byte  0x00008000                  /* 0.5 in 16.16 fixed-point */
.L_vdp1_mode_addr:
    .4byte  sym_06086028                /* &display_control_flag (word) */
.L_vdp2_cram_0xFFE:
    .4byte  0x25F00FFE                  /* VDP2 CRAM last entry (end marker) */
.L_fn_tilemap_dma:
    .4byte  tilemap_dma_update          /* tilemap DMA update function */
.L_fn_subsys_b:
    .4byte  sym_060149E0                /* display_disable: clears bit 15 of display state */
.L_fn_audio_init:
    .4byte  audio_display_init          /* audio/display init function */
.L_fn_render_coord:
    .4byte  render_coord_transform      /* render coordinate transform */
.L_fn_memcpy_word:
    .4byte  memcpy_word_idx             /* word-indexed memcpy for palette DMA */
.L_pal_src_bg:
    .4byte  sym_060484EC                /* BG palette source (0xC0 bytes) */
.L_vdp2_cram_0x060:
    .4byte  0x25F00060                  /* CRAM +0x060: BG palette bank A */
.L_vdp2_cram_0x460:
    .4byte  0x25F00460                  /* CRAM +0x460: BG palette bank B (mirror) */
.L_pal_src_spr_a:
    .4byte  sym_0604870C                /* sprite palette source A (0x20 bytes) */
.L_vdp2_cram_0x520:
    .4byte  0x25F00520                  /* CRAM +0x520: sprite palette A */
.L_vdp2_cram_0x540:
    .4byte  0x25F00540                  /* CRAM +0x540: sprite palette A mirror */
.L_pal_src_obj:
    .4byte  sym_0604842C                /* object palette source (0x40 bytes) */
.L_vdp2_cram_0x1A0:
    .4byte  0x25F001A0                  /* CRAM +0x1A0: object palette bank A */
.L_vdp2_cram_0x7A0:
    .4byte  0x25F007A0                  /* CRAM +0x7A0: object palette bank B (mirror) */
.L_pal_src_obj_b:
    .4byte  sym_0604846C                /* object palette source B (0x20 bytes) */
.L_vdp2_cram_0x1E0:
    .4byte  0x25F001E0                  /* CRAM +0x1E0: object palette B bank A */
.L_vdp2_cram_0x7E0:
    .4byte  0x25F007E0                  /* CRAM +0x7E0: object palette B bank B (mirror) */
.L_pal_src_effect:
    .4byte  sym_0605CA5C                /* effect palette source (0x40 bytes) */
.L_vdp2_cram_0x5A0:
    .4byte  0x25F005A0                  /* CRAM +0x5A0: effect palette */
.L_pal_src_base:
    .4byte  sym_0604814C                /* base palette source (0x60 bytes) */
.L_vdp2_cram_0x000:
    .4byte  0x25F00000                  /* CRAM +0x000: base palette bank A */
.L_vdp2_cram_0x600:
    .4byte  0x25F00600                  /* CRAM +0x600: base palette bank B (mirror) */
.L_pal_src_spr_b:
    .4byte  sym_060484CC                /* sprite palette source B (0x20 bytes) */
.L_vdp2_cram_0x6A0:
    .4byte  0x25F006A0                  /* CRAM +0x6A0: sprite palette B */
.L_pal_src_nbg:
    .4byte  sym_060487AC                /* NBG palette source (r9 bytes) */
.L_vdp2_cram_0x120:
    .4byte  0x25F00120                  /* CRAM +0x120: NBG palette */
.L_palette_and_cleanup:
    .byte   0xD4, 0x27    /* mov.l .L_pool_0600F464, r4 */   ! r4 = VDP2 CRAM +0x720 (course palette ext A dest)
    jsr @r14
    nop
    mov #0x20, r6
    .byte   0xD3, 0x26    /* mov.l .L_pool_0600F468, r3 */   ! r3 = sym_060487CC (palette source C)
    mov.l r3, @r15
    .byte   0xD4, 0x26    /* mov.l .L_pool_0600F46C, r4 */   ! r4 = VDP2 CRAM +0x680 (palette dest)
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    .byte   0xD4, 0x25    /* mov.l .L_pool_0600F470, r4 */   ! r4 = VDP2 CRAM +0x140 (palette dest, bank 6)
    jsr @r14
    mov.l @r15, r5
    mov #0x20, r6
    .byte   0xD3, 0x24    /* mov.l .L_pool_0600F474, r3 */   ! r3 = sym_060483EC (palette source D)
    mov.l r3, @r15
    .byte   0xD4, 0x24    /* mov.l .L_pool_0600F478, r4 */   ! r4 = VDP2 CRAM +0x0C0 (palette dest)
    jsr @r14
    mov r3, r5
    mov #0x20, r6
    .byte   0xD4, 0x23    /* mov.l .L_pool_0600F47C, r4 */   ! r4 = VDP2 CRAM +0x6C0 (course palette bank)
    jsr @r14
    mov.l @r15, r5
    extu.w r11, r3
    .byte   0xD2, 0x22    /* mov.l .L_pool_0600F480, r2 */   ! r2 = &scroll_position_state (sym_0605AAA0)
    mov.w r3, @r2
    .byte   0xD2, 0x22    /* mov.l .L_pool_0600F484, r2 */   ! r2 = &game_state_byte (sym_0607887F)
    mov.b r11, @r2
    .byte   0xD4, 0x22    /* mov.l .L_pool_0600F488, r4 */   ! r4 = &render_mode_flags (sym_0605B6D8)
    .byte   0xD1, 0x23    /* mov.l .L_pool_0600F48C, r1 */   ! r1 = 0x40000000 (bit 30 = "race ready")
    .byte   0xD3, 0x23    /* mov.l .L_pool_0600F490, r3 */   ! r3 = display_update fn (sym_06026CE0)
    mov.l @r4, r2
    or r1, r2
    jsr @r3
    mov.l r2, @r4
    mov r11, r2
    .byte   0xD3, 0x21    /* mov.l .L_pool_0600F494, r3 */   ! r3 = &animation_state (sym_06059F44)
    mov.l r11, @r3
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
