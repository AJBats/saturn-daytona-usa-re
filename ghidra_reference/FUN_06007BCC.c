extern int FUN_06007a50();

void FUN_06007bcc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  unsigned int uVar7;

  puVar5 = 0x060785FC;

  puVar4 = 0x0608AC20;

  puVar3 = 0x00008000;

  puVar2 = 0x060620D0;

  puVar1 = 0x060280F8;

  *(int *)0x06078620 = 0;

  if ((*(unsigned short *)0x06063DA0 & 8) == 0) {

    *(int *)0x0607861C = 0;

  }

  else {

    *(int *)0x0607861C = 1;

  }

  for (uVar6 = *(unsigned int *)0x06078620; uVar6 < *(unsigned int *)puVar2; uVar6 = uVar6 + 1) {

    uVar7 = (unsigned int)*(unsigned short *)(0x0606A4F8 + (uVar6 << 1));

    if (*(short *)(puVar4 + (uVar7 * 0x18 & 0xffff) + 6) == 9) {

      (*(int(*)())0x060281B8)(puVar4 + (uVar7 * 0x18 & 0xffff),*(int *)puVar5,puVar3);

    }

    else {

      (*(int(*)())puVar1)(puVar4 + (uVar7 * 0x18 & 0xffff),*(int *)puVar5);

    }

    *(int *)puVar5 = *(int *)puVar5 + 0x20;

  }

  *(int *)0x0605A008 = *(int *)0x0605A008 + *(int *)puVar2;

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x20228000) != 0) {

    (*(int(*)())0x060333D8)();

    FUN_06007a50();

  }

  (*(int(*)())0x06011DC0)();

  (*(int(*)())0x060171AC)();

  return;

}
