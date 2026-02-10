extern int DAT_0603c07a;
extern int DAT_0603c07c;
extern int DAT_0603c23c;
extern int DAT_0603c378;
extern int DAT_0603c37c;
extern int DAT_0603c37e;
extern int DAT_0603c496;
extern int DAT_0603c49a;
extern int DAT_0603c49c;
extern int DAT_0603c62e;
extern int DAT_0603c7e6;
extern int DAT_0603c7e8;
extern int DAT_0603c7ea;
extern int DAT_0603c8d0;
extern int DAT_0603c8d2;
extern int DAT_0603c8d4;
extern int DAT_0603cad8;
extern int DAT_0603cada;
extern int DAT_0603cadc;
extern int DAT_0603cade;
extern int DAT_0603cae0;
extern int DAT_0603cae2;
extern int DAT_0603cba2;
extern int DAT_0603cd4c;
extern int DAT_0603ce8e;
extern int DAT_0603ce90;
extern int DAT_0603d034;
extern int DAT_0603d1c2;
extern int DAT_0603d426;
extern int DAT_0603d500;
extern int DAT_0603d5be;
extern int DAT_0603e0b2;
extern int DAT_0603e3b6;
extern int DAT_0603e3b8;
extern int DAT_0603e3ba;
extern int DAT_0603e3bc;
extern int DAT_0603e61e;
extern int DAT_0603e93a;
extern int DAT_0603e93c;
extern int DAT_0603e93e;
extern int DAT_0603ea46;
extern int FUN_0603c1a8();
extern int FUN_0603cc88();
extern void FUN_0603cd5c();
extern char * FUN_0603d9ec();
extern char * FUN_0603da88();
extern int FUN_0603eacc();
extern int FUN_0603ec40();
extern int PTR_DAT_0603c7ec;
extern int PTR_DAT_0603e53c;
extern int PTR_DAT_0603e620;

void FUN_0603c000()
{

  int *puVar1;

  unsigned int uVar2;

  int *puVar3;

  unsigned char *pbVar4;

  int iVar5;

  unsigned int uVar6;

  puVar1 = (int *)0x60000000;

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

void FUN_0603c05c(param_1, param_2)
    unsigned int param_1;
    int param_2;
{

  int *puVar1;

  int *puVar2;

  

  puVar1 = (int *)(param_1 & 0x1FFFFFF0 | 0x40000000);

  puVar2 = (int *)((int)puVar1 + param_2);

  for (; puVar1 < puVar2; puVar1 = puVar1 + 4) {

    *puVar1 = 0;

  }

  return;

}

unsigned int FUN_0603c08c(param_1, param_2)
    int param_1;
    int param_2;
{

  return (int)((unsigned long long)((long long)param_2 * (long long)param_1) >> 0x20) << 0x10 |

         (unsigned int)((long long)param_2 * (long long)param_1) >> 0x10;

}

int FUN_0603c0a0(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  

  puVar1 = (int *)0xFFFFFF00;

  *(int *)0xFFFFFF00 = param_2;

  *(int *)(puVar1 + 0x10) = (int)(short)((unsigned int)param_1 >> 0x10);

  *(int *)(puVar1 + 0x14) = param_1 << 0x10;

  return *(int *)(puVar1 + 0x14);

}

void FUN_0603c104()
{

  char *puVar1;

  unsigned int uVar2;

  unsigned char bVar3;

  puVar1 = (int *)0x060A4D60;

  FUN_0603cd5c();

  (*(int(*)())0x0603D2CC)();

  (*(int(*)())0x0603D3A8)();

  (*(int(*)())0x0603D438)();

  (*(int(*)())0x0603D514)();

  (*(int(*)())0x0603D5D0)();

  bVar3 = 0;

  do {

    uVar2 = (unsigned int)bVar3;

    bVar3 = bVar3 + 1;

    *(int *)(puVar1 + (uVar2 << 2)) = 0;

  } while (bVar3 < 8);

  *(int *)0x060A4D80 = 0;

  *(int *)0x060A4DA6 = 0;

  return;

}

int FUN_0603c1a8(param_1, param_2)
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

  puVar4 = (char *)0x060A4D36;

  puVar3 = (char *)0x0000FFBF;

  puVar2 = (int *)0x060A4D3E;

  puVar5 = (char *)0x0000FF00;

  uVar8 = 1;

  puVar7 = (char *)0x060A4D18;

  (*(int(*)())0x06034F78)();

  *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FDFF;

  (*(int(*)())0x06034F78)();

  *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FEFF;

  uVar1 = (unsigned short)puVar5;

  uVar6 = (unsigned short)puVar3;

  if ((0x100 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if ((0x200 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if ((0x400 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if ((0x800 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c496 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 4) = *(unsigned short *)(puVar4 + 4) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c49a & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 4) = *(unsigned short *)(puVar4 + 4) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c49c & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((unsigned int)0x00008000 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((param_1 & 4) != 0) || ((param_1 & 2) != 0)) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) =

           *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFE | (unsigned short)uVar8;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar2 = *(unsigned short *)puVar2 & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFE;

    }

  }

  if (((param_1 & 8) != 0) || ((0x80 & param_1) != 0)) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFD | 2;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar2 = *(unsigned short *)puVar2 & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFD;

    }

  }

  if ((param_1 & 0x10) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFB | 4;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 2) = *(unsigned short *)(puVar2 + 2) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFB;

    }

  }

  if ((param_1 & 0x20) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFF7 | 8;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 2) = *(unsigned short *)(puVar2 + 2) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFF7;

    }

  }

  uVar6 = (unsigned short)param_2;

  if ((param_1 & uVar8) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      puVar5 = (char *)0x0000FFEF;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)puVar5 | 0x10;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 4) = uVar6 & 0xff;

    }

    else {

      puVar5 = (char *)0x0000FFEF;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)puVar5;

    }

  }

  return 0;

}

unsigned int FUN_0603c728()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned int local_40;

  unsigned int uStack_3c;

  unsigned int local_24 [2];

  puVar4 = (char *)0x060A4DA5;

  puVar3 = (char *)0x060A4DA4;

  puVar2 = (int *)0x060A4DA6;

  iVar6 = 0x500;

  iVar7 = 0x300;

  uVar8 = (unsigned int)DAT_0603c7ea;

  uVar5 = (unsigned int)(unsigned char)*(int *)0x060A4DA6;

  if (uVar5 == 1) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      *(int *)0x060A4DA6 = 0;

      puVar3 = (char *)0x060A4DA8;

      for (uVar5 = 0; uVar5 < *(unsigned int *)0x060A4D94; uVar5 = uVar5 + 1) {

        if ((unsigned char)(puVar3 + uVar5)[iVar7] < (unsigned char)puVar3[uVar5]) {

          puVar3[iVar7 + uVar5] = puVar3[iVar7 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[uVar5] < (unsigned char)(puVar3 + uVar5)[iVar7]) {

          puVar3[iVar7 + uVar5] = puVar3[iVar7 + uVar5] + -1;

          *puVar2 = 1;

        }

        if ((unsigned char)puVar3[uVar8 + uVar5] < (unsigned char)puVar3[0x100 + uVar5]) {

          puVar3[uVar8 + uVar5] = puVar3[uVar8 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[0x100 + uVar5] < (unsigned char)puVar3[uVar8 + uVar5]) {

          puVar3[uVar8 + uVar5] = puVar3[uVar8 + uVar5] + -1;

          *puVar2 = 1;

        }

        if ((unsigned char)puVar3[iVar6 + uVar5] < (unsigned char)puVar3[0x200 + uVar5]) {

          puVar3[iVar6 + uVar5] = puVar3[iVar6 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[0x200 + uVar5] < (unsigned char)puVar3[iVar6 + uVar5]) {

          puVar3[iVar6 + uVar5] = puVar3[iVar6 + uVar5] + -1;

          *puVar2 = 1;

        }

      }

      *(int *)0x060A4D8C = 0;

      puVar3 = (char *)0x060A4DA8;

      puVar2 = (int *)0x060A4DA8;

      uVar5 = (int)((unsigned int)*(unsigned short *)0x060A3D96 & (int)DAT_0603c8d4) >> 0xc;

      if (uVar5 == 2) {

        for (local_40 = 0; local_40 < *(unsigned int *)0x060A4D94; local_40 = local_40 + 1) {

          local_24[0] = (unsigned int)((((puVar2[iVar7 + local_40]) << 8 | (puVar2[uVar8 + local_40]) & 0xFF)) << 8 | (puVar2[iVar6 + local_40]) & 0xFF);

          uVar5 = (*(int(*)())0x060429EC)(*(int *)0x060A4D84,*(int *)0x060A4D90 + local_40,1,

                             local_24);

        }

      }

      else {

        for (uStack_3c = 0; uStack_3c < *(unsigned int *)0x060A4D94; uStack_3c = uStack_3c + 1) {

          local_24[0] = (unsigned int)(unsigned char)puVar3[iVar6 + uStack_3c] |

                        ((unsigned int)(unsigned char)puVar3[uVar8 + uStack_3c] |

                        (unsigned int)(unsigned char)puVar3[iVar7 + uStack_3c] << 5) << 5;

          uVar5 = (*(int(*)())0x060429EC)(*(int *)0x060A4D84,*(int *)0x060A4D90 + uStack_3c,1,

                             local_24);

        }

      }

    }

  }

  else if (uVar5 == 2) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      if (*(int *)0x060A4DA7 == '\0') {

        *(int *)0x060A4DA4 = *(int *)0x060A4DA4 + -1;

        if ((unsigned char)*puVar3 <= (unsigned char)*puVar4) {

          *puVar3 = *puVar4;

          *puVar2 = 0;

        }

      }

      else {

        *(int *)0x060A4DA4 = *(int *)0x060A4DA4 + '\x01';

        if ((unsigned char)*puVar4 <= (unsigned char)*puVar3) {

          *puVar3 = *puVar4;

          *puVar2 = 0;

        }

      }

      if ((*(unsigned int *)0x060A4D84 & 0x100) != 0) {

        FUN_0603c1a8(0x100,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x200) != 0) {

        FUN_0603c1a8(0x200,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & uVar8) != 0) {

        FUN_0603c1a8(uVar8,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x800) != 0) {

        FUN_0603c1a8(0x800,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cade) != 0) {

        FUN_0603c1a8((int)DAT_0603cade,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cae0) != 0) {

        FUN_0603c1a8((int)DAT_0603cae0,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cae2) != 0) {

        FUN_0603c1a8((int)DAT_0603cae2,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (unsigned int)0x00008000) != 0) {

        FUN_0603c1a8(0x00008000,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 4) != 0) {

        FUN_0603c1a8(4,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 8) != 0) {

        FUN_0603c1a8(8,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x10) != 0) {

        FUN_0603c1a8(0x10,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x20) != 0) {

        FUN_0603c1a8(0x20,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 1) != 0) {

        FUN_0603c1a8(1,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 2) != 0) {

        FUN_0603c1a8(2,(int)(char)*puVar3);

      }

      uVar5 = *(unsigned int *)0x060A4D84;

      if ((uVar5 & 0x80) != 0) {

        uVar5 = FUN_0603c1a8(0x80,(int)(char)*puVar3);

      }

      *(int *)0x060A4D8C = 0;

    }

  }

  else if (uVar5 == 3) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      uVar5 = FUN_0603cc88(*(int *)0x060A4D84,(int)*(short *)0x060A4D98,

                           (int)*(short *)0x060A4D9A,(int)*(short *)0x060A4D9C);

      puVar3 = (char *)0x060A4D9E;

      sVar1 = *(short *)0x060A4D98;

      *(short *)0x060A4D9E = *(short *)0x060A4D9E - sVar1;

      *(short *)0x060A4DA0 = *(short *)0x060A4DA0 - *(short *)0x060A4D9A;

      *(short *)0x060A4DA2 = *(short *)0x060A4DA2 - *(short *)0x060A4D9C;

      if (sVar1 < 1) {

        if (-1 < *(short *)puVar3) {

          *(short *)0x060A4D98 = 0;

        }

      }

      else if (*(short *)puVar3 < 1) {

        *(short *)0x060A4D98 = 0;

      }

      if (*(short *)0x060A4D9A < 1) {

        if (-1 < *(short *)0x060A4DA0) {

          *(short *)0x060A4D9A = 0;

        }

      }

      else if (*(short *)0x060A4DA0 < 1) {

        *(short *)0x060A4D9A = 0;

      }

      if (*(short *)0x060A4D9C < 1) {

        if (-1 < *(short *)0x060A4DA2) {

          *(short *)0x060A4D9C = 0;

        }

      }

      else if (*(short *)0x060A4DA2 < 1) {

        *(short *)0x060A4D9C = 0;

      }

      if (((*(short *)0x060A4D98 == 0) && (*(short *)0x060A4D9A == 0)) &&

         (*(short *)0x060A4D9C == 0)) {

        *puVar2 = 0;

      }

      *(int *)0x060A4D8C = 0;

    }

  }

  return uVar5;

}

int FUN_0603cc88(param_1, param_2, param_3, param_4)
    int param_1;
    short param_2;
    short param_3;
    short param_4;
{

  unsigned short uVar1;

  char *puVar2;

  puVar2 = (int *)0x060A4D46;

  uVar1 = DAT_0603cd4c;

  if (param_1 == 0) {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar2 + 4) = (*(unsigned short *)(puVar2 + 4) & uVar1) + param_2;

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar2 + 6) = (*(unsigned short *)(puVar2 + 6) & uVar1) + param_3;

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar2 + 8) = (*(unsigned short *)(puVar2 + 8) & uVar1) + param_4;

  }

  else {

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar2 + 10) = (*(unsigned short *)(puVar2 + 10) & uVar1) + param_2;

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar2 + 0xc) = (*(unsigned short *)(puVar2 + 0xc) & uVar1) + param_3;

    (*(int(*)())0x06034F78)();

    *(unsigned short *)(puVar2 + 0xe) = (*(unsigned short *)(puVar2 + 0xe) & uVar1) + param_4;

  }

  return 0;

}

void FUN_0603cd5c()
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  unsigned short *puVar6;

  char *puVar7;

  unsigned short uVar8;

  uVar3 = DAT_0603ce8e;

  puVar6 = (unsigned short *)0x060A4D18;

  (*(int(*)())0x06034F78)(0x060A4D18,0x060A4D58,1);

  *puVar6 = *puVar6 & uVar3 | DAT_0603ce90;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FFBF;

  puVar7 = (char *)0x0000FFDF;

  (*(int(*)())0x06034F78)();

  uVar8 = (unsigned short)puVar7;

  *puVar6 = *puVar6 & uVar8 | 0x20;

  puVar7 = (char *)0x0000FFEF;

  (*(int(*)())0x06034F78)();

  uVar1 = (unsigned short)puVar7;

  *puVar6 = *puVar6 & uVar1;

  puVar7 = (char *)0x0000FFF0;

  (*(int(*)())0x06034F78)();

  uVar5 = (unsigned short)puVar7;

  *puVar6 = *puVar6 & uVar5 | 7;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar5;

  puVar7 = (char *)0x0000FF0F;

  (*(int(*)())0x06034F78)();

  uVar2 = (unsigned short)puVar7;

  puVar6[2] = puVar6[2] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & (unsigned short)0x0000F0FF;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & (unsigned short)0x0000F0FF;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar2;

  puVar7 = (char *)0x0000FFFE;

  (*(int(*)())0x06034F78)();

  uVar2 = (unsigned short)puVar7;

  puVar6[4] = puVar6[4] & uVar2;

  puVar7 = (char *)0x0000FFFD;

  (*(int(*)())0x06034F78)();

  uVar3 = (unsigned short)puVar7;

  puVar6[4] = puVar6[4] & uVar3;

  puVar7 = (char *)0x0000FFFB;

  (*(int(*)())0x06034F78)();

  uVar5 = uVar5 + 7;

  uVar4 = (unsigned short)puVar7;

  puVar6[4] = puVar6[4] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar6[4] = puVar6[4] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[4] = puVar6[4] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar6[4] = puVar6[4] & uVar8;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FFFC;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FFF3;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FFCF;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FF3F;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FCFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & DAT_0603d034;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x00008FFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FBFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FDFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FEFF | DAT_0603d1c2;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FFBF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar8;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FFFC;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FFF3;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FFCF;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FF3F;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FCFF;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar8;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & (unsigned short)0x0000FEFF;

  (*(int(*)())0x06034F78)();

  return;

}

void FUN_0603d2cc()
{

  unsigned short uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D28;

  puVar3 = (char *)0x0000FFF0;

  (*(int(*)())0x06034F78)(0x060A4D28,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  puVar3 = (char *)0x0000F0FF;

  (*(int(*)())0x06034F78)();

  uVar1 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar1;

  (*(int(*)())0x06034F78)();

  return;

}

int FUN_0603d3a8()
{

  int uVar1;

  unsigned short *puVar2;

  unsigned short uVar3;

  char *puVar4;

  unsigned short uVar5;

  uVar3 = 1;

  puVar2 = (unsigned short *)0x060A4D30;

  puVar4 = (char *)0x0000FF00;

  (*(int(*)())0x06034F78)(0x060A4D30,1,0x060A4D58);

  uVar5 = (unsigned short)puVar4;

  *puVar2 = *puVar2 & uVar5 | 3;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & 0xff | DAT_0603d426;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar5 | uVar3;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & 0xff;

  (*(int(*)())0x06034F78)();

  puVar2[2] = 4;

  uVar1 = (*(int(*)())0x06034F78)();

  return uVar1;

}

void FUN_0603d438()
{

  unsigned short uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D36;

  puVar3 = (char *)0x0000FF00;

  (*(int(*)())0x06034F78)(0x060A4D36,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  uVar1 = DAT_0603d500;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[2] = puVar2[2] & uVar1;

  (*(int(*)())0x06034F78)();

  return;

}

void FUN_0603d514()
{

  unsigned short uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D3E;

  puVar3 = (char *)0x0000FF00;

  (*(int(*)())0x06034F78)(0x060A4D3E,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  uVar1 = DAT_0603d5be;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar2[2] = 0;

  (*(int(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[3] = puVar2[3] & uVar1;

  (*(int(*)())0x06034F78)();

  return;

}

int FUN_0603d5d0()
{

  int uVar1;

  unsigned short *puVar2;

  char *puVar3;

  unsigned short uVar4;

  puVar2 = (unsigned short *)0x060A4D46;

  puVar3 = (char *)0x0000FFFE;

  (*(int(*)())0x06034F78)(0x060A4D46,0x060A4D58,1);

  uVar4 = (unsigned short)puVar3;

  *puVar2 = *puVar2 & uVar4;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & (unsigned short)0x0000FFFD;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & (unsigned short)0x0000FFFB;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & (unsigned short)0x0000FFF7;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & (unsigned short)0x0000FFEF;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & (unsigned short)0x0000FFDF;

  (*(int(*)())0x06034F78)();

  *puVar2 = *puVar2 & (unsigned short)0x0000FFBF;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & (unsigned short)0x0000FFFD;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & (unsigned short)0x0000FFFB;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & (unsigned short)0x0000FFF7;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & (unsigned short)0x0000FFEF;

  (*(int(*)())0x06034F78)();

  puVar2[1] = puVar2[1] & (unsigned short)0x0000FFDF;

  (*(int(*)())0x06034F78)();

  uVar4 = 0;

  puVar2[1] = puVar2[1] & (unsigned short)0x0000FFBF;

  (*(int(*)())0x06034F78)();

  puVar2[2] = uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[3] = uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[4] = uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[5] = uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[6] = uVar4;

  (*(int(*)())0x06034F78)();

  puVar2[7] = uVar4;

  uVar1 = (*(int(*)())0x06034F78)();

  return uVar1;

}

char * FUN_0603d9ec(param_1)
    unsigned int param_1;
{

  int iVar1;

  char *puVar2;

  param_1 = 0x80000000 & param_1;

  iVar1 = (*(int(*)())0x06036BE4)();

  if (iVar1 < (int)0x010E0000) {

    if (iVar1 < (int)0x00B40000) {

      if ((int)0x005A0000 <= iVar1) {

        iVar1 = (int)0x00B40000 - iVar1;

      }

      puVar2 = (char *)(*(int(*)())0x060424A2)(iVar1);

    }

    else {

      iVar1 = (*(int(*)())0x060424A2)(0xFF4C0000 + iVar1);

      puVar2 = (char *)-iVar1;

    }

  }

  else {

    iVar1 = (*(int(*)())0x060424A2)((int)0x01680000 - iVar1);

    puVar2 = (char *)-iVar1;

  }

  if (puVar2 == 0x0000FFFF) {

    puVar2 = (int *)0x00010000;

  }

  if (param_1 != 0) {

    puVar2 = (char *)-(int)puVar2;

  }

  return puVar2;

}

char * FUN_0603da88()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar1 = (char *)(*(int(*)())0x06036BE4)();

  puVar2 = (int *)0x00010000;

  if (puVar1 != (char *)0x0) {

    if ((int)puVar1 < (int)0x010E0000) {

      if ((int)0x00B40000 < (int)puVar1) {

        iVar3 = (*(int(*)())0x0604249C)(puVar1 + 0xFF4C0000);

        puVar2 = (char *)-iVar3;

      }

      else {

        puVar2 = (int *)0xFFFF0000;

        if (puVar1 != 0x00B40000) {

          if ((int)puVar1 < (int)0x005A0000) {

            puVar2 = (char *)(*(int(*)())0x0604249C)(puVar1);

          }

          else {

            iVar3 = (*(int(*)())0x0604249C)((int)0x00B40000 - (int)puVar1);

            puVar2 = (char *)-iVar3;

          }

        }

      }

    }

    else {

      puVar2 = (char *)(*(int(*)())0x0604249C)((int)0x01680000 - (int)puVar1);

    }

  }

  return puVar2;

}

short * FUN_0603ddfc(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  char *puVar11;

  short *psVar12;

  unsigned short uVar15;

  int iVar13;

  int uVar14;

  int iVar16;

  char *puVar17;

  int *puVar18;

  int iVar19;

  int iVar20;

  unsigned int uVar21;

  int *piVar22;

  unsigned int uVar23;

  char cVar24;

  unsigned short uVar25;

  int ***pppiVar26;

  int iVar27;

  int iVar28;

  char *local_9c;

  int local_98;

  char *local_90 [2];

  char auStack_88 [8];

  short *local_80;

  int **local_7c;

  unsigned int **local_78;

  char *local_74;

  unsigned int *local_70;

  int *local_6c;

  int *piStack_68;

  unsigned int *local_64;

  int *local_60;

  int *local_5c;

  int *local_58;

  int *piStack_54;

  int iStack_50;

  int iStack_4c;

  int *piStack_48;

  int *piStack_44;

  int *piStack_40;

  int *piStack_3c;

  int *piStack_38;

  int *piStack_34;

  int *piStack_30;

  int *piStack_2c;

  int iStack_28;

  puVar7 = (char *)0x00010000;

  puVar17 = (char *)0x060A4C60;

  puVar6 = (char *)0x060A4C68;

  puVar5 = (char *)0x060A53B8;

  psVar12 = *(short **)0x060635A8;

  if (psVar12 == (short *)(void *)0x00000001) {

    uVar25 = 0;

  }

  else {

    if (psVar12 != (short *)(void *)0x00000002) {

      return psVar12;

    }

    uVar25 = 1;

  }

  cVar24 = (char)uVar25;

  puVar18 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

  *puVar18 = (int *)0x00010000;

  puVar18[1] = 0;

  puVar18[2] = 0;

  puVar18[3] = 0;

  puVar18[4] = puVar7;

  puVar18[5] = 0;

  puVar18[6] = 0;

  puVar18[7] = 0;

  puVar18[8] = puVar7;

  if (*(int *)(0x060A4C44 + (unsigned int)(uVar25 << 2)) == 0) {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = 0;

  }

  else {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) + param_1;

  }

  *(int *)(puVar6 + (unsigned int)(uVar25 << 2)) = *(int *)(puVar6 + (unsigned int)(uVar25 << 2)) + param_2;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) && (param_1 != 0)) {

    if (*(int *)0x060635A8 == 1) {

      uVar15 = *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00;

    }

    else {

      if (*(int *)0x060635A8 != 2) goto LAB_0603dedc;

      uVar15 = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

    }

    *(unsigned short *)(0x060A3E38 + 4) = uVar15;

  }

LAB_0603dedc:

  if (param_3 != 0) {

    FUN_0603ec40(param_3);

  }

  if ((*(int *)(0x060A4C4C + (unsigned int)(uVar25 << 2)) != 0) &&

     (*(int *)(0x060A4C70 + (unsigned int)(uVar25 << 2)) != 0)) {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = 0;

  }

  puVar7 = (char *)0x060A3E68;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) &&

     (*(int *)(0x060A4C78 + (unsigned int)(uVar25 << 2)) == 0)) {

    if (((uVar25 == 0) && ((*(unsigned short *)0x060A3E3C & 0xff) != 0)) ||

       ((uVar25 == 1 && (((unsigned int)*(unsigned short *)0x060A3E3C & (unsigned int)0x0000FF00) != 0)))) {

      puVar18 = (int *)(puVar5 + (char)(cVar24 * '$'));

      *puVar18 = *(int *)(0x060A3E68 + (unsigned int)(uVar25 << 7) + 0x4c);

      puVar18[4] = *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

      *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x1c) =

           *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x4c);

      *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x2c) =

           *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

    }

  }

  else {

    puVar18 = (int *)(puVar5 + (char)(cVar24 * '$'));

    *puVar18 = *(int *)(0x060A3E68 + (unsigned int)(uVar25 << 7) + 0x4c);

    puVar18[4] = *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

  }

  if (*(int *)(puVar6 + (unsigned int)(uVar25 << 2)) != 0) {

    FUN_0603eacc(*(int *)(puVar6 + (unsigned int)(uVar25 << 2)));

  }

  puVar11 = (char *)0x060A3E38;

  puVar10 = (char *)0x0603C0A0;

  puVar9 = (char *)0x00040000;

  sVar1 = DAT_0603e61e;

  puVar8 = (char *)0x060A3E38;

  puVar7 = (char *)0x0603C0A0;

  puVar6 = (char *)0x00008000;

  puVar5 = (char *)0x00040000;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) &&

     (*(int *)(0x060A4C78 + (unsigned int)(uVar25 << 2)) == 0)) {

    return (short *)0x0;

  }

  if ((*(short *)(0x060A4C54 + (unsigned int)(uVar25 << 1)) != 0) &&

     (*(int *)(0x060A4C4C + (unsigned int)(uVar25 << 2)) == 0)) {

    iStack_50 = *(int *)(puVar17 + (unsigned int)(uVar25 << 2));

    uVar21 = (unsigned int)DAT_0603e61e;

    sVar2 = DAT_0603e61e + 1;

    psVar12 = *(short **)0x060635A8;

    if (psVar12 == (short *)(void *)0x00000001) {

      uVar15 = 0;

      *(unsigned short *)(0x060A3E38 + 4) =

           *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00;

      uVar25 = *(unsigned short *)(puVar11 + 4) | 3;

    }

    else {

      if (psVar12 != (short *)(void *)0x00000002) {

        return psVar12;

      }

      uVar15 = 1;

      *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

      uVar25 = *(unsigned short *)(puVar11 + 4) | PTR_DAT_0603e620;

    }

    *(unsigned short *)(puVar11 + 4) = uVar25;

    local_58 = (int *)FUN_0603d9ec(iStack_50);

    iStack_50 = FUN_0603da88(iStack_50);

    puVar5 = (char *)0x0603C08C;

    cVar24 = (char)uVar15;

    piVar22 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

    piStack_30 = (int *)*piVar22;

    piStack_40 = piVar22 + 2;

    piStack_48 = (int *)*piStack_40;

    piStack_38 = piVar22 + 3;

    iStack_4c = *piStack_38;

    piStack_3c = piVar22 + 5;

    piStack_2c = (int *)*piStack_3c;

    piStack_44 = piVar22 + 6;

    iStack_28 = *piStack_44;

    piStack_54 = piVar22 + 8;

    piStack_34 = (int *)*piStack_54;

    local_5c = (int *)(*(int(*)())0x0603C08C)(piStack_30,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_48,local_58);

    *piVar22 = (int)local_5c - iVar13;

    local_5c = piStack_40;

    local_60 = (int *)(*(int(*)())puVar5)(piStack_30,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_48,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    local_5c = piStack_38;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_4c,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_2c,local_58);

    *local_5c = (int)local_60 - iVar13;

    local_5c = piStack_3c;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_4c,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_2c,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    local_5c = piStack_44;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_28,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_34,local_58);

    *local_5c = (int)local_60 - iVar13;

    local_5c = piStack_54;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_28,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_34,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    puVar5 = (char *)0x060A3E68;

    *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *piVar22;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x24) = *piStack_40;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x28) = *piStack_38;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x2c) = piVar22[4];

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x30) = *piStack_3c;

    sVar3 = *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x34);

    sVar4 = *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x3c);

    iVar20 = *piStack_44;

    local_58 = (int *)piVar22[7];

    iStack_50 = (int)*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x36);

    iVar27 = (int)local_58 * (iStack_50 - *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x3e));

    iVar16 = *piStack_54;

    iVar19 = (int)*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x38);

    iStack_4c = ((*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x40)) << 16 | (iStack_4c) & 0xFFFF);

    iVar28 = iVar16 * (iVar19 - *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x40));

    local_6c = (int *)&local_6c;

    (*(int(*)())0x060358EC)();

    local_70 = (unsigned int *)0x0;

    local_74 = (char *)0x40F00000;

    local_78 = &local_64;

    (*(int(*)())0x060359E4)();

    iVar13 = (*(int(*)())0x060357B8)();

    puVar5 = (char *)0x005A0000;

    iVar13 = iVar20 * ((int)sVar3 - (int)sVar4) + iVar27 + iVar28 + iVar13 +

             *(int *)(0x060A4C78 + (unsigned int)(uVar15 << 2));

    local_70 = (unsigned int *)(-(iVar19 * iVar16) - (int)local_70 * (int)local_78);

    if (*(int *)(0x060A4C70 + (unsigned int)(uVar15 << 2)) == 0) {

      puVar18 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      puVar18[0x15] = *puVar18;

      uVar14 = FUN_0603da88(puVar5);

      puVar5 = (char *)0x005A0000;

      puVar18[0x16] = uVar14;

      uVar14 = FUN_0603d9ec(puVar5);

      puVar18[0x17] = uVar14;

      puVar5 = (char *)0x060A4C38;

      *(unsigned int *)(0x060A4C38 + (unsigned int)(uVar15 << 2)) = *(unsigned short *)0x060635AE - 1;

      local_64 = (unsigned int *)(puVar5 + (unsigned int)(uVar15 << 2));

      piStack_68 = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x18);

      local_6c = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      local_74 = 0x060A3F68 + (short)(uVar15 * DAT_0603ea46);

      psVar12 = (short *)0x060A3F68;

      for (uVar23 = 0; uVar23 < *local_64; uVar23 = uVar23 + 1) {

        local_78 = (unsigned int **)(*piStack_68 * (uVar23 - (int)*(short *)(local_6c + 0xd)) +

                            (int)local_70);

        iVar16 = (*(int(*)())0x06034FFC)();

        if (iVar16 == 0) {

          psVar12 = (short *)(local_74 + (uVar23 << 1));

LAB_0603ea9c:

          *psVar12 = sVar1 + 1;

        }

        else {

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          local_7c = (int **)(unsigned int)((int)puVar9 < -iVar16);

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          if (-iVar16 < 0 || local_7c != (int **)0x0) {

            psVar12 = (short *)(local_74 + (uVar23 << 1));

            goto LAB_0603ea9c;

          }

          local_7c = (int **)(local_74 + (uVar23 << 1));

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & uVar21);

          *(short *)local_7c = (short)psVar12;

        }

      }

    }

    else {

      local_74 = (char *)((unsigned int)(uVar15 << 2));

      piVar22 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      piVar22[0x15] = (int)(0x012C0000 + *piVar22);

      local_78 = (unsigned int **)(0x060A4C70 + (int)local_74);

      iVar16 = FUN_0603da88(0x005A0000 + (int)*local_78);

      piVar22[0x16] = iVar16;

      iVar16 = FUN_0603d9ec(0x005A0000 + (int)*local_78);

      piVar22[0x17] = iVar16;

      puVar5 = (char *)0x060A4C38;

      *(int *)(0x060A4C38 + (int)local_74) = (int)DAT_0603e93a;

      local_64 = (unsigned int *)(puVar5 + (unsigned int)(uVar15 << 2));

      piStack_68 = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x18);

      local_6c = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      local_74 = 0x060A3F68 + (short)(uVar15 * DAT_0603e93c);

      psVar12 = (short *)0x060A3F68;

      for (uVar23 = 0; uVar23 < *local_64; uVar23 = uVar23 + 1) {

        local_78 = (unsigned int **)(*piStack_68 *

                             ((uVar23 - (int)*(short *)(local_6c + 0xd)) + (int)DAT_0603e93e) +

                            (int)local_70);

        iVar16 = (*(int(*)())0x06034FFC)();

        if (iVar16 == 0) {

          psVar12 = (short *)(local_74 + (uVar23 << 1));

LAB_0603e964:

          *psVar12 = sVar2;

        }

        else {

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          local_7c = (int **)(unsigned int)((int)puVar9 < -iVar16);

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          if (-iVar16 < 0 || local_7c != (int **)0x0) {

            psVar12 = (short *)(local_74 + (uVar23 << 1));

            goto LAB_0603e964;

          }

          local_7c = (int **)(local_74 + (uVar23 << 1));

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & uVar21);

          *(short *)local_7c = (short)psVar12;

        }

      }

    }

    *(short *)(0x060A4C40 + (unsigned int)(uVar15 << 1)) = 1;

    return psVar12;

  }

  piStack_54 = *(int **)(puVar17 + (unsigned int)(uVar25 << 2));

  psVar12 = *(short **)0x060635A8;

  if (psVar12 == (short *)(void *)0x00000001) {

    uVar15 = 0;

    *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00

    ;

    uVar25 = *(unsigned short *)(puVar8 + 4) | 3;

  }

  else {

    if (psVar12 != (short *)(void *)0x00000002) {

      return psVar12;

    }

    uVar15 = 1;

    *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

    uVar25 = *(unsigned short *)(puVar8 + 4) | DAT_0603e0b2;

  }

  *(unsigned short *)(puVar8 + 4) = uVar25;

  local_5c = (int *)FUN_0603d9ec(piStack_54);

  piStack_54 = (int *)FUN_0603da88(piStack_54);

  puVar17 = (char *)0x0603C08C;

  cVar24 = (char)uVar15;

  puVar18 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

  local_60 = puVar18 + 1;

  iStack_50 = *local_60;

  piStack_30 = puVar18 + 2;

  iStack_28 = *piStack_30;

  piStack_34 = puVar18 + 4;

  piStack_38 = (int *)*piStack_34;

  piStack_40 = puVar18 + 5;

  piStack_3c = (int *)*piStack_40;

  piStack_48 = puVar18 + 7;

  piStack_44 = (int *)*piStack_48;

  local_58 = puVar18 + 8;

  iStack_4c = *local_58;

  piStack_2c = local_60;

  local_64 = (unsigned int *)(*(int(*)())0x0603C08C)(iStack_50,piStack_54);

  iVar13 = (*(int(*)())puVar17)(iStack_28,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_30;

  iVar13 = (*(int(*)())puVar17)(iStack_50,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(iStack_28,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_34;

  local_64 = (unsigned int *)(*(int(*)())puVar17)(piStack_38,piStack_54);

  iVar13 = (*(int(*)())puVar17)(piStack_3c,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_40;

  iVar13 = (*(int(*)())puVar17)(piStack_38,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(piStack_3c,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_48;

  local_64 = (unsigned int *)(*(int(*)())puVar17)(piStack_44,piStack_54);

  iVar13 = (*(int(*)())puVar17)(iStack_4c,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = local_58;

  iVar13 = (*(int(*)())puVar17)(piStack_44,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(iStack_4c,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  puVar17 = (char *)0x060A3E68;

  *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *puVar18;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x20) = *piStack_2c;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x24) = *piStack_30;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x2c) = *piStack_34;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x30) = *piStack_40;

  iVar20 = puVar18[6];

  iVar19 = (int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x34);

  iVar27 = iVar20 * (iVar19 - *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x3c));

  iVar16 = *piStack_48;

  sVar1 = *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x36);

  sVar2 = *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x3e);

  piStack_54 = (int *)*local_58;

  local_5c = (int *)(int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x38);

  iVar28 = (int)piStack_54 * ((int)local_5c - (int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x40))

  ;

  local_70 = (unsigned int *)&local_70;

  (*(int(*)())0x060358EC)();

  local_74 = (char *)0x0;

  local_78 = (unsigned int **)0x40F00000;

  local_7c = &piStack_68;

  pppiVar26 = &local_7c;

  (*(int(*)())0x060359E4)();

  iVar13 = (*(int(*)())0x060357B8)();

  puVar17 = (char *)0x060A3E68;

  local_70 = (unsigned int *)((unsigned int)(uVar15 << 2));

  iVar13 = iVar27 + iVar16 * ((int)sVar1 - (int)sVar2) + iVar28 + iVar13 +

           *(int *)(0x060A4C78 + (int)local_70);

  local_74 = (char *)(-((int)local_7c * (int)local_74) - iVar19 * iVar20);

  if (*(int *)(0x060A4C70 + (int)local_70) == 0) {

    if ((*(int *)(0x060A4C4C + (unsigned int)(uVar15 << 2)) == -1) ||

       (*(int *)(0x060A4C4C + (unsigned int)(uVar15 << 2)) == 0)) {

      *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x54) =

           *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 4);

    }

    else {

      puVar17 = 0x060A3E68 + (unsigned int)(uVar15 << 7);

      local_90[0] = (char *)local_90;

      (*(int(*)())0x060358EC)();

      local_98 = 0x40F00000;

      local_9c = auStack_88;

      pppiVar26 = (int ***)&local_9c;

      (*(int(*)())0x060359E4)();

      iVar16 = (*(int(*)())0x060357B8)();

      *(int *)(puVar17 + 0x54) = iVar16 + *(int *)(puVar17 + 4);

    }

    *pppiVar26 = (int **)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    ((int *)pppiVar26)[-1] = (int)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x58);

    uVar14 = FUN_0603da88(0);

    *(int *)((int *)pppiVar26)[-1] = uVar14;

    ((int *)pppiVar26)[-1] = (int)*pppiVar26 + 0x5c;

    uVar14 = FUN_0603d9ec(0);

    *(int *)((int *)pppiVar26)[-1] = uVar14;

    puVar17 = (char *)0x060A4C38;

    *(unsigned int *)(0x060A4C38 + (unsigned int)(uVar15 << 2)) = *(unsigned short *)0x060635B0 - 1;

    ((int *)pppiVar26)[4] = (int)(puVar17 + (unsigned int)(uVar15 << 2));

    ((int *)pppiVar26)[3] = (int)(0x060A53B8 + (char)(cVar24 * '$') + 0x1c);

    ((int *)pppiVar26)[5] = (int)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    ((int *)pppiVar26)[1] = (int)(0x060A3F68 + (short)(uVar15 * PTR_DAT_0603e53c));

    psVar12 = (short *)0x060A3F68;

    for (uVar21 = 0; uVar21 < *(unsigned int *)((int *)pppiVar26)[4]; uVar21 = uVar21 + 1) {

      *pppiVar26 = (int **)(*(int *)((int *)pppiVar26)[3] *

                            (uVar21 - (int)*(short *)(((int *)pppiVar26)[5] + 0x36)) +

                           ((int *)pppiVar26)[2]);

      iVar16 = (*(int(*)())0x06034FFC)();

      if (iVar16 == 0) {

        psVar12 = (short *)((uVar21 << 1) + ((int *)pppiVar26)[1]);

LAB_0603e58c:

        *psVar12 = (short)puVar6;

      }

      else {

        iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26);

        if (((int)puVar5 < -iVar16) || (iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26), -iVar16 < 0))

        {

          psVar12 = (short *)((uVar21 << 1) + ((int *)pppiVar26)[1]);

          goto LAB_0603e58c;

        }

        ((int *)pppiVar26)[-1] = (uVar21 << 1) + ((int *)pppiVar26)[1];

        iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26);

        psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & (int)DAT_0603e61e);

        *(short *)((int *)pppiVar26)[-1] = (short)psVar12;

      }

    }

  }

  else {

    *(char **)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x54) =

         0x012C0000 + *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 4);

    local_7c = (int **)((unsigned int)(uVar15 << 2));

    local_78 = (unsigned int **)(0x060A4C70 + (int)local_7c);

    uVar14 = FUN_0603da88(*local_78);

    *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x58) = uVar14;

    uVar14 = FUN_0603d9ec(*local_78);

    *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x5c) = uVar14;

    puVar17 = (char *)0x060A4C38;

    *(int *)(0x060A4C38 + (int)local_7c) = (int)DAT_0603e3b6;

    local_70 = (unsigned int *)(puVar17 + (unsigned int)(uVar15 << 2));

    local_6c = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x1c);

    piStack_68 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    local_78 = (unsigned int **)(0x060A3F68 + (short)(uVar15 * DAT_0603e3b8));

    psVar12 = (short *)0x060A3F68;

    for (uVar21 = 0; uVar21 < *local_70; uVar21 = uVar21 + 1) {

      local_7c = (int **)(*local_6c *

                          ((uVar21 - (int)*(short *)((int)piStack_68 + 0x36)) + (int)DAT_0603e3ba) +

                         (int)local_74);

      iVar16 = (*(int(*)())0x06034FFC)();

      if (iVar16 == 0) {

        psVar12 = (short *)((int)local_78 + (uVar21 << 1));

LAB_0603e3dc:

        *psVar12 = (short)puVar6;

      }

      else {

        iVar16 = (*(int(*)())puVar7)(iVar13,local_7c);

        if (((int)puVar5 < -iVar16) || (iVar16 = (*(int(*)())puVar7)(iVar13,local_7c), -iVar16 < 0)) {

          psVar12 = (short *)((int)local_78 + (uVar21 << 1));

          goto LAB_0603e3dc;

        }

        local_80 = (short *)((int)local_78 + (uVar21 << 1));

        iVar16 = (*(int(*)())puVar7)(iVar13,local_7c);

        psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & (int)DAT_0603e3bc);

        *local_80 = (short)psVar12;

      }

    }

  }

  *(short *)(0x060A4C40 + (unsigned int)(uVar15 << 1)) = 1;

  return psVar12;

}
