/* FUN_06028598  0x06028598 */


void FUN_06028598(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  ushort uVar2;
  int unaff_r12;
  
  iVar1 = (int)DAT_06028610;
  FUN_06028368(8,param_2 + 10,iVar1,((param_1 & 0xffff) * (param_3 & 0xffff) >> 0x10) + param_1);
  uVar2 = (ushort)iVar1;
  FUN_06028368(8,param_2);
  iVar1 = **(int **)(PTR_PTR_060285dc + 8);
  ((ushort *)(iVar1 + param_2))[7] = uVar2 | 0x2e;
  if (unaff_r12 == 0) {
    *(ushort *)(iVar1 + param_2) = uVar2 | 0x2d;
  }
  return;
}

