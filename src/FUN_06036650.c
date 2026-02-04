int FUN_06036650(param_1, param_2)
    int param_1;
    int param_2;
{

  unsigned int uVar1;

  int uVar2;

  uVar1 = (*0x06035C4E)();

  if ((uVar1 & 0x40) == 0) {

    uVar2 = 0xffffffff;

  }

  else {

    uVar2 = (*0x06035EA2)(0,param_1,param_2);

  }

  return uVar2;

}
