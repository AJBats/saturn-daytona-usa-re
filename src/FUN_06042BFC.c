extern int DAT_06042c78;

extern int DAT_06042c7a;

extern int DAT_06042cb2;

extern int PTR_DAT_06042cb4;

extern int PTR_DAT_06042cb4;

char * FUN_06042bfc(param_1)
    char *param_1;
{

  if (param_1 == &UNK_00000001) {

    return (char *)(*(unsigned short *)(0x060A4D18 + 6) & 7);

  }

  if ((param_1 == &UNK_00000002) || (param_1 == &UNK_00000004)) {

    return (char *)(*(unsigned short *)(0x060A4D18 + 4) & 7);

  }

  if (param_1 != &UNK_00000008) {

    if (param_1 == &UNK_00000010) {

      return (char *)((int)((unsigned int)*(unsigned short *)(0x060A4D18 + 4) & (int)DAT_06042c78) >> 8);

    }

    if (param_1 == &UNK_00000020) {

      return (char *)

             ((int)((unsigned int)*(unsigned short *)(0x060A4D18 + 4) & (int)DAT_06042c7a) >> 0xc);

    }

    if (param_1 != (char *)(int)DAT_06042cb2) {

      if (param_1 == (char *)(int)PTR_DAT_06042cb4) {

        return (char *)((int)(*(unsigned short *)(0x060A4D18 + 6) & 0x70) >> 4);

      }

      if (param_1 != 0x00040000) {

        return param_1;

      }

      return *(char **)0x060A4D5C;

    }

  }

  return (char *)((int)(*(unsigned short *)(0x060A4D18 + 4) & 0x70) >> 4);

}
