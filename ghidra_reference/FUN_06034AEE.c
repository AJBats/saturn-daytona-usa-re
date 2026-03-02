int FUN_06034aee(param_1)
    int param_1;
{

  int iVar1;

  unsigned int local_18 [2];

  char local_10 [12];

  (*(int(*)())0x06035E90)(local_10);

  local_10[0] = 2;

  iVar1 = (*(int(*)())0x06035EA2)(0,local_10,local_18);

  if (iVar1 != 0) {

    return iVar1;

  }

  iVar1 = (*(int(*)())0x06035CBC)(local_18[0] & 0x00FFFFFF,param_1);

  return iVar1;

}
