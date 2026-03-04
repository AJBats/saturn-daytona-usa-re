/* FUN_06008E48  0x06008E48 */


undefined4 FUN_06008e48(void)

{
  undefined4 uVar1;
  
  if (*(int *)PTR_DAT_06008eb0 < 0) {
    *(undefined4 *)PTR_DAT_06008e8c = 0xe;
    (*(code *)PTR_FUN_06008ea0)();
    *(undefined4 *)PTR_DAT_06008ea4 = 0;
  }
  else {
    (*(code *)PTR_FUN_06008eb4)();
  }
  if (*(int *)PTR_DAT_06008e8c != 0xd) {
    uVar1 = (*(code *)PTR_FUN_06008eb8)();
    return uVar1;
  }
  return 0xd;
}

