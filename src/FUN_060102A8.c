extern short DAT_0601030a;

void FUN_060102a8(param_1)
    unsigned int param_1;
{
  int val;
  unsigned short p = param_1;

  if ((p & 0x8000) != 0 && *(int *)0x0607EADC < 2) {
    *(int *)0x0607EADC = *(int *)0x0607EADC + 1;
  }

  if ((p & DAT_0601030a) != 0 && *(int *)0x0607EADC > 0) {
    *(int *)0x0607EADC = *(int *)0x0607EADC - 1;
  }

  val = *(int *)0x0607EADC;
  *(char *)0x0607887E = (char)val;
  *(int *)0x0607EAD8 = val;
}
