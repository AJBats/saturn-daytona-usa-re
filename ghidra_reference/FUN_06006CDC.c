extern int DAT_06006da6;

extern int DAT_06006da8;

extern int DAT_06006daa;

extern int PTR_DAT_06006dac;

extern int PTR_DAT_06006dac;

int FUN_06006cdc()
{

  short sVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int uVar11;

  int iVar12;

  int iVar13;

  int uVar14;

  int iVar15;

  unsigned int uVar16;

  unsigned int uVar17;

  int iVar18;

  int iVar19;

  unsigned int uVar20;

  short sVar21;

  short sVar22;

  unsigned int uVar23;

  unsigned int uStack_5c;

  unsigned int uStack_58;

  unsigned int uStack_44;

  unsigned int uStack_2c;

  unsigned int uStack_28;

  puVar6 = 0x06089E96;

  puVar5 = 0x002F0000;

  puVar4 = 0x0607EAD8;

  puVar3 = 0x060620D4;

  sVar2 = DAT_06006da6;

  uVar23 = (unsigned int)DAT_06006da6;

  uVar16 = *(int *)0x06063EF0 + 0x800 & (unsigned int)0x0000FFFF;

  uVar14 = *(int *)(0x06062248 + *(int *)(0x0607EAD8 << 3));

  uVar11 = *(int *)(0x06062248 + (*(int *)(0x0607EAD8 << 1) + 1) << 2);

  iVar7 = 0xf2;

  iVar8 = (int)PTR_DAT_06006dac;

  iVar9 = *(int *)(0x06062260 + *(int *)(0x0607EAD8 << 4));

  iVar19 = *(int *)(0x0607EAD8 << 2);

  iVar15 = *(int *)(0x06062260 + (iVar19 + 1) << 2);

  iVar12 = *(int *)(0x06062260 + (iVar19 + 2) << 2);

  iVar19 = (iVar19 + 3) << 2;

  iVar10 = *(int *)(0x06062260 + iVar19);

  uVar17 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar20 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar13 = (uVar20 << 6) + uVar17;

  uStack_2c = 0;

  uStack_58 = 0;

  uStack_44 = 0xb;

  uStack_28 = 0xb;

  if (uVar20 < 0x3b) {

    if (uVar20 < 5) {

      uStack_58 = 5 - uVar20;

    }

  }

  else {

    uStack_28 = 0x45 - uVar20;

  }

  if (uVar17 < 0x3b) {

    if (uVar17 < 5) {

      uStack_2c = 5 - uVar17;

    }

  }

  else {

    uStack_44 = 0x45 - uVar17;

  }

  for (; uStack_58 < uStack_28; uStack_58 = uStack_58 + 1) {

    for (uStack_5c = uStack_2c; uStack_5c < uStack_44; uStack_5c = uStack_5c + 1) {

      iVar19 = (uStack_58 * 0xb + uStack_5c) << 1;

      sVar1 = *(short *)(puVar5 + iVar19 + iVar8 + (uVar16 >> 0xc) * iVar7);

      if (sVar1 != 0) {

        iVar18 = (sVar1 + iVar13) << 1;

        sVar22 = *(short *)(iVar9 + iVar18);

        sVar21 = *(short *)(iVar18 + iVar12);

        if (0 < sVar22) {

          iVar19 = *(int *)(iVar15 + (sVar1 + iVar13) << 2) +

                   *(int *)(0x06062230 + *(int *)((int)(int)puVar4 << 3));

          if (uVar23 <= (unsigned int)((int)sVar22 + *(int *)puVar3)) {

            sVar22 = sVar2 - (short)*(int *)puVar3;

          }

          if (*(int *)puVar4 == 2) {

            iVar19 = (*(int(*)())0x0602B9E0)(iVar19,uVar14,*(short *)puVar6,(int)sVar22);

          }

          else {

            iVar19 = (*(int(*)())0x0602ABB8)(iVar19,uVar14,*(short *)puVar6,(int)sVar22);

          }

        }

        if (0 < sVar21) {

          iVar19 = *(int *)(0x06062230 + (*(int *)((int)(int)puVar4 << 1) + 1) << 2) +

                   *(int *)(iVar10 + (sVar1 + iVar13) << 2);

          if (uVar23 <= (unsigned int)((int)sVar21 + *(int *)puVar3)) {

            sVar21 = sVar2 - (short)*(int *)puVar3;

          }

          if (*(int *)puVar4 == 2) {

            iVar19 = (*(int(*)())0x0602B9E0)(iVar19,uVar11,*(short *)puVar6,(int)sVar21);

          }

          else {

            iVar19 = (*(int(*)())0x0602ABB8)(iVar19,uVar11,*(short *)puVar6,(int)sVar21);

          }

        }

      }

    }

  }

  return iVar19;

}
