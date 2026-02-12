#include "game.h"

extern int DAT_060100f6;
extern int DAT_060100f8;
extern int DAT_060101b2;
extern int DAT_0601038c;
extern int DAT_0601038e;
extern int DAT_0601043e;
extern int DAT_0601064a;
extern int DAT_06010736;
extern int DAT_0601096e;
extern int DAT_06010a2a;
extern int DAT_06010c4c;
extern int DAT_06010c4e;
extern int DAT_0601112c;
extern int DAT_0601112e;
extern int DAT_06011206;
extern int DAT_06011208;
extern int DAT_0601120a;
extern int DAT_060112e2;
extern int DAT_060112e4;
extern int DAT_060112e6;
extern int DAT_060113b2;
extern int DAT_060113b4;
extern int DAT_060113b6;
extern int DAT_06011462;
extern int DAT_06011464;
extern int DAT_06011466;
extern int DAT_060115c6;
extern int DAT_06011fd4;
extern int DAT_06011fd6;
extern int DAT_06011fd8;
extern int DAT_06011fda;
extern void FUN_06010d94();
extern void FUN_060111e2();
extern void FUN_06011310();
extern void FUN_060116a8(int,int,short,int,short);
extern int FUN_06011978();
extern void FUN_06011e7c();
extern int PTR_DAT_06010274;
extern int PTR_DAT_06010278;
extern int PTR_DAT_0601030c;
extern int PTR_DAT_06010440;
extern int PTR_DAT_06010508;
extern int PTR_DAT_06010870;
extern int PTR_DAT_06010970;
extern int PTR_DAT_06010ac8;
extern int PTR_DAT_06010c50;
extern int PTR_DAT_06011130;
extern int PTR_DAT_0601120c;
extern int PTR_DAT_06011f04;
extern short DAT_06011efe;
extern short DAT_06011f00;
extern short DAT_06011f02;

int FUN_060100a4(param_1)
    unsigned char param_1;
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  int iVar4;

  char *puVar5;

  int iVar6;

  char *puVar7;

  int iVar8;

  puVar7 = (char *)0x00010000;

  sVar1 = (unsigned short)param_1 + DAT_060100f6;

  iVar6 = (int)DAT_060100f8;

  iVar4 = *(int *)(0x060447C8 + (unsigned int)(param_1 << 4));

  puVar5 = *(char **)((int)(0x060447C8 + (unsigned int)(param_1 << 4)) + 4);

  if ((unsigned int)param_1 == CAR_COUNT) {

    puVar3 = 0x0605D0BC + (unsigned int)(param_1 << 5);

  }

  else {

    puVar3 = 0x0605D0BC + (param_1 + 3) << 5;

  }

  (*(int(*)())0x0602766C)(*(int *)(0x06078888 + (unsigned int)(param_1 << 2)),puVar3,0x20);

  if (4 < (unsigned char)*(int *)0x0607887F) {

    if ((unsigned int)param_1 == CAR_COUNT) {

      if (*(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) < 0x1e) {

        uVar2 = *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) + 1;

        *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) = uVar2;

      }

      else {

        *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) = 0x20;

        uVar2 = 0x20;

      }

      iVar4 = iVar4 + *(int *)(0x060447F8 + (char)(param_1 * '\f')) * (unsigned int)uVar2;

      puVar5 = puVar5 + *(int *)((int)(0x060447F8 + (char)(param_1 * '\f')) + 4) * (unsigned int)uVar2

      ;

      iVar8 = (unsigned int)uVar2 * (int)DAT_060101b2;

    }

    else {

      if (0x1d < *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1))) {

        return (unsigned int)(param_1 << 1);

      }

      uVar2 = *(short *)(0x06078870 + (unsigned int)(param_1 << 1)) + 1;

      *(unsigned short *)(0x06078870 + (unsigned int)(param_1 << 1)) = uVar2;

      iVar8 = (unsigned int)uVar2 * 0x72b;

    }

    iVar6 = iVar6 + (unsigned int)uVar2 * -0x800;

    puVar7 = puVar7 + -iVar8;

  }

  if (0xb < (unsigned char)*(int *)0x0607887F) {

    puVar5 = (short *)0x00960000;

  }

  iVar4 = (*(int(*)())0x06011AF4)(iVar4,puVar5,

                     (*(unsigned int *)(0x06044844 + *(int *)(0x0605AA98 << 2)) >> 1) << 0x10,

                     0x00200000,iVar6,puVar7,(int)sVar1);

  return iVar4;

}

/* player_count_detect -- Detect number of players from cabinet inputs.
 * Reads raw input word at 0x06063D9C, XOR with 0xFFFF and mask to low byte.
 * Thresholds: >0x72B = 2 players, >0xC0 = 1 player (additive).
 * Sets CAR_COUNT (0=single, 1=2P, 2=4P) and mirrors to 0x0607887E. */
void FUN_06010238(void)
{
  unsigned short raw = *(unsigned short *)0x06063D9C;
  int *player_count = (int *)0x0607EADC;
  unsigned int input_val = ((unsigned int)raw ^ 0x0000FFFF) & 0xff;

  *player_count = 0;
  if (0x72b < (int)input_val) {
    *player_count = *player_count + 1;
  }
  if (0xc0 < (int)input_val) {
    *player_count = *player_count + 1;
  }
  *(int *)0x0607887E = (char)*player_count;
  CAR_COUNT = *player_count;
}

/* coin_start_handler -- Handle coin insert / start button during attract.
 * Decrements start timer at 0x0607EBCC. If start bits (PTR_DAT_0601030c)
 * are set in param_1: transitions to GAME_STATE=6 (service mode).
 * Otherwise: if timer expired or confirm button pressed, loads sound bank
 * for current player count, sets game mode to 2, mirrors CAR_COUNT.
 * On course 0 with START pressed, enables route select (0x0605AB18). */
void FUN_060102ea(unsigned short param_1)
{
  int *start_timer = (int *)0x0607EBCC;
  *start_timer = *start_timer - 1;

  if ((param_1 & PTR_DAT_0601030c) == 0) {
    if ((*start_timer < 1) || ((param_1 & DAT_0601038c) != 0)) {
      (*(int(*)())0x0601D5F4)(0, *(int *)(0x0604481C + *(int *)(0x0607EADC << 2)));
      *start_timer = 0;
      *(int *)0x0607887F = 2;              /* set game mode */
      *(int *)0x06078648 = (char)CAR_COUNT;
      *(int *)0x0605AB18 = 0;
      if ((*(int *)0x06085FF4 == '\0') &&
          (COURSE_SELECT == 0 && ((*(unsigned short *)0x06063D98 & DAT_0601038e) != 0))) {
        *(char *)0x0605AB18 = 1;           /* enable route select */
      }
    }
  } else {
    GAME_STATE = 6;                         /* service mode transition */
  }
}

/* player_select_dpad -- Handle D-pad input for player/character selection.
 * Up (bit 0x8000): increment selection (max 1).
 * Down (DAT_0601043e): decrement selection (min 0).
 * Mirrors selection to 0x0607EAB8 and 0x06078868, then DMA-copies
 * the appropriate character sprite data (0xC0 bytes) for both slots. */
void FUN_060103b8(unsigned int param_1)
{
  int *select_idx = (int *)0x0607EADC;  /* player selection index */

  if (((param_1 & 0xffff & 0x00008000) != 0) && (*select_idx < 1)) {
    *select_idx = *select_idx + 1;
  }
  if (((param_1 & 0xffff & (int)DAT_0601043e) != 0) && (0 < *select_idx)) {
    *select_idx = *select_idx + -1;
  }

  *(int *)0x0607EAB8 = *select_idx;     /* mirror to character select */
  *(int *)0x06078868 = *select_idx;      /* mirror to car select */

  if (*(int *)0x0607EAB8 == 0) {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D05C, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D088, 0xc0);
  } else {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D084, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D060, 0xc0);
  }
}

/* player_select_analog -- Analog input version of player/character selection.
 * Reads raw analog value from 0x06063D9C, inverts (XOR 0xFFFF), masks to low byte.
 * Resets selection to 0, then if analog value > 0xC0 increments to 1.
 * Mirrors to 0x0607EAB8 and 0x06078868, DMA-copies sprite data (0xC0 bytes). */
void FUN_06010470(void)
{
  int *select_idx = (int *)0x0607EADC;
  unsigned int analog_val = (unsigned int)*(unsigned short *)0x06063D9C ^ 0x0000FFFF;

  *select_idx = 0;
  if (0xc0 < (int)(analog_val & 0xff)) {
    *select_idx = *select_idx + 1;
  }

  *(int *)0x0607EAB8 = *select_idx;     /* mirror to character select */
  *(int *)0x06078868 = *select_idx;      /* mirror to car select */

  if (*(int *)0x0607EAB8 == 0) {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D05C, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D088, 0xc0);
  } else {
    (*(int(*)())0x0602766C)(*(int *)0x06078884, *(int *)0x0605D084, 0xc0);
    (*(int(*)())0x0602766C)(*(int *)0x06078880, *(int *)0x0605D060, 0xc0);
  }
}

unsigned int FUN_060104e0(param_1)
    unsigned int param_1;
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  int iVar9;

  int *puVar10;

  int uVar11;

  puVar5 = (short *)0x060788A8;

  puVar4 = (char *)0x06078868;

  puVar3 = (int *)0x0607EAB8;

  puVar2 = (char *)0x0607EADC;

  cVar1 = *(int *)0x0605AB16;

  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {

LAB_06010504:

    iVar9 = 5;

  }

  else {

    if (cVar1 != '\x03') {

      if (cVar1 == '\x04') goto LAB_06010504;

      if ((cVar1 != '\x05') && (cVar1 != '\x06')) {

        if (cVar1 == '\a') {

          iVar9 = 9;

        }

        else {

          iVar9 = 3;

        }

        goto LAB_06010570;

      }

    }

    iVar9 = 7;

  }

LAB_06010570:

  if (*(int *)0x0605AB17 == '\a') {

    iVar9 = 0xb;

  }

  uVar6 = (unsigned int)(char)*(int *)0x0605AB17;

  if (uVar6 == 0xf) {

    iVar9 = 0xd;

  }

  if ((param_1 & 0xffff & (unsigned int)0x00008000) == 0) {

    if ((param_1 & 0xffff & (int)DAT_0601064a) != 0) {

      *(char **)0x0607889C = 0x00010000;

      iVar7 = *(int *)puVar2;

      *(int *)puVar2 = iVar7 + -1;

      if (iVar7 + -1 < 0) {

        *(int *)puVar2 = iVar9;

      }

      uVar11 = 0xFFF40000;

      uVar6 = (unsigned int)(unsigned char)*puVar5;

      if (uVar6 == 0) {

        *puVar5 = 1;

        *(int *)0x06078898 = uVar11;

        *(int *)0x060788A4 = *(int *)puVar2;

      }

      else {

        *puVar5 = 0;

        *(int *)0x06078894 = uVar11;

        *(int *)0x060788A0 = *(int *)puVar2;

      }

    }

  }

  else {

    *(int *)0x0607889C = 0xFFFF0000;

    iVar7 = *(int *)puVar2;

    *(int *)puVar2 = iVar7 + 1;

    if (iVar9 < iVar7 + 1) {

      *(int *)puVar2 = 0;

    }

    if (*puVar5 == '\0') {

      *puVar5 = 1;

      (*(int(*)())0x060359E4)();

      uVar6 = (*(int(*)())0x060357B8)();

      *(unsigned int *)0x06078898 = uVar6;

      *(int *)0x060788A4 = *(int *)puVar2;

    }

    else {

      *puVar5 = 0;

      (*(int(*)())0x060359E4)();

      uVar6 = (*(int(*)())0x060357B8)();

      *(unsigned int *)0x06078894 = uVar6;

      *(int *)0x060788A0 = *(int *)puVar2;

    }

  }

  uVar8 = *(unsigned int *)puVar2;

  *(unsigned int *)puVar4 = uVar8;

  *(unsigned int *)puVar3 = uVar8 & 1;

  if (*(unsigned int *)puVar4 < 10) {

    if (*puVar5 == '\0') {

      uVar11 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      puVar10 = (int *)0x06078884;

    }

    else {

      uVar11 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      puVar10 = (int *)0x06078880;

    }

    uVar6 = (*(int(*)())0x0602766C)(*puVar10,uVar11,0xc0);

  }

  if ((param_1 & 0xffff & (unsigned int)0x0000C000) != 0) {

    if (*(unsigned int *)puVar4 < 0xc) {

      iVar9 = *(int *)puVar4;

    }

    else {

      iVar9 = *(int *)puVar4 + -2;

    }

    uVar6 = (*(int(*)())0x0602761E)(0x25F00000 + (*(int *)((int)(int)puVar3 << 1) + 0x23) << 5,

                       0x0605CA9C + (iVar9 << 6),0x40);

    return uVar6;

  }

  return uVar6;

}

unsigned int FUN_06010760()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  int uVar12;

  puVar5 = (short *)0x0607EADC;

  puVar4 = (char *)0x06078868;

  puVar3 = (int *)0x060788A8;

  puVar2 = (char *)0x0602761E;

  cVar1 = *(int *)0x0605AB16;

  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {

LAB_06010782:

    iVar11 = 5;

  }

  else {

    if (cVar1 != '\x03') {

      if (cVar1 == '\x04') goto LAB_06010782;

      if ((cVar1 != '\x05') && (cVar1 != '\x06')) {

        if (cVar1 == '\a') {

          iVar11 = 9;

        }

        else {

          iVar11 = 3;

        }

        goto LAB_060107c8;

      }

    }

    iVar11 = 7;

  }

LAB_060107c8:

  if (*(int *)0x0605AB17 == '\a') {

    iVar11 = 0xb;

  }

  if (*(int *)0x0605AB17 == '\x0f') {

    iVar11 = 0xd;

  }

  uVar7 = ((unsigned int)*(unsigned short *)0x06063D9C ^ (unsigned int)0x0000FFFF) & 0xff;

  uVar8 = uVar7;

  if (0x90 < (int)uVar7) {

    *(int *)0x0607889C = 0xFFFF0000;

    *(int *)0x0605AA9C = 0x1e;

    iVar10 = *(int *)puVar5;

    *(int *)puVar5 = iVar10 + 1;

    if (iVar11 < iVar10 + 1) {

      *(int *)puVar5 = 0;

    }

    puVar6 = (char *)0x000C0000;

    uVar8 = (unsigned int)(unsigned char)*puVar3;

    if (uVar8 == 0) {

      *puVar3 = 1;

      *(char **)0x06078898 = puVar6;

      *(int *)0x060788A4 = *(int *)puVar5;

    }

    else {

      *puVar3 = 0;

      *(char **)0x06078894 = puVar6;

      *(int *)0x060788A0 = *(int *)puVar5;

    }

  }

  if (uVar7 < 0x70) {

    *(char **)0x0607889C = 0x00010000;

    *(int *)0x0605AA9C = 0x1e;

    iVar10 = *(int *)puVar5;

    *(int *)puVar5 = iVar10 + -1;

    if (iVar10 + -1 < 0) {

      *(int *)puVar5 = iVar11;

    }

    uVar12 = 0xFFF40000;

    uVar8 = (unsigned int)(unsigned char)*puVar3;

    if (uVar8 == 0) {

      *puVar3 = 1;

      *(int *)0x06078898 = uVar12;

      *(int *)0x060788A4 = *(int *)puVar5;

    }

    else {

      *puVar3 = 0;

      *(int *)0x06078894 = uVar12;

      *(int *)0x060788A0 = *(int *)puVar5;

    }

  }

  uVar9 = *(unsigned int *)puVar5;

  *(unsigned int *)puVar4 = uVar9;

  *(unsigned int *)0x0607EAB8 = uVar9 & 1;

  if (*(unsigned int *)puVar4 < 10) {

    if (*puVar3 == '\0') {

      uVar12 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      iVar11 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x40;

    }

    else {

      uVar12 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      iVar11 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + DAT_0601096e + 0x40;

    }

    uVar8 = (*(int(*)())puVar2)(iVar11,uVar12,0xc0);

  }

  if ((uVar7 < 0x70) || (0x90 < (int)uVar7)) {

    if (*(unsigned int *)puVar4 < 0xc) {

      iVar11 = *(int *)puVar4;

    }

    else {

      iVar11 = *(int *)puVar4 + -2;

    }

    uVar8 = (*(int(*)())puVar2)(0x25F00000 + (*(int *)(0x0607EAB8 << 1) + 0x23) << 5,

                              0x0605CA9C + (iVar11 << 6),0x40);

  }

  return uVar8;

}

/* character_sprite_dma -- DMA-copy character sprite data for current selection.
 * Normal mode (0x06083255 == 0): copies 0xC0 bytes from sprite table indexed
 *   by car selection (0x06078868), dest from scroll offset + VDP base + 0x40.
 * Demo mode: copies 0x20 bytes from demo sprite table indexed by 0x0607EAB8,
 *   dest includes player count offset and additional scroll offset.
 * Always copies a second sprite block for the overlay at 0x0607ED91. */
void FUN_06010994(void)
{
  int scroll_base = *(int *)0x06063F5C;   /* VDP scroll base address */
  int scroll_page = *(int *)0x06059FFC;   /* current scroll page index */
  int dest, src, size;

  if (*(int *)0x06083255 == '\0') {
    size = 0xc0;
    src = *(int *)(0x0605D05C + *(int *)(0x06078868 << 2));
    dest = *(int *)(scroll_page << 3) + scroll_base + 0x40;
  } else {
    size = 0x20;
    src = *(int *)(0x0605D0AC + *(int *)(0x0607EAB8 << 2));
    dest = ((unsigned int)(unsigned char)((int *)0x060448B5)[CAR_COUNT] +
            (unsigned int)*(unsigned short *)0x0607886C) << 5 +
            *(int *)(scroll_page << 3) + scroll_base;
  }

  (*(int(*)())0x0602761E)(dest, src, size);
  (*(int(*)())0x0602761E)(*(int *)(scroll_page << 3) + scroll_base + DAT_06010a2a + 0x40,
                    *(int *)(0x0605D05C + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2)));
}

/* subsystem_dma_transfer -- DMA-copy data block for subsystem slot.
 * Computes dest from scroll offset + subsystem base + 0x40,
 * src from table at 0x0605D05C indexed by param. */
void FUN_06010a5c(int slot_idx)
{
    (*(int(*)())0x0602761E)(
        *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + PTR_DAT_06010ac8 + 0x40,
        *(int *)(0x0605D05C + (slot_idx << 2)));
}

/* sound_bank_load -- Load sound bank for current course or demo mode.
 * In normal mode, loads bank from course table (0x0604483C indexed by
 * course ID at 0x0607EAB8). In demo mode, uses fixed bank IDs
 * (0xAB110BFF or 0xAB110AFF for player 2). Sends via SCSP command (0x0601D5F4). */
int FUN_06010b54(void)
{
  int result;

  if (DEMO_MODE_FLAG == 0) {
    result = (*(int(*)())0x0601D5F4)(0, *(int *)(0x0604483C + *(int *)(0x0607EAB8 << 2)));
  } else {
    int bank = 0xAB110BFF;
    if (*(int *)0x06078644 == 1) {
      bank = 0xAB110AFF;                   /* player 2 alternate bank */
    }
    result = (*(int(*)())0x0601D5F4)(0, bank);
  }
  return result;
}

int FUN_06010bc4()
{

  unsigned short uVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int uVar7;

  unsigned char *pbVar8;

  puVar6 = (char *)0x06078878;

  puVar5 = (short *)0x0608A52C;

  puVar4 = (char *)0x06078898;

  puVar3 = (int *)0x06078894;

  sVar2 = PTR_DAT_06010c50;

  uVar1 = DAT_06010c4e;

  pbVar8 = (unsigned char *)-495;

  if (*(int *)0x06085FF4 == '\0') {

    *(int *)0x060788A0 = 1;

    *(short *)puVar6 = *(short *)puVar6 + sVar2;

    FUN_06011310();

    puVar3 = (int *)0x060270D0;

    *(int *)puVar5 = *(int *)puVar5 + 0x30;

    (*(int(*)())puVar3)();

    *(int *)0x0607884C = 1;

    *(char **)0x06078850 = 0x00038000;

    *(int *)0x06078854 = 0xFFFF0000;

    *(char **)0x06078858 = 0x0006B333;

    *(char **)0x06063574 = 0x06010F04;

    *(short *)0x21000000 = (short)0x0000FFFF;

    FUN_06010d94(0,0xFFFC8000,0xFFFF0000,0x0006B333);

    puVar3 = (int *)0x0603C000;

    do {

    } while ((*pbVar8 & uVar1) != uVar1);

    *pbVar8 = *pbVar8 & 0xf;

    uVar7 = (*(int(*)())puVar3)();

  }

  else {

    *(short *)0x06078878 = *(short *)0x06078878 + PTR_DAT_06010c50;

    puVar6 = (char *)0x0607889C;

    *(int *)puVar3 = *(int *)puVar3 + *(int *)0x0607889C;

    *(int *)puVar4 = *(int *)puVar4 + *(int *)puVar6;

    if (*(int *)puVar6 < 0) {

      if (*(int *)0x060788A8 == '\0') {

        if (*(int *)puVar3 < 1) {

          *(int *)puVar3 = 0;

          *(int *)puVar6 = 0;

        }

      }

      else if ((*(int *)0x060788A8 == '\x01') && (*(int *)puVar4 < 1)) {

        *(int *)puVar4 = 0;

        *(int *)puVar6 = 0;

      }

    }

    else if (*(int *)0x060788A8 == '\0') {

      if (-1 < *(int *)puVar3) {

        *(int *)puVar3 = 0;

        *(int *)puVar6 = 0;

      }

    }

    else if ((*(int *)0x060788A8 == '\x01') && (-1 < *(int *)puVar4)) {

      *(int *)puVar4 = 0;

      *(int *)puVar6 = 0;

    }

    FUN_060111e2();

    puVar6 = (char *)0x060270D0;

    *(int *)puVar5 = *(int *)puVar5 + 0x30;

    (*(int(*)())puVar6)();

    *(int *)0x0607884C = 1;

    *(int *)0x06078850 = *(int *)puVar4;

    *(int *)0x06078854 = 0xFFFF3334;

    *(char **)0x06078858 = 0x00063333;

    *(char **)0x06063574 = 0x06010F04;

    *(short *)0x21000000 = (short)0x0000FFFF;

    FUN_06010d94(0,*(int *)puVar3,0xFFFF3334,0x00063333);

    puVar3 = (int *)0x0603C000;

    do {

    } while ((*pbVar8 & uVar1) != uVar1);

    *pbVar8 = *pbVar8 & 0xf;

    uVar7 = (*(int(*)())puVar3)();

  }

  *(int *)puVar5 = *(int *)puVar5 + -0x30;

  return uVar7;

}

void FUN_06010d94(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  short *psVar8;

  puVar2 = (char *)0x06026E0C;

  puVar1 = (char *)0x06089EDC;

  if (*(unsigned int *)0x060788A0 < 10) {

    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + 0x30;

    (*(int(*)())puVar2)();

    puVar2 = (char *)0x06026E2E;

    (*(int(*)())0x06026E2E)(param_2,param_3,param_4);

    (*(int(*)())0x06026EDE)((int)*(short *)0x06078878);

    puVar3 = (int *)0x0606212C;

    (*(int(*)())0x06031D8C)(*(int *)0x0606212C,*(int *)0x060621D8);

    puVar6 = (char *)0x06062180;

    puVar5 = (short *)0x06031A28;

    puVar4 = (char *)0x060620D8;

    psVar8 = (short *)(0x06089E44 + (param_1 << 1));

    (*(int(*)())0x06031A28)(*(int *)0x060620D8,(int)*psVar8,*(int *)0x06062180);

    (*(int(*)())0x06026DBC)();

    (*(int(*)())puVar2)(*(int *)0x06044640,*(int *)0x06044644,

                      -*(int *)0x06044648);

    (*(int(*)())0x06031D8C)(*(int *)(puVar3 + 4),*(int *)0x060621DC);

    (*(int(*)())puVar5)(*(int *)(puVar4 + 4),(int)*psVar8,*(int *)(puVar6 + 4));

    puVar7 = (char *)0x06026DBC;

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

    (*(int(*)())puVar7)();

    (*(int(*)())puVar2)(*(int *)0x0604464C,*(int *)0x06044650,

                      -*(int *)0x06044654);

    (*(int(*)())0x06031D8C)(*(int *)(puVar3 + 8),*(int *)0x060621E0);

    (*(int(*)())puVar5)(*(int *)(puVar4 + 8),(int)*psVar8,*(int *)(puVar6 + 8));

    puVar7 = (char *)0x06026DBC;

    *(int *)puVar1 = *(int *)puVar1 + -0x30;

    (*(int(*)())puVar7)();

    (*(int(*)())puVar2)(*(int *)0x06044670,*(int *)0x06044674,

                      -*(int *)0x06044678);

    (*(int(*)())0x06031D8C)(*(int *)(puVar3 + 0xc),*(int *)0x060621E4);

    (*(int(*)())puVar5)(*(int *)(puVar4 + 0xc),(int)*psVar8,*(int *)(puVar6 + 0xc));

    *(int *)puVar1 = *(int *)puVar1 + -0x60;

  }

  return;

}

void FUN_06011094()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int local_30;

  int iStack_2c;

  int iStack_28;

  puVar3 = (int *)0x0605AC70;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x0607EADC;

  if (*(int *)0x0607887F == '\x03') {

    if ((FRAME_COUNTER & 1) == 0) {

      iStack_28 = 4;

    }

    else {

      iStack_28 = 3;

    }

  }

  else if ((FRAME_COUNTER & 3) < 2) {

    iStack_28 = 3;

  }

  else {

    iStack_28 = 4;

  }

  iVar8 = *(int *)(0x06063750 + DAT_0601112c);

  iVar7 = *(int *)(0x06063750 + DAT_0601112c + 0x10);

  local_30 = iStack_28;

  if (*(int *)0x0607EADC != 0) {

    local_30 = 3;

  }

  (*(int(*)())0x06028400)(4,*(int *)(0x0605AC70 + *(int *)(0x06078644 << 2)),0x282,

             (local_30 << 12) + iVar8);

  puVar5 = (short *)0x0605AB98;

  puVar4 = (char *)0x0605AD00;

  (*(int(*)())puVar2)(8,*(int *)(0x0605AB98 + *(int *)(0x0605AD00 << 2)),

                    (int)PTR_DAT_06011130,(local_30 << 12) + iVar7);

  iStack_2c = iStack_28;

  if (*(int *)puVar1 != 1) {

    iStack_2c = 3;

  }

  iVar6 = (iStack_2c + 2) << 12;

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + *(int *)(0x06078644 << 2) + 0xc),(int)DAT_06011206

                    ,iVar6 + iVar8);

  (*(int(*)())puVar2)(8,*(int *)(puVar5 + *(int *)((int)(int)puVar4 << 2) + 0xc),0x4a8,

                    iVar6 + iVar7);

  if (*(int *)puVar1 != 2) {

    iStack_28 = 3;

  }

  iVar6 = (iStack_28 + 4) << 12;

  (*(int(*)())puVar2)(4,*(int *)(puVar3 + *(int *)(0x06078644 << 2) + 0x18),

                    0x2ba,iVar6 + iVar8);

  (*(int(*)())puVar2)(8,*(int *)(puVar5 + *(int *)((int)(int)puVar4 << 2) + 0x18),

                    (int)PTR_DAT_0601120c,iVar6 + iVar7);

  return;

}

void FUN_060111e2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  puVar3 = (int *)0x06063828;

  puVar2 = (char *)0x06028400;

  puVar1 = (char *)0x06078644;

  iVar5 = 3;

  if ((*(int *)0x0607887F == '\v') && ((FRAME_COUNTER & 1) == 0)) {

    iVar5 = 4;

  }

  if (*(int *)0x0607EAB8 == 0) {

    iVar5 = (iVar5 << 12);

    (*(int(*)())0x06028400)(4,0x0605A7FC,0x2a0,*(int *)(0x06063828 + 4) + iVar5);

    (*(int(*)())puVar2)(4,*(int *)

                         (0x0605ABBC +

                         (unsigned int)(*(int *)puVar1 != 0) << 2 + *(int *)(0x06078868 << 3)),

                      0x530,*(int *)(puVar3 + 4) + iVar5);

    iVar4 = (int)DAT_060112e6;

    iVar5 = *(int *)(puVar3 + 4) + iVar5;

    puVar3 = (int *)0x0605A9B8;

    if (*(int *)puVar1 != 0) {

      puVar3 = (int *)0x0605A9B0;

    }

  }

  else {

    iVar5 = (iVar5 + 2) << 12;

    (*(int(*)())0x06028400)(4,0x0605A8B6,0x2a0,*(int *)(0x06063828 + 4) + iVar5);

    (*(int(*)())puVar2)(4,*(int *)

                         (0x0605ABBC +

                         (unsigned int)(*(int *)puVar1 != 0) << 2 + *(int *)(0x06078868 << 3)),

                      0x530,*(int *)(puVar3 + 4) + iVar5);

    iVar4 = (int)DAT_060112e6;

    iVar5 = *(int *)(puVar3 + 4) + iVar5;

    puVar3 = (int *)0x0605A9B8;

    if (*(int *)puVar1 != 0) {

      puVar3 = (int *)0x0605A9B0;

    }

  }

  (*(int(*)())puVar2)(4,puVar3,iVar4,iVar5);

  return;

}

void FUN_06011310()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int local_20;

  puVar2 = (char *)0x06063828;

  puVar1 = (char *)0x06028400;

  if (*(int *)0x0607887F == '\v') {

    if ((FRAME_COUNTER & 1) == 0) {

      iVar5 = 4;

    }

    else {

      iVar5 = 3;

    }

  }

  else if ((FRAME_COUNTER & 3) < 2) {

    iVar5 = 3;

  }

  else {

    iVar5 = 4;

  }

  local_20 = iVar5;

  if (*(int *)0x0607EADC != 0) {

    local_20 = 3;

  }

  local_20 = (local_20 << 12);

  (*(int(*)())0x06028400)(4,0x0605A7FC,0x288,*(int *)(0x06063828 + 4) + local_20);

  puVar3 = (int *)0x06078644;

  puVar4 = (char *)0x0605A9B8;

  if (*(int *)0x06078644 != 0) {

    puVar4 = (char *)0x0605A9B0;

  }

  (*(int(*)())puVar1)(4,puVar4,(int)DAT_060113b4,*(int *)(puVar2 + 4) + local_20);

  puVar4 = (char *)0x0605A978;

  if (*(int *)puVar3 != 0) {

    puVar4 = (char *)0x0605A998;

  }

  (*(int(*)())puVar1)(4,puVar4,0x518,*(int *)(puVar2 + 4) + local_20);

  local_20 = iVar5;

  if (*(int *)0x0607EADC != 1) {

    local_20 = 3;

  }

  iVar5 = (local_20 + 2) << 12;

  (*(int(*)())puVar1)(4,0x0605A8B6,(int)DAT_06011462,*(int *)(puVar2 + 4) + iVar5);

  puVar4 = (char *)0x0605A9B8;

  if (*(int *)puVar3 != 0) {

    puVar4 = (char *)0x0605A9B0;

  }

  (*(int(*)())puVar1)(4,puVar4,0x54a,*(int *)(puVar2 + 4) + iVar5);

  puVar4 = (char *)0x0605A980;

  if (*(int *)puVar3 != 0) {

    puVar4 = (char *)0x0605A9A0;

  }

  (*(int(*)())puVar1)(4,puVar4,(int)DAT_06011466,*(int *)(puVar2 + 4) + iVar5);

  return;

}

/* gauge_needle_update -- Interpolate gauge needle position toward target.
 * Reads target position from lookup table at 0x060447A8, indexed by
 * player selection and param_1. Smooths toward target by halving the
 * difference each frame (exponential approach).
 * In game modes 3/0xB, skips rendering on odd frames.
 * Calls FUN_060116a8 (needle sprite render) and FUN_06011978 (gauge marks). */
unsigned int FUN_060114ac(unsigned int param_1)
{
  int *needle_pos = (int *)0x06078860;  /* current needle position */
  int target = *(int *)(0x060447A8 + *(int *)(0x0607EADC << 2) + (param_1 & 0xffff) << 4);
  int delta = target - *needle_pos;

  *needle_pos = *needle_pos + ((int)(delta + (unsigned int)(delta < 0)) >> 1);

  if (((*(int *)0x0607887F == '\x03') || (*(int *)0x0607887F == '\v')) &&
     ((FRAME_COUNTER & 1) != 0)) {
    return FRAME_COUNTER;
  }

  {
    short *sprite_idx = (short *)(0x060447A4 + (param_1 & 0xffff) << 1);
    int *needle_data = (int *)(0x060447A8 + (param_1 & 0xffff) << 4 + 0xc);
    unsigned int uVar2;

    FUN_060116a8(*needle_pos, *needle_data, (int)DAT_060115c6, 0x00010000, (int)*sprite_idx);
    FUN_06011978(0x06044764, *needle_pos, *needle_data, (int)*sprite_idx);
    uVar2 = FUN_06011978(0x06044784, *needle_pos, *needle_data, (int)*sprite_idx);
    return uVar2;
  }
}

/* sprite_row_data_load -- Load 0x1C sprite row entries from course data table.
 * Iterates 0x1C entries at stride 0x58 in the course data block (0x06063788),
 * copying 2-word pairs into the sprite buffer at 0x0605AAA6.
 * Then triggers DMA via 0x06028400 with the row offset into VRAM. */
void FUN_0601155e(unsigned short param_1)
{
  char *sprite_buf = (char *)0x0605AAA6;
  int course_data = *(int *)0x06063788;
  unsigned short i = 0;

  do {
    unsigned int idx = (unsigned int)i;
    short *src = (short *)(idx * 0x58 + (unsigned int)(param_1 << 1) + course_data + 4);
    *(short *)(sprite_buf + (idx << 2)) = *src;
    *(short *)((int)(sprite_buf + (idx << 2)) + 2) = src[1];
    i = i + 1;
  } while (i < 0x1c);

  (*(int(*)())0x06028400)(8, 0x0605AAA2, (param_1 & 0x3f) << 1,
             0x0000F000 + *(int *)(0x06063788 + 4));
}

void FUN_060116a8(int param_1,int param_2,short param_3,int param_4,short param_5)
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short *psVar11;

  int uStack_2c;

  int uStack_28;

  short sStack_24;

  sStack_24 = param_3;

  (*(int(*)())0x06027358)((int)param_3,&uStack_2c,&uStack_28);

  puVar4 = (char *)0x06027552;

  puVar3 = (char *)0x0602754C;

  puVar2 = (char *)0x0605AAA0;

  puVar1 = (char *)0x060786CC;

  psVar11 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  iVar5 = (*(int(*)())0x06027552)(0xFFC80000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar8 = (*(int(*)())puVar3)(uVar7);

  sVar9 = (*(int(*)())puVar3)(param_1);

  *psVar11 = sVar9 + sVar8;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0x001E0000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0x00380000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_28);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_2c);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_1);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(0xFFC80000,uStack_2c);

  iVar6 = (*(int(*)())puVar4)(0xFFE20000,uStack_28);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_4);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(param_2);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;

  *(short *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = param_5;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 1;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  return;

}

int FUN_06011978(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    short param_4;
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  short uVar5;

  short *puVar6;

  puVar4 = (char *)0x0605AAA0;

  puVar3 = (int *)0x060786CC;

  puVar2 = (char *)0x0602754C;

  puVar6 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  uVar5 = (*(int(*)())0x0602754C)(*param_1 + param_2);

  *puVar6 = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[1] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 10) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[2] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0xc) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[3] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0xe) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[4] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x10) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[5] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x12) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[6] + param_2);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x14) = uVar5;

  sVar1 = *(short *)puVar4;

  uVar5 = (*(int(*)())puVar2)(param_1[7] + param_3);

  *(short *)(puVar3 + (short)(sVar1 * 0x18) + 0x16) = uVar5;

  *(short *)(puVar3 + (short)(*(short *)puVar4 * 0x18) + 6) = param_4;

  puVar3[(short)(*(short *)puVar4 * 0x18) + 4] = 0;

  puVar3[(short)(*(short *)puVar4 * 0x18) + 5] = 1;

  *(short *)puVar4 = *(short *)puVar4 + 1;

  return 0;

}

void FUN_06011af4(int param_1,int param_2,int param_3,int param_4,short param_5,short param_6,short param_7)
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int iVar6;

  int uVar7;

  short sVar8;

  short sVar9;

  short sVar10;

  short *psVar11;

  int uStack_38;

  int uStack_34;

  int uStack_30;

  int uStack_2c;

  int iStack_28;

  int iStack_24;

  uStack_30 = param_2;

  uStack_2c = param_1;

  (*(int(*)())0x06027358)((int)param_5,&uStack_38,&uStack_34);

  puVar4 = (char *)0x06027552;

  puVar3 = (int *)0x0602754C;

  puVar2 = (char *)0x0605AAA0;

  puVar1 = (char *)0x060786CC;

  iStack_24 = -param_3;

  psVar11 = (short *)(0x060786CC + (short)(*(short *)0x0605AAA0 * 0x18) + 8);

  iVar5 = (*(int(*)())0x06027552)(iStack_24,uStack_34);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar8 = (*(int(*)())puVar3)(uVar7);

  sVar9 = (*(int(*)())puVar3)(uStack_2c);

  *psVar11 = sVar9 - sVar8;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(iStack_24,uStack_38);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 10) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_34);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xc) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_38);

  iVar6 = (*(int(*)())puVar4)(param_4,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0xe) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_34);

  iStack_28 = -param_4;

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x10) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(param_3,uStack_38);

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x12) = sVar10 + sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(iStack_24,uStack_34);

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_38);

  uVar7 = (*(int(*)())puVar4)(iVar5 - iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_2c);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x14) = sVar10 - sVar9;

  sVar8 = *(short *)puVar2;

  iVar5 = (*(int(*)())puVar4)(iStack_24,uStack_38);

  iVar6 = (*(int(*)())puVar4)(iStack_28,uStack_34);

  uVar7 = (*(int(*)())puVar4)(iVar5 + iVar6,param_6);

  sVar9 = (*(int(*)())puVar3)(uVar7);

  sVar10 = (*(int(*)())puVar3)(uStack_30);

  *(short *)(puVar1 + (short)(sVar8 * 0x18) + 0x16) = sVar10 + sVar9;

  *(short *)(puVar1 + (short)(*(short *)puVar2 * 0x18) + 6) = param_7;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 4] = 0;

  puVar1[(short)(*(short *)puVar2 * 0x18) + 5] = 0;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  return;

}

/* vdp1_overlay_dispatch -- Emit VDP1 commands for overlay sprite queue.
 * Iterates overlay entries at 0x060786CC (24 bytes each), count at 0x0605AAA0.
 * Entry byte +5 selects command type: 0=normal sprite (0x060280F8),
 * non-zero=polygon (0x060280C4, clears flag after). Advances VDP1 write
 * pointer by 0x20 per entry, increments frame counter. Resets queue count. */
void FUN_06011dc0(void)
{
  int *vdp1_write = (int *)0x060785FC;     /* VDP1 command write pointer */
  char *overlay_buf = (char *)0x060786CC;  /* overlay command buffer (24B entries) */
  int *frame_cnt = (int *)0x0605A008;      /* frame counter */
  unsigned short *queue_cnt = (unsigned short *)0x0605AAA0;
  unsigned short i;

  for (i = 0; i < *queue_cnt; i++) {
    int off = (short)(i * 0x18);
    if (overlay_buf[off + 5] == '\0') {
      (*(int(*)())0x060280F8)(overlay_buf + off, *vdp1_write);
    } else {
      (*(int(*)())0x060280C4)(overlay_buf + off, *vdp1_write);
      overlay_buf[off + 5] = 0;            /* clear polygon flag */
    }
    *frame_cnt = *frame_cnt + 1;
    *vdp1_write = *vdp1_write + 0x20;
  }
  *queue_cnt = 0;
}

/* subsystem_sprite_pair_update -- Update 2 paired VDP1 sprites.
 * Builds VDP1 commands for two sprite entries at 0x060638B0/A0
 * using shared vertical offset from DAT_06011efe. */
void FUN_06011e7c(void)
{
    register int vdp_cmd_build asm("r3") = 0x06028400;
    register int y_offset asm("r2") = (int)DAT_06011efe;

    (*(int(*)())vdp_cmd_build)(0xC, *(int *)0x060638B0, (int)DAT_06011f00,
        *(int *)0x060638B4 + y_offset);
    (*(int(*)())vdp_cmd_build)(0xC, *(int *)0x060638A0, (int)DAT_06011f02,
        *(int *)0x060638A4 + y_offset);
}

/* sprite_pair_or_single_update -- Update VDP1 sprite(s) for HUD overlay.
 * In alternate mode (0x06085FF4 != 0): updates both sprites via FUN_06011e7c.
 * Otherwise: updates single sprite from buffer 0x060638B0 (if 0x0607EADC set)
 * or 0x060638A0 (default). Uses fixed character ID 0x420 with Y offset. */
void FUN_06011eb4(void)
{
  if (*(int *)0x06085FF4 != '\0') {
    FUN_06011e7c();                         /* update both sprites */
    return;
  }

  if (*(int *)0x0607EADC != 0) {
    (*(int(*)())0x06028400)(0xc, *(int *)0x060638B0, 0x420,
               *(int *)(0x060638B0 + 4) + (int)DAT_06011efe);
  } else {
    (*(int(*)())0x06028400)(0xc, *(int *)0x060638A0, 0x420,
               *(int *)(0x060638A0 + 4) + (int)DAT_06011efe);
  }
}

void FUN_06011f1c(param_1)
    unsigned short *param_1;
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uVar3 = DAT_06011fd6;

  uVar2 = DAT_06011fd4;

  iVar7 = -2048;

  sVar4 = 0;

  do {

    uVar1 = *param_1;

    *param_1 = 0;

    iVar5 = ((int)(short)uVar1 & 0x1fU) - 2;

    if (iVar5 < 1) {

      iVar5 = 0;

    }

    iVar6 = (short)(uVar1 & uVar2) + -0x40;

    *param_1 = *param_1 | (unsigned short)iVar5;

    if (iVar6 < 1) {

      iVar6 = 0;

    }

    *param_1 = *param_1 | (unsigned short)iVar6;

    iVar5 = (short)(uVar1 & uVar3) + iVar7;

    if (iVar5 < 1) {

      iVar5 = 0;

    }

    sVar4 = sVar4 + 1;

    *param_1 = *param_1 | (unsigned short)iVar5;

    param_1 = param_1 + 1;

  } while (sVar4 < 0x10);

  return;

}

void FUN_06011f92(param_1, param_2)
    unsigned short *param_1;
    unsigned short *param_2;
{

  unsigned short uVar1;

  unsigned short uVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  unsigned int uVar6;

  int iVar7;

  short sVar8;

  uVar2 = DAT_06011fd6;

  iVar7 = 0x400;

  uVar6 = iVar7 - 0x20;

  sVar8 = 0;

  do {

    uVar1 = *param_1;

    uVar5 = *param_2;

    *param_1 = 0;

    iVar3 = ((int)(short)uVar1 & 0x1fU) + 1;

    if (iVar3 < (short)uVar5) {

      uVar4 = (unsigned short)iVar3;

    }

    else {

      uVar4 = uVar5 & 0x1f;

    }

    *param_1 = *param_1 | uVar4;

    iVar3 = ((int)(short)uVar1 & uVar6) + 0x20;

    if ((((short)uVar5 <= iVar3 ^ 1) & uVar6) == 0) {

      uVar4 = uVar5 & (unsigned short)uVar6;

    }

    else {

      uVar4 = (unsigned short)iVar3;

    }

    iVar3 = (short)(uVar1 & uVar2) + iVar7;

    *param_1 = *param_1 | uVar4;

    if ((((short)uVar5 <= iVar3 ^ 1) & uVar2) == 0) {

      uVar5 = uVar5 & uVar2;

    }

    else {

      uVar5 = (unsigned short)iVar3;

    }

    sVar8 = sVar8 + 1;

    *param_1 = *param_1 | uVar5;

    param_1 = param_1 + 1;

    param_2 = param_2 + 1;

  } while (sVar8 < 0x10);

  return;

}
