extern int PTR_DAT_0602c66c;

extern int PTR_DAT_0602c66c;

extern int PTR_DAT_0602c67c;

extern int PTR_DAT_0602c67c;

void FUN_0602c494(param_1, param_2)
    unsigned int param_1;
    unsigned short *param_2;
{

  unsigned short uVar1;

  short sVar2;

  unsigned short uVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned short *puVar7;

  unsigned int uVar8;

  unsigned short *puVar9;

  int iVar10;

  short *psVar11;

  unsigned short *puVar12;

  unsigned short *puVar13;

  int iVar14;

  *(char **)0x060A2468 = 0x06094FA8;

  uVar8 = 0;

  puVar7 = param_2;

  puVar9 = (unsigned short *)0x060A17A8;

  do {

    uVar1 = *puVar7;

    puVar7 = puVar7 + 1;

    uVar8 = uVar8 + 1;

    *puVar9 = uVar1;

    puVar4 = 0x060A2468;

    puVar9 = puVar9 + 1;

  } while (uVar8 < param_1);

  *(int *)(0x060A2468 + -4) = 0;

  *(int *)(puVar4 + -8) = 0;

  *(int *)(puVar4 + -0xc) = 0;

  *(int *)(puVar4 + -0x10) = 0;

  *(int *)(puVar4 + -0x14) = 0;

  *(int *)(puVar4 + -0x18) = 0;

  *(int *)(puVar4 + -0x1c) = 0;

  *(int *)(puVar4 + -0x20) = 0;

  *(int *)(puVar4 + -0x24) = 0;

  *(int *)(puVar4 + -0x28) = 0;

  *(int *)(puVar4 + -0x2c) = 0;

  *(int *)(puVar4 + -0x30) = 0;

  *(int *)(puVar4 + -0x34) = 0;

  *(int *)(puVar4 + -0x38) = 0;

  *(int *)(puVar4 + -0x3c) = 0;

  *(int *)(puVar4 + -0x40) = 0;

  puVar5 = 0x060A2428;

  puVar4 = 0x06094FA8;

  uVar8 = 0;

  iVar10 = 0x640;

  psVar11 = (short *)0x060A17A8;

  do {

    sVar2 = *psVar11;

    psVar11 = psVar11 + 1;

    uVar1 = *(unsigned short *)(puVar5 + (((int)sVar2 & 0x1fU) << 1));

    *(unsigned short *)(puVar5 + (((int)sVar2 & 0x1fU) << 1)) = uVar1 + 1;

    *(short *)(puVar4 + (unsigned int)(uVar1 << 1) + ((int)sVar2 & 0x1fU) * iVar10) = (short)uVar8;

    uVar8 = uVar8 + 1;

  } while (uVar8 < param_1);

  iVar14 = 0;

  iVar10 = 0x640;

  puVar7 = (unsigned short *)0x060A2428;

  puVar9 = param_2;

  puVar13 = (unsigned short *)0x06094FA8;

  do {

    uVar1 = *puVar7;

    puVar7 = puVar7 + 1;

    uVar8 = (unsigned int)uVar1;

    puVar12 = (unsigned short *)((int)puVar13 + iVar10);

    if (uVar8 != 0) {

      do {

        uVar1 = *puVar13;

        puVar13 = puVar13 + 1;

        uVar8 = uVar8 - 1;

        *puVar9 = uVar1;

        puVar9 = puVar9 + 1;

      } while (0 < (int)uVar8);

    }

    puVar4 = 0x060A2468;

    iVar14 = iVar14 + 1;

    puVar13 = puVar12;

  } while (iVar14 < 0x20);

  *(int *)(0x060A2468 + -4) = 0;

  *(int *)(puVar4 + -8) = 0;

  *(int *)(puVar4 + -0xc) = 0;

  *(int *)(puVar4 + -0x10) = 0;

  *(int *)(puVar4 + -0x14) = 0;

  *(int *)(puVar4 + -0x18) = 0;

  *(int *)(puVar4 + -0x1c) = 0;

  *(int *)(puVar4 + -0x20) = 0;

  *(int *)(puVar4 + -0x24) = 0;

  *(int *)(puVar4 + -0x28) = 0;

  *(int *)(puVar4 + -0x2c) = 0;

  *(int *)(puVar4 + -0x30) = 0;

  *(int *)(puVar4 + -0x34) = 0;

  *(int *)(puVar4 + -0x38) = 0;

  *(int *)(puVar4 + -0x3c) = 0;

  *(int *)(puVar4 + -0x40) = 0;

  uVar8 = 0;

  puVar7 = param_2;

  do {

    uVar6 = *(unsigned short *)(0x060A17A8 + (unsigned int)(*puVar7 << 1)) >> 5 & 0x1f;

    uVar1 = *(unsigned short *)(0x060A2428 + (uVar6 << 1));

    *(unsigned short *)(0x060A2428 + (uVar6 << 1)) = uVar1 + 1;

    uVar8 = uVar8 + 1;

    uVar3 = *puVar7;

    puVar7 = puVar7 + 1;

    *(unsigned short *)(0x06094FA8 + (unsigned int)(uVar1 << 1) + uVar6 * 0x640) = uVar3;

  } while (uVar8 < param_1);

  iVar14 = 0;

  iVar10 = 0x640;

  puVar7 = (unsigned short *)0x060A2428;

  puVar9 = param_2;

  puVar13 = (unsigned short *)0x06094FA8;

  do {

    uVar1 = *puVar7;

    puVar7 = puVar7 + 1;

    uVar8 = (unsigned int)uVar1;

    puVar12 = (unsigned short *)((int)puVar13 + iVar10);

    if (uVar8 != 0) {

      do {

        uVar1 = *puVar13;

        puVar13 = puVar13 + 1;

        uVar8 = uVar8 - 1;

        *puVar9 = uVar1;

        puVar9 = puVar9 + 1;

      } while (0 < (int)uVar8);

    }

    puVar4 = 0x060A2468;

    iVar14 = iVar14 + 1;

    puVar13 = puVar12;

  } while (iVar14 < 0x20);

  *(int *)(0x060A2468 + -4) = 0;

  *(int *)(puVar4 + -8) = 0;

  *(int *)(puVar4 + -0xc) = 0;

  *(int *)(puVar4 + -0x10) = 0;

  *(int *)(puVar4 + -0x14) = 0;

  *(int *)(puVar4 + -0x18) = 0;

  *(int *)(puVar4 + -0x1c) = 0;

  *(int *)(puVar4 + -0x20) = 0;

  *(int *)(puVar4 + -0x24) = 0;

  *(int *)(puVar4 + -0x28) = 0;

  *(int *)(puVar4 + -0x2c) = 0;

  *(int *)(puVar4 + -0x30) = 0;

  *(int *)(puVar4 + -0x34) = 0;

  *(int *)(puVar4 + -0x38) = 0;

  *(int *)(puVar4 + -0x3c) = 0;

  *(int *)(puVar4 + -0x40) = 0;

  uVar8 = 0;

  puVar7 = param_2;

  do {

    uVar6 = (unsigned int)(int)(char)((int *)0x060A17A8)[(unsigned int)(*puVar7 << 1)] >> 2 & 0x1f;

    uVar1 = *(unsigned short *)(0x060A2428 + (uVar6 << 1));

    *(unsigned short *)(0x060A2428 + (uVar6 << 1)) = uVar1 + 1;

    uVar8 = uVar8 + 1;

    uVar3 = *puVar7;

    puVar7 = puVar7 + 1;

    *(unsigned short *)(0x06094FA8 + (unsigned int)(uVar1 << 1) + uVar6 * 0x640) = uVar3;

  } while (uVar8 < param_1);

  iVar14 = 0;

  iVar10 = 0x640;

  puVar7 = (unsigned short *)0x060A2428;

  puVar9 = (unsigned short *)0x06094FA8;

  do {

    uVar1 = *puVar7;

    puVar7 = puVar7 + 1;

    uVar8 = (unsigned int)uVar1;

    puVar13 = (unsigned short *)((int)puVar9 + iVar10);

    if (uVar8 != 0) {

      do {

        uVar1 = *puVar9;

        puVar9 = puVar9 + 1;

        uVar8 = uVar8 - 1;

        *param_2 = uVar1;

        param_2 = param_2 + 1;

      } while (0 < (int)uVar8);

    }

    iVar14 = iVar14 + 1;

    puVar9 = puVar13;

  } while (iVar14 < 0x20);

  return;

}
