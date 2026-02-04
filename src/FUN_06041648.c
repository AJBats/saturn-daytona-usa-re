int FUN_06041648()
{

  int iVar1;

  int local_1c;

  char auStack_18 [4];

  char auStack_14 [4];

  char local_10 [16];

  iVar1 = (*0x06036518)(auStack_18,auStack_14,&local_1c);

  if (iVar1 != 0) {

    return 0xfffffff6;

  }

  (*ram0x0604172c)(local_10);

  *(char *)(*(int *)0x060A5400 + 0x40) = local_10[0];

  return local_1c;

}
