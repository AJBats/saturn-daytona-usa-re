extern int FUN_0603b28e();
extern int FUN_0603b3fa();
extern int FUN_0603b424();
extern int FUN_0603b93c();

int FUN_0603b21c(param_1)
    int *param_1;
{

  int iVar1;

  int uVar2;

  int local_18;

  char auStack_14 [4];

  int uStack_10;

  uStack_10 = 0x7FFFFFFF;

  uVar2 = *(int *)(*param_1 + 0x28);

  *(int *)(*param_1 + 0x28) = 0x7FFFFFFF;

  iVar1 = FUN_0603b28e(param_1);

  if (iVar1 == 0) {

    while (iVar1 = FUN_0603b424(param_1), -1 < iVar1) {

      if (iVar1 == 0) {

        FUN_0603b3fa(param_1,auStack_14,&local_18);

        FUN_0603b93c(0);

        *(int *)(*param_1 + 0x28) = uVar2;

        return local_18;

      }

      (*(int(*)())0x060423CC)();

    }

    *(int *)(*param_1 + 0x28) = uVar2;

    uVar2 = FUN_0603b93c();

  }

  else {

    *(int *)(*param_1 + 0x28) = uVar2;

    uVar2 = FUN_0603b93c();

  }

  return uVar2;

}
