/* FUN_06015CAC  0x06015CAC */


void FUN_06015cac(undefined1 param_1)

{
  undefined *puVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_06015d28;
  iVar5 = (int)DAT_06015d24;
  cVar4 = '\0';
  bVar3 = 0;
  do {
    iVar2 = *(int *)(puVar1 + (short)((ushort)bVar3 * 0x44) + 0x30);
    *(int *)(puVar1 + (short)((ushort)bVar3 * 0x44) + 0x30) = iVar2 + iVar5;
    if (-1 < iVar2 + iVar5) {
      *(undefined4 *)(puVar1 + (short)((ushort)bVar3 * 0x44) + 0x30) = 0;
      cVar4 = cVar4 + '\x01';
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 8);
  if (cVar4 == '\b') {
    (*(code *)PTR_FUN_06015d2c)(param_1);
    return;
  }
  return;
}

