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

  uVar3 = (*0x0603D9EC)(param_1);

  uVar4 = (*0x0603DA88)(param_1);

  puVar1 = 0x0603C08C;

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

  iVar2 = (*0x0603C08C)(iVar14,uVar4);

  iVar5 = (*puVar1)(iVar10,uVar3);

  *piVar16 = iVar5 + iVar2;

  iVar2 = (*puVar1)(iVar14,uVar3);

  iVar5 = (*puVar1)(iVar10,uVar4);

  *piVar13 = iVar5 - iVar2;

  iVar2 = (*puVar1)(iVar6,uVar4);

  iVar5 = (*puVar1)(iVar9,uVar3);

  *piVar11 = iVar5 + iVar2;

  iVar2 = (*puVar1)(iVar6,uVar3);

  iVar5 = (*puVar1)(iVar9,uVar4);

  *piVar7 = iVar5 - iVar2;

  iVar2 = (*puVar1)(iVar12,uVar4);

  iVar5 = (*puVar1)(iVar8,uVar3);

  piVar16[6] = iVar5 + iVar2;

  iVar2 = (*puVar1)(iVar12,uVar3);

  iVar5 = (*puVar1)(iVar8,uVar4);

  piVar16[7] = iVar5 - iVar2;

  puVar1 = 0x060A3E68;

  *(int *)(0x060A3E68 + (unsigned int)uVar15 * 0x80 + 0x1c) = *piVar16;

  *(int *)(puVar1 + (unsigned int)uVar15 * 0x80 + 0x20) = *piVar13;

  *(int *)(puVar1 + (unsigned int)uVar15 * 0x80 + 0x28) = *piVar11;

  *(int *)(puVar1 + (unsigned int)uVar15 * 0x80 + 0x2c) = *piVar7;

  return iVar5 - iVar2;

}
