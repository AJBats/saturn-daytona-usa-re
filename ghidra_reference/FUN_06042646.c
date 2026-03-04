/* FUN_06042646  0x06042646 */


undefined * FUN_06042646(int param_1,int param_2)

{
  longlong lVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int unaff_r10;
  int iVar7;
  int iVar8;
  
  puVar2 = PTR_DAT_06042700;
  puVar5 = PTR_Onchip_DVSR_060426fc;
  if (unaff_r10 < 0) {
    param_2 = -unaff_r10;
  }
  iVar3 = param_1;
  if (param_1 < 0) {
    iVar3 = -param_1;
  }
  iVar7 = DAT_06042704;
  if (0x40 < param_2) {
    *(int *)PTR_Onchip_DVSR_060426fc = param_2;
    *(int *)(puVar5 + 0x10) = (int)(short)((uint)iVar3 >> 0x10);
    *(int *)(puVar5 + 0x14) = iVar3 << 0x10;
    iVar7 = *(int *)(puVar5 + 0x14);
  }
  iVar4 = 0;
  iVar3 = 0x5a;
  do {
    iVar8 = iVar4 + iVar3 >> 1;
    iVar6 = iVar8;
    if ((*(int *)(puVar2 + iVar8 * 8) <= iVar7) &&
       (iVar4 = iVar8 + 1, iVar6 = iVar3, iVar7 < *(int *)(puVar2 + iVar4 * 8))) break;
    iVar3 = iVar6;
  } while (iVar4 < iVar6);
  lVar1 = (longlong)*(int *)(puVar2 + iVar8 * 8 + 4) *
          (longlong)(iVar7 - *(int *)(puVar2 + iVar8 * 8));
  puVar5 = (undefined *)((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
  if ((int)PTR_DAT_06042708 < (int)puVar5) {
    puVar5 = PTR_DAT_06042708;
  }
  puVar5 = puVar5 + iVar8 * 0x10000;
  if (param_1 < 0) {
    puVar5 = (undefined *)-(int)puVar5;
  }
  if (unaff_r10 < 0) {
    puVar2 = DAT_06042710;
    if (-1 < param_1) {
      puVar2 = PTR_DAT_0604270c;
    }
    puVar5 = puVar2 + -(int)puVar5;
  }
  return puVar5;
}

