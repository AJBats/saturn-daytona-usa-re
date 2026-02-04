int FUN_060283b8(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    unsigned int param_4;
{
  int iVar3;
  int iVar4;

  iVar4 = 0x10;
  iVar3 = **(int **)(0x06028614 + param_1);
  do {
    iVar4 -= 2;
    *(unsigned short *)(iVar3 + param_2 + iVar4) = (param_4 & 0xf) + param_3;
    param_4 >>= 4;
  } while (iVar4);
  return 0;
}
