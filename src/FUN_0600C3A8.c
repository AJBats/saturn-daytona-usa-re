unsigned short FUN_0600c3a8(param_1)
    unsigned short param_1;
{

  char *puVar1;

  unsigned short uVar2;

  int iVar3;

  short uVar4;

  puVar1 = 0x06063E20;

  if ((char *)(unsigned int)*(unsigned short *)0x0607865E == 0x00008000) {

    if ((param_1 & *(unsigned short *)0x06078656) == 0) {

      if ((param_1 & *(unsigned short *)0x06078658) == 0) {

        if ((param_1 & *(unsigned short *)0x0607865A) == 0) {

          if ((param_1 & *(unsigned short *)0x0607865C) != 0) {

            *(int *)0x06063E20 = 3;

          }

        }

        else {

          *(int *)0x06063E20 = 2;

        }

      }

      else if (*0x06083255 == '\0') {

        *(int *)0x06063E20 = 1;

      }

    }

    else {

      *(int *)0x06063E20 = 0;

    }

  }

  else if (((param_1 & *(unsigned short *)0x0607865E) == 0) || (*(int *)0x06063E20 == 0)) {

    if (((param_1 & *(unsigned short *)0x06078660) != 0) &&

       (*(unsigned int *)0x06063E20 < (unsigned int)(int)(char)*0x06078662)) {

      if ((*0x06083255 == '\0') || (*(int *)0x06063E20 != 0)) {

        *(int *)0x06063E20 = *(int *)0x06063E20 + 1;

      }

      else {

        *(int *)0x06063E20 = *(int *)0x06063E20 + 2;

      }

    }

  }

  else {

    if ((*0x06083255 == '\0') || (*(int *)0x06063E20 != 2)) {

      iVar3 = *(int *)0x06063E20 + -1;

    }

    else {

      iVar3 = *(int *)0x06063E20 + -2;

    }

    *(int *)0x06063E20 = iVar3;

  }

  uVar2 = (unsigned short)(unsigned char)*0x06078635;

  if ((uVar2 == 0) && (uVar2 = *(unsigned short *)0x0607ED8C, uVar2 != 0)) {

    if ((unsigned int)(*(int *)0x06063E1C + *(int *)puVar1) < 7) {

      uVar4 = 4;

    }

    else {

      uVar4 = 3;

    }

    *(short *)0x0605A016 = uVar4;

  }

  return uVar2;

}
