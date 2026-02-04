extern int DAT_0600ccf6;

extern int DAT_0600ccf8;

extern int DAT_0600ccfa;

extern int DAT_0600cdbc;

void FUN_0600cc38(param_1, param_2)
    int param_1;
    int *param_2;
{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  iVar2 = *(int *)0x0607E940;

  iVar4 = *(int *)(iVar2 + DAT_0600ccf6) - *(int *)(iVar2 + DAT_0600ccf6 + 4);

  if ((iVar4 < 8) && (-8 < iVar4)) {

    *(int *)(iVar2 + DAT_0600ccf6 + 4) = *(int *)(iVar2 + DAT_0600ccf6);

  }

  else if (iVar4 < 1) {

    *(int *)(iVar2 + DAT_0600ccf8) = *(int *)(iVar2 + DAT_0600ccf8) + -8;

  }

  else {

    *(int *)(iVar2 + DAT_0600ccf8) = *(int *)(iVar2 + DAT_0600ccf8) + 8;

  }

  *(int *)(iVar2 + DAT_0600ccf6) = (int)*(short *)(param_1 + 0x14);

  uVar6 = (unsigned int)((*(unsigned short *)(param_1 + 0x14) & 0xff) >> 6);

  uVar5 = (unsigned int)(*(unsigned short *)(param_1 + 0x14) >> 8);

  if ((uVar6 == 0) || (6 < uVar5)) {

    piVar1 = (int *)((uVar5 + *(int *)(iVar2 + DAT_0600cdbc) << 3) << 4 + *(int *)0x0607EB88)

    ;

    *param_2 = *piVar1;

    param_2[2] = piVar1[1];

  }

  else {

    iVar2 = uVar5 + *(int *)(iVar2 + DAT_0600ccfa) << 3;

    piVar1 = (int *)((iVar2 << 4) + *(int *)0x0607EB88);

    piVar3 = (int *)((iVar2 + 1) << 4 + *(int *)0x0607EB88);

    *param_2 = (int)(*piVar1 * (4 - uVar6) + *piVar3 * uVar6) >> 2;

    param_2[2] = (int)(piVar1[1] * (4 - uVar6) + piVar3[1] * uVar6) >> 2;

  }

  *(short *)(param_2 + 3) = *(short *)(param_1 + 0xc);

  *(short *)((int)param_2 + 0xe) = *(short *)(param_1 + 0xe) << 2;

  *(short *)(param_2 + 4) = *(short *)(param_1 + 0x10);

  *(short *)((int)param_2 + 0x12) = *(short *)(param_1 + 0x12);

  return;

}
