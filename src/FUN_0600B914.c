extern int DAT_0600bab0;

extern int DAT_0600bab2;

extern int DAT_0600bab4;

extern int DAT_0600bab6;

extern int DAT_0600bab8;

extern int DAT_0600baba;

extern int PTR_DAT_0600babc;

extern int PTR_DAT_0600babc;

extern int PTR_DAT_0600bb8c;

extern int PTR_DAT_0600bb8c;

extern void FUN_0600ac44();

unsigned int FUN_0600b914()
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

  short *puVar10;

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

  puVar4 = 0x06031DF4;

  puVar3 = 0x06032158;

  puVar2 = 0x06089E44;

  puVar1 = 0x0608A52C;

  uVar5 = *(unsigned int *)0x0607EAE0;

  if (uVar5 == 0) {

    puVar14 = (int *)(0x060621D8 + 0x28);

    puVar9 = (int *)(0x0606212C + 0x28);

    puVar15 = (int *)(0x06062180 + 0x28);

    puVar10 = (short *)(0x06089E44 + 4);

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

    for (uVar24 = (unsigned int)*(short *)0x06078664; uVar24 < *(unsigned int *)0x0607EA98;

        uVar24 = uVar24 + 1) {

      puVar25 = (unsigned int *)(0x06078900 + uVar24 * (int)DAT_0600bab0);

      if ((*puVar25 & (unsigned int)0x00E00000) != 0) {

        (*0x06027080)();

        (*0x060270F2)

                  (puVar25[4],puVar25[5] + *(int *)((int)puVar25 + (int)DAT_0600bab2),puVar25[6]);

        (*0x060271A2)(0x00008000 + puVar25[8]);

        (*0x060271EE)(-puVar25[9]);

        (*0x06027158)(-puVar25[7]);

        if (*(int *)((int)puVar25 + (int)DAT_0600bab4) + *(int *)((int)puVar25 + (int)DAT_0600bab6)

            != 0) {

          (*0x060271A2)

                    (-*(int *)((int)puVar25 + DAT_0600bab8 + -0xc) -

                     *(int *)((int)puVar25 + (int)DAT_0600bab8));

          (*0x060271EE)(-*(int *)((int)puVar25 + (int)DAT_0600baba));

          (*0x06027158)(-*(int *)((int)puVar25 + (int)PTR_DAT_0600babc));

        }

        uVar23 = (unsigned int)(unsigned char)0x06047FC4[uVar24];

        if (((*puVar25 & 0x400000) == 0) &&

           (*(int *)0x06063E1C + *(int *)0x06063E20 != 8)) {

          if ((*puVar25 & 0x200000) == 0) {

            uVar5 = (unsigned int)*(char *)((int)puVar25 + 1);

            if ((uVar5 & 0x80) != 0) {

              if (*(int *)((int)puVar25 + (int)PTR_DAT_0600bb8c) < 1) {

                (*puVar3)(*puVar9,*puVar14);

                (*puVar4)(*puVar16,*puVar10,*puVar15);

              }

              FUN_0600ac44(puVar25,1);

              (*puVar3)(*puVar21,*puVar20);

              uVar5 = (*puVar4)(*puVar22,*(short *)(puVar2 + uVar23 * 2),*puVar19);

            }

          }

          else {

            (*puVar3)(*puVar18,*puVar7);

            uVar5 = (*puVar4)(*puVar8,*(short *)(puVar2 + uVar23 * 2),*puVar13);

          }

        }

        else {

          if (*(int *)((int)puVar25 + (int)DAT_0600bab4) < 1) {

            (*puVar3)(*puVar9,*puVar14);

            (*puVar4)(*puVar16,*puVar10,*puVar15);

          }

          (*puVar3)(*puVar6,*puVar11);

          uVar5 = (*puVar4)(*puVar12,*(short *)(puVar2 + uVar23 * 2),*puVar17);

        }

        *(int *)puVar1 = *(int *)puVar1 + -0x30;

      }

    }

  }

  return uVar5;

}
