#include "game.h"

extern int DAT_0600635e;
extern int DAT_06006360;
extern int DAT_06006362;
extern int DAT_06006662;
extern int DAT_06006666;
extern int DAT_06006668;
extern int DAT_0600666a;
extern int DAT_06006752;
extern int DAT_06006754;
extern int DAT_06006756;
extern int DAT_06006758;
extern int DAT_0600675a;
extern int DAT_06006802;
extern int DAT_06006c1e;
extern int DAT_06006cca;
extern int DAT_06006da6;
extern int DAT_06006da8;
extern int DAT_06006daa;
extern int DAT_06007412;
extern int DAT_06007414;
extern int DAT_06007416;
extern int DAT_06007418;
extern int DAT_0600741a;
extern int DAT_060076e2;
extern int DAT_0600777e;
extern int DAT_060078ca;
extern int DAT_060079ce;
extern int DAT_06007a92;
extern int DAT_06007a94;
extern int DAT_06007a96;
extern int FUN_060067c8();
extern void FUN_06007a50();
extern void FUN_06007bcc();
extern int PTR_DAT_0600644c;
extern int PTR_DAT_0600654c;
extern int PTR_DAT_06006c20;
extern int PTR_DAT_06006dac;
extern int PTR_DAT_0600741c;
extern int PTR_DAT_060079d0;
extern short DAT_06006804;

/* car_to_object_transfer -- Copy car world position into 4 render buffers.
 * Resets matrix (0x06026DBC), loads identity (0x06026E0C), rotates by heading3,
 * then transforms 4 object positions from template tables (0x06044640-0x06044664)
 * into render buffers (0x06063E9C-0x06063EC4). Adds car X/Z offsets, sets Y.
 * Decrements OBJ_STATE_PRIMARY by 0x30 (one render slot consumed). */
void FUN_060061c8(void)
{
    register int base asm("r11") = CAR_PTR_CURRENT;
    register int car_x asm("r14") = *(int *)(base + CAR_X);
    register int car_y asm("r13") = *(int *)(base + CAR_Y);
    register int car_z asm("r12") = *(int *)(base + CAR_Z);

    (*(int(*)())0x06026DBC)();                     /* matrix reset */
    (*(int(*)())0x06026E0C)();                     /* load identity */
    (*(int(*)())0x06026EDE)(*(int *)(base + CAR_HEADING3));  /* rotate by heading */

    /* Transform 4 object templates into render buffers */
    void (*xform)(int, int) = (void (*)(int, int))0x06026FFC;
    xform(0x0604464C, 0x06063E9C);
    xform(0x06044640, 0x06063EB0);
    xform(0x06044658, 0x06063ED8);
    xform(0x06044664, 0x06063EC4);

    /* Add car world position to each buffer */
    int *p;
    p = (int *)0x06063E9C;  p[0] += car_x;  p[1] = car_y;  p[2] += car_z;
    p = (int *)0x06063EB0;  p[0] += car_x;  p[1] = car_y;  p[2] += car_z;
    p = (int *)0x06063ED8;  p[0] += car_x;  p[1] = car_y;  p[2] += car_z;
    p = (int *)0x06063EC4;  p[0] += car_x;  p[1] = car_y;  p[2] += car_z;

    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;
}

void FUN_0600629c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  puVar4 = (char *)0x0607E940;

  puVar3 = (char *)0x0607E944;

  puVar2 = (char *)0x0600E1D4;

  puVar1 = (char *)0x06078900;

  iVar7 = 0x268;

  *(short *)0x0605DF4E = 0;

  *(short *)0x0605DF50 = 0;

  *(short *)0x0605DF52 = 0;

  *(short *)0x0605DF54 = 0;

  if (*(int *)0x06078635 == '\0') {

    for (iVar6 = 0; iVar6 < *(int *)0x0607EA98; iVar6 = iVar6 + 1) {

      *(char **)puVar4 = puVar1 + iVar6 * iVar7;

      *(int *)(puVar1 + iVar6 * iVar7 + 4) = iVar6;

      (*(int(*)())puVar2)();

    }

  }

  else {

    *(char **)puVar4 = puVar1 + iVar7;

    *(char **)puVar3 = puVar1 + iVar7;

    *(int *)(*(int *)puVar4 + 4) = 0;

    (*(int(*)())puVar2)();

    *(int *)(*(int *)puVar3 + 0x74) = 0x38;

    *(int *)(*(int *)puVar3 + 0x90) = 0x38;

    puVar5 = (char *)0x0607ED90;

    *(unsigned short *)(*(int *)puVar3 + 0x9e) = (unsigned short)(unsigned char)*(int *)0x0607ED90;

    *(unsigned short *)(*(int *)puVar3 + 0x7c) = (unsigned short)(unsigned char)puVar5[1];

    *(unsigned short *)(*(int *)puVar3 + (int)DAT_06006360) = (unsigned short)(unsigned char)puVar5[2];

    if (CAR_COUNT == 0) {

      iVar7 = (int)DAT_06006362;

      *(short *)(*(int *)puVar4 + iVar7) = 3;

      *(short *)(*(int *)puVar4 + iVar7 + 2) = 3;

    }

    else {

      iVar7 = (int)DAT_06006362;

      *(short *)(*(int *)puVar4 + iVar7) = 0;

      *(short *)(*(int *)puVar4 + iVar7 + 2) = 0;

    }

    *(char **)puVar4 = puVar1;

    *(char **)puVar3 = puVar1;

    *(int *)(*(int *)puVar4 + 4) = 0;

    (*(int(*)())puVar2)();

  }

  *(int *)(*(int *)puVar3 + 0x74) = 0x38;

  *(int *)(*(int *)puVar3 + 0x90) = 0x38;

  *(short *)(*(int *)puVar3 + 0x9c) = (short)*(int *)0x0607EAB8;

  *(short *)(*(int *)puVar3 + 0x9e) = *(short *)0x06063F42;

  *(short *)(*(int *)puVar3 + 0x7c) = (short)*(int *)0x06078868;

  (*(int(*)())0x0600D280)();

  (*(int(*)())0x0602E5E4)();

  if ((GAME_STATE_COPY == 0xe) && (CAR_COUNT == 0)) {

    *(int *)0x0607EAD0 = 1;

  }

  else {

    *(int *)0x0607EAD0 = 0;

  }

  puVar1 = (char *)0x06063EF0;

  iVar7 = *(int *)puVar3;

  *(int *)0x06063EF0 = *(int *)(iVar7 + 0x20);

  *(int *)(puVar1 + 4) = 0;

  *(int *)0x06063F10 = 0;

  puVar1 = (char *)0x06063E78;

  *(int *)0x06063E78 = 0;

  puVar2 = (char *)0x06063E8C;

  *(int *)0x06063E8C = *(int *)puVar1;

  puVar1 = (char *)0x06063E64;

  *(int *)0x06063E64 = *(int *)puVar2;

  *(int *)0x06063E50 = *(int *)puVar1;

  *(int *)0x06063F14 = 0xFEA00000;

  if (CAR_COUNT == 0) {

    iVar6 = (int)PTR_DAT_0600654c;

    *(short *)(iVar7 + iVar6) = 3;

    *(short *)(iVar7 + iVar6 + 2) = 3;

  }

  else {

    iVar6 = (int)PTR_DAT_0600644c;

    *(short *)(iVar7 + iVar6) = 0;

    *(short *)(iVar7 + iVar6 + 2) = 0;

  }

  *(int *)0x060620D0 = 0;

  *(int *)0x06063E1C = 2;

  *(int *)0x06059F30 = 1;

  (*(int(*)())0x06038BD4)(8,0);

  *(char **)0x06063E24 = 0x00058000;

  puVar1 = (char *)0x0000F300;

  *(char **)0x06063E34 = 0x0000F300;

  *(char **)0x06063E28 = 0x006E0000;

  *(char **)0x06063E2C = 0x00100000;

  *(int *)0x06063E30 = 0;

  *(char **)0x06063EEC = puVar1;

  *(int *)0x06063E20 = 2;

  FUN_060067c8();

  return;

}

int FUN_060064f2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  int uVar11;

  int iVar12;

  puVar4 = (char *)0x06063F4C;

  puVar3 = (char *)0x00008000;

  puVar2 = (char *)0x06063E24;

  puVar1 = (char *)0x06063E1C;

  *(int *)0x06063F4C = *(int *)(0x060446B8 + *(int *)(0x06063E20 << 2))

  ;

  if (((int)puVar3 < *(int *)puVar2) || (*(int *)0x06078654 == '\x04')) {

    (*(int(*)())0x06038BD4)(8,0);

  }

  else {

    (*(int(*)())0x06038BD4)(8,5);

  }

  puVar10 = (char *)0x06063E34;

  puVar9 = (char *)0x06063E28;

  puVar8 = (char *)0x06063E2C;

  puVar7 = (char *)0x06063E30;

  puVar6 = (char *)0x00010000;

  puVar5 = (char *)0x00058000;

  if (*(int *)puVar2 == *(int *)puVar4) {

    *(int *)puVar1 = *(int *)0x06063E20;

  }

  else if (*(int *)puVar4 < *(int *)puVar2) {

    if ((int)0x00078000 < *(int *)puVar2) {

      *(int *)puVar1 = 4;

      *(int *)puVar2 = *(int *)puVar2 - (int)puVar6;

      *(int *)puVar10 = *(int *)puVar10 - -576;

      *(int *)puVar9 = *(int *)puVar9 - (int)0x0003C000;

    }

    else if ((int)0x00058000 < *(int *)puVar2) {

      *(int *)puVar1 = 3;

      *(int *)puVar2 = *(int *)puVar2 - (int)0x4000E000;

      *(int *)puVar10 = *(int *)puVar10 + 0x80;

      *(int *)puVar9 = *(int *)puVar9 - (int)0x0001C000;

    }

    else if ((int)puVar3 < *(int *)puVar2) {

      *(int *)puVar1 = 2;

      *(int *)puVar2 = *(int *)puVar2 - (int)0x0000A000;

      *(int *)puVar10 = *(int *)puVar10 + 0x40;

      *(int *)puVar9 = *(int *)puVar9 - (int)puVar6;

      *(int *)puVar7 = *(int *)puVar7 - (int)DAT_06006666;

    }

    else if (*(int *)puVar2 < 1) {

      *(int *)puVar1 = 0;

    }

    else {

      *(int *)puVar1 = 1;

      *(int *)puVar2 = *(int *)puVar2 - (int)DAT_06006668;

      *(int *)puVar10 = *(int *)puVar10 - -352;

      *(int *)puVar9 = *(int *)puVar9 - (int)puVar5;

      *(int *)puVar8 = *(int *)puVar8 - (int)0x000D0000;

      if (*(int *)0x06083255 != '\0') {

        *(int *)puVar8 = *(int *)puVar8 - (int)0x000A0000;

      }

    }

  }

  else if (*(int *)puVar2 < *(int *)puVar4) {

    if (*(int *)puVar2 < (int)puVar3) {

      *(int *)puVar1 = 0;

      *(int *)puVar2 = *(int *)puVar2 + (int)DAT_06006752;

      *(int *)puVar10 = *(int *)puVar10 + -352;

      *(char **)puVar9 = puVar5 + *(int *)puVar9;

      *(char **)puVar8 = 0x000D0000 + *(int *)puVar8;

      if (*(int *)0x06083255 != '\0') {

        *(char **)puVar8 = 0x000A0000 + *(int *)puVar8;

      }

    }

    else if (*(int *)puVar2 < (int)0x00058000) {

      *(int *)puVar1 = 1;

      *(char **)puVar2 = 0x0000A000 + *(int *)puVar2;

      *(int *)puVar10 = *(int *)puVar10 + -0x40;

      *(char **)puVar9 = puVar6 + *(int *)puVar9;

      *(int *)puVar7 = *(int *)puVar7 + (int)DAT_06006756;

    }

    else if (*(int *)puVar2 < (int)0x00078000) {

      *(int *)puVar1 = 2;

      *(int *)puVar2 = *(int *)puVar2 + (int)DAT_06006758;

      *(int *)puVar10 = *(int *)puVar10 + -0x80;

      *(char **)puVar9 = 0x0001C000 + *(int *)puVar9;

    }

    else if (*(int *)puVar2 < (int)0x00178000) {

      *(int *)puVar1 = 3;

      *(char **)puVar2 = puVar6 + *(int *)puVar2;

      *(int *)puVar10 = *(int *)puVar10 + -576;

      *(char **)puVar9 = 0x0003C000 + *(int *)puVar9;

    }

    else {

      *(int *)puVar1 = 4;

    }

  }

  uVar11 = (*(int(*)())0x06027552)(*(int *)puVar2,(int)DAT_06006802);

  *(int *)0x06063F04 = uVar11;

  iVar12 = (*(int(*)())0x06027552)(*(int *)puVar2,(int)DAT_06006802);

  *(int *)0x06063F08 = iVar12;

  if ((*(int *)puVar1 == 0) ||

     ((iVar12 = *(int *)puVar1, iVar12 == 1 && (*(unsigned int *)0x06063E20 < 2)))) {

    *(int *)0x06059F30 = 0;

  }

  else {

    *(int *)0x06059F30 = 1;

  }

  return iVar12;

}

/* sound_bank_and_stereo_setup -- Initialize sound bank and stereo panning.
 * Gets sound bank index via get_sound_bank_index, applies to mixer.
 * Then sets stereo panning for L/R channels at 0x06063F48/4A based
 * on player index at 0x06078663 (0=normal, else=swapped). */
int FUN_060067c8(void)
{
    short bank;
    char player_idx;
    short pan_val;

    bank = (*(int(*)())0x0601A5F8)();  /* get_sound_bank_index */
    (*(int(*)())0x06026590)((int)(char)*(char *)0x0605D240, bank);

    pan_val = DAT_06006804;
    player_idx = *(char *)0x06078663;

    if (player_idx == 0) {
        *(short *)0x06063F48 = pan_val;
        *(short *)0x06063F4A = (short)0x8000;
    } else {
        *(short *)0x06063F48 = (short)0x8000;
        *(short *)0x06063F4A = pan_val;
    }

    return (int)player_idx;
}

/* world_to_tile_index -- Convert world X,Z coords to flat tile grid index.
 * World range: X [-0x04000000..+0x03FFFFFF], Z [0..0x03FFFFFF]
 * Grid: 64 columns. >>21 divides 64M range into 32 steps per axis.
 * Returns: row * 64 + column */
int FUN_06006838(int world_x, int world_z)
{
    unsigned int row = (unsigned int)(0x03FFFFFF - world_z) >> 21;
    unsigned int col = (unsigned int)(0x04000000 + world_x) >> 21;
    return (row << 6) + col;
}

unsigned int FUN_06006868()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  int uVar8;

  int iVar9;

  unsigned int uVar10;

  int iVar11;

  unsigned int uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int local_4c;

  int iStack_40;

  int iStack_28;

  int iStack_24;

  puVar2 = (char *)0x0607EAD8;

  *(int *)0x06063F54 = *(int *)(CAR_PTR_TARGET + 0x14);

  puVar3 = (char *)0x06089E96;

  uVar8 = *(int *)(0x06062248 + *(int *)((int)(int)puVar2 << 3));

  uVar5 = *(int *)(0x06062248 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2);

  iVar4 = *(int *)(0x06062260 + *(int *)((int)(int)puVar2 << 4));

  iVar11 = *(int *)((int)(int)puVar2 << 2);

  iVar9 = *(int *)(0x06062260 + (iVar11 + 1) << 2);

  iVar6 = *(int *)(0x06062260 + (iVar11 + 2) << 2);

  iVar11 = *(int *)(0x06062260 + (iVar11 + 3) << 2);

  uVar10 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar12 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar7 = (uVar12 << 6) + uVar10;

  iStack_28 = 0x40;

  iStack_24 = -1;

  iStack_40 = 1;

  local_4c = -0x40;

  if (uVar12 == 0x3f) {

    iStack_28 = 0;

  }

  else if (uVar12 == 0) {

    local_4c = 0;

  }

  if (uVar10 == 0x3f) {

    iStack_40 = 0;

  }

  else if (uVar10 == 0) {

    iStack_24 = 0;

  }

  for (; local_4c <= iStack_28; local_4c = local_4c + 0x40) {

    iVar14 = local_4c + iStack_24 + iVar7;

    for (iVar15 = iStack_24; iVar15 <= iStack_40; iVar15 = iVar15 + 1) {

      sVar1 = *(short *)((iVar14 << 1) + iVar6);

      if (0 < *(short *)(iVar4 + (iVar14 << 1))) {

        iVar13 = *(int *)(0x06062230 + *(int *)((int)(int)puVar2 << 3)) + *(int *)(iVar9 + (iVar14 << 2));

        if (*(int *)puVar2 == 2) {

          uVar10 = (*(int(*)())0x0602B328)(iVar13,uVar8,(int)*(short *)puVar3);

        }

        else {

          uVar10 = (*(int(*)())0x06029BF4)(iVar13,uVar8,(int)*(short *)puVar3);

        }

      }

      if (0 < sVar1) {

        iVar13 = *(int *)(0x06062230 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2) +

                 *(int *)(iVar11 + (iVar14 << 2));

        if (*(int *)puVar2 == 2) {

          uVar10 = (*(int(*)())0x0602AF3C)(iVar13,uVar5,(int)*(short *)puVar3,(int)sVar1);

        }

        else {

          uVar10 = (*(int(*)())0x0602A834)(iVar13,uVar5,(int)*(short *)puVar3,(int)sVar1);

        }

      }

      iVar14 = iVar14 + 1;

    }

  }

  if ((GAME_STATE_BIT & 0x30000000) == 0) {

    iVar4 = *(int *)puVar2;

    if (iVar4 == 0) {

      (*(int(*)())0x06017814)();

    }

    else if (iVar4 == 1) {

      (*(int(*)())0x06017CEC)();

    }

    else if (iVar4 == 2) {

      (*(int(*)())0x06018166)();

    }

    uVar10 = (*(int(*)())0x06022140)();

    return uVar10;

  }

  return uVar10;

}

int FUN_06006a9c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  int uVar9;

  int iVar10;

  unsigned int uVar11;

  int iVar12;

  unsigned int uVar13;

  int iVar14;

  short sVar15;

  int iVar16;

  short sVar17;

  int iStack_40;

  int iStack_28;

  int iStack_24;

  puVar3 = (char *)0x0607EAD8;

  puVar2 = (char *)0x06089E44;

  puVar1 = (char *)0x060620D4;

  uVar9 = *(int *)(0x06062248 + *(int *)(0x0607EAD8 << 3));

  uVar6 = *(int *)(0x06062248 + (*(int *)(0x0607EAD8 << 1) + 1) << 2);

  iVar4 = *(int *)(0x06062260 + *(int *)(0x0607EAD8 << 4));

  iVar12 = *(int *)(0x0607EAD8 << 2);

  iVar10 = *(int *)(0x06062260 + (iVar12 + 1) << 2);

  iVar7 = *(int *)(0x06062260 + (iVar12 + 2) << 2);

  iVar12 = (iVar12 + 3) << 2;

  iVar5 = *(int *)(0x06062260 + iVar12);

  uVar11 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar13 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar14 = -2;

  iStack_24 = -2;

  iStack_40 = 2;

  iStack_28 = 2;

  if (uVar13 < 0x3e) {

    if (uVar13 < 2) {

      iVar14 = -uVar13;

    }

  }

  else {

    iStack_40 = 0x3f - uVar13;

  }

  if (uVar11 < 0x3e) {

    if (uVar11 < 2) {

      iStack_24 = -uVar11;

    }

  }

  else {

    iStack_28 = 0x3f - uVar11;

  }

  for (iVar14 = iVar14 << 6; iVar16 = iStack_24, iVar14 < iStack_40 << 6; iVar14 = iVar14 + 0x40) {

    for (; iVar16 < iStack_28; iVar16 = iVar16 + 1) {

      iVar12 = iVar14;

      if ((((iVar14 == -0x80) || (iVar14 == DAT_06006c1e)) || (iVar12 = iVar16, iVar16 == -2)) ||

         (iVar16 == 2)) {

        iVar8 = iVar14 + iVar16 + (uVar13 << 6) + uVar11;

        sVar17 = *(short *)(iVar4 + (iVar8 << 1));

        sVar15 = *(short *)((iVar8 << 1) + iVar7);

        if (0 < sVar17) {

          iVar12 = *(int *)(0x06062230 + *(int *)((int)(int)puVar3 << 3)) + *(int *)(iVar10 + (iVar8 << 2));

          if ((unsigned int)0x640 <= (unsigned int)((int)sVar17 + *(int *)puVar1)) {

            sVar17 = PTR_DAT_06006c20 - (short)*(int *)puVar1;

          }

          if (*(int *)puVar3 == 2) {

            iVar12 = (*(int(*)())0x0602BDCC)(iVar12,uVar9,*(short *)(puVar2 + 0x52),(int)sVar17);

          }

          else {

            iVar12 = (*(int(*)())0x0602A214)(iVar12,uVar9,*(short *)(puVar2 + 0x52),(int)sVar17);

          }

        }

        if (0 < sVar15) {

          iVar12 = *(int *)(0x06062230 + (*(int *)((int)(int)puVar3 << 1) + 1) << 2) +

                   *(int *)(iVar5 + (iVar8 << 2));

          if ((unsigned int)0x640 <= (unsigned int)((int)sVar15 + *(int *)puVar1)) {

            sVar15 = DAT_06006cca - (short)*(int *)puVar1;

          }

          if (*(int *)puVar3 == 2) {

            iVar12 = (*(int(*)())0x0602B9E0)(iVar12,uVar6,*(short *)(puVar2 + 0x52),(int)sVar15);

          }

          else {

            iVar12 = (*(int(*)())0x0602ABB8)(iVar12,uVar6,*(short *)(puVar2 + 0x52),(int)sVar15);

          }

        }

      }

    }

  }

  return iVar12;

}

int FUN_06006cdc()
{

  short sVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int uVar11;

  int iVar12;

  int iVar13;

  int uVar14;

  int iVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  int iVar18;

  int iVar19;

  unsigned int uVar20;

  short sVar21;

  short sVar22;

  unsigned int uVar23;

  unsigned int uStack_5c;

  unsigned int uStack_58;

  unsigned int uStack_44;

  unsigned int uStack_2c;

  unsigned int uStack_28;

  puVar6 = (char *)0x06089E96;

  puVar5 = (char *)0x002F0000;

  puVar4 = (char *)0x0607EAD8;

  puVar3 = (char *)0x060620D4;

  sVar2 = DAT_06006da6;

  uVar23 = (unsigned int)DAT_06006da6;

  uVar16 = *(int *)0x06063EF0 + 0x800 & (unsigned int)0x0000FFFF;

  uVar14 = *(int *)(0x06062248 + *(int *)(0x0607EAD8 << 3));

  uVar11 = *(int *)(0x06062248 + (*(int *)(0x0607EAD8 << 1) + 1) << 2);

  iVar7 = 0xf2;

  iVar8 = (int)PTR_DAT_06006dac;

  iVar9 = *(int *)(0x06062260 + *(int *)(0x0607EAD8 << 4));

  iVar19 = *(int *)(0x0607EAD8 << 2);

  iVar15 = *(int *)(0x06062260 + (iVar19 + 1) << 2);

  iVar12 = *(int *)(0x06062260 + (iVar19 + 2) << 2);

  iVar19 = (iVar19 + 3) << 2;

  iVar10 = *(int *)(0x06062260 + iVar19);

  uVar17 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar20 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar13 = (uVar20 << 6) + uVar17;

  uStack_2c = 0;

  uStack_58 = 0;

  uStack_44 = 0xb;

  uStack_28 = 0xb;

  if (uVar20 < 0x3b) {

    if (uVar20 < 5) {

      uStack_58 = 5 - uVar20;

    }

  }

  else {

    uStack_28 = 0x45 - uVar20;

  }

  if (uVar17 < 0x3b) {

    if (uVar17 < 5) {

      uStack_2c = 5 - uVar17;

    }

  }

  else {

    uStack_44 = 0x45 - uVar17;

  }

  for (; uStack_58 < uStack_28; uStack_58 = uStack_58 + 1) {

    for (uStack_5c = uStack_2c; uStack_5c < uStack_44; uStack_5c = uStack_5c + 1) {

      iVar19 = (uStack_58 * 0xb + uStack_5c) << 1;

      sVar1 = *(short *)(puVar5 + iVar19 + iVar8 + (uVar16 >> 0xc) * iVar7);

      if (sVar1 != 0) {

        iVar18 = (sVar1 + iVar13) << 1;

        sVar22 = *(short *)(iVar9 + iVar18);

        sVar21 = *(short *)(iVar18 + iVar12);

        if (0 < sVar22) {

          iVar19 = *(int *)(iVar15 + (sVar1 + iVar13) << 2) +

                   *(int *)(0x06062230 + *(int *)((int)(int)puVar4 << 3));

          if (uVar23 <= (unsigned int)((int)sVar22 + *(int *)puVar3)) {

            sVar22 = sVar2 - (short)*(int *)puVar3;

          }

          if (*(int *)puVar4 == 2) {

            iVar19 = (*(int(*)())0x0602B9E0)(iVar19,uVar14,*(short *)puVar6,(int)sVar22);

          }

          else {

            iVar19 = (*(int(*)())0x0602ABB8)(iVar19,uVar14,*(short *)puVar6,(int)sVar22);

          }

        }

        if (0 < sVar21) {

          iVar19 = *(int *)(0x06062230 + (*(int *)((int)(int)puVar4 << 1) + 1) << 2) +

                   *(int *)(iVar10 + (sVar1 + iVar13) << 2);

          if (uVar23 <= (unsigned int)((int)sVar21 + *(int *)puVar3)) {

            sVar21 = sVar2 - (short)*(int *)puVar3;

          }

          if (*(int *)puVar4 == 2) {

            iVar19 = (*(int(*)())0x0602B9E0)(iVar19,uVar11,*(short *)puVar6,(int)sVar21);

          }

          else {

            iVar19 = (*(int(*)())0x0602ABB8)(iVar19,uVar11,*(short *)puVar6,(int)sVar21);

          }

        }

      }

    }

  }

  return iVar19;

}

/* vdp_scroll_setup -- Initialize VDP1 and VDP2 for in-game rendering.
 * Resets sprite count, sets VRAM allocation pointer, initializes VDP1,
 * selects TV mode 2, sets erase window, freezes FB state.
 * Then loads initial command list and sprite table data. */
void FUN_0600736c(void)
{
    *(int *)0x0606A4F4 = 0;
    *(int *)0x0606A4EC = (int)DAT_06007412;
    (*(int(*)())0x06039250)(0x06063F5C);
    (*(int(*)())0x0603931C)(0, 2);
    (*(int(*)())0x060393FC)(0, 0, 0, (int)DAT_06007416, (int)DAT_06007414);
    (*(int(*)())0x06038E54)(0x0000FFFF);
    (*(int(*)())0x06012E00)();
    (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C, 0x002A0000, 0x3c0);
    if ((*(unsigned int *)0x0607EAB8 & 1) != 0) {
        (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x300,
                                0x06059F78, 0x80);
    }
    (*(int(*)())0x0602766C)(*(int *)0x06063F5C, 0x0605A018, 0x60);
    VDP1_CMD_BASE_PTR = 3;
    *(short *)(*(int *)0x06063F5C + 0x60) = (short)0x00008000;
    (*(int(*)())0x0602382C)();
    (*(int(*)())0x06028654)(0x002A3457, 0x0606B178);
    (*(int(*)())0x06026CE0)();
}

/* sprite_table_entry -- Add a sprite to the VDP1 command table.
 * Looks up source sprite data from table at 0x060684EC, copies
 * position/size attributes to command list at 0x06063F64,
 * sets color bank (param_3), increments sprite count at 0x0606A4F4. */
void FUN_06007540(unsigned int sprite_id, unsigned int src_id, short color_bank)
{
    unsigned short uVar1;
    int *cmd_src;
    int sprite_count = *(int *)0x0606A4F4;

    uVar1 = *(unsigned short *)(0x060684EC + (src_id & 0xffff) << 1);
    *(short *)(0x060684EC + (sprite_id & 0xffff) << 1) = (short)sprite_count;
    cmd_src = (int *)(0x06063F64 + (unsigned int)(uVar1 << 3));
    *(int *)(0x06063F64 + (sprite_count << 3)) = *cmd_src;
    *(short *)(0x06063F64 + (sprite_count << 3) + 4) = *(short *)(cmd_src + 1);
    *(short *)(0x06063F64 + (sprite_count << 3) + 6) = color_bank;
    *(int *)0x0606A4F4 = sprite_count + 1;
}

/* sprite_slot_register -- Register a sprite into the VDP1 sorted command list.
 * Looks up source slot from type table (0x060684EC), copies VRAM offset and
 * character attributes into command table (0x06063F64). For types >= 0xD,
 * adjusts character index by param_2 * 4. Increments sprite command count. */
void FUN_06007590(unsigned short *param_1, short param_2)
{
  int idx;
  unsigned short uVar3;
  int *cnt = (int *)0x0606A4F4;         /* sprite command count */

  uVar3 = *(unsigned short *)(0x060684EC + (unsigned int)param_1[1] * 2);
  *(short *)(0x060684EC + ((unsigned int)*param_1 << 1)) = (short)*cnt;
  idx = *cnt << 3;

  /* Copy VRAM offset and character attrs from source slot */
  *(int *)(0x06063F64 + idx) = *(int *)(0x06063F64 + (unsigned int)(uVar3 << 3));
  *(short *)(0x06063F64 + idx + 4) = *(short *)(0x06063F64 + (unsigned int)(uVar3 << 3) + 4);

  if (param_1[1] < 0xd) {
    uVar3 = param_1[2];
  } else {
    uVar3 = param_1[2] + (param_2 << 2);   /* animated sprite frame offset */
  }
  *(unsigned short *)(0x06063F64 + idx + 6) = uVar3;
  *cnt = *cnt + 1;
}

/* vdp1_char_register -- Register a VDP1 character (sprite) command entry.
 * Writes VRAM offset, character size, and pattern into sorted command table
 * (0x06063F64). For types 0xD-0xF (scaled sprites), applies size transform
 * via 0x06034FE0. Type 10 records sky layer base offset. Advances VRAM
 * allocation by (width * height) / 2 bytes. */
void FUN_06007658(unsigned short param_1, unsigned short param_2, short param_3, int param_4)
{
  int *cmd_count = (int *)0x0606A4F4;      /* sprite command count */
  int *vram_off  = (int *)0x0606A4EC;       /* current VRAM write offset */
  char *cmd_tbl  = (char *)0x06063F64;      /* sprite command table base */
  unsigned short uVar4, uVar5, uVar6;

  if (param_1 == 10) {
    *(int *)0x06063F60 = *(int *)(0x0606A4EC << 3) + *(int *)0x06063F5C;
  }

  uVar5 = DAT_060076e2;
  uVar4 = param_2 & DAT_060076e2;
  *(short *)(0x060684EC + (unsigned int)(param_1 << 1)) = (short)*cmd_count;
  *(int *)(cmd_tbl + *((int *)cmd_count) * 8) = *vram_off;

  if (((param_1 == 0xd) || (param_1 == 0xe)) || (param_1 == 0xf)) {
    /* Scaled sprite: transform character size */
    uVar6 = DAT_0600777e & param_2;
    uVar5 = (*(int(*)())0x06034FE0)(param_2, param_2 & uVar5);
    *(unsigned short *)(cmd_tbl + *((int *)cmd_count) * 8 + 4) = uVar5 | uVar6;
    *(int *)0x0606A4F0 = *vram_off;
  } else {
    *(unsigned short *)(cmd_tbl + *((int *)cmd_count) * 8 + 4) = param_2;
  }

  *(short *)(cmd_tbl + *((int *)cmd_count) * 8 + 6) = param_3;
  (*(int(*)())0x06028654)(param_4, *((int *)vram_off) * 8 + *(int *)0x06063F5C);
  *cmd_count = *cmd_count + 1;
  *vram_off = *vram_off + ((int)((unsigned int)(param_2 >> 8 & 0x3f) * (unsigned int)uVar4) >> 1);
}

/* vdp1_char_register_ptr -- Register VDP1 character from descriptor pointer.
 * Like vdp1_char_register but reads type/size/pattern from param_1 array.
 * param_1[0]=type, param_1[1]=char_size, param_1[2]=pattern_base,
 * param_1[4..5]=VRAM address offset. For types 0xD-0xF applies scaled
 * sprite transform. Advances VRAM by (width * height) / 2 bytes. */
void FUN_06007790(unsigned short *param_1, short param_2, int param_3)
{
  int *cmd_count = (int *)0x0606A4F4;      /* sprite command count */
  int *vram_off  = (int *)0x0606A4EC;       /* current VRAM write offset */
  char *cmd_tbl  = (char *)0x06063F64;      /* sprite command table base */
  unsigned short uVar1, uVar5, uVar6;

  if (*param_1 == 10) {
    *(int *)0x06063F60 = *vram_off * 8 + *(int *)0x06063F5C;
  }

  uVar1 = param_1[1];
  *(short *)(0x060684EC + ((unsigned int)(*param_1) << 1)) = (short)*cmd_count;
  *(int *)(cmd_tbl + *cmd_count * 8) = *vram_off;
  uVar5 = *param_1;

  if (((uVar5 == 0xd) || (uVar5 == 0xe)) || (uVar5 == 0xf)) {
    /* Scaled sprite: transform character size */
    uVar6 = uVar1 & DAT_060078ca;
    uVar5 = (*(int(*)())0x06034FE0)();
    *(unsigned short *)(cmd_tbl + *cmd_count * 8 + 4) = uVar5 | uVar6;
    *(int *)0x0606A4F0 = *vram_off;
  } else {
    *(unsigned short *)(cmd_tbl + *cmd_count * 8 + 4) = uVar1;
  }

  *(unsigned short *)(cmd_tbl + *cmd_count * 8 + 6) = param_1[2] + (param_2 << 2);
  (*(int(*)())0x06028654)(*(int *)(param_1 + 4) + param_3, *vram_off * 8 + *(int *)0x06063F5C);
  *cmd_count = *cmd_count + 1;
  *vram_off = *vram_off + ((int)((unsigned int)(uVar1 >> 8 & 0x3f) * (unsigned int)(uVar1 & 0xff)) >> 1);
}

/* vdp1_render_flush -- Flush accumulated VDP1 commands to framebuffer.
 * Sorts pending commands (0x0602C494), copies VDP1 command table header
 * (0x0602766C), dispatches all commands via FUN_06007bcc, then waits for
 * VBL (0x060394C2). Writes end-of-list marker (0x8000) and resets counters.
 * Sets INPUT_STATE render-complete bits, DEMO_MODE_FLAG gate. */
void FUN_060078dc(void)
{
  int *render_count   = (int *)0x060620D0;  /* accumulated render commands */
  int *render_budget  = (int *)0x060620D4;  /* remaining budget this frame */
  int *frame_counter  = (int *)0x0605A008;  /* VDP1 frame index */
  char *sort_buf      = (char *)0x0606A4F8; /* sort key buffer */
  unsigned int budget = (unsigned int)DAT_060079ce;

  *render_budget = *render_budget - budget;

  if ((unsigned int)*render_count < budget) {
    /* Copy overflow commands to secondary buffer */
    (*(int(*)())0x06027630)(0x0608AC20 + (((unsigned int)*render_count & 0xffff) * 0x18 & 0xffff),
               0x0608E460, *render_budget * 0x18);
    (*(int(*)())0x0602761E)(sort_buf + *render_count * 2, sort_buf + PTR_DAT_060079d0,
               *render_budget * 2);
  }

  *render_count = *render_count + *render_budget;
  *render_budget = budget;

  /* Sort and prepare command list */
  (*(int(*)())0x0602C494)(*render_count, sort_buf);
  (*(int(*)())0x0602766C)(*(int *)0x06063F5C, 0x0605A018 + *(short *)(0x0605A016 << 5), 0x20);
  *(char **)0x060785FC = (char *)0x0606BDFC;
  *frame_counter = *frame_counter + 1;

  /* Dispatch all VDP1 draw commands */
  FUN_06007bcc();

  VBL_DISABLE_FLAG = 1;
  (*(int(*)())0x060394C2)();              /* wait for VBL sync */
  (*(int(*)())0x0602766C)(*(int *)0x06063F5C + 0x20, 0x0606BDFC, (*frame_counter + -1) << 5);

  /* Write end-of-list marker */
  *(short *)(*frame_counter * 32 + *(int *)0x06063F5C) = (short)0x00008000;

  INPUT_STATE = INPUT_STATE | (unsigned int)0x20000000 | 4;
  if (DEMO_MODE_FLAG == 0) {
    *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x08000000;
  }

  VBL_DISABLE_FLAG = 0;
  (*(int(*)())0x06026CE0)();              /* post-render cleanup */
  *render_count = 0;
  *frame_counter = 0;
  *(int *)0x0606BDF8 = VBLANK_OUT_COUNTER;
  *(int *)0x06059F44 = 0;
}

/* vdp1_shadow_polygon -- Generate car shadow polygon for VDP1.
 * Computes 4 screen-space vertices from car height (CAR_PTR_TARGET) and
 * sun angle. Uses fixed-point multiply (0x06027552) and sincos (0x06027358)
 * to project shadow corners onto ground plane. Vertices written to shadow
 * command buffer at 0x06078604. Color = 0xA3FF (shadow mesh). */
void FUN_06007a50(void)
{
  int (*fpmul)(int, int) = (int (*)(int, int))0x06027552;
  short (*fp2scr)(int) = (short (*)(int))0x0602754C;
  short *shadow = (short *)0x06078604;     /* shadow polygon vertex buffer */
  short sVar7, sVar9;
  int iVar6, iVar8;
  int local_24;         /* sin component */
  int auStack_20[2];    /* cos component */

  /* Clamp shadow height to car Y position */
  iVar8 = (int)DAT_06007a92;
  if (*(int *)(CAR_PTR_TARGET + (int)DAT_06007a94) <= iVar8) {
    iVar8 = *(int *)(CAR_PTR_TARGET + (int)DAT_06007a94);
  }
  iVar8 = fpmul(iVar8, 0x0000D1B7);        /* scale factor */

  /* Y offset: normal=0x34, alternate=0x24 */
  sVar9 = (*(int *)0x06085FF4 == '\0') ? 0x34 : 0x24;

  /* Get sin/cos of shadow angle */
  (*(int(*)())0x06027358)(DAT_06007a96 + iVar8, &local_24, auStack_20);

  /* Vertex A: top-left */
  iVar8 = fpmul(0x00970000, local_24);
  sVar7 = fp2scr(-iVar8);
  shadow[4] = sVar7 + 8;
  iVar8 = fpmul(0x00970000, auStack_20[0]);
  sVar7 = fp2scr(iVar8);
  shadow[5] = sVar7 + sVar9;

  /* Vertex B: top-right */
  iVar8 = fpmul(0x00020000, auStack_20[0]);
  iVar6 = fpmul(0x00900000, local_24);
  sVar7 = fp2scr(iVar8 - iVar6);
  shadow[6] = sVar7 + 8;
  iVar8 = fpmul(0x00020000, local_24);
  iVar6 = fpmul(0x00900000, auStack_20[0]);
  sVar7 = fp2scr(iVar8 + iVar6);
  shadow[7] = sVar7 + sVar9;

  /* Vertex C: bottom-right */
  iVar8 = fpmul(0x00890000, local_24);
  sVar7 = fp2scr(-iVar8);
  shadow[8] = sVar7 + 8;
  iVar8 = fpmul(0x00890000, auStack_20[0]);
  sVar7 = fp2scr(iVar8);
  shadow[9] = sVar7 + sVar9;

  /* Vertex D: bottom-left */
  iVar8 = fpmul(0xFFFE0000, auStack_20[0]);
  iVar6 = fpmul(0x00900000, local_24);
  sVar7 = fp2scr(iVar8 - iVar6);
  shadow[10] = sVar7 + 8;
  iVar8 = fpmul(0xFFFE0000, local_24);
  iVar6 = fpmul(0x00900000, auStack_20[0]);
  sVar7 = fp2scr(iVar8 + iVar6);
  shadow[11] = sVar7 + sVar9;

  shadow[3] = (short)0x0000A3FF;            /* shadow mesh color */

  /* Write shadow polygon to VDP1 command list */
  (*(int(*)())0x060280C4)(shadow, *(int *)0x060785FC);
  VDP1_CMD_BASE_PTR = VDP1_CMD_BASE_PTR + 1;
  *(int *)0x060785FC = *(int *)0x060785FC + 0x20;
}

/* vdp1_command_dispatch -- Iterate sorted render list and emit VDP1 draw commands.
 * Loops over render_count entries in sort buffer (0x0606A4F8), looks up each
 * command in the 24-byte command array (0x0608AC20). Type 9 uses scaled sprite
 * writer (0x060281B8), others use normal writer (0x060280F8). Advances VDP1
 * write pointer by 0x20 per command. After dispatch, optionally draws shadow
 * polygon (FUN_06007a50) if GAME_STATE_BIT has overlay bits set. */
void FUN_06007bcc(void)
{
  int *vdp1_write  = (int *)0x060785FC;    /* VDP1 command write pointer */
  char *cmd_array  = (char *)0x0608AC20;   /* 24-byte command descriptors */
  int *render_count = (int *)0x060620D0;   /* number of commands to dispatch */
  void (*cmd_write)(char *, int) = (void (*)(char *, int))0x060280F8;
  unsigned int i, idx;

  *(int *)0x06078620 = 0;

  /* Check if interlace mode is active */
  if ((*(unsigned short *)0x06063DA0 & 8) == 0) {
    *(int *)0x0607861C = 0;
  } else {
    *(int *)0x0607861C = 1;
  }

  for (i = 0; i < (unsigned int)*render_count; i++) {
    idx = (unsigned int)*(unsigned short *)(0x0606A4F8 + (i << 1));
    if (*(short *)(cmd_array + (idx * 0x18 & 0xffff) + 6) == 9) {
      /* Scaled sprite command */
      (*(int(*)())0x060281B8)(cmd_array + (idx * 0x18 & 0xffff), *vdp1_write, (int)0x00008000);
    } else {
      cmd_write(cmd_array + (idx * 0x18 & 0xffff), *vdp1_write);
    }
    *vdp1_write = *vdp1_write + 0x20;
  }

  VDP1_CMD_BASE_PTR = VDP1_CMD_BASE_PTR + *render_count;

  /* Draw shadow polygon overlay if game state requires it */
  if ((GAME_STATE_BIT & (unsigned int)0x20228000) != 0) {
    (*(int(*)())0x060333D8)();
    FUN_06007a50();
  }

  (*(int(*)())0x06011DC0)();                /* post-command processing */
  (*(int(*)())0x060171AC)();                /* frame finalize */
}
