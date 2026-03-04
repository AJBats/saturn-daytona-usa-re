/* FUN_06015FB0  0x06015FB0 */


void FUN_06015fb0(byte param_1)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  
  puVar6 = PTR_DAT_060160bc;
  bVar2 = false;
  if (*(int *)(PTR_DAT_060160bc + (short)((ushort)param_1 * 0x44) + 0x30) !=
      *(int *)(PTR_DAT_060160bc + (short)((ushort)param_1 * 0x44) + 0x38)) {
    iVar4 = *(int *)(PTR_DAT_060160bc + (short)((ushort)param_1 * 0x44) + 0x18);
    iVar5 = *(int *)(PTR_DAT_060160bc + (short)((ushort)param_1 * 0x44) + 0x30);
    *(int *)(PTR_DAT_060160bc + (short)((ushort)param_1 * 0x44) + 0x30) = iVar5 + iVar4;
    if (*(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x18) < 0 &&
        iVar5 + iVar4 <= *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x38)) {
      *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x30) =
           *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x38);
    }
    if (*(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x38) <=
        *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x30) &&
        -1 < *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x18)) {
      *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x30) =
           *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x38);
    }
  }
  iVar4 = *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10);
  iVar5 = *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 4);
  *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 4) = iVar5 + iVar4;
  iVar4 = (*(code *)PTR_FUN_060160c0)
                    ((iVar5 + iVar4) - *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x34));
  sVar1 = DAT_060160ba;
  if (iVar4 <= (int)PTR_DAT_060160c4) {
    if (*(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) < 0) {
      *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) = DAT_060160c8;
    }
    else {
      *(undefined **)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) = PTR_DAT_060161fc;
      sVar1 = DAT_060161f8;
    }
    iVar4 = (int)sVar1;
    if (*(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x1c) != 0) {
      *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) =
           *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) << 1;
      iVar4 = iVar4 << 1;
    }
    *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) =
         *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) - iVar4;
  }
  if (*(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10) < 0 &&
      *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 4) <=
      *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x34)) {
    *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 4) =
         *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x34);
    bVar2 = true;
  }
  else if (*(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x34) <=
           *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 4) &&
           -1 < *(int *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x10)) {
    *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 4) =
         *(undefined4 *)(puVar6 + (short)((ushort)param_1 * 0x44) + 0x34);
    bVar2 = true;
  }
  FUN_06016dd8(param_1);
  if (bVar2) {
    puVar6[(short)((ushort)param_1 * 0x44) + 0x41] =
         puVar6[(short)((ushort)param_1 * 0x44) + 0x41] + '\x01';
    if ((byte)puVar6[(short)((ushort)param_1 * 0x44) + 0x41] < 4) {
      puVar6 = puVar6 + (short)((ushort)param_1 * 0x44);
      cVar3 = puVar6[2] + -1;
    }
    else {
      puVar6 = puVar6 + (short)((ushort)param_1 * 0x44);
      cVar3 = '\x02';
    }
    puVar6[2] = cVar3;
  }
  return;
}

