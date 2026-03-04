/* FUN_06015E26  0x06015E26 */


void FUN_06015e26(undefined1 param_1)

{
  undefined *puVar1;
  byte bVar2;
  byte bVar3;
  
  puVar1 = PTR_DAT_06015e70;
  bVar2 = 0;
  do {
    bVar3 = bVar2 + 1;
    puVar1[(short)((ushort)bVar2 * 0x44) + 2] = 8;
    *(undefined4 *)(puVar1 + (short)((ushort)bVar2 * 0x44) + 4) =
         *(undefined4 *)(puVar1 + (short)((ushort)bVar2 * 0x44) + 0x34);
    *(undefined4 *)(puVar1 + (short)((ushort)bVar2 * 0x44) + 0x2c) = 0;
    *(undefined4 *)(puVar1 + (short)((ushort)bVar2 * 0x44) + 0x30) = 0;
    bVar2 = bVar3;
  } while (bVar3 < 8);
  (*(code *)PTR_FUN_06015e74)(param_1);
  return;
}

