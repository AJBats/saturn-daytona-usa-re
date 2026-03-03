	.text
    .global state_race_main
state_race_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0600911C, r8
    mov.l   .L_06009120, r9
    mov.l   .L_06009124, r10
    mov.l   .L_06009128, r11
    mov.l   .L_0600912C, r14
    mov.l   .L_06009130, r3
    mov.w @r3, r2
    mov.w   .L_0600911A, r3
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt.s    .L_060090CE
    mov #0x10, r13
    mov #0xF, r3
    mov.l   .L_06009134, r2
    mov.l r3, @r2
    mov #0x12, r3
    mov.l r3, @r10
.L_060090CE:
    mov.l   .L_06009138, r2
    mov.l   .L_06009138, r3
    mov.l @r2, r2
    add #-0x1, r2
    mov.l r2, @r3
    mov.l   .L_0600913C, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060090E6
    mov.l   .L_06009140, r3
    jsr @r3
    mov #0x0, r4
.L_060090E6:
    mov.w @r11, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_060090F4
    mov.l   .L_06009144, r3
    jsr @r3
    nop
.L_060090F4:
    mov #0x0, r12
    mov.l   .L_06009148, r2
    bra     .L_060091A0
    mov.l r2, @r15
.L_060090FC:
    mov.l   .L_0600914C, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_06009162
    extu.b r12, r12
    tst r12, r12
    bf      .L_06009150
    mov #0x1, r3
    mov.w r3, @r11
    mov.l @r15, r2
    mov.l r2, @r14
    mov r2, r3
    bra     .L_06009162
    mov.l r2, @r9
.L_0600911A:
    .short  0x0800
.L_0600911C:
    .long  sym_0607ED88
.L_06009120:
    .long  sym_0607E940
.L_06009124:
    .long  g_game_state
.L_06009128:
    .long  sym_0607ED8C
.L_0600912C:
    .long  sym_0607E944
.L_06009130:
    .long  sym_06063D9A
.L_06009134:
    .long  sym_0607EACC
.L_06009138:
    .long  sym_0607EBCC
.L_0600913C:
    .long  sym_0605AB18
.L_06009140:
    .long  menu_overlay_render
.L_06009144:
    .long  sym_060033E6
.L_06009148:
    .long  sym_06078B68
.L_0600914C:
    .long  sym_06078635
.L_06009150:
    mov #0x0, r2
    mov.w r2, @r11
    mov.l   .L_06009224, r3
    mov.l r3, @r14
    mov r3, r2
    mov.l r3, @r9
    mov.l @r8, r3
    add #-0x2, r3
    mov.l r3, @r8
.L_06009162:
    mov.l   .L_06009228, r3
    jsr @r3
    nop
    mov.l   .L_0600922C, r3
    jsr @r3
    nop
    mov.l   .L_06009230, r3
    jsr @r3
    nop
    mov.l   .L_06009234, r3
    jsr @r3
    nop
    mov.l   .L_06009238, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_06009194
    mov.l   .L_0600923C, r3
    jsr @r3
    nop
    mov.l   .L_06009240, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600919E
    bra     .L_0600919E
    mov.l r13, @r10
.L_06009194:
    mov.l   .L_06009244, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0600919E
    mov.l r13, @r10
.L_0600919E:
    add #0x1, r12
.L_060091A0:
    extu.b r12, r3
    mov.l   .L_06009248, r2
    mov.b @r2, r2
    extu.b r2, r2
    cmp/ge r2, r3
    bf      .L_060090FC
    mov.l   .L_0600924C, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_060091BE
    mov.l   .L_06009250, r3
    jsr @r3
    nop
    bra     .L_060091C4
    nop
.L_060091BE:
    mov.l   .L_06009254, r3
    jsr @r3
    nop
.L_060091C4:
    mov.l   .L_06009258, r3
    jsr @r3
    nop
    mov.l   .L_0600925C, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_060091EA
    mov.l   .L_06009260, r3
    jsr @r3
    nop
    mov.l   .L_06009264, r6
    mov.l   .L_06009268, r5
    mov.l   .L_0600926C, r4
    mov.l   .L_06009270, r3
    jsr @r3
    mov.l @r6, r6
    bra     .L_060091F0
    nop
.L_060091EA:
    mov.l   .L_06009274, r3
    jsr @r3
    nop
.L_060091F0:
    mov.l   .L_06009278, r3
    jsr @r3
    nop
    mov.l   .L_0600927C, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0600920C
    mov.l   .L_06009280, r7
    mov.l   .L_06009284, r6
    mov.w   .L_06009222, r5
    mov.l   .L_06009288, r3
    jsr @r3
    mov #0x8, r4
.L_0600920C:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_0600928C, r3
    jmp @r3
    mov.l @r15+, r14
.L_06009222:
    .short  0x0082
.L_06009224:
    .long  sym_06078900
.L_06009228:
    .long  sym_060302C6
.L_0600922C:
    .long  render_camera_compute
.L_06009230:
    .long  sym_0602F0E8
.L_06009234:
    .long  race_state_update
.L_06009238:
    .long  sym_0607EAD8
.L_0600923C:
    .long  sym_0600C302
.L_06009240:
    .long  sym_0607EBCC
.L_06009244:
    .long  sym_0607EAD0
.L_06009248:
    .long  sym_06078634
.L_0600924C:
    .long  sym_06083255
.L_06009250:
    .long  terrain_data_lookup
.L_06009254:
    .long  sprite_transform
.L_06009258:
    .long  sym_06012198
.L_0600925C:
    .long  sym_06078654
.L_06009260:
    .long  camera_system
.L_06009264:
    .long  sym_06063E24
.L_06009268:
    .long  sym_06063EEC
.L_0600926C:
    .long  sym_06063EF8
.L_06009270:
    .long  camera_orient_calc
.L_06009274:
    .long  perspective_project
.L_06009278:
    .long  scene_master
.L_0600927C:
    .long  sym_06086030
.L_06009280:
    .long  sym_0605A1C8
.L_06009284:
    .long  0x0000F000
.L_06009288:
    .long  sym_060283E0
.L_0600928C:
    .long  frame_end_commit
