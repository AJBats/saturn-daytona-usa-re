/* FUN_0601550C  0x0601550C */


void FUN_0601550c(ushort param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  byte bVar3;
  
  puVar2 = PTR_DAT_060155a0;
  puVar1 = PTR_DAT_0601559c;
  bVar3 = 0;
  do {
    *(undefined4 *)(puVar2 + (short)((ushort)bVar3 * 0x44) + 0x1c) =
         *(undefined4 *)(puVar1 + (uint)bVar3 * 8);
    *(undefined4 *)(puVar2 + (short)((ushort)bVar3 * 0x44) + 0x20) =
         *(undefined4 *)((int)(puVar1 + (uint)bVar3 * 8) + 4);
    *(undefined4 *)(puVar2 + (short)((ushort)bVar3 * 0x44) + 0x24) = 0x60;
    if (bVar3 == 1 || bVar3 == 2) {
      *(undefined4 *)(puVar2 + (short)((ushort)bVar3 * 0x44) + 0x24) = 0x50;
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 4);
  puVar2[(short)((param_1 & 0xff) * 0x44) + 2] =
       puVar2[(short)((param_1 & 0xff) * 0x44) + 2] + '\x01';
  return;
}

