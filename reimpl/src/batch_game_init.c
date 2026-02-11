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

void FUN_06004f14(param_1, param_2, param_3, param_4)
    short *param_1;
    unsigned int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  short *psVar6;

  puVar4 = (char *)0x06059F10;

  puVar3 = (char *)0x06059F18;

  puVar2 = (int *)0x06059F1C;

  puVar1 = (char *)0x06063750;

  if ((param_2 & 4) != 0) {

    uVar5 = (param_1[1] * *param_1 + 2) << 1;

    psVar6 = *(short **)0x06063D90;

    (*(int(*)())0x0602761E)(psVar6,param_1,uVar5);

    *(unsigned int *)0x06063D90 = *(int *)0x06063D90 + (unsigned int)uVar5;

    *(unsigned int *)0x06063D94 = *(int *)0x06063D94 + (unsigned int)uVar5;

    param_1 = psVar6;

  }

  if (param_3 == 0) {

    *(int *)(puVar1 + (*(int *)puVar4 << 3) + 4) =

         *(int *)(puVar1 + ((*(int *)puVar4 + -1) << 3) + 4);

  }

  else if ((param_2 & 3) == 0) {

    *(int *)(puVar1 + *(int *)((int)(int)puVar4 << 3) + 4) = *(int *)puVar3;

    if ((param_2 & 8) == 0) {

      (*(int(*)())0x0602761E)(0x25E00000 + *(int *)((int)(int)puVar3 << 5),param_3,param_4 << 5);

    }

    else {

      (*(int(*)())0x06028654)(param_3,0x25E00000 + *(int *)((int)(int)puVar3 << 5));

    }

    *(int *)puVar3 = *(int *)puVar3 + param_4;

  }

  else {

    *(int *)(puVar1 + *(int *)((int)(int)puVar4 << 3) + 4) = *(int *)puVar2;

    if ((param_2 & 8) == 0) {

      (*(int(*)())0x0602761E)(0x25E20000 + *(int *)((int)(int)puVar2 << 5),param_3,param_4 << 5);

    }

    else {

      (*(int(*)())0x06028654)(param_3,0x25E20000 + *(int *)((int)(int)puVar2 << 5));

    }

    *(int *)puVar2 = *(int *)puVar2 + param_4;

  }

  *(short **)(puVar1 + *(int *)((int)(int)puVar4 << 3)) = param_1;

  *(int *)puVar4 = *(int *)puVar4 + 1;

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

void FUN_060053ac(param_1, param_2, param_3)
    int *param_1;
    int *param_2;
    int param_3;
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

void FUN_060055bc(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  short *psVar6;

  short *psVar7;

  char *puVar8;

  int iStack_50;

  int iStack_4c;

  int iStack_48;

  int iStack_44;

  int iStack_40;

  int iStack_3c;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  puVar8 = (char *)0x06063E08;

  puVar1 = (char *)0x06063EEC;

  psVar6 = *(short **)0x06063E04;

  psVar7 = psVar6 + 0x10;

  if ((int)*psVar7 <= (int)(unsigned int)*(unsigned short *)0x06063E08) {

    if (*psVar7 == -1) {

      psVar7 = *(short **)(psVar6 + 0x12);

    }

    psVar6 = psVar7;

    *(short **)0x06063E04 = psVar6;

    psVar7 = psVar6 + 0x10;

    if (*psVar6 == 0) {

      *(short *)puVar8 = 0;

    }

  }

  iVar5 = (int)*psVar6;

  uVar4 = (*(int(*)())0x0602755C)(((unsigned int)*(unsigned short *)puVar8 - iVar5) << 16,(*psVar7 - iVar5) << 16,param_3

                     ,param_4,iVar5);

  FUN_0600553c(psVar6 + 1,0);

  puVar2 = (int *)0x06026FFC;

  (*(int(*)())0x06026FFC)(psVar6 + 4,&iStack_2c);

  FUN_0600553c(psVar7 + 1,psVar6 + 1);

  (*(int(*)())puVar2)(psVar7 + 4,&iStack_38);

  puVar3 = (char *)0x06027552;

  iVar5 = iStack_2c;

  iStack_44 = (*(int(*)())0x06027552)(iStack_38 - iStack_2c,uVar4);

  iStack_44 = iStack_44 + iVar5;

  iVar5 = iStack_28;

  iStack_40 = (*(int(*)())puVar3)(iStack_34 - iStack_28,uVar4);

  iStack_40 = iStack_40 + iVar5;

  iVar5 = iStack_24;

  iStack_3c = (*(int(*)())puVar3)(iStack_30 - iStack_24,uVar4);

  iStack_3c = iStack_3c + iVar5;

  FUN_0600553c((int)psVar6 + 3,psVar7 + 1);

  (*(int(*)())puVar2)(psVar6 + 10,&iStack_2c);

  FUN_0600553c((int)psVar7 + 3,(int)psVar6 + 3);

  (*(int(*)())puVar2)(psVar7 + 10,&iStack_38);

  iStack_50 = (*(int(*)())puVar3)(iStack_38 - iStack_2c,uVar4);

  iStack_50 = iStack_50 + iStack_2c;

  iStack_4c = (*(int(*)())puVar3)(iStack_34 - iStack_28,uVar4);

  iStack_4c = iStack_4c + iStack_28;

  iStack_48 = (*(int(*)())puVar3)(iStack_30 - iStack_24,uVar4);

  iStack_48 = iStack_48 + iStack_24;

  *(short *)puVar8 = *(short *)puVar8 + 1;

  (*(int(*)())0x06026E0C)();

  vec3_angle_calc(&iStack_44,&iStack_50,0x06063EEC);

  if (*(int *)0x06078663 == '\0') {

    puVar8 = (char *)(*(int *)(puVar1 + 4) * -0x400 + 0xFFA00000);

  }

  else {

    puVar8 = 0x01A00000 + *(int *)(puVar1 + 4) << 10;

  }

  (*(int(*)())0x0603850C)(4);

  (*(int(*)())0x0603853C)(puVar8,0x003A0000 + *(int *)puVar1 * -0x200,0);

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

void FUN_06005a22()
{

  int iVar1;

  if (*(int *)0x0607EABC < 1) {

    return;

  }

  iVar1 = *(int *)0x0607EABC;

  *(unsigned int *)0x0607EABC = iVar1 - 1U;

  if ((iVar1 - 1U & 1) != 0) {

    if (*(int *)0x06085FF4 == '\0') {

      iVar1 = 0x21;

    }

    else {

      iVar1 = 0xb0;

    }

    if (*(int *)0x0607EAC0 != 0) {

      (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + (iVar1 << 3)),(int)DAT_06005abe,

                 *(int *)((int)(0x06063750 + (iVar1 << 3)) + 4) + (int)DAT_06005abc);

      return;

    }

    (*(int(*)())0x06028400)(8,*(int *)(0x06063750 + (iVar1 << 3)),(int)DAT_06005ac0,

               *(int *)((int)(0x06063750 + (iVar1 << 3)) + 4) + (int)DAT_06005abc);

    return;

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_06005abe,0x90,0x0605ACDD);

  (*(int(*)())0x060284AE)(8,(int)DAT_06005ac0,0x90,0x0605ACDD);

  return;

}

int FUN_06005ae8()
{

  short sVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int bVar8;

  unsigned int uVar9;

  int iVar10;

  puVar7 = (short *)0x06028430;

  puVar6 = (short *)0x06063E0C;

  puVar5 = (short *)0x06063E10;

  puVar4 = (char *)0x0607EAAC;

  puVar3 = (char *)0x06085FF4;

  iVar10 = CAR_PTR_TARGET;

  if (*(int *)(iVar10 + DAT_06005b7c) + 1U <= *(unsigned int *)0x06063F28) {

    (*(int(*)())0x06028430)(8,0x108,0xc);

  }

  sVar1 = DAT_06005b82;

  if (*puVar3 != '\0') {

    sVar1 = DAT_06005b80;

  }

  if (*(int *)0x06078644 == 0) {

    uVar9 = (unsigned int)(*(int *)(iVar10 + 8) * (int)0x00009F1A) >> 0x10;

  }

  else {

    uVar9 = *(unsigned int *)(iVar10 + 8);

  }

  (*(int(*)())puVar7)(8,(int)sVar1,0x24,uVar9);

  if (DEMO_MODE_FLAG == 0) {

    (*(int(*)())puVar7)(8,0x142,0x30,*(int *)(iVar10 + DAT_06005b84) + 1);

  }

  sVar1 = DAT_06005b8a;

  if (*puVar3 != '\0') {

    sVar1 = DAT_06005b88;

  }

  sVar2 = DAT_06005c74;

  if (*(int *)0x0607EAB8 != 0) {

    sVar2 = PTR_DAT_06005b8c;

  }

  (*(int(*)())puVar7)(8,(int)sVar1,0x6c,*(short *)(iVar10 + sVar2) + 1);

  iVar10 = (int)(char)*puVar3;

  if (iVar10 == 0) {

    bVar8 = 1;

    if ((GAME_STATE_BIT & (unsigned int)0x00020000) != 0) {

      if (*(int *)puVar4 == 0x78) {

        *(int *)puVar6 = (short *)0x3c;

        *(int *)puVar5 = 8;

      }

      if ((*(int *)puVar4 < 0x78) &&

         (iVar10 = *(int *)puVar5, *(int *)puVar5 = iVar10 + -1, iVar10 + -1 == 0)) {

        (*(int(*)())0x0601D5F4)(0,0xAE1114FF);

        iVar10 = *(int *)puVar6;

        *(int *)puVar6 = iVar10 + -3;

        if (iVar10 + -3 < 8) {

          *(int *)puVar6 = 8;

        }

        *(int *)puVar5 = (*(int *)puVar6 >> 3) + 1;

        bVar8 = 0;

      }

    }

    if (!bVar8) {

      iVar10 = (*(int(*)())0x060284AE)(8,0xa6,0x60,0x0605ACF3);

      return iVar10;

    }

    iVar10 = (*(int(*)())0x06034FE0)();

    if (DAT_06005c76 < iVar10) {

      iVar10 = (int)DAT_06005c76;

    }

    iVar10 = (*(int(*)())puVar7)(8,(int)PTR_DAT_06005c78,0x18,iVar10);

  }

  return iVar10;

}

int FUN_06005c98()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  char *puVar5;

  int iVar6;

  unsigned int uVar7;

  int uVar8;

  int iVar9;

  char *puVar10;

  char *puVar11;

  unsigned int local_28;

  puVar11 = (char *)0x000927BF;

  puVar2 = (int *)0x060284AE;

  puVar1 = (char *)0x06028430;

  iVar6 = CAR_PTR_TARGET;

  uVar7 = *(int *)0x06063F28 - 1;

  if (*(unsigned int *)(iVar6 + DAT_06005d3e) < uVar7) {

    uVar7 = *(unsigned int *)(iVar6 + DAT_06005d3e);

  }

  if (*(int *)0x0607EAC0 == 0x28) {

    iVar3 = 0x240;

    puVar5 = *(char **)(iVar6 + iVar3);

    iVar6 = uVar7 - 7;

    if (iVar6 < 0) {

      iVar6 = 0;

    }

    iVar9 = 0;

    for (; iVar6 <= (int)uVar7; iVar6 = iVar6 + 1) {

      puVar10 = *(char **)(0x0607EBF8 + (iVar6 << 2));

      if ((int)puVar11 < (int)*(char **)(0x0607EBF8 + (iVar6 << 2))) {

        puVar10 = puVar11;

      }

      uVar4 = FUN_06005dd4(puVar10);

      if (puVar10 == puVar5) {

        uVar8 = 0x54;

      }

      else {

        uVar8 = 0x48;

      }

      iVar3 = (iVar9 + 5) << 6;

      (*(int(*)())puVar2)(8,(iVar3 + 3) << 1,uVar8,uVar4);

      iVar3 = (*(int(*)())puVar1)(8,(iVar3 + 1) << 1,0x3c,iVar6 + 1);

      iVar9 = iVar9 + 1;

    }

  }

  else {

    iVar3 = (int)DAT_06005dcc;

    if (*(int *)(iVar6 + iVar3) != *(int *)0x06063F28) {

      local_28 = uVar7;

      if (6 < (int)uVar7) {

        local_28 = 7;

      }

      puVar11 = (char *)(GAME_STATE_VAR * 5 - *(int *)(iVar6 + DAT_06005dce));

      if ((int)0x000927BF < (int)puVar11) {

        puVar11 = (char *)0x000927BF;

      }

      uVar4 = FUN_06005dd4(puVar11);

      iVar6 = (local_28 + 5) << 6;

      (*(int(*)())puVar2)(8,(iVar6 + 3) << 1,0x48,uVar4);

      iVar3 = (*(int(*)())puVar1)(8,(iVar6 + 1) << 1,0x3c,uVar7 + 1);

    }

  }

  return iVar3;

}

char * FUN_06005dd4(param_1)
    int param_1;
{

  char *puVar1;

  int *puVar2;

  int uVar3;

  unsigned int uVar4;

  char cVar5;

  int *puVar6;

  int *puVar7;

  unsigned int *puVar8;

  int *puVar9;

  puVar1 = (char *)0x06063E14;

  puVar9 = (int *)-252;

  puVar7 = puVar9 + 1;

  puVar6 = (int *)-256;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = param_1;

  puVar1[8] = 0;

  puVar8 = (unsigned int *)-232;

  uVar4 = *puVar8;

  puVar2 = (int *)-228;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[7] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[6] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 6;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[5] = 0xd;

  puVar1[4] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[3] = (char)uVar4 + '\x01';

  uVar4 = *puVar8;

  uVar3 = *puVar2;

  *puVar6 = 10;

  *puVar7 = 0;

  *puVar9 = uVar3;

  puVar1[2] = 0xc;

  puVar1[1] = (char)uVar4 + '\x01';

  if ((*puVar8 & 0xff) == 0) {

    cVar5 = '\v';

  }

  else {

    cVar5 = (char)*puVar8 + '\x01';

  }

  *puVar1 = cVar5;

  return puVar1;

}

void FUN_06005ecc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *puVar9;

  int iVar10;

  char auStack_38 [4];

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  puVar4 = (char *)0x06063E60;

  puVar3 = (char *)0x06063E74;

  puVar2 = (int *)0x06063E4C;

  puVar1 = (char *)0x06063E88;

  iVar10 = CAR_PTR_TARGET;

  iVar8 = *(int *)(iVar10 + 0x10);

  iVar6 = *(int *)(iVar10 + 0x14);

  iVar7 = *(int *)(iVar10 + 0x18);

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E0C)();

  (*(int(*)())0x06026EDE)(*(int *)(iVar10 + 0x20) + *(int *)0x06063F10);

  (*(int(*)())0x06026FFC)(0x0604464C,puVar2);

  (*(int(*)())0x06026FFC)(0x06044640,puVar4);

  (*(int(*)())0x06026FFC)(0x06044658,puVar1);

  (*(int(*)())0x06026FFC)(0x06044664,puVar3);

  (*(int(*)())0x06026FFC)(0x06044688,0x06063E9C);

  (*(int(*)())0x06026FFC)(0x0604467C,0x06063EB0);

  (*(int(*)())0x06026FFC)(0x06044694,0x06063ED8);

  (*(int(*)())0x06026FFC)(0x060446A0,0x06063EC4);

  *(int *)puVar2 = *(int *)puVar2 + iVar8;

  *(int *)(puVar2 + 4) = *(int *)(puVar2 + 4) + iVar6;

  *(int *)(puVar2 + 8) = *(int *)(puVar2 + 8) + iVar7;

  *(int *)puVar4 = *(int *)puVar4 + iVar8;

  *(int *)(puVar4 + 4) = *(int *)(puVar4 + 4) + iVar6;

  *(int *)(puVar4 + 8) = *(int *)(puVar4 + 8) + iVar7;

  *(int *)puVar1 = *(int *)puVar1 + iVar8;

  *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + iVar6;

  *(int *)(puVar1 + 8) = *(int *)(puVar1 + 8) + iVar7;

  *(int *)puVar3 = *(int *)puVar3 + iVar8;

  *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + iVar6;

  *(int *)(puVar3 + 8) = *(int *)(puVar3 + 8) + iVar7;

  puVar9 = (char *)0x06063E9C;

  *(int *)0x06063E9C = *(int *)0x06063E9C + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  puVar9 = (char *)0x06063EB0;

  *(int *)0x06063EB0 = *(int *)0x06063EB0 + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  puVar9 = (char *)0x06063ED8;

  *(int *)0x06063ED8 = *(int *)0x06063ED8 + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  puVar9 = (char *)0x06063EC4;

  *(int *)0x06063EC4 = *(int *)0x06063EC4 + iVar8;

  *(int *)(puVar9 + 8) = *(int *)(puVar9 + 8) + iVar7;

  uVar5 = (*(int(*)())0x06006838)(*(int *)puVar2,*(int *)(puVar2 + 8));

  (*(int(*)())0x06027EDE)(uVar5,puVar2,puVar2 + 0xe);

  uVar5 = (*(int(*)())0x06006838)(*(int *)puVar4,*(int *)(puVar4 + 8));

  (*(int(*)())0x06027EDE)(uVar5,puVar4,puVar4 + 0xe);

  uVar5 = (*(int(*)())0x06006838)(*(int *)puVar1,*(int *)(puVar1 + 8));

  (*(int(*)())0x06027EDE)(uVar5,puVar1,puVar1 + 0xe);

  uVar5 = (*(int(*)())0x06006838)(*(int *)puVar3,*(int *)(puVar3 + 8));

  (*(int(*)())0x06027EDE)(uVar5,puVar3,puVar3 + 0xe);

  iVar6 = *(int *)(puVar4 + 4) + *(int *)(puVar2 + 4) + *(int *)(puVar1 + 4) + *(int *)(puVar3 + 4)

          >> 2;

  *(int *)(iVar10 + 0x14) = iVar6;

  (*(int(*)())0x06026FFC)(0x060446AC,&iStack_2c);

  iStack_2c = iStack_2c + iVar8;

  iStack_28 = iStack_28 + iVar6;

  iStack_24 = iStack_24 + iVar7;

  uVar5 = (*(int(*)())0x06006838)(iStack_2c,iStack_24);

  (*(int(*)())0x06027EDE)(uVar5,&iStack_2c,auStack_38);

  if ((iVar6 == iStack_28) ||

     ((iVar6 = iStack_28, puVar9 = 0x000D6666, CAR_COUNT == 1 &&

      ((int)PTR_DAT_06006118 <= *(int *)(iVar10 + DAT_06006116))))) {

    iVar6 = (*(int(*)())0x06027552)(0x00008000,*(int *)(puVar2 + 4) + *(int *)(puVar4 + 4));

    puVar9 = (char *)0x0002CCCC;

  }

  iStack_34 = (*(int(*)())0x06027552)(0x00008000,*(int *)(puVar3 + 4) + *(int *)(puVar1 + 4));

  iVar7 = (*(int(*)())0x06027552)(0x00008000,*(int *)(puVar3 + 4) + *(int *)(puVar2 + 4));

  iStack_30 = (*(int(*)())0x06027552)(0x00008000,*(int *)(puVar1 + 4) + *(int *)(puVar4 + 4));

  uVar5 = (*(int(*)())0x0602744C)(iVar6 - iStack_34,puVar9);

  *(int *)(iVar10 + 0x1c) = uVar5;

  uVar5 = (*(int(*)())0x0602744C)(iVar7 - iStack_30,0x00011998);

  *(int *)(iVar10 + 0x24) = uVar5;

  OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;

  return;

}
