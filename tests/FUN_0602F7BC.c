void FUN_0602f7bc()
{

  short sVar1;

  int in_r0;

  int iVar2;



  sVar1 = *(short *)(0x0166 + in_r0);

  if (sVar1 != 0) {

    *(short *)(0x0166 + in_r0) = sVar1 + -1;

  }

  sVar1 = *(short *)(0x0152 + in_r0);

  if (sVar1 != 0) {

    *(short *)(0x0152 + in_r0) = sVar1 + -1;

  }

  iVar2 = *(int *)(0x0208 + in_r0);

  if (iVar2 != 0) {

    *(int *)(0x0208 + in_r0) = iVar2 + -1;

  }

  return;

}
