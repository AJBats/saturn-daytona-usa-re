/* FUN_06015C5E  0x06015C5E */


void FUN_06015c5e(undefined1 param_1)

{
  ushort uVar1;
  undefined *puVar2;
  byte bVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_06015ca0;
  iVar4 = (int)DAT_06015c9c;
  bVar3 = 0;
  do {
    uVar1 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    *(int *)(puVar2 + (short)(uVar1 * 0x44) + 0x30) = iVar4;
  } while (bVar3 < 8);
  (*(code *)PTR_FUN_06015ca8)(param_1);
  return;
}

