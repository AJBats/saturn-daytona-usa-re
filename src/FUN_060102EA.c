extern int DAT_0601038c;

extern int DAT_0601038e;

extern int PTR_DAT_0601030c;

extern int PTR_DAT_0601030c;

void FUN_060102ea(param_1)
    unsigned short param_1;
{

  char *puVar1;

  char *puVar2;

  puVar1 = 0x0607EBCC;

  *(int *)0x0607EBCC = *(int *)0x0607EBCC + -1;

  if ((param_1 & PTR_DAT_0601030c) == 0) {

    if ((*(int *)puVar1 < 1) || ((param_1 & DAT_0601038c) != 0)) {

      (*0x0601D5F4)

                (0,*(int *)(0x0604481C + *(int *)0x0607EADC * 4));

      *(int *)puVar1 = 0;

      *0x0607887F = 2;

      *0x06078648 = (char)*(int *)0x0607EAD8;

      puVar2 = 0x0605AB18;

      *0x0605AB18 = 0;

      if ((*0x06085FF4 == '\0') &&

         ((*(int *)0x0605AD00 == 0 && ((*(unsigned short *)0x06063D98 & DAT_0601038e) != 0)))) {

        *puVar2 = 1;

      }

    }

  }

  else {

    *(int *)0x0605AD10 = 6;

  }

  return;

}
