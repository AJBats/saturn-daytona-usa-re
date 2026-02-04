int FUN_060415c8(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  int local_24;

  int iStack_20;

  int iStack_1c;

  char auStack_18 [4];

  int uStack_14;

  char local_10 [16];

  iStack_1c = param_1;

  uStack_14 = param_2;

  iVar1 = (*0x06036A98)(&local_24,&iStack_20,auStack_18);

  if (iVar1 != 0) {

    return 0xfffffff5;

  }

  if ((local_24 == 2) && (iStack_1c < iStack_20 + 2)) {

    iVar1 = (*0x06036AF2)(iStack_1c,uStack_14);

    if (iVar1 != 0) {

      return 0xfffffff5;

    }

    (*0x060349B6)(local_10);

    *(char *)(*(int *)0x060A5400 + 0x40) = local_10[0];

    return 0;

  }

  return 0xfffffff5;

}
