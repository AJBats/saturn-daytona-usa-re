extern int DAT_0603fe2e;

extern int PTR_DAT_0603fe30;

extern int PTR_DAT_0603fe30;

extern int FUN_0603ffe6();

void FUN_0603fd40(param_1, param_2, param_3, param_4, param_5, param_6)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
    unsigned int param_6;
{

  char *puVar1;

  int iVar2;

  unsigned int uVar3;

  int iStack_58;

  int iStack_54;

  unsigned int uStack_50;

  int uStack_4c;

  int uStack_48;

  unsigned int uStack_44;

  unsigned int uStack_40;

  int uStack_3c;

  int iStack_34;

  int uStack_30;

  int uStack_2c;

  int uStack_28;

  puVar1 = 0x06042BEE;

  (*(void(*)())0x06042BBE)(param_1);

  uStack_30 = 0;

  uStack_2c = 1;

  uStack_28 = 7;

  (*(void(*)())0x06042A8C)(&uStack_30);

  uVar3 = param_6 >> 2;

  if (param_3 < 1) {

    if (param_3 < 0) {

      uStack_4c = 2;

    }

    else {

      uStack_4c = 0;

    }

  }

  else {

    uStack_4c = 1;

  }

  if (param_5 < 1) {

    if (param_5 < 0) {

      uStack_48 = 2;

    }

    else {

      uStack_48 = 0;

    }

  }

  else {

    uStack_48 = 1;

  }

  uStack_44 = (unsigned int)DAT_0603fe2e;

  uStack_40 = uStack_44 >> 2;

  uStack_3c = 0;

  iStack_34 = (int)PTR_DAT_0603fe30;

  iStack_58 = param_4;

  iStack_54 = param_2;

  uStack_50 = uVar3;

  (*(void(*)())0x06042ACA)(&iStack_58,param_1);

  (*(void(*)())0x06042BAC)(param_1);

  do {

    iVar2 = (*(void(*)())puVar1)(param_1);

  } while (iVar2 == 0);

  FUN_0603ffe6(param_6 & 3,param_3 * uVar3 * 4 + param_2,param_5 * uVar3 * 4 + param_4);

  (*(void(*)())0x0603C05C)(param_2,param_6);

  return;

}
