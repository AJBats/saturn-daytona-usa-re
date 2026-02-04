extern int DAT_0603c07a;

extern int DAT_0603c07c;

void FUN_0603c000()
{

  int *puVar1;

  unsigned int uVar2;

  int *puVar3;

  unsigned char *pbVar4;

  int iVar5;

  unsigned int uVar6;

  puVar1 = 0x60000000;

  uVar6 = (unsigned int)DAT_0603c07a;

  pbVar4 = (unsigned char *)-366;

  *pbVar4 = *pbVar4 & 0xfe;

  uVar2 = 0;

  do {

    *pbVar4 = *pbVar4 & 0x3f | (unsigned char)uVar2;

    iVar5 = 0x40;

    puVar3 = puVar1;

    do {

      iVar5 = iVar5 + -2;

      *puVar3 = 0;

      puVar3[4] = 0;

      puVar3 = puVar3 + 8;

    } while (iVar5 != 0);

    uVar2 = uVar2 + 0x40;

  } while (uVar2 < uVar6);

  *pbVar4 = *pbVar4 & 0xfe | 1;

  return;

}
