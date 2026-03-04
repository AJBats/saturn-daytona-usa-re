/* FUN_06020284  0x06020284 */


int FUN_06020284(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_8 [8];
  
  puVar5 = auStack_8;
  pcVar2 = PTR_DAT_0602031c;
  pcVar3 = PTR_DAT_06020318;
  puVar4 = PTR_DAT_06020314;
  (*(code *)PTR_FUN_06020324)();
  if ((((uint)*(ushort *)(puVar4 + 2) & (uint)PTR_DAT_06020328) != 0) &&
     (*pcVar2 = *pcVar2 + '\x01', '\x18' < *pcVar2)) {
    *pcVar2 = '\x19';
  }
  if (((*(ushort *)(puVar4 + 2) & DAT_06020310) != 0) && (*pcVar2 = *pcVar2 + -1, *pcVar2 < '\x01'))
  {
    *pcVar2 = '\0';
  }
  if (((*(ushort *)(puVar4 + 2) & DAT_06020312) != 0) &&
     ((int)*pcVar2 == (uint)(byte)puVar5[*pcVar3])) {
    *pcVar3 = *pcVar3 + '\x01';
  }
  cVar1 = *pcVar3;
  if (cVar1 == 4) {
    *PTR_DAT_0602032c = 1;
  }
  return (int)cVar1;
}

