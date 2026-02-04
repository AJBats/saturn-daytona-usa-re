int FUN_06036a98(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int *param_3;
{

  int uVar1;

  char auStack_20 [2];

  unsigned short uStack_1e;

  unsigned int uStack_1c;

  char local_18 [12];

  (*0x06035E90)(local_18);

  local_18[0] = 0x72;

  uVar1 = (*0x06035EA2)(0,local_18,auStack_20);

  *param_2 = (unsigned int)uStack_1e;

  *param_3 = uStack_1c >> 0x18;

  *param_1 = uStack_1c & 0x00FFFFFF;

  return uVar1;

}
