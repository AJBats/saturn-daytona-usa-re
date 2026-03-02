void FUN_060284ae(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    char *param_4;
{

  char cVar1;

  char cVar2;

  char cVar3;

  short sVar4;

  char *pcVar5;

  int iVar6;

  unsigned int uVar7;

  int iVar8;

  short *psVar9;

  int *piVar10;

  short *psVar11;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  psVar9 = (short *)(param_2 + **(int **)(0x06028614 + param_1));

  piVar10 = (int *)(0x06063690 + param_3);

  iVar6 = *piVar10;

  sVar4 = *(short *)(piVar10 + 1);

  uVar7 = (unsigned int)*(char *)((int)piVar10 + 6);

  iVar8 = (int)*(char *)((int)piVar10 + 7);

  cVar1 = *(char *)(piVar10 + 2);

  cVar2 = *(char *)((int)piVar10 + 9);

  uVar13 = 0xffffffff;

  pcVar5 = param_4;

  do {

    cVar3 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    uVar13 = uVar13 + 1;

  } while (cVar3 != '\0');

  pcVar5 = param_4;

  uVar12 = uVar13;

  do {

    do {

      psVar11 = (short *)(iVar6 + ((int)cVar1 & 0xffffU) * ((int)*pcVar5 - (int)cVar2 & 0xffffU));

      uVar14 = uVar7;

      do {

        *psVar9 = *psVar11 + sVar4;

        psVar11 = psVar11 + 1;

        uVar14 = uVar14 - 1;

        psVar9 = psVar9 + 1;

      } while (uVar14 != 0);

      uVar12 = uVar12 - 1;

      pcVar5 = pcVar5 + 1;

    } while (uVar12 != 0);

    iVar6 = iVar6 + (uVar7 << 1);

    iVar8 = iVar8 + -1;

    psVar9 = psVar9 + -((uVar7 & 0xffff) * (uVar13 & 0xffff) + -0x40);

    pcVar5 = param_4;

    uVar12 = uVar13;

  } while (iVar8 != 0);

  return;

}
