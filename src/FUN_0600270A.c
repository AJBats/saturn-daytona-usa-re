void FUN_0600270a(param_1, param_2)
    unsigned char param_1;
    int param_2;
{

  unsigned int uVar1;

  int in_r0;

  unsigned char in_r1;

  int in_r2;

  int iVar2;

  unsigned int unaff_r8;

  unsigned char *unaff_r9;

  if (param_2 < 1) {

    if ((((in_r0 != 0xc) && (in_r0 != 0xe)) && (in_r0 != 0xd)) && (in_r0 != 0xf)) {

      if ((unaff_r8 & 1) != 1) {

        return;

      }

      *unaff_r9 = in_r1 | (unsigned char)in_r0;

      return;

    }

  }

  else if (param_2 == 1) {

    iVar2 = in_r2 * 0x10 + in_r0 + 2;

    do {

      uVar1 = unaff_r8 & 1;

      unaff_r8 = unaff_r8 >> 1;

      if (uVar1 == 1) {

        in_r1 = in_r1 | param_1;

        *unaff_r9 = in_r1;

        unaff_r9 = unaff_r9 + 1;

      }

      else {

        unaff_r8 = unaff_r8 + 1;

        in_r1 = param_1 << 4;

      }

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}
