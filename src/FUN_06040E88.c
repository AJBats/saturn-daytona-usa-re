int FUN_06040e88(param_1)
    int *param_1;
{

  int iVar1;

  

  iVar1 = 0;

  do {

    if (*(char *)(*(int *)0x060A5400 + 0x18 + iVar1) == '\0') {

      *(char *)(*(int *)0x060A5400 + 0x18 + iVar1) = 1;

      *param_1 = iVar1;

      return 0;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x18);

  *param_1 = -1;

  return 0xfffffffd;

}
