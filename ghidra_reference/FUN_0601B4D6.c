/* FUN_0601B4D6  0x0601B4D6 */


int FUN_0601b4d6(void)

{
  int iVar1;
  
  if ((*(ushort *)PTR_DAT_0601b524 & PTR_DAT_0601b4f2._2_2_) != 0) {
    *PTR_DAT_0601b528 = 1;
    iVar1 = (*(code *)PTR_FUN_0601b52c)();
    return iVar1;
  }
  FUN_0601b7f4();
  iVar1 = FUN_0601b6dc();
  if ((*(ushort *)PTR_DAT_0601b570 & DAT_0601b56e) != 0) {
    iVar1 = (int)(char)*PTR_DAT_0601b574;
    if (iVar1 == 2) {
      *PTR_DAT_0601b578 = 1;
      iVar1 = (*(code *)PTR_FUN_0601b57c)();
      return iVar1;
    }
    *PTR_DAT_0601b580 = 2;
  }
  return iVar1;
}

