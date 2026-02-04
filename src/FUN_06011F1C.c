extern int DAT_06011fd4;

extern int DAT_06011fd6;

extern int DAT_06011fd8;

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
