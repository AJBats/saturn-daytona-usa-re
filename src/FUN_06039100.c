extern int DAT_0603918c;

extern int DAT_0603918e;

extern int PTR_DAT_06039190;

extern int PTR_DAT_06039190;

extern int PTR_DAT_0603923c;

extern int PTR_DAT_0603923c;

unsigned int FUN_06039100(unsigned int param_1,int param_2,unsigned int param_3,int param_4,short param_5,short param_6)
{

  char *puVar1;

  unsigned int uVar2;

  short *psVar3;

  short *psVar4;

  int iVar5;

  int uVar6;

  int iVar7;

  char *puVar8;

  char uStack_24;

  puVar8 = 0x060A3E48;

  puVar1 = 0x0603EDC4;

  param_1 = param_1 & 0xff;

  if (param_1 == 0) {

    *(int *)(0x060A3E48 + 0x18) = 0;

    psVar3 = (short *)(puVar8 + 4);

    uStack_24 = 2;

    iVar5 = (int)DAT_0603918c;

    uVar6 = 1;

    iVar7 = iVar5 + 1;

    psVar4 = (short *)puVar8;

  }

  else {

    if (param_1 != 1) {

      return param_1;

    }

    *(int *)(0x060A3E48 + 0x1c) = 0;

    psVar3 = (short *)(puVar8 + 0xc);

    uStack_24 = 8;

    iVar5 = (int)DAT_0603918e;

    uVar6 = 4;

    iVar7 = iVar5 + 4;

    psVar4 = (short *)(puVar8 + 8);

  }

  puVar8 = puVar8 + 0x10;

  if (0x160 < (int)(unsigned int)*(unsigned short *)0x060635AE) {

    *psVar4 = param_5;

    *psVar3 = param_7;

  }

  else {

    *psVar4 = param_5 << 1;

    *psVar3 = param_7 << 1;

  }

  psVar4[1] = param_6;

  psVar3[1] = param_8;

  if (param_2 != 0 || param_3 != 0) {

    (*(int(*)())puVar1)(param_2,param_3,puVar8,0x80,0x7f);

  }

  if (param_4 != 0 || param_3 != 0) {

    (*(int(*)())puVar1)(param_4,param_3,puVar8,uVar6,iVar7);

  }

  uVar2 = (*(int(*)())puVar1)(param_3,0xffffffff,puVar8,uStack_24,iVar5);

  if ((param_3 & (unsigned int)0x00010000) == 0) {

    *(short *)0x060A3E38 = *(short *)0x060A4C80;

  }

  else {

    *(short *)0x060A3E38 = 3;

  }

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return uVar2;

}
