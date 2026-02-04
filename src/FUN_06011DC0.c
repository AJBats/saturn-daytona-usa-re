void FUN_06011dc0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  puVar4 = 0x060785FC;

  puVar3 = 0x060786CC;

  puVar2 = 0x0605A008;

  puVar1 = 0x0605AAA0;

  for (uVar5 = 0; uVar5 < *(unsigned short *)puVar1; uVar5 = uVar5 + 1) {

    if (puVar3[(short)(uVar5 * 0x18) + 5] == '\0') {

      (*0x060280F8)(puVar3 + (short)(uVar5 * 0x18),*(int *)puVar4);

    }

    else {

      (*0x060280C4)(puVar3 + (short)(uVar5 * 0x18),*(int *)puVar4);

      (puVar3 + (short)(uVar5 * 0x18))[5] = 0;

    }

    *(int *)puVar2 = *(int *)puVar2 + 1;

    *(int *)puVar4 = *(int *)puVar4 + 0x20;

  }

  *(short *)puVar1 = 0;

  return;

}
