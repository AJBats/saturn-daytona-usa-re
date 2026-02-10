extern char flag_0607864B;
extern int DAT_060082aa;
extern int DAT_060082ac;
extern int DAT_060082ae;
extern int DAT_060082b0;
extern int DAT_060082b2;
extern int DAT_06008358;
extern int DAT_0600835a;
extern int DAT_060083fa;
extern int DAT_060083fc;
extern int DAT_060083fe;
extern int DAT_06008400;
extern int DAT_06008402;
extern int DAT_060084a2;
extern int DAT_060084a4;
extern int DAT_060084a6;
extern int DAT_0600855e;
extern int DAT_06008624;
extern int DAT_06008626;
extern int DAT_06008628;
extern int DAT_0600862a;
extern int DAT_06008718;
extern int DAT_0600871a;
extern int DAT_0600871c;
extern int DAT_0600871e;
extern int DAT_060087e8;
extern int DAT_060087ea;
extern int DAT_060087ec;
extern int DAT_060087ee;
extern int DAT_060087f0;
extern int DAT_060087f2;
extern int DAT_060087f4;
extern int DAT_060087f6;
extern int DAT_060088aa;
extern int DAT_060088ac;
extern int DAT_060088ae;
extern int DAT_060088b0;
extern int DAT_060088b2;
extern int DAT_060088b4;
extern int DAT_060088b6;
extern void FUN_060084ca();
extern void FUN_060086c0();
extern int FUN_06008730();
extern int PTR_DAT_06008360;
extern int PTR_DAT_06008560;
extern int counter_0607EBCC;
extern int func_0601389E();
extern int func_06018E70();
extern int state_0605AD10;

void FUN_060081f4()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  int iVar5;

  puVar2 = (char *)0x00020000;

  puVar4 = (char *)0x0607EBC4;

  puVar1 = (char *)0x0607E944;

  if (*(int *)(*(int *)0x0607E944 + 0xb8) == 0) {

    if ((0x13 < *(int *)(*(int *)0x0607E944 + 8)) &&

       (*(int *)(*(int *)0x0607E944 + (int)DAT_060082b2) == 0)) {

      if ((**(unsigned char **)0x0607E944 & 0x10) == 0) {

        if ((**(unsigned char **)0x0607E944 & 0x20) != 0) {

          *(int *)(*(int *)0x0607E944 + 0xb8) = 0x30;

          *(int *)(*(int *)puVar1 + (int)DAT_0600835a) = 1;

          if (((unsigned int)puVar2 & *(unsigned int *)puVar4) != 0) {

            (*(int(*)())0x0601D5F4)(0,0xAE111BFF);

          }

        }

      }

      else {

        *(int *)(*(int *)0x0607E944 + 0xb8) = 0x30;

        *(int *)(*(int *)puVar1 + (int)DAT_060082ac) = 0xffffffff;

        if (((unsigned int)puVar2 & *(unsigned int *)puVar4) != 0) {

          (*(int(*)())0x0601D5F4)(0,0xAE111BFF);

        }

      }

    }

  }

  else {

    *(int *)0x0607EBD4 = 0x46;

    iVar3 = 0xb8;

    iVar5 = *(int *)(*(int *)puVar1 + iVar3);

    *(int *)(*(int *)puVar1 + iVar3) = *(int *)(*(int *)puVar1 + iVar3) + -1;

    puVar4 = (char *)0x0604546C;

    if ((**(unsigned char **)puVar1 & 0x40) != 0) {

      puVar4 = (char *)0x0604540C;

    }

    if (*(int *)(*(int *)puVar1 + (int)DAT_060082ac) < 0) {

      iVar3 = (int)*(short *)(puVar4 + ((0x30 - iVar5) << 1));

    }

    else {

      iVar3 = -(int)*(short *)(puVar4 + ((0x30 - iVar5) << 1));

    }

    *(int *)(*(int *)puVar1 + 0x1d8) = iVar3;

    *(int *)(*(int *)puVar1 + 0xc) = *(int *)(*(int *)puVar1 + 0xc) - 0xe3;

  }

  (*(int(*)())0x06034F78)(0);

  (*(int(*)())0x06034F78)();

  return;

}

int FUN_06008318()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  puVar2 = (char *)0x0607EBE0;

  puVar1 = (char *)0x0607E940;

  if (*(int *)(*(int *)0x0607E940 + 0xb8) == 0) {

    if ((0x258 < *(int *)0x0607EBD0) &&

       (*(int *)(*(int *)0x0607E940 + (int)DAT_060083fc) == 0)) {

      if ((**(unsigned char **)0x0607E940 & 0x10) == 0) {

        if ((**(unsigned char **)0x0607E940 & 0x20) != 0) {

          *(int *)(*(int *)0x0607E940 + 0xb8) = 0x20;

          *(int *)(*(int *)puVar1 + (int)DAT_06008400) = 1;

          *(int *)puVar2 = *(int *)puVar1;

          *(short *)(*(int *)puVar1 + (int)DAT_06008402) = 0x28;

        }

      }

      else {

        *(int *)(*(int *)0x0607E940 + 0xb8) = 0x20;

        *(int *)(*(int *)puVar1 + (int)DAT_06008400) = 0xffffffff;

        *(int *)puVar2 = *(int *)puVar1;

        *(short *)(*(int *)puVar1 + (int)DAT_06008402) = 0x28;

      }

    }

  }

  else {

    iVar3 = 0xb8;

    *(int *)(*(int *)0x0607E940 + iVar3) = *(int *)(*(int *)0x0607E940 + iVar3) + -1;

    if (*(int *)(*(int *)puVar1 + (int)DAT_0600835a) < 1) {

      iVar3 = -(int)*(short *)(0x060453CC + *(int *)(*(int *)puVar1 + iVar3) << 1);

    }

    else {

      iVar3 = (int)*(short *)(0x060453CC + *(int *)(*(int *)puVar1 + iVar3) << 1);

    }

    *(int *)(*(int *)puVar1 + 0x1d8) = iVar3;

  }

  (*(int(*)())0x06034F78)(puVar1,0);

  uVar4 = (*(int(*)())0x06034F78)();

  return uVar4;

}

void FUN_06008418()
{

  char *puVar1;

  unsigned char *pbVar2;

  puVar1 = (char *)0x0607E944;

  if (*(int *)(*(int *)0x0607E944 + (int)DAT_060084a2) == 0) {

    if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00020000) != 0) {

      (*(int(*)())0x0601D5F4)(0,0xAE1102FF);

    }

    pbVar2 = (unsigned char *)(*(int *)puVar1 + 1);

    *pbVar2 = *pbVar2 & 0xfe | 1;

    *(int *)(*(int *)puVar1 + (int)DAT_060084a6) = (int)DAT_060084a4;

    FUN_060084ca(*(int *)0x060453B4);

    return;

  }

  return;

}

void FUN_06008460()
{

  char *puVar1;

  unsigned char *pbVar2;

  puVar1 = (char *)0x0607E944;

  if (*(int *)(*(int *)0x0607E944 + (int)DAT_060084a2) == 0) {

    if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00020000) != 0) {

      (*(int(*)())0x0601D5F4)(0,0xAE1102FF);

    }

    pbVar2 = (unsigned char *)(*(int *)puVar1 + 1);

    *pbVar2 = *pbVar2 & 0xfe | 1;

    *(int *)(*(int *)puVar1 + (int)DAT_060084a6) = (int)DAT_060084a4;

    FUN_060084ca(*(int *)0x060453BC);

    return;

  }

  return;

}

void FUN_060084ca()
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x0607E944;

  iVar2 = (int)DAT_0600855e;

  *(int *)(*(int *)0x0607E944 + iVar2) = *(int *)(*(int *)0x0607E944 + iVar2) + 1;

  *(int *)(*(int *)puVar1 + iVar2 + -0x10) = 0;

  FUN_060086c0();

  if (((*(char **)puVar1 == 0x06078900) &&

      ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00020000) != 0)) &&

     ((*(int *)0x06078635 != '\0' || (*(short *)0x0607ED8C == 0)))) {

    *(short *)0x0605A016 = 3;

    *(int *)0x06078654 = 7;

    *(int *)0x06063E1C = 2;

    *(int *)0x06059F30 = 1;

    (*(int(*)())0x06038BD4)(8,0);

    *(char **)0x06063E24 = 0x00058000;

    *(char **)0x06063E34 = 0x0000F300;

    *(char **)0x06063E28 = 0x006E0000;

    *(char **)0x06063E2C = 0x00100000;

    *(int *)0x06063E30 = 0;

    *(int *)0x0607866C = (char)*(int *)(*(int *)puVar1 + (int)PTR_DAT_06008560);

  }

  return;

}

int FUN_060085b8()
{

  char *puVar1;

  int iVar2;

  puVar1 = (char *)0x0607E940;

  iVar2 = 0;

  if (*(int *)(*(int *)0x0607E940 + (int)DAT_06008624) != 0) {

    *(int *)0x0607EBD4 = 0x46;

    if ((*(int *)((int)DAT_06008626 + *(int *)puVar1) == 1) &&

       (((int)*(char *)(*(int *)puVar1 + 0x160) & 0x80U) != 0)) {

      *(int *)(*(int *)puVar1 + 0x28) = *(int *)(*(int *)puVar1 + 0x30);

      *(int *)(*(int *)puVar1 + DAT_0600862a + -8) =

           *(int *)(*(int *)puVar1 + (int)DAT_0600862a);

    }

    FUN_06008730();

    iVar2 = (int)DAT_06008624;

    if (*(int *)(*(int *)puVar1 + iVar2) < 2) {

      if (*(char **)0x0607EBC4 == 0x00200000) {

        *(int *)0x06078654 = 4;

      }

      else {

        *(int *)0x06078654 = 1;

      }

    }

  }

  return iVar2;

}

int FUN_06008640()
{
  char *puVar1;

  puVar1 = (char *)0x0607E940;

  if ((**(unsigned char **)0x0607E940 & 8) == 0) {
    if (*(int *)(*(int *)0x0607E940 + 0x01BC) != 0) {
      return FUN_06008730();
    }
    return 0;
  }

  **(unsigned char **)0x0607E940 = **(unsigned char **)0x0607E940 & 0xf7;

  if (*(int *)(*(int *)puVar1 + 0x01BC) != 0) {
    return FUN_06008730();
  }

  *(short *)(*(int *)puVar1 + 0x00D4) = 0x14;

  if ((*(unsigned int *)0x0607EBC4 & 0x00800000) != 0) {
    FUN_060086c0(*(int *)0x060453C4);
    return 0;
  }

  FUN_060086c0(*(int *)(0x060453B4 + ((*(unsigned int *)0x0607EBD0 & 1) << 3)));
  return 0;
}

void FUN_060086c0(param_1)
    int *param_1;
{

  int iVar1;

  int *piVar2;

  char cVar3;

  cVar3 = '\x01';

  piVar2 = (int *)0x0607E940;

  (*(int(*)())0x06034F78)();

  (*(int(*)())0x06034F78)();

  *(int *)(*piVar2 + 0x1b8) = *param_1;

  iVar1 = param_1[1];

  *(int *)(*piVar2 + (int)DAT_0600871a) = iVar1;

  iVar1 = iVar1 + -0x28;

  *(int *)(*piVar2 + (int)DAT_0600871c) = iVar1;

  *(int *)(*piVar2 + 0x208) = iVar1;

  *(int *)0x0607EBEC = *(int *)0x0607EBEC + cVar3;

  FUN_06008730();

  return;

}

int FUN_06008730()
{

  short sVar1;

  char *puVar2;

  int iVar3;

  int *puVar4;

  puVar2 = (char *)0x0607E940;

  if (0 < *(int *)(*(int *)0x0607E940 + (int)DAT_060087e8)) {

    *(int *)(*(int *)0x0607E940 + (int)DAT_060087e8) =

         *(int *)(*(int *)0x0607E940 + (int)DAT_060087e8) + -1;

  }

  if (0 < *(int *)(*(int *)puVar2 + (int)DAT_060087ea)) {

    *(int *)(*(int *)puVar2 + (int)DAT_060087ea) = *(int *)(*(int *)puVar2 + (int)DAT_060087ea) + -1

    ;

  }

  if (*(int *)((int)DAT_060087ea + *(int *)puVar2) == 10) {

    *(short *)(*(int *)puVar2 + (int)DAT_060087ec) = 10;

  }

  iVar3 = 0x1b8;

  puVar4 = *(int **)(*(int *)puVar2 + iVar3);

  *(int **)(*(int *)puVar2 + iVar3) = puVar4 + 3;

  *(int *)(*(int *)puVar2 + iVar3 + -4) = *puVar4;

  sVar1 = *(short *)(puVar4 + 1);

  if ((*(unsigned char *)(*(int *)puVar2 + 0x1c0) & 0x40) == 0) {

    if (((int)*(char *)(*(int *)puVar2 + 0x1c0) & 0x80U) == 0) {

      *(int *)(*(int *)puVar2 + 0x1c8) = (int)*(short *)((int)puVar4 + 6);

      *(int *)(*(int *)puVar2 + (int)DAT_060088ac) = (int)*(short *)(puVar4 + 2);

      *(int *)(*(int *)puVar2 + 0x1d0) = (int)*(short *)((int)puVar4 + 10);

    }

    else {

      *(int *)(*(int *)puVar2 + 0x1c8) = -(int)*(short *)((int)puVar4 + 6);

      *(int *)(*(int *)puVar2 + (int)DAT_060087f4) = -(int)*(short *)(puVar4 + 2);

      *(int *)(*(int *)puVar2 + 0x1d0) = (int)*(short *)((int)puVar4 + 10);

    }

  }

  else {

    *(int *)(*(int *)puVar2 + 0x1c8) = (int)*(short *)((int)puVar4 + 6);

    *(int *)(*(int *)puVar2 + (int)DAT_060087f4) = -(int)*(short *)(puVar4 + 2);

    *(int *)(*(int *)puVar2 + 0x1d0) = -(int)*(short *)((int)puVar4 + 10);

  }

  if (*(unsigned int *)(*(int *)puVar2 + 4) == (unsigned int)(unsigned char)*(int *)0x0607EBBC) {

    *(int *)(*(int *)puVar2 + (int)DAT_060088b0) = *(int *)(*(int *)puVar2 + (int)DAT_060088b0) + 1;

    if (DAT_060088b2 < sVar1) {

      *(int *)(*(int *)puVar2 + (int)DAT_060088b0) = 0;

    }

    if ((*(int *)(*(int *)puVar2 + (int)DAT_060088b4) == 0) &&

       ((*(int *)0x0607866C = 0, *(int *)0x06078635 != '\0' || (*(short *)0x0607ED8C == 0)))) {

      *(short *)0x0605A016 = 4;

    }

  }

  iVar3 = *(int *)(*(int *)puVar2 + (int)DAT_060088b4);

  if (iVar3 == 0) {

    iVar3 = (int)DAT_060088b6;

    *(int *)(*(int *)puVar2 + iVar3) = 0;

    *(int *)(*(int *)puVar2 + iVar3 + 0x14) = 0;

    *(int *)(*(int *)puVar2 + iVar3 + 0x18) = 0;

    iVar3 = iVar3 + 0x1c;

    *(int *)(*(int *)puVar2 + iVar3) = 0;

  }

  return iVar3;

}

void FUN_06009e02()
{
    counter_0607EBCC = counter_0607EBCC - 1;
    if (counter_0607EBCC == 0) {
        state_0605AD10 = 30;
    }
    func_0601389E();
    if (state_0605AD10 != 27) {
        func_06018E70();
    }
    flag_0607864B = 1;
}

void FUN_06009ffc()
{

  char *puVar1;

  puVar1 = (char *)0x0601D5F4;

  (*(int(*)())0x0601D5F4)(1,0);

  (*(int(*)())puVar1)(3,0);

  (*(int(*)())puVar1)(2,0);

  (*(int(*)())puVar1)(0,0xAE0001FF);

  (*(int(*)())puVar1)(0,0xAE0600FF);

  return;

}
