extern int DAT_0602f7e4;

extern int DAT_0602f7e6;

extern int DAT_0602f7e8;

void FUN_0602f7bc()
{

  short sVar1;

  int in_r0;

  int iVar2;

  sVar1 = *(short *)(DAT_0602f7e4 + in_r0);

  if (sVar1 != 0) {

    *(short *)(DAT_0602f7e4 + in_r0) = sVar1 + -1;

  }

  sVar1 = *(short *)(DAT_0602f7e6 + in_r0);

  if (sVar1 != 0) {

    *(short *)(DAT_0602f7e6 + in_r0) = sVar1 + -1;

  }

  iVar2 = *(int *)(DAT_0602f7e8 + in_r0);

  if (iVar2 != 0) {

    *(int *)(DAT_0602f7e8 + in_r0) = iVar2 + -1;

  }

  return;

}
