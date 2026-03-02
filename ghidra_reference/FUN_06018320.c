extern int DAT_060183ec;

extern int DAT_060183ee;

extern int DAT_060183f0;

extern int DAT_060183f2;

extern int DAT_06018504;

extern int DAT_06018506;

extern int DAT_060185a0;

extern int DAT_060185a2;

extern int PTR_DAT_060185a4;

extern int PTR_DAT_060185a4;

void FUN_06018320()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  unsigned short uVar9;

  unsigned short uVar10;

  int iVar11;

  puVar8 = 0x0605BE33;

  puVar7 = 0x0605BE34;

  puVar6 = 0x06085FC0;

  puVar5 = 0x0605BE32;

  puVar4 = 0x00008000;

  puVar3 = 0x0607E940;

  puVar2 = 0x0605BE35;

  *(int *)0x0605BE34 = *(int *)0x0605BE33;

  if (((int)DAT_060183ee <= *(int *)(*(int *)puVar3 + (int)DAT_060183ec)) &&

     (*(int *)(*(int *)puVar3 + (int)DAT_060183ec) <= (int)DAT_060183f0)) {

    *puVar8 = 1;

    uVar9 = *(unsigned short *)0x06063D98 & 0x40;

    uVar10 = (*(unsigned short *)0x0605BE30 ^ uVar9) & uVar9;

    *(unsigned short *)0x0605BE30 = uVar9;

    if (*(int *)0x0605DE3C == '\0') {

      if ((((*(unsigned char *)(*(int *)puVar3 + 3) & 8) == 0 & (*puVar8 ^ *puVar7)) != 0) &&

         ((*(unsigned int *)0x0605A010 & 0x3f) == 0)) {

        *puVar2 = 1;

      }

    }

    else {

      *puVar2 = 1;

    }

    puVar7 = 0x00010000;

    if (*(int *)0x06085FF4 == '\0') {

      if ((*(int *)(*(int *)puVar3 + 8) == 0) && (uVar10 != 0)) {

        iVar11 = (int)DAT_060183f2;

        if (*puVar5 == '\0') {

          *(int *)puVar6 = 0;

          iVar11 = *(int *)(puVar6 + 4) + iVar11;

          *(int *)(puVar6 + 4) = iVar11;

          if ((int)puVar7 <= iVar11) {

            *(char **)puVar6 = puVar4;

            *(char **)(puVar6 + 4) = puVar4;

            *puVar5 = *puVar5 + '\x01';

          }

        }

        else if (*puVar5 == '\x01') {

          *(char **)puVar6 = puVar4;

          iVar11 = *(int *)(puVar6 + 4) + iVar11;

          *(int *)(puVar6 + 4) = iVar11;

          if ((int)0x00018000 <= iVar11) {

            *(int *)puVar6 = 0;

            *(int *)(puVar6 + 4) = 0;

            *puVar5 = *puVar5 + '\x01';

          }

        }

        else {

          *(int *)puVar6 = 0;

          *(int *)(puVar6 + 4) = 0;

        }

      }

    }

    else {

      cVar1 = *puVar5;

      if (cVar1 == '\0') {

        *(int *)puVar6 = 0;

        *(int *)(puVar6 + 4) = 0;

        if ((*(int *)(*(int *)puVar3 + 8) == 0) && (uVar10 != 0)) {

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x01') {

        iVar11 = *(int *)(puVar6 + 4) + 0x100;

        *(int *)(puVar6 + 4) = iVar11;

        if ((int)puVar7 <= iVar11) {

          *(char **)(puVar6 + 4) = puVar7;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x02') {

        iVar11 = *(int *)puVar6 + 0x200;

        *(int *)puVar6 = iVar11;

        if ((int)puVar4 <= iVar11) {

          *(char **)puVar6 = puVar4;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x03') {

        iVar11 = *(int *)(puVar6 + 4) + 0x100;

        *(int *)(puVar6 + 4) = iVar11;

        if ((int)0x00020000 <= iVar11) {

          *(char **)(puVar6 + 4) = 0x00020000;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else if (cVar1 == '\x04') {

        iVar11 = *(int *)puVar6 + 0x200;

        *(int *)puVar6 = iVar11;

        if ((int)puVar7 <= iVar11) {

          *(int *)puVar6 = 0;

          *puVar5 = *puVar5 + '\x01';

        }

      }

      else {

        *(int *)puVar6 = 0;

        *(int *)(puVar6 + 4) = 0;

      }

    }

    if (*puVar2 != '\0') {

      *(char **)puVar6 = puVar4;

      *(char **)(puVar6 + 4) = puVar4;

    }

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)0x06048140,*(int *)(0x06048140 + 4),

               *(int *)(0x06048140 + 8));

    (*(int(*)())0x06026EDE)(*(int *)(puVar6 + 4) + (int)DAT_060185a0);

    (*(int(*)())0x06026E94)(*(int *)puVar6);

    puVar2 = 0x00200000;

    (*(int(*)())0x06031D8C)(0x00200000 + (int)0x000BABE0,0x178);

    (*(int(*)())0x06031A28)(puVar2 + (int)0x000BBD80,(int)*(short *)0x06089E98,

               (int)PTR_DAT_060185a4);

    (*(int(*)())0x06026DF8)();

    return;

  }

  *(int *)puVar6 = 0;

  *(int *)(puVar6 + 4) = 0;

  *puVar8 = 0;

  *puVar2 = 0;

  *puVar5 = 0;

  return;

}
