/* FUN_0604053A  0x0604053A */


/* WARNING: Type propagation algorithm not settling */

void FUN_0604053a(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_18 [4];
  
  puVar1 = PTR_DAT_060405a8;
  iVar4 = *(int *)(param_1 + 0x18);
  if (param_2 != 0) {
    iVar2 = (int)PTR_DAT_060405a4._0_2_;
    iVar3 = *(int *)PTR_DAT_060405a8;
    *(undefined4 *)(iVar3 + iVar2) = 0;
    *(undefined4 *)(iVar3 + iVar2 + -4) = 0;
    local_18[1] = 3;
    (*(code *)PTR_FUN_060405ac)(local_18 + 1,*(undefined4 *)(iVar4 + 0x28));
  }
  iVar2 = (*(code *)PTR_FUN_060405b0)(*(undefined4 *)(iVar4 + 0x28));
  if (iVar2 != 0) {
    (*(code *)PTR_FUN_060405b4)(*(undefined4 *)(iVar4 + 0x28));
    FUN_060405b8(local_18,0);
    if (*(int *)(*(int *)puVar1 + (int)PTR_DAT_060405a4._0_2_) <= local_18[0]) {
      iVar4 = *(int *)puVar1;
      *(undefined4 *)(iVar4 + PTR_DAT_060405a4._0_2_ + -4) =
           *(undefined4 *)(iVar4 + PTR_DAT_060405a4._0_2_);
    }
  }
  return;
}

