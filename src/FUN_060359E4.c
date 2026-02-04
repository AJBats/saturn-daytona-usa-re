extern int FUN_060359d2();
extern int FUN_060359da();

int FUN_060359e4()
{

  unsigned int uVar1;

  unsigned int uVar5;

  long long lVar2;

  long long lVar3;

  long long lVar4;

  int in_r0;

  int uVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  unsigned int uVar10;

  int iVar11;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int *in_stack_00000000;

  unsigned int in_stack_00000004;

  unsigned int in_stack_00000008;

  unsigned int in_stack_0000000c;

  unsigned int in_stack_00000010;

  uVar13 = in_stack_00000004 ^ in_stack_0000000c;

  uVar10 = in_stack_00000004 >> 0x14 & 0x000007FF;

  uVar12 = in_stack_0000000c >> 0x14 & 0x000007FF;

  in_stack_00000004 = in_stack_00000004 & 0x000FFFFF;

  in_stack_0000000c = in_stack_0000000c & 0x000FFFFF;

  if (uVar10 == 0x000007FF) {

    if ((in_stack_00000004 == 0) && (in_stack_00000008 == 0)) {

      if (uVar12 != 0x000007FF) {

        if (((uVar12 == 0) && (in_stack_0000000c == 0)) && (in_stack_00000010 == 0)) {

          uVar6 = FUN_060359da();

          return uVar6;

        }

        goto code_r0x060359d2;

      }

      if ((in_stack_0000000c == 0) && (in_stack_00000010 == 0)) {

        uVar6 = FUN_060359d2();

        return uVar6;

      }

    }

code_r0x060359da:

    uVar13 = 0;

    uVar8 = 0;

    uVar12 = 8;

    uVar10 = 0x000007FF;

  }

  else {

    if (uVar12 != 0x000007FF) {

      if (uVar10 == 0) {

        if ((in_stack_00000004 != 0) || (in_stack_00000008 != 0)) {

          for (in_stack_00000004 =

                    in_stack_00000004 << 1 | (unsigned int)((in_stack_00000008 & 0x80000000) != 0);

              in_stack_00000008 = in_stack_00000008 << 1,

              (int)in_stack_00000004 < (int)0x00100000;

              in_stack_00000004 =

                   in_stack_00000004 << 1 | (unsigned int)((in_stack_00000008 & 0x80000000) != 0)) {

            uVar10 = uVar10 - 1;

          }

          goto LAB_06035a3a;

        }

      }

      else {

LAB_06035a3a:

        if (uVar12 == 0) {

          if ((in_stack_0000000c == 0) && (in_stack_00000010 == 0)) goto LAB_060359c8;

          for (in_stack_0000000c =

                    in_stack_0000000c << 1 | (unsigned int)((in_stack_00000010 & 0x80000000) != 0);

              in_stack_00000010 = in_stack_00000010 << 1,

              (int)in_stack_0000000c < (int)0x00100000;

              in_stack_0000000c =

                   in_stack_0000000c << 1 | (unsigned int)((in_stack_00000010 & 0x80000000) != 0)) {

            uVar12 = uVar12 - 1;

          }

        }

        uVar10 = (uVar10 + uVar12) - 0x000003FF;

        if ((int)0x000007FF <= (int)uVar10) goto code_r0x060359d2;

        if (-0x36 < (int)uVar10) {

          uVar5 = (unsigned int)((unsigned long long)in_stack_00000010 * (unsigned long long)in_stack_00000008);

          lVar2 = (unsigned long long)(in_stack_0000000c | (unsigned int)0x00100000) *

                  (unsigned long long)(in_stack_00000004 | (unsigned int)0x00100000);

          uVar8 = (unsigned int)lVar2;

          lVar3 = (unsigned long long)in_stack_00000010 *

                  (unsigned long long)(in_stack_00000004 | (unsigned int)0x00100000);

          uVar9 = (unsigned int)lVar3;

          lVar4 = (unsigned long long)(in_stack_0000000c | (unsigned int)0x00100000) *

                  (unsigned long long)in_stack_00000008;

          uVar14 = (unsigned int)((unsigned long long)lVar4 >> 0x20);

          uVar1 = (unsigned int)lVar4;

          uVar7 = uVar9 + (int)((unsigned long long)in_stack_00000010 * (unsigned long long)in_stack_00000008 >> 0x20)

          ;

          uVar12 = uVar14 + (int)((unsigned long long)lVar3 >> 0x20);

          uVar9 = uVar12 + (uVar7 < uVar9);

          uVar7 = uVar1 + uVar7;

          uVar12 = uVar7 + (uVar12 < uVar14 || uVar9 < uVar12);

          uVar9 = uVar8 + uVar9;

          uVar7 = uVar9 + (uVar7 < uVar1 || uVar12 < uVar7);

          if (uVar5 != 0) {

            uVar12 = uVar12 | 1;

          }

          uVar1 = uVar12 >> 0x10;

          uVar14 = uVar7 >> 0x10;

          uVar9 = ((int)((unsigned long long)lVar2 >> 0x20) + (unsigned int)(uVar9 < uVar8 || uVar7 < uVar9)) *

                  0x10000 | uVar14;

          uVar8 = uVar9 >> 1;

          uVar7 = (uVar7 * 0x10000 | uVar1) >> 1 | (unsigned int)((uVar14 & 1) == 1) * -0x80000000;

          uVar12 = (uVar12 << 0x10 | uVar5 >> 0x10) >> 1 | (unsigned int)((uVar1 & 1) != 0) * -0x80000000;

          if ((uVar8 & (unsigned int)0x01000000) != 0) {

            uVar8 = uVar9 >> 2;

            uVar7 = uVar7 >> 1 | (unsigned int)((uVar14 & 2) == 2) * -0x80000000;

            uVar12 = uVar12 >> 1 | (unsigned int)((uVar1 & 2) != 0) * -0x80000000;

            uVar10 = uVar10 + 1;

            if (uVar10 == 0x000007FF) {

              uVar6 = FUN_060359d2();

              return uVar6;

            }

          }

          if (uVar12 != 0) {

            uVar7 = uVar7 | 1;

          }

          if ((int)uVar10 < 1) {

            iVar11 = 1 - uVar10;

            do {

              uVar10 = uVar8 & 1;

              uVar8 = uVar8 >> 1;

              iVar11 = iVar11 + -1;

              uVar7 = uVar7 >> 1 | (unsigned int)(uVar10 == 1) * -0x80000000 | (unsigned int)((uVar7 & 1) != 0);

              uVar10 = 0;

            } while (iVar11 != 0);

          }

          uVar12 = uVar7;

          if (((uVar7 & 4) != 0) && ((uVar7 & 0xb) != 0)) {

            uVar12 = uVar7 + 8;

            uVar8 = uVar8 + (uVar12 < uVar7);

            if ((int)0x01000000 <= (int)uVar8) {

              uVar7 = uVar8 & 1;

              uVar8 = uVar8 >> 1;

              uVar12 = uVar12 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000;

              uVar10 = uVar10 + 1;

            }

          }

          goto LAB_06035ad6;

        }

      }

LAB_060359c8:

      uVar12 = 0;

      uVar10 = (unsigned int)((uVar13 & 0x80000000) != 0) << 0x1f;

      goto LAB_06035af4;

    }

    if ((in_stack_0000000c != 0) || (in_stack_00000010 != 0)) goto code_r0x060359da;

    if (((uVar10 == 0) && (in_stack_00000004 == 0)) && (in_stack_00000008 == 0)) {

      uVar6 = FUN_060359da();

      return uVar6;

    }

code_r0x060359d2:

    uVar8 = 0;

    uVar12 = 0;

    uVar10 = 0x000007FF;

  }

LAB_06035ad6:

  uVar12 = ((uVar12 >> 1 | (unsigned int)((uVar8 & 1) == 1) * -0x80000000) >> 1 |

           (unsigned int)((uVar8 >> 1 & 1) == 1) * -0x80000000) >> 1 |

           (unsigned int)((uVar8 >> 2 & 1) == 1) * -0x80000000;

  uVar10 = uVar8 >> 3 & 0x000FFFFF | (uVar10 & 0x7ff) << 0x14 |

           (unsigned int)((uVar13 & 0x80000000) != 0) * -0x80000000;

LAB_06035af4:

  *in_stack_00000000 = uVar10;

  in_stack_00000000[1] = uVar12;

  return in_r0;

}
