unsigned int FUN_06035340()
{

  unsigned int in_r0;

  unsigned int uVar1;

  int in_r1;

  if (in_r1 < 0) {

    return in_r0;

  }

  if (in_r1 < 0x20) {

    if (((in_r0 & 0x80000000) == 0) && (8 < in_r1)) {

      uVar1 = (*(int(*)())0x06036068)();

      return uVar1;

    }

    uVar1 = (*(int(*)())(0x060353BE + (char)((int *)0x06035338)[in_r1 + -0x18]))();

    return uVar1;

  }

  if ((in_r0 & 0x80000000) == 0) {

    return 0;

  }

  return 0xffffffff;

}
