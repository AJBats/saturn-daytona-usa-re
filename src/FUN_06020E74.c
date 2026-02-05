extern int DAT_06020f2e;

extern int DAT_06020f30;

extern int DAT_06020fc6;

extern int DAT_06020fc8;

extern int DAT_06020fca;

extern int DAT_06021098;

extern int DAT_0602109a;

extern int DAT_0602109c;

extern int DAT_0602109e;

int FUN_06020e74()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned char bVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  puVar4 = 0x06089595;

  puVar3 = 0x06087C84;

  puVar2 = 0x06078663;

  puVar1 = 0x06089594;

  if (*(int *)0x06089595 != '\0') {

    *(int *)0x06089594 = 10;

    *puVar4 = 0;

  }

  if (*puVar1 != '\0') {

    *puVar1 = *puVar1 + -1;

  }

  if ((*(int *)(*(int *)0x0607E944 + (int)DAT_06020f2e) != *(int *)0x06089598) &&

     (*(int *)0x06083255 == '\0')) {

    iVar9 = 0x900;

    uVar5 = *(unsigned int *)((int)DAT_06020f2e + *(int *)0x0607E944) & 0xcc;

    if (uVar5 == 0) {

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + 0x48),iVar9,

                 *(int *)(0x06063750 + 0x4c));

    }

    else if (uVar5 == 0x44) {

      if (*puVar2 == '\0') {

        iVar7 = 10;

      }

      else {

        iVar7 = 0xb;

      }

      if (*puVar2 == '\0') {

        iVar8 = 10;

      }

      else {

        iVar8 = 0xb;

      }

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + (iVar8 << 3)),iVar9,

                 *(int *)(0x06063750 + (iVar7 << 3) + 4));

    }

    else if (uVar5 == 0x88) {

      if (*puVar2 == '\0') {

        iVar7 = 0xb;

      }

      else {

        iVar7 = 10;

      }

      if (*puVar2 == '\0') {

        iVar8 = 0xb;

      }

      else {

        iVar8 = 10;

      }

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + (iVar8 << 3)),iVar9,

                 *(int *)(0x06063750 + (iVar7 << 3) + 4));

    }

    else if (uVar5 == (int)DAT_06020fc8) {

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + 0x60),iVar9,

                 *(int *)(0x06063750 + 100));

    }

  }

  *(int *)0x06089598 = *(int *)(*(int *)0x0607E944 + (int)DAT_06020fca);

  if (*(int *)0x06063E20 != 1) {

    return *(int *)0x06063E20;

  }

  iVar10 = 0;

  iVar7 = 0;

  iVar9 = *(int *)(*(int *)0x0607E944 + 0x60) >> 0xe;

  iVar8 = *(int *)(0x0604D3E0 + (unsigned int)(unsigned char)(*puVar1 << 2));

  if (*puVar2 != '\0') {

    iVar9 = -iVar9;

  }

  if ((iVar9 < DAT_06021098) && (DAT_0602109a < iVar9)) {

    iVar9 = 0;

  }

  *(int *)(puVar3 + DAT_0602109c) = 0;

  bVar6 = 0;

  do {

    iVar10 = iVar10 + iVar9;

    iVar7 = iVar7 - iVar9;

    uVar5 = (unsigned int)bVar6;

    *(int *)(puVar3 + (((0x15 - (unsigned int)bVar6) << 2) + (int)DAT_0602109e)) = iVar10 + iVar8;

    bVar6 = bVar6 + 1;

    *(int *)(puVar3 + (uVar5 << 2) + (int)DAT_0602109e + 0x58) = iVar7 + iVar8;

  } while (bVar6 < 0x16);

  (*(int(*)())0x0603850C)(8);

  (*(int(*)())0x06038120)(0x06087C84);

  iVar9 = (*(int(*)())0x06038520)();

  return iVar9;

}
