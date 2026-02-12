#include "game.h"

extern int DAT_060047d2;
extern int DAT_060047d4;
extern int DAT_0600498a;
extern int DAT_0600498c;
extern int DAT_0600498e;
extern int DAT_06004a88;
extern int DAT_06004a8a;
extern int DAT_06004a8c;
extern int DAT_060052f6;
extern int DAT_0600537a;
extern int DAT_0600584e;
extern int DAT_06005850;
extern int DAT_06005852;
extern int DAT_0600590c;
extern int DAT_0600590e;
extern int DAT_06005910;
extern int DAT_060059da;
extern int DAT_060059dc;
extern int DAT_060059de;
extern int DAT_060059e0;
extern int DAT_060059e2;
extern int DAT_060059e4;
extern int DAT_060059e6;
extern int DAT_06005aba;
extern int DAT_06005abc;
extern int DAT_06005abe;
extern int DAT_06005ac0;
extern int DAT_06005ac2;
extern int DAT_06005b7c;
extern int DAT_06005b7e;
extern int DAT_06005b80;
extern int DAT_06005b82;
extern int DAT_06005b84;
extern int DAT_06005b86;
extern int DAT_06005b88;
extern int DAT_06005b8a;
extern int DAT_06005c74;
extern int DAT_06005c76;
extern int DAT_06005d3e;
extern int DAT_06005dcc;
extern int DAT_06005dce;
extern int DAT_06005eae;
extern int DAT_06005eb0;
extern int DAT_06005eb2;
extern int DAT_06005eb4;
extern int DAT_06006116;
extern void vec3_angle_calc();
extern void FUN_0600553c();
extern void animation_frame_counter();
extern void FUN_06005a22();
extern int FUN_06005ae8();
extern int FUN_06005c98();
extern char * FUN_06005dd4();
extern int PTR_DAT_060055a0;
extern int PTR_DAT_06005854;
extern int PTR_DAT_060059e8;
extern int PTR_DAT_06005b8c;
extern int PTR_DAT_06005c78;
extern int PTR_DAT_06005d40;
extern int PTR_DAT_06006118;

void obj_template_init()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  puVar3 = (char *)0x06042CEE;

  puVar2 = (int *)0x06063690;

  *(char **)0x06063690 = 0x06042CEE;

  *(short *)(puVar2 + 4) = DAT_060047d2;

  puVar2[6] = 1;

  puVar2[7] = 2;

  puVar2[9] = 1;

  *(short *)(puVar2 + 10) = (0x40 - (short)(char)puVar2[6] * (short)(char)puVar2[9]) << 1;

  puVar2[8] = puVar2[6] * puVar2[7] * '\x02';

  *(char **)(puVar2 + 0xc) = puVar3;

  *(short *)(puVar2 + 0x10) = DAT_060047d2;

  puVar2[0x12] = 1;

  puVar2[0x13] = 2;

  puVar2[0x15] = 2;

  *(short *)(puVar2 + 0x16) = (0x40 - (short)(char)puVar2[0x12] * (short)(char)puVar2[0x15]) << 1;

  puVar2[0x14] = puVar2[0x12] * puVar2[0x13] * '\x02';

  *(char **)(puVar2 + 0x18) = 0x06042D72;

  uVar1 = DAT_060047d4;

  *(short *)(puVar2 + 0x1c) = DAT_060047d4;

  puVar2[0x1e] = 2;

  puVar2[0x1f] = 2;

  puVar2[0x21] = 3;

  *(short *)(puVar2 + 0x22) = (0x40 - (short)(char)puVar2[0x1e] * (short)(char)puVar2[0x21]) << 1;

  puVar2[0x20] = puVar2[0x1e] * puVar2[0x1f] * '\x02';

  *(char **)(puVar2 + 0x24) = 0x06042D1A;

  *(short *)(puVar2 + 0x28) = uVar1;

  puVar2[0x2a] = 2;

  puVar2[0x2b] = 2;

  puVar2[0x2d] = 3;

  *(short *)(puVar2 + 0x2e) = (0x40 - (short)(char)puVar2[0x2a] * (short)(char)puVar2[0x2d]) << 1;

  puVar2[0x2c] = puVar2[0x2a] * puVar2[0x2b] * '\x02';

  *(char **)(puVar2 + 0x30) = 0x06042DCA;

  *(short *)(puVar2 + 0x34) = uVar1;

  puVar2[0x36] = 2;

  puVar2[0x37] = 3;

  puVar2[0x39] = 2;

  *(short *)(puVar2 + 0x3a) = (0x40 - (short)(char)puVar2[0x36] * (short)(char)puVar2[0x39]) << 1;

  puVar2[0x38] = puVar2[0x36] * puVar2[0x37] * '\x02';

  puVar3 = (char *)0x06042CBC;

  *(char **)(puVar2 + 0x3c) = 0x06042CBC;

  *(short *)(puVar2 + 0x40) = uVar1;

  puVar2[0x42] = 1;

  puVar2[0x43] = 1;

  puVar2[0x45] = 2;

  *(short *)(puVar2 + 0x46) = (0x40 - (short)(char)puVar2[0x42] * (short)(char)puVar2[0x45]) << 1;

  puVar2[0x44] = puVar2[0x42] * puVar2[0x43] * '\x02';

  puVar4 = (char *)0x06042CD2;

  *(char **)(puVar2 + 0x48) = 0x06042CD2;

  *(short *)(puVar2 + 0x4c) = uVar1;

  puVar2[0x4e] = 1;

  puVar2[0x4f] = 1;

  puVar2[0x51] = 0;

  *(short *)(puVar2 + 0x52) = 0;

  puVar2[0x50] = puVar2[0x4e] * puVar2[0x4f] * '\x02';

  *(char **)(puVar2 + 0x54) = puVar4;

  *(short *)(puVar2 + 0x58) = DAT_0600498a;

  puVar2[0x5a] = 1;

  puVar2[0x5b] = 1;

  puVar2[0x5d] = 0;

  *(short *)(puVar2 + 0x5e) = 0;

  puVar2[0x5c] = puVar2[0x5a] * puVar2[0x5b] * '\x02';

  *(char **)(puVar2 + 0x60) = 0x06042E4E;

  *(short *)(puVar2 + 100) = DAT_0600498c;

  puVar2[0x66] = 2;

  puVar2[0x67] = 2;

  puVar2[0x69] = 0x20;

  *(short *)(puVar2 + 0x6a) = 0;

  puVar2[0x68] = puVar2[0x66] * puVar2[0x67] * '\x02';

  *(char **)(puVar2 + 0x6c) = puVar3;

  *(short *)(puVar2 + 0x70) = DAT_0600498e;

  puVar2[0x72] = 1;

  puVar2[0x73] = 1;

  puVar2[0x75] = 1;

  *(short *)(puVar2 + 0x76) = (0x40 - (short)(char)puVar2[0x72] * (short)(char)puVar2[0x75]) << 1;

  puVar2[0x74] = puVar2[0x72] * puVar2[0x73] * '\x02';

  *(char **)(puVar2 + 0x78) = 0x0604304E;

  *(short *)(puVar2 + 0x7c) = DAT_0600498c;

  puVar2[0x7e] = 2;

  puVar2[0x7f] = 2;

  puVar2[0x81] = 0;

  *(short *)(puVar2 + 0x82) = 0;

  puVar2[0x80] = puVar2[0x7e] * puVar2[0x7f] * '\x02';

  *(char **)(puVar2 + 0x84) = puVar3;

  *(short *)(puVar2 + 0x88) = DAT_06004a88;

  puVar2[0x8a] = 1;

  puVar2[0x8b] = 1;

  puVar2[0x8d] = 1;

  *(short *)(puVar2 + 0x8e) = (0x40 - (short)(char)puVar2[0x8a] * (short)(char)puVar2[0x8d]) << 1;

  puVar2[0x8c] = puVar2[0x8a] * puVar2[0x8b] * '\x02';

  *(char **)(puVar2 + 0x90) = 0x06059CC0;

  *(short *)(puVar2 + 0x94) = DAT_06004a8a;

  puVar2[0x96] = 1;

  puVar2[0x97] = 2;

  puVar2[0x99] = 0x20;

  *(short *)(puVar2 + 0x9a) = 0;

  puVar2[0x98] = puVar2[0x96] * puVar2[0x97] * '\x02';

  *(char **)(puVar2 + 0x9c) = 0x06059DC0;

  *(short *)(puVar2 + 0xa0) = DAT_06004a8c;

  puVar2[0xa2] = 1;

  puVar2[0xa3] = 2;

  puVar2[0xa5] = 0;

  *(short *)(puVar2 + 0xa6) = 0;

  puVar2[0xa4] = puVar2[0xa2] * puVar2[0xa3] * '\x02';

  return;

}

/* vdp_char_register -- Register sprite character data and upload pixels to VDP VRAM.
 * param_2 flags: bit2=copy header to display list, bits0-1=VRAM bank select,
 * bit3=use DMA instead of memcpy. Uploads to 0x25E00000 (VDP1) or 0x25E20000 (VDP2). */
void FUN_06004f14(param_1, param_2, param_3, param_4)
    short *param_1;
    unsigned int param_2;
    int param_3;
    int param_4;
{
  char *obj_table;
  char *vram_b_ptr;
  char *vram_a_ptr;
  char *slot_idx;
  unsigned short data_size;
  short *sprite_ptr;
  slot_idx = (char *)0x06059F10;
  vram_a_ptr = (char *)0x06059F18;
  vram_b_ptr = (int *)0x06059F1C;
  obj_table = (char *)0x06063750;
  /* Copy sprite header to display list buffer if flagged */
  if ((param_2 & 4) != 0) {
    data_size = (param_1[1] * *param_1 + 2) << 1;
    sprite_ptr = *(short **)0x06063D90;
    (*(int(*)())0x0602761E)(sprite_ptr,param_1,data_size);  /* memcpy */
    *(unsigned int *)0x06063D90 = *(int *)0x06063D90 + (unsigned int)data_size;
    *(unsigned int *)0x06063D94 = *(int *)0x06063D94 + (unsigned int)data_size;
    param_1 = sprite_ptr;
  }
  if (param_3 == 0) {
    /* No pixel data — reuse previous slot's VRAM offset */
    *(int *)(obj_table + (*(int *)slot_idx << 3) + 4) =
         *(int *)(obj_table + ((*(int *)slot_idx + -1) << 3) + 4);
  }
  else if ((param_2 & 3) == 0) {
    /* Upload to VDP1 VRAM (bank A at 0x25E00000) */
    *(int *)(obj_table + *(int *)((int)(int)slot_idx << 3) + 4) = *(int *)vram_a_ptr;
    if ((param_2 & 8) == 0) {
      (*(int(*)())0x0602761E)(0x25E00000 + *(int *)((int)(int)vram_a_ptr << 5),param_3,param_4 << 5);
    }
    else {
      (*(int(*)())0x06028654)(param_3,0x25E00000 + *(int *)((int)(int)vram_a_ptr << 5));  /* DMA */
    }
    *(int *)vram_a_ptr = *(int *)vram_a_ptr + param_4;
  }
  else {
    /* Upload to VDP2 VRAM (bank B at 0x25E20000) */
    *(int *)(obj_table + *(int *)((int)(int)slot_idx << 3) + 4) = *(int *)vram_b_ptr;
    if ((param_2 & 8) == 0) {
      (*(int(*)())0x0602761E)(0x25E20000 + *(int *)((int)(int)vram_b_ptr << 5),param_3,param_4 << 5);
    }
    else {
      (*(int(*)())0x06028654)(param_3,0x25E20000 + *(int *)((int)(int)vram_b_ptr << 5));  /* DMA */
    }
    *(int *)vram_b_ptr = *(int *)vram_b_ptr + param_4;
  }
  /* Store sprite pointer in object table and advance slot */
  *(short **)(obj_table + *(int *)((int)(int)slot_idx << 3)) = param_1;
  *(int *)slot_idx = *(int *)slot_idx + 1;
  return;
}

/* vdp1_sprite_upload -- Upload sprite character data and register in display list.
 * If bit 2 of param_3 is set, copies sprite header (width*height+2 words) to
 * work buffer at 0x06063D90 and advances VRAM pointers. Registers sprite
 * pointer and palette offset (param_2) into display list table at 0x06063750.
 * Increments display list entry count at 0x06059F10. */
void FUN_0600508a(unsigned short *param_1, int param_2, unsigned int param_3)
{
  int *work_ptr = (int *)0x06063D90;       /* VRAM work buffer pointer */
  int *entry_count = (int *)0x06059F10;    /* display list entry count */

  if ((param_3 & 4) != 0) {
    /* Copy sprite data to work buffer */
    unsigned short *dest = *(unsigned short **)work_ptr;
    unsigned int size = ((unsigned int)param_1[1] * (unsigned int)*param_1 + 2) << 1 & 0xffff;
    (*(int(*)())0x0602761E)(dest, param_1, size);
    *work_ptr = *work_ptr + size;
    *(int *)0x06063D94 = *(int *)0x06063D94 + size;
    param_1 = dest;
  }

  /* Register in display list table (8 bytes per entry) */
  *(int *)(0x06063750 + *entry_count * 8 + 4) = param_2;
  *(unsigned short **)(0x06063750 + *entry_count * 8) = param_1;
  *entry_count = *entry_count + 1;
}

/* vdp2_upload_conditional -- Upload data to VDP2 VRAM with mode selection.
 * Selects VDP2 VRAM bank: bits 0-1 of param_4 select 0x25E00000 (A) or
 * 0x25E20000 (B). Bit 3 selects transfer mode: 0=bulk copy (0x06027630),
 * 1=DMA transfer (0x06028654). */
void FUN_0600511e(int param_1, int param_2, int param_3, unsigned int param_4)
{
  char *vdp2_base = (char *)0x25E20000;    /* VDP2 VRAM bank B */
  if ((param_4 & 3) == 0) {
    vdp2_base = (char *)0x25E00000;         /* VDP2 VRAM bank A */
  }

  if ((param_4 & 8) == 0) {
    (*(int(*)())0x06027630)(vdp2_base + param_2, param_1, param_3);  /* bulk copy */
  } else {
    (*(int(*)())0x06028654)(param_1, vdp2_base + param_2);           /* DMA transfer */
  }
}

void display_list_process()
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char *puVar6;

  unsigned short *local_14 [2];

  puVar6 = (short *)0x06063D98;

  (*(int(*)())0x06039808)(local_14);

  uVar2 = local_14[0][4];

  uVar3 = local_14[0][1];

  uVar1 = local_14[0][9];

  uVar4 = local_14[0][0xd];

  uVar5 = local_14[0][10];

  if (VBLANK_OUT_COUNTER == 1) {

    *(unsigned short *)puVar6 = ~*local_14[0];

    *(unsigned short *)(puVar6 + 2) = ~uVar2;

    *(unsigned short *)(puVar6 + 4) = ~uVar3;

    *(unsigned short *)(puVar6 + 6) = (unsigned short)*(unsigned char *)(local_14[0] + 8);

    *(unsigned short *)(puVar6 + 8) = ~uVar1;

    *(unsigned short *)(puVar6 + 10) = ~uVar4;

    *(unsigned short *)(puVar6 + 0xc) = ~uVar5;

    *(unsigned short *)(puVar6 + 0xe) = (unsigned short)*(unsigned char *)(local_14[0] + 0x11);

  }

  else {

    *(unsigned short *)puVar6 = *(unsigned short *)puVar6 | ~*local_14[0];

    *(unsigned short *)(puVar6 + 2) = *(unsigned short *)(puVar6 + 2) | ~uVar2;

    *(unsigned short *)(puVar6 + 4) = ~uVar3;

    *(unsigned short *)(puVar6 + 8) = *(unsigned short *)(puVar6 + 8) | ~uVar1;

    *(unsigned short *)(puVar6 + 10) = *(unsigned short *)(puVar6 + 10) | ~uVar4;

    *(unsigned short *)(puVar6 + 0xc) = ~uVar5;

  }

  if (*(short *)(puVar6 + 6) == 0x20) {

    *(short *)puVar6 = 0;

    *(short *)(puVar6 + 2) = 0;

    *(short *)(puVar6 + 4) = 0;

    *(short *)(puVar6 + 8) = 0;

    *(short *)(puVar6 + 10) = 0;

    *(short *)(puVar6 + 0xc) = 0;

  }

  return;

}

void vec3_angle_calc(param_1, param_2, param_3)
    int *param_1;
    int *param_2;
    int *param_3;
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  iVar3 = param_2[1];

  iVar6 = *param_2 - *param_1;

  iVar4 = param_1[1];

  iVar5 = param_2[2] - param_1[2];

  iVar1 = (*(int(*)())0x0602744C)(iVar6,iVar5);

  if (iVar6 < 0) {

    iVar6 = -iVar6;

  }

  if (iVar5 < 0) {

    iVar5 = -iVar5;

  }

  if (iVar5 < iVar6) {

    iVar2 = (*(int(*)())0x06027552)(0x0000EC83,iVar6);

    iVar6 = (*(int(*)())0x06027552)((int)DAT_060052f6,iVar5);

  }

  else {

    iVar2 = (*(int(*)())0x06027552)(0x0000EC83,iVar5);

    iVar6 = (*(int(*)())0x06027552)((int)DAT_0600537a,iVar6);

  }

  iVar3 = (*(int(*)())0x0602744C)(iVar3 - iVar4,iVar2 + iVar6);

  if (*(int *)0x06078663 != '\0') {

    (*(int(*)())0x06026E60)(0xFFFF0000,0x00010000);

  }

  (*(int(*)())0x06026E94)(-iVar3);

  (*(int(*)())0x06026EDE)(iVar1);

  (*(int(*)())0x06026E2E)(-*param_1,-param_1[1],-param_1[2]);

  (*(int(*)())0x06035168)();

  *param_3 = iVar3;

  param_3[1] = -iVar1;

  param_3[2] = 0;

  return;

}

/* object_position_transform -- Transform object position into world space.
 * Builds rotation matrix from param_2 (Y/Z/X Euler angles, negated),
 * translates by param_1 (negated), then applies param_3 (distance scale)
 * via fixed-point multiply (0x06027552). Stores result at 0x06063DF8. */
void FUN_060053ac(int *param_1, int *param_2, int param_3)
{
  register int (*func)() asm("r3") = (int(*)())0x06027552;
  register int *dest asm("r2") = (int *)0x06063DF8;
  int uVar3;
  int iVar4;
  int local_24;
  int local_20;
  int uStack_1c;
  int auStack_18[2];

  (*(void(*)())0x06026E0C)();
  *(int *)(OBJ_STATE_PRIMARY + 0x2c) = param_3;

  if (*(int *)0x06078663 != '\0') {
    (*(void(*)())0x06026E60)(0xFFFF0000, 0x00010000);
  }

  (*(void(*)())0x06026E94)(-*param_2);
  (*(void(*)())0x06026F2A)(-param_2[2]);
  (*(void(*)())0x06026EDE)(-param_2[1]);
  (*(void(*)())0x06026E2E)(-*param_1, -param_1[1], -param_1[2]);

  (*(void(*)())0x06027358)(*param_2, auStack_18, &local_24);
  (*(void(*)())0x06027358)(param_2[1], &local_20, &uStack_1c);

  uVar3 = func(local_24, local_20);
  iVar4 = func(param_3, uVar3);
  *dest = iVar4 + *param_1;

  iVar4 = func(param_3, auStack_18[0]);
  dest[1] = param_1[1] - iVar4;

  uVar3 = func(local_24, uStack_1c);
  iVar4 = func(param_3, uVar3);
  dest[2] = param_1[2] - iVar4;
}

/* matrix_push_from_car -- Load transform matrix from car slot position/rotation.
 * Reads car index from *param_1. Skips if index matches *param_2 (already loaded)
 * or is -1 (invalid). Loads identity (0x06026E0C), then pushes car XYZ position
 * (CAR_ARRAY_BASE + slot*0x268 + 0x10/0x14/0x18) and rotations (+0x20/0x1C/0x24)
 * onto the matrix stack via translate (0x06026E2E) and rotate functions. */
void FUN_0600553c(char *param_1, char *param_2)
{
  char slot = *param_1;
  int skip = 1;

  if ((param_2 != (char *)0x0) && (slot == *param_2)) {
    skip = 0;
  }

  if (skip && ((*(int(*)())0x06026E0C)(), slot != -1)) {
    int off = (int)slot * CAR_STRUCT_SIZE;
    char *car = (char *)CAR_ARRAY_BASE;

    /* Push car world position */
    (*(int(*)())0x06026E2E)(*(int *)(car + off + CAR_X),
                            *(int *)(car + off + CAR_Y),
                            *(int *)(car + off + CAR_Z));
    /* Push car rotations: heading, pitch, roll */
    (*(int(*)())0x06026EDE)(*(int *)(car + off + CAR_HEADING));
    (*(int(*)())0x06026E94)(*(int *)(car + off + 0x1c));
    (*(int(*)())0x06026F2A)(*(int *)(car + off + 0x24));
  }
}

/* camera_path_interpolate -- Interpolate camera position/rotation along spline path.
 * Advances through path segments, lerps position and rotation vectors between
 * keyframes, computes view angles, and applies camera transform. */
void FUN_060055bc(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{
  char *cam_state;
  char *mtx_mult;
  char *lerp_fn;
  int t_factor;
  int temp;
  short *seg_start;
  short *seg_end;
  char *frame_ctr;
  int rot_x;
  int rot_y;
  int rot_z;
  int pos_x;
  int pos_y;
  int pos_z;
  int end_x;
  int end_y;
  int end_z;
  int start_x;
  int start_y;
  int start_z;
  frame_ctr = (char *)0x06063E08;
  cam_state = (char *)0x06063EEC;
  seg_start = *(short **)0x06063E04;
  seg_end = seg_start + 0x10;
  /* Advance to next segment if past endpoint */
  if ((int)*seg_end <= (int)(unsigned int)*(unsigned short *)0x06063E08) {
    if (*seg_end == -1) {
      seg_end = *(short **)(seg_start + 0x12);  /* loop pointer */
    }
    seg_start = seg_end;
    *(short **)0x06063E04 = seg_start;
    seg_end = seg_start + 0x10;
    if (*seg_start == 0) {
      *(short *)frame_ctr = 0;        /* reset frame counter */
    }
  }
  /* Compute interpolation factor t between segment start and end */
  temp = (int)*seg_start;
  t_factor = (*(int(*)())0x0602755C)(((unsigned int)*(unsigned short *)frame_ctr - temp) << 16,(*seg_end - temp) << 16,param_3
                     ,param_4,temp);
  /* Interpolate position vector (set 1) */
  FUN_0600553c(seg_start + 1,0);
  mtx_mult = (int *)0x06026FFC;
  (*(int(*)())0x06026FFC)(seg_start + 4,&start_x);
  FUN_0600553c(seg_end + 1,seg_start + 1);
  (*(int(*)())mtx_mult)(seg_end + 4,&end_x);
  lerp_fn = (char *)0x06027552;
  temp = start_x;
  pos_x = (*(int(*)())0x06027552)(end_x - start_x,t_factor);
  pos_x = pos_x + temp;
  temp = start_y;
  pos_y = (*(int(*)())lerp_fn)(end_y - start_y,t_factor);
  pos_y = pos_y + temp;
  temp = start_z;
  pos_z = (*(int(*)())lerp_fn)(end_z - start_z,t_factor);
  pos_z = pos_z + temp;
  /* Interpolate rotation vector (set 2) */
  FUN_0600553c((int)seg_start + 3,seg_end + 1);
  (*(int(*)())mtx_mult)(seg_start + 10,&start_x);
  FUN_0600553c((int)seg_end + 3,(int)seg_start + 3);
  (*(int(*)())mtx_mult)(seg_end + 10,&end_x);
  rot_x = (*(int(*)())lerp_fn)(end_x - start_x,t_factor);
  rot_x = rot_x + start_x;
  rot_y = (*(int(*)())lerp_fn)(end_y - start_y,t_factor);
  rot_y = rot_y + start_y;
  rot_z = (*(int(*)())lerp_fn)(end_z - start_z,t_factor);
  rot_z = rot_z + start_z;
  /* Advance frame and apply camera transform */
  *(short *)frame_ctr = *(short *)frame_ctr + 1;
  (*(int(*)())0x06026E0C)();          /* reset identity matrix */
  vec3_angle_calc(&pos_x,&rot_x,0x06063EEC);
  /* Compute Y offset based on game mode */
  if (*(int *)0x06078663 == '\0') {
    frame_ctr = (char *)(*(int *)(cam_state + 4) * -0x400 + 0xFFA00000);
  }
  else {
    frame_ctr = 0x01A00000 + *(int *)(cam_state + 4) << 10;
  }
  /* Apply view transform */
  (*(int(*)())0x0603850C)(4);
  (*(int(*)())0x0603853C)(frame_ctr,0x003A0000 + *(int *)cam_state * -0x200,0);
  (*(int(*)())0x06038520)();
  return;
}

void background_layer_init()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  short *puVar5;

  short *puVar6;

  short *puVar7;

  short *puVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  puVar3 = (char *)0x0606129C;

  puVar2 = (int *)0x06063750;

  puVar1 = (char *)0x06085FF4;

  iVar11 = 0x80;

  iVar10 = 0x480;

  (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + 0x20),0x80,

             *(int *)(0x06063750 + 0x24));

  if (*puVar1 != '\0') {

    iVar9 = 0x180;

    do {

      puVar5 = (short *)(*(int *)puVar3 + iVar9 + 0x18);

      puVar7 = (short *)(*(int *)puVar3 + iVar11 + 0x18);

      iVar4 = 0x15;

      do {

        iVar4 = iVar4 + -3;

        *puVar7 = *puVar5;

        puVar6 = puVar5 + 2;

        puVar7[1] = puVar5[1];

        puVar8 = puVar7 + 2;

        puVar5 = puVar5 + 3;

        puVar7 = puVar7 + 3;

        *puVar8 = *puVar6;

      } while (iVar4 != 0);

      iVar9 = iVar9 + 0x80;

      iVar11 = iVar11 + 0x80;

    } while (iVar9 < iVar10);

    (*(int(*)())0x060284AE)(8,0x318,0x60,0x0605ACDF);

  }

  if (*puVar1 == '\0') {

    iVar10 = 7;

  }

  else {

    iVar10 = 5;

  }

  if ((*(unsigned int *)0x0607EAB8 & 1) == 0) {

    (*(int(*)())0x06028400)(8,*(int *)(puVar2 + 0x28),((iVar10 << 6) + 0x19) << 1,

               *(int *)(puVar2 + 0x2c));

  }

  if (*(unsigned int *)0x06063F28 < 10) {

    (*(int(*)())0x06028430)(8,0x110,0,*(int *)0x06063F28);

  }

  else {

    (*(int(*)())0x06028430)(8,0x110,0xc,*(int *)0x06063F28);

  }

  if (DEMO_MODE_FLAG == 0) {

    (*(int(*)())0x06028430)(8,(int)DAT_0600590e,0x30,*(int *)0x0607EA98);

  }

  if (*(int *)0x06078644 == 0) {

    if (*puVar1 == '\0') {

      iVar10 = 6;

    }

    else {

      iVar10 = 4;

    }

    (*(int(*)())0x06028400)(8,*(int *)(puVar2 + 0x30),((iVar10 << 6) + 0x16) << 1,

               *(int *)(puVar2 + 0x34) + (int)DAT_06005910);

    return;

  }

  return;

}

/* intro_sequence_frame -- Single frame of intro/attract sequence.
 * Runs 4 subsystems: scene update, animation step, frame counter, render. */
void FUN_060058fa(void)
{
    FUN_06005c98();
    FUN_06005a22();
    animation_frame_counter();
    FUN_06005ae8();
}

void animation_frame_counter()
{

  int uVar1;

  int iVar2;

  int iVar3;

  char *puVar4;

  puVar4 = (char *)0x0607EAC0;

  iVar3 = (int)DAT_060059da;

  iVar2 = CAR_PTR_TARGET;

  if (((0 < *(int *)0x0607EAC0) &&

      (*(int *)0x0607EAC0 = *(int *)0x0607EAC0 + -1, *(int *)(iVar2 + DAT_060059dc) != 0

      )) && (*(int *)0x0607EBF4 == 0)) {

    if ((*(unsigned int *)puVar4 & 2) != 0) {

      puVar4 = *(char **)(iVar2 + DAT_060059de);

      if ((int)0x000927BF < (int)*(char **)(iVar2 + DAT_060059de)) {

        puVar4 = (char *)0x000927BF;

      }

      if (puVar4 == *(char **)(iVar2 + DAT_060059e0)) {

        (*(int(*)())0x06028400)(8,*(int *)0x06063810,iVar3,

                   *(int *)(0x06063810 + 4) + (int)DAT_060059e2,0x06063810);

      }

      else {

        (*(int(*)())0x06028400)(8,*(int *)0x06063818,iVar3,

                   *(int *)(0x06063818 + 4) + (int)DAT_060059e2,0x06063818);

      }

      uVar1 = FUN_06005dd4(puVar4);

      (*(int(*)())0x060284AE)(8,(int)DAT_060059e4,0x78,uVar1);

      return;

    }

    (*(int(*)())0x060283E0)(8,iVar3,(int)DAT_060059e6,0x0605ACE5);

    (*(int(*)())0x060284AE)(8,(int)DAT_060059e4,0x90,0x0605ACDD);

    return;

  }

  return;

}

/* hud_blink_sprite_render -- Render blinking HUD sprite with countdown timer.
 * Decrements countdown at 0x0607EABC each frame. On odd frames: draws
 * sprite from display list (index 0x21 or 0xB0 depending on mode flag
 * 0x06085FF4) using VDP1 draw command (0x06028400). Selects between
 * two priority values (DAT_06005abe/DAT_06005ac0) based on 0x0607EAC0.
 * On even frames: draws static attribute sprites at fixed position. */
void FUN_06005a22(void)
{
    int countdown;
    int sprite_idx;

    if (*(int *)0x0607EABC < 1) {
        return;
    }

    countdown = *(int *)0x0607EABC;
    *(unsigned int *)0x0607EABC = countdown - 1U;

    if ((countdown - 1U & 1) != 0) {
        /* Odd frame: draw from display list */
        if (*(int *)0x06085FF4 == '\0') {
            sprite_idx = 0x21;  /* normal mode sprite */
        } else {
            sprite_idx = 0xb0;  /* alternate mode sprite */
        }

        if (*(int *)0x0607EAC0 != 0) {
            (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + (sprite_idx << 3)),
                       (int)DAT_06005abe,
                       *(int *)((int)(0x06063750 + (sprite_idx << 3)) + 4) + (int)DAT_06005abc);
            return;
        }

        (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + (sprite_idx << 3)),
                   (int)DAT_06005ac0,
                   *(int *)((int)(0x06063750 + (sprite_idx << 3)) + 4) + (int)DAT_06005abc);
        return;
    }

    /* Even frame: static attribute sprites */
    (*(int(*)())0x060284AE)(8, (int)DAT_06005abe, 0x90, 0x0605ACDD);
    (*(int(*)())0x060284AE)(8, (int)DAT_06005ac0, 0x90, 0x0605ACDD);
}

/* hud_race_display_render -- Render race HUD: speed, position, lap count, and time/countdown.
 * Displays speed scaled by 0x9F1A factor, position rank (if not demo),
 * lap count, and a countdown timer with sound effects in final seconds. */
int FUN_06005ae8()
{
  short sprite_id;
  short lap_offset;
  char *race_flag;
  char *timer_ptr;
  char *countdown_period;
  char *countdown_value;
  char *vdp_render_num;
  int show_time;
  unsigned int speed;
  int car_ptr;
  vdp_render_num = (short *)0x06028430;
  countdown_value = (short *)0x06063E0C;
  countdown_period = (short *)0x06063E10;
  timer_ptr = (char *)0x0607EAAC;
  race_flag = (char *)0x06085FF4;
  car_ptr = CAR_PTR_TARGET;
  /* Goal indicator — show when past finish frame */
  if (*(int *)(car_ptr + DAT_06005b7c) + 1U <= *(unsigned int *)0x06063F28) {
    (*(int(*)())0x06028430)(8,0x108,0xc);
  }
  /* Speed display */
  sprite_id = DAT_06005b82;
  if (*race_flag != '\0') {
    sprite_id = DAT_06005b80;
  }
  if (*(int *)0x06078644 == 0) {
    speed = (unsigned int)(*(int *)(car_ptr + 8) * (int)0x00009F1A) >> 0x10;  /* km/h scale */
  }
  else {
    speed = *(unsigned int *)(car_ptr + 8);  /* mph raw */
  }
  (*(int(*)())vdp_render_num)(8,(int)sprite_id,0x24,speed);
  /* Position/rank display (hidden in demo mode) */
  if (DEMO_MODE_FLAG == 0) {
    (*(int(*)())vdp_render_num)(8,0x142,0x30,*(int *)(car_ptr + DAT_06005b84) + 1);
  }
  /* Lap count display */
  sprite_id = DAT_06005b8a;
  if (*race_flag != '\0') {
    sprite_id = DAT_06005b88;
  }
  lap_offset = DAT_06005c74;
  if (*(int *)0x0607EAB8 != 0) {
    lap_offset = PTR_DAT_06005b8c;
  }
  (*(int(*)())vdp_render_num)(8,(int)sprite_id,0x6c,*(short *)(car_ptr + lap_offset) + 1);
  /* Time/countdown display */
  car_ptr = (int)(char)*race_flag;
  if (car_ptr == 0) {
    show_time = 1;
    /* Countdown timer logic (final seconds warning) */
    if ((GAME_STATE_BIT & (unsigned int)0x00020000) != 0) {
      if (*(int *)timer_ptr == 0x78) {
        *(int *)countdown_value = (short *)0x3c;
        *(int *)countdown_period = 8;
      }
      if ((*(int *)timer_ptr < 0x78) &&
         (car_ptr = *(int *)countdown_period, *(int *)countdown_period = car_ptr + -1, car_ptr + -1 == 0)) {
        (*(int(*)())0x0601D5F4)(0,0xAE1114FF);  /* countdown beep */
        car_ptr = *(int *)countdown_value;
        *(int *)countdown_value = car_ptr + -3;
        if (car_ptr + -3 < 8) {
          *(int *)countdown_value = 8;
        }
        *(int *)countdown_period = (*(int *)countdown_value >> 3) + 1;
        show_time = 0;
      }
    }
    if (!show_time) {
      car_ptr = (*(int(*)())0x060284AE)(8,0xa6,0x60,0x0605ACF3);
      return car_ptr;
    }
    /* Normal time display */
    car_ptr = (*(int(*)())0x06034FE0)();
    if (DAT_06005c76 < car_ptr) {
      car_ptr = (int)DAT_06005c76;
    }
    car_ptr = (*(int(*)())vdp_render_num)(8,(int)PTR_DAT_06005c78,0x18,car_ptr);
  }
  return car_ptr;
}

/* hud_lap_times_render -- Render lap time history or current split time.
 * In split mode (0x0607EAC0==0x28), shows last 8 lap times with best highlighted.
 * Otherwise shows single estimated time entry. Times capped at 0x927BF. */
int FUN_06005c98()
{
  char *vdp_render_num;
  char *vdp_render_sprite;
  int result;
  int formatted_time;
  char *best_time;
  int car_ptr;
  unsigned int frame_count;
  int y_offset;
  int row;
  char *time_entry;
  char *max_time;
  unsigned int display_count;
  max_time = (char *)0x000927BF;             /* ~9:59.99 max displayable */
  vdp_render_sprite = (int *)0x060284AE;
  vdp_render_num = (char *)0x06028430;
  car_ptr = CAR_PTR_TARGET;
  frame_count = *(int *)0x06063F28 - 1;
  if (*(unsigned int *)(car_ptr + DAT_06005d3e) < frame_count) {
    frame_count = *(unsigned int *)(car_ptr + DAT_06005d3e);
  }
  if (*(int *)0x0607EAC0 == 0x28) {
    /* Split time mode — show last 8 lap times */
    result = 0x240;
    best_time = *(char **)(car_ptr + result);
    car_ptr = frame_count - 7;
    if (car_ptr < 0) {
      car_ptr = 0;
    }
    row = 0;
    for (; car_ptr <= (int)frame_count; car_ptr = car_ptr + 1) {
      time_entry = *(char **)(0x0607EBF8 + (car_ptr << 2));
      if ((int)max_time < (int)*(char **)(0x0607EBF8 + (car_ptr << 2))) {
        time_entry = max_time;
      }
      formatted_time = FUN_06005dd4(time_entry);
      if (time_entry == best_time) {
        y_offset = 0x54;              /* highlight best lap */
      }
      else {
        y_offset = 0x48;              /* normal lap */
      }
      result = (row + 5) << 6;
      (*(int(*)())vdp_render_sprite)(8,(result + 3) << 1,y_offset,formatted_time);
      result = (*(int(*)())vdp_render_num)(8,(result + 1) << 1,0x3c,car_ptr + 1);
      row = row + 1;
    }
  }
  else {
    /* Single entry mode — estimated time */
    result = (int)DAT_06005dcc;
    if (*(int *)(car_ptr + result) != *(int *)0x06063F28) {
      display_count = frame_count;
      if (6 < (int)frame_count) {
        display_count = 7;
      }
      max_time = (char *)(GAME_STATE_VAR * 5 - *(int *)(car_ptr + DAT_06005dce));
      if ((int)0x000927BF < (int)max_time) {
        max_time = (char *)0x000927BF;
      }
      formatted_time = FUN_06005dd4(max_time);
      car_ptr = (display_count + 5) << 6;
      (*(int(*)())vdp_render_sprite)(8,(car_ptr + 3) << 1,0x48,formatted_time);
      result = (*(int(*)())vdp_render_num)(8,(car_ptr + 1) << 1,0x3c,frame_count + 1);
    }
  }
  return result;
}

/* time_to_display_string -- Format time value as M:SS.HH tile string.
 * Uses SH-2 hardware division unit to extract digits.
 * Output buffer at 0x06063E14: [min_hi][min_lo][0xC=':'][sec_hi][sec_lo][0xD='.'][hund_hi][hund_lo][0]
 * Tile indices are 1-based (digit 0 = tile 1), 0xB = blank, 0xC/0xD = separators. */
char * FUN_06005dd4(param_1)
    int param_1;
{
  char *buf;
  int *quotient_reg;
  int remainder;
  unsigned int digit;
  char leading;
  int *dvsr;
  int *dvcr;
  unsigned int *remainder_reg;
  int *dvdnt;
  buf = (char *)0x06063E14;
  dvdnt = (int *)-252;               /* SH-2 DVDNT at 0xFFFFFF04 */
  dvcr = dvdnt + 1;                  /* SH-2 DVCR at 0xFFFFFF08 */
  dvsr = (int *)-256;                /* SH-2 DVSR at 0xFFFFFF00 */
  /* Hundredths ones digit: param_1 / 10 */
  *dvsr = 10;
  *dvcr = 0;
  *dvdnt = param_1;
  buf[8] = 0;                        /* null terminator */
  remainder_reg = (unsigned int *)-232;  /* remainder at 0xFFFFFF18 */
  digit = *remainder_reg;
  quotient_reg = (int *)-228;        /* quotient at 0xFFFFFF1C */
  remainder = *quotient_reg;
  /* Hundredths tens digit */
  *dvsr = 10;
  *dvcr = 0;
  *dvdnt = remainder;
  buf[7] = (char)digit + '\x01';
  digit = *remainder_reg;
  remainder = *quotient_reg;
  /* Seconds ones digit */
  *dvsr = 10;
  *dvcr = 0;
  *dvdnt = remainder;
  buf[6] = (char)digit + '\x01';
  digit = *remainder_reg;
  remainder = *quotient_reg;
  /* Seconds tens digit (mod 6 for 0-59 range) */
  *dvsr = 6;
  *dvcr = 0;
  *dvdnt = remainder;
  buf[5] = 0xd;                      /* '.' separator */
  buf[4] = (char)digit + '\x01';
  digit = *remainder_reg;
  remainder = *quotient_reg;
  /* Minutes ones digit */
  *dvsr = 10;
  *dvcr = 0;
  *dvdnt = remainder;
  buf[3] = (char)digit + '\x01';
  digit = *remainder_reg;
  remainder = *quotient_reg;
  /* Minutes tens digit */
  *dvsr = 10;
  *dvcr = 0;
  *dvdnt = remainder;
  buf[2] = 0xc;                      /* ':' separator */
  buf[1] = (char)digit + '\x01';
  /* Leading digit or blank */
  if ((*remainder_reg & 0xff) == 0) {
    leading = '\v';                   /* blank tile */
  }
  else {
    leading = (char)*remainder_reg + '\x01';
  }
  *buf = leading;
  return buf;
}

/* car_ground_contact_compute -- Compute car ground contact and tilt angles.
 * Transforms 8 reference points (4 wheels + 4 axles) through car rotation
 * matrix, translates to world space, looks up terrain height at each,
 * then computes roll (+0x1c) and pitch (+0x24) from height differences. */
void FUN_06005ecc()
{
  char *wheel_fl;   /* 0x06063E60 — front-left contact point */
  char *wheel_rl;   /* 0x06063E74 — rear-left */
  char *wheel_fr;   /* 0x06063E4C — front-right */
  char *wheel_rr;   /* 0x06063E88 — rear-right */
  int height_result;
  int avg_y;
  int front_avg;
  int rear_avg;
  int left_avg;
  int right_avg;
  char *axle_ptr;
  int car_ptr;
  char normal_buf[4];
  int center_y_avg;
  int center_y_right;
  int center_x;
  int center_y;
  int center_z;
  char *roll_divisor;
  wheel_fl = (char *)0x06063E60;
  wheel_rl = (char *)0x06063E74;
  wheel_fr = (int *)0x06063E4C;
  wheel_rr = (char *)0x06063E88;
  car_ptr = CAR_PTR_TARGET;
  front_avg = *(int *)(car_ptr + 0x10);     /* car X */
  avg_y = *(int *)(car_ptr + 0x14);         /* car Y */
  rear_avg = *(int *)(car_ptr + 0x18);      /* car Z */
  /* Build rotation matrix from car heading */
  (*(int(*)())0x06026DBC)();                /* reset matrix */
  (*(int(*)())0x06026E0C)();                /* push matrix */
  (*(int(*)())0x06026EDE)(*(int *)(car_ptr + 0x20) + *(int *)0x06063F10);  /* rotate Y */
  /* Transform 8 reference points from local to world space */
  (*(int(*)())0x06026FFC)(0x0604464C,wheel_fr);   /* front-right wheel */
  (*(int(*)())0x06026FFC)(0x06044640,wheel_fl);    /* front-left wheel */
  (*(int(*)())0x06026FFC)(0x06044658,wheel_rr);    /* rear-right wheel */
  (*(int(*)())0x06026FFC)(0x06044664,wheel_rl);    /* rear-left wheel */
  (*(int(*)())0x06026FFC)(0x06044688,0x06063E9C);  /* axle point A */
  (*(int(*)())0x06026FFC)(0x0604467C,0x06063EB0);  /* axle point B */
  (*(int(*)())0x06026FFC)(0x06044694,0x06063ED8);  /* axle point C */
  (*(int(*)())0x06026FFC)(0x060446A0,0x06063EC4);  /* axle point D */
  /* Translate all 4 wheel points to world coordinates */
  *(int *)wheel_fr = *(int *)wheel_fr + front_avg;
  *(int *)(wheel_fr + 4) = *(int *)(wheel_fr + 4) + avg_y;
  *(int *)(wheel_fr + 8) = *(int *)(wheel_fr + 8) + rear_avg;
  *(int *)wheel_fl = *(int *)wheel_fl + front_avg;
  *(int *)(wheel_fl + 4) = *(int *)(wheel_fl + 4) + avg_y;
  *(int *)(wheel_fl + 8) = *(int *)(wheel_fl + 8) + rear_avg;
  *(int *)wheel_rr = *(int *)wheel_rr + front_avg;
  *(int *)(wheel_rr + 4) = *(int *)(wheel_rr + 4) + avg_y;
  *(int *)(wheel_rr + 8) = *(int *)(wheel_rr + 8) + rear_avg;
  *(int *)wheel_rl = *(int *)wheel_rl + front_avg;
  *(int *)(wheel_rl + 4) = *(int *)(wheel_rl + 4) + avg_y;
  *(int *)(wheel_rl + 8) = *(int *)(wheel_rl + 8) + rear_avg;
  /* Translate axle points (X and Z only) */
  axle_ptr = (char *)0x06063E9C;
  *(int *)0x06063E9C = *(int *)0x06063E9C + front_avg;
  *(int *)(axle_ptr + 8) = *(int *)(axle_ptr + 8) + rear_avg;
  axle_ptr = (char *)0x06063EB0;
  *(int *)0x06063EB0 = *(int *)0x06063EB0 + front_avg;
  *(int *)(axle_ptr + 8) = *(int *)(axle_ptr + 8) + rear_avg;
  axle_ptr = (char *)0x06063ED8;
  *(int *)0x06063ED8 = *(int *)0x06063ED8 + front_avg;
  *(int *)(axle_ptr + 8) = *(int *)(axle_ptr + 8) + rear_avg;
  axle_ptr = (char *)0x06063EC4;
  *(int *)0x06063EC4 = *(int *)0x06063EC4 + front_avg;
  *(int *)(axle_ptr + 8) = *(int *)(axle_ptr + 8) + rear_avg;
  /* Look up terrain height at each wheel contact point */
  height_result = (*(int(*)())0x06006838)(*(int *)wheel_fr,*(int *)(wheel_fr + 8));
  (*(int(*)())0x06027EDE)(height_result,wheel_fr,wheel_fr + 0xe);
  height_result = (*(int(*)())0x06006838)(*(int *)wheel_fl,*(int *)(wheel_fl + 8));
  (*(int(*)())0x06027EDE)(height_result,wheel_fl,wheel_fl + 0xe);
  height_result = (*(int(*)())0x06006838)(*(int *)wheel_rr,*(int *)(wheel_rr + 8));
  (*(int(*)())0x06027EDE)(height_result,wheel_rr,wheel_rr + 0xe);
  height_result = (*(int(*)())0x06006838)(*(int *)wheel_rl,*(int *)(wheel_rl + 8));
  (*(int(*)())0x06027EDE)(height_result,wheel_rl,wheel_rl + 0xe);
  /* Average Y height from 4 wheels */
  avg_y = *(int *)(wheel_fl + 4) + *(int *)(wheel_fr + 4) + *(int *)(wheel_rr + 4) + *(int *)(wheel_rl + 4)
          >> 2;
  *(int *)(car_ptr + 0x14) = avg_y;          /* update car Y */
  /* Transform center reference point for tilt comparison */
  (*(int(*)())0x06026FFC)(0x060446AC,&center_x);
  center_x = center_x + front_avg;
  center_y = center_y + avg_y;
  center_z = center_z + rear_avg;
  height_result = (*(int(*)())0x06006838)(center_x,center_z);
  (*(int(*)())0x06027EDE)(height_result,&center_x,normal_buf);
  /* Determine roll angle from left-right height difference */
  if ((avg_y == center_y) ||
     ((avg_y = center_y, roll_divisor = 0x000D6666, CAR_COUNT == 1 &&
      ((int)PTR_DAT_06006118 <= *(int *)(car_ptr + DAT_06006116))))) {
    avg_y = (*(int(*)())0x06027552)(0x00008000,*(int *)(wheel_fr + 4) + *(int *)(wheel_fl + 4));
    roll_divisor = (char *)0x0002CCCC;
  }
  center_y_avg = (*(int(*)())0x06027552)(0x00008000,*(int *)(wheel_rl + 4) + *(int *)(wheel_rr + 4));
  front_avg = (*(int(*)())0x06027552)(0x00008000,*(int *)(wheel_rl + 4) + *(int *)(wheel_fr + 4));
  center_y_right = (*(int(*)())0x06027552)(0x00008000,*(int *)(wheel_rr + 4) + *(int *)(wheel_fl + 4));
  /* Compute roll angle (left-right height delta) */
  height_result = (*(int(*)())0x0602744C)(avg_y - center_y_avg,roll_divisor);
  *(int *)(car_ptr + 0x1c) = height_result;
  /* Compute pitch angle (front-rear height delta) */
  height_result = (*(int(*)())0x0602744C)(front_avg - center_y_right,0x00011998);
  *(int *)(car_ptr + 0x24) = height_result;
  OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;   /* pop matrix stack */
  return;
}
