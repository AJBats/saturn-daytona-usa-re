int FUN_06035e00(param_1, param_2)
    unsigned short param_1;
    unsigned short *param_2;
{

  int iVar1;

  

  iVar1 = 0;

  do {

    if ((*(unsigned short *)0x25890008 & param_1) != 0) {

      *param_2 = *(unsigned short *)0x25890008;

      return 0;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < (int)0x00240000);

  return 0xfffffffd;

}
