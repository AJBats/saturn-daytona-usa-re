extern int DAT_0603bff8;

extern int DAT_0603bffa;

void FUN_0603bf7c(param_1)
    unsigned char param_1;
{

  int *puVar1;

  int iVar2;

  unsigned char *pbVar3;

  int *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  puVar1 = 0x60000000;

  uVar5 = (unsigned int)DAT_0603bff8;

  pbVar3 = (unsigned char *)(int)DAT_0603bffa;

  *pbVar3 = *pbVar3 & 0xfe;

  uVar6 = 0;

  do {

    *pbVar3 = *pbVar3 & 0x3f | (unsigned char)uVar6;

    iVar2 = 0x40;

    puVar4 = puVar1;

    do {

      *puVar4 = 0;

      iVar2 = iVar2 + -2;

      puVar4[4] = 0;

      puVar4 = puVar4 + 8;

    } while (iVar2 != 0);

    uVar6 = uVar6 + 0x40;

  } while (uVar6 < uVar5);

  *pbVar3 = *pbVar3 & 0xf7 | param_1;

  *pbVar3 = *pbVar3 & 0xfd;

  *pbVar3 = *pbVar3 & 0xfb;

  *pbVar3 = *pbVar3 & 0xfe | 1;

  return;

}
