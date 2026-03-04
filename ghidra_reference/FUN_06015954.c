/* FUN_06015954  0x06015954 */


void FUN_06015954(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  char local_28;
  
  puVar3 = PTR_DAT_06015a38;
  puVar2 = PTR_DAT_06015a34;
  puVar1 = PTR_DAT_06015a30;
  iVar5 = (int)PTR_DAT_06015a2c._0_2_;
  local_28 = '\0';
  bVar6 = 0;
  do {
    *(undefined4 *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x30) = 0;
    puVar3[(short)((ushort)bVar6 * 0x44) + 2] = 2;
    if (*(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) < 1 ||
        (int)puVar1 <= *(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c)) {
      if ((int)puVar1 < *(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c)) {
        iVar4 = *(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) + iVar5;
        *(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) = iVar4;
        if ((int)puVar2 < iVar4) {
          *(undefined **)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) = puVar2;
        }
      }
      else {
        *(undefined4 *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) = 0;
        local_28 = local_28 + '\x01';
      }
    }
    else {
      iVar4 = *(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) - iVar5;
      *(int *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) = iVar4;
      if (iVar4 < 0) {
        *(undefined4 *)(puVar3 + (short)((ushort)bVar6 * 0x44) + 0x2c) = 0;
      }
    }
    (*(code *)PTR_FUN_06015a9c)(bVar6);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 8);
  if (local_28 == '\b') {
    (*(code *)PTR_FUN_06015aa0)(param_1);
    return;
  }
  return;
}

