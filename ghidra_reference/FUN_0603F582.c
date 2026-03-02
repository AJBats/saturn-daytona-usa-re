extern int DAT_0603f682;

extern int FUN_0603f3f6();
extern int FUN_0603f4e0();
extern int FUN_0603f500();
extern int FUN_0603f534();

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
