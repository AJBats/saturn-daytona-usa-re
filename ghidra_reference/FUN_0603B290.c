/* FUN_0603B290  0x0603B290 */


void FUN_0603b290(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int in_r0;
  int iVar1;
  int iVar2;
  
  if (*(char *)((int)param_1 + in_r0) == '\0') {
    FUN_0603b9a4(param_1);
    *(undefined1 *)((int)param_1 + 0x11) = 1;
    *(undefined1 *)((int)param_1 + 0x12) = 1;
    iVar2 = *(int *)(*param_1 + 0x10);
    iVar1 = FUN_0603b058(param_1);
    iVar2 = iVar2 - iVar1;
    if (param_2 < iVar2) {
      iVar2 = param_2;
    }
    FUN_0603be7c(*param_1,iVar2);
    (*(code *)PTR_FUN_0603b310)(param_1[2],iVar2);
    (*(code *)PTR_FUN_0603b314)(param_1[1],param_3,param_4,1);
    (*(code *)PTR_FUN_0603b318)(param_1[2]);
    FUN_0603b93c(0);
    return;
  }
  FUN_0603b93c(0xfffffff0);
  return;
}

