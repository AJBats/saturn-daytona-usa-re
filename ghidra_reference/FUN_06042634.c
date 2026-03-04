/* FUN_06042634  0x06042634 */


undefined * FUN_06042634(int param_1,int param_2)

{
  longlong lVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar2 = PTR_DAT_06042700;
  puVar4 = PTR_Onchip_DVSR_060426fc;
  iVar5 = param_2;
  if (param_2 < 0) {
    iVar5 = -param_2;
  }
  iVar3 = param_1;
  if (param_1 < 0) {
    iVar3 = -param_1;
  }
  iVar7 = DAT_06042704;
  if (0x40 < iVar5) {
    *(int *)PTR_Onchip_DVSR_060426fc = iVar5;
    *(int *)(puVar4 + 0x10) = (int)(short)((uint)iVar3 >> 0x10);
    *(int *)(puVar4 + 0x14) = iVar3 << 0x10;
    iVar7 = *(int *)(puVar4 + 0x14);
  }
  iVar3 = 0;
  iVar5 = 0x5a;
  do {
    iVar8 = iVar3 + iVar5 >> 1;
    iVar6 = iVar8;
    if ((*(int *)(puVar2 + iVar8 * 8) <= iVar7) &&
       (iVar3 = iVar8 + 1, iVar6 = iVar5, iVar7 < *(int *)(puVar2 + iVar3 * 8))) break;
    iVar5 = iVar6;
  } while (iVar3 < iVar6);
  lVar1 = (longlong)*(int *)(puVar2 + iVar8 * 8 + 4) *
          (longlong)(iVar7 - *(int *)(puVar2 + iVar8 * 8));
  puVar4 = (undefined *)((int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10);
  if ((int)PTR_DAT_06042708 < (int)puVar4) {
    puVar4 = PTR_DAT_06042708;
  }
  puVar4 = puVar4 + iVar8 * 0x10000;
  if (param_1 < 0) {
    puVar4 = (undefined *)-(int)puVar4;
  }
  if (param_2 < 0) {
    puVar2 = DAT_06042710;
    if (-1 < param_1) {
      puVar2 = PTR_DAT_0604270c;
    }
    puVar4 = puVar2 + -(int)puVar4;
  }
  return puVar4;
}

