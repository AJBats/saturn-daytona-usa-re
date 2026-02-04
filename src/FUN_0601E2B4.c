extern int FUN_0601e37c();

void FUN_0601e2b4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  puVar4 = 0x20100063;

  puVar3 = 0x0605E068;

  puVar2 = 0x0604A5C0;

  puVar1 = 0x060877D8;

  if (*(int *)0x06087080 == '\0') {

    for (uVar5 = 0; uVar5 < *(unsigned int *)(puVar2 + (unsigned int)(unsigned char)*puVar1 * 4); uVar5 = uVar5 + 1) {

      *(char *)(*(int *)puVar3 + uVar5) = 0;

    }

  }

  do {

  } while ((*puVar4 & 1) == 1);

  *puVar4 = 1;

  *(int *)0x2010001F = 0x1a;

  do {

  } while ((*puVar4 & 1) != 0);

  (*(void(*)())(*(int *)0x06000358))(*(int *)0x0605E060,*(int *)0x0605E064,0x06087086);

  FUN_0601e37c();

  do {

  } while ((*puVar4 & 1) == 1);

  *puVar4 = 1;

  *(int *)0x2010001F = 0x19;

  do {

  } while ((*puVar4 & 1) != 0);

  return;

}
