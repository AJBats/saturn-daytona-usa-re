/* FUN_06016410  0x06016410 */


void FUN_06016410(byte param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_06016460;
  if (*PTR_DAT_0601645c != '\0') {
    iVar2 = (int)DAT_0601645a;
    iVar3 = *(int *)(PTR_DAT_06016460 + (short)((ushort)param_1 * 0x44) + 0x30);
    *(int *)(PTR_DAT_06016460 + (short)((ushort)param_1 * 0x44) + 0x30) = iVar3 + iVar2;
    if (-1 < iVar3 + iVar2) {
      *(undefined4 *)(puVar1 + (short)((ushort)param_1 * 0x44) + 0x30) = 0;
    }
    FUN_06016dd8(param_1);
    return;
  }
  return;
}

