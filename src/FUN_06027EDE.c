extern int DAT_06027f56;

extern int DAT_0602805c;

extern int PTR_DAT_06027fc0;

extern int PTR_DAT_06027fc0;

extern int PTR_DAT_06027ffc;

extern int PTR_DAT_06027ffc;

extern int PTR_DAT_0602802c;

extern int PTR_DAT_0602802c;

unsigned int FUN_06027ede(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    short *param_3;
{

  short sVar1;

  long long lVar2;

  long long lVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  short *psVar7;

  int iVar8;

  unsigned int uVar9;

  unsigned int *puVar10;

  int iVar11;

  unsigned int uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  puVar5 = 0x060BF000;

  puVar4 = 0x060C2000;

  iVar15 = *param_2;

  iVar14 = param_2[2];

  if (*(int *)0x0607EAD8 == 2) {

    iVar11 = 0;

    psVar7 = (short *)0x06061270;

    while( 1 ) {

      sVar1 = *psVar7;

      psVar7 = psVar7 + 1;

      if (sVar1 == 0) break;

      if (param_1 == sVar1) {

        if (*(int *)(*(int *)0x0607E940 + (int)DAT_06027f56) < 0x47) {

          iVar13 = (int)*(short *)((int)(0x06061240 + iVar11 * 2) + 2);

          *(short *)0x06063F50 = *(short *)(0x06061240 + iVar11 * 2);

          goto LAB_06027f66;

        }

        break;

      }

      iVar11 = iVar11 + 2;

    }

    iVar13 = 0;

LAB_06027f66:

    if (iVar13 == 0) {

      iVar13 = (int)*(short *)(puVar4 + (param_1 * 2 + 1) * 2);

      uVar12 = (unsigned int)(int)*(short *)(puVar4 + param_1 * 4) >> 1;

    }

    else {

      uVar12 = (unsigned int)(int)*(short *)0x06063F50 >> 1;

    }

  }

  else {

    iVar13 = (int)*(short *)(0x060C2000 + (param_1 * 2 + 1) * 2);

    uVar12 = (unsigned int)(int)*(short *)(0x060C2000 + param_1 * 4) >> 1;

  }

  iVar11 = 0;

  do {

    puVar10 = (unsigned int *)(0x060A6000 +

                      (unsigned int)*(unsigned short *)(puVar5 + uVar12 * 2) * (0x00000034 & 0xffff));

    uVar9 = *puVar10;

    iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[4] * (long long)iVar15) >> 0x20) << 0x10 |

            (unsigned int)((long long)(int)puVar10[4] * (long long)iVar15) >> 0x10) + puVar10[5];

    if ((uVar9 & (unsigned int)0x01000000) == 0) {

      iVar8 = iVar8 + iVar14;

    }

    uVar6 = (unsigned int)PTR_DAT_06027fc0;

    if ((uVar6 & uVar9) != 0) {

      iVar8 = -iVar8;

    }

    if (-1 < iVar8) {

      iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[6] * (long long)iVar15) >> 0x20) << 0x10 |

              (unsigned int)((long long)(int)puVar10[6] * (long long)iVar15) >> 0x10) + puVar10[7];

      if (((unsigned int)0x02000000 & uVar9) == 0) {

        iVar8 = iVar8 + iVar14;

      }

      uVar6 = (unsigned int)PTR_DAT_06027ffc;

      if ((uVar6 & uVar9) != 0) {

        iVar8 = -iVar8;

      }

      if (-1 < iVar8) {

        iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[8] * (long long)iVar15) >> 0x20) << 0x10 |

                (unsigned int)((long long)(int)puVar10[8] * (long long)iVar15) >> 0x10) + puVar10[9];

        if (((unsigned int)0x04000000 & uVar9) == 0) {

          iVar8 = iVar8 + iVar14;

        }

        uVar6 = (unsigned int)PTR_DAT_0602802c;

        if ((uVar6 & uVar9) != 0) {

          iVar8 = -iVar8;

        }

        if (-1 < iVar8) {

          iVar8 = ((int)((unsigned long long)((long long)(int)puVar10[10] * (long long)iVar15) >> 0x20) << 0x10

                  | (unsigned int)((long long)(int)puVar10[10] * (long long)iVar15) >> 0x10) + puVar10[0xb];

          if ((0x08000000 & uVar9) == 0) {

            iVar8 = iVar8 + iVar14;

          }

          uVar6 = (unsigned int)DAT_0602805c;

          if ((uVar6 & uVar9) != 0) {

            iVar8 = -iVar8;

          }

          if (-1 < iVar8) break;

        }

      }

    }

    iVar11 = iVar11 + 1;

    uVar12 = uVar12 + 1;

  } while (iVar11 < iVar13);

  if ((param_3 != (short *)0x0) && (iVar13 != iVar11)) {

    lVar2 = (long long)*(int *)((int)puVar10 + 0x00000004) * (long long)iVar15;

    lVar3 = (long long)*(int *)((int)puVar10 + 0x00000008) * (long long)iVar14;

    param_2[1] = ((int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10) +

                 ((int)((unsigned long long)lVar3 >> 0x20) << 0x10 | (unsigned int)lVar3 >> 0x10) +

                 *(int *)((int)puVar10 + 0x0000000C);

    uVar6 = uVar12 * 2;

    *param_3 = *(short *)(puVar5 + uVar6);

  }

  return uVar6;

}
