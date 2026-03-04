/* FUN_06015D94  0x06015D94 */


void FUN_06015d94(undefined1 param_1)

{
  undefined *puVar1;
  byte bVar2;
  byte bVar3;
  
  puVar1 = PTR_DAT_06015de0;
  bVar2 = 0;
  do {
    bVar3 = bVar2 + 1;
    puVar1[(short)((ushort)bVar2 * 0x44) + 2] = 9;
    puVar1[(short)((ushort)bVar2 * 0x44) + 0x41] = 3;
    bVar2 = bVar3;
  } while (bVar3 < 8);
  (*(code *)PTR_FUN_06015de4)(param_1);
  return;
}

