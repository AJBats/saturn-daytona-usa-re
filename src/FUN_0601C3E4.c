extern int DAT_0601c510;

extern int DAT_0601c5f8;

extern int DAT_0601c5fa;

extern int DAT_0601c6c0;

extern int DAT_0601c77c;

extern int DAT_0601c844;

extern int DAT_0601c93c;

extern int DAT_0601c93e;

extern int DAT_0601c940;

int FUN_0601c3e4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int uVar6;

  int iVar7;

  int iVar8;

  puVar5 = 0x0605DF56;

  puVar4 = 0x0605DF57;

  puVar3 = 0x0608A52C;

  puVar2 = 0x00008000;

  puVar1 = 0x0605DF44;

  iVar8 = *(int *)0x0607E944;

  if ((*(int *)0x06063E1C == 0) || (*(int *)0x06063E20 == 0)) {

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

    (*(void(*)())0x06034F78)();

    uVar6 = (*(void(*)())0x06034F78)();

  }

  else {

    if ((*(unsigned char *)(iVar8 + 3) & 0x40) != 0) {

      *(short *)0x0605DF4E = 8;

      (*(void(*)())0x06034F78)();

    }

    if (((int)*(char *)(iVar8 + 3) & 0x80U) != 0) {

      *(short *)0x0605DF50 = 8;

      (*(void(*)())0x06034F78)();

    }

    if ((*(unsigned char *)(iVar8 + 2) & 1) != 0) {

      *(short *)0x0605DF52 = 8;

      (*(void(*)())0x06034F78)();

    }

    if ((*(unsigned char *)(iVar8 + 2) & 2) != 0) {

      *(short *)0x0605DF54 = 8;

      (*(void(*)())0x06034F78)();

    }

    if (*(short *)0x0605DF4E == 0) {

      if (*(short *)0x0605DF50 == 0) {

        if (*(short *)0x0605DF52 == 0) {

          if (*(short *)0x0605DF54 != 0) {

            (*(void(*)())0x06027080)();

            (*(void(*)())0x060270F2)(0xFFFE9DF4,puVar2,0x00013333);

            (*(void(*)())0x060271A2)((int)DAT_0601c844);

            iVar7 = ((unsigned char)*puVar4 + 0x12) * 4;

            (*(void(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                       *(int *)(0x060621D8 + iVar7));

            iVar7 = ((unsigned char)*puVar4 + 0x12) * 4;

            (*(void(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                       *(int *)(0x06062180 + iVar7));

            *(int *)puVar3 = *(int *)puVar3 + -0x30;

            *puVar4 = *puVar4 + '\x01';

            if (2 < (unsigned char)*puVar4) {

              *puVar4 = 0;

            }

            *(short *)0x0605DF54 = *(short *)0x0605DF54 + -1;

          }

        }

        else {

          (*(void(*)())0x06027080)();

          (*(void(*)())0x060270F2)(0x0001620C,puVar2,0x00013333);

          (*(void(*)())0x060271A2)((int)DAT_0601c77c);

          iVar7 = ((unsigned char)*puVar5 + 0x12) * 4;

          (*(void(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                     *(int *)(0x060621D8 + iVar7));

          iVar7 = ((unsigned char)*puVar5 + 0x12) * 4;

          (*(void(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                     *(int *)(0x06062180 + iVar7));

          *(int *)puVar3 = *(int *)puVar3 + -0x30;

          *puVar5 = *puVar5 + '\x01';

          if (2 < (unsigned char)*puVar5) {

            *puVar5 = 0;

          }

          *(short *)0x0605DF52 = *(short *)0x0605DF52 + -1;

        }

      }

      else {

        (*(void(*)())0x06027080)();

        if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {

          (*(void(*)())0x060270F2)(0xFFFEB78E,puVar2,0xFFFE4000);

          (*(void(*)())0x06027124)((int)DAT_0601c5fa,(int)DAT_0601c5fa);

        }

        else {

          (*(void(*)())0x060270F2)(0xFFFEB78E,puVar2,0xFFFF0000);

        }

        (*(void(*)())0x060271A2)((int)DAT_0601c6c0);

        iVar7 = ((unsigned char)*puVar4 + 0x12) * 4;

        (*(void(*)())0x06032158)(*(int *)(0x0606212C + iVar7),

                   *(int *)(0x060621D8 + iVar7));

        iVar7 = ((unsigned char)*puVar4 + 0x12) * 4;

        (*(void(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                   *(int *)(0x06062180 + iVar7));

        *(int *)puVar3 = *(int *)puVar3 + -0x30;

        *puVar4 = *puVar4 + '\x01';

        if (2 < (unsigned char)*puVar4) {

          *puVar4 = 0;

        }

        *(short *)0x0605DF50 = *(short *)0x0605DF50 + -1;

      }

    }

    else {

      (*(void(*)())0x06027080)();

      if ((*(int *)0x06063E1C == 1) && (*(int *)0x06063E20 == 1)) {

        (*(void(*)())0x060270F2)(0x00014872,puVar2,0xFFFE4000);

        (*(void(*)())0x06027124)((int)DAT_0601c510,(int)DAT_0601c510);

      }

      else {

        (*(void(*)())0x060270F2)(0x00014872,puVar2,0xFFFF0000);

      }

      (*(void(*)())0x060271A2)((int)DAT_0601c5f8);

      iVar7 = ((unsigned char)*puVar5 + 0x12) * 4;

      (*(void(*)())0x06032158)(*(int *)(0x0606212C + iVar7),*(int *)(0x060621D8 + iVar7)

                );

      iVar7 = ((unsigned char)*puVar5 + 0x12) * 4;

      (*(void(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar7),*(short *)0x06089E9C,

                 *(int *)(0x06062180 + iVar7));

      *(int *)puVar3 = *(int *)puVar3 + -0x30;

      *puVar5 = *puVar5 + '\x01';

      if (2 < (unsigned char)*puVar5) {

        *puVar5 = 0;

      }

      *(short *)0x0605DF4E = *(short *)0x0605DF4E + -1;

    }

    if (*(int *)0x06059F30 == 0) {

      uVar6 = 0;

    }

    else {

      if ((*(short *)(iVar8 + DAT_0601c93c) == 0) && (*(short *)(iVar8 + DAT_0601c93e) == 0)) {

        *(short *)puVar1 = 0;

      }

      if ((*(short *)(iVar8 + DAT_0601c93c) != 0) ||

         (uVar6 = 0, *(short *)(iVar8 + DAT_0601c93e) != 0)) {

        (*(void(*)())0x06027080)();

        (*(void(*)())0x060270F2)(*(int *)0x06044670,

                   *(int *)(0x06044670 + 4) + (int)DAT_0601c940,

                   0xFFFF6000 - *(int *)(0x06044670 + 8));

        (*(void(*)())0x060271A2)(puVar2);

        iVar8 = (*(short *)(0x0605DF46 + *(short *)puVar1 * 2) + 0xe) * 4;

        (*(void(*)())0x06032158)(*(int *)(0x0606212C + iVar8),

                   *(int *)(0x060621D8 + iVar8));

        iVar8 = (*(short *)(0x0605DF46 + *(short *)puVar1 * 2) + 0xe) * 4;

        uVar6 = (*(void(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar8),*(short *)0x06089E9C

                           ,*(int *)(0x06062180 + iVar8));

        *(int *)puVar3 = *(int *)puVar3 + -0x30;

        *(short *)puVar1 = *(short *)puVar1 + 1;

        if (3 < *(short *)puVar1) {

          *(short *)puVar1 = 0;

        }

      }

    }

  }

  return uVar6;

}
