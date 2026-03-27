/* TU: FUN_0602D43C — Collision/steering response + speed/position writers */
/* Functions: FUN_0602D43C, FUN_0602D7E4, sym_0602D814, sym_0602D82A,
 *            sym_0602D88E, FUN_0602D89A, sym_0602D8BC, FUN_0602D8C6 */


/* ============ FUN_0602D43C ============ */

extern int DAT_0602d48a;

extern int DAT_0602d48c;

extern int DAT_0602d48e;

extern int DAT_0602d490;

extern int DAT_0602d492;

extern int DAT_0602d494;

extern int DAT_0602d496;

extern int DAT_0602d542;

extern int DAT_0602d544;

extern int DAT_0602d546;

extern int DAT_0602d548;

extern int DAT_0602d54a;

extern int DAT_0602d5f0;

extern int DAT_0602d5f2;

extern int DAT_0602d5f4;

extern int DAT_0602d5f6;

extern int DAT_0602d62c;

extern int DAT_0602d62e;

extern int DAT_0602d67c;

extern int DAT_0602d67e;

extern int DAT_0602d680;

extern int DAT_0602d682;

extern int DAT_0602d6be;

extern int DAT_0602d6c2;

extern int DAT_0602d730;

extern int DAT_0602d732;

extern int DAT_0602d790;

extern int DAT_0602d792;

extern int PTR_DAT_0602d54c;

extern int PTR_DAT_0602d54c;

extern int PTR_DAT_0602d5f8;

extern int PTR_DAT_0602d5f8;

extern int PTR_DAT_0602d794;

extern int PTR_DAT_0602d794;

extern int PTR_DAT_0602d7dc;

extern int PTR_DAT_0602d7dc;

extern int FUN_0602d7e4();

void FUN_0602d43c()
{

  long long lVar1;

  unsigned int *puVar2;

  int *puVar3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  int uVar7;

  char *puVar8;

  short sVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  unsigned int *unaff_r14;

  unsigned int local_8;

  iVar11 = *(int *)((int)DAT_0602d48a + (int)unaff_r14);

  iVar12 = 0x168;

  if (*(short *)((int)DAT_0602d48e + (int)unaff_r14) < 1) {

    iVar5 = 0x2f8;

    if (((0xf0 <= (int)unaff_r14[2]) &&

        (*(int *)(0x40 + (int)unaff_r14) != 0)) &&

       (*(int *)((int)DAT_0602d496 + (int)unaff_r14) <= (int)0x00006800)) {

      iVar10 = iVar11;

      if (iVar11 <= iVar5) {

        if (-iVar5 <= iVar11) goto LAB_0602d4a4;

        iVar10 = -iVar11;

      }

      iVar10 = iVar10 - iVar5;

      if (iVar10 < 5) {

        iVar10 = 4;

      }

      else if (9 < iVar10) {

        iVar10 = 10;

      }

      *(short *)(iVar12 + (int)unaff_r14) = (short)iVar10;

    }

  }

LAB_0602d4a4:

  iVar5 = (int)*(short *)(iVar12 + (int)unaff_r14);

  puVar2 = unaff_r14;

  if (0 < iVar5) {

    if (*(int *)((int)DAT_0602d542 + (int)unaff_r14) == 0) {

      iVar5 = iVar5 + -2;

    }

    *(short *)(iVar12 + (int)unaff_r14) = (short)(iVar5 + -1);

    uVar7 = 0;

    if (-1 < (int)(0x000A0000 + (iVar5 + -1) * -0x10000)) {

      lVar1 = (long long)*(int *)((int)DAT_0602d544 + (int)unaff_r14) *

              (long long)(int)(0x000A0000 + (iVar5 + -1) * -0x10000);

      puVar3 = (int *)-256;

      *puVar3 = 0x000A0000;

      puVar3[4] = (int)(short)((unsigned long long)lVar1 >> 0x20);

      puVar3[5] = (unsigned int)lVar1 & 0xffff0000;

      uVar7 = puVar3[7];

    }

    *(int *)((int)DAT_0602d544 + (int)unaff_r14) = uVar7;

    puVar2 = (unsigned int *)FUN_0602d7e4();

  }

  iVar12 = (*(int(*)())0x06027344)(*(int *)((int)DAT_0602d548 + (int)puVar2));

  lVar1 = (long long)*(int *)((int)DAT_0602d544 + (int)unaff_r14) *

          (long long)*(int *)((int)DAT_0602d54a + (int)unaff_r14);

  lVar1 = (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) *

          (long long)(int)*(short *)((int)PTR_DAT_0602d54c + (int)unaff_r14);

  uVar6 = (unsigned int)lVar1 >> 0x18 | (int)((unsigned long long)lVar1 >> 0x20) << 8;

  uVar4 = unaff_r14[3];

  if ((int)uVar4 < 0x00000100) {

    puVar8 = 0x00004000;

    if ((int)uVar6 < 0) {

      puVar8 = (char *)-(int)0x00004000;

    }

    local_8 = 0;

  }

  else {

    local_8 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)(int)uVar4) >> 0x20) << 0x10 |

              (unsigned int)((long long)(int)uVar4 * (long long)(int)uVar4) >> 0x10;

    puVar2 = (unsigned int *)-256;

    *puVar2 = local_8;

    puVar2[4] = (int)(short)((unsigned long long)lVar1 >> 0x28);

    puVar2[5] = uVar6 << 0x10;

    puVar8 = (char *)(*(int(*)())0x06027378)(puVar2[7]);

    if (puVar8 == (char *)0x0) {

      puVar8 = (char *)(int)*(char *)((int)DAT_0602d5f2 + (int)unaff_r14);

    }

  }

  sVar9 = (short)puVar8;

  if (((0 < *(short *)((int)DAT_0602d5f4 + (int)unaff_r14)) && ((int)unaff_r14[2] < 0x46)) &&

     ((int)(*(unsigned int *)((int)PTR_DAT_0602d5f8 + (int)unaff_r14) ^

           *(unsigned int *)(0x40 + (int)unaff_r14)) < 0)) {

    iVar10 = (int)(int)puVar8 << 0x10;

    iVar5 = (*(int(*)())0x06027344)((short)((int)*(unsigned int *)(0x40 + (int)unaff_r14) >> 1) * 9);

    sVar9 = (short)((unsigned long long)((long long)iVar10 * (long long)iVar5) >> 0x20);

    if (sVar9 < 0) {

      sVar9 = 0;

    }

  }

  iVar5 = sVar9 * 3;

  iVar10 = -*(int *)((int)PTR_DAT_0602d5f8 + (int)unaff_r14);

  if (iVar10 < 0) {

    iVar5 = sVar9 * -3;

    if (iVar10 <= iVar5) goto LAB_0602d610;

  }

  else if (iVar5 <= iVar10) goto LAB_0602d610;

  iVar5 = iVar10;

LAB_0602d610:

  iVar5 = iVar5 - (short)((unsigned long long)((long long)(iVar11 << 0x10) * (long long)iVar12) >> 0x20);

  iVar12 = 0x300;

  iVar11 = -iVar12;

  if ((iVar11 < iVar5) && (iVar11 = iVar5, iVar12 <= iVar5)) {

    iVar11 = iVar12;

  }

  *(int *)(0x178 + (int)unaff_r14) = iVar11;

  iVar12 = *(int *)((int)DAT_0602d67c + (int)unaff_r14);

  iVar11 = iVar11 + iVar12;

  *(int *)((int)DAT_0602d67c + (int)unaff_r14) = iVar11 - (-(iVar12 - iVar11) >> 3);

  lVar1 = (long long)*(int *)(0x108 + (int)unaff_r14) *

          (long long)*(int *)(0x140 + (int)unaff_r14);

  lVar1 = (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10) *

          (long long)(int)*(short *)((int)DAT_0602d682 + (int)unaff_r14);

  if (local_8 != 0) {

    puVar2 = (unsigned int *)-256;

    *puVar2 = local_8;

    puVar2[4] = (int)(short)((unsigned long long)lVar1 >> 0x28);

    puVar2[5] = ((unsigned int)lVar1 >> 0x18 | (int)((unsigned long long)lVar1 >> 0x20) << 8) << 0x10;

    (*(int(*)())0x06027378)(puVar2[7]);

  }

  (*(int(*)())0x0602ECCC)(DAT_0602d6c2 + -0x32);

  uVar4 = *(unsigned int *)(0x40 + (int)unaff_r14);

  uVar6 = uVar4 - *(int *)((int)DAT_0602d732 + (int)unaff_r14);

  if ((int)(uVar6 ^ uVar4) < 0) {

    iVar11 = 0x00000FE0;

    if ((int)uVar4 < 0) {

      iVar11 = -0x00000FE0;

    }

    (*(int(*)())0x0602ECCC)(iVar11);

  }

  iVar11 = (*(int(*)())0x0602ECCC)();

  *(unsigned int *)((int)DAT_0602d790 + (int)unaff_r14) =

       (iVar11 - uVar6) -

       ((int)-(*(int *)((int)DAT_0602d790 + (int)unaff_r14) - (iVar11 - uVar6)) >> 3);

  iVar11 = (int)PTR_DAT_0602d794;

  if (0x41 < (int)unaff_r14[2]) {

    if (0xFFFFCD80 < *(int *)(iVar11 + (int)unaff_r14)) {

      if (-0xFFFFCD80 <= *(int *)(iVar11 + (int)unaff_r14)) {

        *unaff_r14 = *unaff_r14 | (unsigned int)0x20000000 | 0x40000000;

      }

    }

    else {

      *unaff_r14 = *unaff_r14 | 0x10000000 | 0x40000000;

    }

  }

  iVar5 = *(int *)(iVar11 + (int)unaff_r14);

  iVar12 = 0xFFFFCC00;

  if ((iVar5 <= 0xFFFFCC00) || (iVar12 = -0xFFFFCC00, iVar12 < iVar5)) {

    *(short *)((int)PTR_DAT_0602d7dc + (int)unaff_r14) = 1;

    iVar5 = iVar12;

  }

  *(int *)(iVar11 + (int)unaff_r14) = iVar5;

  return;

}


/* ============ FUN_0602D7E4 ============ */

extern int PTR_DAT_0602d80c;

extern int PTR_DAT_0602d80c;

void FUN_0602d7e4()
{

  short sVar1;

  int in_r0;

  short sVar2;

  if ((0 < *(int *)(in_r0 + 8)) && (sVar1 = *(short *)(PTR_DAT_0602d80c + in_r0), sVar1 < 4))

  {

    sVar2 = (short)0x0000000A;

    if (sVar1 != 0) {

      sVar2 = sVar2 + -3;

    }

    *(short *)(PTR_DAT_0602d80c + in_r0) = sVar2;

  }

  return;

}


/* ============ FUN_0602D814 ============ */

extern int DAT_0602d862;

extern int DAT_0602d864;

extern int DAT_0602d866;

extern int DAT_0602d88c;

void FUN_0602d814()
{

  long long lVar1;

  unsigned long long uVar2;

  int iVar3;

  int iVar4;

  char *puVar5;

  char *puVar6;

  int unaff_r14;

  iVar3 = (int)DAT_0602d862;

  iVar4 = *(int *)(unaff_r14 + 0xc) + *(int *)(iVar3 + unaff_r14);

  *(int *)(unaff_r14 + 0xc) = iVar4;

  if (iVar4 < 0) {

    *(int *)(unaff_r14 + 0xc) = 0;

    *(int *)(iVar3 + unaff_r14) = 0;

  }

  lVar1 = (long long)*(int *)(0x060477BC + *(short *)(DAT_0602d864 + unaff_r14) << 2) *

          (long long)*(int *)(unaff_r14 + 0xc);

  uVar2 = (long long)(int)0x0221AC91 *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar5 = (char *)((unsigned int)(uVar2 >> 0x20) & 0xffff);

  if ((uVar2 & 0xffff00000000) == 0) {

    puVar6 = (char *)0x0;

  }

  else {

    puVar6 = puVar5;

    if ((int)0x00002134 <= (int)puVar5) {

      puVar6 = 0x00002134;

    }

  }

  *(char **)(DAT_0602d866 + unaff_r14) = puVar6;

  iVar3 = (int)puVar5 - (int)puVar6;

  if (iVar3 < 0) {

    iVar3 = 0;

  }

  *(int *)(DAT_0602d88c + unaff_r14) = iVar3;

  return;

}


/* ============ FUN_0602D82A ============ */

extern int DAT_0602d864;

extern int DAT_0602d866;

extern int DAT_0602d88c;

void FUN_0602d82a()
{

  long long lVar1;

  unsigned long long uVar2;

  int in_r0;

  char *puVar3;

  char *puVar4;

  int iVar5;

  lVar1 = (long long)*(int *)(0x060477BC + *(short *)(DAT_0602d864 + in_r0) << 2) *

          (long long)*(int *)(in_r0 + 0xc);

  uVar2 = (long long)(int)0x0221AC91 *

          (long long)(int)((int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10);

  puVar3 = (char *)((unsigned int)(uVar2 >> 0x20) & 0xffff);

  if ((uVar2 & 0xffff00000000) == 0) {

    puVar4 = (char *)0x0;

  }

  else {

    puVar4 = puVar3;

    if ((int)0x00002134 <= (int)puVar3) {

      puVar4 = 0x00002134;

    }

  }

  *(char **)(DAT_0602d866 + in_r0) = puVar4;

  iVar5 = (int)puVar3 - (int)puVar4;

  if (iVar5 < 0) {

    iVar5 = 0;

  }

  *(int *)(DAT_0602d88c + in_r0) = iVar5;

  return;

}


/* ============ FUN_0602D88E ============ */

extern int FUN_0602d8bc();

void FUN_0602d88e()
{

  FUN_0602d8bc();

  return;

}


/* ============ FUN_0602D89A ============ */

/* FUN_0602D89A  0x0602D89A */


void FUN_0602d89a(void)

{
  FUN_0602d8bc();
  return;
}



/* ============ FUN_0602D8BC ============ */

extern int DAT_0602d916;

extern int DAT_0602d918;

extern int DAT_0602d91a;

extern int DAT_0602d9d0;

extern int DAT_0602d9d2;

void FUN_0602d8bc()
{

  long long lVar1;

  unsigned int *in_r0;

  int iVar2;

  int extraout_r1;

  unsigned int uVar3;

  int extraout_r3;

  unsigned int uVar4;

  int iVar5;

  unsigned int uVar6;

  char *puVar7;

  unsigned int uVar8;

  int unaff_r14;

  long long uVar9;

  if (*(short *)(0x250 + (int)in_r0) != 0) {

    uVar3 = in_r0[0xc];

    (*(int(*)())0x0602ECCC)();

    iVar2 = extraout_r1;

    if ((*in_r0 & 0x00000300) == 0) {

      iVar2 = -extraout_r1;

    }

    in_r0[0xc] = uVar3 + iVar2;

    in_r0[8] = uVar3 + iVar2;

    uVar3 = *(unsigned int *)(0x248 + (int)in_r0);

    in_r0[10] = uVar3;

    puVar7 = (char *)

             ((int)((unsigned long long)

                    ((long long)

                     *(int *)(0x0602E8B8 + *(short *)(0x250 + (int)in_r0) << 2) *

                    (long long)(int)in_r0[3]) >> 0x20) << 0x10 |

             (unsigned int)((long long)

                    *(int *)(0x0602E8B8 + *(short *)(0x250 + (int)in_r0) << 2) *

                   (long long)(int)in_r0[3]) >> 0x10);

    in_r0[3] = (unsigned int)puVar7;

    if ((int)in_r0[2] < 0x29) {

      puVar7 = 0x00006AAA;

    }

    uVar4 = in_r0[4];

    uVar6 = in_r0[6];

    in_r0[0xe] = uVar4;

    in_r0[0xf] = uVar6;

    iVar2 = (*(int(*)())0x06027344)();

    uVar9 = (*(int(*)())0x06027348)(-uVar3);

    lVar1 = (long long)(int)puVar7 * (long long)(int)uVar9;

    uVar3 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    *(unsigned int *)(0x0000018C + (int)in_r0) = uVar3;

    in_r0[4] = uVar4 + uVar3;

    lVar1 = (long long)(int)((unsigned long long)uVar9 >> 0x20) * (long long)iVar2;

    uVar3 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    *(unsigned int *)(0x00000190 + (int)in_r0) = uVar3;

    in_r0[6] = uVar6 + uVar3;

    return;

  }

  in_r0[8] = in_r0[0xc];

  iVar5 = -in_r0[10];

  uVar3 = in_r0[3];

  uVar6 = in_r0[4];

  uVar8 = in_r0[6];

  in_r0[0xe] = uVar6;

  in_r0[0xf] = uVar8;

  iVar2 = (*(int(*)())0x06027344)();

  iVar5 = (*(int(*)())0x06027348)(iVar5);

  uVar4 = (int)((unsigned long long)((long long)extraout_r3 * (long long)iVar5) >> 0x20) << 0x10 |

          (unsigned int)((long long)extraout_r3 * (long long)iVar5) >> 0x10;

  *(unsigned int *)(DAT_0602d918 + unaff_r14) = uVar4;

  *(unsigned int *)(unaff_r14 + 0x10) = uVar6 + uVar4;

  uVar3 = (int)((unsigned long long)((long long)(int)uVar3 * (long long)iVar2) >> 0x20) << 0x10 |

          (unsigned int)((long long)(int)uVar3 * (long long)iVar2) >> 0x10;

  *(unsigned int *)(DAT_0602d91a + unaff_r14) = uVar3;

  *(unsigned int *)(unaff_r14 + 0x18) = uVar8 + uVar3;

  return;

}


/* ============ FUN_0602D8C6 ============ */

/* FUN_0602D8C6  0x0602D8C6 */


void FUN_0602d8c6(void)

{
  longlong lVar1;
  int in_r0;
  int iVar2;
  int iVar3;
  int extraout_r3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_r14;
  
  *(undefined4 *)(in_r0 + 0x20) = *(undefined4 *)(in_r0 + 0x30);
  iVar5 = -*(int *)(in_r0 + 0x28);
  iVar3 = *(int *)(in_r0 + 0xc);
  iVar6 = *(int *)(in_r0 + 0x10);
  iVar7 = *(int *)(in_r0 + 0x18);
  *(int *)(in_r0 + 0x38) = iVar6;
  *(int *)(in_r0 + 0x3c) = iVar7;
  iVar2 = (*(code *)PTR_FUN_0602d91c)();
  iVar5 = (*DAT_0602d920)(iVar5);
  uVar4 = (int)((ulonglong)((longlong)extraout_r3 * (longlong)iVar5) >> 0x20) << 0x10 |
          (uint)((longlong)extraout_r3 * (longlong)iVar5) >> 0x10;
  *(uint *)(DAT_0602d918 + unaff_r14) = uVar4;
  *(uint *)(unaff_r14 + 0x10) = iVar6 + uVar4;
  lVar1 = (longlong)iVar3 * (longlong)iVar2;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(DAT_0602d91a + unaff_r14) = uVar4;
  *(uint *)(unaff_r14 + 0x18) = iVar7 + uVar4;
  return;
}


