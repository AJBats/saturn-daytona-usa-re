extern int FUN_06036650();

int FUN_0603660e(param_1)
    unsigned int *param_1;
{

  int uVar1;

  unsigned int local_18 [2];

  char local_10 [12];

  (*(int(*)())0x06035E90)(local_10);

  local_10[0] = 0x53;

  uVar1 = FUN_06036650(local_10,local_18);

  *param_1 = local_18[0] & 0x00FFFFFF;

  return uVar1;

}
