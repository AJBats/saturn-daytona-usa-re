/* FUN_0603B324  0x0603B324 */


void FUN_0603b324(undefined4 param_1,int param_2)

{
  int in_r0;
  int iVar1;
  int iVar2;
  int *unaff_r14;
  
  if (*(char *)((int)unaff_r14 + in_r0) == '\0') {
    FUN_0603b9a4();
    *(undefined1 *)((int)unaff_r14 + 0x11) = 2;
    *(undefined1 *)((int)unaff_r14 + 0x12) = 1;
    iVar2 = *(int *)(*unaff_r14 + 0x10);
    iVar1 = FUN_0603b058();
    iVar2 = iVar2 - iVar1;
    if (param_2 < iVar2) {
      iVar2 = param_2;
    }
    FUN_0603be7c(*unaff_r14,iVar2);
    (*(code *)PTR_FUN_0603b3b0)(unaff_r14[2],0);
    (*(code *)PTR_FUN_0603b3b4)(unaff_r14[1],0,0,1);
    (*(code *)PTR_FUN_0603b3b8)(unaff_r14[2],0xffffffff);
    FUN_0603b93c(0);
    return;
  }
  FUN_0603b93c(0xfffffff0);
  return;
}

