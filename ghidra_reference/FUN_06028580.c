/* FUN_06028580  0x06028580 */


void FUN_06028580(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  
  iVar2 = (((uint)(param_2 << 8) >> 2) + param_1) * 2;
  bVar1 = (int)param_3 < 0;
  if (bVar1) {
    param_3 = -param_3;
  }
  iVar3 = (int)DAT_06028610;
  FUN_06028368(8,iVar2 + 10,iVar3,
               ((uint)DAT_060285da * (param_3 & 0xffff) >> 0x10) + (int)(short)DAT_060285da);
  uVar4 = (ushort)iVar3;
  FUN_06028368(8,iVar2);
  iVar3 = **(int **)(PTR_PTR_060285dc + 8);
  ((ushort *)(iVar3 + iVar2))[7] = uVar4 | 0x2e;
  if (bVar1) {
    *(ushort *)(iVar3 + iVar2) = uVar4 | 0x2d;
  }
  return;
}

