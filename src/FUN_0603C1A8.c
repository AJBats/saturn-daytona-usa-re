extern int DAT_0603c23c;

extern int DAT_0603c378;

extern int DAT_0603c37c;

extern int DAT_0603c37e;

extern int DAT_0603c496;

extern int DAT_0603c49a;

extern int DAT_0603c49c;

extern int DAT_0603c62e;

void FUN_0603c1a8(param_1, param_2)
    unsigned int param_1;
    unsigned int param_2;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned short uVar6;

  char *puVar7;

  unsigned int uVar8;

  puVar4 = 0x060A4D36;

  puVar3 = 0x0000FFBF;

  puVar2 = 0x060A4D3E;

  puVar5 = 0x0000FF00;

  uVar8 = 1;

  puVar7 = 0x060A4D18;

  (*(void(*)())0x06034F78)();

  *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FDFF;

  (*(void(*)())0x06034F78)();

  *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FEFF;

  uVar1 = (unsigned short)puVar5;

  uVar6 = (unsigned short)puVar3;

  if (((int)DAT_0603c23c & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c378 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c37c & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c37e & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c496 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 4) = *(unsigned short *)(puVar4 + 4) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c49a & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 4) = *(unsigned short *)(puVar4 + 4) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c49c & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((unsigned int)0x00008000 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((param_1 & 4) != 0) || ((param_1 & 2) != 0)) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) =

           *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFE | (unsigned short)uVar8;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)puVar2 = *(unsigned short *)puVar2 & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFE;

    }

  }

  if (((param_1 & 8) != 0) || (((int)DAT_0603c62e & param_1) != 0)) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFD | 2;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)puVar2 = *(unsigned short *)puVar2 & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFD;

    }

  }

  if ((param_1 & 0x10) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFB | 4;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 2) = *(unsigned short *)(puVar2 + 2) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFB;

    }

  }

  if ((param_1 & 0x20) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFF7 | 8;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 2) = *(unsigned short *)(puVar2 + 2) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFF7;

    }

  }

  uVar6 = (unsigned short)param_2;

  if ((param_1 & uVar8) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      puVar5 = 0x0000FFEF;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)puVar5 | 0x10;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 4) = uVar6 & 0xff;

    }

    else {

      puVar5 = 0x0000FFEF;

      (*(void(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)puVar5;

    }

  }

  return;

}
