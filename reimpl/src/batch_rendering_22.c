extern int DAT_060222e6;
extern int DAT_060224b6;
extern int DAT_060224b8;
extern int DAT_060224ba;
extern int DAT_06022652;
extern int DAT_0602271e;
extern int DAT_060238fa;
extern int DAT_060238fc;
extern int DAT_060238fe;
extern int DAT_06023900;
extern int DAT_06023902;
extern int DAT_06023904;
extern int DAT_06023906;
extern int DAT_06023908;
extern int DAT_0602390a;
extern int DAT_06023a54;
extern int DAT_06023a56;
extern int DAT_06023a58;
extern int DAT_06023a5a;
extern int DAT_06023a5c;
extern int DAT_06023a5e;
extern int DAT_06023a60;
extern int DAT_06023a62;
extern int DAT_06023ba8;
extern int DAT_06023baa;
extern int DAT_06023bac;
extern int DAT_06023bae;
extern int DAT_06023bb0;
extern int DAT_06023bb2;
extern int DAT_06023cf8;
extern int DAT_06023cfa;
extern int DAT_06023cfc;
extern int DAT_06023cfe;
extern int DAT_06023d00;
extern int DAT_06023d02;
extern int DAT_06023e4e;
extern int DAT_06023e50;
extern int DAT_06023e52;
extern int DAT_060242e0;
extern int DAT_060242e2;
extern int DAT_060242e4;
extern int DAT_060242e6;
extern int DAT_06024506;
extern int DAT_06024508;
extern int DAT_06024552;
extern int DAT_0602461c;
extern int DAT_0602461e;
extern int DAT_06024620;
extern int DAT_06024622;
extern int DAT_06024624;
extern int DAT_06024626;
extern int DAT_06024628;
extern int DAT_0602462a;
extern int DAT_0602462c;
extern int DAT_0602462e;
extern int DAT_06024630;
extern int DAT_06024632;
extern int DAT_06024634;
extern int DAT_06024636;
extern int DAT_06024638;
extern int DAT_06024782;
extern int DAT_06024784;
extern int DAT_06024786;
extern int DAT_06024788;
extern int DAT_0602478a;
extern int DAT_060248ba;
extern int DAT_060248bc;
extern int DAT_060248be;
extern int DAT_06024a06;
extern int DAT_06024a08;
extern int DAT_06024a0a;
extern int DAT_06024a0c;
extern int DAT_06024a0e;
extern int DAT_06024b52;
extern int DAT_06024b54;
extern int DAT_06024b56;
extern int DAT_06024b58;
extern int DAT_06024b5a;
extern int DAT_06024c9c;
extern int DAT_06024c9e;
extern int DAT_06024ca0;
extern int DAT_06024ca2;
extern int DAT_06024d0a;
extern int DAT_06025136;
extern int DAT_0602528a;
extern int DAT_0602528c;
extern int DAT_0602528e;
extern int DAT_06025290;
extern int DAT_06025292;
extern int DAT_06025378;
extern int DAT_0602537a;
extern int DAT_0602537c;
extern int DAT_0602537e;
extern int DAT_06025380;
extern int DAT_06025382;
extern int DAT_06025384;
extern int DAT_06025386;
extern int DAT_06025388;
extern int DAT_0602538a;
extern int DAT_060254de;
extern int DAT_060254e0;
extern int DAT_060254e2;
extern int DAT_060254e4;
extern int DAT_060254e6;
extern int DAT_060255cc;
extern int DAT_060255ce;
extern int DAT_060255d0;
extern int DAT_060255d2;
extern int DAT_060255d4;
extern int DAT_060255d6;
extern int DAT_060255d8;
extern int DAT_060255da;
extern int DAT_060255dc;
extern int DAT_060255de;
extern int DAT_06025746;
extern int DAT_0602596a;
extern int DAT_06025a80;
extern int DAT_06025c6e;
extern int DAT_06025e94;
extern int DAT_06025fac;
extern int DAT_06026016;
extern void FUN_06025224();
extern void FUN_06025478();
extern int FUN_060262c0();
extern int FUN_060263ec();
extern int PTR_DAT_06023a64;
extern int PTR_DAT_06023bb4;
extern int PTR_DAT_06023d04;
extern int PTR_DAT_06023e54;
extern int PTR_DAT_060243e8;
extern int PTR_DAT_060248c0;
extern int PTR_DAT_06024ca4;
extern int PTR_DAT_06025210;
extern int PTR_DAT_0602538c;
extern int PTR_DAT_060255e0;
extern int PTR_DAT_06025748;
extern int PTR_DAT_06025bb8;
extern int PTR_DAT_06025c70;

void FUN_06022140()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int uVar6;

  int iVar7;

  int *puVar8;

  int iVar9;

  unsigned int uVar10;

  int *piVar11;

  int iVar12;

  int iVar13;

  unsigned int uVar14;

  short sVar15;

  char *local_48;

  int iStack_40;

  unsigned short auStack_3c [2];

  char *puStack_38;

  short *psStack_34;

  int iStack_30;

  char *puStack_2c;

  int iStack_28;

  puVar5 = (char *)0x060895A0;

  puVar4 = (char *)0x060897D0;

  puVar3 = (char *)0x060896B8;

  puVar2 = (char *)0x06027552;

  puVar1 = (char *)0x03E80000;

  iVar7 = *(int *)0x0607E944;

  puStack_38 = (char *)0x06089C58;

  psStack_34 = (short *)0x06089E98;

  uVar14 = 0;

  do {

    if (*(unsigned int *)0x06089E24 <= uVar14) {

      return;

    }

    sVar15 = (short)uVar14;

    iVar12 = *(int *)(puVar4 + (short)(sVar15 * 0x18));

    iVar9 = iVar12 - *(int *)(iVar7 + 0x10);

    if (iVar9 < 0) {

      iVar9 = *(int *)(iVar7 + 0x10) - iVar12;

    }

    iVar12 = *(int *)((int)(puVar4 + (short)(sVar15 * 0x18)) + 8);

    iVar13 = iVar12 - *(int *)(iVar7 + 0x18);

    if (iVar13 < 0) {

      iVar13 = *(int *)(iVar7 + 0x18) - iVar12;

    }

    if ((iVar9 < (int)0x006A0000) && (iVar13 < (int)0x006A0000)) {

      if (*(int *)(0x0608962C + (uVar14 << 2)) == 0) {

        if (iVar13 < iVar9) {

          uVar10 = iVar9 + (iVar13 >> 2);

        }

        else {

          uVar10 = (iVar9 >> 2) + iVar13;

        }

        if (*(unsigned int *)(0x06050788 + *(int *)(puVar5 + (uVar14 << 2)) << 2) < uVar10) {

          piVar11 = (int *)(puVar4 + (short)(sVar15 * 0x18));

          iStack_30 = *piVar11;

          iStack_28 = piVar11[2];

          if (piVar11[1] == 0) {

            puStack_2c = puVar1;

            uVar6 = (*(int(*)())0x06006838)(iStack_30,iStack_28);

            (*(int(*)())0x06027EDE)(uVar6,&iStack_30,auStack_3c);

            if ((puStack_2c == puVar1) ||

               ((*(unsigned int *)(0x060A6000 + (unsigned int)auStack_3c[0] * 0x34) & 0x80) != 0)) {

              *(int *)(puVar4 + (short)(sVar15 * 0x18)) = 0x4E200000;

              goto LAB_060227ca;

            }

            puStack_2c = puStack_2c + DAT_060222e6;

            if (*(int *)(puVar5 + (uVar14 << 2)) == 3) {

              puStack_2c = puStack_2c + (int)0x00013333;

            }

            if (*(int *)(puVar5 + (uVar14 << 2)) == 4) {

              puStack_2c = puStack_2c + (int)0x0000CCCC;

            }

          }

          else {

            puStack_2c = *(char **)(puVar4 + (short)(sVar15 * 0x18) + 4);

          }

        }

        else {

          *(int *)(0x0608962C + (uVar14 << 2)) = 1;

          *(int *)(puVar4 + (short)(sVar15 * 0x18) + 4) = 0;

          uVar6 = (*(int(*)())puVar2)(*(int *)(iVar7 + 0xc),

                                    *(int *)

                                     (0x06089E08 + *(int *)(puVar5 + (uVar14 << 2)) << 2));

          if (*(int *)(iVar7 + 8) < 0x47) {

            if (*(int *)(iVar7 + 8) < 0x1f) {

              iStack_40 = (*(int(*)())puVar2)(uVar6,0x00013333);

              iVar9 = (uVar14 << 2);

              iStack_40 = iStack_40 + DAT_060224b6;

              *(char **)(0x06089744 + iVar9) = 0x00020000;

              if ((*(int *)(puVar5 + iVar9) == 3) || (*(int *)(puVar5 + iVar9) == 4)) {

                uVar6 = 0xe;

              }

              else {

                uVar6 = 0x16;

              }

              *(int *)(puVar3 + iVar9) = uVar6;

            }

            else {

              iStack_40 = (*(int(*)())puVar2)(uVar6,0x00014CCC);

              iVar9 = (uVar14 << 2);

              puVar8 = (int *)(0x06089744 + iVar9);

              uVar6 = (*(int(*)())puVar2)(*(int *)(iVar7 + 0xc),0x00030000);

              *puVar8 = uVar6;

              if ((*(int *)(puVar5 + iVar9) == 3) || (*(int *)(puVar5 + iVar9) == 4)) {

                uVar6 = 0xe;

              }

              else {

                uVar6 = 4;

              }

              *(int *)(puVar3 + iVar9) = uVar6;

            }

          }

          else {

            iStack_40 = (*(int(*)())puVar2)(uVar6,0x00014CCC);

            iVar9 = (uVar14 << 2);

            *(int *)(0x06089744 + iVar9) = iStack_40;

            iVar12 = *(int *)(puVar5 + iVar9);

            if (((iVar12 == 0) || (iVar12 == 3)) || (iVar12 == 4)) {

              uVar6 = 0;

            }

            else {

              uVar6 = 4;

            }

            *(int *)(puVar3 + iVar9) = uVar6;

          }

          iVar9 = 0x380;

          uVar10 = *(unsigned int *)(iVar7 + 8);

          iVar13 = *(int *)(iVar7 + 0x28);

          iVar12 = -448;

          if ((*(int *)(puVar5 + (uVar14 << 2)) == 3) || (*(int *)(puVar5 + (uVar14 << 2)) == 4)) {

            *(char **)(0x06089744 + (uVar14 << 2)) = 0x00018000;

          }

          *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14) = 0;

          *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16) = (short)*(int *)(iVar7 + 0x28);

          (*(int(*)())0x06027358)(iVar13 + (uVar10 & 1) * iVar9 + iVar12,puVar4 + (short)(sVar15 * 0x18) + 0xc,

                     puVar4 + (short)(sVar15 * 0x18) + 0x10);

          uVar6 = (*(int(*)())puVar2)(iStack_40,*(int *)(puVar4 + (short)(sVar15 * 0x18) + 0xc)

                                   );

          *(int *)(puVar4 + (short)(sVar15 * 0x18) + 0xc) = uVar6;

          uVar6 = (*(int(*)())puVar2)(iStack_40,

                                    *(int *)(puVar4 + (short)(sVar15 * 0x18) + 0x10));

          *(int *)(puVar4 + (short)(sVar15 * 0x18) + 0x10) = uVar6;

          if (*(int *)(puVar5 + (uVar14 << 2)) == 0) {

            (*(int(*)())0x0601D5F4)(0,0xAE110BFF);

          }

          else {

            (*(int(*)())0x0601D5F4)(0,0xAE110DFF);

          }

LAB_060224e0:

          if (*(unsigned int *)(puVar3 + (uVar14 << 2)) < 0x28) {

            if ((*(int *)(puVar5 + (uVar14 << 2)) == 3) || (*(int *)(puVar5 + (uVar14 << 2)) == 4)) {

              local_48 = puStack_38;

            }

            else {

              local_48 = (char *)0x06089B18;

            }

            piVar11 = (int *)(puVar4 + (short)(sVar15 * 0x18));

            *piVar11 = *piVar11 - piVar11[3];

            piVar11[2] = piVar11[2] + piVar11[4];

            iStack_30 = *piVar11;

            iStack_28 = piVar11[2];

            puStack_2c = puVar1;

            uVar6 = (*(int(*)())0x06006838)(iStack_30,iStack_28);

            (*(int(*)())0x06027EDE)(uVar6,&iStack_30,auStack_3c);

            if ((puStack_2c == puVar1) ||

               ((*(unsigned int *)(0x060A6000 + (unsigned int)auStack_3c[0] * 0x34) & 0x80) != 0)) {

              *(int *)(puVar4 + (short)(sVar15 * 0x18)) = 0x4E200000;

              *(int *)(puVar3 + (uVar14 << 2)) = 0;

              goto LAB_060226d6;

            }

            iVar9 = (uVar14 << 2);

            iVar12 = (*(int(*)())puVar2)(*(int *)(0x06089744 + iVar9),

                                       *(int *)(local_48 + (*(int *)(puVar3 + iVar9) << 3)));

            puStack_2c = puStack_2c + DAT_06022652 + iVar12;

            if (*(int *)(puVar5 + iVar9) == 3) {

              puStack_2c = puStack_2c + (int)0x00013333;

            }

            if (*(int *)(puVar5 + (uVar14 << 2)) == 4) {

              puStack_2c = puStack_2c + (int)0x0000CCCC;

            }

            piVar11 = (int *)(puVar3 + (uVar14 << 2));

            *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14) =

                 *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14) +

                 *(short *)(local_48 + (*piVar11 << 3) + 4);

            *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16) =

                 *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16) +

                 *(short *)(local_48 + (*piVar11 << 3) + 6);

            *piVar11 = *piVar11 + 1;

          }

          else {

            iStack_30 = *(int *)(puVar4 + (short)(sVar15 * 0x18));

            iStack_28 = *(int *)((int)(puVar4 + (short)(sVar15 * 0x18)) + 8);

            puStack_2c = puVar1;

            uVar6 = (*(int(*)())0x06006838)(iStack_30,iStack_28);

            (*(int(*)())0x06027EDE)(uVar6,&iStack_30,auStack_3c);

            if ((puStack_2c == puVar1) ||

               ((*(unsigned int *)(0x060A6000 + (unsigned int)auStack_3c[0] * 0x34) & 0x80) != 0)) {

              *(int *)(puVar4 + (short)(sVar15 * 0x18)) = 0x4E200000;

              *(int *)(puVar3 + (uVar14 << 2)) = 0;

LAB_060226d6:

              *(int *)(0x0608962C + (uVar14 << 2)) = 0;

              goto LAB_060227ca;

            }

            puStack_2c = puStack_2c + DAT_0602271e;

            if (*(int *)(puVar5 + (uVar14 << 2)) == 3) {

              puStack_2c = puStack_2c + (int)0x00013333;

            }

            if (*(int *)(puVar5 + (uVar14 << 2)) == 4) {

              puStack_2c = puStack_2c + (int)0x0000CCCC;

            }

            *(int *)(puVar3 + (uVar14 << 2)) = 0;

            *(int *)(0x0608962C + (uVar14 << 2)) = 0;

          }

        }

      }

      else if (*(int *)(0x0608962C + (uVar14 << 2)) == 1) goto LAB_060224e0;

      (*(int(*)())0x06026DBC)();

      (*(int(*)())0x06026E2E)(iStack_30,puStack_2c,iStack_28);

      (*(int(*)())0x06026EDE)((int)*(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16));

      (*(int(*)())0x06026E94)((int)*(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14));

      iVar9 = *(int *)(puVar5 + (uVar14 << 2)) << 2;

      (*(int(*)())0x06031D8C)(*(int *)(0x06089D98 + iVar9),*(int *)(0x06089DB4 + iVar9)

                );

      iVar9 = *(int *)(puVar5 + (uVar14 << 2)) << 2;

      (*(int(*)())0x06031A28)(*(int *)(0x06089DD0 + iVar9),(int)*psStack_34,

                 *(int *)(0x06089DEC + iVar9));

      (*(int(*)())0x06026DF8)();

    }

LAB_060227ca:

    uVar14 = uVar14 + 1;

  } while( 1 );

}

int FUN_0602382c()
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  *(short *)0x06089E44 = 0;

  (*(int(*)())0x06007658)(1,0x108,0,0x002A299B);

  (*(int(*)())0x06007658)(2,0x810,0,0x002A29A3);

  (*(int(*)())0x06007658)(3,(int)DAT_060238fe,0,0x002A2A53);

  (*(int(*)())0x06007658)(4,(int)DAT_06023900,0,0x002A2B27);

  (*(int(*)())0x06007658)(5,0x519,0,0x002A2E73);

  (*(int(*)())0x06007658)(6,(int)DAT_06023904,0,0x002A2F93);

  (*(int(*)())0x06007658)(7,0x738,4,0x002A3027);

  (*(int(*)())0x06007658)(8,0x738,4,0x002A325B);

  (*(int(*)())0x06007658)(9,0x208,0,0x002A3433);

  (*(int(*)())0x06007658)(10,0xa28,0x3c,0x002A3457);

  (*(int(*)())0x06007658)(0x10,0x228,8,0x002A0640);

  (*(int(*)())0x06007658)(0x11,0x428,8,0x002A06AC);

  (*(int(*)())0x06007658)(0x12,0x418,8,0x002A074C);

  (*(int(*)())0x06007658)(0x13,0x820,8,0x002A07E4);

  (*(int(*)())0x06007658)(0x14,0x518,8,0x002A09B4);

  (*(int(*)())0x06007658)(0x15,0x518,8,0x002A0A34);

  (*(int(*)())0x06007658)(0x16,0x508,0xc,0x002A0AA4);

  (*(int(*)())0x06007658)(0x17,0xd10,8,0x002A0AD8);

  (*(int(*)())0x06007658)(0x18,(int)DAT_06023a62,0x1c,0x002A0C14);

  (*(int(*)())0x06007658)(0x19,0x348,0x10,0x002A0D7C);

  (*(int(*)())0x06007658)(0x1a,0x348,0x10,0x002A0F58);

  (*(int(*)())0x06007658)(0x1b,0x348,0x10,0x002A1140);

  (*(int(*)())0x06007658)(0x1c,0x630,0x1c,0x002A12F8);

  (*(int(*)())0x06007658)(0x1d,0xa28,0x10,0x002A1484);

  (*(int(*)())0x06007658)(0x1e,0xc08,0x18,0x002A1890);

  (*(int(*)())0x06007658)(0x1f,0xc10,0x18,0x002A1908);

  (*(int(*)())0x06007658)(0x20,0x308,0xc,0x002A1AC4);

  (*(int(*)())0x06007658)(0x21,0x410,0xc,0x002A1B04);

  (*(int(*)())0x06007658)(0x22,0x308,0xc,0x002A1B9C);

  (*(int(*)())0x06007658)(0x23,0x308,0xc,0x002A1BC8);

  (*(int(*)())0x06007658)(0x24,0x410,0xc,0x002A1C04);

  (*(int(*)())0x06007658)(0x25,(int)DAT_06023cf8,0x14,0x002A1CC8);

  (*(int(*)())0x06007658)(0x26,(int)DAT_06023cf8,0x14,0x002A1D2C);

  (*(int(*)())0x06007658)(0x27,0x610,0xc,0x002A1D84);

  (*(int(*)())0x06007658)(0x28,0x510,0x14,0x002A1E20);

  (*(int(*)())0x06007658)(0x29,0x310,0x14,0x002A1E8C);

  (*(int(*)())0x06007658)(0x2a,(int)DAT_06023d00,0x14,0x002A1EFC);

  (*(int(*)())0x06007658)(0x2b,(int)DAT_06023d02,0x14,0x002A1FC8);

  (*(int(*)())0x06007658)(0x2c,0x110,0xc,0x002A2060);

  (*(int(*)())0x06007658)(0x2d,0x110,0xc,0x002A2080);

  (*(int(*)())0x06007658)(0x2e,0x510,0x14,0x002A20A0);

  (*(int(*)())0x06007658)(0x2f,0x310,0x14,0x002A211C);

  (*(int(*)())0x06007658)(0x30,(int)DAT_06023e50,0x14,0x002A2194);

  (*(int(*)())0x06007658)(0x31,(int)DAT_06023e52,0x14,0x002A225C);

  (*(int(*)())0x06007658)(0x32,0x108,0x14,0x002A22F4);

  (*(int(*)())0x06007658)(0x33,0x108,0x14,0x002A22FC);

  (*(int(*)())0x06007658)(0x34,0x108,0x14,0x002A2304);

  (*(int(*)())0x06007658)(0x35,0x108,0x14,0x002A230C);

  (*(int(*)())0x06007658)(0x36,0x108,0x10,0x002A2314);

  (*(int(*)())0x06007658)(0x37,0x108,0x1c,0x002A231C);

  (*(int(*)())0x06007658)(0x38,0x108,8,0x002A2324);

  (*(int(*)())0x06007658)(0x39,0x108,0x10,0x002A232C);

  *(short *)0x06089E46 = 1;

  (*(int(*)())0x06007540)(0x41,1,0);

  (*(int(*)())0x06007540)(0x42,2,0);

  (*(int(*)())0x06007540)(0x43,3,0);

  (*(int(*)())0x06007540)(0x44,4,0);

  (*(int(*)())0x06007540)(0x45,5,0);

  (*(int(*)())0x06007540)(0x46,6,0);

  (*(int(*)())0x06007540)(0x47,7,4);

  (*(int(*)())0x06007540)(0x48,8,4);

  (*(int(*)())0x06007540)(0x49,9,0);

  (*(int(*)())0x06007540)(0x4a,10,0x3c);

  (*(int(*)())0x06007540)(0x50,0x10,0x20);

  (*(int(*)())0x06007540)(0x51,0x11,0x20);

  (*(int(*)())0x06007540)(0x52,0x12,0x20);

  (*(int(*)())0x06007540)(0x53,0x13,0x20);

  (*(int(*)())0x06007540)(0x54,0x14,0x20);

  (*(int(*)())0x06007540)(0x55,0x15,0x20);

  (*(int(*)())0x06007540)(0x56,0x16,0x24);

  (*(int(*)())0x06007540)(0x57,0x17,0x20);

  (*(int(*)())0x06007540)(0x58,0x18,0x34);

  (*(int(*)())0x06007540)(0x59,0x19,0x28);

  (*(int(*)())0x06007540)(0x5a,0x1a,0x28);

  (*(int(*)())0x06007540)(0x5b,0x1b,0x28);

  (*(int(*)())0x06007540)(0x5c,0x1c,0x34);

  (*(int(*)())0x06007540)(0x5d,0x1d,0x28);

  (*(int(*)())0x06007540)(0x5e,0x1e,0x30);

  (*(int(*)())0x06007540)(0x5f,0x1f,0x30);

  (*(int(*)())0x06007540)(0x60,0x20,0x24);

  (*(int(*)())0x06007540)(0x61,0x21,0x24);

  (*(int(*)())0x06007540)(0x62,0x22,0x24);

  (*(int(*)())0x06007540)(99,0x23,0x24);

  (*(int(*)())0x06007540)(100,0x24);

  (*(int(*)())0x06007540)(0x65,0x25,0x2c);

  (*(int(*)())0x06007540)(0x66,0x26,0x2c);

  (*(int(*)())0x06007540)(0x67,0x27,0x24);

  (*(int(*)())0x06007540)(0x68,0x28,0x2c);

  (*(int(*)())0x06007540)(0x69,0x29,0x2c);

  (*(int(*)())0x06007540)(0x6a,0x2a,0x2c);

  (*(int(*)())0x06007540)(0x6b,0x2b,0x2c);

  (*(int(*)())0x06007540)(0x6c,0x2c,0x24);

  (*(int(*)())0x06007540)(0x6d,0x2d,0x24);

  (*(int(*)())0x06007540)(0x6e,0x2e,0x2c);

  (*(int(*)())0x06007540)(0x6f,0x2f,0x2c);

  (*(int(*)())0x06007540)(0x70,0x30,0x2c);

  (*(int(*)())0x06007540)(0x71,0x31,0x2c);

  (*(int(*)())0x06007540)(0x72,0x32,0x2c);

  (*(int(*)())0x06007540)(0x73,0x33,0x2c);

  (*(int(*)())0x06007540)(0x74,0x34,0x2c);

  (*(int(*)())0x06007540)(0x75,0x35,0x2c);

  (*(int(*)())0x06007540)(0x76,0x36,0x28);

  (*(int(*)())0x06007540)(0x77,0x37,0x34);

  (*(int(*)())0x06007540)(0x78,0x38,0x20);

  (*(int(*)())0x06007540)(0x79,0x39,0x28);

  *(short *)0x06089E9C = 0x38;

  uVar1 = DAT_060242e0;

  (*(int(*)())0x06007658)(DAT_060242e0 + 0x10,0x630,0x40,0x002A3987);

  (*(int(*)())0x06007658)(uVar1 + 0x11,0x630,0x74,0x002A3C2F);

  (*(int(*)())0x06007658)(uVar1 + 0x12,0x630,0x74,0x002A3D23);

  (*(int(*)())0x06007658)(uVar1 + 0x13,0x630,0x74,0x002A3E23);

  *(short *)0x06089EA0 = 0x3a;

  uVar1 = DAT_060242e4;

  if (*(int *)0x0607EAB8 == 0) {

    (*(int(*)())0x06007658)(DAT_060242e4,0x210,0x38,0x002A452A);

    (*(int(*)())0x06007658)(uVar1 + 1,0x210,0x38,0x002A455C);

    (*(int(*)())0x06007658)(uVar1 + 2,0x210,0x38,0x002A45CD);

    (*(int(*)())0x06007658)(uVar1 + 3,0x210,0x38,0x002A463C);

  }

  else {

    (*(int(*)())0x06007658)(DAT_060242e4,0x210,0x38,0x002A43A6);

    (*(int(*)())0x06007658)(uVar1 + 1,0x210,0x38,0x002A43D8);

    (*(int(*)())0x06007658)(uVar1 + 2,0x210,0x38,0x002A4450);

    (*(int(*)())0x06007658)(uVar1 + 3,0x210,0x38,0x002A44BF);

  }

  if (*(int *)0x06078635 == '\0') {

    (*(int(*)())0x06007658)(uVar1 + 4,0x210,0x38,0x002A4836);

    (*(int(*)())0x06007658)(uVar1 + 5,0x210,0x38,0x002A4862);

    (*(int(*)())0x06007658)(uVar1 + 6,0x210,0x38,0x002A48CF);

    (*(int(*)())0x06007658)(uVar1 + 7,0x210,0x38,0x002A4946);

    (*(int(*)())0x06007658)(uVar1 + 8,0x210,0x38,0x002A49B3);

    (*(int(*)())0x06007658)(uVar1 + 9,0x210,0x38,0x002A49F0);

    (*(int(*)())0x06007658)(uVar1 + 10,0x210,0x38,0x002A4A61);

    (*(int(*)())0x06007658)(uVar1 + 0xb,0x210,0x38,0x002A4AD7);

  }

  else {

    (*(int(*)())0x06007658)(uVar1 + 4,0x210,0x38,0x002A46AC);

    (*(int(*)())0x06007658)(uVar1 + 5,0x210,0x38,0x002A46DE);

    (*(int(*)())0x06007658)(uVar1 + 6,0x210,0x38,0x002A4753);

    (*(int(*)())0x06007658)(uVar1 + 7,0x210,0x38,0x002A47C4);

  }

  iVar3 = *(int *)0x0607EAD8;

  if (iVar3 == 0) {

    (*(int(*)())0x06007658)(uVar1 + 0xc,0x940,0x38,0x002A3F1F);

  }

  else if (iVar3 == 1) {

    (*(int(*)())0x06007658)(uVar1 + 0xc,0x940,0x38,0x002A405A);

  }

  else if (iVar3 == 2) {

    (*(int(*)())0x06007658)(uVar1 + 0xc,0xc40,0x38,0x002A41C5);

  }

  (*(int(*)())0x06007658)((int)DAT_0602461e,0x418,0x4c,0x002A7A5E);

  puVar2 = (char *)0x06085F98;

  *(int *)0x06085F98 = *(int *)0x0606A4F4;

  *(int *)puVar2 = *(int *)puVar2 + -1;

  (*(int(*)())0x06007658)(0xe98,0x418,0x4c,0x002A7AC5);

  (*(int(*)())0x06007658)(0xe99,0x418,0x4c,0x002A7B1F);

  (*(int(*)())0x06007658)(0xe9a,0x418,0x4c,0x002A7BA0);

  (*(int(*)())0x06007658)(0xe9b,0x418,0x4c,0x002A7BE9);

  (*(int(*)())0x06007658)((int)DAT_06024628,0x418,0x4c,0x002A7C3B);

  (*(int(*)())0x06007540)(DAT_06024624 + 3,0xe9a,0x50);

  (*(int(*)())0x06007658)((int)DAT_0602462a,0x418,0x4c,0x002A7CA5);

  (*(int(*)())0x06007658)((int)DAT_0602462c,0x418,0x4c,0x002A7CFA);

  (*(int(*)())0x06007658)(0xe90,0x110,0x44,0x002A8B47);

  (*(int(*)())0x06007658)(0xe91,0x210,0x44,0x002A8B7E);

  (*(int(*)())0x06007658)(0xe92,0x420,0x48,0x002A8BBB);

  (*(int(*)())0x06007540)(DAT_06024638 + 1,0xe92,0x4c);

  (*(int(*)())0x06007540)(DAT_06024638 + 2,0xe92,0x50);

  (*(int(*)())0x06007540)(DAT_06024782 + 3,0xe92,0x54);

  (*(int(*)())0x06007658)((int)DAT_06024786,(int)DAT_06024784,0x58,0x002A92CB);

  *(short *)0x06089E9E = 0x39;

  uVar1 = DAT_06024788;

  (*(int(*)())0x06007540)(DAT_06024788 + 1,1,0);

  (*(int(*)())0x06007540)(uVar1 + 2,2,0);

  (*(int(*)())0x06007540)(uVar1 + 3,3,0);

  (*(int(*)())0x06007540)(uVar1 + 4,4,0);

  (*(int(*)())0x06007540)(uVar1 + 5,5,0);

  (*(int(*)())0x06007540)(uVar1 + 6,6,0);

  (*(int(*)())0x06007540)(uVar1 + 7,7,4);

  (*(int(*)())0x06007540)(uVar1 + 8,8,4);

  (*(int(*)())0x06007540)(uVar1 + 9,9,0);

  (*(int(*)())0x06007540)(uVar1 + 10,10,0x3c);

  (*(int(*)())0x06007658)(uVar1 + 0x10,0x108,0x68,0x002A7D76);

  (*(int(*)())0x06007658)(uVar1 + 0x11,0x108,0x68,0x002A7D8E);

  (*(int(*)())0x06007658)(uVar1 + 0x12,0x108,0x6c,0x002A7DA6);

  (*(int(*)())0x06007658)(uVar1 + 0x13,0x108,0x6c,0x002A7DC6);

  (*(int(*)())0x06007658)(uVar1 + 0x14,0x108,0x6c,0x002A7DE6);

  (*(int(*)())0x06007658)(uVar1 + 0x15,(int)DAT_060248bc,0x6c,0x002A7DF2);

  (*(int(*)())0x06007658)(uVar1 + 0x16,0x108,0x68,0x002A7E0A);

  (*(int(*)())0x06007658)(uVar1 + 0x17,(int)DAT_060248be,0x6c,0x002A7E16);

  (*(int(*)())0x06007658)(uVar1 + 0x18,0x108,0x68,0x002A7E9E);

  (*(int(*)())0x06007658)(uVar1 + 0x19,0x108,100,0x002A7EB6);

  (*(int(*)())0x06007658)(uVar1 + 0x1a,0x208,100,0x002A7ECA);

  (*(int(*)())0x06007658)(uVar1 + 0x1b,0x108,0x6c,0x002A7EFE);

  (*(int(*)())0x06007658)(uVar1 + 0x1c,0x108,0x6c,0x002A7F0A);

  (*(int(*)())0x06007658)(uVar1 + 0x1d,0x108,0x6c,0x002A7F12);

  (*(int(*)())0x06007658)(uVar1 + 0x1e,0x108,0x6c,0x002A7F1A);

  (*(int(*)())0x06007658)(uVar1 + 0x1f,(int)DAT_06024a08,100,0x002A7F3A);

  (*(int(*)())0x06007658)(uVar1 + 0x20,(int)DAT_06024a0a,100,0x002A7FB6);

  (*(int(*)())0x06007658)(uVar1 + 0x21,0x508,0x6c,0x002A8072);

  (*(int(*)())0x06007658)(uVar1 + 0x22,0x210,0x60,0x002A80FA);

  (*(int(*)())0x06007658)(uVar1 + 0x23,0x210,0x60,0x002A8172);

  (*(int(*)())0x06007658)(uVar1 + 0x24,0x210,0x68,0x002A81F6);

  (*(int(*)())0x06007658)(uVar1 + 0x25,0x108,0x6c,0x002A8276);

  (*(int(*)())0x06007658)(uVar1 + 0x26,0x108,0x6c,0x002A8292);

  (*(int(*)())0x06007658)(uVar1 + 0x27,0x108,0x60,0x002A829A);

  (*(int(*)())0x06007658)(uVar1 + 0x28,0x108,0x60,0x002A82A2);

  (*(int(*)())0x06007658)(uVar1 + 0x29,0x108,0x6c,0x002A82B2);

  (*(int(*)())0x06007658)(uVar1 + 0x2a,0x108,0x6c,0x002A82BA);

  (*(int(*)())0x06007658)(uVar1 + 0x2b,(int)DAT_06024b54,100,0x002A82CE);

  (*(int(*)())0x06007658)(uVar1 + 0x2c,0x320,0x6c,0x002A8372);

  (*(int(*)())0x06007658)(uVar1 + 0x2d,0x120,0x6c,0x002A84BE);

  (*(int(*)())0x06007658)(uVar1 + 0x2e,0x108,0x6c,0x002A854A);

  (*(int(*)())0x06007658)(uVar1 + 0x2f,0x308,0x6c,0x002A8572);

  (*(int(*)())0x06007658)(uVar1 + 0x30,0x320,0x60,0x002A85C6);

  (*(int(*)())0x06007658)(uVar1 + 0x31,0x308,0x60,0x002A86EE);

  (*(int(*)())0x06007658)(uVar1 + 0x32,0x110,0x60,0x002A873E);

  (*(int(*)())0x06007658)(uVar1 + 0x33,0x110,0x60,0x002A878A);

  (*(int(*)())0x06007658)(uVar1 + 0x34,0x110,0x68,0x002A87C6);

  (*(int(*)())0x06007658)(uVar1 + 0x39,(int)DAT_06024c9e,100,0x002A8812);

  (*(int(*)())0x06007658)(uVar1 + 0x3a,(int)DAT_06024c9e,100,0x002A8852);

  (*(int(*)())0x06007658)(uVar1 + 0x3b,(int)DAT_06024ca0,100,0x002A8896);

  (*(int(*)())0x06007658)(uVar1 + 0x35,(int)DAT_06024ca2,100,0x002A8906);

  (*(int(*)())0x06007658)(uVar1 + 0x36,(int)PTR_DAT_06024ca4,100,0x002A8926);

  (*(int(*)())0x06007658)(uVar1 + 0x37,(int)DAT_06024ca2,100,0x002A897E);

  (*(int(*)())0x06007658)(uVar1 + 0x38,(int)PTR_DAT_06024ca4,100,0x002A89A6);

  (*(int(*)())0x06007658)(uVar1 + 0x3c,0x108,100,0x002A89F6);

  uVar4 = (*(int(*)())0x06007658)(uVar1 + 0x3d,0x108,100,0x002A8A06);

  return uVar4;

}

void FUN_06025070()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned int uVar7;

  int *puVar8;

  int *puVar9;

  unsigned short *puVar10;

  puVar3 = (char *)0x06059094;

  puVar2 = (char *)0x06060F2C;

  puVar1 = (char *)0x060610BC;

  uVar5 = 0;

  do {

    uVar7 = uVar5 & 0xffff;

    uVar4 = uVar5 & 0xff;

    uVar5 = uVar5 + 1;

    puVar8 = (int *)(puVar2 + (uVar7 << 3));

    *puVar8 = 0;

    *(short *)(puVar8 + 1) = 0;

    *(short *)((int)puVar8 + 6) = DAT_06025136;

    **(short **)(puVar1 + (uVar4 * 0xc & 0xff) + 4) = 0;

  } while ((uVar5 & 0xffff) < 10);

  for (uVar5 = 0; (uVar5 & 0xffff) < 0xe; uVar5 = uVar5 + 1) {

    uVar6 = 0;

    puVar8 = (int *)(0x06060D7C + (uVar5 & 0xffff) << 3);

    uVar4 = (uVar5 & 0xff) * 0xc & 0xff;

    do {

      if ((*(unsigned short *)(puVar3 + (unsigned int)(uVar6 << 1)) & *(unsigned short *)*puVar8) != 0) {

        puVar9 = (int *)(puVar2 + (unsigned int)(uVar6 << 3));

        *puVar9 = *(int *)(puVar1 + uVar4 + 4);

        puVar10 = (unsigned short *)(puVar3 + (unsigned int)(uVar6 << 1));

        *(unsigned short *)(puVar9 + 1) = *puVar10;

        *(short *)((int)puVar9 + 6) = *(short *)(puVar1 + uVar4 + 8);

        *(unsigned short *)*puVar9 = *(unsigned short *)*puVar9 | *puVar10;

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < 10);

  }

  return;

}

void FUN_06025148()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  unsigned int uVar7;

  int *puVar8;

  int *puVar9;

  unsigned short *puVar10;

  puVar3 = (char *)0x060590A8;

  puVar2 = (char *)0x0606107C;

  puVar1 = (char *)0x060610BC;

  uVar5 = 0;

  do {

    uVar7 = uVar5 & 0xffff;

    uVar4 = uVar5 & 0xff;

    uVar5 = uVar5 + 1;

    puVar8 = (int *)(puVar2 + (uVar7 << 3));

    *puVar8 = 0;

    *(short *)(puVar8 + 1) = 0;

    *(short *)((int)puVar8 + 6) = PTR_DAT_06025210;

    **(short **)(puVar1 + (uVar4 * 0xc & 0xff) + 4) = 0;

  } while ((uVar5 & 0xffff) < 8);

  for (uVar5 = 0; (uVar5 & 0xffff) < 0xe; uVar5 = uVar5 + 1) {

    uVar6 = 0;

    puVar8 = (int *)(0x06060D7C + (uVar5 & 0xffff) << 3 + 4);

    uVar4 = (uVar5 & 0xff) * 0xc & 0xff;

    do {

      if ((*(unsigned short *)(puVar3 + (unsigned int)(uVar6 << 1)) & *(unsigned short *)*puVar8) != 0) {

        puVar9 = (int *)(puVar2 + (unsigned int)(uVar6 << 3));

        *puVar9 = *(int *)(puVar1 + uVar4 + 4);

        puVar10 = (unsigned short *)(puVar3 + (unsigned int)(uVar6 << 1));

        *(unsigned short *)(puVar9 + 1) = *puVar10;

        *(short *)((int)puVar9 + 6) = *(short *)(puVar1 + uVar4 + 8);

        *(unsigned short *)*puVar9 = *(unsigned short *)*puVar9 | *puVar10;

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < 8);

  }

  return;

}

void FUN_06025224(param_1)
    int param_1;
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  unsigned short uVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  int *puVar10;

  unsigned int uVar11;

  puVar3 = (char *)0x06028400;

  puVar2 = (char *)0x06063750;

  sVar1 = DAT_0602528a;

  iVar6 = 0xa9;

  iVar9 = 0xc08;

  iVar7 = 0x590;

  if (*(int *)0x06061198 == '\x04') {

    (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590B8);

    (*(int(*)())puVar3)(8,*(int *)(puVar2 + iVar7),(int)DAT_06025292,

                      *(int *)((int)(puVar2 + iVar7) + 4));

  }

  else {

    if (*(int *)0x06061198 == '\x05') {

      (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590E0);

    }

    else {

      (*(int(*)())0x060284AE)(8,iVar9,0x90,0x06059104);

    }

    puVar10 = (int *)(puVar2 + iVar7);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_0602537a,puVar10[1]);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_0602537c,puVar10[1]);

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_0602537e,0x90,0x06058F94 + (param_1 << 3));

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_06025380),0x10,

                    *(int *)((int)(puVar2 + DAT_06025380) + 4) + (int)DAT_06025382);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_06025384),0x2a0,

                    *(int *)((int)(puVar2 + DAT_06025384) + 4) + (int)DAT_06025386);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_0602538a),(int)PTR_DAT_0602538c,

                    *(int *)((int)(puVar2 + DAT_0602538a) + 4) + (int)DAT_06025386);

  uVar11 = 0;

  piVar8 = (int *)(0x06061170 + (param_1 << 2));

  do {

    (*(int(*)())0x0601A3F4)(uVar11 & 0xffff,sVar1);

    if ((((unsigned int)*(unsigned short *)((uVar11 << 3) + *piVar8 + 6) != iVar6 + 0xbU) ||

        (*(int *)0x06061198 == '\x04')) || (*(int *)0x06061198 == '\x05')) {

      iVar7 = (uVar11 << 3);

      if ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) == iVar6 + 0xbU) {

        uVar4 = 9;

      }

      else {

        uVar4 = 8;

      }

      piVar5 = (int *)(0x06058FBC + iVar7);

      (*(int(*)())puVar3)(piVar5[1] << 2,*(int *)(puVar2 + (*piVar5 << 3)),

                        ((unsigned int)(unsigned char)((char *)(0x0605904C + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x0605904C)[(uVar11 << 1)]) << 1,

                        0x00008000 + *(int *)((int)(puVar2 + (*piVar5 << 3)) + 4));

      (*(int(*)())puVar3)(piVar5[1] << 2,

                        *(int *)(puVar2 + ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3)),

                        ((unsigned int)(unsigned char)((char *)(0x06059060 + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059060)[(uVar11 << 1)]) << 1,

                        (unsigned int)(uVar4 << 12) +

                        *(int *)((int)(puVar2 + ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3)) + 4));

    }

    uVar11 = uVar11 + 1;

  } while ((int)uVar11 < 10);

  return;

}

void FUN_06025478(param_1)
    int param_1;
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  unsigned short uVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  int *puVar10;

  unsigned int uVar11;

  puVar3 = (char *)0x06028400;

  puVar2 = (char *)0x06063750;

  sVar1 = DAT_060254de;

  iVar6 = 0xa8;

  iVar9 = 0xc08;

  iVar7 = 0x590;

  if (*(int *)0x06061198 == '\x04') {

    (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590B8);

    (*(int(*)())puVar3)(8,*(int *)(puVar2 + iVar7),(int)DAT_060254e6,

                      *(int *)((int)(puVar2 + iVar7) + 4));

  }

  else {

    if (*(int *)0x06061198 == '\x05') {

      (*(int(*)())0x060284AE)(8,iVar9,0x90,0x060590E0);

    }

    else {

      (*(int(*)())0x060284AE)(8,iVar9,0x90,0x06059104);

    }

    puVar10 = (int *)(puVar2 + iVar7);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_060255ce,puVar10[1]);

    (*(int(*)())puVar3)(8,*puVar10,(int)DAT_060255d0,puVar10[1]);

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_060255d2,0x90,0x06058F94 + (param_1 << 3));

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_060255d4),0x10,

                    *(int *)((int)(puVar2 + DAT_060255d4) + 4) + (int)DAT_060255d6);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_060255d8),0x2a0,

                    *(int *)((int)(puVar2 + DAT_060255d8) + 4) + (int)DAT_060255da);

  (*(int(*)())puVar3)(8,*(int *)(puVar2 + DAT_060255de),(int)PTR_DAT_060255e0,

                    *(int *)((int)(puVar2 + DAT_060255de) + 4) + (int)DAT_060255da);

  uVar11 = 0;

  piVar8 = (int *)(0x06061184 + (param_1 << 2));

  do {

    (*(int(*)())0x0601A3F4)(uVar11 & 0xffff,sVar1);

    if ((((unsigned int)*(unsigned short *)((uVar11 << 3) + *piVar8 + 6) != iVar6 + 0xcU) ||

        (*(int *)0x06061198 == '\x04')) || (*(int *)0x06061198 == '\x05')) {

      iVar7 = (uVar11 << 3);

      if ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) == iVar6 + 0xcU) {

        uVar4 = 9;

      }

      else {

        uVar4 = 8;

      }

      piVar5 = (int *)(0x0605900C + iVar7);

      (*(int(*)())puVar3)(piVar5[1] << 2,*(int *)(puVar2 + (*piVar5 << 3)),

                        ((unsigned int)(unsigned char)((char *)(0x06059074 + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059074)[(uVar11 << 1)]) << 1,

                        0x00008000 + *(int *)((int)(puVar2 + (*piVar5 << 3)) + 4));

      (*(int(*)())puVar3)(piVar5[1] << 2,

                        *(int *)(puVar2 + ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3)),

                        ((unsigned int)(unsigned char)((char *)(0x06059084 + (uVar11 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059084)[(uVar11 << 1)]) << 1,

                        (unsigned int)(uVar4 << 12) +

                        *(int *)((int)(puVar2 + ((unsigned int)*(unsigned short *)(*piVar8 + iVar7 + 6) << 3)) + 4));

    }

    uVar11 = uVar11 + 1;

  } while ((int)uVar11 < 8);

  return;

}

void FUN_060256cc()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  unsigned short uVar7;

  unsigned int uVar8;

  unsigned short uVar9;

  int iVar10;

  int *piVar11;

  puVar5 = (char *)0x06089ED0;

  puVar4 = (char *)0x06089ECC;

  puVar3 = (char *)0x06060F2C;

  puVar2 = (char *)0x06063750;

  uVar1 = DAT_06025746;

  if (*(int *)0x06061199 == '\0') {

    iVar6 = (*(int(*)())0x06035C2C)();

    if (iVar6 < 6) {

      uVar8 = 0;

      do {

        (*(int(*)())0x0601A3F4)(uVar8,uVar1);

        uVar8 = uVar8 + 1;

      } while ((uVar8 & 0xffff) < 10);

    }

    else {

      uVar8 = 0;

      do {

        (*(int(*)())0x0601A3F4)(uVar8,uVar1);

        iVar6 = (uVar8 & 0xffff) << 3;

        if ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) == (int)PTR_DAT_06025748) {

          uVar7 = 9;

        }

        else {

          uVar7 = 8;

        }

        piVar11 = (int *)(0x06058FBC + iVar6);

        iVar10 = (uVar8 & 0xffff) << 1;

        (*(int(*)())0x06028400)(piVar11[1] << 2,*(int *)(puVar2 + (*piVar11 << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x0605904C + iVar10))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x0605904C)[iVar10]) << 1,

                   0x00008000 + *(int *)((int)(puVar2 + (*piVar11 << 3)) + 4));

        (*(int(*)())0x06028400)(piVar11[1] << 2,

                   *(int *)(puVar2 + ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x06059060 + iVar10))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x06059060)[iVar10]) << 1,

                   (unsigned int)(uVar7 << 12) +

                   *(int *)((int)(puVar2 + ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) << 3)) + 4));

        uVar8 = uVar8 + 1;

      } while ((uVar8 & 0xffff) < 10);

    }

    if ((*(unsigned short *)0x06063D9A != 0) &&

       (((unsigned int)0x0000C000 & (unsigned int)*(unsigned short *)0x06063D9A) == 0)) {

      *(int *)0x06061199 = 1;

    }

  }

  if (*(int *)0x06061199 != '\0') {

    uVar7 = *(unsigned short *)0x06063D9A;

    if (uVar7 != 0) {

      if (((unsigned int)uVar7 & (unsigned int)0x0000C000) == 0) {

        if ((uVar7 & DAT_06025a80) != 0) {

          *(int *)0x06061198 = 5;

          *(short *)0x06089EDA = 0x12;

          *(int *)0x06061199 = 0;

          FUN_06025224(4);

          return;

        }

        uVar9 = 0;

        do {

          if ((*(unsigned short *)(0x06059094 + (unsigned int)(uVar9 << 1)) & uVar7) != 0) break;

          uVar9 = uVar9 + 1;

        } while (uVar9 < 10);

        *(unsigned int *)puVar4 = (unsigned int)uVar9;

        FUN_060262c0((unsigned int)uVar9);

        uVar8 = 0;

        do {

          if (*(short *)(0x060610BC + ((uVar8 & 0xff) * 0xc & 0xff) + 8) ==

              *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 6)) break;

          uVar8 = uVar8 + 1;

        } while ((uVar8 & 0xffff) < 0xe);

        *(unsigned int *)puVar5 = uVar8 & 0xffff;

      }

      else if (((unsigned int)uVar7 & (unsigned int)0x00008000) == 0) {

        if ((uVar7 & DAT_0602596a) != 0) {

          iVar6 = *(int *)puVar5;

          *(int *)puVar5 = iVar6 + -1;

          if (iVar6 + -1 < 0) {

            *(int *)puVar5 = (char *)0xe;

          }

          if ((*(short *)0x06089ED4 == 1) && (*(int *)0x06089ED0 == 0xd)) {

            *(int *)puVar5 = 9;

          }

          if ((*(short *)0x06089ED4 == 2) && (*(int *)0x06089ED0 == 9)) {

            *(int *)puVar5 = 7;

          }

          if ((*(short *)0x06089ED6 == 1) && (*(int *)0x06089ED0 == 7)) {

            *(int *)puVar5 = 3;

          }

          if ((*(short *)0x06089ED6 == 2) && (*(int *)0x06089ED0 == 3)) {

            *(int *)puVar5 = 1;

          }

        }

      }

      else {

        iVar6 = *(int *)puVar5;

        *(int *)puVar5 = iVar6 + 1;

        if (0xe < iVar6 + 1) {

          *(int *)puVar5 = 0;

        }

        if ((*(short *)0x06089ED6 == 1) && (*(int *)0x06089ED0 == 4)) {

          *(int *)puVar5 = 8;

        }

        if ((*(short *)0x06089ED6 == 2) && (*(int *)0x06089ED0 == 2)) {

          *(int *)puVar5 = 4;

        }

        if ((*(short *)0x06089ED4 == 1) && (*(int *)0x06089ED0 == 10)) {

          *(int *)puVar5 = (char *)0xe;

        }

        if ((*(short *)0x06089ED4 == 2) && (*(int *)0x06089ED0 == 8)) {

          *(int *)puVar5 = 10;

        }

      }

      *(int *)(puVar3 + *(int *)((int)(int)puVar4 << 3)) =

           *(int *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 4);

      *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 4) =

           *(short *)(0x06059094 + *(int *)((int)(int)puVar4 << 1));

      *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 6) =

           *(short *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8);

      FUN_06025224(4);

    }

    if (-1 < *(int *)puVar4) {

      iVar6 = (*(int(*)())0x06035C2C)();

      if (5 < iVar6) {

        if ((unsigned int)*(unsigned short *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) ==

            (int)PTR_DAT_06025bb8) {

          uVar7 = 9;

        }

        else {

          uVar7 = 8;

        }

        (*(int(*)())0x06028400)(*(int *)((int)(0x06058FBC + *(int *)((int)(int)puVar4 << 3)) + 4) << 2,

                   *(int *)(puVar2 + (*(int *)(0x06058FBC + *(int *)((int)(int)puVar4 << 3)) << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x0605904C + *(int *)((int)(int)puVar4 << 1)))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x0605904C)[*(int *)((int)(int)puVar4 << 1)]) << 1,

                   0x00008000 +

                   *(int *)((int)(puVar2 + (*(int *)(0x06058FBC + *(int *)((int)(int)puVar4 << 3)) << 3)) + 4)

                  );

        (*(int(*)())0x06028400)(*(int *)(0x06058FBC + *(int *)((int)(int)puVar4 << 3) + 4) << 2,

                   *(int *)

                    (puVar2 + ((unsigned int)*(unsigned short *)

                                     (0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8

                                     ) << 3)),

                   ((unsigned int)(unsigned char)((char *)(0x06059060 + *(int *)((int)(int)puVar4 << 1)))[1] * 0x40 +

                   (unsigned int)(unsigned char)((int *)0x06059060)[*(int *)((int)(int)puVar4 << 1)]) << 1,

                   (unsigned int)(uVar7 << 12) +

                   *(int *)((int)(puVar2 + ((unsigned int)*(unsigned short *)

                                                  (0x060610BC +

                                                  ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) << 3))

                           + 4));

        return;

      }

      (*(int(*)())0x0601A3F4)(*(unsigned int *)puVar4 & 0xffff,uVar1);

      return;

    }

  }

  return;

}

void FUN_06025bf4()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  unsigned short uVar7;

  unsigned int uVar8;

  unsigned short uVar9;

  int iVar10;

  int *piVar11;

  puVar5 = (char *)0x06089ED0;

  puVar4 = (char *)0x06089ECC;

  puVar3 = (char *)0x0606107C;

  puVar2 = (char *)0x06028400;

  uVar1 = DAT_06025c6e;

  if (*(int *)0x06061199 == '\0') {

    iVar6 = (*(int(*)())0x06035C2C)();

    if (iVar6 < 6) {

      uVar8 = 0;

      do {

        (*(int(*)())0x0601A3F4)(uVar8,uVar1);

        uVar8 = uVar8 + 1;

      } while ((uVar8 & 0xffff) < 8);

    }

    else {

      uVar8 = 0;

      do {

        (*(int(*)())0x0601A3F4)(uVar8,uVar1);

        iVar6 = (uVar8 & 0xffff) << 3;

        if ((unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) == (int)PTR_DAT_06025c70) {

          uVar7 = 9;

        }

        else {

          uVar7 = 8;

        }

        piVar11 = (int *)(0x0605900C + iVar6);

        iVar10 = (uVar8 & 0xffff) << 1;

        (*(int(*)())puVar2)(piVar11[1] << 2,*(int *)(0x06063750 + (*piVar11 << 3)),

                          ((unsigned int)(unsigned char)((char *)(0x06059074 + iVar10))[1] * 0x40 +

                          (unsigned int)(unsigned char)((int *)0x06059074)[iVar10]) << 1,

                          0x00008000 + *(int *)((int)(0x06063750 + (*piVar11 << 3)) + 4));

        (*(int(*)())puVar2)(piVar11[1] << 2,

                          *(int *)

                           (0x06063750 + (unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) << 3),

                          ((unsigned int)(unsigned char)((char *)(0x06059084 + iVar10))[1] * 0x40 +

                          (unsigned int)(unsigned char)((int *)0x06059084)[iVar10]) << 1,

                          (unsigned int)(uVar7 << 12) +

                          *(int *)((int)(0x06063750 +

                                        (unsigned int)*(unsigned short *)(puVar3 + iVar6 + 6) << 3) + 4));

        uVar8 = uVar8 + 1;

      } while ((uVar8 & 0xffff) < 8);

    }

    if ((*(unsigned short *)0x06063D9A != 0) &&

       (((unsigned int)0x0000C088 & (unsigned int)*(unsigned short *)0x06063D9A) == 0)) {

      *(int *)0x06061199 = 1;

    }

  }

  if (*(int *)0x06061199 != '\0') {

    uVar7 = *(unsigned short *)0x06063D9A;

    if (uVar7 != 0) {

      if (((unsigned int)uVar7 & (unsigned int)0x0000C088) == 0) {

        if ((uVar7 & DAT_06025fac) != 0) {

          *(int *)0x06061198 = 5;

          *(short *)0x06089EDA = 0x12;

          *(int *)0x06061199 = 0;

          FUN_06025478(4);

          return;

        }

        uVar9 = 0;

        do {

          if ((*(unsigned short *)(0x060590A8 + (unsigned int)(uVar9 << 1)) & uVar7) != 0) break;

          uVar9 = uVar9 + 1;

        } while (uVar9 < 8);

        *(unsigned int *)puVar4 = (unsigned int)uVar9;

        FUN_060263ec((unsigned int)uVar9);

        uVar8 = 0;

        do {

          if (*(short *)(0x060610BC + ((uVar8 & 0xff) * 0xc & 0xff) + 8) ==

              *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 6)) break;

          uVar8 = uVar8 + 1;

        } while ((uVar8 & 0xffff) < 0xe);

        *(unsigned int *)puVar5 = uVar8 & 0xffff;

      }

      else if (((unsigned int)uVar7 & (unsigned int)0x00008080) == 0) {

        if ((uVar7 & DAT_06025e94) != 0) {

          iVar6 = *(int *)puVar5;

          *(int *)puVar5 = iVar6 + -1;

          if (iVar6 + -1 < 0) {

            *(int *)puVar5 = (char *)0xe;

          }

          if ((*(short *)0x06089ED4 == 1) && (*(int *)0x06089ED0 == 0xd)) {

            *(int *)puVar5 = 9;

          }

          if ((*(short *)0x06089ED4 == 2) && (*(int *)0x06089ED0 == 9)) {

            *(int *)puVar5 = 7;

          }

          if ((*(short *)0x06089ED6 == 1) && (*(int *)0x06089ED0 == 7)) {

            *(int *)puVar5 = 3;

          }

          if ((*(short *)0x06089ED6 == 2) && (*(int *)0x06089ED0 == 3)) {

            *(int *)puVar5 = 1;

          }

        }

      }

      else {

        iVar6 = *(int *)puVar5;

        *(int *)puVar5 = iVar6 + 1;

        if (0xe < iVar6 + 1) {

          *(int *)puVar5 = 0;

        }

        if ((*(short *)0x06089ED6 == 1) && (*(int *)0x06089ED0 == 4)) {

          *(int *)puVar5 = 8;

        }

        if ((*(short *)0x06089ED6 == 2) && (*(int *)0x06089ED0 == 2)) {

          *(int *)puVar5 = 4;

        }

        if ((*(short *)0x06089ED4 == 1) && (*(int *)0x06089ED0 == 10)) {

          *(int *)puVar5 = (char *)0xe;

        }

        if ((*(short *)0x06089ED4 == 2) && (*(int *)0x06089ED0 == 8)) {

          *(int *)puVar5 = 10;

        }

      }

      *(int *)(puVar3 + *(int *)((int)(int)puVar4 << 3)) =

           *(int *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 4);

      *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 4) =

           *(short *)(0x060590A8 + *(int *)((int)(int)puVar4 << 1));

      *(short *)(puVar3 + *(int *)((int)(int)puVar4 << 3) + 6) =

           *(short *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8);

      FUN_06025478(4);

    }

    if (-1 < *(int *)puVar4) {

      iVar6 = (*(int(*)())0x06035C2C)();

      if (iVar6 < 6) {

        (*(int(*)())0x0601A3F4)(*(unsigned int *)puVar4 & 0xffff,uVar1);

        return;

      }

      if ((unsigned int)*(unsigned short *)(0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) ==

          (int)DAT_06026016) {

        uVar7 = 9;

      }

      else {

        uVar7 = 8;

      }

      (*(int(*)())puVar2)(*(int *)((int)(0x0605900C + *(int *)((int)(int)puVar4 << 3)) + 4) << 2,

                        *(int *)

                         (0x06063750 + *(int *)(0x0605900C + *(int *)((int)(int)puVar4 << 3)) << 3),

                        ((unsigned int)(unsigned char)((char *)(0x06059074 + *(int *)((int)(int)puVar4 << 1)))[1] * 0x40 +

                        (unsigned int)(unsigned char)((int *)0x06059074)[*(int *)((int)(int)puVar4 << 1)]) << 1,

                        0x00008000 +

                        *(int *)((int)(0x06063750 +

                                      *(int *)(0x0605900C + *(int *)((int)(int)puVar4 << 3)) << 3) + 4));

      (*(int(*)())puVar2)(*(int *)(0x0605900C + *(int *)((int)(int)puVar4 << 3) + 4) << 2,

                        *(int *)

                         (0x06063750 +

                         (unsigned int)*(unsigned short *)

                                (0x060610BC + ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) << 3

                         ),((unsigned int)(unsigned char)((char *)(0x06059084 + *(int *)((int)(int)puVar4 << 1)))[1] * 0x40 +

                           (unsigned int)(unsigned char)((int *)0x06059084)[*(int *)((int)(int)puVar4 << 1)]) << 1,

                        (unsigned int)(uVar7 << 12) +

                        *(int *)((int)(0x06063750 +

                                      (unsigned int)*(unsigned short *)

                                             (0x060610BC +

                                             ((*(unsigned int *)puVar5 & 0xff) * 0xc & 0xff) + 8) << 3) + 4))

      ;

    }

  }

  return;

}
