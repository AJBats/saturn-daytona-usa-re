int FUN_06034a10(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  int local_24;

  int iStack_20;

  puVar1 = 0x06035E5E;

  iVar2 = 0;

  while( true ) {

    (*puVar1)(param_1);

    (*puVar1)(&local_24);

    if ((*param_1 == local_24) && (param_1[1] == iStack_20)) break;

    iVar2 = iVar2 + 1;

    if (99 < iVar2) {

      return 0xfffffffd;

    }

  }

  return 0;

}
