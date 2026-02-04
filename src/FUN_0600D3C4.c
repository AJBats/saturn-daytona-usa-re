extern int DAT_0600d4a6;

extern int DAT_0600d534;

extern int DAT_0600d536;

extern int PTR_DAT_0600d408;

extern int PTR_DAT_0600d408;

void FUN_0600d3c4()
{

  int *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned int uVar5;

  int uVar6;

  unsigned int uVar7;

  int *piVar8;

  int *piVar9;

  unsigned int uVar10;

  int *puVar11;

  int *puVar12;

  puVar12 = (int *)0x0607E9EC;

  if (*(unsigned int *)(*(int *)0x0607E9EC + (int)PTR_DAT_0600d408) < *(unsigned int *)0x060786B4)

  {

    for (uVar7 = 1;

        (uVar10 = uVar7, puVar1 = (int *)0x0607EA8C,

        puVar11 = (int *)0x0607E9EC,

        *(unsigned int *)(*(int *)(0x0607E9EC + uVar7 * 4) + (int)DAT_0600d4a6) <

        *(unsigned int *)0x060786B4 && (uVar7 < 3)); uVar7 = uVar7 + 1) {

    }

    for (; uVar10 != 0; uVar10 = uVar10 - 1) {

      *puVar1 = *puVar11;

      puVar1 = puVar1 + 1;

      puVar11 = puVar11 + 1;

    }

    for (uVar10 = *(int *)0x0607EA98 - uVar7; puVar1 = (int *)0x0607EA8C,

        1 < uVar10; uVar10 = uVar10 - 1) {

      uVar6 = *puVar11;

      puVar11 = puVar11 + 1;

      *puVar12 = uVar6;

      puVar12 = puVar12 + 1;

    }

    for (; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar12 = *puVar1;

      puVar12 = puVar12 + 1;

      puVar1 = puVar1 + 1;

    }

  }

  else {

    uVar7 = *(unsigned int *)(*(int *)0x0607E9EC + (int)PTR_DAT_0600d408);

    piVar9 = (int *)0x0607E9EC;

    for (uVar10 = *(unsigned int *)0x0607EA98; 1 < uVar10; uVar10 = uVar10 - 1) {

      uVar5 = *(unsigned int *)(piVar9[1] + (int)PTR_DAT_0600d408);

      if (uVar7 < uVar5) {

        iVar4 = *piVar9;

        *piVar9 = piVar9[1];

        piVar9[1] = iVar4;

        uVar5 = uVar7;

      }

      piVar9 = piVar9 + 1;

      uVar7 = uVar5;

    }

  }

  puVar3 = 0x0607EA98;

  puVar2 = 0x0607E9EC;

  piVar8 = (int *)(0x0607E9EC + 4);

  piVar9 = piVar8;

  for (uVar7 = 1; uVar7 < *(int *)puVar3 - 1U; uVar7 = uVar7 + 1) {

    iVar4 = (int)DAT_0600d534;

    *(int *)(*piVar9 + iVar4) = piVar9[-1];

    *(int *)(*piVar9 + iVar4 + 4) = piVar9[1];

    piVar9 = piVar9 + 1;

  }

  *(int *)(*(int *)puVar2 + (int)DAT_0600d534) = *piVar9;

  iVar4 = (int)DAT_0600d536;

  *(int *)(*(int *)puVar2 + iVar4) = *piVar8;

  *(int *)(*piVar9 + iVar4 + -4) = piVar9[-1];

  *(int *)(*piVar9 + iVar4) = *(int *)puVar2;

  *(int *)0x060786B4 = *(int *)(*piVar9 + iVar4 + -0x50);

  return;

}
