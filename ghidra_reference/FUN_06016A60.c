/* FUN_06016A60  0x06016A60 */


void FUN_06016a60(byte param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_06016ad8;
  if ((int)PTR_DAT_06016ae8 < *(int *)(PTR_DAT_06016ad8 + (short)((ushort)param_1 * 0x44) + 0xc)) {
    *(int *)(PTR_DAT_06016ad8 + (short)((ushort)param_1 * 0x44) + 4) =
         *(int *)(PTR_DAT_06016ad8 + (short)((ushort)param_1 * 0x44) + 4) +
         *(int *)(PTR_DAT_06016ad8 + (short)((ushort)param_1 * 0x44) + 0x10);
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
    if (iVar3 - iVar2 <= (int)PTR_DAT_06016b94) {
      *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = (int)DAT_06016b92;
      *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x10) = 0;
    }
  }
  else {
    *(undefined **)(PTR_DAT_06016ad8 + (short)((ushort)param_1 * 0x44) + 0xc) = PTR_DAT_06016ae8;
    *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x24) = 0;
    *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x18) = 0;
    puVar1[(short)((ushort)param_1 * 0x44) + 2] = 2;
  }
  FUN_06016dd8(param_1);
  return;
}

