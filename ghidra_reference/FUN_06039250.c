extern int DAT_060392e6;

extern int PTR_DAT_060392e8;

extern int PTR_DAT_060392e8;

extern int FUN_0603931c();
extern int FUN_060393fc();
extern int FUN_060394f0();

unsigned int FUN_06039250(param_1)
    int *param_1;
{

  char *puVar1;

  unsigned int uVar2;

  unsigned int in_sr;

  unsigned int uVar3;

  uVar3 = in_sr & -241 & 0xfff0fff | 0xf0;

  FUN_060394f0(0);

  FUN_0603931c(0,0,0);

  *(short *)0x25D00002 = *(short *)0x060A4C92;

  *(short *)0x25D00004 = 2;

  *(short *)0x25D00006 = (short)0x00008000;

  *(short *)0x25D00008 = 0;

  *(short *)0x25D0000A = (short)0x0000FFFF;

  FUN_060393fc(0x00008000,0,0,*(int *)0x060A4C88 - 1U & 0xffff,

               *(int *)0x060A4C8C - 1U & 0xffff);

  puVar1 = 0x25C00000;

  *param_1 = (int)0x25C00000;

  *puVar1 = (char)PTR_DAT_060392e8;

  *(char *)(*param_1 + 1) = 0;

  uVar2 = (unsigned int)DAT_060392e6;

  *(int *)0x060635CC = 1;

  return (in_sr >> 4 & 0xf) << 4 | uVar3 & uVar2;

}
