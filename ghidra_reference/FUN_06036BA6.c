/* FUN_06036BA6  0x06036BA6 */


void FUN_06036ba6(void)

{
  undefined1 local_c [12];
  
  (*(code *)PTR_FUN_06036bd8)(local_c);
  local_c[0] = 0x75;
  (*(code *)PTR_FUN_06036be0)((int)DAT_06036bce);
  (*(code *)PTR_FUN_06036bdc)((int)DAT_06036bce,local_c);
  return;
}

