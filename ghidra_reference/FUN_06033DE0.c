/* FUN_06033DE0  0x06033DE0 */


int FUN_06033de0(void)

{
  int iVar1;
  int unaff_r13;
  
  FUN_06033f54();
  if (DAT_06033e84 <= unaff_r13) {
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
  iVar1 = *(int *)PTR_DAT_06033e68 + 1;
  if (DAT_06033e88 <= *(int *)PTR_DAT_06033e68 + 1) {
    iVar1 = DAT_06033e88;
  }
  *(int *)PTR_DAT_06033e68 = iVar1;
  return iVar1;
}

