/* FUN_0600F8BE  0x0600F8BE */


void FUN_0600f8be(void)

{
  short sVar1;
  
  sVar1 = *(short *)PTR_DAT_0600f8e0;
  *(short *)PTR_DAT_0600f8e0 = sVar1 + -1;
  if (0 < (short)(sVar1 + -1)) {
    (*(code *)PTR_FUN_0600f8f4)();
    return;
  }
  (*(code *)PTR_FUN_0600f960)(4);
  *PTR_DAT_0600f964 = *PTR_DAT_0600f964 + '\x01';
  return;
}

