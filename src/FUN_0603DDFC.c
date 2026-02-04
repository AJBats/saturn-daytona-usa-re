extern int DAT_0603e0b2;

extern int DAT_0603e3b6;

extern int DAT_0603e3b8;

extern int DAT_0603e3ba;

extern int DAT_0603e3bc;

extern int DAT_0603e61e;

extern int DAT_0603e93a;

extern int DAT_0603e93c;

extern int DAT_0603e93e;

extern int DAT_0603ea46;

extern int PTR_DAT_0603e53c;

extern int PTR_DAT_0603e53c;

extern int PTR_DAT_0603e620;

extern int PTR_DAT_0603e620;

extern int FUN_0603d9ec();
extern int FUN_0603da88();
extern int FUN_0603eacc();
extern int FUN_0603ec40();

short * FUN_0603ddfc(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  char *puVar11;

  short *psVar12;

  unsigned short uVar15;

  int iVar13;

  int uVar14;

  int iVar16;

  char *puVar17;

  int *puVar18;

  int iVar19;

  int iVar20;

  unsigned int uVar21;

  int *piVar22;

  unsigned int uVar23;

  char cVar24;

  unsigned short uVar25;

  int ***pppiVar26;

  int iVar27;

  int iVar28;

  char *local_9c;

  int local_98;

  char *local_90 [2];

  char auStack_88 [8];

  short *local_80;

  int **local_7c;

  unsigned int **local_78;

  char *local_74;

  unsigned int *local_70;

  int *local_6c;

  int *piStack_68;

  unsigned int *local_64;

  int *local_60;

  int *local_5c;

  int *local_58;

  int *piStack_54;

  int iStack_50;

  int iStack_4c;

  int *piStack_48;

  int *piStack_44;

  int *piStack_40;

  int *piStack_3c;

  int *piStack_38;

  int *piStack_34;

  int *piStack_30;

  int *piStack_2c;

  int iStack_28;

  puVar7 = 0x00010000;

  puVar17 = 0x060A4C60;

  puVar6 = 0x060A4C68;

  puVar5 = 0x060A53B8;

  psVar12 = *(short **)0x060635A8;

  if (psVar12 == (short *)(void *)0x00000001) {

    uVar25 = 0;

  }

  else {

    if (psVar12 != (short *)(void *)0x00000002) {

      return psVar12;

    }

    uVar25 = 1;

  }

  cVar24 = (char)uVar25;

  puVar18 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

  *puVar18 = 0x00010000;

  puVar18[1] = 0;

  puVar18[2] = 0;

  puVar18[3] = 0;

  puVar18[4] = puVar7;

  puVar18[5] = 0;

  puVar18[6] = 0;

  puVar18[7] = 0;

  puVar18[8] = puVar7;

  if (*(int *)(0x060A4C44 + (unsigned int)(uVar25 << 2)) == 0) {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = 0;

  }

  else {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) + param_1;

  }

  *(int *)(puVar6 + (unsigned int)(uVar25 << 2)) = *(int *)(puVar6 + (unsigned int)(uVar25 << 2)) + param_2;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) && (param_1 != 0)) {

    if (*(int *)0x060635A8 == 1) {

      uVar15 = *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00;

    }

    else {

      if (*(int *)0x060635A8 != 2) goto LAB_0603dedc;

      uVar15 = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

    }

    *(unsigned short *)(0x060A3E38 + 4) = uVar15;

  }

LAB_0603dedc:

  if (param_3 != 0) {

    FUN_0603ec40(param_3);

  }

  if ((*(int *)(0x060A4C4C + (unsigned int)(uVar25 << 2)) != 0) &&

     (*(int *)(0x060A4C70 + (unsigned int)(uVar25 << 2)) != 0)) {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = 0;

  }

  puVar7 = 0x060A3E68;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) &&

     (*(int *)(0x060A4C78 + (unsigned int)(uVar25 << 2)) == 0)) {

    if (((uVar25 == 0) && ((*(unsigned short *)0x060A3E3C & 0xff) != 0)) ||

       ((uVar25 == 1 && (((unsigned int)*(unsigned short *)0x060A3E3C & (unsigned int)0x0000FF00) != 0)))) {

      puVar18 = (int *)(puVar5 + (char)(cVar24 * '$'));

      *puVar18 = *(int *)(0x060A3E68 + (unsigned int)(uVar25 << 7) + 0x4c);

      puVar18[4] = *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

      *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x1c) =

           *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x4c);

      *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x2c) =

           *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

    }

  }

  else {

    puVar18 = (int *)(puVar5 + (char)(cVar24 * '$'));

    *puVar18 = *(int *)(0x060A3E68 + (unsigned int)(uVar25 << 7) + 0x4c);

    puVar18[4] = *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

  }

  if (*(int *)(puVar6 + (unsigned int)(uVar25 << 2)) != 0) {

    FUN_0603eacc(*(int *)(puVar6 + (unsigned int)(uVar25 << 2)));

  }

  puVar11 = 0x060A3E38;

  puVar10 = 0x0603C0A0;

  puVar9 = 0x00040000;

  sVar1 = DAT_0603e61e;

  puVar8 = 0x060A3E38;

  puVar7 = 0x0603C0A0;

  puVar6 = 0x00008000;

  puVar5 = 0x00040000;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) &&

     (*(int *)(0x060A4C78 + (unsigned int)(uVar25 << 2)) == 0)) {

    return (short *)0x0;

  }

  if ((*(short *)(0x060A4C54 + (unsigned int)(uVar25 << 1)) != 0) &&

     (*(int *)(0x060A4C4C + (unsigned int)(uVar25 << 2)) == 0)) {

    iStack_50 = *(int *)(puVar17 + (unsigned int)(uVar25 << 2));

    uVar21 = (unsigned int)DAT_0603e61e;

    sVar2 = DAT_0603e61e + 1;

    psVar12 = *(short **)0x060635A8;

    if (psVar12 == (short *)(void *)0x00000001) {

      uVar15 = 0;

      *(unsigned short *)(0x060A3E38 + 4) =

           *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00;

      uVar25 = *(unsigned short *)(puVar11 + 4) | 3;

    }

    else {

      if (psVar12 != (short *)(void *)0x00000002) {

        return psVar12;

      }

      uVar15 = 1;

      *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

      uVar25 = *(unsigned short *)(puVar11 + 4) | PTR_DAT_0603e620;

    }

    *(unsigned short *)(puVar11 + 4) = uVar25;

    local_58 = (int *)FUN_0603d9ec(iStack_50);

    iStack_50 = FUN_0603da88(iStack_50);

    puVar5 = 0x0603C08C;

    cVar24 = (char)uVar15;

    piVar22 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

    piStack_30 = (int *)*piVar22;

    piStack_40 = piVar22 + 2;

    piStack_48 = (int *)*piStack_40;

    piStack_38 = piVar22 + 3;

    iStack_4c = *piStack_38;

    piStack_3c = piVar22 + 5;

    piStack_2c = (int *)*piStack_3c;

    piStack_44 = piVar22 + 6;

    iStack_28 = *piStack_44;

    piStack_54 = piVar22 + 8;

    piStack_34 = (int *)*piStack_54;

    local_5c = (int *)(*(int(*)())0x0603C08C)(piStack_30,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_48,local_58);

    *piVar22 = (int)local_5c - iVar13;

    local_5c = piStack_40;

    local_60 = (int *)(*(int(*)())puVar5)(piStack_30,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_48,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    local_5c = piStack_38;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_4c,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_2c,local_58);

    *local_5c = (int)local_60 - iVar13;

    local_5c = piStack_3c;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_4c,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_2c,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    local_5c = piStack_44;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_28,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_34,local_58);

    *local_5c = (int)local_60 - iVar13;

    local_5c = piStack_54;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_28,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_34,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    puVar5 = 0x060A3E68;

    *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *piVar22;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x24) = *piStack_40;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x28) = *piStack_38;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x2c) = piVar22[4];

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x30) = *piStack_3c;

    sVar3 = *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x34);

    sVar4 = *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x3c);

    iVar20 = *piStack_44;

    local_58 = (int *)piVar22[7];

    iStack_50 = (int)*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x36);

    iVar27 = (int)local_58 * (iStack_50 - *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x3e));

    iVar16 = *piStack_54;

    iVar19 = (int)*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x38);

    iStack_4c = ((*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x40)) << 16 | (iStack_4c) & 0xFFFF);

    iVar28 = iVar16 * (iVar19 - *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x40));

    local_6c = (int *)&local_6c;

    (*(int(*)())0x060358EC)();

    local_70 = (unsigned int *)0x0;

    local_74 = (char *)0x40F00000;

    local_78 = &local_64;

    (*(int(*)())0x060359E4)();

    iVar13 = (*(int(*)())0x060357B8)();

    puVar5 = 0x005A0000;

    iVar13 = iVar20 * ((int)sVar3 - (int)sVar4) + iVar27 + iVar28 + iVar13 +

             *(int *)(0x060A4C78 + (unsigned int)(uVar15 << 2));

    local_70 = (unsigned int *)(-(iVar19 * iVar16) - (int)local_70 * (int)local_78);

    if (*(int *)(0x060A4C70 + (unsigned int)(uVar15 << 2)) == 0) {

      puVar18 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      puVar18[0x15] = *puVar18;

      uVar14 = FUN_0603da88(puVar5);

      puVar5 = 0x005A0000;

      puVar18[0x16] = uVar14;

      uVar14 = FUN_0603d9ec(puVar5);

      puVar18[0x17] = uVar14;

      puVar5 = 0x060A4C38;

      *(unsigned int *)(0x060A4C38 + (unsigned int)(uVar15 << 2)) = *(unsigned short *)0x060635AE - 1;

      local_64 = (unsigned int *)(puVar5 + (unsigned int)(uVar15 << 2));

      piStack_68 = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x18);

      local_6c = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      local_74 = 0x060A3F68 + (short)(uVar15 * DAT_0603ea46);

      psVar12 = (short *)0x060A3F68;

      for (uVar23 = 0; uVar23 < *local_64; uVar23 = uVar23 + 1) {

        local_78 = (unsigned int **)(*piStack_68 * (uVar23 - (int)*(short *)(local_6c + 0xd)) +

                            (int)local_70);

        iVar16 = (*(int(*)())0x06034FFC)();

        if (iVar16 == 0) {

          psVar12 = (short *)(local_74 + (uVar23 << 1));

LAB_0603ea9c:

          *psVar12 = sVar1 + 1;

        }

        else {

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          local_7c = (int **)(unsigned int)((int)puVar9 < -iVar16);

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          if (-iVar16 < 0 || local_7c != (int **)0x0) {

            psVar12 = (short *)(local_74 + (uVar23 << 1));

            goto LAB_0603ea9c;

          }

          local_7c = (int **)(local_74 + (uVar23 << 1));

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & uVar21);

          *(short *)local_7c = (short)psVar12;

        }

      }

    }

    else {

      local_74 = (char *)((unsigned int)(uVar15 << 2));

      piVar22 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      piVar22[0x15] = (int)(0x012C0000 + *piVar22);

      local_78 = (unsigned int **)(0x060A4C70 + (int)local_74);

      iVar16 = FUN_0603da88(0x005A0000 + (int)*local_78);

      piVar22[0x16] = iVar16;

      iVar16 = FUN_0603d9ec(0x005A0000 + (int)*local_78);

      piVar22[0x17] = iVar16;

      puVar5 = 0x060A4C38;

      *(int *)(0x060A4C38 + (int)local_74) = (int)DAT_0603e93a;

      local_64 = (unsigned int *)(puVar5 + (unsigned int)(uVar15 << 2));

      piStack_68 = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x18);

      local_6c = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      local_74 = 0x060A3F68 + (short)(uVar15 * DAT_0603e93c);

      psVar12 = (short *)0x060A3F68;

      for (uVar23 = 0; uVar23 < *local_64; uVar23 = uVar23 + 1) {

        local_78 = (unsigned int **)(*piStack_68 *

                             ((uVar23 - (int)*(short *)(local_6c + 0xd)) + (int)DAT_0603e93e) +

                            (int)local_70);

        iVar16 = (*(int(*)())0x06034FFC)();

        if (iVar16 == 0) {

          psVar12 = (short *)(local_74 + (uVar23 << 1));

LAB_0603e964:

          *psVar12 = sVar2;

        }

        else {

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          local_7c = (int **)(unsigned int)((int)puVar9 < -iVar16);

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          if (-iVar16 < 0 || local_7c != (int **)0x0) {

            psVar12 = (short *)(local_74 + (uVar23 << 1));

            goto LAB_0603e964;

          }

          local_7c = (int **)(local_74 + (uVar23 << 1));

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & uVar21);

          *(short *)local_7c = (short)psVar12;

        }

      }

    }

    *(short *)(0x060A4C40 + (unsigned int)(uVar15 << 1)) = 1;

    return psVar12;

  }

  piStack_54 = *(int **)(puVar17 + (unsigned int)(uVar25 << 2));

  psVar12 = *(short **)0x060635A8;

  if (psVar12 == (short *)(void *)0x00000001) {

    uVar15 = 0;

    *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00

    ;

    uVar25 = *(unsigned short *)(puVar8 + 4) | 3;

  }

  else {

    if (psVar12 != (short *)(void *)0x00000002) {

      return psVar12;

    }

    uVar15 = 1;

    *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

    uVar25 = *(unsigned short *)(puVar8 + 4) | DAT_0603e0b2;

  }

  *(unsigned short *)(puVar8 + 4) = uVar25;

  local_5c = (int *)FUN_0603d9ec(piStack_54);

  piStack_54 = (int *)FUN_0603da88(piStack_54);

  puVar17 = 0x0603C08C;

  cVar24 = (char)uVar15;

  puVar18 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

  local_60 = puVar18 + 1;

  iStack_50 = *local_60;

  piStack_30 = puVar18 + 2;

  iStack_28 = *piStack_30;

  piStack_34 = puVar18 + 4;

  piStack_38 = (int *)*piStack_34;

  piStack_40 = puVar18 + 5;

  piStack_3c = (int *)*piStack_40;

  piStack_48 = puVar18 + 7;

  piStack_44 = (int *)*piStack_48;

  local_58 = puVar18 + 8;

  iStack_4c = *local_58;

  piStack_2c = local_60;

  local_64 = (unsigned int *)(*(int(*)())0x0603C08C)(iStack_50,piStack_54);

  iVar13 = (*(int(*)())puVar17)(iStack_28,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_30;

  iVar13 = (*(int(*)())puVar17)(iStack_50,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(iStack_28,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_34;

  local_64 = (unsigned int *)(*(int(*)())puVar17)(piStack_38,piStack_54);

  iVar13 = (*(int(*)())puVar17)(piStack_3c,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_40;

  iVar13 = (*(int(*)())puVar17)(piStack_38,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(piStack_3c,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_48;

  local_64 = (unsigned int *)(*(int(*)())puVar17)(piStack_44,piStack_54);

  iVar13 = (*(int(*)())puVar17)(iStack_4c,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = local_58;

  iVar13 = (*(int(*)())puVar17)(piStack_44,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(iStack_4c,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  puVar17 = 0x060A3E68;

  *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *puVar18;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x20) = *piStack_2c;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x24) = *piStack_30;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x2c) = *piStack_34;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x30) = *piStack_40;

  iVar20 = puVar18[6];

  iVar19 = (int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x34);

  iVar27 = iVar20 * (iVar19 - *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x3c));

  iVar16 = *piStack_48;

  sVar1 = *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x36);

  sVar2 = *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x3e);

  piStack_54 = (int *)*local_58;

  local_5c = (int *)(int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x38);

  iVar28 = (int)piStack_54 * ((int)local_5c - (int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x40))

  ;

  local_70 = (unsigned int *)&local_70;

  (*(int(*)())0x060358EC)();

  local_74 = (char *)0x0;

  local_78 = (unsigned int **)0x40F00000;

  local_7c = &piStack_68;

  pppiVar26 = &local_7c;

  (*(int(*)())0x060359E4)();

  iVar13 = (*(int(*)())0x060357B8)();

  puVar17 = 0x060A3E68;

  local_70 = (unsigned int *)((unsigned int)(uVar15 << 2));

  iVar13 = iVar27 + iVar16 * ((int)sVar1 - (int)sVar2) + iVar28 + iVar13 +

           *(int *)(0x060A4C78 + (int)local_70);

  local_74 = (char *)(-((int)local_7c * (int)local_74) - iVar19 * iVar20);

  if (*(int *)(0x060A4C70 + (int)local_70) == 0) {

    if ((*(int *)(0x060A4C4C + (unsigned int)(uVar15 << 2)) == -1) ||

       (*(int *)(0x060A4C4C + (unsigned int)(uVar15 << 2)) == 0)) {

      *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x54) =

           *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 4);

    }

    else {

      puVar17 = 0x060A3E68 + (unsigned int)(uVar15 << 7);

      local_90[0] = (char *)local_90;

      (*(int(*)())0x060358EC)();

      local_98 = 0x40F00000;

      local_9c = auStack_88;

      pppiVar26 = (int ***)&local_9c;

      (*(int(*)())0x060359E4)();

      iVar16 = (*(int(*)())0x060357B8)();

      *(int *)(puVar17 + 0x54) = iVar16 + *(int *)(puVar17 + 4);

    }

    *pppiVar26 = (int **)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    ((int *)pppiVar26)[-1] = (int)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x58);

    uVar14 = FUN_0603da88(0);

    *(int *)((int *)pppiVar26)[-1] = uVar14;

    ((int *)pppiVar26)[-1] = (int)*pppiVar26 + 0x5c;

    uVar14 = FUN_0603d9ec(0);

    *(int *)((int *)pppiVar26)[-1] = uVar14;

    puVar17 = 0x060A4C38;

    *(unsigned int *)(0x060A4C38 + (unsigned int)(uVar15 << 2)) = *(unsigned short *)0x060635B0 - 1;

    ((int *)pppiVar26)[4] = (int)(puVar17 + (unsigned int)(uVar15 << 2));

    ((int *)pppiVar26)[3] = (int)(0x060A53B8 + (char)(cVar24 * '$') + 0x1c);

    ((int *)pppiVar26)[5] = (int)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    ((int *)pppiVar26)[1] = (int)(0x060A3F68 + (short)(uVar15 * PTR_DAT_0603e53c));

    psVar12 = (short *)0x060A3F68;

    for (uVar21 = 0; uVar21 < *(unsigned int *)((int *)pppiVar26)[4]; uVar21 = uVar21 + 1) {

      *pppiVar26 = (int **)(*(int *)((int *)pppiVar26)[3] *

                            (uVar21 - (int)*(short *)(((int *)pppiVar26)[5] + 0x36)) +

                           ((int *)pppiVar26)[2]);

      iVar16 = (*(int(*)())0x06034FFC)();

      if (iVar16 == 0) {

        psVar12 = (short *)((uVar21 << 1) + ((int *)pppiVar26)[1]);

LAB_0603e58c:

        *psVar12 = (short)puVar6;

      }

      else {

        iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26);

        if (((int)puVar5 < -iVar16) || (iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26), -iVar16 < 0))

        {

          psVar12 = (short *)((uVar21 << 1) + ((int *)pppiVar26)[1]);

          goto LAB_0603e58c;

        }

        ((int *)pppiVar26)[-1] = (uVar21 << 1) + ((int *)pppiVar26)[1];

        iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26);

        psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & (int)DAT_0603e61e);

        *(short *)((int *)pppiVar26)[-1] = (short)psVar12;

      }

    }

  }

  else {

    *(char **)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x54) =

         0x012C0000 + *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 4);

    local_7c = (int **)((unsigned int)(uVar15 << 2));

    local_78 = (unsigned int **)(0x060A4C70 + (int)local_7c);

    uVar14 = FUN_0603da88(*local_78);

    *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x58) = uVar14;

    uVar14 = FUN_0603d9ec(*local_78);

    *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x5c) = uVar14;

    puVar17 = 0x060A4C38;

    *(int *)(0x060A4C38 + (int)local_7c) = (int)DAT_0603e3b6;

    local_70 = (unsigned int *)(puVar17 + (unsigned int)(uVar15 << 2));

    local_6c = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x1c);

    piStack_68 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    local_78 = (unsigned int **)(0x060A3F68 + (short)(uVar15 * DAT_0603e3b8));

    psVar12 = (short *)0x060A3F68;

    for (uVar21 = 0; uVar21 < *local_70; uVar21 = uVar21 + 1) {

      local_7c = (int **)(*local_6c *

                          ((uVar21 - (int)*(short *)((int)piStack_68 + 0x36)) + (int)DAT_0603e3ba) +

                         (int)local_74);

      iVar16 = (*(int(*)())0x06034FFC)();

      if (iVar16 == 0) {

        psVar12 = (short *)((int)local_78 + (uVar21 << 1));

LAB_0603e3dc:

        *psVar12 = (short)puVar6;

      }

      else {

        iVar16 = (*(int(*)())puVar7)(iVar13,local_7c);

        if (((int)puVar5 < -iVar16) || (iVar16 = (*(int(*)())puVar7)(iVar13,local_7c), -iVar16 < 0)) {

          psVar12 = (short *)((int)local_78 + (uVar21 << 1));

          goto LAB_0603e3dc;

        }

        local_80 = (short *)((int)local_78 + (uVar21 << 1));

        iVar16 = (*(int(*)())puVar7)(iVar13,local_7c);

        psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & (int)DAT_0603e3bc);

        *local_80 = (short)psVar12;

      }

    }

  }

  *(short *)(0x060A4C40 + (unsigned int)(uVar15 << 1)) = 1;

  return psVar12;

}
