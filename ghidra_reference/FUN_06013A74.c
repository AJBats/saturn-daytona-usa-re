/* FUN_06013A74  0x06013A74 */


undefined4 FUN_06013a74(void)

{
  short sVar1;
  undefined4 uVar2;
  
  FUN_06014360();
  FUN_0601416c();
  FUN_0601424c();
  FUN_060140c4();
  FUN_0601444c();
  if (*(short *)PTR_DAT_06013aec == 0x10) {
    FUN_06014466();
  }
  else {
    FUN_0601450c();
  }
  uVar2 = FUN_060145bc();
  if ((*(ushort *)PTR_DAT_06013af0 & DAT_06013aea) != 0) {
    uVar2 = FUN_060146d2();
  }
  if ((*(uint *)PTR_DAT_06013af4 < 4) &&
     (sVar1 = *(short *)PTR_DAT_06013af8, *(short *)PTR_DAT_06013af8 = sVar1 + -1,
     0 < (short)(sVar1 + -1))) {
    return uVar2;
  }
  uVar2 = FUN_060146d2();
  return uVar2;
}

