extern int DAT_06028348;

char * FUN_06028306(param_1)
    int param_1;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  int iVar4;

  int *puVar5;

  char uVar6;

  uVar2 = 0x0A0A0A0A;

  puVar1 = 0x060620C4;

  *(int *)0x060620C4 = 0x0A0A0A0A;

  *(int *)(puVar1 + 4) = uVar2;

  *(int *)(puVar1 + 8) = uVar2;

  puVar1[0xb] = 0;

  uVar6 = 10;

  if (param_1 < 0) {

    param_1 = -param_1;

    uVar6 = 0x2d;

  }

  puVar5 = (int *)(int)DAT_06028348;

  *puVar5 = 10;

  iVar3 = 10;

  do {

    iVar4 = iVar3;

    if (param_1 == 0) break;

    puVar5[1] = param_1;

    iVar4 = iVar3 + -1;

    puVar1[iVar3 + 1] = (char)puVar5[6];

    param_1 = puVar5[7];

    iVar3 = iVar4;

  } while (iVar4 != 0);

  puVar1[iVar4] = uVar6;

  return puVar1;

}
