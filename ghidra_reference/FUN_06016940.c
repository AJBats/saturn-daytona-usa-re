/* FUN_06016940  0x06016940 */


void FUN_06016940(uint param_1)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  
  puVar4 = PTR_DAT_06016a10;
  bVar2 = false;
  uVar3 = (ushort)param_1;
  if ((param_1 & 0xff) < 7) {
    puVar7 = PTR_DAT_06016a10 + (short)((uVar3 & 0xff) * 0x44);
    iVar5 = (*(code *)PTR_FUN_06016a14)();
    iVar6 = *(int *)(puVar7 + 0x30);
    *(int *)(puVar7 + 0x30) = iVar6 + iVar5;
    if (iVar6 + iVar5 <= *(int *)(puVar7 + 0x38)) {
      *(undefined4 *)(puVar4 + (short)((uVar3 & 0xff) * 0x44) + 0x30) =
           *(undefined4 *)(puVar4 + (short)((uVar3 & 0xff) * 0x44) + 0x38);
      bVar2 = true;
    }
  }
  else {
    uVar1 = uVar3 & 0xff;
    iVar5 = (*(code *)PTR_FUN_06016a14)(param_1,4);
    *(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x30) =
         *(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x30) + iVar5;
    FUN_06016dd8(param_1 & 0xff);
    if (*(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x38) <=
        *(int *)(puVar4 + (short)(uVar1 * 0x44) + 0x30)) {
      *(undefined4 *)(puVar4 + (short)((uVar3 & 0xff) * 0x44) + 0x30) =
           *(undefined4 *)(puVar4 + (short)((uVar3 & 0xff) * 0x44) + 0x38);
      bVar2 = true;
    }
  }
  FUN_06016dd8(param_1 & 0xff);
  if (bVar2) {
    puVar4[(short)((uVar3 & 0xff) * 0x44) + 2] = 2;
  }
  return;
}

