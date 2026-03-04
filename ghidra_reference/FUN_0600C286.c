/* FUN_0600C286  0x0600C286 */


int FUN_0600c286(void)

{
  int iVar1;
  
  (*(code *)PTR_FUN_0600c2dc)();
  (*(code *)PTR_FUN_0600c2e0)();
  if (*PTR_DAT_0600c2e4 == '\0') {
    iVar1 = (*(code *)PTR_FUN_0600c2e8)();
  }
  else {
    iVar1 = (int)(char)*PTR_DAT_0600c2e4;
    if (iVar1 == 1) {
      iVar1 = (*(code *)PTR_FUN_0600c378)();
    }
  }
  *(short *)PTR_DAT_0600c380 = (short)PTR_DAT_0600c37c;
  return iVar1;
}

