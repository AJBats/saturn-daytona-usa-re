extern int PTR_DAT_0603f180;

extern int PTR_DAT_0603f180;

int FUN_0603f148(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  puVar2 = 0x06036D94;

  uVar1 = PTR_DAT_0603f180;

  iVar3 = (*(int(*)())0x06036D14)();

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int(*)())0x06036D14)();

    if (iVar3 == 0) {

      iVar3 = 1;

    }

    else {

      iVar3 = 2;

      param_1 = param_1 + 0x30;

      if (2 < param_3) {

        do {

          iVar4 = (*(int(*)())puVar2)(param_2,param_1 + 0xc,0xc);

          if (iVar4 == 0) {

            return iVar3;

          }

          if ((*(unsigned char *)(param_1 + 0xb) & uVar1) != 0) break;

          iVar3 = iVar3 + 1;

          param_1 = param_1 + 0x18;

        } while (iVar3 < param_3);

      }

      iVar3 = -1;

    }

  }

  return iVar3;

}
