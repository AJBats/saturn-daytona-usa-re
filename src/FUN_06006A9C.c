extern int DAT_06006c1e;

extern int DAT_06006cca;

extern int PTR_DAT_06006c20;

extern int PTR_DAT_06006c20;

int FUN_06006a9c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  int uVar9;

  int iVar10;

  unsigned int uVar11;

  int iVar12;

  unsigned int uVar13;

  int iVar14;

  short sVar15;

  int iVar16;

  short sVar17;

  int iStack_40;

  int iStack_28;

  int iStack_24;

  puVar3 = 0x0607EAD8;

  puVar2 = 0x06089E44;

  puVar1 = 0x060620D4;

  uVar9 = *(int *)(0x06062248 + *(int *)0x0607EAD8 * 8);

  uVar6 = *(int *)(0x06062248 + (*(int *)0x0607EAD8 * 2 + 1) * 4);

  iVar4 = *(int *)(0x06062260 + *(int *)0x0607EAD8 * 0x10);

  iVar12 = *(int *)0x0607EAD8 * 4;

  iVar10 = *(int *)(0x06062260 + (iVar12 + 1) * 4);

  iVar7 = *(int *)(0x06062260 + (iVar12 + 2) * 4);

  iVar12 = (iVar12 + 3) * 4;

  iVar5 = *(int *)(0x06062260 + iVar12);

  uVar11 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar13 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar14 = -2;

  iStack_24 = -2;

  iStack_40 = 2;

  iStack_28 = 2;

  if (uVar13 < 0x3e) {

    if (uVar13 < 2) {

      iVar14 = -uVar13;

    }

  }

  else {

    iStack_40 = 0x3f - uVar13;

  }

  if (uVar11 < 0x3e) {

    if (uVar11 < 2) {

      iStack_24 = -uVar11;

    }

  }

  else {

    iStack_28 = 0x3f - uVar11;

  }

  for (iVar14 = iVar14 << 6; iVar16 = iStack_24, iVar14 < iStack_40 << 6; iVar14 = iVar14 + 0x40) {

    for (; iVar16 < iStack_28; iVar16 = iVar16 + 1) {

      iVar12 = iVar14;

      if ((((iVar14 == -0x80) || (iVar14 == DAT_06006c1e)) || (iVar12 = iVar16, iVar16 == -2)) ||

         (iVar16 == 2)) {

        iVar8 = iVar14 + iVar16 + uVar13 * 0x40 + uVar11;

        sVar17 = *(short *)(iVar4 + iVar8 * 2);

        sVar15 = *(short *)(iVar8 * 2 + iVar7);

        if (0 < sVar17) {

          iVar12 = *(int *)(0x06062230 + *(int *)puVar3 * 8) + *(int *)(iVar10 + iVar8 * 4);

          if ((unsigned int)(int)PTR_DAT_06006c20 <= (unsigned int)((int)sVar17 + *(int *)puVar1)) {

            sVar17 = PTR_DAT_06006c20 - (short)*(int *)puVar1;

          }

          if (*(int *)puVar3 == 2) {

            iVar12 = (*0x0602BDCC)

                               (iVar12,uVar9,*(short *)(puVar2 + 0x52),(int)sVar17);

          }

          else {

            iVar12 = (*0x0602A214)

                               (iVar12,uVar9,*(short *)(puVar2 + 0x52),(int)sVar17);

          }

        }

        if (0 < sVar15) {

          iVar12 = *(int *)(0x06062230 + (*(int *)puVar3 * 2 + 1) * 4) +

                   *(int *)(iVar5 + iVar8 * 4);

          if ((unsigned int)(int)DAT_06006cca <= (unsigned int)((int)sVar15 + *(int *)puVar1)) {

            sVar15 = DAT_06006cca - (short)*(int *)puVar1;

          }

          if (*(int *)puVar3 == 2) {

            iVar12 = (*0x0602B9E0)

                               (iVar12,uVar6,*(short *)(puVar2 + 0x52),(int)sVar15);

          }

          else {

            iVar12 = (*0x0602ABB8)

                               (iVar12,uVar6,*(short *)(puVar2 + 0x52),(int)sVar15);

          }

        }

      }

    }

  }

  return iVar12;

}
