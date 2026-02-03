int FUN_06040eba(param_1)
    int param_1;
{

  if ((-1 < param_1) && (param_1 < 0x18)) {

    if (*(char *)(param_1 + *(int *)0x060A5400 + 0x18) != '\x01') {

      return 0xfffffff9;

    }

    *(char *)(param_1 + *(int *)0x060A5400 + 0x18) = 0;

    return 0;

  }

  return 0xfffffffa;

}
