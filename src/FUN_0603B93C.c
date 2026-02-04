extern int DAT_0603b986;

int FUN_0603b93c(param_1)
    int param_1;
{

  int *piVar1;

  piVar1 = (int *)(*(int *)0x060A4D14 + (int)DAT_0603b986);

  piVar1[2] = param_1;

  if ((param_1 != 0) && (*piVar1 != 0)) {

    (**piVar1)(piVar1[1],param_1);

  }

  return param_1;

}
