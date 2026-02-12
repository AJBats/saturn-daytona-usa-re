#include "game.h"

extern int DAT_06014136;
extern int DAT_06014212;
extern int DAT_06014306;
extern int DAT_0601440e;
extern int DAT_06014410;
extern int DAT_06014594;
extern int DAT_06014682;
extern int DAT_06014818;
extern int DAT_06014a4e;
extern int DAT_06014ae2;
extern int DAT_06014bce;
extern int DAT_06014bd0;
extern int DAT_06014bd2;
extern int DAT_06014bd4;
extern int DAT_06014bd6;
extern int DAT_06014cf2;
extern int DAT_06014de4;
extern int DAT_0601541a;
extern int FUN_06013e12();
extern unsigned int FUN_060146d2();
extern unsigned int FUN_0601476c();
extern int FUN_06014f34();
extern int PTR_DAT_06014308;
extern int PTR_DAT_06014684;
extern int PTR_DAT_06014cf4;

/* hud_position_marker_render -- Render position marker sprite for current car.
 * Guards on car count < 4. Looks up sprite offset from 0x0605AD4C table,
 * pushes matrix, sets position/scale, renders via FUN_06013e12,
 * then draws texture with palette from 0x06062338/0x060622C0 tables. */
void FUN_060140c4()
{
  int sprite_offset;

  if (*(unsigned int *)0x06084B18 < 4) {
    sprite_offset = *(int *)(0x0605AD4C + *(int *)(0x06084B18 << 2));
    (*(int(*)())0x06026DBC)(); /* matrix_push */
    (*(int(*)())0x06026E2E)(sprite_offset, -13107, 0x00010000); /* set position */
    (*(int(*)())0x06026E60)(0x00010000, 0x00010000, 0x00010000); /* set scale 1.0 */
    FUN_06013e12(); /* render digit/marker */
    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + *(int *)(0x06084B08 << 2)), 4); /* texture select */
    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + *(int *)(0x06084B08 << 2)),
               (int)*(short *)0x06089E4A, 1); /* palette draw */
    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30; /* advance VDP1 cmd slot */
  }
}

/* hud_position_digits_render -- Render up to 3 position digit sprites.
 * Resets matrix, then for each digit slot (up to car count):
 * looks up position from 0x0605AD4C, maps character to sprite index
 * ('.' → 0x1A, else char + 0xBF), renders texture from lookup tables. */
void FUN_0601416c()
{
  unsigned char sprite_idx;
  unsigned int i;

  (*(int(*)())0x06026E0C)(); /* matrix_reset */

  i = 0;
  do {
    if (i < *(unsigned int *)0x06084B18) {
      (*(int(*)())0x06026DBC)(); /* matrix_push */
      (*(int(*)())0x06026E2E)(*(int *)(0x0605AD4C + (i << 2)), -13107, 0x00010000); /* position */
      (*(int(*)())0x06026E60)(0x00010000, 0x00010000, 0x00010000); /* scale 1.0 */

      if (((int *)0x06084B14)[i] == '.') {
        sprite_idx = 0x1a; /* period character */
      } else {
        sprite_idx = ((int *)0x06084B14)[i] + 0xbf; /* ASCII to sprite index */
      }

      (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + (unsigned int)(sprite_idx << 2)), 4);
      (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + (unsigned int)(sprite_idx << 2)),
                 (int)*(short *)0x06089E4A, 1);
      *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30; /* advance VDP1 cmd slot */
    }
    i = i + 1;
  } while (i < 3);
}

/* hud_indicator_render -- Render HUD indicator with smoothed rotation.
 * Smooths target angle (exponential half-step toward target from table 0x0605AD5C),
 * applies fixed-point multiply for position offset,
 * rotates by frame counter bits (animation), renders at scale 1.0. */
void FUN_0601424c()
{
  int delta;
  int pos_offset;
  int *anim_table;

  (*(int(*)())0x06026E0C)(); /* matrix_reset */
  (*(int(*)())0x06026DBC)(); /* matrix_push */
  (*(int(*)())0x06026E2E)(0, (int)DAT_06014306, 0x000108F5); /* set base position */

  anim_table = (int *)(0x0605AD5C + *(int *)(0x06084B08 << 5));

  /* smooth angle: move halfway toward target each frame */
  delta = (int)*(short *)(anim_table + 6) - (int)*(short *)0x06084AF8;
  *(short *)0x06084AF8 =
       *(short *)0x06084AF8 + (short)((int)(delta + (unsigned int)(delta < 0)) >> 1);

  (*(int(*)())0x06026F2A)((int)*(short *)0x06084AF8); /* set rotation */

  /* smooth position offset with fixed-point multiply */
  pos_offset = (*(int(*)())0x06027552)((*anim_table - *(int *)0x06084AFC) + (int)PTR_DAT_06014308,
                     0x00008000);
  pos_offset = *(int *)0x06084AFC + pos_offset;
  *(int *)0x06084AFC = pos_offset;

  (*(int(*)())0x06026E2E)(0, pos_offset); /* apply position */
  (*(int(*)())0x06026F2A)(-(int)*(short *)0x06084AF8); /* undo rotation */
  (*(int(*)())0x06026EDE)((FRAME_COUNTER & 0x1f) << 0xb); /* frame-based animation */
  (*(int(*)())0x06026E60)(0x00010000, 0x00010000, 0x00010000); /* scale 1.0 */

  (*(int(*)())0x06031D8C)(*(int *)0x060623AC, 4); /* texture select */
  (*(int(*)())0x06031A28)(*(int *)0x06062334, (int)*(short *)0x06089E4A, 1); /* draw */
  OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30; /* advance VDP1 cmd slot */
}

void FUN_06014360()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int *puVar6;

  unsigned int uVar7;

  int iVar8;

  puVar3 = (char *)0x06089EDC;

  puVar2 = (char *)0x06026E2E;

  puVar1 = (char *)0x06026F2A;

  iVar5 = (int)DAT_0601440e;

  iVar8 = 0x4ccc;

  (*(int(*)())0x06026E0C)();

  puVar4 = (char *)0x06089E4A;

  uVar7 = 0;

  do {

    puVar6 = (int *)(0x0605AD5C + (uVar7 << 5));

    (*(int(*)())0x06026DBC)();

    (*(int(*)())puVar2)(0,iVar5,0x00010000);

    (*(int(*)())puVar1)((int)*(short *)(puVar6 + 6));

    (*(int(*)())puVar2)(0,*puVar6);

    (*(int(*)())puVar1)(-(int)*(short *)(puVar6 + 6));

    if (*(unsigned int *)0x06084B08 == uVar7) {

      FUN_06013e12();

    }

    (*(int(*)())0x06026E60)(iVar8,iVar8,iVar8);

    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + (uVar7 << 2)),4);

    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + (uVar7 << 2)),(int)*(short *)puVar4,1);

    uVar7 = uVar7 + 1;

    *(int *)puVar3 = *(int *)puVar3 + -0x30;

  } while (uVar7 < 0x1d);

  return;

}

unsigned int FUN_06014466()
{

  char *puVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  puVar1 = (char *)0x06084B08;

  uVar2 = (int)(((unsigned int)*(unsigned short *)(0x06063D98 + 4) ^ (unsigned int)0x0000FFFF) & 0xff) >> 3;

  uVar3 = uVar2;

  if (0x1c < uVar2) {

    uVar3 = 0x1c;

  }

  *(int *)0x06084B0C = *(int *)0x06084B08;

  *(unsigned int *)puVar1 = uVar3;

  if (2 < *(unsigned int *)0x06084B18) {

    if (uVar3 < 0xf) {

      *(int *)puVar1 = (char *)0x1b;

    }

    else {

      *(int *)puVar1 = (char *)0x1c;

    }

  }

  if (*(int *)puVar1 != *(int *)0x06084B0C) {

    uVar2 = (*(int(*)())0x0601D5F4)(0,0xAB111DFF);

  }

  *(unsigned int *)0x06084B20 =

       (unsigned int)(unsigned char)((int *)0x0605AD2C)[*(int *)puVar1];

  return uVar2;

}

/* hud_camera_angle_update -- Update HUD camera view angle index.
 * Reads controller input every 4th frame: D-pad up (DAT_06014594)
 * decrements, bit 15 (analog up) increments (range 0..0x1C).
 * Clamps to 0x1B..0x1C when car count > 2.
 * Looks up render flag from table 0x0605AD2C, plays sound on change. */
void FUN_0601450c()
{
  int prev_angle = *(int *)0x06084B08;

  if ((FRAME_COUNTER & 3) == 0) {
    if ((*(unsigned short *)0x06063D98 & DAT_06014594) == 0) {
      if ((((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) != 0) &&
         (*(unsigned int *)0x06084B08 < 0x1c)) {
        *(int *)0x06084B08 = *(int *)0x06084B08 + 1; /* increment angle */
      }
    } else if (*(int *)0x06084B08 != 0) {
      *(int *)0x06084B08 = *(int *)0x06084B08 + -1; /* decrement angle */
    }
  }

  /* clamp range when 3+ cars */
  if (2 < *(unsigned int *)0x06084B18) {
    if (*(unsigned int *)0x06084B08 < 0x1b) {
      *(int *)0x06084B08 = 0x1b;
    } else if (0x1c < *(unsigned int *)0x06084B08) {
      *(int *)0x06084B08 = 0x1c;
    }
  }

  *(unsigned int *)0x06084B20 =
       (unsigned int)(unsigned char)((int *)0x0605AD2C)[*(int *)0x06084B08];

  if (prev_angle != *(int *)0x06084B08) {
    (*(int(*)())0x0601D5F4)(0, 0xAB111DFF); /* play angle change sound */
  }
}

void FUN_060145bc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int uVar6;

  puVar4 = (char *)0x06084B20;

  puVar3 = (char *)0x06084B14;

  puVar2 = (char *)0x06084B18;

  puVar1 = (char *)0x0601D5F4;

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06014682) != 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06014684) == 0 &&

        *(int *)0x06084B20 != 0x7d) {

      if (*(int *)0x06084B20 == 0x7b) {

        FUN_060146d2();

        return;

      }

      iVar5 = *(int *)0x06084B18;

      *(int *)0x06084B18 = iVar5 + 1;

      puVar3[iVar5] = (char)*(int *)puVar4;

      uVar6 = 0xAB1102FF;

      if (-1 < *(int *)puVar4 + -0x41) {

        uVar6 = *(int *)(0x0605B0FC + (*(int *)puVar4 + -0x41) << 2);

      }

      (*(int(*)())puVar1)(0,uVar6);

      if (*(int *)puVar2 == 3) {

        *(int *)0x06084B08 = 0x1c;

        (*(int(*)())puVar1)(0,0xAB111EFF);

      }

    }

    else if (*(int *)0x06084B18 == 0) {

      *(int *)0x06084B14 = 0;

      puVar3[1] = 0;

      puVar3[2] = 0;

      puVar3[3] = 0;

    }

    else {

      (*(int(*)())0x0601D5F4)(0,0xAB1101FF);

      iVar5 = *(int *)puVar2;

      *(int *)puVar2 = iVar5 + -1;

      puVar3[iVar5 + -1] = 0;

    }

  }

  return;

}

unsigned int FUN_060146d2()
{

  char *puVar1;

  char cVar3;

  unsigned int uVar2;

  char *puVar4;

  char *puVar5;

  *(int *)0x0607EBCC = 0;

  cVar3 = FUN_0601476c(0x06084FB4);

  if (cVar3 == '\0') {

    *(int *)0x06084AF2 = 4;

  }

  else {

    *(int *)0x06084AF2 = 6;

  }

  puVar1 = (char *)0x06084B14;

  uVar2 = *(unsigned int *)0x06084B10;

  if ((uVar2 & 1) == 0) {

    puVar4 = *(char **)0x06085FFC;

    if (puVar4 != (char *)0x0) {

      puVar5 = 0x06084B14 + 1;

      *puVar4 = *(int *)0x06084B14;

      puVar4[1] = *puVar5;

      puVar4[2] = puVar1[2];

      puVar4[3] = puVar1[3];

    }

    puVar1 = (char *)0x06084B14;

    puVar4 = *(char **)0x06086000;

    if (puVar4 != (char *)0x0) {

      puVar5 = 0x06084B14 + 1;

      *puVar4 = *(int *)0x06084B14;

      puVar4[1] = *puVar5;

      puVar4[2] = puVar1[2];

      puVar4[3] = puVar1[3];

    }

  }

  return uVar2;

}

unsigned int FUN_0601476c(param_1)
    unsigned int *param_1;
{

  char *puVar1;

  unsigned char *pbVar2;

  unsigned char *pbVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  char cVar8;

  pbVar3 = 0x0605B3C4;

  puVar1 = (char *)0x06084B14;

  uVar6 = (unsigned int)DAT_06014818;

  uVar7 = 1;

  uVar5 = 0;

  *(short *)0x06084FB8 = 0;

  *(unsigned int *)0x0607EBCC = uVar6 - 0x4b;

  do {

    cVar8 = *puVar1 == *pbVar3;

    pbVar2 = pbVar3 + 2;

    if (puVar1[1] == pbVar3[1]) {

      cVar8 = cVar8 + '\x01';

    }

    pbVar3 = pbVar3 + 3;

    if (puVar1[2] == *pbVar2) {

      cVar8 = cVar8 + '\x01';

    }

    if (cVar8 == '\x03') {

      *(int *)0x0607EBCC = *(int *)(0x0605B164 + (uVar5 << 2));

      if (uVar5 < 2) {

        if (0x2a < uVar5) {

          uVar5 = 0x2b;

        }

        puVar4 = 0x0605B4A8 +

                 (short)(((short)(uVar5 << 2) + ((unsigned short)FRAME_COUNTER & 3)) * 3);

        *puVar1 = *puVar4;

        puVar1[1] = puVar4[1];

        pbVar3 = puVar4 + 3;

        puVar1[2] = puVar4[2];

        uVar7 = uVar6 & 0xff;

      }

      else {

        uVar7 = 0;

        *(short *)0x06084FB8 = 1;

      }

    }

    uVar5 = uVar5 + 1;

    if (*pbVar3 == uVar6) {

      uVar7 = 0;

    }

  } while (uVar7 == 1);

  *param_1 = uVar5;

  return uVar7;

}

/* hud_init_and_render -- Initialize HUD: DMA palette to VDP1, render digits.
 * Copies 32 words from 0x06044B64 to VDP1 CRAM at calculated offset
 * (0x25C00260 + frame-selected bank). Calls hud_digits_render_all.
 * Sets HUD active flag (bit 0 of 0x0607EBF4), initializes display slots. */
void FUN_06014a04(void)
{
    int in_r7 = 0;

    (*(int(*)())0x0602761E)(0x25C00000 + 0x260 + *(int *)(0x06059FFC << 3),
                            0x06044B64, 0x20, in_r7, 0x25C00000);

    (*(int(*)())0x060172BC)();  /* hud_digits_render_all */

    *(unsigned int *)0x0607EBF4 = *(unsigned int *)0x0607EBF4 | 1;
    *(short *)0x06085F90 = 0;
    *(short *)0x06085F94 = 1;
}

void FUN_06014a74()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  short *puVar5;

  unsigned char bVar6;

  unsigned char bVar7;

  puVar2 = (char *)0x06038BD4;

  puVar1 = (char *)0x06085640;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar2)(4,1);

  (*(int(*)())puVar2)(8,1);

  (*(int(*)())puVar2)(0x10,2);

  (*(int(*)())puVar2)(0x20,7);

  (*(int(*)())puVar2)(1,0);

  if (*(int *)0x06085F8A == '\0') {

    (*(int(*)())0x0602853E)(4);

    (*(int(*)())0x06014884)(8,0);

    (*(int(*)())puVar2)(0x10,6);

    (*(int(*)())0x06028560)();

    (*(int(*)())0x060032D4)();

  }

  else {

    (*(int(*)())0x06020CF4)();

    (*(int(*)())0x060078DC)();

  }

  (*(int(*)())puVar2)(0x100,4);

  (*(int(*)())0x0602853E)(0xc);

  (*(int(*)())0x06014884)(0x10,0);

  (*(int(*)())0x06014884)(0x20,0);

  puVar2 = (char *)0x0602761E;

  (*(int(*)())0x0602761E)(0x25F00660,0x06044A64,0x20);

  (*(int(*)())puVar2)(0x25F00680,0x06044A84,0x20);

  (*(int(*)())puVar2)(0x25F006A0,0x06044AA4,0x20);

  (*(int(*)())puVar2)(0x25F006C0,0x06044AC4,0x20);

  puVar3 = (char *)0x25C00000;

  (*(int(*)())puVar2)(0x25C00000 + 0x260 + *(int *)(0x06059FFC << 3),

                    0x06044AE4,0x20);

  (*(int(*)())puVar2)(puVar3 + 0x280 + *(int *)(0x06059FFC << 3),0x06044B24,0x20)

  ;

  (*(int(*)())puVar2)(puVar3 + 0x220 + *(int *)(0x06059FFC << 3),0x06044B04,0x20)

  ;

  (*(int(*)())puVar2)(puVar3 + 0x240 + *(int *)(0x06059FFC << 3),0x06044B44,0x20)

  ;

  puVar2 = (char *)0x0600511E;

  (*(int(*)())0x0600511E)(0x25E73B98,0x00017700,0,8);

  (*(int(*)())puVar2)(0x25E74158,0x000189E0,0,8);

  (*(int(*)())puVar2)(0x25E74AFC,0x0001AFA0,0,8);

  (*(int(*)())puVar2)(0x25E75730,0x0001C980,0,8);

  for (bVar7 = 0; bVar7 < 0x2c; bVar7 = bVar7 + 1) {

    puVar5 = (short *)(puVar1 + (short)((unsigned short)bVar7 * 0x36));

    *puVar5 = 1;

    puVar5[1] = 0x19;

    bVar6 = 0;

    do {

      uVar4 = (unsigned int)bVar6;

      bVar6 = bVar6 + 1;

      *(short *)(puVar1 + (uVar4 << 1) + (int)(short)((unsigned short)bVar7 * 0x36) + 4) = 0x20;

    } while (bVar6 < 0x19);

  }

  (*(int(*)())0x060172BC)();

  (*(int(*)())0x060173AC)();

  *(int *)0x06085F89 = 0;

  *(short *)0x06085F90 = 0;

  *(short *)0x06085F94 = 1;

  (*(int(*)())0x060149CC)();

  if (((unsigned int)(*(short *)0x0607ED8C == 2) & *(unsigned int *)0x0607EBF4) != 0) {

    *(short *)0x06085F90 = 0x27;

    puVar1 = (char *)0x0607E944;

    *(int *)(CAR_PTR_TARGET + (int)DAT_06014cf2) = (int)(char)*(int *)0x06078637;

    *(int *)(*(int *)puVar1 + 0x240) = *(int *)0x06078638;

    *(int *)0x060786A4 = *(int *)0x0607863C;

  }

  return;

}

void FUN_06014d2c()
{

  char *puVar1;

  char *puVar2;

  short uVar3;

  int iVar4;

  char *puVar5;

  unsigned char bVar6;

  puVar2 = (char *)0x06085F90;

  puVar1 = (char *)0x06063F64;

  puVar5 = (char *)0x06085F94;

  if ((*(int *)0x06085F89 == '\0') && ((*(unsigned short *)0x06063D9A & DAT_06014de4) != 0)) {

    if ((*(unsigned int *)0x0607EBF4 & 1) == 0) {

      if (*(unsigned short *)0x06085F90 < 0xc || 0x15 < *(unsigned short *)0x06085F90) {

        if (3 < *(unsigned short *)0x06085F90 && *(unsigned short *)0x06085F90 < 0x16) {

          *(int *)0x06085F89 = 1;

          *(short *)puVar5 = 1;

          *(short *)puVar2 = *(short *)puVar2 + 0x12;

        }

      }

      else {

        *(int *)0x06085F89 = 1;

        bVar6 = 8;

        do {

          (*(int(*)())0x060172E4)(bVar6);

          bVar6 = bVar6 + 1;

        } while (bVar6 < 0x10);

        *(short *)puVar5 = 1;

        uVar3 = 0x20;

        if (0x14 < *(unsigned short *)puVar2) {

          uVar3 = 0x22;

        }

        *(short *)puVar2 = uVar3;

      }

    }

    else if (*(unsigned short *)0x06085F90 < 0xc || 0x16 < *(unsigned short *)0x06085F90) {

      if (3 < *(unsigned short *)0x06085F90 && *(unsigned short *)0x06085F90 < 0x17) {

        *(int *)0x06085F89 = 1;

        *(short *)puVar5 = 1;

        *(short *)puVar2 = *(short *)puVar2 + 0x13;

      }

    }

    else {

      *(int *)0x06085F89 = 1;

      bVar6 = 8;

      do {

        (*(int(*)())0x060172E4)(bVar6);

        bVar6 = bVar6 + 1;

      } while (bVar6 < 0x10);

      *(short *)puVar5 = 1;

      uVar3 = 0x23;

      if (0x14 < *(unsigned short *)puVar2) {

        uVar3 = 0x26;

      }

      *(short *)puVar2 = uVar3;

    }

  }

  if (*(int *)0x06085F8A != '\0') {

    (*(int(*)())0x06020CF4)();

  }

  FUN_06014f34();

  (*(int(*)())0x0601712C)();

  bVar6 = 0;

  iVar4 = *(int *)0x06085F98;

  do {

    puVar5 = *(char **)(0x06084FC8 + (short)((unsigned short)bVar6 * 0x44) + 0x2c);

    if ((puVar5 == (char *)0x0 || puVar5 == 0x00008000) || puVar5 == 0x00010000) {

      *(short *)(puVar1 + (((unsigned int)bVar6 + iVar4) << 3) + 6) = 0x4c;

      uVar3 = 0x50;

    }

    else {

      *(short *)(puVar1 + (((unsigned int)bVar6 + iVar4) << 3) + 6) = 0x44;

      uVar3 = 0x48;

    }

    bVar6 = bVar6 + 1;

    *(short *)(puVar1 + ((iVar4 + 6) << 3) + 6) = uVar3;

  } while (bVar6 < 8);

  return;

}

/* replay_init_sequence -- Initialize replay mode state and rendering.
 * Stops sound (0x06018E70), configures CD transfer (0x06038BD4),
 * sets GAME_STATE to 0x1E (replay). If demo flags set, may redirect
 * to state 0x1A. Sets up VDP rendering, clears screen twice,
 * configures scroll planes, enables input, then dispatches to
 * course-specific handler via jump table at 0x0605B724. */
void FUN_06015338()
{
  int (*cd_config)(int, int) = (int (*)(int, int))0x06038BD4;

  (*(int(*)())0x06018E70)(); /* stop sound */
  cd_config(0x100, 0); /* configure CD transfer */

  *(int *)0x06085F8A = 0; /* clear render flag */
  GAME_STATE = 0x1e; /* set replay state */
  (*(int(*)())0x0601ABC6)(); /* replay setup */

  if (*(int *)0x06085FF8 != '\0' || *(int *)0x06085FF9 != '\0') {
    if (*(short *)0x06085F92 == 0) {
      (*(int(*)())0x0601AC7C)(); /* demo mode setup */
    }
    GAME_STATE = 0x1a; /* redirect to attract mode */
  }

  (*(int(*)())0x060172BC)(); /* init replay subsystem */
  cd_config(0x100, 0);
  cd_config(4, 1);
  cd_config(0x10, 6);

  (*(int(*)())0x060149E0)(); /* HUD setup */
  VBL_DISABLE_FLAG = 0;
  (*(int(*)())0x06026CE0)(); /* VDP sync */
  PHASE_FLAG = 3;

  (*(int(*)())0x06020CF4)(); /* vdp1_clear */
  (*(int(*)())0x060078DC)(); /* wait vblank */
  (*(int(*)())0x06020CF4)(); /* vdp1_clear (double buffer) */
  (*(int(*)())0x060078DC)(); /* wait vblank */

  (*(int(*)())0x0602853E)(4); /* scroll plane setup A */
  (*(int(*)())0x0602853E)(0xc); /* scroll plane setup B */
  (*(int(*)())0x06028560)(); /* finalize scroll config */
  (*(int(*)())0x060032D4)(); /* system sync */

  INPUT_STATE = INPUT_STATE | 4; /* enable input */
  VBL_DISABLE_FLAG = 0;
  (*(int(*)())0x06026CE0)(); /* VDP sync */
  cd_config(0x100, 4);
  cd_config(4, 0);

  (*(int(*)())(*(int *)(0x0605B724 + *(int *)(0x0607EAD8 << 2))))(); /* course handler dispatch */
}

/* sound_channel_configure -- Configure a sound channel from lookup tables.
 * param_1 low byte = channel index. Computes table offset from channel's
 * state byte at 0x06084FC8, loads PCM address/pitch/flags from 0x0605B8B8.
 * Checks if pitch == 0x100000 (special marker) to set loop flag.
 * If stereo mode (0x06085F89), also loads alternate PCM parameters.
 * Increments channel's sequence counter. */
void FUN_06015eb8(param_1)
    unsigned int param_1;
{
  unsigned short chan_idx;
  unsigned int table_off;
  int *table_entry;
  int pitch_check;
  char *chan_base = (char *)0x06084FC8;
  char *pcm_table = (char *)0x0605B8B8;

  chan_idx = (unsigned short)param_1 & 0xff;
  table_off = (unsigned int)(unsigned char)((int *)0x06084FC8)[(short)(chan_idx * 0x44) + 0x41] * 4 +
              (param_1 & 0xff) << 4 & 0xff;

  table_entry = (int *)(0x0605B8B8 + (table_off << 2));

  *(int *)(0x06084FC8 + (short)(chan_idx * 0x44) + 0x34) = *table_entry; /* PCM address */
  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x10) = table_entry[1]; /* pitch */
  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x1c) = 0; /* clear loop flag */

  pitch_check = (*(int(*)())0x06035438)(*(int *)(chan_base + (short)(chan_idx * 0x44) + 0x10));
  if (pitch_check == 0x00100000) {
    *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x1c) = 1; /* set loop flag */
  }

  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x38) =
       *(int *)(pcm_table + (table_off << 2) + 8); /* volume */
  *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x18) =
       *(int *)(pcm_table + (table_off << 2) + 0xc); /* pan */

  if (*(int *)0x06085F89 != '\0') {
    /* stereo mode: load alternate parameters */
    *(int *)(chan_base + (short)(chan_idx * 0x44) + 0x30) =
         *(int *)((int)(pcm_table + ((((param_1 & 0xff) << 4) + 8) << 2)) + 8);
    *(int *)(chan_base + (short)(chan_idx * 0x44) + 4) =
         *(int *)(pcm_table + ((((param_1 & 0xff) << 4) + 8) << 2));
  }

  chan_base[(short)(chan_idx * 0x44) + 2] = chan_base[(short)(chan_idx * 0x44) + 2] + '\x01'; /* increment sequence */
}
