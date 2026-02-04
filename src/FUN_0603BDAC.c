extern int PTR_DAT_0603be10;

extern int PTR_DAT_0603be10;

int FUN_0603bdac(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char auStack_14 [8];

  iVar2 = (*(int(*)())0x0603FACE)(*(int *)(param_1 + 8),auStack_14);

  puVar1 = 0x060A4D14;

  if ((iVar2 == 5) ||

     (iVar3 = (*(int(*)())0x0603EFD4)(*(int *)(param_1 + 4)), iVar3 == 0)) {

    (*(int(*)())0x0603FA1A)(*(int *)(param_1 + 8),0xffffffff);

    if (*(int *)(*(int *)puVar1 + (int)PTR_DAT_0603be10) == param_1) {

      *(int *)(*(int *)puVar1 + (int)PTR_DAT_0603be10) = 0;

    }

    iVar2 = 5;

  }

  else if (iVar2 != 0) {

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_0603be10) = param_1;

    *(char *)(param_1 + 0x12) = 1;

  }

  return iVar2;

}
