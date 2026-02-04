extern int DAT_0600b838;

extern int DAT_0600b83a;

extern int DAT_0600b83c;

extern int DAT_0600b83e;

extern int DAT_0600b840;

extern int DAT_0600b842;

extern int DAT_0600b90e;

extern int PTR_DAT_0600b844;

extern int PTR_DAT_0600b844;

extern int FUN_0600aa98();

unsigned int FUN_0600b6a0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int *puVar6;

  int *puVar7;

  int *puVar8;

  int *puVar9;

  short *psVar10;

  int *puVar11;

  int *puVar12;

  int *puVar13;

  int *puVar14;

  int *puVar15;

  int *puVar16;

  int *puVar17;

  int *puVar18;

  int *puVar19;

  int *puVar20;

  int *puVar21;

  int *puVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int *puVar25;

  puVar4 = 0x06031A28;

  puVar3 = 0x06031D8C;

  puVar2 = 0x06089E44;

  puVar1 = 0x06089EDC;

  uVar5 = *(unsigned int *)0x0607EAE0;

  if (uVar5 == 0) {

    puVar14 = (int *)(0x060621D8 + 0x28);

    puVar9 = (int *)(0x0606212C + 0x28);

    puVar15 = (int *)(0x06062180 + 0x28);

    psVar10 = (short *)(0x06089E44 + 4);

    puVar16 = (int *)(0x060620D8 + 0x28);

    puVar11 = (int *)(0x060621D8 + 0x2c);

    puVar6 = (int *)(0x0606212C + 0x2c);

    puVar17 = (int *)(0x06062180 + 0x2c);

    puVar12 = (int *)(0x060620D8 + 0x2c);

    puVar7 = (int *)(0x060621D8 + 0x30);

    puVar18 = (int *)(0x0606212C + 0x30);

    puVar13 = (int *)(0x06062180 + 0x30);

    puVar8 = (int *)(0x060620D8 + 0x30);

    uVar5 = 0x40;

    puVar20 = (int *)(0x060621D8 + 0x18);

    puVar21 = (int *)(0x0606212C + 0x18);

    puVar19 = (int *)(0x06062180 + 0x18);

    puVar22 = (int *)(0x060620D8 + 0x18);

    for (uVar24 = 1; uVar24 < (unsigned int)(int)*(short *)0x06078664; uVar24 = uVar24 + 1) {

      puVar25 = (unsigned int *)(0x06078900 + uVar24 * (int)DAT_0600b838);

      if ((*puVar25 & (unsigned int)0x00E00000) != 0) {

        (*(void(*)())0x06026DBC)();

        (*(void(*)())0x06026E2E)(puVar25[4],puVar25[5] + *(int *)((int)puVar25 + (int)DAT_0600b83a),puVar25[6]);

        (*(void(*)())0x06026EDE)(0x00008000 + puVar25[8]);

        (*(void(*)())0x06026F2A)(-puVar25[9]);

        (*(void(*)())0x06026E94)(-puVar25[7]);

        if (*(int *)((int)puVar25 + (int)DAT_0600b83c) + *(int *)((int)puVar25 + (int)DAT_0600b83e)

            != 0) {

          (*(void(*)())0x06026EDE)(-*(int *)((int)puVar25 + DAT_0600b840 + -0xc) -

                     *(int *)((int)puVar25 + (int)DAT_0600b840));

          (*(void(*)())0x06026F2A)(-*(int *)((int)puVar25 + (int)DAT_0600b842));

          (*(void(*)())0x06026E94)(-*(int *)((int)puVar25 + (int)PTR_DAT_0600b844));

        }

        uVar23 = (unsigned int)(unsigned char)0x06047FC4[uVar24];

        if (((*puVar25 & 0x400000) == 0) &&

           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {

          if ((*puVar25 & 0x200000) == 0) {

            uVar5 = (unsigned int)*(char *)((int)puVar25 + 1);

            if ((uVar5 & 0x80) != 0) {

              if (*(int *)((int)puVar25 + (int)DAT_0600b90e) < 1) {

                (*(void(*)())puVar3)(*puVar9,*puVar14);

                (*(void(*)())puVar4)(*puVar16,(int)*psVar10,*puVar15);

              }

              FUN_0600aa98(puVar25,1);

              (*(void(*)())puVar3)(*puVar21,*puVar20);

              uVar5 = (*(void(*)())puVar4)(*puVar22,(int)*(short *)(puVar2 + uVar23 * 2),*puVar19);

            }

          }

          else {

            (*(void(*)())puVar3)(*puVar18,*puVar7);

            uVar5 = (*(void(*)())puVar4)(*puVar8,(int)*(short *)(puVar2 + uVar23 * 2),*puVar13);

          }

        }

        else {

          if (*(int *)((int)puVar25 + (int)DAT_0600b83c) < 1) {

            (*(void(*)())puVar3)(*puVar9,*puVar14);

            (*(void(*)())puVar4)(*puVar16,(int)*psVar10,*puVar15);

          }

          (*(void(*)())puVar3)(*puVar6,*puVar11);

          uVar5 = (*(void(*)())puVar4)(*puVar12,(int)*(short *)(puVar2 + uVar23 * 2),*puVar17);

        }

        *(int *)puVar1 = *(int *)puVar1 + -0x30;

      }

    }

  }

  return uVar5;

}
