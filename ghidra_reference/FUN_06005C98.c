extern int DAT_06005d3e;

extern int DAT_06005dcc;

extern int DAT_06005dce;

extern int PTR_DAT_06005d40;

extern int PTR_DAT_06005d40;

extern int FUN_06005dd4();

int FUN_06005c98()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  char *puVar5;

  int iVar6;

  unsigned int uVar7;

  int uVar8;

  int iVar9;

  char *puVar10;

  char *puVar11;

  unsigned int local_28;

  puVar11 = 0x000927BF;

  puVar2 = 0x060284AE;

  puVar1 = 0x06028430;

  iVar6 = *(int *)0x0607E944;

  uVar7 = *(int *)0x06063F28 - 1;

  if (*(unsigned int *)(iVar6 + DAT_06005d3e) < uVar7) {

    uVar7 = *(unsigned int *)(iVar6 + DAT_06005d3e);

  }

  if (*(int *)0x0607EAC0 == 0x28) {

    iVar3 = 0x240;

    puVar5 = *(char **)(iVar6 + iVar3);

    iVar6 = uVar7 - 7;

    if (iVar6 < 0) {

      iVar6 = 0;

    }

    iVar9 = 0;

    for (; iVar6 <= (int)uVar7; iVar6 = iVar6 + 1) {

      puVar10 = *(char **)(0x0607EBF8 + (iVar6 << 2));

      if ((int)puVar11 < (int)*(char **)(0x0607EBF8 + (iVar6 << 2))) {

        puVar10 = puVar11;

      }

      uVar4 = FUN_06005dd4(puVar10);

      if (puVar10 == puVar5) {

        uVar8 = 0x54;

      }

      else {

        uVar8 = 0x48;

      }

      iVar3 = (iVar9 + 5) << 6;

      (*(int(*)())puVar2)(8,(iVar3 + 3) << 1,uVar8,uVar4);

      iVar3 = (*(int(*)())puVar1)(8,(iVar3 + 1) << 1,0x3c,iVar6 + 1);

      iVar9 = iVar9 + 1;

    }

  }

  else {

    iVar3 = (int)DAT_06005dcc;

    if (*(int *)(iVar6 + iVar3) != *(int *)0x06063F28) {

      local_28 = uVar7;

      if (6 < (int)uVar7) {

        local_28 = 7;

      }

      puVar11 = (char *)(*(int *)0x0607EBD0 * 5 - *(int *)(iVar6 + DAT_06005dce));

      if ((int)0x000927BF < (int)puVar11) {

        puVar11 = 0x000927BF;

      }

      uVar4 = FUN_06005dd4(puVar11);

      iVar6 = (local_28 + 5) << 6;

      (*(int(*)())puVar2)(8,(iVar6 + 3) << 1,0x48,uVar4);

      iVar3 = (*(int(*)())puVar1)(8,(iVar6 + 1) << 1,0x3c,uVar7 + 1);

    }

  }

  return iVar3;

}
