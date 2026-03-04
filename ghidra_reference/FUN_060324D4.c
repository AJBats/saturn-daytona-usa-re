/* FUN_060324D4  0x060324D4 */


undefined4 FUN_060324d4(void)

{
  undefined4 uVar1;
  int unaff_r14;
  
  if (*(byte *)(unaff_r14 + DAT_060324e8) == 0) {
    FUN_06032e6c();
    FUN_0603253c();
    FUN_0603268c();
    FUN_06032584();
    uVar1 = FUN_06032ea4();
  }
  else {
    if ((*(byte *)(unaff_r14 + DAT_060324e8) & 4) == 0) {
      uVar1 = FUN_06032528();
      return uVar1;
    }
    FUN_06032e6c();
    FUN_0603253c();
    FUN_0603268c();
    uVar1 = FUN_06032584();
  }
  return uVar1;
}

