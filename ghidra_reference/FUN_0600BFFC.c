extern int DAT_0600c090;

extern int FUN_0600b6a0();

void FUN_0600bffc()
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  unsigned char *pbVar6;

  puVar4 = 0x0605A1DD;

  puVar3 = 0x0608A52C;

  puVar2 = 0x0607EBC4;

  pbVar6 = (unsigned char *)-495;

  bVar1 = 0;

  if (*(int *)0x06083255 != '\0') {

    (*(int(*)())0x06034708)(*(int *)0x0607EB8C);

  }

  if ((*(unsigned int *)puVar2 & (unsigned int)0x02000000) == 0) {

    if (*(int *)0x06078635 == '\0') {

      (*(int(*)())0x0600D31C)();

    }

    else {

      (*(int(*)())0x0600D336)();

    }

  }

  if ((*(char **)puVar2 == 0x00020000) && (*(int *)0x0607EAE0 == 0)) {

    (*(int(*)())0x0602E610)();

  }

  iVar5 = *(int *)puVar3;

  *(int *)puVar3 = iVar5 + 0x30;

  (*(int(*)())0x06027630)(iVar5 + 0x30,*(int *)0x06089EDC,0x30);

  if (*(int *)0x06059F30 == 0) {

    *(short *)0x06078664 = (short)(*(int *)0x0607EA98 >> 1);

  }

  else {

    *(unsigned short *)0x06078664 = (unsigned short)(unsigned char)*puVar4;

  }

  *(char **)0x06063574 = 0x0600C170;

  *(short *)0x21000000 = (short)0x0000FFFF;

  if ((*(unsigned int *)puVar2 & (unsigned int)0x02800008) == 0) {

    (*(int(*)())0x060058FA)();

  }

  (*(int(*)())0x06006868)();

  FUN_0600b6a0();

  if (*(char **)puVar2 != 0x02000000) {

    (*(int(*)())0x0601BDEC)();

  }

  while ((*pbVar6 & 0x80) != 0x80) {

    bVar1 = 1;

  }

  *pbVar6 = *pbVar6 & 0xf;

  if (bVar1) {

    if ((int)(unsigned int)(unsigned char)*puVar4 < *(int *)0x0607EA98) {

      *puVar4 = *puVar4 + '\x01';

    }

  }

  else if (1 < (unsigned char)*puVar4) {

    *puVar4 = *puVar4 + -1;

  }

  (*(int(*)())0x0603C000)();

  *(int *)puVar3 = *(int *)puVar3 + -0x30;

  return;

}
