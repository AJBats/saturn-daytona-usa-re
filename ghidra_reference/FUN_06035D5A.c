extern int DAT_06035e22;

extern int FUN_06035c6e();
extern int FUN_06035e00();
extern int FUN_06035e3c();
extern int FUN_06035e5e();

int FUN_06035d5a(param_1, param_2, param_3)
    unsigned int param_1;
    int param_2;
    unsigned char *param_3;
{

  char *puVar1;

  int iVar2;

  char auStack_18 [8];

  puVar1 = 0x06063590;

  *(unsigned short *)0x06063590 = *(unsigned short *)0x06063590 | *(unsigned short *)0x25890008;

  if ((*(unsigned short *)puVar1 & param_1) == param_1) {

    if ((*(unsigned short *)puVar1 & 1) == 0) {

      iVar2 = -2;

    }

    else {

      FUN_06035c6e(~(param_1 | 1) & 0xffff);

      *(unsigned short *)puVar1 = *(unsigned short *)puVar1 & 0xfffe;

      FUN_06035e3c(param_2);

      iVar2 = FUN_06035e00(1,auStack_18);

      if (iVar2 == 0) {

        FUN_06035e5e(param_3);

        if (*param_3 == DAT_06035e22) {

          iVar2 = -5;

        }

        else if ((*param_3 & 0x80) != 0) {

          iVar2 = -6;

        }

        if (iVar2 == 0) {

          *(unsigned short *)puVar1 = *(unsigned short *)puVar1 & ~(unsigned short)param_1;

        }

      }

    }

  }

  else {

    iVar2 = -1;

  }

  return iVar2;

}
