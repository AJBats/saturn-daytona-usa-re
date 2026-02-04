extern int DAT_06011fd6;

extern int DAT_06011fda;

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

  iVar7 = (int)DAT_06011fda;

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
