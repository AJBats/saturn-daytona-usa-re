#include "game.h"

extern int DAT_0603ee76;
extern int DAT_0603ef2a;
extern int DAT_0603ef8a;
extern int DAT_0603eff4;
extern int DAT_0603f2c2;
extern int DAT_0603f5b8;
extern int DAT_0603f682;
extern int DAT_0603f8ac;
extern int DAT_0603f8ae;
extern int DAT_0603fb22;
extern int DAT_0603fb24;
extern int DAT_0603fcb6;
extern int DAT_0603fe2e;
extern int FUN_0603f2e0();
extern int FUN_0603f342();
extern int FUN_0603f3da();
extern int FUN_0603f3f6();
extern int FUN_0603f4e0();
extern int FUN_0603f500();
extern char FUN_0603f534();
extern unsigned int FUN_0603f582();
extern void FUN_0603f84c();
extern int FUN_0603f92c();
extern char FUN_0603f970();
extern void FUN_0603fc60();
extern void FUN_0603fce4();
extern void FUN_0603ff9c();
extern void FUN_0603ffe6();
extern int PTR_DAT_0603f180;
extern int PTR_DAT_0603f8b0;
extern int PTR_DAT_0603fe30;

int FUN_0603eacc(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  int uVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int *piVar11;

  int iVar12;

  int *piVar13;

  int iVar14;

  unsigned short uVar15;

  int *piVar16;

  iVar2 = *(int *)0x060635A8;

  if (iVar2 == 1) {

    uVar15 = 0;

  }

  else {

    if (iVar2 != 2) {

      return iVar2;

    }

    uVar15 = 1;

  }

  uVar3 = (*(int(*)())0x0603D9EC)(param_1);

  uVar4 = (*(int(*)())0x0603DA88)(param_1);

  puVar1 = (char *)0x0603C08C;

  piVar16 = (int *)(0x060A53B8 + (char)((char)uVar15 * '$'));

  iVar14 = *piVar16;

  piVar13 = piVar16 + 1;

  iVar10 = *piVar13;

  piVar11 = piVar16 + 3;

  iVar6 = *piVar11;

  piVar7 = piVar16 + 4;

  iVar9 = *piVar7;

  iVar12 = piVar16[6];

  iVar8 = piVar16[7];

  iVar2 = (*(int(*)())0x0603C08C)(iVar14,uVar4);

  iVar5 = (*(int(*)())puVar1)(iVar10,uVar3);

  *piVar16 = iVar5 + iVar2;

  iVar2 = (*(int(*)())puVar1)(iVar14,uVar3);

  iVar5 = (*(int(*)())puVar1)(iVar10,uVar4);

  *piVar13 = iVar5 - iVar2;

  iVar2 = (*(int(*)())puVar1)(iVar6,uVar4);

  iVar5 = (*(int(*)())puVar1)(iVar9,uVar3);

  *piVar11 = iVar5 + iVar2;

  iVar2 = (*(int(*)())puVar1)(iVar6,uVar3);

  iVar5 = (*(int(*)())puVar1)(iVar9,uVar4);

  *piVar7 = iVar5 - iVar2;

  iVar2 = (*(int(*)())puVar1)(iVar12,uVar4);

  iVar5 = (*(int(*)())puVar1)(iVar8,uVar3);

  piVar16[6] = iVar5 + iVar2;

  iVar2 = (*(int(*)())puVar1)(iVar12,uVar3);

  iVar5 = (*(int(*)())puVar1)(iVar8,uVar4);

  piVar16[7] = iVar5 - iVar2;

  puVar1 = (char *)0x060A3E68;

  *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *piVar16;

  *(int *)(puVar1 + (unsigned int)(uVar15 << 7) + 0x20) = *piVar13;

  *(int *)(puVar1 + (unsigned int)(uVar15 << 7) + 0x28) = *piVar11;

  *(int *)(puVar1 + (unsigned int)(uVar15 << 7) + 0x2c) = *piVar7;

  return iVar5 - iVar2;

}

int FUN_0603ec40(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int iVar9;

  int *piVar10;

  int *puVar11;

  puVar1 = (char *)0x060A4C70;

  iVar3 = *(int *)0x060635A8;

  if (iVar3 == 1) {

    iVar3 = 0;

  }

  else {

    if (iVar3 != 2) {

      return iVar3;

    }

    iVar3 = 1;

  }

  iVar9 = (iVar3 << 2);

  if ((*(int *)(0x060A4C4C + iVar9) == 0) ||

     ((*(int *)(0x060A4C60 + iVar9) == 0 && (*(int *)(0x060A4C78 + iVar9) == 0)))) {

    param_1 = *(int *)(0x060A4C70 + (iVar3 << 2)) + param_1;

    *(int *)(0x060A4C70 + (iVar3 << 2)) = param_1;

    if ((int)0x01680000 <= param_1) {

      *(int *)(puVar1 + (iVar3 << 2)) = *(int *)(puVar1 + (iVar3 << 2)) - (int)0x01680000;

    }

    if (*(int *)(puVar1 + (iVar3 << 2)) < 0) {

      *(char **)(puVar1 + (iVar3 << 2)) = 0x01680000 + *(int *)(puVar1 + (iVar3 << 2));

    }

    puVar2 = (int *)0x0603C08C;

    iVar9 = (iVar3 << 2);

    puVar11 = (int *)(puVar1 + iVar9);

    piVar10 = (int *)(0x060A3E68 + (iVar3 << 7));

    piVar7 = (int *)(0x060A53A8 + iVar9);

    iVar6 = *piVar7;

    uVar4 = (*(int(*)())0x0603DA88)(*puVar11);

    iVar3 = (*(int(*)())puVar2)(uVar4,iVar6);

    piVar8 = (int *)(0x060A53B0 + iVar9);

    iVar5 = *piVar8;

    iVar9 = (*(int(*)())0x0603D9EC)(*puVar11);

    iVar9 = (*(int(*)())puVar2)(-iVar9,iVar5);

    *piVar10 = (iVar6 - iVar3) - iVar9;

    iVar5 = *piVar8;

    iVar3 = *piVar7;

    uVar4 = (*(int(*)())0x0603D9EC)(*puVar11);

    iVar3 = (*(int(*)())puVar2)(uVar4,iVar3);

    iVar9 = *piVar8;

    uVar4 = (*(int(*)())0x0603DA88)(*puVar11);

    iVar9 = (*(int(*)())puVar2)(uVar4,iVar9);

    piVar10[1] = (iVar5 - iVar3) - iVar9;

    piVar10[2] = 0;

    iVar3 = (*(int(*)())0x0603D9EC)(*puVar11);

    piVar10[3] = -iVar3;

    iVar3 = (*(int(*)())0x0603DA88)(*puVar11);

    piVar10[4] = iVar3;

    iVar3 = (*(int(*)())0x0603DA88)(*puVar11);

    piVar10[5] = iVar3;

    iVar3 = (*(int(*)())0x0603D9EC)(*puVar11);

    piVar10[6] = iVar3;

  }

  else {

    iVar3 = (iVar3 << 2);

    *(int *)(0x060A4C70 + iVar3) = 0;

  }

  return iVar3;

}

unsigned int FUN_0603edc4(param_1, param_2, param_3, param_4, param_5)
    unsigned int param_1;
    unsigned int param_2;
    unsigned char *param_3;
    unsigned char param_4;
    unsigned char param_5;
{

  unsigned int uVar1;

  uVar1 = (unsigned int)(char)param_5;

  if (((param_2 & 4) != 0) || ((param_2 & 2) != 0)) {

    if (((param_1 & 4) == 0) && ((param_1 & 2) == 0)) {

      uVar1 = (int)(char)param_3[1] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[1] | (unsigned int)param_4;

    }

    param_3[1] = (unsigned char)uVar1;

  }

  if (((param_2 & 8) != 0) || ((0x80 & param_2) != 0)) {

    if (((param_1 & 8) == 0) && ((0x80 & param_1) == 0)) {

      *param_3 = *param_3 & param_5;

    }

    else {

      *param_3 = *param_3 | param_4;

    }

  }

  if ((param_2 & 0x10) != 0) {

    if ((param_1 & 0x10) == 0) {

      uVar1 = (int)(char)param_3[3] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[3] | (unsigned int)param_4;

    }

    param_3[3] = (unsigned char)uVar1;

  }

  if ((param_2 & 0x20) != 0) {

    if ((param_1 & 0x20) == 0) {

      uVar1 = (int)(char)param_3[2] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[2] | (unsigned int)param_4;

    }

    param_3[2] = (unsigned char)uVar1;

  }

  if ((param_2 & 1) != 0) {

    if ((param_1 & 1) == 0) {

      uVar1 = (int)(char)param_3[5] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[5] | (unsigned int)param_4;

    }

    param_3[5] = (unsigned char)uVar1;

  }

  if ((0x100 & param_2) != 0) {

    if ((0x100 & param_1) == 0) {

      uVar1 = (int)(char)param_3[4] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[4] | (unsigned int)param_4;

    }

    param_3[4] = (unsigned char)uVar1;

  }

  if (((unsigned int)0x00010000 & param_2) != 0) {

    if (((unsigned int)0x00010000 & param_1) == 0) {

      uVar1 = (int)(char)param_3[7] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[7] | (unsigned int)param_4;

    }

    param_3[7] = (unsigned char)uVar1;

  }

  if ((param_2 & (unsigned int)0x00020000) != 0) {

    if ((param_1 & (unsigned int)0x00020000) == 0) {

      uVar1 = (int)(char)param_3[6] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[6] | (unsigned int)param_4;

    }

    param_3[6] = (unsigned char)uVar1;

  }

  return uVar1;

}

char * FUN_0603ef64(param_1, param_2, param_3)
    int param_1;
    char *param_2;
    int *param_3;
{

  int iVar1;

  char *puVar2;

  if (param_2 == 0x0000FFFF) {

    param_2 = (int *)0x7FFFFFFF;

  }

  puVar2 = (char *)

           ((unsigned int)((int)DAT_0603ef8a + (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14))) >> 0xb

           );

  if (param_2 < puVar2) {

    puVar2 = param_2;

  }

  if ((((param_3 != (int *)0x0) &&

       (*param_3 = (int)((int)(int)puVar2 << 11),

       *(int *)(param_1 + 0x10) < *(int *)(param_1 + 0x14) + (int)((int)(int)puVar2 << 11))) &&

      (iVar1 = (*(int(*)())0x06036BE4)(), *param_3 != 0)) && (iVar1 != 0)) {

    *param_3 = *param_3 - (DAT_0603eff4 - iVar1);

  }

  return puVar2;

}

int FUN_0603f0fc(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = (char *)0x0603B424;

  if (param_1 != 0) {

    (*(int(*)())0x0603B31C)(param_1,param_3);

    do {

      iVar2 = (*(int(*)())puVar1)(param_1);

    } while (iVar2 != 0);

  }

  if (*param_2 == 0) {

    uVar3 = FUN_0603f2e0(param_1,param_2[2],param_2[1]);

  }

  else {

    uVar3 = FUN_0603f342(param_1,param_2[2],param_2[1]);

  }

  return uVar3;

}

int FUN_0603f148(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  puVar2 = (int *)0x06036D94;

  uVar1 = PTR_DAT_0603f180;

  iVar3 = (*(int(*)())0x06036D14)();

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int(*)())0x06036D14)();

    if (iVar3 == 0) {

      iVar3 = 1;

    }

    else {

      iVar3 = 2;

      param_1 = param_1 + 0x30;

      if (2 < param_3) {

        do {

          iVar4 = (*(int(*)())puVar2)(param_2,param_1 + 0xc,0xc);

          if (iVar4 == 0) {

            return iVar3;

          }

          if ((*(unsigned char *)(param_1 + 0xb) & uVar1) != 0) break;

          iVar3 = iVar3 + 1;

          param_1 = param_1 + 0x18;

        } while (iVar3 < param_3);

      }

      iVar3 = -1;

    }

  }

  return iVar3;

}

int FUN_0603f22c()
{

  int uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int local_24;

  char auStack_20 [4];

  char auStack_1c [8];

  puVar4 = (char *)0x060A4D14;

  puVar3 = (char *)0x06041470;

  puVar2 = (int *)0x06041698;

  uVar1 = 0x00FFFFFF;

  iVar5 = (*(int(*)())0x06041470)(0x00FFFFFF,*(int *)(CD_STATE_A + 0xc8));

  if (iVar5 == -5) {

    local_24 = -1;

  }

  else {

    (*(int(*)())0x06041884)(0x00008000);

    while (iVar5 != 0) {

      iVar5 = (*(int(*)())puVar2)();

      if (iVar5 == -0xc) {

        return -1;

      }

      iVar5 = (*(int(*)())puVar3)(uVar1,*(int *)(*(int *)puVar4 + 0xc8));

    }

    iVar5 = (*(int(*)())0x0604188C)();

    if (iVar5 == 0) {

      iVar5 = (*(int(*)())0x06036A98)(auStack_20,&local_24,auStack_1c);

      if (iVar5 == 0) {

        local_24 = local_24 + 2;

      }

      else {

        local_24 = -1;

      }

    }

    else {

      local_24 = -1;

    }

  }

  return local_24;

}

int FUN_0603f2e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  char local_44 [32];

  char auStack_24 [24];

  FUN_0603f3da(auStack_24,param_1,param_3,param_4,param_1);

  iVar1 = 0;

  while ((0 < param_3 && (FUN_0603f582(auStack_24,local_44), local_44[0] != '\0'))) {

    FUN_0603f84c(param_2,local_44);

    param_2 = param_2 + 0xc;

    param_3 = param_3 + -1;

    iVar1 = iVar1 + 1;

  }

  *(unsigned char *)(param_2 + -1) = *(unsigned char *)(param_2 + -1) | 0x80;

  return iVar1;

}

int FUN_0603f342(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char local_4c [16];

  char auStack_3c [16];

  char auStack_2c [24];

  puVar1 = (char *)0x06036DDC;

  FUN_0603f3da(auStack_2c,param_1,param_3,param_4,param_1);

  iVar3 = 0;

  while ((0 < param_3 && (FUN_0603f582(auStack_2c,local_4c), local_4c[0] != '\0'))) {

    if ((iVar3 < 3) ||

       (iVar2 = (*(int(*)())0x06036D94)(param_2 + -0xc,auStack_3c,0xc), iVar2 != 0)) {

      FUN_0603f84c(param_2,local_4c);

      (*(int(*)())puVar1)(param_2 + 0xc,auStack_3c,0xc);

    }

    param_2 = param_2 + 0x18;

    iVar3 = iVar3 + 1;

    param_3 = param_3 + -1;

  }

  *(unsigned char *)(param_2 + -0xd) = *(unsigned char *)(param_2 + -0xd) | 0x80;

  return iVar3;

}

/* cd_read_word -- Read 16-bit word from CD buffer via DMA double-read pattern.
 * First read primes the bus, second read gets actual data. */
int FUN_0603f4e0(int addr)
{
    short result[2];
    volatile int saved_addr;
    char dummy_buf[8];

    saved_addr = addr;
    FUN_0603f3f6(addr, dummy_buf, 2);         /* prime DMA bus */
    FUN_0603f3f6(saved_addr, result, 2);      /* actual read */
    return (int)result[0];
}

/* cd_read_long -- Read 32-bit long from CD buffer via DMA double-read pattern.
 * Same prime-then-read pattern as cd_read_word but for 4 bytes. */
int FUN_0603f500(int addr)
{
    struct { int val; int saved; char buf[8]; } frame;

    frame.saved = addr;
    FUN_0603f3f6(addr, frame.buf, 4);         /* prime DMA bus */
    FUN_0603f3f6(frame.saved, &frame.val, 4); /* actual read */
    return frame.val;
}

char FUN_0603f534(param_1)
    int *param_1;
{

  int iVar1;

  char local_10 [4];

  char acStack_c [8];

  FUN_0603f3f6(param_1,acStack_c,1);

  if ((acStack_c[0] == '\0') &&

     (iVar1 = param_1[3], param_1[3] = iVar1 + 1, iVar1 + 1 != param_1[4])) {

    (*(int(*)())0x0603B21C)(*param_1,1,param_1[1],0x800);

    param_1[2] = 0;

    FUN_0603f3f6(param_1,local_10,1);

    acStack_c[0] = local_10[0];

  }

  return acStack_c[0];

}

unsigned int FUN_0603f582(param_1, param_2)
    int *param_1;
    unsigned char *param_2;
{

  int bVar1;

  unsigned char *pbVar2;

  unsigned int uVar3;

  int iVar4;

  int uVar5;

  short uVar6;

  unsigned char *pbVar7;

  unsigned char local_74;

  unsigned int uStack_70;

  unsigned char abStack_6c [4];

  short auStack_68 [2];

  unsigned char abStack_64 [4];

  char acStack_60 [4];

  unsigned char abStack_5c [4];

  unsigned char abStack_58 [4];

  unsigned char abStack_54 [4];

  unsigned char abStack_50 [4];

  unsigned char abStack_4c [4];

  unsigned char bStack_48;

  char auStack_44 [4];

  char auStack_40 [4];

  char auStack_3c [4];

  char auStack_38 [4];

  char auStack_34 [4];

  char auStack_30 [4];

  char auStack_2c [4];

  char auStack_28 [4];

  unsigned char *pbStack_24;

  bVar1 = 0;

  if (*param_1 == 0) {

    *param_2 = 0;

    return 0;

  }

  uVar3 = FUN_0603f534(param_1);

  *param_2 = (unsigned char)uVar3;

  if (*param_2 == 0) {

    return uVar3;

  }

  FUN_0603f3f6(param_1,auStack_28,1);

  iVar4 = FUN_0603f500(param_1);

  *(int *)(param_2 + 4) = iVar4 + DAT_0603f682;

  uVar5 = FUN_0603f500(param_1);

  *(int *)(param_2 + 8) = uVar5;

  for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {

    FUN_0603f3f6(param_1,auStack_2c,1);

  }

  FUN_0603f3f6(param_1,abStack_4c,1);

  bStack_48 = abStack_4c[0];

  FUN_0603f3f6(param_1,abStack_50,1);

  param_2[0xe] = abStack_50[0];

  FUN_0603f3f6(param_1,abStack_54,1);

  param_2[0xf] = abStack_54[0];

  FUN_0603f4e0(param_1);

  FUN_0603f3f6(param_1,abStack_58,1);

  uStack_70 = abStack_58[0] + 0x21;

  pbVar7 = param_2 + 0x10;

  iVar4 = 0;

  do {

    uVar3 = (unsigned int)abStack_58[0];

    if (8 < uVar3) {

      uVar3 = 8;

    }

    pbVar2 = pbStack_24;

    if ((int)uVar3 <= iVar4) break;

    FUN_0603f3f6(param_1,abStack_5c,1);

    local_74 = abStack_5c[0];

    iVar4 = iVar4 + 1;

    pbVar2 = pbStack_24;

    if (abStack_5c[0] == 0x3b) break;

    *pbVar7 = abStack_5c[0];

    pbVar7 = pbVar7 + 1;

    pbVar2 = pbVar7;

  } while (abStack_5c[0] != 0x2e);

  pbStack_24 = pbVar2;

  if (local_74 == 0x3b) {

    for (; iVar4 < (int)(unsigned int)abStack_58[0]; iVar4 = iVar4 + 1) {

      FUN_0603f3f6(param_1,auStack_30,1);

    }

  }

  else if (local_74 != 0x2e) {

    while (iVar4 < (int)(unsigned int)abStack_58[0]) {

      FUN_0603f3f6(param_1,acStack_60,1);

      iVar4 = iVar4 + 1;

      if (acStack_60[0] == '.') {

        pbStack_24 = pbVar7 + 1;

        *pbVar7 = 0x2e;

        pbVar7 = pbStack_24;

        break;

      }

      bVar1 = 1;

    }

  }

LAB_0603f748:

  if (iVar4 < (int)(unsigned int)abStack_58[0]) {

    FUN_0603f3f6(param_1,abStack_64,1);

    iVar4 = iVar4 + 1;

    if (abStack_64[0] == 0x3b) goto LAB_0603f716;

    if ((int)pbVar7 - (int)pbStack_24 < 4) {

      if ((int)pbVar7 - (int)(param_2 + 0x10) < 0xc) {

        *pbVar7 = abStack_64[0];

        pbVar7 = pbVar7 + 1;

      }

    }

    else {

      bVar1 = 1;

    }

    goto LAB_0603f748;

  }

LAB_0603f74e:

  if ((int)pbVar7 - (int)(param_2 + 0x10) < 0xc) {

    *pbVar7 = 0;

  }

  if ((abStack_58[0] + 1 & 1) != 0) {

    FUN_0603f3f6(param_1,auStack_38,1);

    uStack_70 = abStack_58[0] + 0x22;

  }

  if (param_2[0x10] == 0) {

    (*(int(*)())0x06035FEC)();

  }

  else if (param_2[0x10] == 1) {

    (*(int(*)())0x06035FEC)();

  }

  if (uStack_70 < *param_2) {

    FUN_0603f3f6(param_1,auStack_3c,4);

    FUN_0603f3f6(param_1,auStack_68,2);

    *(short *)(param_2 + 0xc) = auStack_68[0];

    FUN_0603f3f6(param_1,auStack_40,2);

    FUN_0603f3f6(param_1,abStack_6c,1);

    uVar3 = 0x1d;

    param_2[0x1d] = abStack_6c[0];

    for (iVar4 = uStack_70 + 9; iVar4 < (int)(unsigned int)*param_2; iVar4 = iVar4 + 1) {

      uVar3 = FUN_0603f3f6(param_1,auStack_44,1);

    }

  }

  else {

    if ((bStack_48 & 2) == 0) {

      uVar6 = 0;

    }

    else {

      uVar6 = SUB42(0x00008000,0);

    }

    *(short *)(param_2 + 0xc) = uVar6;

    uVar3 = 0x1d;

    param_2[0x1d] = 0;

  }

  if (bVar1) {

    uVar3 = (int)*(short *)(param_2 + 0xc) | 0x80;

    *(short *)(param_2 + 0xc) = (short)uVar3;

  }

  return uVar3;

LAB_0603f716:

  for (; iVar4 < (int)(unsigned int)abStack_58[0]; iVar4 = iVar4 + 1) {

    FUN_0603f3f6(param_1,auStack_34,1);

  }

  goto LAB_0603f74e;

}

void FUN_0603f84c(param_1, param_2)
    int *param_1;
    int param_2;
{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  unsigned int uVar5;

  *param_1 = *(int *)(param_2 + 4);

  param_1[1] = *(int *)(param_2 + 8);

  *(char *)((int)param_1 + 10) = *(char *)(param_2 + 0x1d);

  uVar5 = (unsigned int)*(unsigned short *)(param_2 + 0xc);

  if (((unsigned int)0x00008000 & uVar5) == 0) {

    cVar4 = '\0';

  }

  else {

    cVar4 = '\x10';

  }

  if ((0x800 & uVar5) == 0) {

    cVar1 = '\0';

  }

  else {

    cVar1 = '\b';

  }

  if (((int)DAT_0603f8ae & uVar5) == 0) {

    cVar2 = '\0';

  }

  else {

    cVar2 = '\x04';

  }

  if (((int)PTR_DAT_0603f8b0 & uVar5) == 0) {

    cVar3 = '\0';

  }

  else {

    cVar3 = '\x02';

  }

  *(char *)((int)param_1 + 0xb) = cVar4 + cVar1 + cVar2 + cVar3;

  *(char *)(param_1 + 2) = *(char *)(param_2 + 0xe);

  *(char *)((int)param_1 + 9) = *(char *)(param_2 + 0xf);

  return;

}

int * FUN_0603f93c(param_1)
    int *param_1;
{

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 1;

  param_1[5] = 0;

  param_1[6] = 0;

  FUN_0603f970(param_1,3);

  param_1[0xc] = 1;

  *(char *)(param_1 + 0xd) = 0;

  return param_1;

}

/* cd_buf_set_mode -- Set buffer mode and apply configuration.
 * Saves previous mode from +0x35, stores new mode.
 * If mode is 0-3, applies configuration from 12-byte table at 0x0606364C.
 * Returns the previous mode. */
char FUN_0603f970(int param_1, int param_2)
{
    char prev = *(char *)(param_1 + 0x35);
    *(char *)(param_1 + 0x35) = (char)param_2;

    if (param_2 >= 0 && param_2 < 4) {
        FUN_0603f92c(param_1, 0, 0x0606364C + (char)((char)param_2 * '\f'));
    }

    return prev;
}

unsigned short FUN_0603face(param_1, param_2)
    int *param_1;
    int *param_2;
{

  unsigned char bVar1;

  unsigned short uVar3;

  int iVar2;

  int uVar4;

  int uVar5;

  int uVar6;

  uVar6 = 0;

  uVar5 = *param_1;

  uVar4 = param_1[2];

  if ((int)param_1[5] < 1) {

    *param_2 = 0;

    return 5;

  }

  if ((*(unsigned char *)(param_1 + 0xd) & DAT_0603fb22) != DAT_0603fb22) {

    *param_2 = 0;

    return *(unsigned char *)(param_1 + 0xd) & DAT_0603fb24;

  }

  uVar3 = *(unsigned char *)(param_1 + 0xd) & DAT_0603fb24;

  bVar1 = (unsigned char)DAT_0603fb22;

  if (uVar3 == 0) {

    FUN_0603fc60(param_1,uVar5,uVar4);

    if (param_1[1] == 0) goto LAB_0603fc40;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 1;

LAB_0603fb50:

    FUN_0603fce4(param_1,uVar5,uVar4);

    if (param_1[3] == 0) goto LAB_0603fc40;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 2;

LAB_0603fb74:

    iVar2 = (*(int(*)())param_1[9])(param_1[8]);

    if (iVar2 == 0) goto LAB_0603fc40;

    FUN_0603ff9c(param_1);

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 3;

LAB_0603fba0:

    iVar2 = (*(int(*)())param_1[0xb])(param_1[8]);

    if (0 < iVar2) goto LAB_0603fc40;

    uVar6 = 1;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 4;

  }

  else {

    if (uVar3 == 1) goto LAB_0603fb50;

    if (uVar3 == 2) goto LAB_0603fb74;

    if (uVar3 == 3) goto LAB_0603fba0;

    if (uVar3 != 4) goto LAB_0603fc40;

  }

  if (param_1[7] == *(int *)(param_1[1] + 8)) {

    (*(int(*)())0x0603F91C)(uVar5,param_1[1],0xffffffff);

    param_1[6] = param_1[6] + *(int *)(param_1[1] + 0xc);

    param_1[1] = 0;

  }

  (*(int(*)())0x0603F91C)(uVar4,param_1[3],0xffffffff);

  param_1[3] = 0;

  if ((int)param_1[6] < (int)param_1[5]) {

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1;

  }

  else {

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 5;

  }

LAB_0603fc40:

  *param_2 = uVar6;

  return *(unsigned char *)(param_1 + 0xd) & DAT_0603fcb6;

}

void FUN_0603fc60(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int iVar2;

  iVar2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18);

  if (*(int *)(param_1 + 0x10) < iVar2) {

    iVar2 = *(int *)(param_1 + 0x10);

  }

  iVar1 = iVar2;

  if (1 < *(int *)(param_1 + 0x30)) {

    if (*(int *)(param_1 + 4) != 0) {

      iVar2 = (*(int(*)())0x06034FFC)();

    }

    (*(int(*)())0x0603F8EE)(param_3);

    iVar1 = (*(int(*)())0x06034FFC)();

    if (iVar2 < iVar1) {

      iVar1 = iVar2;

    }

  }

  if (*(int *)(param_1 + 4) == 0) {

    iVar2 = (*(int(*)())0x0603F900)(param_2,iVar1);

    *(int *)(param_1 + 4) = iVar2;

    if (iVar2 != 0) {

      *(int *)(param_1 + 0x1c) = 0;

    }

  }

  return;

}

/* cd_buf_calc_transfer_size -- Calculate transfer size for CD buffer.
 * If state (+0x30) < 2: remaining = total_size - offset, clamp to param_3 limit.
 * If state >= 2: use full buffer size.
 * Stores computed descriptor at +0x0C via FUN_0603F90E. */
void FUN_0603fce4(int param_1, int param_2, int param_3)
{
    register int size_func asm("r3") = 0x0603F8EE;
    int size, limit;

    if (*(int *)(param_1 + 0x30) < 2) {
        size = *(int *)(*(int *)(param_1 + 4) + 8) - *(int *)(param_1 + 0x1c);
        limit = (*(int(*)())size_func)(param_3);
        if (limit <= size) {
            size = (*(int(*)())size_func)(param_3);
        }
    } else {
        size = *(int *)(*(int *)(param_1 + 4) + 8);
    }

    *(int *)(param_1 + 0xc) = (*(int(*)())0x0603F90E)(param_3, size);
}

void FUN_0603fd40(param_1, param_2, param_3, param_4, param_5, param_6)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
    unsigned int param_6;
{

  char *puVar1;

  int iVar2;

  unsigned int uVar3;

  int iStack_58;

  int iStack_54;

  unsigned int uStack_50;

  int uStack_4c;

  int uStack_48;

  unsigned int uStack_44;

  unsigned int uStack_40;

  int uStack_3c;

  int iStack_34;

  int uStack_30;

  int uStack_2c;

  int uStack_28;

  puVar1 = (char *)0x06042BEE;

  (*(int(*)())0x06042BBE)(param_1);

  uStack_30 = 0;

  uStack_2c = 1;

  uStack_28 = 7;

  (*(int(*)())0x06042A8C)(&uStack_30);

  uVar3 = param_6 >> 2;

  if (param_3 < 1) {

    if (param_3 < 0) {

      uStack_4c = 2;

    }

    else {

      uStack_4c = 0;

    }

  }

  else {

    uStack_4c = 1;

  }

  if (param_5 < 1) {

    if (param_5 < 0) {

      uStack_48 = 2;

    }

    else {

      uStack_48 = 0;

    }

  }

  else {

    uStack_48 = 1;

  }

  uStack_44 = (unsigned int)DAT_0603fe2e;

  uStack_40 = uStack_44 >> 2;

  uStack_3c = 0;

  iStack_34 = (int)PTR_DAT_0603fe30;

  iStack_58 = param_4;

  iStack_54 = param_2;

  uStack_50 = uVar3;

  (*(int(*)())0x06042ACA)(&iStack_58,param_1);

  (*(int(*)())0x06042BAC)(param_1);

  do {

    iVar2 = (*(int(*)())puVar1)(param_1);

  } while (iVar2 == 0);

  FUN_0603ffe6(param_6 & 3,param_3 * (uVar3 << 2) + param_2,param_5 * (uVar3 << 2) + param_4);

  (*(int(*)())0x0603C05C)(param_2,param_6);

  return;

}

/* cd_buf_transfer_step -- Execute one DMA transfer step for CD buffer.
 * Reads transfer descriptor from +0x0C, computes source address from
 * base (+0x04) + stride * offset (+0x1C), calls transfer function (+0x28).
 * Advances offset by the transfer count. */
void FUN_0603ff9c(int param_1)
{
    int *desc = *(int **)(param_1 + 0xc);
    int stride = (*(int **)(param_1 + 4))[1];
    int count = desc[2];

    (*(int(*)())(*(int *)(param_1 + 0x28)))(
        *(int *)(param_1 + 0x20),    /* dest */
        *desc,                        /* src offset */
        desc[1],                      /* src param */
        stride * *(int *)(param_1 + 0x1c) + **(int **)(param_1 + 4),  /* src addr */
        stride,                       /* stride */
        count);                       /* count */

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + count;
}

void FUN_0603ffe6(param_1, param_2, param_3)
    int param_1;
    char *param_2;
    int *param_3;
{

  char *puVar1;

  int iVar2;

  int local_4;

  

  if (0 < param_1) {

    local_4 = *param_3;

    iVar2 = 0;

    if (0 < param_1) {

      do {

        puVar1 = (char *)((int)&local_4 + iVar2);

        iVar2 = iVar2 + 1;

        *param_2 = *puVar1;

        param_2 = param_2 + 1;

      } while (iVar2 < param_1);

    }

  }

  return;

}
