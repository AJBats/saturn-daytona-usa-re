extern int PTR_DAT_06010508;

extern int PTR_DAT_06010508;

void FUN_06010470()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  int *puVar4;

  int iVar5;

  puVar1 = 0x0607EADC;

  iVar5 = (int)PTR_DAT_06010508;

  uVar3 = (unsigned int)*(unsigned short *)0x06063D9C ^ (unsigned int)0x0000FFFF;

  *(int *)0x0607EADC = 0;

  if (iVar5 < (int)(uVar3 & 0xff)) {

    *(int *)puVar1 = *(int *)puVar1 + 1;

  }

  puVar2 = 0x0607EAB8;

  *(int *)0x0607EAB8 = *(int *)puVar1;

  *(int *)0x06078868 = *(int *)puVar1;

  puVar1 = 0x0602766C;

  if (*(int *)puVar2 == 0) {

    (*0x0602766C)

              (*(int *)0x06078884,*(int *)0x0605D05C,iVar5);

    puVar4 = (int *)0x0605D088;

  }

  else {

    (*0x0602766C)

              (*(int *)0x06078884,*(int *)0x0605D084,iVar5);

    puVar4 = (int *)0x0605D060;

  }

  (*puVar1)(*(int *)0x06078880,*puVar4,iVar5);

  return;

}
