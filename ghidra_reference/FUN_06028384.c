/* FUN_06028384  0x06028384 */


undefined4 FUN_06028384(int param_1,int param_2,short param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  
  param_2 = param_2 + **(int **)(PTR_PTR_060283ac + param_1);
  pcVar3 = (char *)FUN_060282c0(param_4);
  iVar4 = 0;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *(short *)(param_2 + iVar4) = cVar1 + param_3;
    bVar2 = iVar4 != 0x16;
    iVar4 = iVar4 + 2;
  } while (bVar2);
  return 0x18;
}

