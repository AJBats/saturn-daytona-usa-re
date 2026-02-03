extern void FUN_06035c6e();

void FUN_06035c54(param_1)
    unsigned int param_1;
{

  *(unsigned short *)0x06063590 = *(unsigned short *)0x06063590 | *(unsigned short *)0x25890008;

  FUN_06035c6e(param_1 | 1);

  return;

}
