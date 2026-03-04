/* FUN_0602E69E  0x0602E69E */


int FUN_0602e69e(void)

{
  int iVar1;
  int iVar2;
  int unaff_r9;
  code *unaff_r13;
  
  iVar1 = (*unaff_r13)();
  iVar2 = iVar1 * 2;
  if (iVar2 < 0) {
    iVar2 = iVar1 * -2;
  }
  if (iVar2 < (int)PTR_DAT_0602e6e4) {
    iVar1 = FUN_0602e7c0();
    return iVar1;
  }
  *(undefined4 *)PTR_DAT_0602e7b4 = *(undefined4 *)(unaff_r9 + DAT_0602e7b0);
  iVar1 = DAT_0602e7b8;
  *(undefined4 *)PTR_DAT_0602e7bc = *(undefined4 *)(unaff_r9 + DAT_0602e7b8);
  return iVar1;
}

