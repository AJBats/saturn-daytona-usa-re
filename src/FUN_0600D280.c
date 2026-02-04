extern int PTR_DAT_0600d304;

extern int PTR_DAT_0600d304;

void FUN_0600d280()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  int *puVar5;

  int iVar6;

  puVar2 = 0x0607EA98;

  puVar1 = 0x06078900;

  iVar6 = (int)PTR_DAT_0600d304;

  puVar5 = (int *)0x0607E94C;

  for (uVar4 = 0; uVar4 < 0x28; uVar4 = uVar4 + 2) {

    *puVar5 = 0;

    puVar5[1] = 0;

    puVar5 = puVar5 + 2;

  }

  puVar5 = (int *)0x0607E9EC;

  for (uVar4 = 0; puVar3 = 0x0607EA8C, uVar4 < 0x28; uVar4 = uVar4 + 2) {

    *puVar5 = 0;

    puVar5[1] = 0;

    puVar5 = puVar5 + 2;

  }

  *(int *)0x0607EA8C = 0;

  *(int *)(puVar3 + 4) = 0;

  *(int *)(puVar3 + 8) = 0;

  puVar5 = (int *)0x0607E94C;

  for (uVar4 = 1; uVar4 <= *(unsigned int *)puVar2; uVar4 = uVar4 + 1) {

    *puVar5 = puVar1 + (*(int *)puVar2 - uVar4) * iVar6;

    puVar5 = puVar5 + 1;

  }

  puVar5 = (int *)0x0607E9EC;

  for (uVar4 = 1; uVar4 <= *(unsigned int *)puVar2; uVar4 = uVar4 + 1) {

    *puVar5 = puVar1 + (*(int *)puVar2 - uVar4) * iVar6;

    puVar5 = puVar5 + 1;

  }

  return;

}
