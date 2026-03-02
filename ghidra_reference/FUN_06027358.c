void FUN_06027358(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    int *param_3;
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;



  puVar1 = 0x002F2F20;

  iVar3 = 0x4000;

  uVar2 = 0x3FFC;

  *param_2 = *(int *)(0x002F2F20 + (param_1 + 8U >> 2 & uVar2));

  *param_3 = *(int *)(puVar1 + (iVar3 + param_1 + 8U >> 2 & uVar2));

  return;

}
