/* FUN_0603AFDC  0x0603AFDC */


undefined4 FUN_0603afdc(undefined4 param_1,undefined4 param_2,int param_3)

{
  int in_r0;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_r13;
  int unaff_r14;
  
  iVar3 = *(int *)PTR_DAT_0603b038 + 4 + (uint)*(byte *)((int)unaff_r13 + in_r0) * 0x10;
  if (param_3 == 1) {
    iVar1 = (**(code **)(iVar3 + 0xc))(*unaff_r13);
    unaff_r14 = unaff_r14 + iVar1;
  }
  else if (param_3 == 2) {
    unaff_r14 = unaff_r14 + *(int *)(*unaff_r13 + 0x10);
  }
  else if (param_3 != 0) {
    uVar2 = FUN_0603b93c(0xfffffff3);
    return uVar2;
  }
  if (unaff_r14 < 0) {
    uVar2 = FUN_0603b93c(0xfffffff1);
    return uVar2;
  }
  uVar2 = (**(code **)(iVar3 + 8))(*unaff_r13,unaff_r14);
  FUN_0603b93c(0);
  return uVar2;
}

