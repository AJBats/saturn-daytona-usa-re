extern int DAT_060222e6;

extern int DAT_060224b6;

extern int DAT_060224b8;

extern int DAT_060224ba;

extern int DAT_06022652;

extern int DAT_0602271e;

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

  puVar5 = 0x060895A0;

  puVar4 = 0x060897D0;

  puVar3 = 0x060896B8;

  puVar2 = 0x06027552;

  puVar1 = 0x03E80000;

  iVar7 = *(int *)0x0607E944;

  puStack_38 = 0x06089C58;

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

      if (*(int *)(0x0608962C + uVar14 * 4) == 0) {

        if (iVar13 < iVar9) {

          uVar10 = iVar9 + (iVar13 >> 2);

        }

        else {

          uVar10 = (iVar9 >> 2) + iVar13;

        }

        if (*(unsigned int *)(0x06050788 + *(int *)(puVar5 + uVar14 * 4) * 4) < uVar10) {

          piVar11 = (int *)(puVar4 + (short)(sVar15 * 0x18));

          iStack_30 = *piVar11;

          iStack_28 = piVar11[2];

          if (piVar11[1] == 0) {

            puStack_2c = puVar1;

            uVar6 = (*0x06006838)(iStack_30,iStack_28);

            (*0x06027EDE)(uVar6,&iStack_30,auStack_3c);

            if ((puStack_2c == puVar1) ||

               ((*(unsigned int *)(0x060A6000 + (unsigned int)auStack_3c[0] * 0x34) & 0x80) != 0)) {

              *(int *)(puVar4 + (short)(sVar15 * 0x18)) = 0x4E200000;

              goto LAB_060227ca;

            }

            puStack_2c = puStack_2c + DAT_060222e6;

            if (*(int *)(puVar5 + uVar14 * 4) == 3) {

              puStack_2c = puStack_2c + (int)0x00013333;

            }

            if (*(int *)(puVar5 + uVar14 * 4) == 4) {

              puStack_2c = puStack_2c + (int)0x0000CCCC;

            }

          }

          else {

            puStack_2c = *(char **)(puVar4 + (short)(sVar15 * 0x18) + 4);

          }

        }

        else {

          *(int *)(0x0608962C + uVar14 * 4) = 1;

          *(int *)(puVar4 + (short)(sVar15 * 0x18) + 4) = 0;

          uVar6 = (*puVar2)(*(int *)(iVar7 + 0xc),

                                    *(int *)

                                     (0x06089E08 + *(int *)(puVar5 + uVar14 * 4) * 4));

          if (*(int *)(iVar7 + 8) < 0x47) {

            if (*(int *)(iVar7 + 8) < 0x1f) {

              iStack_40 = (*puVar2)(uVar6,0x00013333);

              iVar9 = uVar14 * 4;

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

              iStack_40 = (*puVar2)(uVar6,0x00014CCC);

              iVar9 = uVar14 * 4;

              puVar8 = (int *)(0x06089744 + iVar9);

              uVar6 = (*puVar2)(*(int *)(iVar7 + 0xc),0x00030000);

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

            iStack_40 = (*puVar2)(uVar6,0x00014CCC);

            iVar9 = uVar14 * 4;

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

          iVar9 = (int)DAT_060224b8;

          uVar10 = *(unsigned int *)(iVar7 + 8);

          iVar13 = *(int *)(iVar7 + 0x28);

          iVar12 = (int)DAT_060224ba;

          if ((*(int *)(puVar5 + uVar14 * 4) == 3) || (*(int *)(puVar5 + uVar14 * 4) == 4)) {

            *(char **)(0x06089744 + uVar14 * 4) = 0x00018000;

          }

          *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14) = 0;

          *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16) = (short)*(int *)(iVar7 + 0x28);

          (*0x06027358)

                    (iVar13 + (uVar10 & 1) * iVar9 + iVar12,puVar4 + (short)(sVar15 * 0x18) + 0xc,

                     puVar4 + (short)(sVar15 * 0x18) + 0x10);

          uVar6 = (*puVar2)(iStack_40,*(int *)(puVar4 + (short)(sVar15 * 0x18) + 0xc)

                                   );

          *(int *)(puVar4 + (short)(sVar15 * 0x18) + 0xc) = uVar6;

          uVar6 = (*puVar2)(iStack_40,

                                    *(int *)(puVar4 + (short)(sVar15 * 0x18) + 0x10));

          *(int *)(puVar4 + (short)(sVar15 * 0x18) + 0x10) = uVar6;

          if (*(int *)(puVar5 + uVar14 * 4) == 0) {

            (*0x0601D5F4)(0,0xAE110BFF);

          }

          else {

            (*0x0601D5F4)(0,0xAE110DFF);

          }

LAB_060224e0:

          if (*(unsigned int *)(puVar3 + uVar14 * 4) < 0x28) {

            if ((*(int *)(puVar5 + uVar14 * 4) == 3) || (*(int *)(puVar5 + uVar14 * 4) == 4)) {

              local_48 = puStack_38;

            }

            else {

              local_48 = 0x06089B18;

            }

            piVar11 = (int *)(puVar4 + (short)(sVar15 * 0x18));

            *piVar11 = *piVar11 - piVar11[3];

            piVar11[2] = piVar11[2] + piVar11[4];

            iStack_30 = *piVar11;

            iStack_28 = piVar11[2];

            puStack_2c = puVar1;

            uVar6 = (*0x06006838)(iStack_30,iStack_28);

            (*0x06027EDE)(uVar6,&iStack_30,auStack_3c);

            if ((puStack_2c == puVar1) ||

               ((*(unsigned int *)(0x060A6000 + (unsigned int)auStack_3c[0] * 0x34) & 0x80) != 0)) {

              *(int *)(puVar4 + (short)(sVar15 * 0x18)) = 0x4E200000;

              *(int *)(puVar3 + uVar14 * 4) = 0;

              goto LAB_060226d6;

            }

            iVar9 = uVar14 * 4;

            iVar12 = (*puVar2)(*(int *)(0x06089744 + iVar9),

                                       *(int *)(local_48 + *(int *)(puVar3 + iVar9) * 8));

            puStack_2c = puStack_2c + DAT_06022652 + iVar12;

            if (*(int *)(puVar5 + iVar9) == 3) {

              puStack_2c = puStack_2c + (int)0x00013333;

            }

            if (*(int *)(puVar5 + uVar14 * 4) == 4) {

              puStack_2c = puStack_2c + (int)0x0000CCCC;

            }

            piVar11 = (int *)(puVar3 + uVar14 * 4);

            *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14) =

                 *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14) +

                 *(short *)(local_48 + *piVar11 * 8 + 4);

            *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16) =

                 *(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16) +

                 *(short *)(local_48 + *piVar11 * 8 + 6);

            *piVar11 = *piVar11 + 1;

          }

          else {

            iStack_30 = *(int *)(puVar4 + (short)(sVar15 * 0x18));

            iStack_28 = *(int *)((int)(puVar4 + (short)(sVar15 * 0x18)) + 8);

            puStack_2c = puVar1;

            uVar6 = (*0x06006838)(iStack_30,iStack_28);

            (*0x06027EDE)(uVar6,&iStack_30,auStack_3c);

            if ((puStack_2c == puVar1) ||

               ((*(unsigned int *)(0x060A6000 + (unsigned int)auStack_3c[0] * 0x34) & 0x80) != 0)) {

              *(int *)(puVar4 + (short)(sVar15 * 0x18)) = 0x4E200000;

              *(int *)(puVar3 + uVar14 * 4) = 0;

LAB_060226d6:

              *(int *)(0x0608962C + uVar14 * 4) = 0;

              goto LAB_060227ca;

            }

            puStack_2c = puStack_2c + DAT_0602271e;

            if (*(int *)(puVar5 + uVar14 * 4) == 3) {

              puStack_2c = puStack_2c + (int)0x00013333;

            }

            if (*(int *)(puVar5 + uVar14 * 4) == 4) {

              puStack_2c = puStack_2c + (int)0x0000CCCC;

            }

            *(int *)(puVar3 + uVar14 * 4) = 0;

            *(int *)(0x0608962C + uVar14 * 4) = 0;

          }

        }

      }

      else if (*(int *)(0x0608962C + uVar14 * 4) == 1) goto LAB_060224e0;

      (*0x06026DBC)();

      (*0x06026E2E)(iStack_30,puStack_2c,iStack_28);

      (*0x06026EDE)((int)*(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x16));

      (*0x06026E94)((int)*(short *)(puVar4 + (short)(sVar15 * 0x18) + 0x14));

      iVar9 = *(int *)(puVar5 + uVar14 * 4) * 4;

      (*0x06031D8C)

                (*(int *)(0x06089D98 + iVar9),*(int *)(0x06089DB4 + iVar9)

                );

      iVar9 = *(int *)(puVar5 + uVar14 * 4) * 4;

      (*0x06031A28)

                (*(int *)(0x06089DD0 + iVar9),(int)*psStack_34,

                 *(int *)(0x06089DEC + iVar9));

      (*0x06026DF8)();

    }

LAB_060227ca:

    uVar14 = uVar14 + 1;

  } while( true );

}
