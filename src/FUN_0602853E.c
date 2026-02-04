int * FUN_0602853e(param_1)
    int param_1;
{

  int *puVar1;

  int iVar2;

  int uVar3;



  uVar3 = *(int *)(0x06028644 + param_1);

  puVar1 = (int *)**(int **)(0x0602862C + param_1);

  iVar2 = 0x0800;

  do {

    *puVar1 = uVar3;

    iVar2 = iVar2 + -1;

    puVar1 = puVar1 + 1;

  } while (iVar2 != 0);

  return puVar1;

}
