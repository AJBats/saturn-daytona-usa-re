/* FUN_060164CE  0x060164CE */


void FUN_060164ce(byte param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_06016500;
  if (*PTR_DAT_06016510 == '\0') {
    if ((int)PTR_DAT_06016628 < *(int *)(PTR_DAT_06016500 + (short)((ushort)param_1 * 0x44) + 0xc))
    {
      *(int *)(PTR_DAT_06016500 + (short)((ushort)param_1 * 0x44) + 4) =
           *(int *)(PTR_DAT_06016500 + (short)((ushort)param_1 * 0x44) + 4) +
           *(int *)(PTR_DAT_06016500 + (short)((ushort)param_1 * 0x44) + 0x10);
      if (param_1 < 4) {
        if (*(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34) <=
            *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4)) {
          *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) =
               *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34);
        }
      }
      else if (*(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) <=
               *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34)) {
        *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 4) =
             *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x34);
      }
      *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) =
           *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0xc) -
           *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18);
      iVar2 = *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x24);
      iVar3 = *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18);
      *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = iVar3 - iVar2;
      if (iVar3 - iVar2 <= (int)PTR_DAT_0601662c) {
        *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = (int)DAT_06016624;
        *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x10) = 0;
      }
    }
    else {
      *(undefined **)(PTR_DAT_06016500 + (short)((ushort)param_1 * 0x44) + 0xc) = PTR_DAT_06016628;
      *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x24) = 0;
      *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = 0;
      puVar1[(short)((ushort)param_1 * 0x44) + 2] =
           puVar1[(short)((ushort)param_1 * 0x44) + 2] + '\x01';
    }
  }
  else {
    *(undefined4 *)(PTR_DAT_06016500 + (short)((ushort)param_1 * 0x44) + 0x2c) = 0;
    puVar1[(short)((ushort)param_1 * 0x44) + 2] = 3;
  }
  FUN_06016dd8(param_1);
  return;
}

