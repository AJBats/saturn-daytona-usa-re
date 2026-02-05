void FUN_06007590(param_1, param_2)
    unsigned short *param_1;
    short param_2;
{
  int idx;
  unsigned short uVar3;
  int *cnt = (int *)0x0606A4F4;

  uVar3 = *(unsigned short *)(0x060684EC + (unsigned int)param_1[1] * 2);

  *(short *)(0x060684EC + ((unsigned int)*param_1 << 1)) = (short)*cnt;

  idx = *cnt << 3;

  *(int *)(0x06063F64 + idx) = *(int *)(0x06063F64 + (unsigned int)(uVar3 << 3));

  *(short *)(0x06063F64 + idx + 4) = *(short *)(0x06063F64 + (unsigned int)(uVar3 << 3) + 4);

  if (param_1[1] < 0xd) {
    uVar3 = param_1[2];
  }
  else {
    uVar3 = param_1[2] + (param_2 << 2);
  }

  *(unsigned short *)(0x06063F64 + idx + 6) = uVar3;

  *cnt = *cnt + 1;
}
