extern int DAT_0603b7a4;

extern int DAT_0603b7a6;

extern int DAT_0603b7a8;

extern int DAT_0603b7aa;

extern int FUN_0603b734();

void FUN_0603b74c(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  puVar1 = 0x060A4D14;

  **(int **)0x060A4D14 = param_1;

  FUN_0603b734();

  iVar2 = (int)DAT_0603b7a4;

  *(int *)(*(int *)puVar1 + iVar2) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x14) = 0;

  iVar3 = *(int *)puVar1;

  *(int *)(iVar3 + iVar2 + 0x1c) = 0;

  *(int *)(iVar3 + iVar2 + 0x18) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x24) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x30) = 0;

  iVar3 = *(int *)puVar1 + (int)DAT_0603b7a6;

  for (iVar2 = 0; iVar2 < **(int **)puVar1; iVar2 = iVar2 + 1) {

    *(int *)(iVar3 + DAT_0603b7a8) = 0;

    iVar3 = iVar3 + DAT_0603b7aa;

  }

  return;

}
