extern int DAT_0600cac2;

extern int DAT_0600cb84;

extern int DAT_0600cb86;

extern int PTR_DAT_0600cb88;

extern int PTR_DAT_0600cb88;

void FUN_0600ca96(param_1)
    int *param_1;
{

  int iVar1;

  int *piVar2;

  int iVar3;

  unsigned int uVar4;

  int *piVar5;

  unsigned int uVar6;

  iVar1 = *(int *)0x0607E940;

  iVar3 = *(int *)(iVar1 + DAT_0600cac2) - *(int *)(iVar1 + DAT_0600cac2 + 4);

  if ((iVar3 < 8) && (-8 < iVar3)) {

    *(int *)(iVar1 + DAT_0600cac2 + 4) = *(int *)(iVar1 + DAT_0600cac2);

  }

  else if (iVar3 < 1) {

    *(int *)(iVar1 + DAT_0600cb84) = *(int *)(iVar1 + DAT_0600cb84) + -4;

  }

  else {

    *(int *)(iVar1 + DAT_0600cb84) = *(int *)(iVar1 + DAT_0600cb84) + 4;

  }

  uVar6 = (*(unsigned int *)(iVar1 + DAT_0600cb84) & (int)DAT_0600cb86 & 0xffff) >> 6;

  uVar4 = (*(unsigned int *)(iVar1 + DAT_0600cb84) & 0xffff) >> 8;

  if ((uVar6 == 0) || (6 < uVar4)) {

    piVar2 = (int *)((uVar4 + *(int *)(iVar1 + PTR_DAT_0600cb88) << 3) << 4 +

                    *(int *)0x0607EB88);

    *param_1 = *piVar2;

    param_1[2] = piVar2[1];

  }

  else {

    iVar1 = uVar4 + *(int *)(iVar1 + PTR_DAT_0600cb88) << 3;

    piVar2 = (int *)((iVar1 << 4) + *(int *)0x0607EB88);

    piVar5 = (int *)((iVar1 + 1) << 4 + *(int *)0x0607EB88);

    *param_1 = (int)(*piVar2 * (4 - uVar6) + *piVar5 * uVar6) >> 2;

    param_1[2] = (int)(piVar2[1] * (4 - uVar6) + piVar5[1] * uVar6) >> 2;

  }

  *(short *)(param_1 + 3) = *(short *)(piVar2 + 2);

  *(short *)((int)param_1 + 0xe) = *(short *)((int)piVar2 + 10) << 2;

  *(short *)(param_1 + 4) = *(short *)(piVar2 + 3);

  *(short *)((int)param_1 + 0x12) = 0;

  return;

}
