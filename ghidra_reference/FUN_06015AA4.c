/* FUN_06015AA4  0x06015AA4 */


void FUN_06015aa4(ushort param_1)

{
  undefined *puVar1;
  byte bVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_06015b44;
  iVar3 = (int)DAT_06015b40;
  PTR_DAT_06015b44[(short)((param_1 & 0xff) * 0x44) + 1] = 1;
  bVar2 = 0;
  do {
    *(int *)(puVar1 + (short)((ushort)bVar2 * 0x44) + 0x30) = iVar3;
    if (puVar1[(short)((param_1 & 0xff) * 0x44) + 0x40] == '\x01') {
      puVar1[(short)((ushort)bVar2 * 0x44) + 2] = 2;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 8);
  puVar1[(short)((param_1 & 0xff) * 0x44) + 2] =
       puVar1[(short)((param_1 & 0xff) * 0x44) + 2] + '\x01';
  return;
}

