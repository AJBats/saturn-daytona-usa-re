/* FUN_0603367A  0x0603367A */


undefined4
FUN_0603367a(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int extraout_r2;
  short sVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_060336c8();
  iVar1 = (int)uVar3;
  do {
    iVar1 = iVar1 + DAT_060336c4;
    if (*(int *)(extraout_r2 + iVar1) == param_1) break;
    param_3 = param_3 + -1;
  } while (0 < param_3);
  sVar2 = 6;
  if (((char)*PTR_DAT_06033880 < '\x01') && (param_1 < 2)) {
    sVar2 = (short)param_1 * 4 + 6;
  }
  *(short *)((int)((ulonglong)uVar3 >> 0x20) + -2) = sVar2;
  FUN_06033550();
  return param_5;
}

