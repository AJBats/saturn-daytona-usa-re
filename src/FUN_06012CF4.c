void FUN_06012cf4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int in_r7;

  int iVar5;

  int uVar6;

  puVar2 = 0x0600026C;

  puVar1 = 0x0603AC1C;

  uVar6 = 0xffffffff;

  iVar5 = 0;

  *(int *)0x06084AEC = 0;

  puVar3 = 0x06084360;

  *(int *)0x06084360 = 1;

  *(char **)(puVar3 + 8) = 0x0608436C;

  *(int *)(puVar3 + 4) = 0x50;

  puVar3 = 0x06083274;

  do {

    iVar4 = (*(void(*)())puVar1)(5,puVar3,0x06084360,in_r7,uVar6);

    iVar5 = iVar5 + 1;

    if (4 < iVar5) {

      (**(void **)puVar2)();

    }

  } while (iVar4 < 3);

  return;

}
