int FUN_0602aebe(param_1, param_2, param_3, UNRECOVERED_JUMPTABLE)
    int param_1;
    int *param_2;
    int param_3;
    void *UNRECOVERED_JUMPTABLE;
{

  unsigned int in_r0;

  int iVar1;

  int iVar2;

  int unaff_r9;

  int *unaff_r11;

  int *piVar3;

  piVar3 = (int *)(0x06094220 + (in_r0 & 0x3f) << 4);

  iVar1 = *piVar3;

  if ((-1 < iVar1) && (unaff_r9 == iVar1)) {

    iVar1 = piVar3[2];

    iVar2 = piVar3[3];

    *unaff_r11 = piVar3[1];

    unaff_r11[1] = iVar1;

    *param_2 = iVar2;

    iVar1 = (*(int(*)())UNRECOVERED_JUMPTABLE)(param_1,param_2 + 1);

    return iVar1;

  }

  return iVar1;

}
