/* FUN_06027498  0x06027498 */


void FUN_06027498(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_060274da(param_1,param_1);
  iVar2 = FUN_06027476(uVar1);
  if (0 < iVar2) {
    iVar2 = FUN_0602755c(PTR_DAT_060274f8,iVar2);
    *param_1 = (int)((ulonglong)((longlong)(int)*param_1 * (longlong)iVar2) >> 0x20) << 0x10 |
               (uint)((longlong)(int)*param_1 * (longlong)iVar2) >> 0x10;
    param_1[1] = (int)((ulonglong)((longlong)(int)param_1[1] * (longlong)iVar2) >> 0x20) << 0x10 |
                 (uint)((longlong)(int)param_1[1] * (longlong)iVar2) >> 0x10;
    param_1[2] = (int)((ulonglong)((longlong)(int)param_1[2] * (longlong)iVar2) >> 0x20) << 0x10 |
                 (uint)((longlong)(int)param_1[2] * (longlong)iVar2) >> 0x10;
  }
  return;
}

