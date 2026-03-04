/* FUN_06013E14  0x06013E14 */


void FUN_06013e14(void)

{
  int in_r2;
  int iVar1;
  
  iVar1 = (int)(short)((ushort)*(undefined4 *)PTR_DAT_06013e34 & 0x1f);
  if (in_r2 < iVar1) {
    (*(code *)PTR_FUN_06013e38)((int)(short)(iVar1 << 0xc));
    return;
  }
  return;
}

