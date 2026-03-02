int FUN_06036d94(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    unsigned int param_3;
{

  char cVar1;

  char *pcVar2;

  unsigned int uVar3;

  if (param_3 == 0) {

    return 0;

  }

  uVar3 = 0;

  pcVar2 = param_1;

  if (param_3 != 0) {

    do {

      param_1 = pcVar2 + 1;

      cVar1 = *param_2;

      param_2 = param_2 + 1;

      if ((*pcVar2 != cVar1) || (*pcVar2 == '\0')) break;

      uVar3 = uVar3 + 1;

      pcVar2 = param_1;

    } while (uVar3 < param_3);

  }

  return (unsigned int)(unsigned char)param_1[-1] - (unsigned int)(unsigned char)param_2[-1];

}
