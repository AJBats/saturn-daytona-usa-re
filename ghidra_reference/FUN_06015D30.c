/* FUN_06015D30  0x06015D30 */


void FUN_06015d30(undefined1 param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  puVar1 = PTR_DAT_06015de0;
  bVar2 = 0;
  do {
    *(undefined4 *)(puVar1 + (short)((ushort)bVar2 * 0x44) + 0x30) = 0;
    if (puVar1[(short)((ushort)bVar2 * 0x44) + 2] == '\x02') {
      puVar1[(short)((ushort)bVar2 * 0x44) + 2] = 5;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 8);
  (*(code *)PTR_FUN_06015de4)(param_1);
  return;
}

