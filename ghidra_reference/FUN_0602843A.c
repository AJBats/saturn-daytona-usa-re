/* FUN_0602843A  0x0602843A */


void FUN_0602843a(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int *piVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  
  psVar10 = (short *)(param_2 + **(int **)(PTR_PTR_060284a4 + param_1));
  iVar5 = FUN_06028306(param_4);
  piVar11 = (int *)(PTR_DAT_060284a8 + param_3);
  iVar8 = *piVar11;
  sVar3 = *(short *)(piVar11 + 1);
  cVar1 = *(char *)((int)piVar11 + 6);
  iVar9 = (int)*(char *)((int)piVar11 + 7);
  cVar2 = *(char *)(piVar11 + 2);
  iVar12 = (int)*(char *)((int)piVar11 + 9);
  sVar4 = *(short *)((int)piVar11 + 10);
  pcVar6 = (char *)(iVar5 - (iVar12 + -0xc));
  pcVar7 = pcVar6;
  iVar5 = iVar12;
  do {
    do {
      psVar13 = (short *)(iVar8 + ((int)cVar2 & 0xffffU) * ((int)*pcVar7 & 0xffffU));
      iVar14 = (int)cVar1;
      do {
        *psVar10 = *psVar13 + sVar3;
        psVar13 = psVar13 + 1;
        iVar14 = iVar14 + -1;
        psVar10 = psVar10 + 1;
      } while (iVar14 != 0);
      iVar5 = iVar5 + -1;
      pcVar7 = pcVar7 + 1;
    } while (iVar5 != 0);
    iVar8 = iVar8 + cVar1 * 2;
    iVar9 = iVar9 + -1;
    psVar10 = (short *)((int)psVar10 + (int)sVar4);
    pcVar7 = pcVar6;
    iVar5 = iVar12;
  } while (iVar9 != 0);
  return;
}

