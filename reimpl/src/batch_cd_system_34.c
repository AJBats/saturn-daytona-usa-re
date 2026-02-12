#include "game.h"

extern char DAT_06082A7C[];
extern int DAT_0603489e;
extern int DAT_06034976;
extern int DAT_06034a8e;
extern int DAT_06034bf4;
extern int DAT_06034bf6;
extern int DAT_06034d02;
extern int DAT_06034ffa;
extern int DAT_06035734;
extern int DAT_06035c46;
extern int FUN_06034754();
extern int FUN_060347a8();
extern unsigned int FUN_06034848();
extern int FUN_06034a10();
extern int FUN_06034cc8();
extern int FUN_06034d5e();
extern long long FUN_060359d2();
extern long long FUN_060359da();
extern int FUN_06035c6e();
extern void FUN_06035f16();

/* scene_object_position_compute -- Compute 3D position for a scene object.
 * Implicit r14 = scene object pointer.
 * Type 3 (obj[1]==3): simple rotation advance at obj+0x1C.
 * Others: orbit around origin (obj+0x14,0x18,0x1C) at radius (obj+0x20):
 *   X = origin.X + radius * sin(angle), Z = origin.Z + radius * cos(angle).
 *   Type 2: grounded — queries terrain height via 0x06006838.
 *   Type 1/4: computed Y from vertical offset (obj+0x24) and orbit math. */
int FUN_06034000()
{
  long long lVar1;
  int iVar2;
  int uVar3;
  int uVar4;
  int iVar5;
  unsigned int uVar6;
  int in_r7 = 0;
  int iVar7;
  int unaff_r14 = 0;
  int in_pr;

  if (*(char *)(unaff_r14 + 0x00000001) == '\x03') {
    iVar2 = 0x0000001C;
    *(int *)(unaff_r14 + 0x0000001C) =
         *(int *)(unaff_r14 + 0x0000001C) + (int)*(short *)(unaff_r14 + 0x00000012);
    return iVar2;
  }
  iVar5 = (int)*(short *)(unaff_r14 + 0x00000002) + (int)*(short *)(unaff_r14 + 0x00000012);
  *(short *)(unaff_r14 + 0x00000002) = (short)iVar5;
  iVar2 = (*(int(*)())0x06027344)(iVar5);
  iVar7 = *(int *)(unaff_r14 + 0x00000020);
  *(unsigned int *)(unaff_r14 + 0x00000004) =
       ((int)((unsigned long long)((long long)iVar7 * (long long)iVar2) >> 0x20) << 0x10 |
       (unsigned int)((long long)iVar7 * (long long)iVar2) >> 0x10) + *(int *)(unaff_r14 + 0x00000014);
  iVar5 = (*(int(*)())0x06027348)(iVar5);
  *(unsigned int *)(unaff_r14 + 0x0000000C) =
       ((int)((unsigned long long)((long long)iVar7 * (long long)iVar5) >> 0x20) << 0x10 |
       (unsigned int)((long long)iVar7 * (long long)iVar5) >> 0x10) + *(int *)(unaff_r14 + 0x0000001C);
  if (*(char *)(unaff_r14 + 0x00000001) == '\x02') {
    *(int *)0x06083238 = *(int *)(unaff_r14 + 0x00000004);
    *(int *)0x06083240 = *(int *)(unaff_r14 + 0x0000000C);
    uVar3 = (*(int(*)())0x06006838)();
    (*(int(*)())0x06027EDE)(uVar3,0x06083238,0x06083244,in_r7,in_pr);
    iVar2 = 0x00000008;
    *(int *)(unaff_r14 + 0x00000008) = *(int *)0x0608323C;
  }
  else {
    if (*(short *)(unaff_r14 + 0x00000024) == 0) {
      uVar6 = 0;
    }
    else {
      lVar1 = (long long)(int)*(short *)(unaff_r14 + 0x00000024) * (long long)iVar2;
      uVar6 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
      uVar3 = (*(int(*)())0x06027348)(uVar6);
      uVar4 = (*(int(*)())0x06027344)(uVar6);
      iVar2 = (*(int(*)())0x0602755C)(uVar3,uVar4);
      uVar6 = (int)((unsigned long long)((long long)iVar7 * (long long)iVar2) >> 0x20) << 0x10 |
              (unsigned int)((long long)iVar7 * (long long)iVar2) >> 0x10;
    }
    iVar2 = 0x00000008;
    *(unsigned int *)(unaff_r14 + 0x00000008) = uVar6 + *(int *)(unaff_r14 + 0x00000018);
  }
  return iVar2;
}

/* scene_object_transform_render -- Transform and render scene object by type.
 * Implicit r14 = scene object pointer.
 * Type 1: push matrix, translate XYZ, rotate by angle, set LOD (billboard), pop.
 * Type 2: same as 1 but angle += 0x8000 (180°), uses alternate LOD function.
 * Type 3: translate from origin coords (obj+0x14,0x18,0x1C) instead of XYZ.
 * Type 4: same as 1, plus duplicates at two fixed offsets for repeating
 *   scenery (e.g., grandstands). Offsets conditional on track length >= 0x4EC/0x627. */
int FUN_06034168()
{
  int iVar1;
  int in_r7 = 0;
  int unaff_r14 = 0;
  int in_pr;

  iVar1 = (int)*(char *)(unaff_r14 + 0x00000001);
  if (iVar1 == 1) {
    (*(int(*)())0x06026DBC)();
    (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000004),*(int *)(unaff_r14 + 0x00000008),
               *(int *)(unaff_r14 + 0x0000000C),in_r7,in_pr);
    (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));
    (*(int(*)())0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));
    iVar1 = (*(int(*)())0x06026DF8)();
  }
  else if (iVar1 == 2) {
    (*(int(*)())0x06026DBC)();
    (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000004),*(int *)(unaff_r14 + 0x00000008),
               *(int *)(unaff_r14 + 0x0000000C),in_r7,in_pr);
    (*(int(*)())0x06026EDE)((int)(short)(*(short *)(unaff_r14 + 0x00000002) + (short)0x00008000));
    (*(int(*)())0x0600A4CA)((int)*(char *)(unaff_r14 + 0x00000011));
    iVar1 = (*(int(*)())0x06026DF8)();
  }
  else if (iVar1 == 3) {
    (*(int(*)())0x06026DBC)();
    (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000014),*(int *)(unaff_r14 + 0x00000018),
               *(int *)(unaff_r14 + 0x0000001C),in_r7,in_pr);
    (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));
    (*(int(*)())0x0600A4CA)((int)*(char *)(unaff_r14 + 0x00000011));
    iVar1 = (*(int(*)())0x06026DF8)();
  }
  else if (iVar1 == 4) {
    (*(int(*)())0x06026DBC)();
    (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000004),*(int *)(unaff_r14 + 0x00000008),
               *(int *)(unaff_r14 + 0x0000000C),in_r7,in_pr);
    (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));
    (*(int(*)())0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));
    (*(int(*)())0x06026DF8)();
    iVar1 = 0x000004EC;
    if (0x000004EC <= *(int *)0x06083250) {
      (*(int(*)())0x06026DBC)();
      (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000004) - (int)0x00280000,
                 *(int *)(unaff_r14 + 0x00000008),
                 *(int *)(unaff_r14 + 0x0000000C) - (int)0x003E0000,in_r7,in_pr);
      (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));
      (*(int(*)())0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));
      (*(int(*)())0x06026DF8)();
      iVar1 = 0x00000627;
      if (0x00000627 <= *(int *)0x06083250) {
        (*(int(*)())0x06026DBC)();
        (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000004) - (int)0x00190000,
                   *(int *)(unaff_r14 + 0x00000008),
                   *(int *)(unaff_r14 + 0x0000000C) - (int)0x001C0000,in_r7,in_pr);
        (*(int(*)())0x06026EDE)(*(short *)(unaff_r14 + 0x00000002) + 0x00000002);
        (*(int(*)())0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));
        iVar1 = (*(int(*)())0x06026DF8)();
      }
    }
  }
  return iVar1;
}

/* cd_clear_transfer_flags -- Clear status byte (+0x26) in all 5 CD transfer slots.
 * Each slot is 0x2C bytes. Resets transfer completion flags. */
void FUN_0603446c(void)
{
    int i;
    for (i = 0; i < 5; i++) {
        *(char *)((char *)DAT_06082A7C + i * 0x2C + 0x26) = 0;
    }
}

/* scene_object_visibility_check -- Check if static scene object is visible.
 * Implicit r14 = scene object pointer. Implicit r10 = scene data source.
 * Type 2 objects: computes distance from object position to camera
 * (stored at r10+0x10/0x18). If distance < 0x80000 (8.0 fixed),
 * marks obj+0x26 = 1 (visible). Returns obj type or visibility flag. */
char * FUN_0603449c()
{
  long long lVar1;
  char *puVar2;
  int iVar3;
  char *puVar4;
  int uVar5;
  unsigned int uVar6;
  int uVar7;
  int uVar8;
  int unaff_r10 = 0;
  int unaff_r14 = 0;

  puVar2 = (int *)0x06083238;
  puVar4 = (char *)(int)*(char *)(unaff_r14 + 0x00000001);
  if ((char *)(int)*(char *)(unaff_r14 + 0x00000001) == (void *)0x00000002) {
    uVar5 = *(int *)(unaff_r14 + 0x0000000C);
    uVar7 = *(int *)(unaff_r10 + 0x00000010);
    uVar8 = *(int *)(unaff_r10 + 0x00000018);
    *(int *)0x06083238 = *(int *)(unaff_r14 + 0x00000004);
    *(int *)(puVar2 + 4) = uVar5;
    *(int *)(puVar2 + 8) = uVar7;
    *(int *)(puVar2 + 0xc) = uVar8;
    lVar1 = (long long)(*(int *)(puVar2 + 8) - *(int *)puVar2) *
            (long long)(*(int *)(puVar2 + 8) - *(int *)puVar2);
    *(unsigned int *)(puVar2 + 0x10) = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
    lVar1 = (long long)(*(int *)(puVar2 + 0xc) - *(int *)(puVar2 + 4)) *
            (long long)(*(int *)(puVar2 + 0xc) - *(int *)(puVar2 + 4));
    uVar6 = *(int *)(puVar2 + 0x10) +
            ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);
    if ((int)uVar6 < 0) {
      iVar3 = (*(int(*)())0x06027476)(uVar6 >> 2);
      iVar3 = iVar3 << 1;
    }
    else {
      iVar3 = (*(int(*)())0x06027476)();
    }
    puVar2 = (int *)0x00000026;
    puVar4 = (char *)0x00080000;
    if (iVar3 < (int)0x00080000) {
      ((int *)0x00000026)[unaff_r14] = (char)0x00000001;
      puVar4 = puVar2;
    }
  }
  return puVar4;
}

/* scene_object_anim_start -- Begin animation on a scene object.
 * Implicit r14 = scene object pointer (0x06082A7C + index * 0x2C).
 * Implicit r10 = scene data source pointer.
 * Copies animation index from source+0x28, sets speed from source+0x0C<<1,
 * marks animation state at obj+0x26 = 2 (running). */
int FUN_06034560()
{
  int iVar1;
  int unaff_r10 = 0;
  int unaff_r14 = 0;

  *(short *)(unaff_r14 + 0x02) = (short)*(int *)(unaff_r10 + 0x28);
  *(int *)(unaff_r14 + 0x28) = *(int *)(unaff_r10 + 0x0C) << 1;
  iVar1 = 0x26;
  *(char *)(unaff_r14 + 0x26) = 2;
  return iVar1;
}

/* scene_object_anim_step -- Advance animated scene object position.
 * Implicit r14 = scene object pointer.
 * Computes X/Z displacement from angle (obj+0x02 + 0x4000) and speed (obj+0x28):
 *   obj.x += speed * sin(angle), obj.z += speed * cos(angle)
 * Writes position to global buffer 0x06083238, calls terrain height query
 * (0x06006838) and matrix transform (0x06027EDE), reads back Y height. */
int FUN_0603458c()
{
  long long lVar1;
  int iVar2;
  int uVar3;
  int in_r7 = 0;
  int iVar4;
  char *puVar5;
  int unaff_r14 = 0;
  int in_pr;

  puVar5 = 0x4000 + *(short *)(unaff_r14 + 0x02);  /* angle index */
  iVar4 = *(int *)(unaff_r14 + 0x28);                /* animation speed */
  iVar2 = (*(int(*)())0x06027344)(puVar5);            /* sin(angle) */
  lVar1 = (long long)iVar4 * (long long)iVar2;
  *(unsigned int *)(unaff_r14 + 0x04) =               /* obj.x += speed * sin */
       *(int *)(unaff_r14 + 0x04) +
       ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);
  iVar2 = (*(int(*)())0x06027348)(puVar5);            /* cos(angle) */
  lVar1 = (long long)iVar4 * (long long)iVar2;
  *(unsigned int *)(unaff_r14 + 0x0C) =               /* obj.z += speed * cos */
       *(int *)(unaff_r14 + 0x0C) +
       ((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);
  *(int *)0x06083238 = *(int *)(unaff_r14 + 0x04);   /* global X */
  *(int *)0x06083240 = *(int *)(unaff_r14 + 0x0C);   /* global Z */
  uVar3 = (*(int(*)())0x06006838)();                  /* terrain height query */
  (*(int(*)())0x06027EDE)(uVar3, 0x06083238, 0x06083244, in_r7, in_pr);
  iVar2 = 0x08;
  *(int *)(unaff_r14 + 0x08) = *(int *)0x0608323C;   /* obj.y = terrain height */
  return iVar2;
}

/* scene_object_render -- Render a scene object using its position and angle.
 * Implicit r14 = scene object pointer.
 * Pushes matrix (0x06026DBC), translates by obj X/Y/Z (0x06026E2E),
 * rotates by angle at obj+0x02 (0x06026EDE), sets LOD from obj+0x11
 * (0x0600A4CA), then pops/renders (0x06026DF8). */
int FUN_06034640()
{
  int uVar1;
  int in_r7 = 0;
  int unaff_r14 = 0;
  int in_pr;

  (*(int(*)())0x06026DBC)();                                       /* matrix push */
  (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x04),             /* translate X */
             *(int *)(unaff_r14 + 0x08),                           /* translate Y */
             *(int *)(unaff_r14 + 0x0C), in_r7, in_pr);           /* translate Z */
  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x02));     /* rotate by angle */
  (*(int(*)())0x0600A4CA)((int)*(char *)(unaff_r14 + 0x11));      /* set LOD level */
  uVar1 = (*(int(*)())0x06026DF8)();                               /* matrix pop / render */
  return uVar1;
}

/* scene_object_anim_advance -- Advance animation frame/variant counters.
 * Implicit r14 = scene object pointer.
 * Increments frame counter at obj+0x10. When frame reaches limit
 * (from table at 0x060631B4, indexed by obj[1]-1), resets frame to 0
 * and advances variant at obj+0x11. When variant reaches its limit
 * (from 0x060631B8), resets variant to 0 (loops animation). */
int FUN_060346c0()
{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int unaff_r14 = 0;

  iVar4 = 0x10;
  iVar3 = *(char *)(unaff_r14 + 0x01) + -1;        /* object type index */
  cVar1 = ((int *)0x060631B4)[iVar3];                /* frame limit for this type */
  cVar2 = ((int *)0x060631B8)[iVar3];                /* variant limit for this type */
  iVar3 = *(char *)(unaff_r14 + 0x10) + 1;          /* increment frame */
  *(char *)(unaff_r14 + 0x10) = (char)iVar3;
  if (cVar1 <= iVar3) {
    *(char *)(unaff_r14 + iVar4) = 0;               /* reset frame to 0 */
    iVar4 = 0x11;
    iVar3 = *(char *)(unaff_r14 + 0x11) + 1;        /* increment variant */
    if (cVar2 <= iVar3) {
      iVar3 = 0;                                     /* wrap variant to 0 */
    }
    *(char *)(unaff_r14 + 0x11) = (char)iVar3;
  }
  return iVar4;
}

/* cd_transfer_step -- Execute one step of CD data transfer.
 * Copies state+0x0C to state+0x10 (advance read position),
 * then runs: sector header parse, data validation, transfer completion.
 * Returns transfer status. */
int FUN_06034708(int state)
{
    *(int *)(state + 0x10) = *(int *)(state + 0x0C);
    FUN_06034754();
    FUN_060347a8();
    return FUN_06034848();
}

/* scene_object_wind_effect -- Compute wind sway phase from car speed.
 * Implicit r14 = scene object pointer.
 * Multiplies car Z speed (CAR_PTR_TARGET+0x08) by 300.0 fixed-point,
 * accumulates into obj+0x08. When >= 0x60000 (6.0), wraps to 0.
 * Extracts wind phase 0-7 from upper bits → obj+0x0C. */
int FUN_06034754()
{
  int iVar1;
  unsigned int uVar2;
  int unaff_r14 = 0;

  iVar1 = (*(int(*)())0x0602755C)(*(int *)(CAR_PTR_TARGET + 0x08) << 0x10, 0x012C0000);
  uVar2 = *(int *)(unaff_r14 + 0x08) + iVar1;
  if ((int)0x60000 <= (int)uVar2) {
    uVar2 = 0;
  }
  *(unsigned int *)(unaff_r14 + 0x08) = uVar2;
  iVar1 = 0x0C;
  *(unsigned int *)(unaff_r14 + 0x0C) = uVar2 >> 0x10 & 0x07;
  return iVar1;
}

/* scene_object_sway_update -- Update oscillation state for two sway channels.
 * Implicit r14 = scene object pointer.
 * Channel A (obj+0x00..0x02): triggers when wind phase (obj+0x0C) enters 1.
 *   Sets amplitude (obj+1) = -1, resets counter (obj+2). Counter increments
 *   each frame, phase = counter & 3. When phase==3, clears amplitude.
 * Channel B (obj+0x03..0x05): triggers when wind phase enters 5, same logic.
 * Used for tree/flag sway animations along the track. */
int FUN_060347a8()
{
  int iVar1;
  int iVar2;
  unsigned char bVar3;
  int unaff_r14 = 0;

  /* Channel A: trigger on wind phase transition to 1 */
  if ((*(int *)(unaff_r14 + 0x0C) == 1) && (*(int *)(unaff_r14 + 0x10) != 1)) {
    *(char *)(unaff_r14 + 0x01) = (char)0xFF;       /* amplitude = -1 (max sway) */
    *(char *)(unaff_r14 + 0x02) = 0;                 /* reset counter */
  }
  /* Channel B: trigger on wind phase transition to 5 */
  if ((*(int *)(unaff_r14 + 0x0C) == 5) && (*(int *)(unaff_r14 + 0x10) != 5)) {
    *(char *)(unaff_r14 + 0x04) = (char)0xFF;
    *(char *)(unaff_r14 + 0x05) = 0;
  }
  /* Advance channel A */
  bVar3 = *(char *)(unaff_r14 + 0x02) + 1;
  *(unsigned char *)(unaff_r14 + 0x02) = bVar3;
  bVar3 = bVar3 & 3;
  *(unsigned char *)(unaff_r14 + 0x00) = bVar3;     /* phase = counter & 3 */
  if (bVar3 == 3) {
    *(char *)(unaff_r14 + 0x01) = 0;                 /* stop sway */
  }
  /* Advance channel B */
  bVar3 = *(char *)(unaff_r14 + 0x05) + 1;
  *(unsigned char *)(unaff_r14 + 0x05) = bVar3;
  iVar2 = 0x03;
  bVar3 = bVar3 & 3;
  *(unsigned char *)(unaff_r14 + 0x03) = bVar3;
  iVar1 = 0x04;
  if (bVar3 == 3) {
    *(char *)(unaff_r14 + 0x04) = 0;
    iVar2 = iVar1;
  }
  return iVar2;
}

/* scene_object_sound_trigger -- Play wind/sway sound when phase changes.
 * Implicit r14 = scene object pointer.
 * If sound enabled (0x06083255 != 0) and game active (bits 0x28000),
 * and wind phase (obj+0x0C) changed from prev frame (obj+0x10):
 *   Select sound ID by phase and car speed vs DAT_0603489e threshold:
 *     phase 0,3,4,5: 0xAE113DFF (distant), 0xAE113CFF (medium), 0xAE113BFF (close)
 *   Dispatch via sound_cmd_dispatch(0, sound_id). */
unsigned int FUN_06034848()
{
  unsigned int uVar1;
  int uVar2;
  int unaff_r14 = 0;

  uVar1 = 0;
  if (((*(int *)0x06083255 != '\0') &&
      (uVar1 = GAME_STATE_BIT, (0x00028000 & uVar1) != 0)) &&
     (uVar1 = *(unsigned int *)(unaff_r14 + 0x0C),
      uVar1 != *(unsigned int *)(unaff_r14 + 0x10))) {
    uVar2 = 0xAE113DFF;                              /* default = distant sound */
    if (*(int *)(CAR_PTR_TARGET + 0x08) < (int)DAT_0603489e) {
      uVar1 = *(unsigned int *)(unaff_r14 + 0x0C);
      if (((uVar1 != 0) && (uVar2 = 0xAE113BFF, uVar1 != 3)) &&
         ((uVar2 = 0xAE113CFF, uVar1 != 4 && (uVar2 = 0xAE113DFF, uVar1 != 5)))) {
        return uVar1;
      }
    } else {
      uVar1 = *(unsigned int *)(unaff_r14 + 0x0C);
      if (((uVar1 != 0) && (uVar2 = 0xAE113BFF, uVar1 != 3)) &&
         (uVar2 = 0xAE113CFF, uVar1 != 4)) {
        return uVar1;
      }
    }
    uVar1 = (*(int(*)())0x0601D5F4)(0, uVar2);       /* sound_cmd_dispatch */
  }
  return uVar1;
}

int terrain_data_lookup(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int uVar1;

  unsigned int uVar2;

  int iVar3;

  int in_pr;

  iVar3 = CAR_PTR_TARGET;

  if ((*(int *)(iVar3 + 0x000000B8) == 0x2c) || (*(int *)(iVar3 + 0x000001BC) == 0x28)) {

    (*(int(*)())0x0601D5F4)(0x00000000,0xAE1128FF);

  }

  uVar2 = *(unsigned int *)(iVar3 + DAT_06034976);

  if ((int)uVar2 < 0) {

    uVar2 = -uVar2;

  }

  uVar2 = uVar2 >> 10;

  if (7 < uVar2) {

    uVar2 = 7;

  }

  uVar1 = (*(int(*)())0x0601D5F4)(2,uVar2,param_3,param_4,in_pr);

  return uVar1;

}

/* cd_init_and_seek -- Initialize CD status, clear command byte, seek to position.
 * Gets current status via cd_get_status, clears command byte,
 * calls cd_status_full_read, then seeks to param_1 via FUN_06035F04. */
int FUN_06034984(int param_1)
{
    int result;
    char buf[12];

    (*(int(*)())0x06035E90)(buf);  /* cd_get_status */
    buf[0] = 0;                     /* clear command */
    result = (*(int(*)())0x06035EC8)(0, buf);  /* cd_status_full_read */
    (*(int(*)())0x06035F04)(param_1);          /* seek */
    return result;
}

/* cd_check_ready -- Check if CD drive is in ready state.
 * Polls via FUN_06034a10; on success, unpacks status.
 * Returns -8 if drive reports specific error (DAT_06034a8e) or not ready
 * (bit 5 clear). Returns 0 on success, or error from FUN_06034a10. */
int FUN_060349c4(unsigned char *param_1)
{
    int err;
    char buf[12];

    err = FUN_06034a10(buf);
    if (err == 0) {
        (*(int(*)())0x06035F16)(buf, param_1);  /* cd_status_unpack */
        if (*param_1 == DAT_06034a8e || (*param_1 & 0x20) == 0) {
            err = -8;
        }
    }
    return err;
}

/* cd_register_verify -- Read CD register pair and verify consistency.
 * Reads register via 0x06035E5E into param_1 and a local copy.
 * Retries up to 100 times until both reads match (word 0 and word 1).
 * Returns 0 on match, -3 (0xFFFFFFFD) on timeout. */
int FUN_06034a10(int *param_1)
{
  int retries = 0;
  int local_24;
  int iStack_20;

  while (1) {
    (*(int(*)())0x06035E5E)(param_1);
    (*(int(*)())0x06035E5E)(&local_24);
    if ((*param_1 == local_24) && (param_1[1] == iStack_20)) break;
    retries = retries + 1;
    if (99 < retries) {
      return 0xfffffffd;            /* timeout error */
    }
  }
  return 0;
}

/* cd_read_toc -- Read CD table of contents into output buffer.
 * Sends CD status query (0x06035E90), sets command byte to 2 (read TOC),
 * issues command (0x06035EA2). On success, masks response to 24-bit sector
 * count and reads that many words via FUN_06035CBC into param_1. */
int FUN_06034aee(int param_1)
{
  int iVar1;
  unsigned int local_18[2];
  char local_10[12];

  (*(int(*)())0x06035E90)(local_10);
  local_10[0] = 2;                       /* TOC read command */
  iVar1 = (*(int(*)())0x06035EA2)(0, local_10, local_18);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (*(int(*)())0x06035CBC)(local_18[0] & 0x00FFFFFF, param_1);
  return iVar1;
}

/* cd_get_session_info -- Query CD session info for given session number.
 * Sends CD status query, sets command byte to 3 (session info),
 * session number in byte 1. Returns session data in *param_2. */
int FUN_06034b54(char param_1, int *param_2)
{
  int uVar1;
  char auStack_1c[4];
  int uStack_18;
  char local_14;
  char uStack_13;

  (*(int(*)())0x06035E90)(&local_14);
  local_14 = 3;                          /* session info command */
  uStack_13 = param_1;                   /* session number */
  uVar1 = (*(int(*)())0x06035EA2)(0, &local_14, auStack_1c);
  *param_2 = uStack_18;
  return uVar1;
}

/* cd_play_command -- Issue CD play/seek command with track parameters.
 * Builds 6-byte command packet: cmd=4, track=param_1, FAD=param_2,
 * play mode=param_3, repeat=param_4.
 * If (param_1 & 0x81) == 1: delay loop, set HIRQ bit 0x41, send with
 * flag 0x40, then reset HIRQ on success.
 * Otherwise: send command normally with flag 0. */
int FUN_06034b9a(unsigned int param_1, short param_2, char param_3, char param_4)
{
  int iVar1;
  char local_1c;
  char uStack_1b;
  short uStack_1a;
  char uStack_16;
  char uStack_15;

  (*(int(*)())0x06035E90)(&local_1c);
  local_1c = 4;                          /* play command */
  uStack_1b = (char)param_1;             /* track number */
  uStack_1a = param_2;                   /* FAD position */
  uStack_16 = param_3;                   /* play mode */
  uStack_15 = param_4;                   /* repeat flag */

  if ((0x81 & param_1) == 1) {
    for (iVar1 = (int)DAT_06034bf6; 0 < iVar1; iVar1 = iVar1 + -1) {
    }                                    /* busy-wait delay */
    (*(int(*)())0x06035C92)(0x41);       /* set HIRQ bit */
    iVar1 = (*(int(*)())0x06035EC8)(0x40, &local_1c);
    if (iVar1 == 0) {
      (*(int(*)())0x06035C80)();         /* reset HIRQ */
    }
  } else {
    iVar1 = (*(int(*)())0x06035EC8)(0, &local_1c);
  }
  return iVar1;
}

/* cd_tray_command -- Open or close the CD tray.
 * param_1=0: open (cmd 0x02), param_1=1: close (cmd 0x82).
 * Sends command via 0x06035E00, checks close response for disc-in bit.
 * On error, reads disc position via FUN_06034cc8.
 * Clears pending status with mask 0xFFFD via 0x06035C6E. */
int cd_tray_command(param_1)
    int param_1;
{
  int result;
  unsigned short status[2];
  char position_buf[8];

  if (param_1 == 0) {
    result = 2;                                         /* open tray command */
  } else {
    result = 0x82;                                      /* close tray command */
  }
  result = (*(int(*)())0x06035E00)(result, status);
  if (((param_1 == 1) && (result == 0)) && ((status[0] & 0x80) != 0)) {
    result = -4;                                        /* disc not inserted after close */
  }
  if (result != 0) {
    FUN_06034cc8(position_buf);                         /* read disc position on error */
  }
  (*(int(*)())0x06035C6E)(0x0000FFFD);                 /* clear pending status */
  return result;
}

/* cd_get_disc_position -- Read current disc FAD (frame address).
 * Gets status, sets command byte to 6 (get position),
 * calls cd_status_read, masks result to 24-bit FAD. */
int FUN_06034cc8(unsigned int *param_1)
{
    int result;
    unsigned int response[2];
    char buf[12];

    (*(int(*)())0x06035E90)(buf);
    buf[0] = 6;
    result = (*(int(*)())0x06035EA2)(0, buf, response);
    *param_1 = response[0] & 0x00FFFFFF;
    return result;
}

/* cd_extract_play_params -- Extract CD play parameters from track descriptor.
 * Dispatches by descriptor type (*param_1):
 *   0: call CD sync (0x06035228)
 *   1: FAD-based — set byte 0 = track|0x80, byte 1 = index, byte 2 = flag
 *   2: time-based — set byte 0 = 0, byte 1 = minute, byte 2 = second
 *   3: call CD sync and return immediately
 *   other: fall through to CD sync */
int FUN_06034d5e(int *param_1, unsigned char *param_2)
{
  unsigned char bVar1;
  int iVar2 = *param_1;

  if (iVar2 == 0) {
LAB_06034dac:
    iVar2 = (*(int(*)())0x06035228)();
  } else {
    if (iVar2 == 1) {
      *param_2 = *(unsigned char *)((int)param_1 + 5) | 0x80;
      param_2[1] = *(unsigned char *)((int)param_1 + 6);
      bVar1 = *(unsigned char *)((int)param_1 + 7);
    } else {
      if (iVar2 != 2) {
        if (iVar2 == 3) {
          iVar2 = (*(int(*)())0x06035228)();
          return iVar2;
        }
        goto LAB_06034dac;
      }
      *param_2 = 0;
      param_2[1] = *(unsigned char *)(param_1 + 1);
      bVar1 = *(unsigned char *)((int)param_1 + 5);
    }
    iVar2 = (int)(char)bVar1;
    param_2[2] = bVar1;
  }
  return iVar2;
}

/* cd_play_track -- Start CD audio playback for a track.
 * Gets status, sets command byte to 0x11 (play),
 * extracts play params via FUN_06034d5e, sends full status. */
void FUN_06034dea(int param_1)
{
    char buf[12];

    (*(int(*)())0x06035E90)(buf);
    buf[0] = 0x11;
    FUN_06034d5e(param_1, buf + 1);
    (*(int(*)())0x06035EC8)(0, buf);
    return;

}

/* FUN_06034f78: L2 version in bitfield_utils.c */
extern void FUN_06034F78(int val, int param, int ptr);
void FUN_06034f78(int val, int param, int ptr) { FUN_06034F78(val, param, ptr); }

int FUN_06034fe0()
{
  int in_r0 = 0;
  int in_r1 = 0;
  int *puVar1;

  puVar1 = (int *)-256;
  *puVar1 = in_r0;
  puVar1[2] = 0;
  puVar1[1] = in_r1;
  return puVar1[5];
}

int FUN_06034ffc()
{
  int bVar1;
  unsigned int uVar2;
  char cVar3;
  int bVar4;
  int bVar5;
  unsigned int uVar6;
  int in_r0 = 0;
  int in_r1 = 0;
  unsigned int uVar7;
  unsigned int uVar8;
  unsigned int uVar9;
  unsigned int uVar11;
  unsigned int uVar12;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;
  unsigned int uVar18;
  unsigned int uVar19;
  unsigned int uVar20;
  unsigned int uVar21;
  unsigned int uVar22;
  unsigned int uVar23;
  unsigned int uVar24;
  unsigned int uVar25;
  unsigned int uVar26;
  unsigned int uVar27;
  unsigned int uVar28;
  unsigned int uVar29;
  unsigned int uVar30;
  unsigned int uVar31;
  unsigned int uVar32;
  unsigned int uVar33;
  unsigned int uVar34;
  unsigned int uVar35;
  unsigned int uVar36;
  unsigned int uVar37;
  unsigned int uVar38;
  unsigned int uVar39;
  unsigned int uVar40;
  unsigned int uVar41;
  unsigned int uVar42;
  unsigned int uVar10;
  unsigned int uVar13;

  if (in_r0 != 0) {
    uVar6 = -(unsigned int)(in_r1 < 0);
    uVar7 = in_r1 - (unsigned int)(uVar6 != 0);
    bVar1 = in_r0 < 0;
    uVar2 = (unsigned int)bVar1 << 9;
    uVar12 = (uVar7 << 1);
    uVar7 = (unsigned int)(in_r1 < 0) * -2 | (unsigned int)((uVar7 & 0x80000000) != 0);
    bVar4 = (int)uVar6 < 0 == bVar1;
    bVar5 = bVar1 == ((uVar6 & 0x80000000) != 0);
    uVar8 = (unsigned int)bVar4 * (uVar7 - in_r0) + (unsigned int)!bVar4 * (uVar7 + in_r0);
    cVar3 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
    uVar7 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar13 = uVar2 | uVar7;
    uVar9 = (uVar8 << 1) | (unsigned int)((uVar12 & 0x80000000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar9 - in_r0) + (unsigned int)!bVar4 * (uVar9 + in_r0);
    cVar3 = bVar4 * (uVar9 < uVar10) + !bVar4 * (uVar10 < uVar9);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar14 = uVar2 | uVar7 & 0xfffffeff | uVar13;
    uVar9 = uVar2 | uVar7 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar15 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar16 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar17 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar18 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar19 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar20 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar21 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar22 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar23 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar24 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar25 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar26 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar27 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar28 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar29 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar30 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar31 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar32 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar33 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar34 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar35 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar36 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar37 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar38 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar39 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar40 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar41 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 8) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar42 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 4) != 0);
    bVar4 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar4 * (uVar11 - in_r0) + (unsigned int)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar11 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar12 = (uVar10 << 1) | (unsigned int)((uVar12 & 2) != 0);
    bVar4 = ((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1);
    bVar5 = (int)((unsigned char)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar13 = (unsigned int)bVar4 * (uVar12 - in_r0) + (unsigned int)!bVar4 * (uVar12 + in_r0);
    cVar3 = bVar4 * (uVar12 < uVar13) + !bVar4 * (uVar13 < uVar12);
    uVar13 = uVar9 | uVar8 & 0xfffffeff |
             (unsigned int)(unsigned char)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    return ((((((((((((((((((((((((((((((((unsigned int)(((unsigned char)((uVar2 | uVar7) >> 8) & 1) ==
                                                ((unsigned char)((uVar2 | uVar7) >> 9) & 1)) << 1 |
                                         (unsigned int)(((unsigned char)(uVar14 >> 8) & 1) ==
                                               ((unsigned char)(uVar14 >> 9) & 1))) << 1 |
                                        (unsigned int)(((unsigned char)(uVar15 >> 8) & 1) ==
                                              ((unsigned char)(uVar15 >> 9) & 1))) << 1 |
                                       (unsigned int)(((unsigned char)(uVar16 >> 8) & 1) == ((unsigned char)(uVar16 >> 9) & 1)
                                             )) << 1 |
                                      (unsigned int)(((unsigned char)(uVar17 >> 8) & 1) == ((unsigned char)(uVar17 >> 9) & 1))
                                      ) << 1 | (unsigned int)(((unsigned char)(uVar18 >> 8) & 1) ==
                                                     ((unsigned char)(uVar18 >> 9) & 1))) << 1 |
                                    (unsigned int)(((unsigned char)(uVar19 >> 8) & 1) == ((unsigned char)(uVar19 >> 9) & 1)))
                                    << 1 | (unsigned int)(((unsigned char)(uVar20 >> 8) & 1) ==
                                                 ((unsigned char)(uVar20 >> 9) & 1))) << 1 |
                                  (unsigned int)(((unsigned char)(uVar21 >> 8) & 1) == ((unsigned char)(uVar21 >> 9) & 1))) <<
                                  1 | (unsigned int)(((unsigned char)(uVar22 >> 8) & 1) == ((unsigned char)(uVar22 >> 9) & 1))
                                 ) << 1 | (unsigned int)(((unsigned char)(uVar23 >> 8) & 1) ==
                                                ((unsigned char)(uVar23 >> 9) & 1))) << 1 |
                               (unsigned int)(((unsigned char)(uVar24 >> 8) & 1) == ((unsigned char)(uVar24 >> 9) & 1))) << 1
                              | (unsigned int)(((unsigned char)(uVar25 >> 8) & 1) == ((unsigned char)(uVar25 >> 9) & 1))) << 1
                             | (unsigned int)(((unsigned char)(uVar26 >> 8) & 1) == ((unsigned char)(uVar26 >> 9) & 1))) << 1
                            | (unsigned int)(((unsigned char)(uVar27 >> 8) & 1) == ((unsigned char)(uVar27 >> 9) & 1))) << 1 |
                           (unsigned int)(((unsigned char)(uVar28 >> 8) & 1) == ((unsigned char)(uVar28 >> 9) & 1))) << 1 |
                          (unsigned int)(((unsigned char)(uVar29 >> 8) & 1) == ((unsigned char)(uVar29 >> 9) & 1))) << 1 |
                         (unsigned int)(((unsigned char)(uVar30 >> 8) & 1) == ((unsigned char)(uVar30 >> 9) & 1))) << 1 |
                        (unsigned int)(((unsigned char)(uVar31 >> 8) & 1) == ((unsigned char)(uVar31 >> 9) & 1))) << 1 |
                       (unsigned int)(((unsigned char)(uVar32 >> 8) & 1) == ((unsigned char)(uVar32 >> 9) & 1))) << 1 |
                      (unsigned int)(((unsigned char)(uVar33 >> 8) & 1) == ((unsigned char)(uVar33 >> 9) & 1))) << 1 |
                     (unsigned int)(((unsigned char)(uVar34 >> 8) & 1) == ((unsigned char)(uVar34 >> 9) & 1))) << 1 |
                    (unsigned int)(((unsigned char)(uVar35 >> 8) & 1) == ((unsigned char)(uVar35 >> 9) & 1))) << 1 |
                   (unsigned int)(((unsigned char)(uVar36 >> 8) & 1) == ((unsigned char)(uVar36 >> 9) & 1))) << 1 |
                  (unsigned int)(((unsigned char)(uVar37 >> 8) & 1) == ((unsigned char)(uVar37 >> 9) & 1))) << 1 |
                 (unsigned int)(((unsigned char)(uVar38 >> 8) & 1) == ((unsigned char)(uVar38 >> 9) & 1))) << 1 |
                (unsigned int)(((unsigned char)(uVar39 >> 8) & 1) == ((unsigned char)(uVar39 >> 9) & 1))) << 1 |
               (unsigned int)(((unsigned char)(uVar40 >> 8) & 1) == ((unsigned char)(uVar40 >> 9) & 1))) << 1 |
              (unsigned int)(((unsigned char)(uVar41 >> 8) & 1) == ((unsigned char)(uVar41 >> 9) & 1))) << 1 |
             (unsigned int)(((unsigned char)(uVar42 >> 8) & 1) == ((unsigned char)(uVar42 >> 9) & 1))) << 1 |
            (unsigned int)(((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1))) << 1 |
           (unsigned int)(((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1))) +
           (unsigned int)(bVar1 != (int)uVar6 < 0);
  }
  *(int *)0x060A246C = 0x0000044E;
  return 0;
}

long long FUN_060350b0()
{
  char cVar1;
  int bVar2;
  int bVar3;
  int bVar4;
  unsigned char bVar5;
  unsigned int uVar6;
  char *puVar7;
  int in_r0 = 0;
  unsigned int in_r1 = 0;
  unsigned int uVar8;
  unsigned int uVar10;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;
  unsigned int uVar18;
  unsigned int uVar19;
  unsigned int uVar20;
  unsigned int uVar21;
  unsigned int uVar22;
  unsigned int uVar23;
  unsigned int uVar24;
  unsigned int uVar25;
  unsigned int uVar26;
  unsigned int uVar27;
  unsigned int uVar28;
  unsigned int uVar29;
  unsigned int uVar30;
  unsigned int uVar31;
  unsigned int uVar32;
  unsigned int uVar33;
  unsigned int uVar34;
  unsigned int uVar35;
  unsigned int uVar36;
  unsigned int uVar37;
  unsigned int uVar38;
  unsigned int uVar39;
  unsigned int uVar40;
  unsigned int uVar41;
  unsigned int uVar9;
  unsigned int uVar11;

  puVar7 = (char *)0x060A246C;
  if (in_r0 == 0) {
    *(int *)0x060A246C = 0x0000044E;
    return ZEXT48(puVar7) << 0x20;
  }
  uVar8 = (unsigned int)((in_r1 & 0x80000000) != 0);
  uVar9 = uVar8 - in_r0;
  bVar4 = uVar9 <= uVar8;
  uVar13 = in_r1 << 2;
  bVar3 = (uVar9 & 0x80000000) == 0;
  uVar8 = (uVar9 << 1) | (unsigned int)((in_r1 & 0x40000000) != 0);
  uVar9 = (unsigned int)bVar4 * (uVar8 - in_r0) + (unsigned int)!bVar4 * (uVar8 + in_r0);
  cVar1 = bVar4 * (uVar8 < uVar9) + !bVar4 * (uVar9 < uVar8);
  bVar5 = bVar3 * cVar1 + (!bVar3 && cVar1 == '\0');
  uVar8 = (unsigned int)bVar5 << 8;
  uVar10 = (uVar9 << 1) | (unsigned int)((uVar13 & 0x80000000) != 0);
  bVar3 = (bVar5 & 1) == ((unsigned char)(uVar8 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar10 - in_r0) + (unsigned int)!bVar3 * (uVar10 + in_r0);
  cVar1 = bVar3 * (uVar10 < uVar11) + !bVar3 * (uVar11 < uVar10);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar14 = uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar8 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x40000000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar15 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x20000000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar16 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x10000000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar17 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x8000000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar18 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x4000000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar19 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x2000000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar20 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x1000000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar21 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x800000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar22 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x400000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar23 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x200000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar24 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x100000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar25 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x80000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar26 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x40000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar27 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x20000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar28 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x10000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar29 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x8000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar30 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x4000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar31 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x2000) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar32 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x1000) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar33 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x800) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar34 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x400) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar35 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x200) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar36 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x100) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar37 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x80) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar38 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x40) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar39 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x20) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar40 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 0x10) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar10 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar41 = uVar6 | uVar9 & 0xfffffeff | uVar10;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar10;
  uVar12 = (uVar11 << 1) | (unsigned int)((uVar13 & 8) != 0);
  bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar11 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
  cVar1 = bVar3 * (uVar12 < uVar11) + !bVar3 * (uVar11 < uVar12);
  uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar12 = uVar6 | uVar10 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar10 & 0xfffffefe;
  uVar10 = uVar6 | uVar9;
  uVar8 = ((((((((((((((((((((((((((((((unsigned int)bVar4 << 1 |
                                      (unsigned int)((bVar5 & 1) == ((unsigned char)(uVar8 >> 9) & 1))) << 1 |
                                     (unsigned int)(((unsigned char)(uVar14 >> 8) & 1) == ((unsigned char)(uVar14 >> 9) & 1)))
                                     << 1 | (unsigned int)(((unsigned char)(uVar15 >> 8) & 1) ==
                                                  ((unsigned char)(uVar15 >> 9) & 1))) << 1 |
                                   (unsigned int)(((unsigned char)(uVar16 >> 8) & 1) == ((unsigned char)(uVar16 >> 9) & 1)))
                                   << 1 | (unsigned int)(((unsigned char)(uVar17 >> 8) & 1) ==
                                                ((unsigned char)(uVar17 >> 9) & 1))) << 1 |
                                 (unsigned int)(((unsigned char)(uVar18 >> 8) & 1) == ((unsigned char)(uVar18 >> 9) & 1))) <<
                                 1 | (unsigned int)(((unsigned char)(uVar19 >> 8) & 1) == ((unsigned char)(uVar19 >> 9) & 1)))
                                << 1 | (unsigned int)(((unsigned char)(uVar20 >> 8) & 1) == ((unsigned char)(uVar20 >> 9) & 1)
                                             )) << 1 |
                              (unsigned int)(((unsigned char)(uVar21 >> 8) & 1) == ((unsigned char)(uVar21 >> 9) & 1))) << 1 |
                             (unsigned int)(((unsigned char)(uVar22 >> 8) & 1) == ((unsigned char)(uVar22 >> 9) & 1))) << 1 |
                            (unsigned int)(((unsigned char)(uVar23 >> 8) & 1) == ((unsigned char)(uVar23 >> 9) & 1))) << 1 |
                           (unsigned int)(((unsigned char)(uVar24 >> 8) & 1) == ((unsigned char)(uVar24 >> 9) & 1))) << 1 |
                          (unsigned int)(((unsigned char)(uVar25 >> 8) & 1) == ((unsigned char)(uVar25 >> 9) & 1))) << 1 |
                         (unsigned int)(((unsigned char)(uVar26 >> 8) & 1) == ((unsigned char)(uVar26 >> 9) & 1))) << 1 |
                        (unsigned int)(((unsigned char)(uVar27 >> 8) & 1) == ((unsigned char)(uVar27 >> 9) & 1))) << 1 |
                       (unsigned int)(((unsigned char)(uVar28 >> 8) & 1) == ((unsigned char)(uVar28 >> 9) & 1))) << 1 |
                      (unsigned int)(((unsigned char)(uVar29 >> 8) & 1) == ((unsigned char)(uVar29 >> 9) & 1))) << 1 |
                     (unsigned int)(((unsigned char)(uVar30 >> 8) & 1) == ((unsigned char)(uVar30 >> 9) & 1))) << 1 |
                    (unsigned int)(((unsigned char)(uVar31 >> 8) & 1) == ((unsigned char)(uVar31 >> 9) & 1))) << 1 |
                   (unsigned int)(((unsigned char)(uVar32 >> 8) & 1) == ((unsigned char)(uVar32 >> 9) & 1))) << 1 |
                  (unsigned int)(((unsigned char)(uVar33 >> 8) & 1) == ((unsigned char)(uVar33 >> 9) & 1))) << 1 |
                 (unsigned int)(((unsigned char)(uVar34 >> 8) & 1) == ((unsigned char)(uVar34 >> 9) & 1))) << 1 |
                (unsigned int)(((unsigned char)(uVar35 >> 8) & 1) == ((unsigned char)(uVar35 >> 9) & 1))) << 1 |
               (unsigned int)(((unsigned char)(uVar36 >> 8) & 1) == ((unsigned char)(uVar36 >> 9) & 1))) << 1 |
              (unsigned int)(((unsigned char)(uVar37 >> 8) & 1) == ((unsigned char)(uVar37 >> 9) & 1))) << 1 |
             (unsigned int)(((unsigned char)(uVar38 >> 8) & 1) == ((unsigned char)(uVar38 >> 9) & 1))) << 1 |
            (unsigned int)(((unsigned char)(uVar39 >> 8) & 1) == ((unsigned char)(uVar39 >> 9) & 1))) << 1 |
           (unsigned int)(((unsigned char)(uVar40 >> 8) & 1) == ((unsigned char)(uVar40 >> 9) & 1))) << 1 |
          (unsigned int)(((unsigned char)(uVar41 >> 8) & 1) == ((unsigned char)(uVar41 >> 9) & 1))) << 1 |
          (unsigned int)(((unsigned char)(uVar12 >> 8) & 1) == ((unsigned char)(uVar12 >> 9) & 1));
  uVar13 = (uVar11 << 1) | (unsigned int)((uVar13 & 4) != 0);
  bVar3 = ((unsigned char)(uVar10 >> 8) & 1) == ((unsigned char)(uVar10 >> 9) & 1);
  bVar2 = (int)((unsigned char)(uVar10 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
  uVar10 = (unsigned int)bVar3 * (uVar13 - in_r0) + (unsigned int)!bVar3 * (uVar13 + in_r0);
  cVar1 = bVar3 * (uVar13 < uVar10) + !bVar3 * (uVar10 < uVar13);
  uVar9 = uVar6 | uVar9 & 0xfffffeff | (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  if (((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1)) {
    return CONCAT44(uVar8,uVar10);
  }
  return CONCAT44(uVar8,in_r0 + uVar10);
}

void FUN_06035168()
{
  unsigned int in_r0 = 0;
  int *in_r1;
  int *in_r2;
  int *puVar1;
  int *puVar2;

  if (in_r0 < 0x41) {
    (*(int(*)())(*(int *)(0x060351C4 + in_r0)))();
    return;
  }
  puVar2 = (int *)((int)in_r2 + in_r0);
  while( 1 ) {
    puVar1 = in_r2 + 1;
    if (puVar2 < puVar1) {
      return;
    }
    *in_r1 = *in_r2;
    in_r2 = in_r2 + 2;
    if (puVar2 < in_r2) break;
    in_r1[1] = *puVar1;
    in_r1 = in_r1 + 2;
  }
  return;
}

void FUN_06035228()
{
  int in_r0 = 0;
  char *in_r1;
  char *in_r2;
  char *puVar1;
  char *puVar2;

  if (in_r0 != 0) {
    puVar2 = in_r2 + in_r0;
    do {
      *in_r1 = *in_r2;
      if (puVar2 <= in_r2 + 1) {
        return;
      }
      in_r1[1] = in_r2[1];
      if (puVar2 <= in_r2 + 2) {
        return;
      }
      puVar1 = in_r2 + 3;
      in_r1[2] = in_r2[2];
      if (puVar2 <= puVar1) {
        return;
      }
      in_r2 = in_r2 + 4;
      in_r1[3] = *puVar1;
      in_r1 = in_r1 + 4;
    } while (in_r2 < puVar2);
  }
  return;
}

int FUN_06035280()
{
  int in_r0 = 0;
  int uVar1;
  int in_r1 = 0;

  if (in_r1 < 0) {
    return in_r0;
  }
  if (in_r1 < 0x20) {
    uVar1 = (*(int(*)())(0x060352AA + (char)((int *)0x06035260)[in_r1]))();
    return uVar1;
  }
  return 0;
}

unsigned int FUN_06035340()
{
  unsigned int in_r0 = 0;
  unsigned int uVar1;
  int in_r1 = 0;

  if (in_r1 < 0) {
    return in_r0;
  }
  if (in_r1 < 0x20) {
    if (((in_r0 & 0x80000000) == 0) && (8 < in_r1)) {
      uVar1 = (*(int(*)())0x06036068)();
      return uVar1;
    }
    uVar1 = (*(int(*)())(0x060353BE + (char)((int *)0x06035338)[in_r1 + -0x18]))();
    return uVar1;
  }
  if ((in_r0 & 0x80000000) == 0) {
    return 0;
  }
  return 0xffffffff;
}

int FUN_06035460()
{
  long long lVar1;
  long long lVar2;
  int bVar3;
  int in_r0 = 0;
  int iVar4;
  unsigned int uVar5;
  unsigned int uVar6;
  char *puVar8;
  char *puVar9;
  char *puVar10;
  unsigned int uVar11;
  unsigned int uVar12;
  char *puVar13;
  char *puVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int *in_stack_00000000;
  unsigned int in_stack_00000004 = 0;
  char *in_stack_00000008;
  unsigned int in_stack_0000000c = 0;
  char *in_stack_00000010;
  unsigned int uVar7;

  uVar5 = in_stack_0000000c << 1 | (unsigned int)((in_stack_0000000c & 0x80000000) != 0);
  uVar11 = (in_stack_00000004 ^ 0x80000000) << 1 |
           (unsigned int)(((in_stack_00000004 ^ 0x80000000) & 0x80000000) != 0);
  uVar7 = uVar5;
  puVar9 = in_stack_00000010;
  if (uVar5 < uVar11) {
    uVar7 = uVar11;
    puVar9 = in_stack_00000008;
    uVar11 = uVar5;
    in_stack_00000008 = in_stack_00000010;
  }
  uVar5 = uVar7 << 0x1f;
  uVar6 = uVar7 >> 1 | uVar5;
  uVar7 = uVar11 << 0x1f;
  uVar12 = uVar11 >> 1 | uVar7;
  uVar11 = uVar6 >> 0x14 & 0x000007FF;
  uVar16 = uVar12 >> 0x14 & 0x000007FF;
  puVar8 = (char *)(uVar6 & 0x000FFFFF);
  puVar13 = (char *)(uVar12 & 0x000FFFFF);
  if (uVar11 == 0x000007FF) {
    if (((puVar8 != (char *)0x0) || (puVar9 != (char *)0x0)) ||
       ((uVar16 == 0x000007FF &&
        ((in_stack_00000008 != (char *)0x0 || ((uVar5 != 0) != (uVar7 != 0))))))) {
      uVar6 = 0;
      puVar8 = (char *)0x0;
      puVar9 = (void *)0x00000008;
    }
    goto LAB_060356ca;
  }
  uVar15 = uVar11;
  if (uVar16 == 0) {
    if (uVar11 == 0) {
      if ((puVar8 == (char *)0x0) && (puVar9 == (char *)0x0)) {
        if (in_stack_00000008 == (char *)0x0) {
          uVar6 = uVar6 & uVar12;
          goto LAB_060356ca;
        }
        uVar11 = 0;
        puVar8 = puVar13;
        puVar9 = in_stack_00000008;
        uVar6 = uVar12;
      }
      else if ((puVar13 != (char *)0x0) || (in_stack_00000008 != (char *)0x0)) {
        for (puVar8 = (char *)((int)(int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0));
            puVar9 = (char *)((int)(int)puVar9 << 1), (int)puVar8 < (int)0x00100000;
            puVar8 = (char *)((int)(int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0))) {
          uVar11 = uVar11 - 1;
        }
        goto LAB_060354ee;
      }
    }
    else if ((puVar13 != (char *)0x0) || (in_stack_00000008 != (char *)0x0)) {
LAB_060354ee:
      for (puVar13 = (char *)
                     ((int)(int)puVar13 << 1 | (unsigned int)(((unsigned int)in_stack_00000008 & 0x80000000) != 0));
          in_stack_00000008 = (char *)((int)(int)in_stack_00000008 << 1), uVar15 = uVar11,
          (int)puVar13 < (int)0x00100000;
          puVar13 = (char *)
                    ((int)(int)puVar13 << 1 | (unsigned int)(((unsigned int)in_stack_00000008 & 0x80000000) != 0))) {
        uVar16 = uVar16 - 1;
      }
      goto LAB_0603556e;
    }
    uVar7 = (unsigned int)puVar9 & 0x80000000;
    uVar5 = (unsigned int)puVar9 & 0x40000000;
    uVar16 = (unsigned int)puVar9 & 0x20000000;
    puVar9 = (char *)((int)(int)puVar9 << 3);
    puVar8 = (char *)
             ((((int)(int)puVar8 << 1 | (unsigned int)(uVar7 != 0)) << 1 | (unsigned int)(uVar5 != 0)) << 1 |
             (unsigned int)(uVar16 != 0));
  }
  else {
LAB_0603556e:
    puVar10 = (char *)((int)((int)(int)puVar9 << 3));
    puVar14 = (char *)((int)(int)in_stack_00000008 << 3);
    puVar9 = (char *)
             ((((int)(int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0)) << 1 |
              (unsigned int)(((unsigned int)puVar9 & 0x40000000) != 0)) << 1 |
              (unsigned int)(((unsigned int)puVar9 & 0x20000000) != 0) | (unsigned int)0x00800000);
    puVar8 = (char *)
             ((((int)(int)puVar13 << 1 | (unsigned int)(((unsigned int)in_stack_00000008 & 0x80000000) != 0)) << 1 |
              (unsigned int)(((unsigned int)in_stack_00000008 & 0x40000000) != 0)) << 1 |
              (unsigned int)(((unsigned int)in_stack_00000008 & 0x20000000) != 0) | (unsigned int)0x00800000);
    iVar4 = uVar15 - uVar16;
    if (iVar4 != 0) {
      if (iVar4 < 4) {
        do {
          uVar11 = (unsigned int)puVar8 & 1;
          puVar8 = (char *)((unsigned int)puVar8 >> 1);
          puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar11 == 1) * -0x80000000);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      else if (iVar4 < 0x37) {
        if (0x20 < iVar4) {
          iVar4 = iVar4 + -0x20;
          bVar3 = puVar14 != (char *)0x0;
          puVar14 = puVar8;
          if (bVar3) {
            puVar14 = (char *)((unsigned int)puVar8 | 1);
          }
          puVar8 = (char *)0x0;
        }
        lVar1 = ZEXT48(puVar14) * (unsigned long long)*(unsigned int *)(&DAT_06035734 + (iVar4 << 2));
        lVar2 = ZEXT48(puVar8) * (unsigned long long)*(unsigned int *)(&DAT_06035734 + (iVar4 << 2));
        puVar8 = (char *)((unsigned long long)lVar2 >> 0x20);
        puVar14 = (char *)((unsigned int)((unsigned long long)lVar1 >> 0x20) | (unsigned int)lVar2);
        if ((int)lVar1 != 0) {
          puVar14 = (char *)((unsigned int)puVar14 | 1);
        }
      }
      else {
        puVar8 = (char *)0x0;
        puVar14 = (void *)0x00000001;
      }
    }
    if ((uVar5 != 0) == (uVar7 != 0)) {
      puVar14 = puVar10 + (int)puVar14;
      puVar8 = puVar9 + (int)puVar8 + (puVar14 < puVar10);
      uVar11 = uVar15;
      if ((int)0x01000000 <= (int)puVar8) {
        uVar7 = (unsigned int)puVar8 & 1;
        puVar8 = (char *)((unsigned int)puVar8 >> 1);
        uVar11 = uVar15 + 1;
        puVar14 = (char *)
                  ((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000 |
                  (unsigned int)(((unsigned int)puVar14 & 1) != 0));
        if (uVar11 == 0x000007FF) {
          puVar8 = (char *)0x0;
          puVar9 = (char *)0x0;
          goto LAB_060356ca;
        }
      }
    }
    else {
      if ((puVar8 == puVar9) && (puVar14 == puVar10)) {
        uVar6 = 0;
        uVar11 = 0;
        puVar8 = (char *)0x0;
        puVar9 = (char *)0x0;
        goto LAB_060356ca;
      }
      puVar13 = puVar10 + -(int)puVar14;
      puVar14 = puVar9 + -(int)puVar8;
      puVar8 = puVar14 + -(unsigned int)(puVar10 < puVar13);
      if (puVar9 < puVar14 || puVar14 < puVar8) {
        puVar13 = (char *)-(int)puVar13;
        puVar8 = (char *)(-(unsigned int)(puVar13 != (char *)0x0) - (int)puVar8);
        uVar6 = uVar12;
      }
      puVar9 = puVar13;
      if (puVar8 == (char *)0x0) {
        puVar9 = (char *)0x0;
        uVar15 = uVar15 - 0x20;
        puVar8 = puVar13;
      }
      if (((unsigned int)puVar8 & 0xFFFF0000) == 0) {
        puVar8 = (char *)((int)(int)puVar8 << 0x10 | (unsigned int)puVar9 >> 0x10);
        puVar9 = (char *)((int)(int)puVar9 << 0x10);
        uVar15 = uVar15 - 0x10;
      }
      puVar13 = puVar8;
      if (puVar8 < 0x01000000) {
        for (; puVar14 = puVar9, uVar11 = uVar15, (int)puVar8 < (int)0x00800000;
            puVar8 = (char *)((int)(int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar14 & 0x80000000) != 0))) {
          puVar14 = (char *)((int)(int)puVar9 << 1);
          puVar8 = (char *)((int)(int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0));
          uVar11 = uVar15 - 1;
          if ((int)0x00800000 <= (int)puVar8) break;
          uVar7 = (unsigned int)puVar14 & 0x80000000;
          puVar14 = (char *)((int)(int)puVar9 << 2);
          puVar8 = (char *)((int)(int)puVar8 << 1 | (unsigned int)(uVar7 != 0));
          uVar11 = uVar15 - 2;
          if ((int)0x00800000 <= (int)puVar8) break;
          uVar7 = (unsigned int)puVar14 & 0x80000000;
          puVar14 = (char *)((int)(int)puVar9 << 3);
          puVar8 = (char *)((int)(int)puVar8 << 1 | (unsigned int)(uVar7 != 0));
          uVar11 = uVar15 - 3;
          if ((int)0x00800000 <= (int)puVar8) break;
          puVar9 = (char *)((int)(int)puVar9 << 4);
          uVar15 = uVar15 - 4;
        }
      }
      else {
        do {
          puVar8 = (char *)((unsigned int)puVar13 >> 1);
          puVar14 = (char *)
                    ((unsigned int)puVar9 >> 1 | (unsigned int)(((unsigned int)puVar13 & 1) == 1) * -0x80000000);
          uVar11 = uVar15 + 1;
          if (puVar8 < 0x01000000) break;
          uVar7 = (unsigned int)puVar8 & 1;
          puVar8 = (char *)((unsigned int)puVar13 >> 2);
          puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);
          uVar11 = uVar15 + 2;
          if (puVar8 < 0x01000000) break;
          uVar7 = (unsigned int)puVar8 & 1;
          puVar8 = (char *)((unsigned int)puVar13 >> 3);
          puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);
          uVar11 = uVar15 + 3;
          if (puVar8 < 0x01000000) break;
          uVar7 = (unsigned int)puVar8 & 1;
          puVar8 = (char *)((unsigned int)puVar13 >> 4);
          puVar9 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);
          uVar15 = uVar15 + 4;
          puVar13 = puVar8;
          puVar14 = puVar9;
          uVar11 = uVar15;
        } while (0x01000000 <= puVar8);
      }
    }
    if ((int)uVar11 < 1) {
      iVar4 = 1 - uVar11;
      do {
        uVar7 = (unsigned int)puVar8 & 1;
        puVar8 = (char *)((unsigned int)puVar8 >> 1);
        puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);
        iVar4 = iVar4 + -1;
        uVar11 = 0;
      } while (iVar4 != 0);
    }
    puVar9 = puVar14;
    if ((((unsigned int)puVar14 & 4) != 0) && (((unsigned int)puVar14 & 0xb) != 0)) {
      puVar9 = puVar14 + 8;
      puVar8 = puVar8 + (puVar9 < puVar14);
      if ((int)0x01000000 <= (int)puVar8) {
        uVar7 = (unsigned int)puVar8 & 1;
        puVar8 = (char *)((unsigned int)puVar8 >> 1);
        puVar9 = (char *)((unsigned int)puVar9 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);
        uVar11 = uVar11 + 1;
      }
    }
  }
LAB_060356ca:
  *in_stack_00000000 =
       (unsigned int)puVar8 >> 3 & 0x000FFFFF | (uVar11 & 0x7ff) << 0x14 |
       (unsigned int)((uVar6 & 0x80000000) != 0) * -0x80000000;
  in_stack_00000000[1] =
       (((unsigned int)puVar9 >> 1 | (unsigned int)(((unsigned int)puVar8 & 1) == 1) * -0x80000000) >> 1 |
       (unsigned int)(((unsigned int)puVar8 >> 1 & 1) == 1) * -0x80000000) >> 1 |
       (unsigned int)(((unsigned int)puVar8 >> 2 & 1) == 1) * -0x80000000;
  return in_r0;
}

long long FUN_060357b8()
{
  unsigned int uVar1;
  unsigned int uVar2;
  int in_r1 = 0;
  int iVar3;
  int iVar4;
  unsigned int in_stack_00000000 = 0;
  unsigned int in_stack_00000004 = 0;

  iVar3 = (in_stack_00000000 >> 0x14 & 0x000007FF) - 0x000003FF;
  if ((iVar3 < 0) || (0x53 < iVar3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = in_stack_00000000 & 0x000FFFFF | (unsigned int)0x00100000;
    iVar4 = iVar3 + -0x14;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      do {
        iVar4 = iVar4 + -1;
        uVar2 = uVar2 >> 1;
      } while (iVar4 != 0);
    }
    else if (iVar4 < 0x20) {
      iVar3 = iVar3 + -0x13;
      while (iVar3 = iVar3 + -1, iVar3 != 0) {
        uVar1 = in_stack_00000004 & 0x80000000;
        in_stack_00000004 = in_stack_00000004 << 1;
        uVar2 = uVar2 << 1 | (unsigned int)(uVar1 != 0);
      }
    }
    else {
      uVar2 = in_stack_00000004;
      for (iVar3 = iVar3 + -0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
        uVar2 = uVar2 << 1;
      }
    }
    if ((in_stack_00000000 & 0x80000000) != 0) {
      uVar2 = -uVar2;
    }
  }
  return CONCAT44(in_r1,uVar2);
}

int FUN_06035844()
{
  int bVar1;
  unsigned int in_stack_00000000 = 0;
  unsigned int in_stack_00000004 = 0;
  unsigned int in_stack_00000008 = 0;
  unsigned int in_stack_0000000c = 0;

  if ((((in_stack_00000008 & 0x7FF00000) == 0x7FF00000) &&
      (((in_stack_00000008 & 0x000FFFFF) != 0 || (in_stack_0000000c != 0)))) ||
     (((in_stack_00000000 & 0x7FF00000) == 0x7FF00000 &&
      (((in_stack_00000000 & 0x000FFFFF) != 0 || (in_stack_00000004 != 0)))))) {
    bVar1 = 0;
  }
  else if (((((in_stack_00000008 & 0x7FF00000) == 0) && ((in_stack_00000000 & 0x7FF00000) == 0))
           && ((in_stack_00000008 & 0x000FFFFF) == 0)) &&
          (((in_stack_0000000c == 0 && ((in_stack_00000000 & 0x000FFFFF) == 0)) &&
           (in_stack_00000004 == 0)))) {
    bVar1 = 0;
  }
  else if ((int)in_stack_00000008 < 0 == (int)in_stack_00000000 < 0) {
    if (-1 < (int)in_stack_00000008) {
      in_stack_00000008 = in_stack_00000000 - in_stack_00000008;
      bVar1 = in_stack_00000000 < in_stack_00000008 ||
              in_stack_00000008 <
              in_stack_00000008 - (in_stack_00000004 < in_stack_00000004 - in_stack_0000000c);
    }
    else {
      in_stack_00000004 = in_stack_0000000c - in_stack_00000004;
      in_stack_00000000 = in_stack_00000008 - in_stack_00000000;
      bVar1 = in_stack_00000008 < in_stack_00000000 ||
              in_stack_00000000 <
              in_stack_00000000 -
              (in_stack_0000000c < in_stack_00000004 ||
              in_stack_00000004 < in_stack_00000004 - (-1 < (int)in_stack_00000008));
    }
  }
  else {
    bVar1 = -1 < (int)in_stack_00000008;
  }
  return bVar1;
}

void FUN_060358ec()
{
  unsigned int in_r0 = 0;
  unsigned int uVar1;
  unsigned int uVar2;
  int iVar3;
  unsigned int uVar4;
  unsigned int *in_stack_00000000;

  if (in_r0 == 0) {
    uVar4 = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = in_r0;
    iVar3 = 0x0000041F;
    if ((int)in_r0 < 0) {
      uVar2 = -in_r0;
    }
    do {
      uVar1 = uVar2;
      iVar3 = iVar3 + -1;
      uVar2 = uVar1 << 1;
    } while ((uVar1 & 0x80000000) == 0);
    uVar4 = uVar1 << 0x15;
    uVar2 = (uVar1 << 1) >> 0xc | (iVar3 << 20) & 0x7fffffffU |
            (unsigned int)((int)in_r0 < 0) * -0x80000000;
  }
  *in_stack_00000000 = uVar2;
  in_stack_00000000[1] = uVar4;
  return;
}

long long FUN_060359d2()
{
  unsigned int unaff_r10 = 0;
  long long in_stack_0000003c;
  unsigned int *in_stack_00000044;

  *in_stack_00000044 =
       (0x000007FF & 0x7ff) << 0x14 | (unsigned int)((unaff_r10 & 0x80000000) != 0) * -0x80000000;
  in_stack_00000044[1] = 0;
  return in_stack_0000003c;
}

long long FUN_060359da()
{
  long long in_stack_0000003c;
  int *in_stack_00000044;

  *in_stack_00000044 = (0x000007FF & 0x7ff) << 0x14;
  in_stack_00000044[1] = 1;
  return in_stack_0000003c;
}

int FUN_060359e4()
{
  unsigned int uVar1;
  unsigned int uVar5;
  long long lVar2;
  long long lVar3;
  long long lVar4;
  int in_r0 = 0;
  int uVar6;
  unsigned int uVar7;
  unsigned int uVar8;
  unsigned int uVar9;
  unsigned int uVar10;
  int iVar11;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int *in_stack_00000000;
  unsigned int in_stack_00000004 = 0;
  unsigned int in_stack_00000008 = 0;
  unsigned int in_stack_0000000c = 0;
  unsigned int in_stack_00000010 = 0;

  uVar13 = in_stack_00000004 ^ in_stack_0000000c;
  uVar10 = in_stack_00000004 >> 0x14 & 0x000007FF;
  uVar12 = in_stack_0000000c >> 0x14 & 0x000007FF;
  in_stack_00000004 = in_stack_00000004 & 0x000FFFFF;
  in_stack_0000000c = in_stack_0000000c & 0x000FFFFF;
  if (uVar10 == 0x000007FF) {
    if ((in_stack_00000004 == 0) && (in_stack_00000008 == 0)) {
      if (uVar12 != 0x000007FF) {
        if (((uVar12 == 0) && (in_stack_0000000c == 0)) && (in_stack_00000010 == 0)) {
          uVar6 = FUN_060359da();
          return uVar6;
        }
        goto code_r0x060359d2;
      }
      if ((in_stack_0000000c == 0) && (in_stack_00000010 == 0)) {
        uVar6 = FUN_060359d2();
        return uVar6;
      }
    }
code_r0x060359da:
    uVar13 = 0;
    uVar8 = 0;
    uVar12 = 8;
    uVar10 = 0x000007FF;
  }
  else {
    if (uVar12 != 0x000007FF) {
      if (uVar10 == 0) {
        if ((in_stack_00000004 != 0) || (in_stack_00000008 != 0)) {
          for (in_stack_00000004 =
                    in_stack_00000004 << 1 | (unsigned int)((in_stack_00000008 & 0x80000000) != 0);
              in_stack_00000008 = in_stack_00000008 << 1,
              (int)in_stack_00000004 < (int)0x00100000;
              in_stack_00000004 =
                   in_stack_00000004 << 1 | (unsigned int)((in_stack_00000008 & 0x80000000) != 0)) {
            uVar10 = uVar10 - 1;
          }
          goto LAB_06035a3a;
        }
      }
      else {
LAB_06035a3a:
        if (uVar12 == 0) {
          if ((in_stack_0000000c == 0) && (in_stack_00000010 == 0)) goto LAB_060359c8;
          for (in_stack_0000000c =
                    in_stack_0000000c << 1 | (unsigned int)((in_stack_00000010 & 0x80000000) != 0);
              in_stack_00000010 = in_stack_00000010 << 1,
              (int)in_stack_0000000c < (int)0x00100000;
              in_stack_0000000c =
                   in_stack_0000000c << 1 | (unsigned int)((in_stack_00000010 & 0x80000000) != 0)) {
            uVar12 = uVar12 - 1;
          }
        }
        uVar10 = (uVar10 + uVar12) - 0x000003FF;
        if ((int)0x000007FF <= (int)uVar10) goto code_r0x060359d2;
        if (-0x36 < (int)uVar10) {
          uVar5 = (unsigned int)((unsigned long long)in_stack_00000010 * (unsigned long long)in_stack_00000008);
          lVar2 = (unsigned long long)(in_stack_0000000c | (unsigned int)0x00100000) *
                  (unsigned long long)(in_stack_00000004 | (unsigned int)0x00100000);
          uVar8 = (unsigned int)lVar2;
          lVar3 = (unsigned long long)in_stack_00000010 *
                  (unsigned long long)(in_stack_00000004 | (unsigned int)0x00100000);
          uVar9 = (unsigned int)lVar3;
          lVar4 = (unsigned long long)(in_stack_0000000c | (unsigned int)0x00100000) *
                  (unsigned long long)in_stack_00000008;
          uVar14 = (unsigned int)((unsigned long long)lVar4 >> 0x20);
          uVar1 = (unsigned int)lVar4;
          uVar7 = uVar9 + (int)((unsigned long long)in_stack_00000010 * (unsigned long long)in_stack_00000008 >> 0x20)
          ;
          uVar12 = uVar14 + (int)((unsigned long long)lVar3 >> 0x20);
          uVar9 = uVar12 + (uVar7 < uVar9);
          uVar7 = uVar1 + uVar7;
          uVar12 = uVar7 + (uVar12 < uVar14 || uVar9 < uVar12);
          uVar9 = uVar8 + uVar9;
          uVar7 = uVar9 + (uVar7 < uVar1 || uVar12 < uVar7);
          if (uVar5 != 0) {
            uVar12 = uVar12 | 1;
          }
          uVar1 = uVar12 >> 0x10;
          uVar14 = uVar7 >> 0x10;
          uVar9 = ((int)((unsigned long long)lVar2 >> 0x20) + (unsigned int)(uVar9 < uVar8 || uVar7 < uVar9)) << 16 | uVar14;
          uVar8 = uVar9 >> 1;
          uVar7 = ((uVar7 << 16) | uVar1) >> 1 | (unsigned int)((uVar14 & 1) == 1) * -0x80000000;
          uVar12 = (uVar12 << 0x10 | uVar5 >> 0x10) >> 1 | (unsigned int)((uVar1 & 1) != 0) * -0x80000000;
          if ((uVar8 & (unsigned int)0x01000000) != 0) {
            uVar8 = uVar9 >> 2;
            uVar7 = uVar7 >> 1 | (unsigned int)((uVar14 & 2) == 2) * -0x80000000;
            uVar12 = uVar12 >> 1 | (unsigned int)((uVar1 & 2) != 0) * -0x80000000;
            uVar10 = uVar10 + 1;
            if (uVar10 == 0x000007FF) {
              uVar6 = FUN_060359d2();
              return uVar6;
            }
          }
          if (uVar12 != 0) {
            uVar7 = uVar7 | 1;
          }
          if ((int)uVar10 < 1) {
            iVar11 = 1 - uVar10;
            do {
              uVar10 = uVar8 & 1;
              uVar8 = uVar8 >> 1;
              iVar11 = iVar11 + -1;
              uVar7 = uVar7 >> 1 | (unsigned int)(uVar10 == 1) * -0x80000000 | (unsigned int)((uVar7 & 1) != 0);
              uVar10 = 0;
            } while (iVar11 != 0);
          }
          uVar12 = uVar7;
          if (((uVar7 & 4) != 0) && ((uVar7 & 0xb) != 0)) {
            uVar12 = uVar7 + 8;
            uVar8 = uVar8 + (uVar12 < uVar7);
            if ((int)0x01000000 <= (int)uVar8) {
              uVar7 = uVar8 & 1;
              uVar8 = uVar8 >> 1;
              uVar12 = uVar12 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000;
              uVar10 = uVar10 + 1;
            }
          }
          goto LAB_06035ad6;
        }
      }
LAB_060359c8:
      uVar12 = 0;
      uVar10 = (unsigned int)((uVar13 & 0x80000000) != 0) << 0x1f;
      goto LAB_06035af4;
    }
    if ((in_stack_0000000c != 0) || (in_stack_00000010 != 0)) goto code_r0x060359da;
    if (((uVar10 == 0) && (in_stack_00000004 == 0)) && (in_stack_00000008 == 0)) {
      uVar6 = FUN_060359da();
      return uVar6;
    }
code_r0x060359d2:
    uVar8 = 0;
    uVar12 = 0;
    uVar10 = 0x000007FF;
  }
LAB_06035ad6:
  uVar12 = ((uVar12 >> 1 | (unsigned int)((uVar8 & 1) == 1) * -0x80000000) >> 1 |
           (unsigned int)((uVar8 >> 1 & 1) == 1) * -0x80000000) >> 1 |
           (unsigned int)((uVar8 >> 2 & 1) == 1) * -0x80000000;
  uVar10 = uVar8 >> 3 & 0x000FFFFF | (uVar10 & 0x7ff) << 0x14 |
           (unsigned int)((uVar13 & 0x80000000) != 0) * -0x80000000;
LAB_06035af4:
  *in_stack_00000000 = uVar10;
  in_stack_00000000[1] = uVar12;
  return in_r0;
}

int FUN_06035b34()
{
  unsigned int in_stack_00000000 = 0;
  int in_stack_00000004 = 0;
  unsigned int in_stack_00000008 = 0;
  int in_stack_0000000c = 0;

  if ((in_stack_00000008 & 0x7FF00000) == 0x7FF00000) {
    if ((in_stack_00000008 & 0x000FFFFF) != 0) {
      return 1;
    }
    if (in_stack_0000000c != 0) {
      return 1;
    }
  }
  if ((in_stack_00000000 & 0x7FF00000) == 0x7FF00000) {
    if ((in_stack_00000000 & 0x000FFFFF) != 0) {
      return 1;
    }
    if (in_stack_00000004 != 0) {
      return 1;
    }
  }
  if ((in_stack_00000008 & 0x7FF00000) == 0) {
    if ((in_stack_00000000 & 0x7FF00000) != 0) {
      return 1;
    }
    if (((in_stack_00000008 & 0x000FFFFF) == 0) && (in_stack_0000000c == 0)) {
      if ((in_stack_00000000 & 0x000FFFFF) != 0) {
        return 1;
      }
      if (in_stack_00000004 != 0) {
        return 1;
      }
      return 0;
    }
  }
  if ((in_stack_00000000 == in_stack_00000008) && (in_stack_00000004 == in_stack_0000000c)) {
    return 0;
  }
  return 1;
}

void FUN_06035bc8()
{
  unsigned int in_r0 = 0;
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  unsigned int *in_stack_00000000;

  iVar2 = 0x0000041F;
  if (in_r0 == 0) {
    uVar3 = 0;
    uVar1 = 0;
  }
  else {
    do {
      uVar1 = in_r0;
      iVar2 = iVar2 + -1;
      in_r0 = uVar1 << 1;
    } while ((uVar1 & 0x80000000) == 0);
    uVar3 = uVar1 << 0x15;
    uVar1 = (uVar1 << 1) >> 0xc | (iVar2 << 20);
  }
  *in_stack_00000000 = uVar1;
  in_stack_00000000[1] = uVar3;
  return;
}

/* cd_strlen -- String length (custom strlen for CD subsystem).
 * Counts characters until null terminator. Goto/check pattern
 * matches original SH-2 dt/bf loop. */
int FUN_06035c1c(char *str)
{
    register int count asm("r0") = 0;
    goto check;
body:
    count++;
check:
    if (*str++ != '\0') goto body;
    return count;
}

int FUN_06035c2c()
{
  int in_r0 = 0;
  int in_r1 = 0;
  int *puVar1;

  puVar1 = (int *)-256;
  *puVar1 = in_r0;
  puVar1[2] = 0;
  puVar1[1] = in_r1;
  return puVar1[4];
}

/* cd_hirq_set_and_send -- Set HIRQ request bit and send CD command with bit 0 set */
void FUN_06035c54(unsigned int cmd)
{
    *(unsigned short *)0x06063590 |= CD_HIRQREQ;
    FUN_06035c6e(cmd | 1);
}

/* cd_reset_hirq -- Send CD reset command (0x0BE1) and clear HIRQ status */
void FUN_06035c80(void)
{
    FUN_06035c6e(0x0BE1);
    *(short *)0x06063590 = 0;
}

/* cd_sector_read_words -- Read param_1 words from CD data register into buffer.
 * Initializes transfer via FUN_06034C68, then reads words from the CD
 * data port at 0x25898000 into param_2. After transfer, verifies the
 * actual word count matches expected. Returns -7 on count mismatch. */
int FUN_06035cbc(int param_1, short *param_2)
{
  short *cd_data_port = (short *)0x25898000;
  int iVar2;
  int local_14[2];

  iVar2 = (*(int(*)())0x06034C68)(0);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (0 < param_1) {
      do {
        iVar2 = iVar2 + 1;
        *param_2 = *cd_data_port;
        param_2 = param_2 + 1;
      } while (iVar2 < param_1);
    }
    iVar2 = (*(int(*)())0x06034CC8)(local_14);
    if ((iVar2 == 0) && (param_1 != local_14[0])) {
      iVar2 = -7;                        /* word count mismatch */
    }
  }
  return iVar2;
}

/* cd_wait_hirq -- Poll CD HIRQ register until requested bits are set.
 * Spins up to 0x240000 iterations (~2.3M) checking CD_HIRQREQ against
 * param_1 mask. On match, stores current HIRQ status to *param_2.
 * Returns 0 on success, -3 (0xFFFFFFFD) on timeout. */
int FUN_06035e00(unsigned short param_1, unsigned short *param_2)
{
  int iVar1 = 0;

  do {
    if ((CD_HIRQREQ & param_1) != 0) {
      *param_2 = CD_HIRQREQ;
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < (int)0x00240000);

  return 0xfffffffd;                     /* timeout */
}

/* cd_get_status -- Thin wrapper: query CD drive status via FUN_06035168 */
int FUN_06035e90(void)
{
    return (*(int(*)())0x06035168)();
}

/* cd_status_read -- Read CD drive status byte.
 * Calls low-level CD command (0x06035D22); on success, copies
 * first byte of response to CD status mirror at 0x06063594. */
int FUN_06035ea2(int param_1, int param_2, char *param_3)
{
    int err = (*(int(*)())0x06035D22)();
    if (err != 0)
        return err;

    *(int *)0x06063594 = *param_3;
    return 0;
}

/* cd_status_full_read -- Read full CD status and copy to mirror buffer.
 * Calls low-level CD command into temp buffer, then copies parsed
 * fields to the CD status mirror at 0x06063594 via FUN_06035f16. */
int FUN_06035ec8(int param_1, int param_2)
{
    int err;
    char buf[12];

    err = (*(int(*)())0x06035D22)(param_1, param_2, buf);
    if (err != 0)
        return err;

    FUN_06035f16(buf, (char *)0x06063594);
    return 0;
}

/* cd_status_unpack -- Unpack CD status from compact 5-byte format to expanded fields.
 * src[0] -> dest[0] (status byte)
 * src[1..4] -> dest[4..7] (FAD/track info)
 * src[4..7] masked to 24-bit -> dest[8..11] (position) */
void FUN_06035f16(char *src, char *dest)
{
    dest[0] = src[0];
    dest[4] = src[1];
    dest[5] = src[2];
    dest[6] = src[3];
    dest[7] = src[4];
    *(unsigned int *)(dest + 8) = *(unsigned int *)(src + 4) & 0x00FFFFFF;
}

unsigned int FUN_06035f44()
{
  char cVar1;
  int bVar2;
  int bVar3;
  int bVar4;
  unsigned char bVar5;
  unsigned int uVar6;
  int in_r0 = 0;
  unsigned int in_r1 = 0;
  unsigned int uVar7;
  unsigned int uVar9;
  unsigned int uVar11;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;
  unsigned int uVar18;
  unsigned int uVar19;
  unsigned int uVar20;
  unsigned int uVar21;
  unsigned int uVar22;
  unsigned int uVar23;
  unsigned int uVar24;
  unsigned int uVar25;
  unsigned int uVar26;
  unsigned int uVar27;
  unsigned int uVar28;
  unsigned int uVar29;
  unsigned int uVar30;
  unsigned int uVar31;
  unsigned int uVar32;
  unsigned int uVar33;
  unsigned int uVar34;
  unsigned int uVar35;
  unsigned int uVar36;
  unsigned int uVar37;
  unsigned int uVar38;
  unsigned int uVar39;
  unsigned int uVar40;
  unsigned int uVar8;
  unsigned int uVar10;

  if (in_r0 != 0) {
    uVar7 = (unsigned int)((in_r1 & 0x80000000) != 0);
    uVar8 = uVar7 - in_r0;
    bVar4 = uVar8 <= uVar7;
    uVar12 = in_r1 << 2;
    bVar3 = (uVar8 & 0x80000000) == 0;
    uVar7 = (uVar8 << 1) | (unsigned int)((in_r1 & 0x40000000) != 0);
    uVar8 = (unsigned int)bVar4 * (uVar7 - in_r0) + (unsigned int)!bVar4 * (uVar7 + in_r0);
    cVar1 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
    bVar5 = bVar3 * cVar1 + (!bVar3 && cVar1 == '\0');
    uVar7 = (unsigned int)bVar5 << 8;
    uVar9 = (uVar8 << 1) | (unsigned int)((uVar12 & 0x80000000) != 0);
    bVar3 = (bVar5 & 1) == ((unsigned char)(uVar7 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar7 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar9 - in_r0) + (unsigned int)!bVar3 * (uVar9 + in_r0);
    cVar1 = bVar3 * (uVar9 < uVar10) + !bVar3 * (uVar10 < uVar9);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar13 = uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar7 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar14 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar15 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar16 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar17 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar18 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar19 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar20 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar21 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar22 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar23 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar24 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar25 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar26 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar27 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar28 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x8000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar29 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x4000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar30 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x2000) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar31 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x1000) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar32 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x800) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar33 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x400) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar34 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x200) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar35 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x100) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar36 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x80) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar37 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x40) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar38 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x20) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar39 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 0x10) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar9 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar40 = uVar6 | uVar8 & 0xfffffeff | uVar9;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar9;
    uVar11 = (uVar10 << 1) | (unsigned int)((uVar12 & 8) != 0);
    bVar3 = ((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (unsigned int)bVar3 * (uVar11 - in_r0) + (unsigned int)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
    uVar8 = (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar11 = uVar6 | uVar9 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar9 & 0xfffffefe;
    uVar9 = uVar6 | uVar8;
    uVar12 = (uVar10 << 1) | (unsigned int)((uVar12 & 4) != 0);
    bVar3 = ((unsigned char)(uVar9 >> 8) & 1) == ((unsigned char)(uVar9 >> 9) & 1);
    bVar2 = (int)((unsigned char)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar9 = (unsigned int)bVar3 * (uVar12 - in_r0) + (unsigned int)!bVar3 * (uVar12 + in_r0);
    cVar1 = bVar3 * (uVar12 < uVar9) + !bVar3 * (uVar9 < uVar12);
    uVar8 = uVar6 | uVar8 & 0xfffffeff |
            (unsigned int)(unsigned char)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    return (((((((((((((((((((((((((((((((unsigned int)bVar4 << 1 |
                                        (unsigned int)((bVar5 & 1) == ((unsigned char)(uVar7 >> 9) & 1))) << 1 |
                                       (unsigned int)(((unsigned char)(uVar13 >> 8) & 1) == ((unsigned char)(uVar13 >> 9) & 1)
                                             )) << 1 |
                                      (unsigned int)(((unsigned char)(uVar14 >> 8) & 1) == ((unsigned char)(uVar14 >> 9) & 1))
                                      ) << 1 | (unsigned int)(((unsigned char)(uVar15 >> 8) & 1) ==
                                                     ((unsigned char)(uVar15 >> 9) & 1))) << 1 |
                                    (unsigned int)(((unsigned char)(uVar16 >> 8) & 1) == ((unsigned char)(uVar16 >> 9) & 1)))
                                    << 1 | (unsigned int)(((unsigned char)(uVar17 >> 8) & 1) ==
                                                 ((unsigned char)(uVar17 >> 9) & 1))) << 1 |
                                  (unsigned int)(((unsigned char)(uVar18 >> 8) & 1) == ((unsigned char)(uVar18 >> 9) & 1))) <<
                                  1 | (unsigned int)(((unsigned char)(uVar19 >> 8) & 1) == ((unsigned char)(uVar19 >> 9) & 1))
                                 ) << 1 | (unsigned int)(((unsigned char)(uVar20 >> 8) & 1) ==
                                                ((unsigned char)(uVar20 >> 9) & 1))) << 1 |
                               (unsigned int)(((unsigned char)(uVar21 >> 8) & 1) == ((unsigned char)(uVar21 >> 9) & 1))) << 1
                              | (unsigned int)(((unsigned char)(uVar22 >> 8) & 1) == ((unsigned char)(uVar22 >> 9) & 1))) << 1
                             | (unsigned int)(((unsigned char)(uVar23 >> 8) & 1) == ((unsigned char)(uVar23 >> 9) & 1))) << 1
                            | (unsigned int)(((unsigned char)(uVar24 >> 8) & 1) == ((unsigned char)(uVar24 >> 9) & 1))) << 1 |
                           (unsigned int)(((unsigned char)(uVar25 >> 8) & 1) == ((unsigned char)(uVar25 >> 9) & 1))) << 1 |
                          (unsigned int)(((unsigned char)(uVar26 >> 8) & 1) == ((unsigned char)(uVar26 >> 9) & 1))) << 1 |
                         (unsigned int)(((unsigned char)(uVar27 >> 8) & 1) == ((unsigned char)(uVar27 >> 9) & 1))) << 1 |
                        (unsigned int)(((unsigned char)(uVar28 >> 8) & 1) == ((unsigned char)(uVar28 >> 9) & 1))) << 1 |
                       (unsigned int)(((unsigned char)(uVar29 >> 8) & 1) == ((unsigned char)(uVar29 >> 9) & 1))) << 1 |
                      (unsigned int)(((unsigned char)(uVar30 >> 8) & 1) == ((unsigned char)(uVar30 >> 9) & 1))) << 1 |
                     (unsigned int)(((unsigned char)(uVar31 >> 8) & 1) == ((unsigned char)(uVar31 >> 9) & 1))) << 1 |
                    (unsigned int)(((unsigned char)(uVar32 >> 8) & 1) == ((unsigned char)(uVar32 >> 9) & 1))) << 1 |
                   (unsigned int)(((unsigned char)(uVar33 >> 8) & 1) == ((unsigned char)(uVar33 >> 9) & 1))) << 1 |
                  (unsigned int)(((unsigned char)(uVar34 >> 8) & 1) == ((unsigned char)(uVar34 >> 9) & 1))) << 1 |
                 (unsigned int)(((unsigned char)(uVar35 >> 8) & 1) == ((unsigned char)(uVar35 >> 9) & 1))) << 1 |
                (unsigned int)(((unsigned char)(uVar36 >> 8) & 1) == ((unsigned char)(uVar36 >> 9) & 1))) << 1 |
               (unsigned int)(((unsigned char)(uVar37 >> 8) & 1) == ((unsigned char)(uVar37 >> 9) & 1))) << 1 |
              (unsigned int)(((unsigned char)(uVar38 >> 8) & 1) == ((unsigned char)(uVar38 >> 9) & 1))) << 1 |
             (unsigned int)(((unsigned char)(uVar39 >> 8) & 1) == ((unsigned char)(uVar39 >> 9) & 1))) << 1 |
            (unsigned int)(((unsigned char)(uVar40 >> 8) & 1) == ((unsigned char)(uVar40 >> 9) & 1))) << 1 |
           (unsigned int)(((unsigned char)(uVar11 >> 8) & 1) == ((unsigned char)(uVar11 >> 9) & 1))) << 1 |
           (unsigned int)(((unsigned char)(uVar8 >> 8) & 1) == ((unsigned char)(uVar8 >> 9) & 1));
  }
  *(int *)0x060A246C = 0x0000044E;
  return 0;
}
