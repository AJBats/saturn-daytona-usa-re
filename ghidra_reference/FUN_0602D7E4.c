extern int PTR_DAT_0602d80c;

extern int PTR_DAT_0602d80c;

void FUN_0602d7e4()
{

  short sVar1;

  int in_r0;

  short sVar2;

  if ((0 < *(int *)(in_r0 + 8)) && (sVar1 = *(short *)(PTR_DAT_0602d80c + in_r0), sVar1 < 4))

  {

    sVar2 = (short)0x0000000A;

    if (sVar1 != 0) {

      sVar2 = sVar2 + -3;

    }

    *(short *)(PTR_DAT_0602d80c + in_r0) = sVar2;

  }

  return;

}
