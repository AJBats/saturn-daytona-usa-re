void FUN_060280f8(param_1, param_2)
    int param_1;
    short *param_2;
{

  unsigned short uVar1;

  short sVar2;

  int uVar3;

  int *puVar4;

  int uVar5;

  int uVar6;

  uVar1 = *(unsigned short *)

           (0x060684EC +

           ((int)*(short *)(param_1 + 6) + (((unsigned int)*(unsigned char *)(param_1 + 5) << 8) >> 2)) << 1);

  sVar2 = *(short *)(0x06063F64 + (unsigned int)(uVar1 << 3) + 6);

  *param_2 = (short)*(int *)(0x06028178 + ((int)*(char *)(param_1 + 4) & 0xc));

  param_2[2] = *(short *)(0x06028174 + ((int)*(char *)(param_1 + 4) & 1U) << 1);

  param_2[3] = (short)*(int *)0x06059FFC + sVar2;

  puVar4 = (int *)(0x06063F64 + (unsigned int)(uVar1 << 3));

  uVar3 = *(int *)(param_1 + 0x14);

  param_2[4] = (short)*puVar4;

  uVar6 = *(int *)(param_1 + 0x10);

  param_2[5] = *(short *)(puVar4 + 1);

  uVar5 = *(int *)(param_1 + 0xc);

  *(int *)(param_2 + 6) = *(int *)(param_1 + 8);

  *(int *)(param_2 + 8) = uVar5;

  *(int *)(param_2 + 10) = uVar6;

  *(int *)(param_2 + 0xc) = uVar3;

  return;

}
