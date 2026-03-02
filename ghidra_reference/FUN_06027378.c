extern int DAT_00280000;

extern int DAT_00320000;

extern int DAT_00460000;

extern int DAT_00640000;

extern int DAT_060274fc;

extern int DAT_06027504;

extern int DAT_06027506;

extern int DAT_06027508;

extern int DAT_0602750a;

extern int DAT_0602750c;

extern int DAT_0602750e;

extern int DAT_06027510;

extern int DAT_06027512;

extern int DAT_06027514;

extern int DAT_06027516;

extern int DAT_06027518;

extern int DAT_0602751a;

extern int DAT_0602751c;

extern int DAT_0602751e;

extern int DAT_06027520;

extern int DAT_06027522;

extern int DAT_06027524;

extern int DAT_06027526;

int FUN_06027378(param_1)
    int param_1;
{

  unsigned int uVar1;

  int bVar2;

  int iVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  bVar2 = param_1 < 0;

  if (bVar2) {

    param_1 = -param_1;

  }

  uVar6 = param_1 + 0x80;

  if (uVar6 < 0x100000) {

    iVar3 = (int)*(short *)(0x002F0000 + (uVar6 >> 8) << 1);

    if (bVar2) {

      return -iVar3;

    }

  }

  else {

    uVar1 = uVar6 >> 0x10;

    if (uVar1 < (unsigned int)0x3e8) {

      if (uVar1 < (unsigned int)(int)DAT_06027520) {

        if (uVar1 < (unsigned int)0x32) {

          if (uVar1 < (unsigned int)(int)DAT_06027518) {

            iVar3 = 0x3d74;

            puVar5 = (char *)0x100000;

            puVar4 = 0x0015B6DB;

          }

          else if (uVar1 < (unsigned int)(int)DAT_0602751a) {

            iVar3 = 0x3ea4;

            puVar5 = (char *)0x1e0000;

            puVar4 = 0x0008B333;

          }

          else {

            iVar3 = 0x3efb;

            puVar5 = &DAT_00280000;

            puVar4 = 0x00053333;

          }

        }

        else if (uVar1 < (unsigned int)(int)DAT_0602751e) {

          iVar3 = 0x3f2f;

          puVar5 = &DAT_00320000;

          puVar4 = 0x0002F333;

        }

        else {

          iVar3 = 0x3f6a;

          puVar5 = &DAT_00460000;

          puVar4 = 0x00018000;

        }

      }

      else if (uVar1 < (unsigned int)0xfa) {

        if (uVar1 < (unsigned int)(int)DAT_06027522) {

          iVar3 = (int)DAT_0602750a;

          puVar5 = &DAT_00640000;

          puVar4 = 0x0000B333;

        }

        else {

          iVar3 = 0x3fba;

          puVar5 = (char *)((int)DAT_06027522 << 0x10 | (unsigned int)(int)DAT_06027522 >> 0x10);

          puVar4 = 0x000047AE;

        }

      }

      else if (uVar1 < (unsigned int)(int)DAT_06027526) {

        iVar3 = (int)DAT_06027506;

        puVar5 = (char *)(0xfa << 0x10 | (unsigned int)0xfa >> 0x10);

        puVar4 = 0x00001581;

      }

      else {

        iVar3 = 0x3feb;

        puVar5 = (char *)((int)DAT_06027526 << 0x10 | (unsigned int)(int)DAT_06027526 >> 0x10);

        puVar4 = 0x00000AC0;

      }

      iVar3 = (short)((unsigned long long)((long long)(int)puVar4 * (long long)(int)(uVar6 - (int)puVar5)) >>

                     0x20) + iVar3;

      if (bVar2) {

        iVar3 = -iVar3;

      }

    }

    else {

      iVar3 = (int)DAT_060274fc;

      if (bVar2) {

        return -iVar3;

      }

    }

  }

  return iVar3;

}
