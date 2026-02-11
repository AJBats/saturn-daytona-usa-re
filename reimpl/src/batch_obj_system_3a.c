#include "game.h"

extern int DAT_0603a1a2;
extern int DAT_0603a2ca;
extern int DAT_0603a6fa;
extern int DAT_0603a6fc;
extern int DAT_0603a6fe;
extern int DAT_0603a8bc;
extern int DAT_0603aa7c;
extern int DAT_0603aa7e;
extern int DAT_0603ac16;
extern int DAT_0603ac18;
extern int DAT_0603ac1a;
extern int DAT_0603ac9e;
extern int DAT_0603adda;
extern int DAT_0603ae60;
extern int DAT_0603ae62;
extern int DAT_0603af70;
extern int DAT_0603af72;
extern int DAT_0603b270;
extern int DAT_0603b4c6;
extern int DAT_0603b4c8;
extern int DAT_0603b4ca;
extern int DAT_0603b4cc;
extern int DAT_0603b4ce;
extern int DAT_0603b7a4;
extern int DAT_0603b7a6;
extern int DAT_0603b7a8;
extern int DAT_0603b7aa;
extern int DAT_0603b838;
extern int DAT_0603b83a;
extern int DAT_0603b88c;
extern int DAT_0603b88e;
extern int DAT_0603b91c;
extern int DAT_0603b91e;
extern int DAT_0603bae6;
extern int DAT_0603bbb0;
extern int DAT_0603bbb2;
extern int DAT_0603bbb4;
extern int DAT_0603bbb6;
extern int DAT_0603bc50;
extern int DAT_0603bc52;
extern int DAT_0603bc54;
extern int DAT_0603bc56;
extern int DAT_0603be0e;
extern int DAT_0603bf6e;
extern unsigned int FUN_0603a7b0();
extern void FUN_0603ab46();
extern void FUN_0603adac();
extern int FUN_0603aee8();
extern void FUN_0603af94();
extern int FUN_0603afd0();
extern int FUN_0603b058();
extern int FUN_0603b21c();
extern int FUN_0603b28e();
extern void FUN_0603b3fa();
extern unsigned int FUN_0603b424();
extern void FUN_0603b734();
extern void FUN_0603b74c();
extern int FUN_0603b7c0();
extern int FUN_0603b81e();
extern int FUN_0603b878();
extern void FUN_0603b8b4();
extern void FUN_0603b8f4();
extern int FUN_0603b93c();
extern int FUN_0603b96a();
extern int FUN_0603b9a4();
extern void FUN_0603b9d6();
extern int FUN_0603ba2c();
extern int FUN_0603bac6();
extern int FUN_0603bb86();
extern int FUN_0603bc86();
extern int FUN_0603bd1c();
extern int FUN_0603bdac();
extern void FUN_0603be7c();
extern void FUN_0603bf22();
extern int FUN_0603bf5a();
extern int PTR_DAT_0603a1a4;
extern int PTR_DAT_0603aa80;
extern int PTR_DAT_0603addc;
extern int PTR_DAT_0603ae64;
extern int PTR_DAT_0603af74;
extern int PTR_DAT_0603b83c;
extern int PTR_DAT_0603bcd0;
extern int PTR_DAT_0603bd64;
extern int PTR_DAT_0603be10;

char FUN_0603a01c(param_1)
    unsigned int param_1;
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  puVar3 = (char *)0x060A4CD4;

  puVar2 = (char *)0x060A4CEC;

  func_0x0603aa82();

  puVar5 = (char *)0x060A4CD0;

  puVar4 = (char *)0x060A4CC8;

  *(int *)0x060A4CD0 = *(int *)0x060A4CC8;

  *(int *)puVar3 = *(int *)puVar4;

  *(int *)0x060A4CCC = 1;

  puVar4 = (char *)0x060A4CFD;

  cVar1 = *(int *)0x060A4CFC;

  if (cVar1 == ' ') {

    if ((unsigned char)*(int *)0x060A4D02 < 5) {

      *(char **)puVar5 = (char *)0x060A4CFD;

      *(char **)puVar3 = puVar4 + 2;

    }

    else {

      *(int *)puVar3 = *(int *)puVar3 + 2;

    }

  }

  while (*(unsigned int *)puVar2 < param_1) {

    **(char **)puVar3 = **(char **)puVar2;

    *(int *)puVar3 = *(int *)puVar3 + 1;

    *(int *)puVar2 = *(int *)puVar2 + 2;

  }

  return cVar1;

}

char * FUN_0603a0b0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  short sVar8;

  unsigned short *puVar9;

  int iVar10;

  unsigned char *pbVar11;

  unsigned int uVar12;

  puVar5 = (char *)0x060A4CD0;

  puVar4 = (char *)0x060A4CCC;

  puVar3 = (char *)0x060A4CC0;

  puVar2 = (char *)0x060A4CB4;

  puVar1 = (char *)0x060A4CAE;

  if (*(int *)0x060A4CFC == ' ') {

    **(char **)0x060A4CD0 = (char)DAT_0603a1a2;

    *(char *)((unsigned int)(unsigned char)*puVar4 + *(int *)puVar5) = (char)DAT_0603a1a2;

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 0x80) == PTR_DAT_0603a1a4) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x20) == 0x20) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xdf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xef;

      }

    }

    else if (10 < *(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 2) + *(int *)puVar5)) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x20) == 0x20) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xdf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xef;

      }

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 0x40) == 0x40) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x10) == 0x10) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xbf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & (unsigned char)DAT_0603a2ca;

      }

    }

    else if (10 < *(unsigned char *)((unsigned int)(unsigned char)*puVar4 * 3 + *(int *)puVar5)) {

      if ((*(unsigned char *)((unsigned int)(unsigned char)(*puVar4 << 1) + *(int *)puVar5) & 0x10) == 0x10) {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xbf;

      }

      else {

        **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & (unsigned char)DAT_0603a2ca;

      }

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 1) == 1) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfb;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 4) == 4) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfe;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 2) == 2) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xfd;

    }

    if ((*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1)) & 8) == 8) {

      **(unsigned char **)puVar5 = **(unsigned char **)puVar5 & 0xf7;

    }

    *puVar1 = *(int *)0x060A4D02;

  }

  puVar6 = (char *)0x060A4CBC;

  puVar7 = (char *)(unsigned int)(unsigned char)*(int *)0x060A4CAF;

  if (puVar7 == (char *)0x0) {

    *(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[1] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)0x00000010) {

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 2) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1));

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 4) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*puVar4 * 3);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 6) =

         (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 2));

    puVar9 = (unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3);

    puVar9[4] = ~*(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6) | *puVar9;

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    *(short *)(iVar10 + 10) =

         *(short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6 + 2) - *(short *)(iVar10 + 2);

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    *(short *)(iVar10 + 0xc) =

         *(short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6 + 4) - *(short *)(iVar10 + 4);

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    sVar8 = *(short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6 + 6) - *(short *)(iVar10 + 6);

    puVar7 = (char *)(int)sVar8;

    *(short *)(iVar10 + 0xe) = sVar8;

  }

  else if (puVar7 == (char *)0x00000020) {

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    *(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3 + 2) =

         ~(unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1));

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    if ((*(unsigned short *)(iVar10 + 2) & 0x10) == 0x10) {

      sVar8 = 1;

    }

    else {

      sVar8 = -1;

    }

    *(unsigned short *)(iVar10 + 4) = (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)*puVar4 * 3) * sVar8;

    iVar10 = *(int *)puVar2 * 0x12 + *(int *)puVar3;

    if ((*(unsigned short *)(iVar10 + 2) & 0x20) == 0x20) {

      sVar8 = 1;

    }

    else {

      sVar8 = -1;

    }

    *(unsigned short *)(iVar10 + 6) = (unsigned short)*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 2)) * sVar8;

    puVar9 = (unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 0x12 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[4] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)0x00000030) {

    *(unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    *(unsigned char *)(*(int *)puVar2 * 10 + *(int *)puVar3 + 2) =

         ~*(unsigned char *)(*(int *)puVar5 + (unsigned int)(unsigned char)(*puVar4 << 1));

    *(char *)(*(int *)puVar2 * 10 + *(int *)puVar3 + 3) =

         *(char *)((unsigned int)(unsigned char)*puVar4 * 3 + *(int *)puVar5);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 10 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[2] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)0xe1) {

    *(char *)(*(int *)puVar2 * 3 + *(int *)puVar3) = **(char **)puVar5;

    pbVar11 = (unsigned char *)(*(int *)puVar2 * 3 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned char *)(*(int *)puVar2 * 3 + *(int *)puVar6) & 0xff | (unsigned int)*pbVar11);

    pbVar11[1] = (unsigned char)puVar7;

  }

  else if (puVar7 == (char *)0xe2) {

    *(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3) =

         ((**(char **)puVar5) << 8 | ((unsigned char *)*(int *)puVar5)[(unsigned char)*puVar4]);

    puVar9 = (unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar3);

    puVar7 = (char *)

             (~(unsigned int)*(unsigned short *)(*(int *)puVar2 * 6 + *(int *)puVar6) & 0xffff | (unsigned int)*puVar9);

    puVar9[1] = (unsigned short)puVar7;

  }

  else if (puVar7 == (char *)(int)DAT_0603a6fe) {

    for (uVar12 = 0; uVar12 < (unsigned char)*puVar1; uVar12 = uVar12 + 1) {

      puVar7 = (char *)((unsigned char)*puVar4 * uVar12 + *(int *)puVar5);

      *(char *)(((unsigned char)*puVar1 + 1) * *(int *)puVar2 + *(int *)puVar3 + uVar12 + 1) = *puVar7;

    }

  }

  return puVar7;

}

void FUN_0603a6c0()
{

  *(int *)0x060A4D0C = 1;

  *(int *)0x060A4D0D = 0;

  *(int *)0x060A4D0E = 0;

  *(int *)0x060A4D0F = 0;

  *(int *)0x060A4D10 = 0;

  *(int *)0x060A4D11 = 0;

  *(int *)0x060A4CD8 = 0;

  *(int *)0x060A4CB4 = 0;

  *(int *)0x060A4CF0 = 0;

  *(int *)0x060A4CF8 = 0;

  *(int *)0x060A4CA9 = 0;

  return;

}

int FUN_0603a72c()
{

  char *puVar1;

  char *puVar2;

  if ((SMPC_SF & 1) == 1) {

    return 1;

  }

  SMPC_SF = 1;

  puVar2 = (char *)0x20100001;

  puVar1 = (char *)0x06063602;

  SMPC_IREG0 = *(int *)0x06063602;

  puVar2[2] = puVar1[1];

  puVar2[4] = puVar1[2];

  puVar2[0x1e] = 0x10;

  return 0;

}

void FUN_0603a766()
{
  int *counter;
  unsigned short *limit;

  counter = (int *)0x060A4CB4;
  limit = (unsigned short *)0x060A4CAC;

  goto check;

loop:
  FUN_0603ab46(255);
  FUN_0603a7b0();
  *counter = *counter + 1;

check:
  if (*counter < (int)(unsigned int)*limit) {
    goto loop;
  }
}

unsigned int FUN_0603a7b0()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned char bVar9;

  puVar5 = (char *)0x0000FFFF;

  puVar4 = (char *)0x060A4CC0;

  puVar3 = (char *)0x060A4CB4;

  puVar2 = (char *)0x060A4CAE;

  uVar6 = (unsigned int)(unsigned char)*(int *)0x060A4CAF;

  uVar1 = SUB42(0x0000FFFF,0);

  if (uVar6 == 0) {

    *(short *)(*(int *)0x060A4CB4 * 6 + *(int *)0x060A4CC0) = uVar1;

    iVar7 = *(int *)puVar3;

  }

  else {

    if (uVar6 == 0x10) {

      *(short *)(*(int *)0x060A4CB4 * 0x12 + *(int *)0x060A4CC0) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 2) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 4) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 6) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 8) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 10) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xc) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xe) = 0;

      return 0;

    }

    if (uVar6 == 0x20) {

      *(short *)(*(int *)0x060A4CB4 * 0x12 + *(int *)0x060A4CC0 + 2) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 4) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 6) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 10) = uVar1;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xc) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 0xe) = 0;

      *(short *)(*(int *)puVar3 * 0x12 + *(int *)puVar4 + 8) = uVar1;

      return (unsigned int)puVar5 & 0xffff;

    }

    bVar9 = (unsigned char)DAT_0603a8bc;

    if (uVar6 == 0x30) {

      *(short *)(*(int *)0x060A4CB4 * 10 + *(int *)0x060A4CC0) = uVar1;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 2) = bVar9;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 3) = bVar9;

      *(short *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 4) = uVar1;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 6) = bVar9;

      *(unsigned char *)(*(int *)puVar3 * 10 + *(int *)puVar4 + 7) = bVar9;

      return (unsigned int)bVar9;

    }

    if (uVar6 == 0xe1) {

      *(unsigned char *)(*(int *)0x060A4CB4 * 3 + *(int *)0x060A4CC0) = bVar9;

      *(unsigned char *)(*(int *)puVar3 * 3 + *(int *)puVar4 + 1) = bVar9;

      return (unsigned int)bVar9;

    }

    if (uVar6 != 0xe2) {

      if (uVar6 != (int)PTR_DAT_0603aa80) {

        return uVar6;

      }

      for (uVar8 = 0; uVar8 < (unsigned char)*puVar2; uVar8 = uVar8 + 1) {

        uVar6 = (unsigned int)bVar9;

        *(unsigned char *)(((unsigned char)*puVar2 + 1) * *(int *)puVar3 + *(int *)puVar4 + uVar8 + 1) = bVar9;

      }

      return uVar6;

    }

    *(short *)(*(int *)0x060A4CB4 * 6 + *(int *)0x060A4CC0) = uVar1;

    iVar7 = *(int *)puVar3;

  }

  *(short *)(iVar7 * 6 + *(int *)puVar4 + 2) = uVar1;

  return (unsigned int)puVar5 & 0xffff;

}

void FUN_0603ab46(param_1)
    char param_1;
{

  unsigned short uVar1;

  int iVar2;

  uVar1 = (unsigned short)(unsigned char)*(int *)0x060A4CAF;

  if (uVar1 == 0) {

    iVar2 = *(int *)0x060A4CB4;

LAB_0603abe6:

    *(char *)(iVar2 * 6 + *(int *)0x060A4CC0 + 4) = param_1;

  }

  else {

    if (uVar1 == 0x10) {

      iVar2 = *(int *)0x060A4CB4;

    }

    else {

      if (uVar1 != 0x20) {

        if (uVar1 == 0x30) {

          *(char *)(*(int *)0x060A4CB4 * 10 + *(int *)0x060A4CC0 + 8) = param_1;

          return;

        }

        if (uVar1 == DAT_0603ac16) {

          *(char *)(*(int *)0x060A4CB4 * 3 + *(int *)0x060A4CC0 + 2) = param_1;

          return;

        }

        if (uVar1 != DAT_0603ac18) {

          if (uVar1 != DAT_0603ac1a) {

            return;

          }

          *(char *)

           (((unsigned char)*(int *)0x060A4CAE + 1) * *(int *)0x060A4CB4 + *(int *)0x060A4CC0) =

               param_1;

          return;

        }

        iVar2 = *(int *)0x060A4CB4;

        goto LAB_0603abe6;

      }

      iVar2 = *(int *)0x060A4CB4;

    }

    *(char *)(iVar2 * 0x12 + *(int *)0x060A4CC0 + 0x10) = param_1;

  }

  return;

}

int FUN_0603ac1c(param_1, param_2, param_3)
    int param_1;
    unsigned int param_2;
    int *param_3;
{

  int iVar1;

  if ((param_1 < 1) || (0x18 < param_1)) {

    iVar1 = -5;

  }

  else if ((param_2 & 3) == 0) {

    if ((param_3 == (int *)0x0) ||

       ((((*param_3 == 0 || (*param_3 == 1)) && (1 < param_3[1])) && (param_3[2] != 0)))) {

      CD_STATE_A = param_2;

      FUN_0603b74c();

      iVar1 = (*(int(*)())0x0604000C)(param_3 == (int *)0x0);

      if (iVar1 != 0) {

        iVar1 = FUN_0603b93c();

        return iVar1;

      }

      if ((*(unsigned int *)((int)DAT_0603ac9e + CD_STATE_A) & 1) == 0) {

        iVar1 = FUN_0603b93c(0xfffffffe);

        return iVar1;

      }

      if (param_3 == (int *)0x0) {

        iVar1 = (*(int(*)())0x0603F22C)();

        if (iVar1 < 0) {

          iVar1 = FUN_0603b93c(0xfffffff9);

          return iVar1;

        }

      }

      else {

        iVar1 = (*(int(*)())0x0603BC12)(param_3);

        if (iVar1 < 1) {

          iVar1 = FUN_0603b93c(0xffffffff);

          return iVar1;

        }

      }

      FUN_0603adac(param_3);

      FUN_0603b93c(0);

    }

    else {

      iVar1 = -4;

    }

  }

  else {

    iVar1 = -0x15;

  }

  return iVar1;

}

void FUN_0603adac(param_1)
    int param_1;
{

  int uVar1;

  int iVar2;

  iVar2 = CD_STATE_A + 0x98;

  if (param_1 == 0) {

    if (*(int *)(CD_STATE_A + 0xa0) != 0) {

      FUN_0603b93c(0xfffffff9);

      return;

    }

    *(int *)(iVar2 + 8) = 0;

    *(int *)(iVar2 + 0xc) = 0;

    *(int *)(iVar2 + 4) = 0;

  }

  else {

    (*(int(*)())0x06035168)();

    uVar1 = FUN_0603b7c0();

    *(int *)(iVar2 + 0xc) = uVar1;

  }

  FUN_0603b93c(0);

  return;

}

int FUN_0603ae08(param_1)
    int param_1;
{

  int iVar1;

  if ((*(int *)(CD_STATE_A + 0xa0) != 0) &&

     (*(int *)(0x98 + CD_STATE_A) == 1)) {

    iVar1 = (*(int(*)())0x0603F148)(*(int *)(CD_STATE_A + 0xa0),param_1,

                       *(int *)(CD_STATE_A + (int)PTR_DAT_0603ae64));

    if (iVar1 < 0) {

      iVar1 = FUN_0603b93c(0xfffffff7);

      return iVar1;

    }

    FUN_0603b93c(0);

    return iVar1;

  }

  iVar1 = FUN_0603b93c(0xfffffff8);

  return iVar1;

}

int FUN_0603aee8(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = (char *)0x060A4D14;

  if ((*(int *)(CD_STATE_A + 0xa0) == 0) ||

     ((-1 < param_1 && (param_1 < *(int *)(CD_STATE_A + (int)DAT_0603af72))))) {

    iVar2 = FUN_0603b81e();

    if (iVar2 == 0) {

      FUN_0603b93c(0xffffffed);

      iVar2 = 0;

    }

    else {

      if (*(int *)(*(int *)puVar1 + 0xa0) == 0) {

        uVar3 = 0;

      }

      else if (*(int *)(*(int *)puVar1 + 0x98) == 0) {

        uVar3 = (*(int(*)())0x0603F1E0)(param_1,*(int *)(*(int *)puVar1 + 0xa0));

      }

      else {

        uVar3 = (*(int(*)())0x0603F1F0)(param_1,*(int *)(*(int *)puVar1 + 0xa0));

      }

      iVar2 = FUN_0603ba2c(iVar2,uVar3,param_1);

      if (iVar2 == 0) {

        FUN_0603b93c(0xfffffff6);

      }

      else {

        FUN_0603b93c(0);

      }

    }

  }

  else {

    FUN_0603b93c(0xfffffff6);

    iVar2 = 0;

  }

  return iVar2;

}

/* cd_request_abort -- Abort a CD request and clean up resources.
 * Gets abort context via FUN_0603b878; if NULL, report error (-11).
 * Otherwise: complete active transfer, cancel pending, release request. */
void FUN_0603af94(int param_1)
{
    int ctx = FUN_0603b878();

    if (ctx == 0) {
        FUN_0603b93c(-11);  /* error: no context */
        return;
    }

    FUN_0603b8b4(param_1);       /* cd_transfer_complete */
    FUN_0603b8f4(param_1);       /* cd_cancel_pending */
    (*(int(*)())0x0603BF22)(ctx, param_1);  /* cd_request_release */
    FUN_0603b93c(0);             /* success */
}

int FUN_0603afd0(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int uVar2;

  int iVar3;

  iVar3 = CD_STATE_A + 4 + (unsigned int)*(unsigned char *)(param_1 + 4) << 4;

  if (param_3 == 1) {

    iVar1 = (*(int(*)())(*(int *)(iVar3 + 0xc)))(*param_1);

    param_2 = param_2 + iVar1;

  }

  else if (param_3 == 2) {

    param_2 = param_2 + *(int *)(*param_1 + 0x10);

  }

  else if (param_3 != 0) {

    uVar2 = FUN_0603b93c(0xfffffff3);

    return uVar2;

  }

  if (param_2 < 0) {

    uVar2 = FUN_0603b93c(0xfffffff1);

    return uVar2;

  }

  uVar2 = (*(int(*)())(*(int *)(iVar3 + 8)))(*param_1,param_2);

  FUN_0603b93c(0);

  return uVar2;

}

/* cd_command_dispatch -- Dispatch CD command via command type vtable.
 * Reads command type from param[4] byte, looks up handler in CD_STATE_A table,
 * calls it with param[0], then invokes callback dispatch (FUN_0603b93c). */
int FUN_0603b058(int *param_1)
{
    int result = (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + CD_STATE_A + 0x10)))(*param_1);
    FUN_0603b93c(0);
    return result;
}

int FUN_0603b1b6(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int *piVar1;

  int iVar2;

  piVar1 = (int *)FUN_0603aee8();

  if (piVar1 == (int *)0x0) {

    iVar2 = FUN_0603b93c(0xfffffff7);

    return iVar2;

  }

  FUN_0603afd0(piVar1,param_2,0);

  param_2 = *(int *)(*piVar1 + 0x10) - param_2;

  if (param_4 == -1) {

    param_4 = param_2 * DAT_0603b270;

  }

  iVar2 = FUN_0603b21c(piVar1,param_2,param_3,param_4);

  FUN_0603af94(piVar1);

  if (-1 < iVar2) {

    FUN_0603b93c(0);

  }

  return iVar2;

}

int FUN_0603b21c(param_1)
    int *param_1;
{

  int iVar1;

  int uVar2;

  int local_18;

  char auStack_14 [4];

  int uStack_10;

  uStack_10 = 0x7FFFFFFF;

  uVar2 = *(int *)(*param_1 + 0x28);

  *(int *)(*param_1 + 0x28) = 0x7FFFFFFF;

  iVar1 = FUN_0603b28e(param_1);

  if (iVar1 == 0) {

    while (iVar1 = FUN_0603b424(param_1), -1 < iVar1) {

      if (iVar1 == 0) {

        FUN_0603b3fa(param_1,auStack_14,&local_18);

        FUN_0603b93c(0);

        *(int *)(*param_1 + 0x28) = uVar2;

        return local_18;

      }

      (*(int(*)())0x060423CC)();

    }

    *(int *)(*param_1 + 0x28) = uVar2;

    uVar2 = FUN_0603b93c();

  }

  else {

    *(int *)(*param_1 + 0x28) = uVar2;

    uVar2 = FUN_0603b93c();

  }

  return uVar2;

}

int FUN_0603b28e(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  int iVar2;

  if (*(char *)((int)param_1 + 0x12) == '\0') {

    FUN_0603b9a4(param_1);

    *(char *)((int)param_1 + 0x11) = 1;

    *(char *)((int)param_1 + 0x12) = 1;

    iVar2 = *(int *)(*param_1 + 0x10);

    iVar1 = FUN_0603b058(param_1);

    iVar2 = iVar2 - iVar1;

    if (param_2 < iVar2) {

      iVar2 = param_2;

    }

    FUN_0603be7c(*param_1,iVar2);

    (*(int(*)())0x0603F9DA)(param_1[2],iVar2);

    (*(int(*)())0x0603EF54)(param_1[1],param_3,param_4,1);

    (*(int(*)())0x0603FA00)(param_1[2]);

    FUN_0603b93c(0);

    return 0;

  }

  FUN_0603b93c(0xfffffff0);

  return 0;

}

void FUN_0603b31c(param_1, param_2)
    int *param_1;
    int param_2;
{

  int iVar1;

  int iVar2;

  if (*(char *)((int)param_1 + 0x12) == '\0') {

    FUN_0603b9a4(param_1);

    *(char *)((int)param_1 + 0x11) = 2;

    *(char *)((int)param_1 + 0x12) = 1;

    iVar2 = *(int *)(*param_1 + 0x10);

    iVar1 = FUN_0603b058(param_1);

    iVar2 = iVar2 - iVar1;

    if (param_2 < iVar2) {

      iVar2 = param_2;

    }

    FUN_0603be7c(*param_1,iVar2);

    (*(int(*)())0x0603F9DA)(param_1[2],0);

    (*(int(*)())0x0603EF54)(param_1[1],0,0,1);

    (*(int(*)())0x0603FA1A)(param_1[2],0xffffffff);

    FUN_0603b93c(0);

    return;

  }

  FUN_0603b93c(0xfffffff0);

  return;

}

/* cd_block_read_start -- Start CD block data read.
 * Extracts sector count from offset +0x11, sets max read length (0x7FFFFFFF),
 * calls CD read function (0x0603EF64), then resets CD state via FUN_0603b93c. */
void FUN_0603b3fa(int param_1, unsigned int *param_2)
{
    *param_2 = (unsigned int)*(unsigned char *)(param_1 + 0x11);
    (*(int(*)())0x0603EF64)(*(int *)(param_1 + 4), 0x7FFFFFFF);
    FUN_0603b93c(0);
}

unsigned int FUN_0603b424(param_1)
    int param_1;
{

  int iVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned char bVar4;

  if (*(char *)(param_1 + 0x12) != '\0') {

    iVar1 = FUN_0603bd1c(param_1);

    if (iVar1 == 0) {

      if (*(char *)(param_1 + 0x11) == '\x02') {

        *(char *)(param_1 + 0x12) = 0;

        FUN_0603b9d6(param_1);

        FUN_0603b93c(0);

        bVar4 = *(unsigned char *)(param_1 + 0x12);

        goto LAB_0603b530;

      }

    }

    else if (iVar1 == 1) {

      iVar3 = FUN_0603bf5a(param_1);

      if (iVar3 == 1) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4ce;

        uVar2 = FUN_0603b93c(0xffffffe8);

        return uVar2;

      }

    }

    else {

      if (iVar1 == 3) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4c8;

        uVar2 = FUN_0603b93c(0xffffffe9);

        return uVar2;

      }

      if (iVar1 == 4) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4ca;

        uVar2 = FUN_0603b93c(0xfffffffe);

        return uVar2;

      }

      if (iVar1 == 5) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4cc;

        uVar2 = FUN_0603b93c(0xffffffec);

        return uVar2;

      }

      if (iVar1 == 6) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4c6;

        uVar2 = FUN_0603b93c(0xffffffff);

        return uVar2;

      }

    }

    iVar3 = FUN_0603bdac(param_1);

    if ((iVar1 == 2) && (iVar3 == 5)) {

      iVar1 = (*(int(*)())0x0603F9F2)(*(int *)(param_1 + 8));

      iVar3 = (*(int(*)())0x0603F9F6)(*(int *)(param_1 + 8));

      FUN_0603afd0(param_1,iVar1 - iVar3,1);

      *(char *)(param_1 + 0x12) = 0;

      FUN_0603b8b4(param_1);

      FUN_0603b8f4(param_1);

      FUN_0603b9d6(param_1);

    }

  }

  FUN_0603b93c(0);

  bVar4 = *(unsigned char *)(param_1 + 0x12);

LAB_0603b530:

  return (unsigned int)bVar4;

}

/* cd_vtable_init -- Initialize CD subsystem function pointer table.
 * Sets 4 handler function pointers in CD_STATE_A structure:
 * +0x04: read, +0x08: write, +0x0C: status, +0x10: error. */
void FUN_0603b734(void)
{
    int base = CD_STATE_A;
    *(char **)(base + 0x04) = (char *)0x060402BC;
    *(char **)(base + 0x08) = (char *)0x0604053A;
    *(char **)(base + 0x0c) = (char *)0x060406A6;
    *(char **)(base + 0x10) = (char *)0x0604069A;
}

void FUN_0603b74c(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  puVar1 = (char *)0x060A4D14;

  **(int **)0x060A4D14 = param_1;

  FUN_0603b734();

  iVar2 = (int)DAT_0603b7a4;

  *(int *)(*(int *)puVar1 + iVar2) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x14) = 0;

  iVar3 = *(int *)puVar1;

  *(int *)(iVar3 + iVar2 + 0x1c) = 0;

  *(int *)(iVar3 + iVar2 + 0x18) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x24) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x30) = 0;

  iVar3 = *(int *)puVar1 + (int)DAT_0603b7a6;

  for (iVar2 = 0; iVar2 < **(int **)puVar1; iVar2 = iVar2 + 1) {

    *(int *)(iVar3 + DAT_0603b7a8) = 0;

    iVar3 = iVar3 + DAT_0603b7aa;

  }

  return;

}

int FUN_0603b7c0(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  int iVar5;

  puVar2 = (char *)0x0603F202;

  puVar1 = (char *)0x0603F216;

  uVar4 = (unsigned int)DAT_0603b838;

  for (iVar5 = 0; iVar5 < param_1[1]; iVar5 = iVar5 + 1) {

    if (*param_1 == 0) {

      uVar3 = (*(int(*)())puVar2)(iVar5,param_1[2]);

    }

    else {

      uVar3 = (*(int(*)())puVar1)(iVar5,param_1[2]);

    }

    if ((uVar3 & uVar4) != 0) break;

  }

  if (param_1[1] < iVar5) {

    iVar5 = 0;

  }

  else {

    iVar5 = iVar5 + 1;

  }

  return iVar5;

}

int FUN_0603b81e()
{

  int iVar1;

  int iVar2;

  iVar2 = 0;

  for (iVar1 = CD_STATE_A + (int)DAT_0603b83a;

      (iVar2 < **(int **)0x060A4D14 && (*(int *)(iVar1 + PTR_DAT_0603b83c) != 0));

      iVar1 = iVar1 + DAT_0603b88c) {

    iVar2 = iVar2 + 1;

  }

  if (iVar2 == **(int **)0x060A4D14) {

    iVar1 = 0;

  }

  else {

    *(int *)(iVar1 + DAT_0603b88e) = 1;

  }

  return iVar1;

}

int FUN_0603b878(param_1)
    int param_1;
{
  int iVar1;
  int iVar2;
  int *pp;

  pp = (int *)0x060A4D14;
  iVar2 = 0;
  iVar1 = *(int *)pp + 0x0C3C;
  goto check;
loop:
  if (iVar1 == param_1) goto done;
  iVar1 = iVar1 + 0x00F0;
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < **(int **)pp) goto loop;
done:
  if (iVar2 == **(int **)pp) {
    iVar1 = 0;
  }
  return iVar1;
}

/* cd_transfer_complete -- Handle CD transfer completion for a request.
 * If param_1 matches the active transfer at CD_STATE_A+0xa8,
 * clears it and calls the completion callback via vtable dispatch. */
void FUN_0603b8b4(int *param_1)
{
    if (*(int **)(CD_STATE_A + 0xa8) == param_1) {
        *(int *)(CD_STATE_A + 0xa8) = 0;
        (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + *(int *)0x060A4D14 + 8)))(*param_1, 1);
    }
}

/* cd_cancel_pending -- Cancel a pending CD request if it matches.
 * Checks CD_STATE_A at offset DAT_0603b91e for param_1.
 * On match: clears the slot and calls abort handler (0x0603FA1A)
 * with the request's data pointer and -1 (cancel signal). */
void FUN_0603b8f4(int param_1)
{
    if (*(int *)(CD_STATE_A + (int)DAT_0603b91e) == param_1) {
        *(int *)(CD_STATE_A + (int)DAT_0603b91e) = 0;
        (*(int(*)())0x0603FA1A)(*(int *)(param_1 + 8), 0xffffffff);
    }
}

int FUN_0603b96a(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  

  iVar2 = CD_STATE_A;

  for (iVar1 = 0;

      (iVar1 < *(int *)(iVar2 + 0x94) && (param_1 != *(int *)((iVar1 << 2) + iVar2 + 0x34)));

      iVar1 = iVar1 + 1) {

  }

  if (iVar1 == *(int *)(iVar2 + 0x94)) {

    iVar1 = -1;

  }

  return iVar1;

}

/* cd_request_register -- Register a new CD request in the pending queue.
 * First checks if param_1 is already registered via FUN_0603b96a.
 * If not found (-1), appends to the queue at CD_STATE_A+0x34,
 * increments queue count at +0x94, returns 0x60 (success).
 * If already queued, returns the existing index. */
int FUN_0603b9a4(int param_1)
{
    int idx = FUN_0603b96a();

    if (idx == -1) {
        int base = CD_STATE_A;
        *(int *)((*(int *)(base + 0x94) << 2) + base + 0x34) = param_1;
        idx = 0x60;
        *(int *)(base + 0x94) = *(int *)(base + 0x94) + 1;
    }

    return idx;
}

void FUN_0603b9d6(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  if (param_1 != 0) {

    iVar2 = FUN_0603b96a();

    if (iVar2 != -1) {

      iVar5 = CD_STATE_A;

      iVar3 = *(int *)(iVar5 + 0x94) + -1;

      *(int *)(iVar5 + 0x94) = iVar3;

      iVar4 = iVar2 << 2;

      iVar1 = (iVar2 + 1) << 2;

      for (; iVar2 < iVar3; iVar2 = iVar2 + 1) {

        *(int *)(iVar5 + 0x34 + iVar4) = *(int *)(iVar1 + iVar5 + 0x34);

        iVar4 = iVar4 + 4;

        iVar1 = iVar1 + 4;

      }

    }

    return;

  }

  return;

}

int FUN_0603ba2c(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  int uVar1;

  int iVar2;

  int uVar3;

  int uVar4;

  uVar1 = (*(int(*)())0x0603F93C)(param_1 + 0x40);

  if (param_1 == 0) {

    param_1 = 0;

  }

  else {

    iVar2 = FUN_0603bc86(param_1,param_1,param_3,param_2);

    if (iVar2 == 0) {

      param_1 = 0;

    }

    else {

      uVar3 = (*(int(*)())0x0603EF34)(DAT_0603bae6 + param_1,0,0xffffffff);

      uVar4 = (*(int(*)())0x0603F8B8)(param_1 + 0x90,uVar3,0x0603EF64,0x0603EFD4,0x0603EFE6,

                         0x0603F036,0x0603F070);

      (*(int(*)())0x0603F9B8)(uVar1,iVar2,uVar4);

      *(int *)(param_1 + 4) = uVar3;

      *(char *)(param_1 + 0x11) = 0;

      *(char *)(param_1 + 0x12) = 0;

      *(int *)(param_1 + 8) = uVar1;

    }

  }

  return param_1;

}

int FUN_0603bac6(param_1)
    int param_1;
{

  int iVar1;

  int uVar2;

  int iVar3;

  int iVar4;

  int uVar5;

  int local_24;

  int iStack_20;

  char uStack_1c;

  char uStack_1b;

  char uStack_1a;

  char uStack_19;

  uVar5 = 0;

  iVar1 = (*(int(*)())0x06040680)();

  if (iVar1 == 0) {

    uVar5 = 0;

  }

  else {

    local_24 = (*(int(*)())0x06040F82)();

    local_24 = local_24 + DAT_0603bbb0;

    iVar4 = 0x800;

    uStack_1a = 0;

    uStack_19 = 0;

    uStack_1c = 0;

    uStack_1b = 0;

    iStack_20 = iVar4;

    uVar2 = FUN_0603b81e();

    iVar1 = FUN_0603ba2c(uVar2,&local_24,0);

    if ((iVar1 != 0) && (iVar3 = FUN_0603b21c(iVar1,1,param_1,iVar4), iVar3 == iVar4)) {

      uVar5 = 1;

    }

    FUN_0603bf22(uVar2,iVar1);

  }

  return uVar5;

}

int FUN_0603bb86(param_1)
    int *param_1;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  puVar1 = (char *)0x060A4D14;

  if ((*(unsigned int *)((int)DAT_0603bbb4 + CD_STATE_A) & 1) == 0) {

    uVar2 = 0;

  }

  else {

    iVar3 = FUN_0603bac6(CD_STATE_A + (int)DAT_0603bbb6);

    if (iVar3 == 0) {

      uVar2 = 0;

    }

    else {

      iVar3 = (int)DAT_0603bc50 + *(int *)puVar1 + (int)DAT_0603bc52;

      (*(int(*)())0x060360FC)(param_1,iVar3 + 6,4);

      *param_1 = *param_1 + (int)DAT_0603bc54;

      (*(int(*)())0x060360FC)(param_1 + 1,iVar3 + 0xe,4);

      if (param_1[1] == 0) {

        uVar2 = 0;

      }

      else {

        *(char *)((int)param_1 + 10) = 0;

        *(char *)((int)param_1 + 0xb) = 0;

        *(char *)(param_1 + 2) = 0;

        *(char *)((int)param_1 + 9) = 0;

        uVar2 = 1;

      }

    }

  }

  return uVar2;

}

int FUN_0603bc12(param_1)
    int param_1;
{

  int iVar1;

  int uVar2;

  int unaff_r13 = 0;

  char auStack_18 [4];

  int uStack_14;

  iVar1 = FUN_0603bb86(auStack_18);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    unaff_r13 = FUN_0603b81e();

    iVar1 = FUN_0603ba2c(unaff_r13,auStack_18,0);

  }

  if (((*(unsigned int *)((int)DAT_0603bc56 + CD_STATE_A) & 1) == 0) || (iVar1 != 0)) {

    uVar2 = (*(int(*)())0x0603F0FC)(iVar1,param_1,uStack_14);

    if (iVar1 != 0) {

      FUN_0603bf22(unaff_r13,iVar1);

    }

  }

  else {

    uVar2 = 0xfffffffd;

  }

  return uVar2;

}

int FUN_0603bc86(param_1, param_2, param_3, param_4)
    int param_1;
    int *param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  int uVar2;

  int iVar3;

  iVar1 = (*(int(*)())0x060400D6)(param_1 + 0x14,param_4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    *param_2 = iVar1;

    iVar3 = (*(int(*)())0x0604077C)(PTR_DAT_0603bcd0 + param_1,iVar1,*(int *)(iVar1 + 0xc),

                       *(char *)(iVar1 + 0x1c),0,param_2,param_4);

    if (iVar3 == 0) {

      uVar2 = 0;

    }

    else {

      (*(int(*)())0x060401E4)(iVar1,iVar3);

      uVar2 = (*(int(*)())0x0603F8B8)(param_1 + 0x78,iVar3,0x060408B0,0x06040954,0x06040AF8,

                         0x06040C50,0x06040C5C);

      *(char *)(param_2 + 4) = 0;

    }

  }

  return uVar2;

}

int FUN_0603bd1c(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x060A4D14;

  if ((*(int **)(CD_STATE_A + 0xa8) == (int *)0x0

      ) || (*(int **)(CD_STATE_A + 0xa8) == param_1)) {

    iVar2 = (*(int(*)())(*(int *)((unsigned int)*(unsigned char *)(param_1 + 4) << 4 + CD_STATE_A + 4)))(*param_1);

    if (iVar2 == 0) {

      *(int **)(*(int *)puVar1 + 0xa8) = param_1;

    }

    else if ((iVar2 == 2) && (*(int **)(*(int *)puVar1 + 0xa8) == param_1)) {

      *(int *)(*(int *)puVar1 + 0xa8) = 0;

    }

  }

  else {

    iVar2 = 5;

  }

  return iVar2;

}

int FUN_0603bdac(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char auStack_14 [8];

  iVar2 = (*(int(*)())0x0603FACE)(*(int *)(param_1 + 8),auStack_14);

  puVar1 = (char *)0x060A4D14;

  if ((iVar2 == 5) ||

     (iVar3 = (*(int(*)())0x0603EFD4)(*(int *)(param_1 + 4)), iVar3 == 0)) {

    (*(int(*)())0x0603FA1A)(*(int *)(param_1 + 8),0xffffffff);

    if (*(int *)(*(int *)puVar1 + (int)PTR_DAT_0603be10) == param_1) {

      *(int *)(*(int *)puVar1 + (int)PTR_DAT_0603be10) = 0;

    }

    iVar2 = 5;

  }

  else if (iVar2 != 0) {

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_0603be10) = param_1;

    *(char *)(param_1 + 0x12) = 1;

  }

  return iVar2;

}

/* cd_seek_or_reset -- Seek to position or reset based on flags.
 * If flag bits 5-6 at param_1+0x1D are clear, calls cd_session_seek.
 * Otherwise, stores position at +0x20 and zeros offset at +0x24. */
void FUN_0603be7c(int param_1, int param_2)
{
    if ((*(unsigned char *)(param_1 + 0x1d) & 0x60) == 0) {
        (*(int(*)())0x060401F8)();
        return;
    }
    *(int *)(param_1 + 0x20) = param_2;
    *(int *)(param_1 + 0x24) = 0;
}

/* cd_request_release -- Release a CD request and clean up.
 * Unregisters param_2 via FUN_0603b9d6, clears slot in param_1.
 * If param_2 is non-NULL, frees the associated buffer via FUN_0604087C. */
void FUN_0603bf22(int param_1, int *param_2)
{
    FUN_0603b9d6(param_2);
    *(int *)(param_1 + DAT_0603bf6e) = 0;

    if (param_2 == (int *)0x0)
        return;

    (*(int(*)())0x0604087C)(*(int *)(*param_2 + 0x18));
}

/* cd_get_read_offset -- Get current read offset for a CD request.
 * If flag bits 5-6 at (*param_1)+0x1D are clear (normal mode),
 * returns the sector offset from the session structure.
 * Otherwise returns 0 (no offset in direct mode). */
int FUN_0603bf5a(int *param_1)
{
    if ((*(unsigned char *)(*param_1 + 0x1d) & 0x60) == 0)
        return *(int *)(*(int *)(*param_1 + 0x18) + 0x24);

    return 0;
}
