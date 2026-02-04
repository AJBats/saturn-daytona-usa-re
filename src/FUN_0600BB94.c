extern int DAT_0600bc2c;

extern int DAT_0600bc2e;

extern int DAT_0600bcee;

extern int DAT_0600bdac;

extern int DAT_0600bdae;

extern int DAT_0600bf3c;

extern int PTR_DAT_0600bc30;

extern int PTR_DAT_0600bc30;

extern int PTR_DAT_0600be4c;

extern int PTR_DAT_0600be4c;

extern int FUN_0600bf70();
extern int FUN_0600c3a8();

void FUN_0600bb94()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  char *puVar8;

  int iVar9;

  int local_28;

  int aiStack_24 [2];

  puVar8 = 0x06063E24;

  puVar6 = 0x06063EEC;

  puVar5 = 0x06063EF8;

  puVar4 = 0x06063E30;

  puVar3 = 0x06063E28;

  puVar2 = 0x06038520;

  iVar9 = *(int *)0x0607E944;

  iVar7 = (int)DAT_0600bc2c;

  cVar1 = *(int *)0x06078654;

  if (cVar1 != '\0') {

    if (cVar1 == '\x01') {

      if (*(int *)0x0605A1C4 == 0) {

        if (*(unsigned int *)0x06063E20 < 2) {

          *(int *)(0x06063EEC + 4) = *(int *)(iVar9 + 0x20) + *(int *)(iVar9 + DAT_0600bc2e);

        }

        FUN_0600c3a8((int)*(short *)0x06063D9A);

      }

    }

    else if (cVar1 == '\x04') {

      if (*(int *)(iVar9 + DAT_0600bcee) == 0) {

        *(int *)0x06063E20 = 2;

      }

      else if (*(int *)(iVar9 + DAT_0600bcee) < 0x31) {

        if (*(int *)(iVar9 + DAT_0600bcee) < 0x29) {

          if (*(int *)(iVar9 + DAT_0600bcee) < 0x11) {

            if (*(int *)(iVar9 + DAT_0600bcee) < 9) {

              if ((*(int *)(iVar9 + DAT_0600bdac) == 8) || (*(int *)(iVar9 + DAT_0600bdac) == 7)) {

                *(int *)0x06063E1C = 2;

                *(int *)0x06059F30 = 1;

                (*(void(*)())0x06038BD4)(8,0);

                *(char **)puVar8 = 0x00058000;

                *(char **)0x06063E34 = 0x0000F300;

                *(char **)puVar3 = 0x006E0000;

                *(char **)0x06063E2C = 0x00100000;

                *(int *)puVar4 = 0;

              }

            }

            else {

              *(int *)0x06063E24 = *(int *)0x06063E24 + iVar7;

            }

          }

        }

        else {

          *(int *)0x06063E24 = *(int *)0x06063E24 - iVar7;

        }

      }

      iVar7 = (int)DAT_0600bdae;

      *(int *)(puVar6 + 4) = *(int *)(iVar9 + 0x20) - *(int *)(iVar9 + iVar7);

      *(int *)(iVar9 + iVar7) =

           *(int *)(iVar9 + iVar7) + ((int)0x00008000 - *(int *)(iVar9 + iVar7) >> 4);

    }

    else if (cVar1 == '\x06') {

      *(int *)0x06063E20 = 3;

    }

    else if (cVar1 == '\a') {

      if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x31) {

        if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x29) {

          if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 0x11) {

            if (*(int *)(iVar9 + PTR_DAT_0600bc30) < 9) {

              if ((*(int *)(iVar9 + DAT_0600bcee) == 8) || (*(int *)(iVar9 + DAT_0600bcee) == 7)) {

                *(int *)0x06063E1C = 2;

                *(int *)0x06059F30 = 1;

                (*(void(*)())0x06038BD4)(8,0);

                *(char **)puVar8 = 0x00058000;

                *(char **)0x06063E34 = 0x0000F300;

                *(char **)puVar3 = 0x006E0000;

                *(char **)0x06063E2C = 0x00100000;

                *(int *)puVar4 = 0;

              }

            }

            else {

              *(int *)0x06063E24 = *(int *)0x06063E24 + iVar7;

            }

          }

        }

        else {

          *(int *)0x06063E24 = *(int *)0x06063E24 - iVar7;

        }

      }

      FUN_0600c3a8((int)*(short *)0x06063D9A);

    }

  }

  if (*(int *)0x06078663 == '\0') {

    puVar8 = (char *)(*(int *)(puVar6 + 4) * -0x400 + 0xFFA00000);

  }

  else {

    puVar8 = 0x01A00000 + *(int *)(puVar6 + 4) * 0x400;

  }

  if (*(int *)0x06082A30 == 0) {

    if (*(int *)(iVar9 + PTR_DAT_0600be4c) == 0) {

      (*(void(*)())0x060064F2)();

    }

    else {

      iVar7 = (int)DAT_0600bf3c;

      *(int *)0x06063F04 = iVar7;

      *(int *)0x06063F08 = iVar7;

    }

    (*(void(*)())0x0603850C)(4);

    (*(void(*)())0x0603853C)(puVar8,*(int *)puVar3,0);

    (*(void(*)())puVar2)();

    iVar7 = *(int *)(iVar9 + 0x1c) << 8;

    if (iVar7 < 0) {

      iVar7 = *(int *)(iVar9 + 0x1c) << 9;

    }

    (*(void(*)())0x0603850C)(8);

    (*(void(*)())0x0603853C)(0,*(int *)(0x0605BDCC + (*(unsigned short *)0x06063F46 & 0xc) * 4) * 0x200 +

                 *(int *)0x06063E2C + iVar7);

    (*(void(*)())puVar2)();

    (*(void(*)())0x06020E74)();

    (*(void(*)())0x06027358)(*(int *)(puVar6 + 4),&local_28,aiStack_24);

    *(int *)puVar5 = *(int *)(iVar9 + 0x10) - local_28;

    *(int *)(puVar5 + 4) = *(int *)(iVar9 + 0x14) + *(int *)puVar4;

    *(int *)(puVar5 + 8) = *(int *)(iVar9 + 0x18) + aiStack_24[0];

    FUN_0600bf70();

    iVar7 = (*(void(*)())0x06027344)(*(int *)(puVar6 + 4) - *(int *)(iVar9 + 0x20));

    *(int *)0x06078668 = -(iVar7 >> 7);

    iVar7 = (*(void(*)())0x06027552)(*(int *)(iVar9 + 0x24),iVar7);

    *(int *)(puVar6 + 8) = iVar7 + *(int *)(puVar6 + 8) >> 1;

  }

  else {

    (*(void(*)())0x0603850C)(4);

    (*(void(*)())0x0603853C)(puVar8,*(int *)puVar3,0);

    (*(void(*)())puVar2)();

    (*(void(*)())0x06027358)(*(int *)(puVar6 + 4),&local_28,aiStack_24);

    *(int *)puVar5 = (*(int *)(iVar9 + 0x10) - local_28) + *(int *)0x06082A70;

    *(int *)(puVar5 + 4) = *(int *)(iVar9 + 0x14) + *(int *)puVar4;

    *(int *)(puVar5 + 8) = *(int *)(iVar9 + 0x18) + aiStack_24[0] + *(int *)0x06082A78;

  }

  return;

}
