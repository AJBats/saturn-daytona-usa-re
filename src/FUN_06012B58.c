void FUN_06012b58()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  puVar2 = 0x06084360;

  puVar1 = 0x0603AC1C;

  iVar4 = -1;

  *(int *)0x06084360 = 1;

  *(char **)(puVar2 + 8) = 0x0608436C;

  *(int *)(puVar2 + 4) = 0x50;

  puVar2 = 0x06083274;

  iVar5 = 0;

  while (puVar3 = 0x06084AEC, iVar5 = iVar5 + 1, iVar5 < 5) {

    iVar4 = (*(int(*)())puVar1)(5,puVar2,0x06084360);

  }

  if (iVar4 < 3) {

    *(int *)0x06084AEC = 1;

  }

  else {

    iVar4 = (*(int(*)())0x0603AE08)(0x060448C8);

    if (iVar4 < 0) {

      *puVar3 = 1;

    }

    else {

      *puVar3 = 0;

    }

  }

  return;

}
