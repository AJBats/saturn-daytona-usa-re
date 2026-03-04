/* FUN_0600C170  0x0600C170 */


undefined4 FUN_0600c170(void)

{
  undefined4 uVar1;
  
  (*(code *)PTR_FUN_0600c1b0)();
  if (*PTR_DAT_0600c1b4 == '\0') {
    (*(code *)PTR_FUN_0600c1f4)();
  }
  else {
    FUN_0600b340();
  }
  FUN_0600b914();
  if (*(int *)PTR_DAT_0600c1f8 + *(int *)PTR_DAT_0600c1fc == 8) {
    uVar1 = (*(code *)PTR_FUN_0600c200)();
  }
  else {
    uVar1 = (*(code *)PTR_FUN_0600c204)();
  }
  *(undefined4 *)PTR_DAT_0600c20c = *(undefined4 *)PTR_DAT_0600c208;
  *(short *)PTR_DAT_0600c214 = (short)PTR_DAT_0600c210;
  return uVar1;
}

