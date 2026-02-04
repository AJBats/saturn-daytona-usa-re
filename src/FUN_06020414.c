extern int DAT_060204a8;

void FUN_06020414(param_1, param_2, param_3, param_4)
    char param_1;
    unsigned int param_2;
    unsigned int param_3;
    int param_4;
{

  unsigned short uVar1;

  char *puVar2;

  short sVar3;

  short *psVar4;

  int iVar5;

  short *psVar6;

  unsigned int uVar7;

  puVar2 = 0x0605F44E;

  uVar7 = 0;

  iVar5 = 0x3c79;

  psVar6 = (short *)(0x0605F44E + 4);

  psVar4 = (short *)(0x0605F44E + 6);

  if ('\0' < param_1) {

    do {

      uVar1 = *(unsigned short *)(param_4 + (uVar7 & 0xff) << 1);

      if ((char)uVar1 == ' ') {

        *psVar6 = 0;

        *psVar4 = 0;

      }

      else {

        sVar3 = ((uVar1 & 0xff) - 0x40) << 1;

        *psVar6 = sVar3;

        *psVar4 = sVar3 + 1;

      }

      (*(int(*)())0x06028400)(8,puVar2,((param_2 & 0xffff) + (param_3 & 0xffff) << 6) << 1,iVar5);

      uVar7 = uVar7 + 1;

      param_2 = param_2 + 1;

    } while ((int)(uVar7 & 0xff) < (int)param_1);

  }

  return;

}
