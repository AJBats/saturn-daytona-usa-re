#include "game.h"

extern int DAT_0601c510;
extern int DAT_0601c5f8;
extern int DAT_0601c5fa;
extern int DAT_0601c6c0;
extern int DAT_0601c77c;
extern int DAT_0601c844;
extern int DAT_0601c93c;
extern int DAT_0601c93e;
extern int DAT_0601c940;
extern int DAT_0601ca3a;
extern int DAT_0601ca3c;
extern int DAT_0601ca3e;
extern int DAT_0601cb48;
extern int DAT_0601d056;
extern int DAT_0601d0f2;
extern int DAT_0601d18c;
extern int DAT_0601d18e;
extern int DAT_0601d24c;
extern int DAT_0601d24e;
extern int DAT_0601d2c6;
extern int DAT_0601d36a;
extern int DAT_0601d36c;
extern int DAT_0601d444;
extern int DAT_0601d446;
extern int DAT_0601d974;
extern int DAT_0601d976;
extern int DAT_0601dd30;
extern int DAT_0601dd34;
extern int DAT_0601dd38;
extern int DAT_0601dd3a;
extern int DAT_0601de24;
extern int DAT_0601de26;
extern int DAT_0601df14;
extern int DAT_0601df16;
extern int DAT_0601df18;
extern int DAT_0601df1a;
extern int DAT_0601df1c;
extern int DAT_0601df1e;
extern int DAT_0601df7a;
extern int DAT_0601e022;
extern int DAT_0601e024;
extern int DAT_0601e026;
extern int DAT_0601e028;
extern int DAT_0601e02a;
extern int DAT_0601e02c;
extern int DAT_0601e02e;
extern int DAT_0601e0e2;
extern int DAT_0601e0e4;
extern int DAT_0601e0e6;
extern void FUN_0601cdc0();
extern void FUN_0601cefc();
extern void FUN_0601d014();
extern void FUN_0601d074();
extern int FUN_0601d0bc();
extern void FUN_0601d12c();
extern int scsp_command_dispatch();
extern int FUN_0601db84();
extern int FUN_0601ddf6();
extern int FUN_0601e26c();
extern int PTR_DAT_0601ca40;
extern int PTR_DAT_0601d250;
extern int PTR_DAT_0601d2c8;
extern int PTR_DAT_0601d884;
extern int PTR_DAT_0601da3c;
extern int PTR_DAT_0601df20;
extern int PTR_DAT_0601e030;

int FUN_0601c3e4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  puVar5 = (char *)0x0605DF56;

  puVar4 = (char *)0x0605DF57;

  puVar3 = (char *)0x0608A52C;

  puVar2 = (char *)0x00008000;

  puVar1 = (char *)0x0605DF44;

  iVar8 = CAR_PTR_TARGET;

  if ((*(int *)0x06063E1C == 0) || (*(int *)0x06063E20 == 0)) {

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    (*(int(*)())0x06034F78)();

    uVar6 = (*(int(*)())0x06034F78)();

  }

  else {

    if ((*(unsigned char *)(iVar8 + 3) & 0x40) != 0) {

      *(short *)0x0605DF4E = 8;

      (*(int(*)())0x06034F78)();

    }

    if (((int)*(char *)(iVar8 + 3) & 0x80U) != 0) {

      *(short *)0x0605DF50 = 8;

      (*(int(*)())0x06034F78)();

    }

    if ((*(unsigned char *)(iVar8 + 2) & 1) != 0) {

      *(short *)0x0605DF52 = 8;

      (*(int(*)())0x06034F78)();

    }

    if ((*(unsigned char *)(iVar8 + 2) & 2) != 0) {

      *(short *)0x0605DF54 = 8;

      (*(int(*)())0x06034F78)();

    }

    if (*(short *)0x0605DF4E == 0) {

      if (*(short *)0x0605DF50 == 0) {

        if (*(short *)0x0605DF52 == 0) {

          if (*(short *)0x0605DF54 != 0) {

            (*(int(*)())0x06027080)();

            (*(int(*)())0x060270F2)(0xFFFE9DF4,puVar2,0x00013333);

            (*(int(*)())0x060271A2)((int)DAT_0601c844);

            iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

            (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                       *(int *)(0x060621D8 + iVar7));

            iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

            (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                       *(int *)(0x06062180 + iVar7));

            *(int *)puVar3 = *(int *)puVar3 + -0x30;

            *puVar4 = *puVar4 + '\x01';

            if (2 < (unsigned char)*puVar4) {

              *puVar4 = 0;

            }

            *(short *)0x0605DF54 = *(short *)0x0605DF54 + -1;

          }

        }

        else {

          (*(int(*)())0x06027080)();

          (*(int(*)())0x060270F2)(0x0001620C,puVar2,0x00013333);

          (*(int(*)())0x060271A2)((int)DAT_0601c77c);

          iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

          (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                     *(int *)(0x060621D8 + iVar7));

          iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

          (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                     *(int *)(0x06062180 + iVar7));

          *(int *)puVar3 = *(int *)puVar3 + -0x30;

          *puVar5 = *puVar5 + '\x01';

          if (2 < (unsigned char)*puVar5) {

            *puVar5 = 0;

          }

          *(short *)0x0605DF52 = *(short *)0x0605DF52 + -1;

        }

      }

      else {

        (*(int(*)())0x06027080)();

        if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {

          (*(int(*)())0x060270F2)(0xFFFEB78E,puVar2,0xFFFE4000);

          (*(int(*)())0x06027124)((int)DAT_0601c5fa,(int)DAT_0601c5fa);

        }

        else {

          (*(int(*)())0x060270F2)(0xFFFEB78E,puVar2,0xFFFF0000);

        }

        (*(int(*)())0x060271A2)((int)DAT_0601c6c0);

        iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

        (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                   *(int *)(0x060621D8 + iVar7));

        iVar7 = ((unsigned char)*puVar4 + 0x12) << 2;

        (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                   *(int *)(0x06062180 + iVar7));

        *(int *)puVar3 = *(int *)puVar3 + -0x30;

        *puVar4 = *puVar4 + '\x01';

        if (2 < (unsigned char)*puVar4) {

          *puVar4 = 0;

        }

        *(short *)0x0605DF50 = *(short *)0x0605DF50 + -1;

      }

    }

    else {

      (*(int(*)())0x06027080)();

      if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {

        (*(int(*)())0x060270F2)(0x00014872,puVar2,0xFFFE4000);

        (*(int(*)())0x06027124)((int)DAT_0601c510,(int)DAT_0601c510);

      }

      else {

        (*(int(*)())0x060270F2)(0x00014872,puVar2,0xFFFF0000);

      }

      (*(int(*)())0x060271A2)((int)DAT_0601c5f8);

      iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

      (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar7),*(int *)(0x060621D8 + iVar7)

                );

      iVar7 = ((unsigned char)*puVar5 + 0x12) << 2;

      (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                 *(int *)(0x06062180 + iVar7));

      *(int *)puVar3 = *(int *)puVar3 + -0x30;

      *puVar5 = *puVar5 + '\x01';

      if (2 < (unsigned char)*puVar5) {

        *puVar5 = 0;

      }

      *(short *)0x0605DF4E = *(short *)0x0605DF4E + -1;

    }

    if (*(int *)0x06059F30 == 0) {

      uVar6 = 0;

    }

    else {

      if ((*(short *)(iVar8 + DAT_0601c93c) == 0) && (*(short *)(iVar8 + DAT_0601c93e) == 0)) {

        *(short *)puVar1 = 0;

      }

      if ((*(short *)(iVar8 + DAT_0601c93c) != 0) ||

         (uVar6 = 0, *(short *)(iVar8 + DAT_0601c93e) != 0)) {

        (*(int(*)())0x06027080)();

        (*(int(*)())0x060270F2)(*(int *)0x06044670,

                   *(int *)(0x06044670 + 4) + -13107,

                   0xFFFF6000 - *(int *)(0x06044670 + 8));

        (*(int(*)())0x060271A2)(puVar2);

        iVar8 = (*(short *)(0x0605DF46 + *(short *)((int)(int)puVar1 << 1)) + 0xe) << 2;

        (*(int(*)())0x06032158)(*(int *)(0x0606212C + iVar8),

                   *(int *)(0x060621D8 + iVar8));

        iVar8 = (*(short *)(0x0605DF46 + *(short *)((int)(int)puVar1 << 1)) + 0xe) << 2;

        uVar6 = (*(int(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar8),*(short *)0x06089E9C

                           ,*(int *)(0x06062180 + iVar8));

        *(int *)puVar3 = *(int *)puVar3 + -0x30;

        *(short *)puVar1 = *(short *)puVar1 + 1;

        if (3 < *(short *)puVar1) {

          *(short *)puVar1 = 0;

        }

      }

    }

  }

  return uVar6;

}

/* results_screen_init -- Initialize results/record display screen.
 * Clears display counters (0x0608602C, 0x06086030), sets initial
 * palette color (DAT_0601ca3a), calls HUD setup (0x060149E0) and
 * VDP sync (0x06026CE0). Fills VDP2 CRAM banks A (0x25F00200) and
 * B (0x25F00400) with base color. Loads race palette from 0x0604880C,
 * two tile banks via CD (0x0600511E), two VDP1 sprite overlays.
 * Configures 5 CD audio channels (0x06038BD4), enables palette
 * interrupt (0x06036E90), sets INPUT_STATE display flag, re-syncs VDP. */
void FUN_0601c978()
{
  int count;
  short *cram_ptr;
  short *next;

  *(int *)0x0608602C = 0;                               /* clear display counter A */
  *(int *)0x06086030 = 0;                               /* clear display counter B */
  *(short *)0x06086028 = DAT_0601ca3a;                  /* base palette color */
  (*(int(*)())0x060149E0)();                             /* HUD layout setup */
  (*(int(*)())0x060148FC)();                             /* HUD state reset */
  (*(int(*)())0x06026CE0)();                             /* VDP vsync */
  VBLANK_OUT_COUNTER = 0;
  (*(int(*)())0x0600A026)();                             /* timing reset */
  *(int *)0x0608601C = (int)DAT_0601ca3c;               /* display mode */
  *(int *)0x06086020 = 0;                               /* fade step counter */
  *(int *)0x06086024 = 0;                               /* animation counter */
  /* fill VDP2 CRAM bank A (0x25F00200) with base color */
  count = 0x20;
  cram_ptr = (short *)0x25F00200;
  do {
    count = count + -2;
    *cram_ptr = *(short *)0x06086028;
    next = cram_ptr + 1;
    cram_ptr = cram_ptr + 2;
    *next = *(short *)0x06086028;
  } while (count != 0);
  /* fill VDP2 CRAM bank B (0x25F00400) with base color */
  count = 0x20;
  cram_ptr = (short *)0x25F00400;
  do {
    count = count + -2;
    *cram_ptr = *(short *)0x06086028;
    next = cram_ptr + 1;
    cram_ptr = cram_ptr + 2;
    *next = *(short *)0x06086028;
  } while (count != 0);
  (*(int(*)())0x0602766C)(0x25F00000, 0x0604880C, 0x40); /* DMA race palette */
  (*(int(*)())0x0600511E)(0x25E70E40, 0x00014000, 0, 9); /* load tile bank A from CD */
  (*(int(*)())0x0600511E)(0x25E7B168, 0x00016BC0, 0, 9); /* load tile bank B from CD */
  /* VDP1 sprite overlays for results screen */
  (*(int(*)())0x06028400)(4, *(int *)0x06063958, 0x518,
             *(int *)(0x06063958 + 4), 0x06063958);
  (*(int(*)())0x06028400)(0, *(int *)0x06063960, 0x518,
             *(int *)(0x06063960 + 4), 0x06063960);
  /* CD audio channel configuration */
  (*(int(*)())0x06038BD4)(0x100, 0);                     /* master volume */
  (*(int(*)())0x06038BD4)(4, 1);                         /* channel 1 */
  (*(int(*)())0x06038BD4)(8, 2);                         /* channel 2 */
  (*(int(*)())0x06038BD4)(0x10, 0);                      /* channel 3 */
  (*(int(*)())0x06038BD4)(0x20, 0);                      /* channel 4 */
  (*(int(*)())0x06036E90)(0x25F00FFE, 1, 0x06086028);    /* palette interrupt enable */
  INPUT_STATE = INPUT_STATE | 0x40000000;                /* set display active flag */
  (*(int(*)())0x06026CE0)();                             /* VDP vsync */
  VBLANK_OUT_COUNTER = 0;
}

void FUN_0601caee()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int *puVar8;

  int local_48;

  int local_44;

  char *local_40 [3];

  int local_34;

  int local_30;

  char *local_2c [3];

  char local_20 [4];

  puVar6 = (char *)0x0608601C;

  puVar5 = (char *)0x06086024;

  puVar4 = (char *)0x0602766C;

  puVar3 = (char *)0x25F00400;

  puVar2 = (char *)0x25F00200;

  puVar1 = (char *)0x06086020;

  *(int *)0x0608601C = *(int *)0x0608601C + -1;

  puVar8 = (int *)local_20;

  if (((*(unsigned short *)0x06063D98 & DAT_0601cb48) != 0) &&

     (puVar8 = (int *)local_20, *(int *)0x06086024 == 0)) {

    local_2c[0] = (char *)local_2c;

    (*(int(*)())0x060358EC)();

    local_30 = 0;

    local_34 = 0x40680000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 == 0) {

      local_40[0] = (char *)local_40;

      (*(int(*)())0x060358EC)();

      local_44 = 0;

      puVar8 = &local_48;

      local_48 = 0x40568000;

      iVar7 = (*(int(*)())0x06035844)();

      if (iVar7 == 0) {

        *(int *)puVar5 = 3;

      }

      else {

        *(int *)puVar5 = 2;

        puVar8 = &local_48;

      }

    }

    else {

      *(int *)puVar5 = 1;

      puVar8 = &local_34;

    }

  }

  FUN_0601d12c();

  if (*(int *)puVar5 == 0) {

    *(char **)((int)puVar8 + -0xc) = (char *)((int)puVar8 + -0xc);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x10) = 0;

    *(int *)((int)puVar8 + -0x14) = 0x40726000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) goto LAB_0601cda4;

    *(char **)((int)puVar8 + -0x20) = (char *)((int)puVar8 + -0x20);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x24) = 0;

    *(int *)((int)puVar8 + -0x28) = 0x406D4000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x34) = (char *)((int)puVar8 + -0x34);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x38) = 0;

    *(int *)((int)puVar8 + -0x3c) = 0x406D4000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    *(char **)((int)puVar8 + -0x48) = (char *)((int)puVar8 + -0x48);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x4c) = 0;

    *(int *)((int)puVar8 + -0x50) = 0x40680000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x5c) = (char *)((int)puVar8 + -0x5c);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x60) = 0;

    *(int *)((int)puVar8 + -100) = 0x40680000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      FUN_0601d014();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x70) = (char *)((int)puVar8 + -0x70);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x74) = 0;

    *(int *)((int)puVar8 + -0x78) = 0x40608000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x84) = (char *)((int)puVar8 + -0x84);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x88) = 0;

    *(int *)((int)puVar8 + -0x8c) = 0x40608000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    *(char **)((int)puVar8 + -0x98) = (char *)((int)puVar8 + -0x98);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x9c) = 0;

    *(int *)((int)puVar8 + -0xa0) = 0x40568000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xac) = (char *)((int)puVar8 + -0xac);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xb0) = 0;

    *(int *)((int)puVar8 + -0xb4) = 0x40568000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      FUN_0601d074();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xc0) = (char *)((int)puVar8 + -0xc0);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xc4) = 0;

    *(int *)((int)puVar8 + -200) = 0x403E0000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xd4) = (char *)((int)puVar8 + -0xd4);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xd8) = 0;

    *(int *)((int)puVar8 + -0xdc) = 0x403E0000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    if (0 < *(int *)puVar6) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

  }

  else {

    if (*(int *)puVar5 == 1) {

      (*(int(*)())puVar4)(puVar2,0x0604880C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0604882C,0x20);

    }

    if (*(int *)puVar5 == 2) {

      FUN_0601d014();

      (*(int(*)())puVar4)(puVar2,0x0604884C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0604886C,0x20);

    }

    if (*(int *)puVar5 == 3) {

      (*(int(*)())puVar4)(puVar2,0x0605D17C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0605D19C,0x20);

    }

  }

  GAME_STATE = 2;

LAB_0601cda4:

  (*(int(*)())0x06026CE0)();

  VBLANK_OUT_COUNTER = 0;

  return;

}

/* palette_fade_out -- Fade VDP2 palette to black.
 * Reads 32 palette entries from VDP2 CRAM (0x25F00000),
 * decomposes each RGB555 color, attenuates R/G/B by step
 * from fade table at 0x0605DF58, recomposes and DMA-writes
 * back. Step counter at 0x06086020, max 0x12 frames. */
void FUN_0601cdc0()
{
  short fade_factor;
  short rgb555;
  int i;
  short red[2];
  short green[2];
  short blue[2];
  short *src_palette;
  short *dst_ptr;
  short faded_palette[16];
  char faded_palette_b[40];

  if (*(int *)0x06086020 < 0x12) {                     /* fade not complete */
    fade_factor = *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1)); /* fade table lookup */
    src_palette = (short *)0x25F00000;                  /* VDP2 CRAM base */
    dst_ptr = faded_palette;
    for (i = 0; i < 0x20; i = i + 1) {
      rgb555 = *src_palette;
      src_palette = src_palette + 1;
      FUN_0601d0bc(rgb555, red, green, blue);           /* decompose RGB555 */
      red[0] = (*(int(*)())0x06034FE0)(fade_factor * 0x1d);   /* attenuate R */
      green[0] = (*(int(*)())0x06034FE0)();             /* attenuate G */
      blue[0] = (*(int(*)())0x06034FE0)();              /* attenuate B */
      *dst_ptr = blue[0] * 0x400 + green[0] * 0x20 + red[0]; /* recompose RGB555 */
      dst_ptr = dst_ptr + 1;
    }
    (*(int(*)())0x0602766C)(0x25F00200, faded_palette, 0x20);  /* DMA palette bank A */
    (*(int(*)())0x0602766C)(0x25F00400, faded_palette_b, 0x20); /* DMA palette bank B */
  }
  *(int *)0x06086020 = *(int *)0x06086020 + 1;         /* advance fade step */
}

/* palette_fade_in -- Fade VDP2 palette from black to full color.
 * Inverse of palette_fade_out: uses (100 - step) as blend factor
 * so colors ramp from black toward original values. Same RGB555
 * decompose/recompose and DMA pattern. */
void FUN_0601cefc()
{
  short rgb555;
  int i;
  short red[2];
  short green[2];
  short blue[2];
  short *src_palette;
  int inv_fade_factor;
  short *dst_ptr;
  short faded_palette[16];
  char faded_palette_b[40];

  if (*(int *)0x06086020 < 0x12) {                     /* fade not complete */
    inv_fade_factor = 100 - *(short *)(0x0605DF58 + *(int *)(0x06086020 << 1)); /* inverted fade */
    src_palette = (short *)0x25F00000;                  /* VDP2 CRAM base */
    dst_ptr = faded_palette;
    for (i = 0; i < 0x20; i = i + 1) {
      rgb555 = *src_palette;
      src_palette = src_palette + 1;
      FUN_0601d0bc(rgb555, red, green, blue);           /* decompose RGB555 */
      red[0] = (*(int(*)())0x06034FE0)(inv_fade_factor * 0x1d);  /* blend R */
      green[0] = (*(int(*)())0x06034FE0)();             /* blend G */
      blue[0] = (*(int(*)())0x06034FE0)();              /* blend B */
      *dst_ptr = blue[0] * 0x400 + green[0] * 0x20 + red[0]; /* recompose RGB555 */
      dst_ptr = dst_ptr + 1;
    }
    (*(int(*)())0x0602766C)(0x25F00200, faded_palette, 0x20);  /* DMA palette bank A */
    (*(int(*)())0x0602766C)(0x25F00400, faded_palette_b, 0x20); /* DMA palette bank B */
  }
  *(int *)0x06086020 = *(int *)0x06086020 + 1;         /* advance fade step */
}

/* timer_display_init -- Initialize timer/countdown VDP display.
 * DMA-copies timer font data to VDP2 VRAM (0x25F00000),
 * sets up 2 VDP1 sprite commands for minutes and seconds digits,
 * clears timer display state. */
void FUN_0601d014(void)
{
    (*(int(*)())0x0602766C)(0x25F00000, 0x0604884C, 0x40);   /* DMA font data */
    (*(int(*)())0x06028400)(4, *(int *)0x06063968, 0x518,
        *(int *)(0x06063968 + 4), 0x06063968);                /* minutes sprite */
    (*(int(*)())0x06028400)(0, *(int *)0x06063970, 0x518,
        *(int *)(0x06063970 + 4), 0x06063970);                /* seconds sprite */
    *(int *)0x06086020 = 0;                                    /* reset display state */
}

/* countdown_display_init -- Initialize countdown timer display.
 * Sets VDP sprite slot (4), DMA-copies countdown font data (0x40 bytes),
 * builds 2 VDP1 sprite commands for countdown digits, clears state. */
void FUN_0601d074(void)
{
    (*(int(*)())0x0602853E)(4);                                /* VDP sprite slot config */
    (*(int(*)())0x0602766C)(0x25F00000, 0x0605D17C, 0x40);    /* DMA font data */
    (*(int(*)())0x06028400)(4, *(int *)0x06063CF8, 0x518,
        *(int *)(0x06063CF8 + 4), 0x06063CF8);                /* countdown digit 1 */
    (*(int(*)())0x06028400)(0, *(int *)0x06063D00, 0x518,
        *(int *)(0x06063D00 + 4), 0x06063D00);                /* countdown digit 2 */
    *(int *)0x06086020 = 0;                                    /* reset state */
}

/* cheat_code_input_check -- Detect 11-step cheat code button sequence.
 * Reads controller input at 0x06063D9A, advances step counter at 0x0608602C
 * when the expected button mask matches. If wrong input on any step, resets.
 * Steps 0-1: DAT_0601d18c, step 2: DAT_0601d18e, step 3: DAT_0601d24c,
 * steps 4,6: DAT_0601d24e, steps 5,7: 0x8000, step 8: PTR_DAT_0601d250,
 * step 9: DAT_0601d2c6, step 10: PTR_DAT_0601d2c8.
 * On completion (step 11): set unlock flag (0x06086030=1), play sound 0xAE1146FF. */
void FUN_0601d12c(void)
{
  int *step = (int *)0x0608602C;
  int prev_step = *step;
  unsigned short input = *(unsigned short *)0x06063D9A;

  if ((*step == 0) && ((input & DAT_0601d18c) != 0)) {
    *step = *step + 1;
  } else if ((*step == 1) && ((input & DAT_0601d18c) != 0)) {
    *step = *step + 1;
  } else if ((*step == 2) && ((input & DAT_0601d18e) != 0)) {
    *step = *step + 1;
  } else if ((*step == 3) && ((input & DAT_0601d24c) != 0)) {
    *step = *step + 1;
  } else if ((*step == 4) && ((input & DAT_0601d24e) != 0)) {
    *step = *step + 1;
  } else if ((*step == 5) && (((unsigned int)input & 0x00008000) != 0)) {
    *step = *step + 1;
  } else if ((*step == 6) && ((input & DAT_0601d24e) != 0)) {
    *step = *step + 1;
  } else if ((*step == 7) && (((unsigned int)input & 0x00008000) != 0)) {
    *step = *step + 1;
  } else if ((*step == 8) && ((input & PTR_DAT_0601d250) != 0)) {
    *step = *step + 1;
  } else if ((*step == 9) && ((input & DAT_0601d2c6) != 0)) {
    *step = *step + 1;
  } else if ((*step == 10) && ((input & PTR_DAT_0601d2c8) != 0)) {
    *step = *step + 1;
  }

  if ((*step == prev_step) && (*(short *)0x06063D9A != 0)) {
    *step = 0;                               /* wrong input — reset */
  }
  if (*step == 0xb) {
    *(int *)0x06086030 = 1;                  /* cheat unlocked */
    *step = 0;
    (*(int(*)())0x0601D5F4)(0, 0xAE1146FF); /* confirmation sound */
  }
}

/* service_subsystem_init -- Initialize service/test mode subsystem.
 * Disables interrupts (0x060149E0), configures SCU interrupt priorities
 * (timer0=0, VBlank-IN=0, VBlank-OUT=0, HBlank-IN=6, timer1=7),
 * initializes VDP state (0x0600A026), configures VDP2 scroll (0x0600511E).
 * DMA-copies 3 font/sprite tables to VDP1 VRAM, loads 2 sprite tables
 * to VDP2 VRAM, sets game mode to 0, re-enables interrupts. */
void FUN_0601d2dc(void)
{
  void (*scu_int_config)(int, int) = (void (*)(int, int))0x06038BD4;
  void (*dma_copy)(int, int, int) = (void (*)(int, int, int))0x0602766C;

  (*(int(*)())0x060149E0)();                  /* disable interrupts */

  scu_int_config(0x100, 0);                   /* timer 0: off */
  scu_int_config(4, 0);                       /* VBlank-IN: off */
  scu_int_config(8, 0);                       /* VBlank-OUT: off */
  scu_int_config(0x10, 6);                    /* HBlank-IN: priority 6 */
  scu_int_config(0x20, 7);                    /* timer 1: priority 7 */

  (*(int(*)())0x0600A026)();                  /* VDP state init */
  (*(int(*)())0x0600511E)(0x25E6F9C4, 0x00017700, 0, 8);  /* VDP2 scroll config */

  dma_copy(0x25F00600, 0x0604842C, 0x40);    /* font table A */
  dma_copy(0x25F00660, 0x0604888C, 0x60);    /* font table B */
  dma_copy(0x25F00000, 0x0604842C, 0x60);    /* font table C */

  (*(int(*)())0x06028654)(0x25E759EC, 0x06094FA8);   /* sprite table A → VDP2 */
  (*(int(*)())0x06028654)(0x25E75DDC, 0x06095F48);   /* sprite table B → VDP2 */
  (*(int(*)())0x06028400)(8, 0x06095F48, 0, (int)DAT_0601d36c);

  *(int *)0x0607887F = 0;                     /* game mode = 0 */
  (*(int(*)())0x060149CC)();                  /* re-enable interrupts */
}

/* service_mode_start -- Handle service mode entry and dispatch.
 * On first entry (0x06086024==0) with start button (DAT_0601d444):
 *   - Check for special controller patterns (0xAAA8 → unlock courses,
 *     DAT_0601d446 → unlock all courses + characters)
 *   - Initialize perspective (0x06014884), DMA sprite table, set timer=0xC
 *   - Set game mode to 4, mark as entered (0x06086024=1)
 * Always dispatches to game mode handler via vtable at 0x0605DF80. */
void FUN_0601d3c0(void)
{
  char *unlock_flags = (char *)0x0605AB16;

  if ((*(int *)0x06086024 == 0) && ((*(unsigned short *)0x06063D9A & DAT_0601d444) != 0)) {
    if ((unsigned int)*(unsigned short *)0x06063D98 == 0x0000AAA8) {
      *(int *)0x0605AB16 = *(int *)0x0605AB16 | 7;    /* unlock courses */
    }
    if ((unsigned int)*(unsigned short *)0x06063D98 == (int)DAT_0601d446) {
      *unlock_flags = *unlock_flags | 7;               /* unlock courses */
      *(int *)0x0605AB17 = *(int *)0x0605AB17 | 7;    /* unlock characters */
    }
    (*(int(*)())0x06014884)(0x20, 0);                  /* perspective init */
    (*(int(*)())0x06028400)(0xc, 0x06094FA8, 0);       /* DMA sprite table */
    *(int *)0x0607EBCC = 0xc;                          /* countdown timer */
    *(int *)0x0607887F = 4;                            /* game mode = 4 */
    *(int *)0x06086024 = 1;                            /* mark entered */
  }

  (*(int(*)())(*(int *)(0x0605DF80 + (unsigned int)(unsigned char)*(int *)(0x0607887F << 2))))();
}

/* hud_sprite_table_copy -- Copy 28 sprite entries from source table to HUD buffer.
 * Source at 0x06094FAC has 0x58-byte stride; dest at 0x0605AAA6 has 4-byte stride.
 * param_1 selects column offset (<<1). Issues VDP1 command after copy. */
void FUN_0601d57c(unsigned short param_1)
{
    register char *dest asm("r2") = (char *)0x0605AAA6;
    register char *src asm("r3") = (char *)0x06094FAC;
    unsigned short i = 0;

    do {
        int dest_off = i << 2;
        int src_off = i * 0x58 + (param_1 << 1);
        i++;
        *(short *)(dest + dest_off)     = *(short *)(src + src_off);
        *(short *)(dest + dest_off + 2) = *(short *)(src + src_off + 2);
    } while (i < 0x1c);

    (*(void(*)())0x06028400)(0xc, 0x0605AAA2, (param_1 & 0x3f) << 1, 0);
}

/* scsp_command_dispatch -- routes sound commands to SCSP mailbox by channel.
 *   param_1 = channel (0=direct, 1-5=tracked channels, 0xF=direct bypass)
 *   param_2 = sound command or track ID (shifted into 0xAn7000FF format for ch 1-5)
 *   Channels 1-5 build command word 0xAn7000FF + (param_2 << 8) and skip if unchanged.
 *   Channel 0 and 0xF send raw command if it has 0xA0000000 signature.
 *   Channel 4 sends param_2 directly without encoding.
 *   Returns channel number on success, SOUND_TIMEOUT_FLAG on timeout. */
int scsp_command_dispatch(param_1, param_2)
    int param_1;
    unsigned int param_2;
{
  int result;
  int cmd_word;
  result = SOUND_TIMEOUT_FLAG;
  if (SOUND_TIMEOUT_FLAG == 0) {
    result = param_1;
    if (param_1 == 0) {
      /* Channel 0: direct SCSP command (must have 0xA0 signature) */
      if ((param_2 & 0xA0000000) == 0xA0000000) {
        result = FUN_0601db84();             /* wait for SCSP mailbox ready */
        SCSP_MAILBOX = param_2;
        SOUND_CMD_MIRROR = param_2;
      }
    } else {
      if (param_1 == 1) {
        /* Channel 1: BGM / main music (0xA07000FF base) */
        cmd_word = 0xA07000FF + (param_2 << 8);
        result = 1;
        if (SOUND_CHAN_STATE != cmd_word) {
          result = FUN_0601db84();
          SOUND_CHAN_STATE = cmd_word;
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if (param_1 == 2) {
        /* Channel 2: secondary audio (0xA17000FF base) */
        cmd_word = 0xA17000FF + (param_2 << 8);
        result = 2;
        if (*(int *)0x0605DF98 != cmd_word) {
          result = FUN_0601db84();
          *(int *)0x0605DF98 = cmd_word;     /* channel 2 state */
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if (param_1 == 3) {
        /* Channel 3: tertiary audio (0xA27000FF base) */
        cmd_word = 0xA27000FF + (param_2 << 8);
        result = 3;
        if (*(int *)0x0605DF9C != cmd_word) {
          result = FUN_0601db84();
          *(int *)0x0605DF9C = cmd_word;     /* channel 3 state */
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if (param_1 == 4) {
        /* Channel 4: raw command pass-through */
        result = 4;
        if (*(unsigned int *)0x0605DFA4 != param_2) {
          result = FUN_0601db84();
          *(unsigned int *)0x0605DFA4 = param_2; /* channel 4 state */
          SOUND_CMD_MIRROR = param_2;
          SCSP_MAILBOX = param_2;
        }
        return result;
      }
      if (param_1 == 5) {
        /* Channel 5: effect audio (0xA37000FF base) */
        cmd_word = 0xA37000FF + (param_2 << 8);
        result = 5;
        if (*(int *)0x0605DFA8 != cmd_word) {
          result = FUN_0601db84();
          *(int *)0x0605DFA8 = cmd_word;     /* channel 5 state */
          SOUND_CMD_MIRROR = cmd_word;
          SCSP_MAILBOX = cmd_word;
        }
        return result;
      }
      if ((param_1 == 0xf) && ((param_2 & 0xA0000000) == 0xA0000000)) {
        /* Channel 0xF: direct bypass (same as channel 0) */
        result = FUN_0601db84();
        SCSP_MAILBOX = param_2;
        SOUND_CMD_MIRROR = param_2;
      }
    }
  }
  return result;
}

/* race_position_sound -- dispatches SCSP sound cues based on race checkpoint progress
 *   Monitors player checkpoint position relative to course total, triggers
 *   final-lap fanfare and position approach sounds via SCSP command dispatcher.
 *   Sound codes: 0xAE1121FF=final lap, 0xAE1127FF=approach far, 0xAE1126FF=approach near, 0xAE1146FF=generic
 */
int race_position_sound()
{
  char *delay_timer = (char *)0x06086058;       /* sound delay timer (short) */
  char *final_lap_flag = (char *)0x06087060;    /* final lap triggered flag */
  char *lap_state = (char *)0x0607EAD8;         /* race lap state (1=lap2, 2=lap3) */
  char *delay_counter = (char *)0x06086054;     /* sound delay counter (short) */
  int result;
  int car_base;
  int total_ckpts;
  total_ckpts = *(int *)(0x0604A50C +           /* checkpoint count for current course */
                  *(int *)(0x0605AD00 << 2) +
                  (int)(char)((char)CAR_COUNT * '\f'));
  car_base = CAR_PTR_TARGET;
  if (*(int *)0x06085FF4 == '\0') {
    /* Normal race — not on final stretch */
    if ((CAR_COUNT == 0) && (total_ckpts - *(int *)(car_base + PTR_DAT_0601d884) < 9)) {
      /* Player within 9 checkpoints of finish */
      if ((*(int *)0x06087060 == '\0') && (COURSE_SELECT != 0)) {
        *(int *)0x06087060 = 1;
        *(short *)delay_timer = 0;
      } else {
        *(short *)0x06086058 = *(short *)0x06086058 + 1;
      }
    }
    if ((*(int *)lap_state == 1) && (total_ckpts - *(int *)(car_base + DAT_0601d974) < 5)) {
      /* Lap 2: within 5 checkpoints of lap end */
      if ((*final_lap_flag == '\0') && (COURSE_SELECT != 0)) {
        *final_lap_flag = 1;
      } else {
        *(short *)delay_timer = *(short *)delay_timer + 1;
      }
    }
    if ((*(int *)lap_state == 2) && (total_ckpts - *(int *)(car_base + DAT_0601d974) < 3)) {
      /* Lap 3: within 3 checkpoints of lap end */
      if ((*final_lap_flag == '\0') && (COURSE_SELECT != 0)) {
        *final_lap_flag = 1;
      } else {
        *(short *)delay_timer = *(short *)delay_timer + 1;
      }
    }
    lap_state = (char *)0x06086056;             /* repurpose as sound interval ptr */
    if ((int)(total_ckpts + (unsigned int)(total_ckpts < 0)) >> 1 < *(int *)(car_base + DAT_0601d974) + 1) {
      /* Past halfway through course */
      if ((*(int *)(car_base + DAT_0601d974) == *(int *)0x06063F28 + -1) &&
         (*(int *)0x06086034 == 0)) {
        /* At final checkpoint — FINAL LAP fanfare */
        result = scsp_command_dispatch(0,0xAE1121FF);    /* SCSP: final lap fanfare */
        *(short *)lap_state = (char *)0x50;
        *(short *)delay_counter = (char *)0x50;
        *(int *)0x06086034 = 1;                 /* mark final lap sound played */
      } else {
        result = scsp_command_dispatch(0,0xAE1127FF);    /* SCSP: approach sound (far) */
        *(short *)delay_counter = PTR_DAT_0601da3c;
        *(short *)lap_state = (char *)0x14;
      }
    } else {
      result = scsp_command_dispatch(0,0xAE1126FF);      /* SCSP: approach sound (near) */
      *(short *)delay_counter = DAT_0601d976;
      *(short *)lap_state = (char *)0x14;
    }
  } else {
    /* Final lap active or race complete */
    if ((*(int *)(car_base + PTR_DAT_0601d884) != *(int *)0x06063F28 + -1) ||
       (*(int *)0x06086034 != 0)) {
      result = scsp_command_dispatch(0,0xAE1146FF);      /* SCSP: generic position cue */
      return result;
    }
    result = scsp_command_dispatch(0,0xAE1121FF);        /* SCSP: final lap fanfare */
    *(short *)delay_counter = (char *)0x50;
    *(int *)0x06086034 = 1;                     /* mark final lap sound played */
  }
  return result;
}

unsigned int FUN_0601d9b0()
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  int uVar4;

  char *puVar5;

  unsigned int uVar6;

  short uVar7;

  puVar3 = (char *)0x06086054;

  if ((int)(char)*(int *)0x06085FF4 != 0) {

    return (int)(char)*(int *)0x06085FF4;

  }

  if (((*(short *)0x06086056 == 0) || (*(int *)0x0608605A == '\x01')) ||

     (sVar1 = *(short *)0x06086056, *(short *)0x06086056 = sVar1 + -1,

     uVar4 = 0xAE112BFF, sVar1 != 1)) goto LAB_0601db20;

  if (CAR_COUNT != 0) {

    if (CAR_COUNT == 1) {

      sVar1 = *(short *)0x06086058;

      if (sVar1 == 1) {

        *(short *)0x06086056 = 0;

        scsp_command_dispatch(0,uVar4);

      }

      else if (sVar1 == 3) {

        *(short *)0x06086056 = 0;

        scsp_command_dispatch(0,uVar4);

      }

      else {

        if (sVar1 != 6) {

          *(short *)puVar3 = 100;

          goto LAB_0601db20;

        }

        *(short *)0x06086056 = 0;

        scsp_command_dispatch(0,0xAE112DFF);

      }

      *(short *)puVar3 = (char *)0x28;

    }

    else if ((CAR_COUNT == 2) && (*(short *)0x06086058 == 8)) {

      *(short *)0x06086056 = 0;

      scsp_command_dispatch(0,0xAE112FFF);

      *(short *)puVar3 = (char *)0x28;

    }

    goto LAB_0601db20;

  }

  sVar1 = *(short *)0x06086058;

  if (sVar1 == 1) {

    *(short *)0x06086056 = 0;

    scsp_command_dispatch(0,0xAE1129FF);

LAB_0601da72:

    uVar7 = 0x28;

  }

  else {

    if (sVar1 == 2) {

      *(short *)0x06086056 = 0;

      scsp_command_dispatch(0,uVar4);

      goto LAB_0601da72;

    }

    if (sVar1 == 3) {

      *(short *)0x06086056 = 0;

      scsp_command_dispatch(0,0xAE112AFF);

      uVar7 = 0x14;

    }

    else {

      if (sVar1 == 4) {

        *(short *)0x06086056 = 0;

        scsp_command_dispatch(0,uVar4);

        goto LAB_0601da72;

      }

      if (sVar1 == 5) {

        *(short *)0x06086056 = 0;

        scsp_command_dispatch(0,0xAE112CFF);

        uVar7 = 0x14;

      }

      else {

        if (sVar1 != 6) {

          *(short *)puVar3 = 100;

          goto LAB_0601db20;

        }

        *(short *)0x06086056 = 0;

        scsp_command_dispatch(0,uVar4);

        uVar7 = 0x28;

      }

    }

  }

  *(short *)puVar3 = uVar7;

LAB_0601db20:

  puVar5 = (char *)0x0608605A;

  uVar6 = (unsigned int)(unsigned char)*(int *)0x0608605A;

  if (uVar6 == 1) {

    uVar2 = *(unsigned short *)0x06086056;

    *(unsigned short *)0x06086056 = uVar2 - 1;

    uVar6 = (unsigned int)uVar2;

    if (uVar6 == 1) {

      *puVar5 = 0;

      *(short *)0x06086056 = 0;

      *(short *)puVar3 = (char *)0x28;

      uVar6 = scsp_command_dispatch(0,0xAE1120FF);

      return uVar6;

    }

  }

  return uVar6;

}

/* scsp_mailbox_wait -- Busy-wait for SCSP sound mailbox at 0x25A02C20.
 * Polls up to 100,000 iterations (0x186A0). If mailbox stays non-zero
 * throughout, sets SOUND_TIMEOUT_FLAG = 1. Returns when either the
 * mailbox clears or the timeout expires. */
int FUN_0601db84(void)
{
    register int *dest asm("r7") = (int *)0x06086050;
    register int *src asm("r6") = (int *)0x25A02C20;
    register int val asm("r5") = 1;
    register int count asm("r4") = 0x000186A0;

L:
    if (--count == 0) {
        *dest = val;   /* SOUND_TIMEOUT_FLAG = 1 */
    }
    else if (*src != 0) goto L;
}

int FUN_0601dbb8()
{

  char cVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  int uVar10;

  int iVar11;

  char *puVar12;

  puVar8 = (char *)0x06087070;

  puVar7 = (char *)0x06087068;

  puVar6 = (char *)0x06087074;

  puVar5 = (char *)0x06028400;

  puVar4 = (char *)0x0608706C;

  puVar3 = (char *)0x00009000;

  if (*(int *)0x060786AC != 0) {

    uVar10 = FUN_0601ddf6();

    return uVar10;

  }

  if ((((unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EBF4) != 0) ||

     (((unsigned int)((((int *)0x06078900)[3] & 8) == 0) &

      (unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EABC) != 0)) {

    *(int *)0x06087068 = 1;

    *(short *)0x0608706A = DAT_0601dd30;

    *(int *)0x0605DFED = 0;

    *(int *)puVar8 = *(int *)0x060786A0;

    puVar12 = (char *)0x0605DDB4;

    *(int *)puVar6 = 3;

    puVar9 = (char *)0x0605DDD4;

    if (CAR_COUNT == 2) {

      *(int *)puVar6 = 6;

      puVar12 = puVar9;

    }

    iVar11 = (*(int(*)())0x060350B0)();

    *(int *)puVar4 = *(int *)(puVar12 + (iVar11 << 2));

    *(int *)0x0608707C = 9;

    if (*(unsigned int *)puVar8 < *(unsigned int *)puVar4) {

      *(int *)0x0608707C = 10;

      *(int *)puVar4 = *(int *)puVar8;

      iVar11 = (*(int(*)())0x060350B0)();

      *(int *)(puVar12 + (iVar11 << 2)) = *(int *)puVar8;

    }

  }

  if (*puVar7 == '\0') {

    uVar10 = 0;

  }

  else {

    cVar1 = *(int *)0x0605DFED;

    *(int *)0x0605DFED = cVar1 + 0x30U;

    puVar6 = (char *)0x060639F8;

    if ((short)(unsigned short)(unsigned char)(cVar1 + 0x30U) < DAT_0601dd34) {

      iVar11 = (*(int(*)())0x060350B0)();

      (*(int(*)())puVar5)(8,0x0605E008 + iVar11 * 0xe);

      puVar12 = (char *)0x060639E0;

      (*(int(*)())puVar5)(8,*(int *)0x060639D8,0x842,

                        *(int *)(0x060639E0 + 4) + (unsigned int)(unsigned char)*(int *)(0x0608707C << 12));

      (*(int(*)())puVar5)(8,*(int *)puVar12,0x942,puVar3 + *(int *)(puVar12 + 4));

      FUN_0601e26c(*(int *)puVar4);

      (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601de24,puVar3 + *(int *)(puVar6 + 4));

      if (*(char **)puVar8 < 0x000927BF) {

        FUN_0601e26c(*(int *)puVar8);

      }

      else {

        FUN_0601e26c(0x000927BF);

      }

      uVar10 = (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601de26,

                                 puVar3 + *(int *)(0x060639F8 + 4));

    }

    else {

      uVar10 = FUN_0601ddf6();

    }

    sVar2 = *(short *)0x0608706A;

    *(short *)0x0608706A = sVar2 + -1;

    if ((short)(sVar2 + -1) == 0) {

      *puVar7 = 0;

      uVar10 = FUN_0601ddf6();

      return uVar10;

    }

  }

  return uVar10;

}

/* hud_sprite_setup -- Configure 3 HUD sprite entries for lap/timer display.
 * Sets VDP sprite attributes for tiles 0x7C2, 0x8C2, 0x9C2 at dest 0x0605ACE3.
 * Third sprite uses FUN_060283E0 (wide sprite variant, 0xE000 size). */
int FUN_0601ddf6(void)
{
    register int dest asm("r0") = 0x0605ACE3;
    register int vdp_attr_set asm("r3") = 0x060284AE;
    (*(int(*)())vdp_attr_set)(8, 0x7C2, 0x90, dest);
    (*(int(*)())vdp_attr_set)(8, 0x8C2, 0x90, dest);
    (*(void(*)())0x060283E0)(8, 0x9C2, 0xE000, dest);
}

/* lap_record_notify -- Display lap time and "NEW RECORD" indicator.
 * Renders current lap time via FUN_0601e26c (clamped to 9:59.99),
 * draws time digits sprite. If lap time beats stored record at
 * car struct +DAT_0601df18, updates high score table and shows
 * "NEW RECORD" banner with animation counter at 0x0605DFEC. */
int FUN_0601de50()
{
  int result;
  int *sprite_data;

  if ((char *)(GAME_STATE_VAR * 5) < 0x000927BF) {     /* time within display range */
    FUN_0601e26c();                                     /* render current time */
  } else {
    FUN_0601e26c(0x000927BF);                           /* clamp to 9:59.99 max */
  }
  (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601df16,  /* draw lap time digits */
             0x00009000 + *(int *)(0x06063750 + DAT_0601df14));
  result = 0;
  if (*(unsigned int *)(0x06078900 + DAT_0601df18) < *(unsigned int *)0x06086008 &&
      *(int *)(0x06078900 + DAT_0601df1a) != 0) {      /* new record beaten */
    *(int *)
     (*(int *)(0x0605DE24 + (*(int *)(0x0607EAD8 << 1) + DEMO_MODE_FLAG) << 2) + 4
     ) = *(int *)(0x06078900 + DAT_0601df18);           /* update high score table */
    sprite_data = (int *)(0x06063750 + DAT_0601df1c);
    (*(int(*)())0x06028400)(8, *sprite_data, 0x3c2,     /* draw record time sprite */
               0x0000A000 + sprite_data[1]);
    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';      /* advance animation counter */
    if ((char)*(int *)0x0605DFEC < '\0') {              /* animation overflow → show banner */
      result = (*(int(*)())0x060283E0)(8, 0x442, 0x0000E000, 0x0605ACE3); /* "NEW RECORD" sprite */
      return result;
    }
    FUN_0601e26c(*(int *)(0x06078900 + DAT_0601df18));  /* render record time */
    result = (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)PTR_DAT_0601df20,
                              0x0000A000 + *(int *)(0x06063750 + DAT_0601df14));
  }
  return result;
}

/* race_time_display -- Show total race time with best-time comparison.
 * Renders current total time and best lap time from car struct.
 * If current time beats stored best at 0x0607863C vs 0x06086004,
 * shows "NEW RECORD" banner with animation counter at 0x0605DFEC.
 * Uses sprite renderer at 0x06028400, time formatter FUN_0601e26c. */
int FUN_0601df88()
{
  int result;
  int car_offset;

  car_offset = 0x2a8;
  /* --- lap split time display --- */
  if (*(unsigned int *)(0x06078900 + car_offset + -0x68) < *(unsigned int *)0x06086008) {
    (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + DAT_0601e024), 0x3c2,  /* split label sprite */
               0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601e024) + 4));
    FUN_0601e26c(*(int *)(0x06078900 + DAT_0601e028));  /* render split time */
    (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e02a,  /* split time digits */
               0x0000A000 + *(int *)(0x06063750 + car_offset + 4));
  }
  /* --- total time display --- */
  FUN_0601e26c(*(int *)0x0607863C);                     /* render total time */
  result = (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e02c,  /* total time digits */
                            0x00009000 + *(int *)(0x06063750 + car_offset + 4));
  /* --- best time comparison --- */
  if (*(unsigned int *)0x0607863C < *(unsigned int *)0x06086004) {  /* beat best time */
    (*(int(*)())0x06028400)(8, *(int *)(0x06063750 + DAT_0601e02e), 0x4c2,  /* best time label */
                      0x0000A000 + *(int *)((int)(0x06063750 + DAT_0601e02e) + 4));
    if (*(unsigned int *)0x0607863C < 0x000927BF) {     /* within displayable range */
      FUN_0601e26c(*(int *)0x0607863C);                 /* render best time */
    } else {
      FUN_0601e26c(0x000927BF);                         /* clamp to 9:59.99 */
    }
    (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e0e2,  /* best time digits row 1 */
                      0x00009000 + *(int *)(0x06063750 + car_offset + 4));
    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';      /* advance animation counter */
    if ((char)*(int *)0x0605DFEC < '\0') {              /* animation overflow → show banner */
      result = (*(int(*)())0x060283E0)(8, 0x542, 0x0000E000, 0x0605ACE3); /* "NEW RECORD" sprite */
      return result;
    }
    if (*(unsigned int *)0x0607863C < 0x000927BF) {     /* within displayable range */
      FUN_0601e26c(*(int *)0x0607863C);                 /* render best time again */
    } else {
      FUN_0601e26c(0x000927BF);                         /* clamp to 9:59.99 */
    }
    result = (*(int(*)())0x06028400)(8, 0x0605DFF4, (int)DAT_0601e0e4,  /* best time digits row 2 */
                              0x0000A000 + *(int *)(0x06063750 + car_offset + 4));
  }
  return result;
}
