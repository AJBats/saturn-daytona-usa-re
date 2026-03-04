/* FUN_06028368  0x06028368 */


undefined4 FUN_06028368(int param_1,int param_2,short param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  
  param_2 = param_2 + **(int **)(PTR_PTR_06028380 + param_1);
  iVar3 = FUN_060282c0(param_4);
  pcVar4 = (char *)(iVar3 + 5);
  iVar3 = 0;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *(short *)(param_2 + iVar3) = cVar1 + param_3;
    bVar2 = iVar3 != 0xc;
    iVar3 = iVar3 + 2;
  } while (bVar2);
  return 0xe;
}

