extern int DAT_0601043e;

extern int PTR_DAT_06010440;

extern int PTR_DAT_06010440;

void FUN_060103b8(param_1)
    unsigned int param_1;
{

  char *puVar1;

  char *puVar2;

  int *puVar3;

  int iVar4;

  puVar1 = 0x0607EADC;

  if (((param_1 & 0xffff & (unsigned int)0x00008000) != 0) && (*(int *)0x0607EADC < 1)) {

    *(int *)0x0607EADC = *(int *)0x0607EADC + 1;

  }

  if (((param_1 & 0xffff & (int)DAT_0601043e) != 0) && (0 < *(int *)0x0607EADC)) {

    *(int *)puVar1 = *(int *)puVar1 + -1;

  }

  puVar2 = 0x0607EAB8;

  *(int *)0x0607EAB8 = *(int *)puVar1;

  *(int *)0x06078868 = *(int *)puVar1;

  puVar1 = 0x0602766C;

  iVar4 = 0xc0;

  if (*(int *)puVar2 == 0) {

    (*(int(*)())0x0602766C)(*(int *)0x06078884,*(int *)0x0605D05C,iVar4);

    puVar3 = (int *)0x0605D088;

  }

  else {

    (*(int(*)())0x0602766C)(*(int *)0x06078884,*(int *)0x0605D084,iVar4);

    puVar3 = (int *)0x0605D060;

  }

  (*(int(*)())puVar1)(*(int *)0x06078880,*puVar3,iVar4);

  return;

}
