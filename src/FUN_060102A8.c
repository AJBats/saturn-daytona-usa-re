extern int DAT_0601030a;

void FUN_060102a8(param_1)
    unsigned int param_1;
{

  char *puVar1;

  puVar1 = 0x0607EADC;

  if (((param_1 & 0xffff & (unsigned int)0x00008000) != 0) && (*(int *)0x0607EADC < 2)) {

    *(int *)0x0607EADC = *(int *)0x0607EADC + 1;

  }

  if (((param_1 & 0xffff & (int)DAT_0601030a) != 0) && (0 < *(int *)0x0607EADC)) {

    *(int *)puVar1 = *(int *)puVar1 + -1;

  }

  *(int *)0x0607887E = (char)*(int *)puVar1;

  *(int *)0x0607EAD8 = *(int *)puVar1;

  return;

}
