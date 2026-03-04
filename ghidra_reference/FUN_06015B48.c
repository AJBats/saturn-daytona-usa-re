/* FUN_06015B48  0x06015B48 */


void FUN_06015b48(undefined1 param_1)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  byte bVar5;
  
  puVar1 = PTR_DAT_06015c24;
  iVar4 = (int)DAT_06015c22;
  cVar3 = '\0';
  bVar5 = 0;
  do {
    if (bVar5 < 7) {
      iVar2 = *(int *)(puVar1 + (short)((ushort)bVar5 * 0x44) + 0x30) + iVar4;
      *(int *)(puVar1 + (short)((ushort)bVar5 * 0x44) + 0x30) = iVar2;
      if (-1 < iVar2) {
        *(undefined4 *)(puVar1 + (short)((ushort)bVar5 * 0x44) + 0x30) = 0;
        cVar3 = cVar3 + '\x01';
      }
    }
    else if ((bVar5 == 7) &&
            (iVar2 = *(int *)(puVar1 + 0x20c) - iVar4, *(int *)(puVar1 + 0x20c) = iVar2, iVar2 < 1))
    {
      *(undefined4 *)(puVar1 + 0x20c) = 0;
      cVar3 = cVar3 + '\x01';
    }
    (*(code *)PTR_FUN_06015c28)(bVar5);
    bVar5 = bVar5 + 1;
  } while (bVar5 < 8);
  if (cVar3 == '\b') {
                    /* WARNING: Could not recover jumptable at 0x06015c0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_FUN_06015c2c)(param_1);
    return;
  }
  return;
}

