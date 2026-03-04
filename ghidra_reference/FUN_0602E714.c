/* FUN_0602E714  0x0602E714 */


int FUN_0602e714(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_r9;
  code *unaff_r13;
  
  iVar1 = (*unaff_r13)();
  iVar2 = (*(code *)PTR_FUN_0602e75c)(param_5 - param_3,param_5 - param_3);
  uVar3 = iVar1 + iVar2;
  if ((int)uVar3 < 0) {
    iVar1 = (*(code *)PTR_FUN_0602e760)(uVar3 >> 2);
    iVar1 = iVar1 << 1;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_0602e784)(uVar3);
  }
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < (int)PTR_DAT_0602e788) {
    iVar1 = FUN_0602e7c0();
    return iVar1;
  }
  *(undefined4 *)PTR_DAT_0602e7b4 = *(undefined4 *)(unaff_r9 + DAT_0602e7b0);
  iVar1 = DAT_0602e7b8;
  *(undefined4 *)PTR_DAT_0602e7bc = *(undefined4 *)(unaff_r9 + DAT_0602e7b8);
  return iVar1;
}

