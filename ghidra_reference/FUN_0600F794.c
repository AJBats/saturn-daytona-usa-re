/* FUN_0600F794  0x0600F794 */


void FUN_0600f794(void)

{
  short sVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_0600f7e4;
  sVar1 = *(short *)(PTR_DAT_0600f7e4 + 2);
  (*(code *)PTR_FUN_0600f7e8)(0);
  (*(code *)PTR_FUN_0600f7ec)();
  if (*(short *)(puVar2 + 6) == 0x10) {
    FUN_06010238();
  }
  else {
    FUN_060102a8((int)sVar1);
  }
  FUN_060102ea((int)sVar1);
  if (*PTR_DAT_0600f84c != '\0') {
    *PTR_DAT_0600f854 = (*(ushort *)PTR_DAT_0600f850 & DAT_0600f848) != 0;
  }
  return;
}

