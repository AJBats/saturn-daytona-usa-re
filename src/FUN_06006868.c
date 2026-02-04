unsigned int FUN_06006868()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  int uVar8;

  int iVar9;

  unsigned int uVar10;

  int iVar11;

  unsigned int uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int local_4c;

  int iStack_40;

  int iStack_28;

  int iStack_24;

  puVar2 = 0x0607EAD8;

  *(int *)0x06063F54 = *(int *)(*(int *)0x0607E944 + 0x14);

  puVar3 = 0x06089E96;

  uVar8 = *(int *)(0x06062248 + *(int *)puVar2 * 8);

  uVar5 = *(int *)(0x06062248 + (*(int *)puVar2 * 2 + 1) * 4);

  iVar4 = *(int *)(0x06062260 + *(int *)puVar2 * 0x10);

  iVar11 = *(int *)puVar2 * 4;

  iVar9 = *(int *)(0x06062260 + (iVar11 + 1) * 4);

  iVar6 = *(int *)(0x06062260 + (iVar11 + 2) * 4);

  iVar11 = *(int *)(0x06062260 + (iVar11 + 3) * 4);

  uVar10 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar12 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar7 = uVar12 * 0x40 + uVar10;

  iStack_28 = 0x40;

  iStack_24 = -1;

  iStack_40 = 1;

  local_4c = -0x40;

  if (uVar12 == 0x3f) {

    iStack_28 = 0;

  }

  else if (uVar12 == 0) {

    local_4c = 0;

  }

  if (uVar10 == 0x3f) {

    iStack_40 = 0;

  }

  else if (uVar10 == 0) {

    iStack_24 = 0;

  }

  for (; local_4c <= iStack_28; local_4c = local_4c + 0x40) {

    iVar14 = local_4c + iStack_24 + iVar7;

    for (iVar15 = iStack_24; iVar15 <= iStack_40; iVar15 = iVar15 + 1) {

      sVar1 = *(short *)(iVar14 * 2 + iVar6);

      if (0 < *(short *)(iVar4 + iVar14 * 2)) {

        iVar13 = *(int *)(0x06062230 + *(int *)puVar2 * 8) + *(int *)(iVar9 + iVar14 * 4);

        if (*(int *)puVar2 == 2) {

          uVar10 = (*0x0602B328)(iVar13,uVar8,(int)*(short *)puVar3);

        }

        else {

          uVar10 = (*0x06029BF4)(iVar13,uVar8,(int)*(short *)puVar3);

        }

      }

      if (0 < sVar1) {

        iVar13 = *(int *)(0x06062230 + (*(int *)puVar2 * 2 + 1) * 4) +

                 *(int *)(iVar11 + iVar14 * 4);

        if (*(int *)puVar2 == 2) {

          uVar10 = (*0x0602AF3C)(iVar13,uVar5,(int)*(short *)puVar3,(int)sVar1);

        }

        else {

          uVar10 = (*0x0602A834)(iVar13,uVar5,(int)*(short *)puVar3,(int)sVar1);

        }

      }

      iVar14 = iVar14 + 1;

    }

  }

  if ((*(unsigned int *)0x0607EBC4 & 0x30000000) == 0) {

    iVar4 = *(int *)puVar2;

    if (iVar4 == 0) {

      (*0x06017814)();

    }

    else if (iVar4 == 1) {

      (*0x06017CEC)();

    }

    else if (iVar4 == 2) {

      (*0x06018166)();

    }

    uVar10 = (*0x06022140)();

    return uVar10;

  }

  return uVar10;

}
