unsigned short FUN_0603931c(param_1, param_2, param_3)
    unsigned short param_1;
    unsigned short param_2;
    short param_3;
{

  char *puVar1;

  short *psVar2;

  puVar1 = 0x060A4C8C;

  *(unsigned short *)0x060A4C90 = param_1 & 7;

  *(unsigned short *)0x25D00000 = param_1 & 7;

  if (7 < param_2) {

    param_2 = 0;

  }

  psVar2 = (short *)(0x060635E0 + (unsigned int)param_2 * 4);

  *(int *)0x060A4C88 = (int)*psVar2;

  *(int *)puVar1 = (int)psVar2[1];

  if (param_3 == 1) {

    *(int *)puVar1 = *(int *)puVar1 << 1;

  }

  if ((param_1 == 1) || (param_1 == 3)) {

    *(short *)0x060635DE = 1;

  }

  else {

    *(short *)0x060635DE = 0;

  }

  if (param_3 == 0) {

    *(short *)0x060A4C94 = 0;

  }

  else {

    *(short *)0x060A4C94 = 8;

  }

  *(short *)0x060A4C96 = 0;

  return param_1;

}
