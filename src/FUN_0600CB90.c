extern int DAT_0600cc2a;

void FUN_0600cb90(param_1, param_2)
    int *param_1;
    unsigned int param_2;
{

  unsigned int uVar1;

  int *piVar2;

  unsigned int uVar3;

  int *piVar4;

  if ((param_2 & 1) == 0) {

    piVar2 = (int *)(((*(unsigned int *)(*(int *)0x0607E940 + 0x1f8) >> 8) +

                     ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);

    *param_1 = *piVar2;

    param_1[2] = piVar2[1];

  }

  else {

    uVar3 = ((param_2 & 0xffff) >> 1) + 1;

    if (*(unsigned int *)0x0607EA9C < uVar3) {

      uVar3 = 0;

    }

    uVar1 = *(unsigned int *)(*(int *)0x0607E940 + 0x1f8) >> 8;

    piVar2 = (int *)((uVar1 + ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);

    piVar4 = (int *)((uVar1 + (uVar3 << 3)) << 4 + *(int *)0x0607EB88);

    *param_1 = *piVar2 + *piVar4 >> 1;

    param_1[2] = piVar2[1] + piVar4[1] >> 1;

  }

  *(short *)(param_1 + 3) = *(short *)(piVar2 + 2);

  *(short *)((int)param_1 + 0xe) = *(short *)((int)piVar2 + 10) << 2;

  *(short *)(param_1 + 4) = *(short *)(piVar2 + 3);

  *(short *)((int)param_1 + 0x12) = 0;

  return;

}
