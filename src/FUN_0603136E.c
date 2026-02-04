extern int DAT_0603143a;

extern int DAT_06031496;

extern int DAT_06031516;

extern int DAT_0603156a;

extern int DAT_060315b0;

extern int DAT_060315be;

extern int DAT_060315ce;

extern int DAT_0603162a;

extern int DAT_0603162c;

extern int DAT_0603162e;

extern int PTR_DAT_0603156c;

extern int PTR_DAT_0603156c;

extern int FUN_06031340();

int FUN_0603136e(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char cVar1;

  int bVar2;

  long long lVar3;

  int in_r0;

  short sVar5;

  int iVar4;

  unsigned int uVar6;

  int extraout_r1;

  int iVar7;

  int extraout_r2;

  int extraout_r3;

  int extraout_r3_00;

  unsigned int uVar8;

  char *pcVar9;

  int iVar10;

  int unaff_r8;

  unsigned int uVar11;

  int unaff_r9;

  int iVar12;

  char *puVar13;

  char *unaff_r12;

  unsigned int *unaff_r13;

  unsigned int *unaff_r14;

  int in_pr;

  long long uVar14;

  int iVar15;

  char *puVar16;

  sVar5 = (*(void(*)())0x0602744C)(unaff_r8 - param_3,unaff_r9 - param_4);

  iVar12 = (int)-sVar5;

  sVar5 = (*(void(*)())0x0602744C)(unaff_r14[0xe] - unaff_r13[0xe],unaff_r14[0xf] - unaff_r13[0xf],unaff_r13[0xe],

                     unaff_r13[0xf],in_pr,in_r0);

  uVar8 = (unsigned int)DAT_0603143a;

  uVar6 = (int)(short)unaff_r13[0xc] - ((unsigned int)(unsigned short)-sVar5 | uVar8 << 1);

  if ((int)uVar6 < 1) {

    uVar6 = -uVar6;

  }

  uVar6 = (unsigned int)((uVar6 & 0xffff) < uVar8);

  FUN_06031340();

  iVar7 = extraout_r1;

  if (extraout_r1 >= (int)uVar8) {

    iVar7 = extraout_r1 - uVar8;

  }

  uVar11 = (unsigned int)(extraout_r1 < (int)uVar8);

  bVar2 = uVar11 != uVar6;

  uVar14 = (*(void(*)())0x06027348)(iVar7);

  iVar7 = (int)uVar14;

  uVar6 = extraout_r2 - iVar12 & 0xffff;

  if ((int)uVar8 <= (int)uVar6) {

    uVar6 = uVar6 - uVar8;

  }

  uVar8 = (unsigned int)((unsigned long long)uVar14 >> 0x29);

  iVar10 = 0;

  if ((10 < uVar8) && (uVar8 < 0x37)) {

    iVar10 = 1;

  }

  if (((bVar2) && (uVar11 = (unsigned int)(uVar11 == 0), iVar10 != 0)) ||

     (unaff_r12 = (char *)

                  ((*(int *)(0x0605BCC8 + uVar8 * 4) - (int)unaff_r12) +

                  *(int *)(0x0605BCC8 + (uVar6 >> 9) * 4)), 0 < (int)unaff_r12)) {

    uVar6 = unaff_r14[10] - unaff_r13[10] & 0xffff;

    if (((int)DAT_06031496 < (int)uVar6) && ((int)uVar6 < DAT_06031496 * 3)) {

      iVar15 = 1;

      if ((int)0x00042AAA < (int)(unaff_r14[3] + unaff_r13[3])) {

        *unaff_r13 = *unaff_r13 | 0x08000000;

      }

    }

    else {

      iVar15 = 0;

      if ((int)0x00042AAA < (int)(unaff_r13[3] - unaff_r14[3])) {

        *unaff_r13 = *unaff_r13 | 0x08000000;

      }

      else if ((iVar10 == 0) &&

              ((int)((unsigned int)0x00042AAA >> 1) <= (int)(unaff_r13[3] - unaff_r14[3]))) {

        puVar13 = 0x20000000;

        if (uVar11 != 0) {

          puVar13 = (char *)((unsigned int)0x20000000 >> 1);

        }

        *unaff_r13 = *unaff_r13 | (unsigned int)puVar13;

      }

      else {

        uVar6 = unaff_r13[10] - iVar12 & 0xffff;

        if (((int)uVar6 <= (int)DAT_06031516) || (DAT_06031516 * 3 <= (int)uVar6)) {

          if (iVar10 != 0) {

            unaff_r14[0xc] = unaff_r13[8];

            *(int *)((int)DAT_0603156a + (int)unaff_r13) = 8;

          }

          iVar4 = (*(void(*)())0x06027344)(uVar6);

          lVar3 = (long long)(int)(unaff_r13[3] - unaff_r14[3]) * (long long)iVar4;

          iVar4 = (int)((int)((unsigned long long)lVar3 >> 0x20) << 0x10 | (unsigned int)lVar3 >> 0x10) >> 1;

          unaff_r14[3] = unaff_r14[3] + iVar4;

          *(unsigned int *)((int)PTR_DAT_0603156c + (int)unaff_r13) = unaff_r13[3] - iVar4;

        }

      }

    }

    if (iVar10 == 0) {

      if (*(int *)0x0602FD9A == '\0') {

        *(int *)0x0602FD9A = 3;

      }

    }

    else {

      sVar5 = *(short *)0x06031A24;

      pcVar9 = 0x0602FD98;

      if (iVar15 == 0) {

        if (uVar11 == 0) {

          uVar6 = (unsigned int)DAT_0603162a;

          if (sVar5 != 0) {

            uVar6 = 0x40;

          }

        }

        else {

          uVar6 = (unsigned int)DAT_060315ce;

          pcVar9 = 0x0602FD98 + 1;

          if (sVar5 != 0) {

            uVar6 = 0x80;

          }

        }

      }

      else if (uVar11 == 0) {

        uVar6 = 0x80;

        pcVar9 = 0x0602FD98 + 1;

        if (sVar5 != 0) {

          uVar6 = (unsigned int)DAT_060315b0;

        }

      }

      else {

        uVar6 = 0x40;

        if (sVar5 != 0) {

          uVar6 = (unsigned int)DAT_060315be;

        }

      }

      cVar1 = *pcVar9;

      *unaff_r14 = *unaff_r14 | uVar6;

      if (cVar1 == '\0') {

        *pcVar9 = '\x03';

      }

      iVar12 = (int)DAT_0603162c;

      if (uVar11 == 0) {

        iVar12 = iVar12 * 3;

      }

      iVar12 = (unaff_r13[0xc] & 0xffff) + iVar12;

      unaff_r12 = (char *)

                  ((int)((unsigned long long)((long long)(int)unaff_r12 * (long long)iVar7) >> 0x20) << 0x10 |

                  (unsigned int)((long long)(int)unaff_r12 * (long long)iVar7) >> 0x10);

      if (bVar2) {

        unaff_r12 = unaff_r12 + (int)0x0000D999;

      }

    }

    if (*(short *)((int)DAT_0603162e + (int)unaff_r14) < 8) {

      if (*(short *)((int)DAT_0603162e + (int)unaff_r14) < 6) {

        puVar13 = (char *)((unsigned int)unaff_r12 >> 2);

        puVar16 = (char *)((unsigned int)unaff_r12 >> 2) + ((unsigned int)unaff_r12 >> 1);

      }

      else {

        puVar13 = (char *)0x0;

        puVar16 = unaff_r12;

      }

    }

    else {

      puVar16 = (char *)0x0;

      puVar13 = unaff_r12;

    }

    uVar6 = unaff_r14[4];

    uVar8 = unaff_r14[6];

    unaff_r14[0xe] = uVar6;

    unaff_r14[0xf] = uVar8;

    iVar7 = (*(void(*)())0x06027344)(-iVar12);

    iVar10 = (*(void(*)())0x06027348)(-iVar12);

    unaff_r14[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3 * (long long)iVar10) >> 0x20) <<

                            0x10 | (unsigned int)((long long)extraout_r3 * (long long)iVar10) >> 0x10);

    unaff_r14[6] = uVar8 + ((int)((unsigned long long)((long long)(int)puVar13 * (long long)iVar7) >> 0x20) <<

                            0x10 | (unsigned int)((long long)(int)puVar13 * (long long)iVar7) >> 0x10);

    puVar13 = 0x00008000 + iVar12;

    uVar6 = unaff_r13[4];

    uVar8 = unaff_r13[6];

    unaff_r13[0xe] = uVar6;

    unaff_r13[0xf] = uVar8;

    iVar12 = (*(void(*)())0x06027344)(-(int)puVar13);

    iVar7 = (*(void(*)())0x06027348)(-(int)puVar13);

    unaff_r13[4] = uVar6 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)iVar7) >> 0x20)

                            << 0x10 | (unsigned int)((long long)extraout_r3_00 * (long long)iVar7) >> 0x10);

    unaff_r13[6] = uVar8 + ((int)((unsigned long long)

                                  ((long long)(int)(puVar16 + ((unsigned int)puVar16 >> 1)) *

                                  (long long)iVar12) >> 0x20) << 0x10 |

                           (unsigned int)((long long)(int)(puVar16 + ((unsigned int)puVar16 >> 1)) * (long long)iVar12

                                 ) >> 0x10);

  }

  return iVar7;

}
