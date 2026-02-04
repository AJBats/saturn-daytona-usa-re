extern int FUN_0603b058();
extern int FUN_0603b93c();
extern int FUN_0603b9a4();
extern int FUN_0603be7c();

void FUN_0603b28e(param_1, param_2, param_3, param_4)
    int *param_1;
    int param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  int iVar2;

  if (*(char *)((int)param_1 + 0x12) == '\0') {

    FUN_0603b9a4(param_1);

    *(char *)((int)param_1 + 0x11) = 1;

    *(char *)((int)param_1 + 0x12) = 1;

    iVar2 = *(int *)(*param_1 + 0x10);

    iVar1 = FUN_0603b058(param_1);

    iVar2 = iVar2 - iVar1;

    if (param_2 < iVar2) {

      iVar2 = param_2;

    }

    FUN_0603be7c(*param_1,iVar2);

    (*(void(*)())0x0603F9DA)(param_1[2],iVar2);

    (*(void(*)())0x0603EF54)(param_1[1],param_3,param_4,1);

    (*(void(*)())0x0603FA00)(param_1[2]);

    FUN_0603b93c(0);

    return;

  }

  FUN_0603b93c(0xfffffff0);

  return;

}
