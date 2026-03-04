/* FUN_06013C20  0x06013C20 */


void FUN_06013c20(void)

{
  uint uVar1;
  
  uVar1 = *(ushort *)PTR_DAT_06013c54 + 1;
  if (0x14 < uVar1) {
    uVar1 = 0x14;
  }
  *(short *)PTR_DAT_06013c54 = (short)uVar1;
  FUN_06013fc4();
  FUN_0601416c();
  return;
}

