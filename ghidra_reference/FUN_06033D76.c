/* FUN_06033D76  0x06033D76 */


int FUN_06033d76(void)

{
  int iVar1;
  
  FUN_06033f54();
  iVar1 = *(int *)PTR_DAT_06033e68;
  if (DAT_06033e6c <= iVar1) {
    FUN_06033f54(DAT_06033e70);
    FUN_06033f54(DAT_06033e74);
    FUN_06033f54(DAT_06033e78);
    FUN_06033f54(DAT_06033e7c);
    if (DAT_06033e80 <= iVar1) {
      FUN_06033f54(0x1e);
      FUN_06033f54(0x1f);
      FUN_06033f54(0x20);
      FUN_06033f54(0x21);
      FUN_06033f54(0x22);
      if (DAT_06033e84 <= iVar1) {
        FUN_06033f54(0x23);
        FUN_06033f54(0x24);
        FUN_06033f54(0x25);
        FUN_06033f54(0x26);
        FUN_06033f54(0x27);
        FUN_06033f54(0x28);
        FUN_06033f54(0x29);
        FUN_06033f54(0x2a);
        FUN_06033f54(0x2b);
        FUN_06033f54(0x2c);
      }
    }
  }
  iVar1 = *(int *)PTR_DAT_06033e68 + 1;
  if (DAT_06033e88 <= *(int *)PTR_DAT_06033e68 + 1) {
    iVar1 = DAT_06033e88;
  }
  *(int *)PTR_DAT_06033e68 = iVar1;
  return iVar1;
}

