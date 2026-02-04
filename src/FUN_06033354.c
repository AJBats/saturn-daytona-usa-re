extern int PTR_DAT_060333b0;

extern int PTR_DAT_060333b0;

int FUN_06033354()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  short *psVar9;

  int in_pr;

  short *psVar10;

  puVar8 = 0x060338DC;

  if (0 < **(int **)0x06033868) {

    puVar8 = 0x060338E8;

  }

  iVar5 = 6;

  puVar6 = 0x06062D95;

  do {

    puVar7 = puVar8 + 1;

    *puVar6 = *puVar8;

    puVar8 = puVar8 + 2;

    puVar6[1] = *puVar7;

    puVar3 = 0x060629AC;

    puVar2 = 0x060430CE;

    puVar6 = puVar6 + 4;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  iVar5 = 6;

  psVar9 = (short *)0x060338F4;

  do {

    sVar1 = *psVar9;

    psVar10 = psVar9 + 1;

    psVar9 = psVar9 + 2;

    (*(void(*)())0x0602761E)(puVar3 + sVar1,puVar2 + sVar1,(int)*psVar10,iVar5,in_pr);

    iVar5 = iVar5 + -1;

  } while (0 < iVar5);

  uVar4 = (*(void(*)())0x0602761E)(0x25E03700,0x060629AC,(int)PTR_DAT_060333b0,iVar5,in_pr);

  return uVar4;

}
