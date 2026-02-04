int FUN_06028400(param_1, param_2, param_3, param_4)
    int param_1;
    short *param_2;
    int param_3;
    int param_4;
{

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  short *puVar5;

  puVar5 = (short *)(param_3 + **(int **)(0x06028614 + param_1));

  iVar4 = (int)*param_2;

  iVar3 = (int)param_2[1];

  param_2 = param_2 + 2;

  iVar2 = iVar4;

  do {

    do {

      sVar1 = *param_2;

      param_2 = param_2 + 1;

      *puVar5 = (short)(sVar1 + param_4);

      iVar2 = iVar2 + -1;

      puVar5 = puVar5 + 1;

    } while (iVar2 != 0);

    iVar3 = iVar3 + -1;

    puVar5 = (short *)((int)puVar5 - (iVar4 * 2 + -0x80));

    iVar2 = iVar4;

  } while (iVar3 != 0);

  return sVar1 + param_4;

}
