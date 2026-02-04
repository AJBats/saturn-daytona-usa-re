extern int DAT_06038a9a;

extern int DAT_06038a9e;

unsigned int FUN_06038a64(param_1)
    unsigned int param_1;
{

  unsigned short uVar1;

  if (param_1 == 0) {

    uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a;

  }

  else if (param_1 == 1) {

    uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a | 0x10002000;

  }

  else {

    if (param_1 != 2) goto LAB_06038ab0;

    uVar1 = *(unsigned short *)(0x060A3D88 + 0xe) & DAT_06038a9a | DAT_06038a9e;

  }

  param_1 = (unsigned int)uVar1;

  *(unsigned short *)(0x060A3D88 + 0xe) = uVar1;

LAB_06038ab0:

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return param_1;

}
