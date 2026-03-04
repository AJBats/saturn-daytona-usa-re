/* FUN_060167C8  0x060167C8 */


void FUN_060167c8(byte param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = PTR_DAT_06016870;
  iVar3 = *(int *)(PTR_DAT_06016870 + (short)((ushort)param_1 * 0x44) + 0x2c) + (int)DAT_0601686c;
  *(int *)(PTR_DAT_06016870 + (short)((ushort)param_1 * 0x44) + 0x2c) = iVar3;
  iVar4 = *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x3c);
  if (iVar4 <= iVar3) {
    *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x2c) =
         *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x3c);
  }
  if (*(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) != 0) {
    if (param_1 < 7) {
      iVar2 = *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) + (int)DAT_0601686e;
      *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) = iVar2;
      if (-1 < iVar2) {
        *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) = 0;
      }
    }
    else {
      iVar2 = *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) - (int)DAT_0601686e;
      *(int *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) = iVar2;
      if (iVar2 < 1) {
        *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) = 0;
      }
    }
  }
  FUN_06016dd8(param_1);
  if (iVar4 <= iVar3) {
    puVar1[(short)((ushort)param_1 * 0x44) + 0x41] = 4;
    puVar1[(short)((ushort)param_1 * 0x44) + 2] = 3;
  }
  return;
}

