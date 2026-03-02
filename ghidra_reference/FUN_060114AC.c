extern int DAT_060115c6;

extern int FUN_060116a8();
extern int FUN_06011978();

unsigned int FUN_060114ac(param_1)
    unsigned int param_1;
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  int *puVar4;

  short *psVar5;

  puVar1 = 0x06078860;

  iVar3 = *(int *)(0x060447A8 + *(int *)(0x0607EADC << 2) + (param_1 & 0xffff) << 4) -

          *(int *)0x06078860;

  *(int *)0x06078860 = *(int *)0x06078860 + ((int)(iVar3 + (unsigned int)(iVar3 < 0)) >> 1);

  if (((*(int *)0x0607887F == '\x03') || (*(int *)0x0607887F == '\v')) &&

     ((*(unsigned int *)0x0607EBC8 & 1) != 0)) {

    return *(unsigned int *)0x0607EBC8;

  }

  psVar5 = (short *)(0x060447A4 + (param_1 & 0xffff) << 1);

  puVar4 = (int *)(0x060447A8 + (param_1 & 0xffff) << 4 + 0xc);

  FUN_060116a8(*(int *)puVar1,*puVar4,(int)DAT_060115c6,0x00010000,(int)*psVar5);

  FUN_06011978(0x06044764,*(int *)puVar1,*puVar4,(int)*psVar5);

  uVar2 = FUN_06011978(0x06044784,*(int *)puVar1,*puVar4,(int)*psVar5);

  return uVar2;

}
