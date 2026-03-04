/* FUN_0602745C  0x0602745C */


int FUN_0602745c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  uint uVar3;
  
  uVar3 = (uint)(-1 < param_2);
  uVar1 = FUN_0602755c();
  sVar2 = FUN_06027378(uVar1);
  if (uVar3 == 0) {
    sVar2 = sVar2 + (short)PTR_DAT_060274f4;
  }
  return (int)sVar2;
}

