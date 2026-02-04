int FUN_06036af2(param_1, param_2)
    unsigned int param_1;
    int param_2;
{

  int iVar1;

  unsigned int local_1c [2];

  char local_14 [4];

  unsigned int uStack_10;

  (*0x06035E90)(local_14);

  local_14[0] = 0x73;

  uStack_10 = (unsigned int)param_1;

  iVar1 = (*0x06035EA2)(0,local_14,local_1c);

  if (iVar1 == 0) {

    iVar1 = (*0x06035CBC)(local_1c[0] & 0x00FFFFFF,param_2);

  }

  return iVar1;

}
