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

  puVar1 = 0x060A4C70;

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

  iVar9 = iVar3 * 4;

  if ((*(int *)(0x060A4C4C + iVar9) == 0) ||

     ((*(int *)(0x060A4C60 + iVar9) == 0 && (*(int *)(0x060A4C78 + iVar9) == 0)))) {

    param_1 = *(int *)(0x060A4C70 + iVar3 * 4) + param_1;

    *(int *)(0x060A4C70 + iVar3 * 4) = param_1;

    if ((int)0x01680000 <= param_1) {

      *(int *)(puVar1 + iVar3 * 4) = *(int *)(puVar1 + iVar3 * 4) - (int)0x01680000;

    }

    if (*(int *)(puVar1 + iVar3 * 4) < 0) {

      *(char **)(puVar1 + iVar3 * 4) = 0x01680000 + *(int *)(puVar1 + iVar3 * 4);

    }

    puVar2 = 0x0603C08C;

    iVar9 = iVar3 * 4;

    puVar11 = (int *)(puVar1 + iVar9);

    piVar10 = (int *)(0x060A3E68 + iVar3 * 0x80);

    piVar7 = (int *)(0x060A53A8 + iVar9);

    iVar6 = *piVar7;

    uVar4 = (*0x0603DA88)(*puVar11);

    iVar3 = (*puVar2)(uVar4,iVar6);

    piVar8 = (int *)(0x060A53B0 + iVar9);

    iVar5 = *piVar8;

    iVar9 = (*0x0603D9EC)(*puVar11);

    iVar9 = (*puVar2)(-iVar9,iVar5);

    *piVar10 = (iVar6 - iVar3) - iVar9;

    iVar5 = *piVar8;

    iVar3 = *piVar7;

    uVar4 = (*0x0603D9EC)(*puVar11);

    iVar3 = (*puVar2)(uVar4,iVar3);

    iVar9 = *piVar8;

    uVar4 = (*0x0603DA88)(*puVar11);

    iVar9 = (*puVar2)(uVar4,iVar9);

    piVar10[1] = (iVar5 - iVar3) - iVar9;

    piVar10[2] = 0;

    iVar3 = (*0x0603D9EC)(*puVar11);

    piVar10[3] = -iVar3;

    iVar3 = (*0x0603DA88)(*puVar11);

    piVar10[4] = iVar3;

    iVar3 = (*0x0603DA88)(*puVar11);

    piVar10[5] = iVar3;

    iVar3 = (*0x0603D9EC)(*puVar11);

    piVar10[6] = iVar3;

  }

  else {

    iVar3 = iVar3 * 4;

    *(int *)(0x060A4C70 + iVar3) = 0;

  }

  return iVar3;

}
