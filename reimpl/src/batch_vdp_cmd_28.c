extern int DAT_06028304;
extern int DAT_06028348;
extern int DAT_06028708;
extern int DAT_06029c2e;
extern int DAT_06029ea4;
extern int DAT_06029ea6;
extern int DAT_06029ed4;
extern int DAT_06029ee2;
extern int DAT_06029f2a;
extern int DAT_06029f2c;
extern int DAT_06029f2e;
extern int DAT_06029f30;
extern int DAT_06029f3e;
extern int DAT_06029f4c;
extern int DAT_06029f94;
extern int DAT_06029f96;
extern int DAT_06029f98;
extern int DAT_06029f9a;
extern int DAT_06029fa8;
extern int DAT_06029fb6;
extern int DAT_06029ffe;
extern int DAT_0602a000;
extern int DAT_0602a002;
extern int DAT_0602a004;
extern int DAT_0602a012;
extern int DAT_0602a020;
extern int DAT_0602a050;
extern char * FUN_060282c0();
extern char * FUN_06028306();
extern int PTR_DAT_060286ac;
extern int PTR_DAT_06029ea8;

void FUN_060280f8(param_1, param_2)
    int param_1;
    short *param_2;
{

  unsigned short uVar1;

  short sVar2;

  int uVar3;

  int *puVar4;

  int uVar5;

  int uVar6;

  uVar1 = *(unsigned short *)

           (0x060684EC +

           ((int)*(short *)(param_1 + 6) + (((unsigned int)*(unsigned char *)(param_1 + 5) << 8) >> 2)) << 1);

  sVar2 = *(short *)(0x06063F64 + (unsigned int)(uVar1 << 3) + 6);

  *param_2 = (short)*(int *)(0x06028178 + ((int)*(char *)(param_1 + 4) & 0xc));

  param_2[2] = *(short *)(0x06028174 + ((int)*(char *)(param_1 + 4) & 1U) << 1);

  param_2[3] = (short)*(int *)0x06059FFC + sVar2;

  puVar4 = (int *)(0x06063F64 + (unsigned int)(uVar1 << 3));

  uVar3 = *(int *)(param_1 + 0x14);

  param_2[4] = (short)*puVar4;

  uVar6 = *(int *)(param_1 + 0x10);

  param_2[5] = *(short *)(puVar4 + 1);

  uVar5 = *(int *)(param_1 + 0xc);

  *(int *)(param_2 + 6) = *(int *)(param_1 + 8);

  *(int *)(param_2 + 8) = uVar5;

  *(int *)(param_2 + 10) = uVar6;

  *(int *)(param_2 + 0xc) = uVar3;

  return;

}

char * FUN_060282c0(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int *puVar5;

  char uVar6;

  puVar2 = (int *)0x20202020;

  puVar1 = (int *)0x060620C4;

  *(char **)0x060620C4 = 0x20202020;

  *(char **)(puVar1 + 4) = puVar2;

  *(char **)(puVar1 + 8) = puVar2;

  puVar1[0xb] = 0;

  uVar6 = 0x20;

  if (param_1 < 0) {

    param_1 = -param_1;

    uVar6 = 0x2d;

  }

  puVar5 = (int *)-256;

  *puVar5 = 10;

  iVar3 = 10;

  do {

    iVar4 = iVar3;

    if (param_1 == 0) break;

    puVar5[1] = param_1;

    iVar4 = iVar3 + -1;

    puVar1[iVar3 + 1] = (char)puVar5[6];

    param_1 = puVar5[7];

    iVar3 = iVar4;

  } while (iVar4 != 0);

  puVar1[iVar4] = uVar6;

  return puVar1;

}

char * FUN_06028306(param_1)
    int param_1;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  int iVar4;

  int *puVar5;

  char uVar6;

  uVar2 = 0x0A0A0A0A;

  puVar1 = (int *)0x060620C4;

  *(int *)0x060620C4 = 0x0A0A0A0A;

  *(int *)(puVar1 + 4) = uVar2;

  *(int *)(puVar1 + 8) = uVar2;

  puVar1[0xb] = 0;

  uVar6 = 10;

  if (param_1 < 0) {

    param_1 = -param_1;

    uVar6 = 0x2d;

  }

  puVar5 = (int *)-256;

  *puVar5 = 10;

  iVar3 = 10;

  do {

    iVar4 = iVar3;

    if (param_1 == 0) break;

    puVar5[1] = param_1;

    iVar4 = iVar3 + -1;

    puVar1[iVar3 + 1] = (char)puVar5[6];

    param_1 = puVar5[7];

    iVar3 = iVar4;

  } while (iVar4 != 0);

  puVar1[iVar4] = uVar6;

  return puVar1;

}

int FUN_0602834a(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    int param_4;
{

  char cVar1;

  int bVar2;

  int iVar3;

  char *pcVar4;

  param_2 = param_2 + **(int **)(0x06028614 + param_1);

  iVar3 = FUN_060282c0(param_4);

  pcVar4 = (char *)(iVar3 + 8);

  iVar3 = 0;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

    *(short *)(param_2 + iVar3) = cVar1 + param_3;

    bVar2 = iVar3 != 6;

    iVar3 = iVar3 + 2;

  } while (bVar2);

  return 8;

}

char * FUN_060283e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    char *param_4;
{

  char cVar1;

  char *puVar2;

  short *psVar3;

  puVar2 = (int *)0x06028614;

  psVar3 = (short *)(**(int **)(0x06028614 + param_1) + param_2);

  while( 1 ) {

    cVar1 = *param_4;

    param_4 = param_4 + 1;

    if (cVar1 == '\0') break;

    *psVar3 = cVar1 + param_3;

    psVar3 = psVar3 + 1;

  }

  return puVar2;

}

int FUN_06028400(param_1, param_2, param_3, param_4)
    int param_1;
    short *param_2;
    int param_3;
    int param_4;
{

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  short *puVar5;

  puVar5 = (short *)(param_3 + **(int **)(0x06028614 + param_1));

  iVar4 = (int)*param_2;

  iVar3 = (int)param_2[1];

  param_2 = param_2 + 2;

  iVar2 = iVar4;

  do {

    do {

      sVar1 = *param_2;

      param_2 = param_2 + 1;

      *puVar5 = (short)(sVar1 + param_4);

      iVar2 = iVar2 + -1;

      puVar5 = puVar5 + 1;

    } while (iVar2 != 0);

    iVar3 = iVar3 + -1;

    puVar5 = (short *)((int)puVar5 - ((iVar4 << 1) + -0x80));

    iVar2 = iVar4;

  } while (iVar3 != 0);

  return sVar1 + param_4;

}

void FUN_06028430(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char cVar1;

  char cVar2;

  short sVar3;

  short sVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  int iVar8;

  int iVar9;

  short *psVar10;

  int *piVar11;

  int iVar12;

  short *psVar13;

  int iVar14;

  psVar10 = (short *)(param_2 + **(int **)(0x06028614 + param_1));

  iVar5 = FUN_06028306(param_4);

  piVar11 = (int *)(0x06063690 + param_3);

  iVar8 = *piVar11;

  sVar3 = *(short *)(piVar11 + 1);

  cVar1 = *(char *)((int)piVar11 + 6);

  iVar9 = (int)*(char *)((int)piVar11 + 7);

  cVar2 = *(char *)(piVar11 + 2);

  iVar12 = (int)*(char *)((int)piVar11 + 9);

  sVar4 = *(short *)((int)piVar11 + 10);

  pcVar6 = (char *)(iVar5 - (iVar12 + -0xc));

  pcVar7 = pcVar6;

  iVar5 = iVar12;

  do {

    do {

      psVar13 = (short *)(iVar8 + ((int)cVar2 & 0xffffU) * ((int)*pcVar7 & 0xffffU));

      iVar14 = (int)cVar1;

      do {

        *psVar10 = *psVar13 + sVar3;

        psVar13 = psVar13 + 1;

        iVar14 = iVar14 + -1;

        psVar10 = psVar10 + 1;

      } while (iVar14 != 0);

      iVar5 = iVar5 + -1;

      pcVar7 = pcVar7 + 1;

    } while (iVar5 != 0);

    iVar8 = iVar8 + (cVar1 << 1);

    iVar9 = iVar9 + -1;

    psVar10 = (short *)((int)psVar10 + (int)sVar4);

    pcVar7 = pcVar6;

    iVar5 = iVar12;

  } while (iVar9 != 0);

  return;

}

void FUN_060284ae(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    char *param_4;
{

  char cVar1;

  char cVar2;

  char cVar3;

  short sVar4;

  char *pcVar5;

  int iVar6;

  unsigned int uVar7;

  int iVar8;

  short *psVar9;

  int *piVar10;

  short *psVar11;

  unsigned int uVar12;

  unsigned int uVar13;

  unsigned int uVar14;

  psVar9 = (short *)(param_2 + **(int **)(0x06028614 + param_1));

  piVar10 = (int *)(0x06063690 + param_3);

  iVar6 = *piVar10;

  sVar4 = *(short *)(piVar10 + 1);

  uVar7 = (unsigned int)*(char *)((int)piVar10 + 6);

  iVar8 = (int)*(char *)((int)piVar10 + 7);

  cVar1 = *(char *)(piVar10 + 2);

  cVar2 = *(char *)((int)piVar10 + 9);

  uVar13 = 0xffffffff;

  pcVar5 = param_4;

  do {

    cVar3 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    uVar13 = uVar13 + 1;

  } while (cVar3 != '\0');

  pcVar5 = param_4;

  uVar12 = uVar13;

  do {

    do {

      psVar11 = (short *)(iVar6 + ((int)cVar1 & 0xffffU) * ((int)*pcVar5 - (int)cVar2 & 0xffffU));

      uVar14 = uVar7;

      do {

        *psVar9 = *psVar11 + sVar4;

        psVar11 = psVar11 + 1;

        uVar14 = uVar14 - 1;

        psVar9 = psVar9 + 1;

      } while (uVar14 != 0);

      uVar12 = uVar12 - 1;

      pcVar5 = pcVar5 + 1;

    } while (uVar12 != 0);

    iVar6 = iVar6 + (uVar7 << 1);

    iVar8 = iVar8 + -1;

    psVar9 = psVar9 + -((uVar7 & 0xffff) * (uVar13 & 0xffff) + -0x40);

    pcVar5 = param_4;

    uVar12 = uVar13;

  } while (iVar8 != 0);

  return;

}

int * FUN_0602853e(param_1)
    int param_1;
{

  int *puVar1;

  int iVar2;

  int uVar3;

  uVar3 = *(int *)(0x06028644 + param_1);

  puVar1 = (int *)**(int **)(0x0602862C + param_1);

  iVar2 = 0x0800;

  do {

    *puVar1 = uVar3;

    iVar2 = iVar2 + -1;

    puVar1 = puVar1 + 1;

  } while (iVar2 != 0);

  return puVar1;

}

int * FUN_06028560()
{

  char *puVar1;

  int *puVar2;

  int iVar3;

  puVar1 = (int *)0x00200020;

  iVar3 = 0x0380;

  puVar2 = (int *)0x060612C4;

  do {

    *puVar2 = puVar1;

    iVar3 = iVar3 + -1;

    puVar2 = puVar2 + 1;

  } while (iVar3 != 0);

  return puVar2;

}

long long FUN_06028654(param_1, param_2)
    unsigned char *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned char bVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int in_r0 = 0;

  int in_r1 = 0;

  int iVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  int iVar9;

  unsigned int uVar10;

  uVar5 = 0x00000FFF;

  puVar4 = (char *)0x0000FF00;

  puVar3 = (char *)0x0602872C;

  uVar7 = 0;

  uVar8 = 0;

  while( 1 ) {

    while( 1 ) {

      uVar8 = uVar8 >> 1;

      if ((uVar8 & 0x100) == 0) {

        bVar1 = *param_1;

        param_1 = param_1 + 1;

        uVar8 = (unsigned int)bVar1 | (unsigned int)puVar4;

      }

      if ((uVar8 & 1) == 0) break;

      bVar1 = *param_1;

      param_1 = param_1 + 1;

      *param_2 = bVar1;

      param_2 = param_2 + 1;

      puVar3[uVar7] = bVar1;

      uVar7 = uVar7 + 1 & uVar5;

    }

    bVar1 = *param_1;

    bVar2 = param_1[1];

    param_1 = param_1 + 2;

    if (bVar2 == 0 && bVar1 == 0) break;

    uVar10 = (unsigned int)DAT_06028708;

    iVar9 = ((bVar2 | uVar10) << 8 | (unsigned int)bVar1) + uVar7;

    iVar6 = 0;

    do {

      bVar1 = puVar3[iVar9 + iVar6 & uVar5];

      *param_2 = bVar1;

      param_2 = param_2 + 1;

      puVar3[uVar7] = bVar1;

      uVar7 = uVar7 + 1 & uVar5;

      iVar6 = iVar6 + 1;

    } while (iVar6 < ((int)(bVar2 & uVar10) >> 4) + 3);

  }

  return CONCAT44(in_r1,in_r0);

}

unsigned int FUN_06029bf4(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    char param_3;
    int param_4;
{

  unsigned int uVar1;

  unsigned int uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  int *puVar10;

  int uVar11;

  int iVar12;

  unsigned int *puVar13;

  unsigned int *puVar14;

  unsigned int *puVar15;

  unsigned int *puVar16;

  int iVar17;

  unsigned int in_sr = 0;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  iVar17 = *(int *)0x06063F08;

  puVar15 = (unsigned int *)(param_1 + param_4 * 0x18);

  do {

    puVar3 = (char *)0x0608A70C;

    puVar16 = puVar15 + -6;

    uVar19 = in_sr & 0xfffffffe;

    uVar18 = uVar19 | *(short *)0x0605BE36 == 0;

    if ((((unsigned char)uVar18 & 1) == 1) ||

       (uVar7 = (unsigned int)*(short *)((int)puVar15 + -10), uVar18 = uVar19, (int)DAT_06029c2e != uVar7))

    {

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -2) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar7 = *puVar14;

      uVar19 = *puVar13;

      uVar20 = uVar7 ^ uVar19;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar2 = (uVar19 & 0xffff) * (uVar7 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar7 & 0xffff);

      iVar8 = 0;

      uVar1 = iVar9 + (uVar19 & 0xffff) * (uVar7 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar2 + (uVar1 << 16);

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar19 >> 0x10) * (uVar7 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar20 = puVar14[1];

      uVar7 = puVar13[1];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar26 = uVar21 + uVar26;

        uVar19 = uVar7 + (uVar26 < uVar21) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar26 = uVar21 + uVar26;

        uVar19 = uVar7 + (uVar26 < uVar21) + uVar19;

      }

      uVar20 = puVar14[2];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar26 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar26 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar26) + uVar19;

      }

      uVar20 = puVar14[3];

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[4];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + uVar7;

      }

      *(unsigned int *)0x0608A70C = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar14[9];

      uVar20 = puVar14[5];

      uVar19 = puVar13[2];

      uVar1 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar21 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar19 + (uVar23 < uVar22) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar19 + (uVar23 < uVar22) + uVar7;

      }

      uVar20 = puVar14[6];

      uVar19 = *puVar13;

      uVar1 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar21 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar19 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar26 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar1 = puVar14[7];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + uVar19;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar7 << 0x10 | uVar23 >> 0x10) + puVar14[10];

      uVar20 = puVar14[8];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar22) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar22) + uVar19;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar14[0xb];

      puVar4 = (char *)0x0608A704;

      uVar19 = uVar18 & 0xfffffffe;

      *(unsigned short *)0x0608A704 = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = (char *)0x0608A73C;

      if ((puVar15[-3] & 0x80000) == 0) {

        puVar13 = *(unsigned int **)0x06089EDC;

        uVar20 = *puVar13;

        uVar7 = *puVar16;

        uVar1 = uVar20 ^ uVar7;

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

        iVar8 = 0;

        uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar23 = uVar21 + (uVar2 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

                (uVar7 >> 0x10) * (uVar20 >> 0x10);

        if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar23 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar23 = ~uVar23 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar23 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar23 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        uVar1 = puVar13[1];

        uVar20 = puVar15[-5];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar26 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

        }

        uVar1 = puVar13[2];

        uVar20 = puVar15[-4];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        uVar1 = puVar13[3];

        uVar20 = *puVar16;

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        *(unsigned int *)0x0608A73C = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar1 = puVar13[4];

        uVar7 = puVar15[-5];

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar26 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar20 = uVar7 + (uVar26 < uVar24) + (uVar20 & 0xffff);

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar20 = uVar7 + (uVar26 < uVar24) + uVar20;

        }

        uVar1 = puVar13[5];

        uVar7 = puVar15[-4];

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + (uVar21 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar24 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar26 + uVar24;

          uVar20 = uVar7 + (uVar24 < uVar26) + (uVar20 & 0xffff);

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        else {

          uVar24 = uVar26 + uVar24;

          uVar20 = uVar7 + (uVar24 < uVar26) + uVar20;

        }

        uVar1 = puVar13[6];

        uVar7 = *puVar16;

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar26 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        *(unsigned int *)(puVar3 + 4) = uVar20 << 0x10 | uVar24 >> 0x10;

        uVar1 = puVar13[7];

        uVar20 = puVar15[-5];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar26 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar26) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar26 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar26) + uVar7;

        }

        uVar1 = puVar13[8];

        uVar20 = puVar15[-4];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        *(unsigned int *)(puVar3 + 8) = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar20 = *(unsigned int *)puVar3;

        uVar7 = *(unsigned int *)0x0608A70C;

        uVar1 = uVar20 ^ uVar7;

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

        iVar8 = 0;

        uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar23 = uVar21 + (uVar2 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

                (uVar7 >> 0x10) * (uVar20 >> 0x10);

        if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar23 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar23 = ~uVar23 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar23 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar23 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        uVar1 = *(unsigned int *)(puVar3 + 4);

        uVar20 = *(unsigned int *)(0x0608A70C + 4);

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar26 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

        }

        uVar1 = *(unsigned int *)(puVar3 + 8);

        uVar20 = *(unsigned int *)(0x0608A70C + 8);

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        uVar7 = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar19 = uVar19 | 0 < (int)uVar7;

        if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602a1b6;

      }

      puVar3 = (char *)0x0608A718;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -6) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar7 = *puVar14;

      uVar18 = *puVar13;

      uVar20 = uVar7 ^ uVar18;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar2 = (uVar18 & 0xffff) * (uVar7 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar7 & 0xffff);

      iVar8 = 0;

      uVar1 = iVar9 + (uVar18 & 0xffff) * (uVar7 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar2 + (uVar1 << 16);

      uVar18 = iVar8 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar7 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar21 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar20 = puVar14[1];

      uVar7 = puVar13[1];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar21 + uVar26;

        uVar18 = uVar7 + (uVar26 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar26 = uVar21 + uVar26;

        uVar18 = uVar7 + (uVar26 < uVar21) + uVar18;

      }

      uVar20 = puVar14[2];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar26 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar26) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar26 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar26) + uVar18;

      }

      uVar20 = puVar14[3];

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[4];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + uVar7;

      }

      *(unsigned int *)0x0608A718 = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar14[9];

      uVar20 = puVar14[5];

      uVar18 = puVar13[2];

      uVar1 = uVar20 ^ uVar18;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar21 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar18 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

               (uVar18 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar23 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar18 + (uVar23 < uVar22) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar18 + (uVar23 < uVar22) + uVar7;

      }

      uVar20 = puVar14[6];

      uVar18 = *puVar13;

      uVar1 = uVar20 ^ uVar18;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar21 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar18 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) +

               (uVar18 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar26 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar1 = puVar14[7];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar18 = uVar20 + (uVar22 < uVar26) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar18 = uVar20 + (uVar22 < uVar26) + uVar18;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar7 << 0x10 | uVar23 >> 0x10) + puVar14[10];

      uVar20 = puVar14[8];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar22) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar22) + uVar18;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar14[0xb];

      uVar18 = uVar19 & 0xfffffffe;

      *(unsigned short *)(puVar4 + 2) = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = (char *)0x0608A724;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -1) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar14;

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[1];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar26 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

      }

      uVar1 = puVar14[2];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

      }

      uVar1 = puVar14[3];

      uVar20 = *puVar13;

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar2 = puVar14[4];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + uVar20;

      }

      *(unsigned int *)0x0608A724 = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[9];

      uVar1 = puVar14[5];

      uVar7 = puVar13[2];

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + uVar20;

      }

      uVar1 = puVar14[6];

      uVar7 = *puVar13;

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar24 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar2 = puVar14[7];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + uVar7;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar20 << 0x10 | uVar26 >> 0x10) + puVar14[10];

      uVar1 = puVar14[8];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + uVar7;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[0xb];

      *(unsigned short *)(puVar4 + 4) = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = (char *)0x0608A730;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -2) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar14;

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[1];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar26 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

      }

      uVar1 = puVar14[2];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

      }

      uVar1 = puVar14[3];

      uVar20 = *puVar13;

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar2 = puVar14[4];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + uVar20;

      }

      *(unsigned int *)0x0608A730 = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[9];

      uVar1 = puVar14[5];

      uVar7 = puVar13[2];

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + uVar20;

      }

      uVar1 = puVar14[6];

      uVar7 = *puVar13;

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar24 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar2 = puVar14[7];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + uVar7;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar20 << 0x10 | uVar26 >> 0x10) + puVar14[10];

      uVar1 = puVar14[8];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + uVar7;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[0xb];

      iVar8 = *(int *)(puVar3 + 8);

      *(unsigned short *)(puVar4 + 6) = (unsigned short)(iVar8 <= iVar17);

      iVar8 = (unsigned int)(iVar8 <= iVar17) + (int)*(short *)(puVar4 + 4) +

              (int)*(short *)(puVar4 + 2) + (int)*(short *)puVar4;

      uVar19 = uVar18 | iVar8 == 0;

      if (((unsigned char)uVar19 & 1) != 1) {

        if (iVar8 == 4) {

          uVar7 = 4;

          uVar19 = uVar18;

          goto LAB_0602a1b6;

        }

        (*(int(*)())(*(int *)(0x0602A1E0 + (iVar8 << 2))))(0x0608A70C,0x0608A704,puVar14 + 9,puVar14 + 0xc);

        uVar19 = uVar18;

      }

      puVar5 = (short *)0x0608A76C;

      puVar4 = (char *)0x0608AC20;

      puVar3 = (char *)0x0608A70C;

      iVar8 = *(int *)0x060620D0;

      puVar10 = (int *)-256;

      uVar11 = *(int *)(0x0608A70C + 8);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 4);

      iVar9 = puVar10[7];

      *(int *)puVar5 = (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)puVar3) >> 0x20);

      *(int *)(puVar5 + 4) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      puVar6 = (char *)0x0608A6FC;

      iVar9 = *(int *)puVar5;

      iVar12 = *(int *)(puVar5 + 4);

      *(short *)0x0608A6FC = 0;

      uVar19 = uVar19 & 0xfffffffe;

      if (PTR_DAT_06029ea8 < iVar9) {

        *(short *)puVar6 = 1;

      }

      else if (iVar9 < DAT_06029ed4) {

        *(short *)puVar6 = 1;

      }

      else if (DAT_06029ee2 < iVar12) {

        *(short *)puVar6 = 1;

      }

      else if (iVar12 < DAT_06029f2a) {

        *(short *)puVar6 = 1;

      }

      puVar10 = (int *)-256;

      uVar11 = *(int *)(puVar3 + 0x14);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x10);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 8) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0xc)) >> 0x20);

      *(int *)(puVar5 + 0xc) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 8);

      iVar12 = *(int *)(puVar5 + 0xc);

      *(short *)(puVar6 + 2) = 0;

      if (DAT_06029f30 < iVar9) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (iVar9 < DAT_06029f3e) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (DAT_06029f4c < iVar12) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (iVar12 < DAT_06029f94) {

        *(short *)(puVar6 + 2) = 1;

      }

      puVar10 = (int *)-256;

      uVar11 = *(int *)(puVar3 + 0x20);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x1c);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 0x10) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0x18)) >> 0x20);

      *(int *)(puVar5 + 0x14) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 0x10);

      iVar12 = *(int *)(puVar5 + 0x14);

      *(short *)(puVar6 + 4) = 0;

      if (DAT_06029f9a < iVar9) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (iVar9 < DAT_06029fa8) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (DAT_06029fb6 < iVar12) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (iVar12 < DAT_06029ffe) {

        *(short *)(puVar6 + 4) = 1;

      }

      puVar10 = (int *)-256;

      uVar11 = *(int *)(puVar3 + 0x2c);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x28);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 0x18) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0x24)) >> 0x20);

      *(int *)(puVar5 + 0x1c) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 0x18);

      iVar12 = *(int *)(puVar5 + 0x1c);

      *(short *)(puVar6 + 6) = 0;

      if (DAT_0602a004 < iVar9) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (iVar9 < DAT_0602a012) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (DAT_0602a020 < iVar12) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (iVar12 < DAT_0602a050) {

        *(short *)(puVar6 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar5) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar5 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar5 + 0x10))) ||

         (uVar7 = *(unsigned int *)(puVar5 + 0x18), (int)0xFFFFFF50 <= (int)uVar7)) {

        uVar18 = uVar19 | *(int *)puVar5 < 0x000000B0;

        if (((((unsigned char)uVar18 & 1) != 1) &&

            (uVar18 = uVar19 | *(int *)(puVar5 + 8) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) &&

           (uVar18 = uVar19 | *(int *)(puVar5 + 0x10) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) {

          uVar7 = *(unsigned int *)(puVar5 + 0x18);

          uVar18 = uVar19 | (int)uVar7 < 0x000000B0;

          uVar19 = uVar18;

          if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602a1b6;

        }

        uVar18 = uVar18 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar5 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar5 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar5 + 0x14) ||

            (uVar7 = *(unsigned int *)(puVar5 + 0x1c), uVar19 = uVar18, (int)0xFFFFFF81 <= (int)uVar7)

            ))) {

          uVar19 = uVar18 | *(int *)(puVar5 + 4) < 0x00000051;

          if (((((unsigned char)uVar19 & 1) != 1) &&

              (uVar19 = uVar18 | *(int *)(puVar5 + 0xc) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) &&

             (uVar19 = uVar18 | *(int *)(puVar5 + 0x14) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) {

            uVar7 = *(unsigned int *)(puVar5 + 0x1c);

            uVar19 = uVar18 | (int)uVar7 < 0x00000051;

            if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602a1b6;

          }

          iVar9 = (int)*(short *)(puVar6 + 6) +

                  (int)*(short *)puVar6 + (int)*(short *)(puVar6 + 2) + (int)*(short *)(puVar6 + 4);

          if (iVar9 != 4) {

            if (iVar9 != 0) {

              (*(int(*)())(*(int *)(0x0602A1F0 + (iVar9 << 2))))(puVar5,puVar6);

            }

            *(short *)(puVar4 + iVar8 * 0x18 + 8) = (short)*(int *)puVar5;

            *(short *)(puVar4 + iVar8 * 0x18 + 10) = (short)*(int *)(puVar5 + 4);

            *(short *)(puVar4 + iVar8 * 0x18 + 0xc) = (short)*(int *)(puVar5 + 8);

            *(short *)(puVar4 + iVar8 * 0x18 + 0xe) = (short)*(int *)(puVar5 + 0xc);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x10) = (short)*(int *)(puVar5 + 0x10);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x12) = (short)*(int *)(puVar5 + 0x14);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x14) = (short)*(int *)(puVar5 + 0x18);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x16) = (short)*(int *)(puVar5 + 0x1c);

            *(short *)(puVar4 + iVar8 * 0x18 + 6) = *(short *)((int)puVar15 + -10);

            puVar4[iVar8 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar15 + -3) >> 4) & 0xf;

            puVar4[iVar8 * 0x18 + 5] = param_3;

            uVar19 = (*(int(*)())(*(int *)(0x0602A200 + ((int)*(short *)(puVar15 + -3) & 7U) << 2)))(*(int *)(0x0608A70C + 0x14),

                                *(int *)(0x0608A70C + 0x20),

                                *(int *)(0x0608A70C + 0x2c));

            return uVar19;

          }

          uVar7 = 4;

          uVar19 = uVar19 & 0xfffffffe;

        }

      }

    }

LAB_0602a1b6:

    param_4 = param_4 + -1;

    in_sr = uVar19 & 0xfffffffe | (unsigned int)(param_4 == 0);

    puVar15 = puVar16;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar7;

    }

  } while( 1 );

}
