/* FUN_0602E578  0x0602E578 */


int FUN_0602e578(undefined4 param_1,short param_2)

{
  int iVar1;
  int iVar2;
  code *unaff_r13;
  
  iVar1 = (*unaff_r13)();
  iVar2 = (int)(short)((param_2 - (short)*(undefined4 *)(PTR_DAT_0602e5a8._0_2_ + iVar1)) +
                      (short)PTR_DAT_0602e5c8);
  if ((DAT_0602e5cc <= iVar2) && (iVar2 <= (int)PTR_DAT_0602e5d0)) {
    return iVar1;
  }
  *(int *)(DAT_0602e5e0 + iVar1) = *(int *)(DAT_0602e5e0 + iVar1) + 1;
  return iVar1;
}

