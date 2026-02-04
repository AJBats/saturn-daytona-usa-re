extern int DAT_0600c9e4;

extern int DAT_0600c9e6;

extern int DAT_0600cac0;

void FUN_0600c994()
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  char *puVar4;

  short sVar5;

  int iVar6;

  unsigned int uVar7;

  unsigned short uVar8;

  unsigned int uVar9;

  int *piVar10;

  int iVar11;

  unsigned short uVar12;

  short *psVar13;

  short local_30 [8];

  short local_20 [2];

  puVar4 = 0x0607EB88;

  puVar3 = 0x0602744C;

  uVar2 = DAT_0600c9e6;

  iVar11 = *(int *)0x0607E944;

  iVar6 = *(int *)(iVar11 + DAT_0600c9e4) + 1;

  sVar1 = *(short *)((iVar6 * 8 + 3) * 0x10 + *(int *)0x0607EB88 + 10);

  iVar6 = iVar6 * 0x80;

  for (psVar13 = local_30; psVar13 < local_20; psVar13 = psVar13 + 2) {

    piVar10 = (int *)(*(int *)puVar4 + iVar6);

    sVar5 = (*(void(*)())puVar3)(*piVar10 - *(int *)(iVar11 + 0x10),

                              piVar10[1] - *(int *)(iVar11 + 0x18));

    *psVar13 = -sVar5;

    piVar10 = (int *)(*(int *)puVar4 + iVar6 + 0x10);

    sVar5 = (*(void(*)())puVar3)(*piVar10 - *(int *)(iVar11 + 0x10),

                              piVar10[1] - *(int *)(iVar11 + 0x18));

    psVar13[1] = -sVar5;

    iVar6 = iVar6 + 0x20;

  }

  sVar1 = sVar1 * -4;

  uVar7 = (unsigned int)(short)(local_30[0] + sVar1);

  if ((int)uVar7 < 0) {

    uVar7 = -uVar7;

  }

  uVar7 = uVar7 & 0xffff;

  uVar12 = 0;

  psVar13 = local_30;

  uVar8 = uVar2;

  while (psVar13 = psVar13 + 1, psVar13 < local_20) {

    uVar9 = (unsigned int)(short)(*psVar13 + sVar1);

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar9 < (int)uVar7) {

      uVar7 = uVar9 & 0xffff;

      uVar12 = uVar8;

    }

    uVar8 = uVar8 + uVar2;

  }

  *(unsigned int *)(iVar11 + DAT_0600cac0) = (unsigned int)uVar12;

  return;

}
