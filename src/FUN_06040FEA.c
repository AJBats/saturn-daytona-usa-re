int FUN_06040fea(param_1)
    int param_1;
{

  if (*(int *)(*0x060A5400 + 0x30) == 0) {

    return 0xfffffff9;

  }

  if (*(int *)(*0x060A5400 + 0x38) != param_1) {

    return 0xfffffff7;

  }

  *(int *)(*0x060A5400 + 0x30) = 0;

  return 0;

}
