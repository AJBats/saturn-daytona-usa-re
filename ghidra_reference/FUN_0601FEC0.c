extern int DAT_0601ff8a;

extern int DAT_0601ff8c;

extern int DAT_0601ff8e;

extern int DAT_0601ff90;

extern int DAT_0601ff92;

void FUN_0601fec0(param_1)
    unsigned short *param_1;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  int iVar5;

  int iVar6;

  puVar2 = 0x06078680;

  iVar3 = (int)DAT_0601ff8a;

  iVar6 = *(int *)0x0607E940;

  iVar5 = (int)(unsigned int)*param_1 >> 1;

  *(int *)(iVar6 + iVar3) = iVar5;

  *(int *)(iVar6 + iVar3 + 4) = iVar5;

  *(int *)(iVar6 + iVar3 + -4) = iVar5;

  *(int *)(iVar6 + iVar3 + -8) = iVar5;

  uVar1 = param_1[1];

  *(unsigned int *)(iVar6 + 8) = (unsigned int)uVar1;

  uVar4 = (*(int(*)())0x06027552)(0x35a,(unsigned int)uVar1 << 0x10);

  *(int *)(iVar6 + 0xc) = uVar4;

  *(int *)(iVar6 + DAT_0601ff8e) = uVar4;

  uVar1 = param_1[2];

  iVar3 = (int)DAT_0601ff90;

  *(unsigned int *)(iVar6 + iVar3) = (unsigned int)uVar1;

  *(unsigned int *)(iVar6 + iVar3 + -4) = (unsigned int)uVar1;

  (*(int(*)())0x0600CB90)(puVar2,*param_1);

  *(int *)(iVar6 + 0x10) = *(int *)puVar2;

  *(int *)(iVar6 + 0x14) = *(int *)(puVar2 + 4);

  *(int *)(iVar6 + 0x18) = *(int *)(puVar2 + 8);

  *(int *)(iVar6 + 0x1c) = (int)*(short *)(puVar2 + 0xc);

  *(int *)(iVar6 + 0x20) = (int)*(short *)(puVar2 + 0xe);

  *(int *)(iVar6 + 0x24) = (int)*(short *)(puVar2 + 0x10);

  *(int *)(iVar6 + 0x30) = *(int *)(iVar6 + 0x20);

  *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x20);

  iVar3 = 0x1b0;

  *(int *)(iVar6 + iVar3) = *(int *)(iVar6 + 0x20);

  *(int *)(iVar6 + iVar3 + -0xc) = *(int *)(iVar6 + 0x1c);

  *(int *)(iVar6 + iVar3 + -8) = *(int *)(iVar6 + 0x20);

  *(int *)(iVar6 + iVar3 + -4) = *(int *)(iVar6 + 0x24);

  iVar3 = iVar3 + 0x3c;

  *(int *)(iVar6 + iVar3) = *(int *)(iVar6 + iVar3) + 1;

  if (*(int *)0x0607EA9C < *(int *)(iVar6 + iVar3)) {

    *(int *)(iVar6 + DAT_0601ff8a) = *(int *)(iVar6 + DAT_0601ff8a) - *(int *)0x0607EA9C;

  }

  *(int *)(iVar6 + DAT_0601ff8a + -8) = *(int *)(iVar6 + DAT_0601ff8a);

  return;

}
