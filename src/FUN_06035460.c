extern int DAT_06035734;

int FUN_06035460()
{

  long long lVar1;

  long long lVar2;

  int bVar3;

  int in_r0;

  int iVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  unsigned int uVar11;

  unsigned int uVar12;

  char *puVar13;

  char *puVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  unsigned int *in_stack_00000000;

  unsigned int in_stack_00000004;

  char *in_stack_00000008;

  unsigned int in_stack_0000000c;

  char *in_stack_00000010;

  unsigned int uVar7;

  uVar5 = in_stack_0000000c << 1 | (unsigned int)((in_stack_0000000c & 0x80000000) != 0);

  uVar11 = (in_stack_00000004 ^ 0x80000000) << 1 |

           (unsigned int)(((in_stack_00000004 ^ 0x80000000) & 0x80000000) != 0);

  uVar7 = uVar5;

  puVar9 = in_stack_00000010;

  if (uVar5 < uVar11) {

    uVar7 = uVar11;

    puVar9 = in_stack_00000008;

    uVar11 = uVar5;

    in_stack_00000008 = in_stack_00000010;

  }

  uVar5 = uVar7 << 0x1f;

  uVar6 = uVar7 >> 1 | uVar5;

  uVar7 = uVar11 << 0x1f;

  uVar12 = uVar11 >> 1 | uVar7;

  uVar11 = uVar6 >> 0x14 & 0x000007FF;

  uVar16 = uVar12 >> 0x14 & 0x000007FF;

  puVar8 = (char *)(uVar6 & 0x000FFFFF);

  puVar13 = (char *)(uVar12 & 0x000FFFFF);

  if (uVar11 == 0x000007FF) {

    if (((puVar8 != (char *)0x0) || (puVar9 != (char *)0x0)) ||

       ((uVar16 == 0x000007FF &&

        ((in_stack_00000008 != (char *)0x0 || ((uVar5 != 0) != (uVar7 != 0))))))) {

      uVar6 = 0;

      puVar8 = (char *)0x0;

      puVar9 = &UNK_00000008;

    }

    goto LAB_060356ca;

  }

  uVar15 = uVar11;

  if (uVar16 == 0) {

    if (uVar11 == 0) {

      if ((puVar8 == (char *)0x0) && (puVar9 == (char *)0x0)) {

        if (in_stack_00000008 == (char *)0x0) {

          uVar6 = uVar6 & uVar12;

          goto LAB_060356ca;

        }

        uVar11 = 0;

        puVar8 = puVar13;

        puVar9 = in_stack_00000008;

        uVar6 = uVar12;

      }

      else if ((puVar13 != (char *)0x0) || (in_stack_00000008 != (char *)0x0)) {

        for (puVar8 = (char *)((int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0));

            puVar9 = (char *)((int)puVar9 << 1), (int)puVar8 < (int)0x00100000;

            puVar8 = (char *)((int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0))) {

          uVar11 = uVar11 - 1;

        }

        goto LAB_060354ee;

      }

    }

    else if ((puVar13 != (char *)0x0) || (in_stack_00000008 != (char *)0x0)) {

LAB_060354ee:

      for (puVar13 = (char *)

                     ((int)puVar13 << 1 | (unsigned int)(((unsigned int)in_stack_00000008 & 0x80000000) != 0));

          in_stack_00000008 = (char *)((int)in_stack_00000008 << 1), uVar15 = uVar11,

          (int)puVar13 < (int)0x00100000;

          puVar13 = (char *)

                    ((int)puVar13 << 1 | (unsigned int)(((unsigned int)in_stack_00000008 & 0x80000000) != 0))) {

        uVar16 = uVar16 - 1;

      }

      goto LAB_0603556e;

    }

    uVar7 = (unsigned int)puVar9 & 0x80000000;

    uVar5 = (unsigned int)puVar9 & 0x40000000;

    uVar16 = (unsigned int)puVar9 & 0x20000000;

    puVar9 = (char *)((int)puVar9 << 3);

    puVar8 = (char *)

             ((((int)puVar8 << 1 | (unsigned int)(uVar7 != 0)) << 1 | (unsigned int)(uVar5 != 0)) << 1 |

             (unsigned int)(uVar16 != 0));

  }

  else {

LAB_0603556e:

    puVar10 = (char *)((int)puVar9 * 8);

    puVar14 = (char *)((int)in_stack_00000008 << 3);

    puVar9 = (char *)

             ((((int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0)) << 1 |

              (unsigned int)(((unsigned int)puVar9 & 0x40000000) != 0)) << 1 |

              (unsigned int)(((unsigned int)puVar9 & 0x20000000) != 0) | (unsigned int)0x00800000);

    puVar8 = (char *)

             ((((int)puVar13 << 1 | (unsigned int)(((unsigned int)in_stack_00000008 & 0x80000000) != 0)) << 1 |

              (unsigned int)(((unsigned int)in_stack_00000008 & 0x40000000) != 0)) << 1 |

              (unsigned int)(((unsigned int)in_stack_00000008 & 0x20000000) != 0) | (unsigned int)0x00800000);

    iVar4 = uVar15 - uVar16;

    if (iVar4 != 0) {

      if (iVar4 < 4) {

        do {

          uVar11 = (unsigned int)puVar8 & 1;

          puVar8 = (char *)((unsigned int)puVar8 >> 1);

          puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar11 == 1) * -0x80000000);

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

      }

      else if (iVar4 < 0x37) {

        if (0x20 < iVar4) {

          iVar4 = iVar4 + -0x20;

          bVar3 = puVar14 != (char *)0x0;

          puVar14 = puVar8;

          if (bVar3) {

            puVar14 = (char *)((unsigned int)puVar8 | 1);

          }

          puVar8 = (char *)0x0;

        }

        lVar1 = ZEXT48(puVar14) * (unsigned long long)*(unsigned int *)(&DAT_06035734 + iVar4 * 4);

        lVar2 = ZEXT48(puVar8) * (unsigned long long)*(unsigned int *)(&DAT_06035734 + iVar4 * 4);

        puVar8 = (char *)((unsigned long long)lVar2 >> 0x20);

        puVar14 = (char *)((unsigned int)((unsigned long long)lVar1 >> 0x20) | (unsigned int)lVar2);

        if ((int)lVar1 != 0) {

          puVar14 = (char *)((unsigned int)puVar14 | 1);

        }

      }

      else {

        puVar8 = (char *)0x0;

        puVar14 = &UNK_00000001;

      }

    }

    if ((uVar5 != 0) == (uVar7 != 0)) {

      puVar14 = puVar10 + (int)puVar14;

      puVar8 = puVar9 + (int)puVar8 + (puVar14 < puVar10);

      uVar11 = uVar15;

      if ((int)0x01000000 <= (int)puVar8) {

        uVar7 = (unsigned int)puVar8 & 1;

        puVar8 = (char *)((unsigned int)puVar8 >> 1);

        uVar11 = uVar15 + 1;

        puVar14 = (char *)

                  ((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000 |

                  (unsigned int)(((unsigned int)puVar14 & 1) != 0));

        if (uVar11 == 0x000007FF) {

          puVar8 = (char *)0x0;

          puVar9 = (char *)0x0;

          goto LAB_060356ca;

        }

      }

    }

    else {

      if ((puVar8 == puVar9) && (puVar14 == puVar10)) {

        uVar6 = 0;

        uVar11 = 0;

        puVar8 = (char *)0x0;

        puVar9 = (char *)0x0;

        goto LAB_060356ca;

      }

      puVar13 = puVar10 + -(int)puVar14;

      puVar14 = puVar9 + -(int)puVar8;

      puVar8 = puVar14 + -(unsigned int)(puVar10 < puVar13);

      if (puVar9 < puVar14 || puVar14 < puVar8) {

        puVar13 = (char *)-(int)puVar13;

        puVar8 = (char *)(-(unsigned int)(puVar13 != (char *)0x0) - (int)puVar8);

        uVar6 = uVar12;

      }

      puVar9 = puVar13;

      if (puVar8 == (char *)0x0) {

        puVar9 = (char *)0x0;

        uVar15 = uVar15 - 0x20;

        puVar8 = puVar13;

      }

      if (((unsigned int)puVar8 & 0xFFFF0000) == 0) {

        puVar8 = (char *)((int)puVar8 << 0x10 | (unsigned int)puVar9 >> 0x10);

        puVar9 = (char *)((int)puVar9 << 0x10);

        uVar15 = uVar15 - 0x10;

      }

      puVar13 = puVar8;

      if (puVar8 < 0x01000000) {

        for (; puVar14 = puVar9, uVar11 = uVar15, (int)puVar8 < (int)0x00800000;

            puVar8 = (char *)((int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar14 & 0x80000000) != 0))) {

          puVar14 = (char *)((int)puVar9 << 1);

          puVar8 = (char *)((int)puVar8 << 1 | (unsigned int)(((unsigned int)puVar9 & 0x80000000) != 0));

          uVar11 = uVar15 - 1;

          if ((int)0x00800000 <= (int)puVar8) break;

          uVar7 = (unsigned int)puVar14 & 0x80000000;

          puVar14 = (char *)((int)puVar9 << 2);

          puVar8 = (char *)((int)puVar8 << 1 | (unsigned int)(uVar7 != 0));

          uVar11 = uVar15 - 2;

          if ((int)0x00800000 <= (int)puVar8) break;

          uVar7 = (unsigned int)puVar14 & 0x80000000;

          puVar14 = (char *)((int)puVar9 << 3);

          puVar8 = (char *)((int)puVar8 << 1 | (unsigned int)(uVar7 != 0));

          uVar11 = uVar15 - 3;

          if ((int)0x00800000 <= (int)puVar8) break;

          puVar9 = (char *)((int)puVar9 << 4);

          uVar15 = uVar15 - 4;

        }

      }

      else {

        do {

          puVar8 = (char *)((unsigned int)puVar13 >> 1);

          puVar14 = (char *)

                    ((unsigned int)puVar9 >> 1 | (unsigned int)(((unsigned int)puVar13 & 1) == 1) * -0x80000000);

          uVar11 = uVar15 + 1;

          if (puVar8 < 0x01000000) break;

          uVar7 = (unsigned int)puVar8 & 1;

          puVar8 = (char *)((unsigned int)puVar13 >> 2);

          puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);

          uVar11 = uVar15 + 2;

          if (puVar8 < 0x01000000) break;

          uVar7 = (unsigned int)puVar8 & 1;

          puVar8 = (char *)((unsigned int)puVar13 >> 3);

          puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);

          uVar11 = uVar15 + 3;

          if (puVar8 < 0x01000000) break;

          uVar7 = (unsigned int)puVar8 & 1;

          puVar8 = (char *)((unsigned int)puVar13 >> 4);

          puVar9 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);

          uVar15 = uVar15 + 4;

          puVar13 = puVar8;

          puVar14 = puVar9;

          uVar11 = uVar15;

        } while (0x01000000 <= puVar8);

      }

    }

    if ((int)uVar11 < 1) {

      iVar4 = 1 - uVar11;

      do {

        uVar7 = (unsigned int)puVar8 & 1;

        puVar8 = (char *)((unsigned int)puVar8 >> 1);

        puVar14 = (char *)((unsigned int)puVar14 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);

        iVar4 = iVar4 + -1;

        uVar11 = 0;

      } while (iVar4 != 0);

    }

    puVar9 = puVar14;

    if ((((unsigned int)puVar14 & 4) != 0) && (((unsigned int)puVar14 & 0xb) != 0)) {

      puVar9 = puVar14 + 8;

      puVar8 = puVar8 + (puVar9 < puVar14);

      if ((int)0x01000000 <= (int)puVar8) {

        uVar7 = (unsigned int)puVar8 & 1;

        puVar8 = (char *)((unsigned int)puVar8 >> 1);

        puVar9 = (char *)((unsigned int)puVar9 >> 1 | (unsigned int)(uVar7 == 1) * -0x80000000);

        uVar11 = uVar11 + 1;

      }

    }

  }

LAB_060356ca:

  *in_stack_00000000 =

       (unsigned int)puVar8 >> 3 & 0x000FFFFF | (uVar11 & 0x7ff) << 0x14 |

       (unsigned int)((uVar6 & 0x80000000) != 0) * -0x80000000;

  in_stack_00000000[1] =

       (((unsigned int)puVar9 >> 1 | (unsigned int)(((unsigned int)puVar8 & 1) == 1) * -0x80000000) >> 1 |

       (unsigned int)(((unsigned int)puVar8 >> 1 & 1) == 1) * -0x80000000) >> 1 |

       (unsigned int)(((unsigned int)puVar8 >> 2 & 1) == 1) * -0x80000000;

  return in_r0;

}
