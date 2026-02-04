extern void FUN_0601476c();

unsigned int FUN_060146d2()
{

  char *puVar1;

  char cVar3;

  unsigned int uVar2;

  char *puVar4;

  char *puVar5;

  *(int *)0x0607EBCC = 0;

  cVar3 = FUN_0601476c(0x06084FB4);

  if (cVar3 == '\0') {

    *0x06084AF2 = 4;

  }

  else {

    *0x06084AF2 = 6;

  }

  puVar1 = 0x06084B14;

  uVar2 = *(unsigned int *)0x06084B10;

  if ((uVar2 & 1) == 0) {

    puVar4 = *(char **)0x06085FFC;

    if (puVar4 != (char *)0x0) {

      puVar5 = 0x06084B14 + 1;

      *puVar4 = *0x06084B14;

      puVar4[1] = *puVar5;

      puVar4[2] = puVar1[2];

      puVar4[3] = puVar1[3];

    }

    puVar1 = 0x06084B14;

    puVar4 = *(char **)0x06086000;

    if (puVar4 != (char *)0x0) {

      puVar5 = 0x06084B14 + 1;

      *puVar4 = *0x06084B14;

      puVar4[1] = *puVar5;

      puVar4[2] = puVar1[2];

      puVar4[3] = puVar1[3];

    }

  }

  return uVar2;

}
