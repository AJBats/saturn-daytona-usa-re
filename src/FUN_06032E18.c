void FUN_06032e18(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  int unaff_r14;

  *(int *)(unaff_r14 + 0x000002D0) = param_1;

  iVar2 = *(int *)((int)(0x060627F8 + param_1 * 8) + 4);

  *(int *)(unaff_r14 + 0x000002CC) = *(int *)(0x060627F8 + param_1 * 8);

  *(int *)(unaff_r14 + 0x000002C8) = iVar2;

  iVar1 = 0x00000001;

  if ((0x00000002 & (int)*(short *)(unaff_r14 + 0x0000000E)) != 0) {

    iVar1 = iVar2 + -1;

  }

  *(int *)(unaff_r14 + 0x000002C4) = iVar1;

  return;

}
