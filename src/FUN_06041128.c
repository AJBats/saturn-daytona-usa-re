extern int DAT_06041174;

extern int PTR_DAT_06041176;

extern int PTR_DAT_06041176;

extern void FUN_06041aa0();

int FUN_06041128(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = 0x060A5400;

  if ((param_1 != DAT_06041174) && (*(char *)(param_1 + *(int *)0x060A5400 + 0x18) != '\x01'))

  {

    return 0xfffffff9;

  }

  if (*(int *)(*(int *)0x060A5400 + 0x38) != param_2) {

    return 0xfffffff7;

  }

  iVar2 = (int)PTR_DAT_06041176;

  *(int *)(*(int *)0x060A5400 + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  FUN_06041aa0(auStack_8);

  return 0;

}
