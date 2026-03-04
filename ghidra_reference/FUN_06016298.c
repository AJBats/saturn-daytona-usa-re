/* FUN_06016298  0x06016298 */


void FUN_06016298(byte param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  
  puVar2 = PTR_DAT_06016354;
  bVar1 = false;
  iVar4 = *(int *)(PTR_DAT_06016354 + (short)((ushort)param_1 * 0x44) + 0x10);
  iVar5 = *(int *)(PTR_DAT_06016354 + (short)((ushort)param_1 * 0x44) + 4);
  *(int *)(PTR_DAT_06016354 + (short)((ushort)param_1 * 0x44) + 4) = iVar5 + iVar4;
  iVar4 = (*(code *)PTR_FUN_06016358)
                    ((iVar5 + iVar4) - *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x34));
  if (*PTR_PTR_0601635c == '\0' &&
      iVar4 <= *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x24)) {
    *PTR_PTR_0601635c = 1;
    puVar6 = puVar2 + (short)((ushort)param_1 * 0x44);
    *(undefined4 *)(puVar6 + 4) = *(undefined4 *)(puVar6 + 0x20);
    uVar3 = (*(code *)PTR_FUN_06016360)();
    *(undefined4 *)(puVar6 + 0x10) = uVar3;
  }
  if (param_1 < 4 &&
      *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 4) <=
      *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x34)) {
    *(undefined4 *)(puVar2 + (short)((ushort)param_1 * 0x44) + 4) =
         *(undefined4 *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x34);
    bVar1 = true;
  }
  else if (*(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x34) <=
           *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 4) && 3 < param_1) {
    *(undefined4 *)(puVar2 + (short)((ushort)param_1 * 0x44) + 4) =
         *(undefined4 *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x34);
    bVar1 = true;
  }
  if ((*PTR_DAT_0601645c != '\0') &&
     (iVar4 = (int)DAT_0601645a, iVar5 = *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x30),
     *(int *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x30) = iVar5 + iVar4, -1 < iVar5 + iVar4))
  {
    *(undefined4 *)(puVar2 + (short)((ushort)param_1 * 0x44) + 0x30) = 0;
  }
  FUN_06016dd8(param_1);
  if (bVar1) {
    puVar2[(short)((ushort)param_1 * 0x44) + 2] = 7;
  }
  return;
}

