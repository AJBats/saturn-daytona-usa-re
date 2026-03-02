void FUN_060393fc(param_1, param_2, param_3, param_4, param_5)
    short param_1;
    unsigned short param_2;
    unsigned short param_3;
    short param_4;
    unsigned short param_5;
{

  unsigned short uVar1;

  *(short *)0x060635D4 = param_1;

  *(unsigned short *)0x060635D6 = param_2;

  *(unsigned short *)0x060635D8 = param_3;

  *(short *)0x060635DA = param_4;

  *(unsigned short *)0x060635DC = param_5;

  *(short *)0x25D00006 = param_1;

  if (*(short *)0x060635DE == 0) {

    param_2 = param_2 >> 3;

  }

  else {

    param_2 = param_2 >> 4;

  }

  if (*(short *)0x060A4C94 != 0) {

    param_3 = param_3 >> 1;

  }

  *(unsigned short *)0x060635D0 = (param_2 << 9) + param_3;

  *(short *)0x25D00008 = *(short *)0x060635D0;

  if (*(short *)0x060635DE == 0) {

    uVar1 = (unsigned short)(param_4 + 1U) >> 3;

  }

  else {

    uVar1 = (unsigned short)(param_4 + 1U) >> 4;

  }

  if (*(short *)0x060A4C94 != 0) {

    param_5 = param_5 >> 1;

  }

  *(unsigned short *)0x060635D2 = (uVar1 << 9) + param_5;

  *(short *)0x25D0000A = *(short *)0x060635D2;

  return;

}
