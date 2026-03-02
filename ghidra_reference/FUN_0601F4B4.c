extern int DAT_0601f5c6;

void FUN_0601f4b4(param_1)
    char *param_1;
{

  unsigned char bVar1;

  unsigned char bVar2;

  unsigned char bVar3;

  unsigned char bVar4;

  int iVar5;

  iVar5 = *(int *)0x060A4C98;

  *(int *)0x060877E4 = iVar5;

  bVar1 = *(unsigned char *)(iVar5 + 1);

  bVar2 = *(unsigned char *)(iVar5 + 2);

  bVar3 = *(unsigned char *)(iVar5 + 3);

  bVar4 = *(unsigned char *)(iVar5 + 4);

  *param_1 = (char)DAT_0601f5c6 +

             (char)((int)(unsigned int)*(unsigned char *)(iVar5 + 5) >> 4) * '\n' + (*(unsigned char *)(iVar5 + 5) & 0xf) +

             (char)((int)(unsigned int)*(unsigned char *)(iVar5 + 6) >> 4) * (char)0x03E8F844 +

             (*(unsigned char *)(iVar5 + 6) & 0xf) * 'd';

  param_1[1] = bVar4 & 0xf;

  param_1[5] = (char)((int)(unsigned int)bVar4 >> 4);

  param_1[2] = (bVar3 & 0xf) + (char)((int)(unsigned int)bVar3 >> 4) * '\n';

  param_1[3] = (bVar2 & 0xf) + (char)((int)(unsigned int)bVar2 >> 4) * '\n';

  param_1[4] = (bVar1 & 0xf) + (char)((int)(unsigned int)bVar1 >> 4) * '\n';

  return;

}
