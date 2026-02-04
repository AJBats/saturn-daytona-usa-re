extern int FUN_0603316c();
extern int FUN_06033188();
extern int FUN_0603320c();

int FUN_060330a0()
{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  iVar4 = FUN_0603316c();

  iVar3 = 0x00000268;

  iVar2 = 0x00000018;

  iVar1 = 0x00000010;

  iVar8 = *(int *)(0x00000010 + iVar4);

  iVar9 = *(int *)(0x00000018 + iVar4);

  iVar4 = iVar4 + 0x00000268;

  iVar5 = **(int **)0x0603386C + -1;

  do {

    iVar6 = iVar8 - *(int *)(iVar1 + iVar4);

    iVar7 = iVar9 - *(int *)(iVar2 + iVar4);

    iVar6 = iVar6 + (iVar6 >> 1);

    if (iVar6 < 0) {

      iVar6 = -iVar6;

    }

    if (iVar6 <= (int)0x00220000) {

      iVar6 = iVar7;

      if (iVar7 < 0) {

        iVar6 = -iVar7;

      }

      if (iVar6 <= (int)0x001A0000) {

        FUN_0603316c(iVar7);

        FUN_06033188();

        FUN_0603320c(0x0000FFFF);

      }

    }

    iVar4 = iVar4 + iVar3;

    iVar5 = iVar5 + -1;

  } while (0 < iVar5);

  return iVar4;

}
