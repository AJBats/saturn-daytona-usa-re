extern int DAT_060411f6;

extern int PTR_DAT_060411f8;

extern int PTR_DAT_060411f8;

extern int FUN_06041b3c();

int FUN_060411A0(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = 0x060A5400;

  if (*(int *)(*(int *)0x060A5400 + (int)DAT_060411f6) != 0) {

    return 0xffffffff;

  }

  iVar2 = (int)DAT_060411f6;

  *(int *)(*(int *)0x060A5400 + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

  *(int *)(*(int *)puVar1 + iVar2 + 0xc) = param_3;

  *(int *)(*(int *)puVar1 + iVar2 + 0x10) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x14) = param_4;

  *(int *)(*(int *)puVar1 + (int)PTR_DAT_060411f8) = param_5;

  FUN_06041b3c(auStack_8);

  return 0;

}
