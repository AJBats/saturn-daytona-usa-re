extern void FUN_0603b058();
extern void FUN_0603b93c();
extern void FUN_0603b9a4();
extern void FUN_0603be7c();

void FUN_0603b31c(param_1, param_2)
    int *param_1;
    int param_2;
{

  int iVar1;

  int iVar2;

  if (*(char *)((int)param_1 + 0x12) == '\0') {

    FUN_0603b9a4(param_1);

    *(char *)((int)param_1 + 0x11) = 2;

    *(char *)((int)param_1 + 0x12) = 1;

    iVar2 = *(int *)(*param_1 + 0x10);

    iVar1 = FUN_0603b058(param_1);

    iVar2 = iVar2 - iVar1;

    if (param_2 < iVar2) {

      iVar2 = param_2;

    }

    FUN_0603be7c(*param_1,iVar2);

    (*0x0603F9DA)(param_1[2],0);

    (*0x0603EF54)(param_1[1],0,0,1);

    (*0x0603FA1A)(param_1[2],0xffffffff);

    FUN_0603b93c(0);

    return;

  }

  FUN_0603b93c(0xfffffff0);

  return;

}
