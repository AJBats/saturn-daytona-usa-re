int FUN_06041258()
{

  char *puVar1;

  int iVar2;

  char local_14 [16];

  puVar1 = 0x060A5400;

  if (*(int *)(*(int *)0x060A5400 + 0x34) == 0) {

    return 0xfffffff9;

  }

  iVar2 = (*0x06034CC8)();

  *(int *)(*(int *)puVar1 + 0x34) = 0;

  if (iVar2 != 0) {

    return 0xfffffff6;

  }

  (*ram0x06041308)(local_14);

  *(char *)(*(int *)puVar1 + 0x40) = local_14[0];

  return 0;

}
