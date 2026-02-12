#include "game.h"

extern int DAT_0604211e;
extern int DAT_06042120;
extern int DAT_06042122;
extern int DAT_0604222c;
extern int DAT_0604222e;
extern int DAT_0604230a;
extern int DAT_0604230c;
extern int DAT_0604230e;
extern int DAT_06042398;
extern int DAT_0604239a;
extern int DAT_060424c8;
extern int DAT_060424ca;
extern int DAT_06042b9c;
extern int DAT_06042b9e;
extern int DAT_06042ba0;
extern int DAT_06042ba2;
extern int DAT_06042ba4;
extern int DAT_06042ba6;
extern int DAT_06042c78;
extern int DAT_06042c7a;
extern int DAT_06042cb2;
extern int Onchip_DMA0R;
extern int PTR_DAT_06042230;
extern int PTR_DAT_060423f6;
extern int PTR_DAT_06042cb4;

int FUN_06042088(param_1)
    int *param_1;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  char local_14 [16];

  puVar2 = (char *)0x060A5400;

  if (*(int *)(0x360 + CD_SESSION_BASE) == 1) {

    iVar3 = (*(int(*)())0x06036A1C)(*(int *)(CD_SESSION_BASE + DAT_06042120 + 4),

                       *(int *)(CD_SESSION_BASE + (int)DAT_06042120));

    if (iVar3 != 0) {

      return 1;

    }

    (*(int(*)())0x060349B6)(local_14);

    *(char *)(*(int *)puVar2 + 0x40) = local_14[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x360) = 2;

  }

  uVar1 = DAT_06042122;

  if ((*(int *)(0x360 + *(int *)puVar2) == 2) &&

     (uVar4 = (*(int(*)())0x06035C4E)(), (uVar4 & uVar1) != 0)) {

    *(int *)(*(int *)puVar2 + 0x360) = 0;

  }

  return *(int *)(0x360 + *(int *)puVar2);

}

int FUN_06042134(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned short uVar3;

  int iVar4;

  unsigned char bVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  short sVar9;

  char local_2c [16];

  puVar2 = (char *)0x060A5400;

  puVar1 = (char *)0x060349B6;

  iVar7 = (int)DAT_0604222c;

  for (iVar8 = 0; iVar8 < *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230); iVar8 = iVar8 + 1)

  {

    sVar9 = (short)iVar8;

    bVar5 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 4) != -2;

    iVar4 = iVar7;

    if ((int)bVar5) {

      iVar4 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 4);

    }

    iVar6 = iVar7;

    if (*(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 8) != -2) {

      bVar5 = bVar5 | 2;

      iVar6 = *(int *)(*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc) + 8);

    }

    iVar4 = (*(int(*)())0x06036414)(*(int *)

                        (*(int *)puVar2 + (int)DAT_0604222e + (int)(short)(sVar9 * 0xc)),bVar5,iVar4

                       ,iVar6);

    if (iVar4 != 0) break;

    (*(int(*)())puVar1)(local_2c);

    *(char *)(*(int *)puVar2 + 0x40) = local_2c[0];

    *param_1 = *param_1 + 1;

  }

  if (iVar8 < *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230)) {

    iVar7 = 0;

    for (; iVar8 < *(int *)(*(int *)puVar2 + (int)DAT_0604230c); iVar8 = iVar8 + 1) {

      iVar4 = (int)(short)((short)iVar7 * 0xc);

      iVar6 = (int)(short)((short)iVar8 * 0xc);

      *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar4) =

           *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar6);

      *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar4 + 4) =

           *(int *)(*(int *)puVar2 + (int)DAT_0604230a + iVar6 + 4);

      *(int *)(iVar4 + *(int *)puVar2 + (int)DAT_0604230a + 8) =

           *(int *)(iVar6 + *(int *)puVar2 + (int)DAT_0604230a + 8);

      iVar7 = iVar7 + 1;

    }

    *(int *)(*(int *)puVar2 + (int)DAT_0604230c) = iVar7;

  }

  else {

    *(int *)(*(int *)puVar2 + (int)PTR_DAT_06042230) = 0;

  }

  uVar3 = (*(int(*)())0x06035C4E)();

  if (((uVar3 & 0x40) != 0) && (*(int *)(*(int *)puVar2 + (int)DAT_0604230c) == 0)) {

    *(int *)(*(int *)puVar2 + 0x1e0) = 0;

  }

  return *(int *)((int)DAT_0604230c + *(int *)puVar2);

}

void FUN_0604231e()
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x060A5400;

  iVar2 = 0;

  do {

    *(char *)(iVar2 + *(int *)puVar1) = 0;

    *(char *)(*(int *)puVar1 + 0x18 + iVar2) = 0;

    iVar2 = iVar2 + 1;

  } while (iVar2 < 0x17);

  *(int *)(*(int *)puVar1 + 0x30) = 0;

  *(int *)(*(int *)puVar1 + 0x34) = 0;

  *(int *)(*(int *)puVar1 + 0x38) = 0xffffffff;

  *(int *)(*(int *)puVar1 + 0x3c) = 0;

  *(int *)(*(int *)puVar1 + 0x4c) = 0;

  *(int *)(*(int *)puVar1 + 0x50) = 0;

  *(int *)(*(int *)puVar1 + 0x54) = 0;

  *(int *)(*(int *)puVar1 + 0x58) = 0;

  iVar2 = (int)DAT_06042398;

  *(int *)(*(int *)puVar1 + iVar2) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x24) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x34) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x44) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x5c) = 0;

  iVar2 = (int)DAT_0604239a;

  *(int *)(*(int *)puVar1 + iVar2) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = 0;

  return;

}

/* cd_poll_status_ready -- Busy-wait for CD drive status bit, then read.
 * Spins on cd_get_status (0x06035C4E) until required bits
 * (PTR_DAT_060423f6) are set, then reads sector via cd_read (0x06035C54)
 * with mask 0xFBFF. Returns read result. */
int cd_poll_status_ready()
{
    unsigned short status_mask = PTR_DAT_060423f6;
    unsigned short status;

    /* Busy-wait until CD status bits are ready */
    do {
        status = (*(int(*)())0x06035C4E)();    /* cd_get_status */
    } while ((status & status_mask) == 0);

    return (*(int(*)())0x06035C54)(0xFBFF);    /* cd_read_sector */
}

/* cd_lba_to_msf_minutes -- Convert LBA offset (0x005A0000-based) to MSF minutes.
 * Uses piecewise linear interpolation from lookup table at DAT_060424c8.
 * Input: LBA value. Returns minutes component. */
int FUN_0604249c(int lba)
{
    int idx = ((unsigned int)(0x005A0000 - lba) >> 16) << 2;
    return (unsigned int)*(unsigned short *)(&DAT_060424ca + idx) +
        ((unsigned int)*(unsigned short *)(&DAT_060424c8 + idx) *
         (0x005A0000 - lba & 0xFFFFU) >> 16);
}

/* cd_lba_to_msf_seconds -- Convert raw LBA to MSF seconds.
 * Same interpolation table as minutes, but uses raw LBA input. */
int FUN_060424a2(unsigned int lba)
{
    int idx = (lba >> 16) << 2;
    return (unsigned int)*(unsigned short *)(&DAT_060424ca + idx) +
        ((unsigned int)*(unsigned short *)(&DAT_060424c8 + idx) *
         (lba & 0xFFFF) >> 16);
}

void FUN_060429ec(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int *param_4;
{

  int iVar1;

  iVar1 = (*(int(*)())0x0603C156)();

  if (iVar1 == 2) {

    iVar1 = (*(int(*)())0x06042BFC)(param_1);

    if (param_3 != 1) {

      (*(int(*)())0x06038A48)(0x25F00000 + (param_2 << 2) + (iVar1 << 10),param_4,param_3 << 2);

      return;

    }

    *(int *)(0x25F00000 + (param_2 << 2) + (iVar1 << 10)) = *param_4;

  }

  else {

    iVar1 = (*(int(*)())0x06042BFC)(param_1);

    if (param_3 != 1) {

      (*(int(*)())0x06038A48)(0x25F00000 + (param_2 << 1) + (iVar1 << 9),param_4,param_3 << 1);

      return;

    }

    *(short *)(0x25F00000 + (param_2 << 1) + (iVar1 << 9)) = *(short *)param_4;

  }

  return;

}

void FUN_06042a8c(param_1)
    unsigned int *param_1;
{
  register int *reg asm("r2") = &Onchip_DMA0R;
  int flags;
  int val;

  val = *reg;
  val = (val & 0xfffffff7) | *param_1;
  *reg = val;

  flags = param_1[2];

  if ((flags & 4) == 4) {
    val = (val & 0xfffffffe) | param_1[1];
    *reg = val;
  }

  if ((flags & 1) == 1) {
    val = val & 0xfffffffb;
    *reg = val;
  }

  if ((flags & 2) == 2) {
    val = val & 0xfffffffd;
    *reg = val;
  }
}

unsigned int FUN_06042aca(param_1, param_2)
    int *param_1;
    int param_2;
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  unsigned int *puVar4;

  *(int *)((param_2 << 4) + -0x80) = *param_1;

  if ((param_1[9] & 1) == 1) {

    *(int *)((param_2 << 4) + -0x7c) = param_1[1];

  }

  if ((param_1[9] & 2) == 2) {

    *(int *)((param_2 << 4) + -0x78) = param_1[2];

  }

  puVar4 = (unsigned int *)((param_2 << 4) + -0x74);

  uVar2 = *puVar4;

  if ((param_1[9] & 4) == 4) {

    uVar2 = uVar2 & 0xFFFF3FFF | param_1[3] << 0xe;

  }

  if ((param_1[9] & 8) == 8) {

    uVar2 = uVar2 & -12289 | param_1[4] << 0xc;

  }

  if ((param_1[9] & 0x10) == 0x10) {

    uVar2 = uVar2 & -3073 | param_1[5];

  }

  if ((param_1[9] & 0x20) == 0x20) {

    uVar2 = uVar2 & -513 | param_1[6];

  }

  uVar1 = param_1[9];

  uVar3 = uVar2 & 0xffffffe7;

  if ((uVar1 & 0x40) == 0x40) {

    uVar3 = uVar2 & 0xffffffe3 | param_1[7];

  }

  if ((param_1[9] & 0x100) == 0x100) {

    uVar3 = uVar3 & 0xfffffffd;

  }

  *puVar4 = uVar3;

  if ((param_1[9] & 0x80) == 0x80) {

    *(char *)(param_2 + DAT_06042ba6) = (char)param_1[8];

  }

  return uVar1 & 0x40;

}

char * FUN_06042bfc(param_1)
    char *param_1;
{

  if (param_1 == (void *)0x00000001) {

    return (char *)(*(unsigned short *)(0x060A4D18 + 6) & 7);

  }

  if ((param_1 == (void *)0x00000002) || (param_1 == (void *)0x00000004)) {

    return (char *)(*(unsigned short *)(0x060A4D18 + 4) & 7);

  }

  if (param_1 != (void *)0x00000008) {

    if (param_1 == (void *)0x00000010) {

      return (char *)((int)((unsigned int)*(unsigned short *)(0x060A4D18 + 4) & 0x700) >> 8);

    }

    if (param_1 == (void *)0x00000020) {

      return (char *)

             ((int)((unsigned int)*(unsigned short *)(0x060A4D18 + 4) & (int)DAT_06042c7a) >> 0xc);

    }

    if (param_1 != (char *)0x80) {

      if (param_1 == (char *)0x100) {

        return (char *)((int)(*(unsigned short *)(0x060A4D18 + 6) & 0x70) >> 4);

      }

      if (param_1 != 0x00040000) {

        return param_1;

      }

      return *(char **)0x060A4D5C;

    }

  }

  return (char *)((int)(*(unsigned short *)(0x060A4D18 + 4) & 0x70) >> 4);

}
