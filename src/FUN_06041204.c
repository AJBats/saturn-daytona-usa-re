extern int DAT_0604128e;

extern void FUN_06041cc8();

int FUN_06041204(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = 0x060A5400;

  if (*(int *)(*(int *)0x060A5400 + (int)DAT_0604128e) != 0) {

    return 0xffffffff;

  }

  if (*(int *)(*(int *)0x060A5400 + 0x34) == 1) {

    return 0xfffffffb;

  }

  *(int *)(*(int *)0x060A5400 + 0x34) = 1;

  iVar2 = (int)DAT_0604128e;

  *(int *)(*(int *)puVar1 + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

  *(int *)(*(int *)puVar1 + iVar2 + 0xc) = param_3;

  FUN_06041cc8(auStack_8);

  return 0;

}
