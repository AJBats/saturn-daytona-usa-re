int FUN_06034cc8(param_1)
    unsigned int *param_1;
{

  int uVar1;

  unsigned int local_18 [2];

  char local_10 [12];

  (*(void(*)())0x06035E90)(local_10);

  local_10[0] = 6;

  uVar1 = (*(void(*)())0x06035EA2)(0,local_10,local_18);

  *param_1 = local_18[0] & 0x00FFFFFF;

  return uVar1;

}
