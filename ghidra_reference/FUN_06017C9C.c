unsigned int FUN_06017c9c(param_1)
    short *param_1;
{

  unsigned int uVar1;

  uVar1 = (*(int(*)())0x06035C2C)();

  if ((uVar1 & 0xffff) < 4) {

    *param_1 = *param_1 - (short)uVar1;

  }

  else {

    *param_1 = (*param_1 - (short)uVar1) + 6;

  }

  return uVar1;

}
