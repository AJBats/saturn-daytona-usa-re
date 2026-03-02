extern int DAT_0600e2ba;

extern int DAT_0600e2bc;

extern int DAT_0600e2be;

extern int DAT_0600e2c0;

extern int DAT_0600e2c2;

extern int DAT_0600e2c4;

extern int DAT_0600e2c6;

extern int DAT_0600e2c8;

extern int DAT_0600e2ca;

extern int DAT_0600e3e8;

extern int DAT_0600e3ea;

extern int DAT_0600e3ec;

extern int DAT_0600e3ee;

extern int DAT_0600e3f0;

extern int DAT_0600e3f2;

extern int DAT_0600e3f4;

extern int DAT_0600e3f6;

extern int PTR_DAT_0600e3f8;

extern int PTR_DAT_0600e3f8;

void FUN_0600e1d4()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  unsigned int uVar7;

  int *puVar8;

  int iVar9;

  char auStack_1c [8];

  puVar3 = 0x06078680;

  puVar2 = 0x0607EAD8;

  iVar9 = *(int *)0x0607E940;

  *(int *)(iVar9 + DAT_0600e2ba) = 0;

  puVar8 = (int *)(0x06047DE4 + *(int *)(iVar9 + 4) * 0xc);

  uVar1 = *(unsigned short *)((int)puVar8 + 6);

  iVar4 = 0x1f0;

  *(unsigned int *)(iVar9 + iVar4) = (unsigned int)uVar1;

  *(unsigned int *)(iVar9 + iVar4 + -8) = (unsigned int)uVar1;

  uVar5 = (*(int(*)())0x06035C2C)();

  *(int *)(DAT_0600e2be + iVar9) = uVar5;

  *(int *)(iVar9 + DAT_0600e2c0) =

       *(int *)(0x06085FD0 + (unsigned int)*(unsigned short *)(puVar8 + 1) << 2);

  *(unsigned int *)(iVar9 + DAT_0600e2c2) = (unsigned int)*(unsigned short *)(puVar8 + 2);

  uVar7 = (unsigned int)((unsigned char *)0x06047DD0)

                      [*(int *)0x0605AD04 + (int)(char)((char)*(int *)puVar2 * '\x05')]

          + *(int *)0x0605AD00;

  if (*(int *)0x06086030 != '\0') {

    uVar7 = (unsigned int)(unsigned char)((int *)0x06047DDF)[*(int *)puVar2];

  }

  uVar5 = (*(int(*)())0x06027552)(*(int *)(0x06047D8C + (uVar7 << 2)),*puVar8);

  *(int *)(DAT_0600e2c4 + iVar9) = uVar5;

  uVar5 = (*(int(*)())0x06027552)(*(int *)(iVar9 + DAT_0600e2c4),0x372f);

  *(int *)(DAT_0600e2c8 + iVar9) = uVar5;

  if (*(int *)(iVar9 + DAT_0600e2be) <

      (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1) {

    *(int *)(iVar9 + DAT_0600e2ca) = 0;

  }

  else {

    *(int *)(iVar9 + DAT_0600e3e8) = 0xffffffff;

  }

  *(int *)(iVar9 + DAT_0600e3ea + -8) = *(int *)(iVar9 + DAT_0600e3ea);

  uVar7 = *(unsigned int *)(iVar9 + 4) & 1;

  if (*(int *)puVar2 == 0) {

    if (uVar7 == 0) {

      *(int *)(iVar9 + DAT_0600e3ec + 0x7c) = 0x180;

      *(char **)(iVar9 + 0xc) = 0x00042000;

      iVar6 = (int)DAT_0600e3f4;

      iVar4 = (int)DAT_0600e3f2;

      *(int *)(iVar9 + iVar4) = iVar6;

      *(int *)(iVar9 + iVar4 + -4) = iVar6;

    }

    else {

      *(int *)(iVar9 + DAT_0600e3f0) = 0x580;

      *(char **)(iVar9 + 0xc) = 0x00042E38;

    }

  }

  else {

    if (uVar7 == 0) {

      *(int *)(iVar9 + DAT_0600e3f0) = 0x580;

    }

    else {

      *(int *)(iVar9 + DAT_0600e3ec + 0x7c) = 0x180;

    }

    iVar4 = (int)DAT_0600e3f2;

    *(int *)(iVar9 + iVar4) = 0;

    *(int *)(iVar9 + iVar4 + -4) = 0;

  }

  *(int *)(iVar9 + DAT_0600e3f0 + -4) = *(int *)(iVar9 + DAT_0600e3f0);

  (*(int(*)())0x0600CA96)(puVar3);

  *(int *)(iVar9 + 0x10) = *(int *)puVar3;

  *(int *)(iVar9 + 0x18) = *(int *)(puVar3 + 8);

  if ((*(int *)(iVar9 + 4) == 0) && (*(int *)puVar2 == 2)) {

    *(short *)(puVar3 + 0xe) = DAT_0600e3f6;

  }

  uVar5 = (*(int(*)())0x06006838)(*(int *)(iVar9 + 0x10),*(int *)(iVar9 + 0x18));

  (*(int(*)())0x06027EDE)(uVar5,iVar9 + 0x10,auStack_1c);

  *(int *)(iVar9 + 0x1c) = (int)*(short *)(puVar3 + 0xc);

  *(int *)(iVar9 + 0x20) = (int)*(short *)(puVar3 + 0xe);

  *(int *)(iVar9 + 0x24) = (int)*(short *)(puVar3 + 0x10);

  *(int *)(iVar9 + 0x30) = *(int *)(iVar9 + 0x20);

  *(int *)(iVar9 + 0x34) = *(int *)(iVar9 + 0x20);

  *(int *)(iVar9 + 0x28) = *(int *)(iVar9 + 0x20);

  *(int *)(iVar9 + PTR_DAT_0600e3f8) = *(int *)(iVar9 + 0x20);

  return;

}
