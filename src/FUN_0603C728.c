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

extern int PTR_DAT_0603c7ec;

extern int PTR_DAT_0603c7ec;

extern int FUN_0603c1a8();
extern int FUN_0603cc88();

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

  puVar4 = 0x060A4DA5;

  puVar3 = 0x060A4DA4;

  puVar2 = 0x060A4DA6;

  iVar6 = (int)DAT_0603c7e6;

  iVar7 = (int)DAT_0603c7e8;

  uVar8 = (unsigned int)DAT_0603c7ea;

  uVar5 = (unsigned int)(unsigned char)*0x060A4DA6;

  if (uVar5 == 1) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      *(int *)0x060A4DA6 = 0;

      puVar3 = 0x060A4DA8;

      for (uVar5 = 0; uVar5 < *(unsigned int *)0x060A4D94; uVar5 = uVar5 + 1) {

        if ((unsigned char)(puVar3 + uVar5)[iVar7] < (unsigned char)puVar3[uVar5]) {

          puVar3[iVar7 + uVar5] = puVar3[iVar7 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[uVar5] < (unsigned char)(puVar3 + uVar5)[iVar7]) {

          puVar3[iVar7 + uVar5] = puVar3[iVar7 + uVar5] + -1;

          *puVar2 = 1;

        }

        if ((unsigned char)puVar3[uVar8 + uVar5] < (unsigned char)puVar3[(int)PTR_DAT_0603c7ec + uVar5]) {

          puVar3[uVar8 + uVar5] = puVar3[uVar8 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[(int)DAT_0603c8d0 + uVar5] < (unsigned char)puVar3[uVar8 + uVar5]) {

          puVar3[uVar8 + uVar5] = puVar3[uVar8 + uVar5] + -1;

          *puVar2 = 1;

        }

        if ((unsigned char)puVar3[iVar6 + uVar5] < (unsigned char)puVar3[(int)DAT_0603c8d2 + uVar5]) {

          puVar3[iVar6 + uVar5] = puVar3[iVar6 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[(int)DAT_0603c8d2 + uVar5] < (unsigned char)puVar3[iVar6 + uVar5]) {

          puVar3[iVar6 + uVar5] = puVar3[iVar6 + uVar5] + -1;

          *puVar2 = 1;

        }

      }

      *(int *)0x060A4D8C = 0;

      puVar3 = 0x060A4DA8;

      puVar2 = 0x060A4DA8;

      uVar5 = (int)((unsigned int)*(unsigned short *)0x060A3D96 & (int)DAT_0603c8d4) >> 0xc;

      if (uVar5 == 2) {

        for (local_40 = 0; local_40 < *(unsigned int *)0x060A4D94; local_40 = local_40 + 1) {

          local_24[0] = (unsigned int)CONCAT21(CONCAT11(puVar2[iVar7 + local_40],puVar2[uVar8 + local_40]),

                                       puVar2[iVar6 + local_40]);

          uVar5 = (*(void(*)())0x060429EC)(*(int *)0x060A4D84,*(int *)0x060A4D90 + local_40,1,

                             local_24);

        }

      }

      else {

        for (uStack_3c = 0; uStack_3c < *(unsigned int *)0x060A4D94; uStack_3c = uStack_3c + 1) {

          local_24[0] = (unsigned int)(unsigned char)puVar3[iVar6 + uStack_3c] |

                        ((unsigned int)(unsigned char)puVar3[uVar8 + uStack_3c] |

                        (unsigned int)(unsigned char)puVar3[iVar7 + uStack_3c] << 5) << 5;

          uVar5 = (*(void(*)())0x060429EC)(*(int *)0x060A4D84,*(int *)0x060A4D90 + uStack_3c,1,

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

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cad8) != 0) {

        FUN_0603c1a8((int)DAT_0603cad8,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cada) != 0) {

        FUN_0603c1a8((int)DAT_0603cada,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & uVar8) != 0) {

        FUN_0603c1a8(uVar8,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cadc) != 0) {

        FUN_0603c1a8((int)DAT_0603cadc,(int)(char)*puVar3);

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

        uVar5 = FUN_0603c1a8((int)DAT_0603cba2,(int)(char)*puVar3);

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

      puVar3 = 0x060A4D9E;

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
