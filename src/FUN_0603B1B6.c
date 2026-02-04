extern int DAT_0603b270;

extern int FUN_0603aee8();
extern int FUN_0603af94();
extern int FUN_0603afd0();
extern int FUN_0603b21c();
extern int FUN_0603b93c();

int FUN_0603b1b6(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int *piVar1;

  int iVar2;

  piVar1 = (int *)FUN_0603aee8();

  if (piVar1 == (int *)0x0) {

    iVar2 = FUN_0603b93c(0xfffffff7);

    return iVar2;

  }

  FUN_0603afd0(piVar1,param_2,0);

  param_2 = *(int *)(*piVar1 + 0x10) - param_2;

  if (param_4 == -1) {

    param_4 = param_2 * DAT_0603b270;

  }

  iVar2 = FUN_0603b21c(piVar1,param_2,param_3,param_4);

  FUN_0603af94(piVar1);

  if (-1 < iVar2) {

    FUN_0603b93c(0);

  }

  return iVar2;

}
