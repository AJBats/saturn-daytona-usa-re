int FUN_06040722(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  int extraout_r3;

  if (*(char *)(param_1 + 0x1e) == '\0') {

    return param_2;

  }

  (*(void(*)())0x06034FFC)(param_1,param_2,*(char *)(param_1 + 0x1e));

  iVar1 = (*(void(*)())0x06036BE4)();

  return iVar1 + extraout_r3;

}
