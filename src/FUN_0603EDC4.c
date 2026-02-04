extern int DAT_0603ee76;

extern int DAT_0603ef2a;

unsigned int FUN_0603edc4(param_1, param_2, param_3, param_4, param_5)
    unsigned int param_1;
    unsigned int param_2;
    unsigned char *param_3;
    unsigned char param_4;
    unsigned char param_5;
{

  unsigned int uVar1;

  uVar1 = (unsigned int)(char)param_5;

  if (((param_2 & 4) != 0) || ((param_2 & 2) != 0)) {

    if (((param_1 & 4) == 0) && ((param_1 & 2) == 0)) {

      uVar1 = (int)(char)param_3[1] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[1] | (unsigned int)param_4;

    }

    param_3[1] = (unsigned char)uVar1;

  }

  if (((param_2 & 8) != 0) || ((0x80 & param_2) != 0)) {

    if (((param_1 & 8) == 0) && ((0x80 & param_1) == 0)) {

      *param_3 = *param_3 & param_5;

    }

    else {

      *param_3 = *param_3 | param_4;

    }

  }

  if ((param_2 & 0x10) != 0) {

    if ((param_1 & 0x10) == 0) {

      uVar1 = (int)(char)param_3[3] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[3] | (unsigned int)param_4;

    }

    param_3[3] = (unsigned char)uVar1;

  }

  if ((param_2 & 0x20) != 0) {

    if ((param_1 & 0x20) == 0) {

      uVar1 = (int)(char)param_3[2] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[2] | (unsigned int)param_4;

    }

    param_3[2] = (unsigned char)uVar1;

  }

  if ((param_2 & 1) != 0) {

    if ((param_1 & 1) == 0) {

      uVar1 = (int)(char)param_3[5] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[5] | (unsigned int)param_4;

    }

    param_3[5] = (unsigned char)uVar1;

  }

  if ((0x100 & param_2) != 0) {

    if ((0x100 & param_1) == 0) {

      uVar1 = (int)(char)param_3[4] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[4] | (unsigned int)param_4;

    }

    param_3[4] = (unsigned char)uVar1;

  }

  if (((unsigned int)0x00010000 & param_2) != 0) {

    if (((unsigned int)0x00010000 & param_1) == 0) {

      uVar1 = (int)(char)param_3[7] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[7] | (unsigned int)param_4;

    }

    param_3[7] = (unsigned char)uVar1;

  }

  if ((param_2 & (unsigned int)0x00020000) != 0) {

    if ((param_1 & (unsigned int)0x00020000) == 0) {

      uVar1 = (int)(char)param_3[6] & (unsigned int)param_5;

    }

    else {

      uVar1 = (int)(char)param_3[6] | (unsigned int)param_4;

    }

    param_3[6] = (unsigned char)uVar1;

  }

  return uVar1;

}
