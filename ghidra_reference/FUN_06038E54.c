extern int DAT_06038efa;

extern int DAT_06038efc;

void FUN_06038e54(param_1)
    unsigned short param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  puVar5 = 0x060635B8;

  puVar4 = 0x060635B4;

  puVar3 = 0x25D00002;

  puVar2 = 0x060A4C92;

  puVar1 = 0x060635BC;

  if ((char *)(unsigned int)param_1 == 0x0000FFFF) {

    *(short *)0x060635B4 = 2;

    *(int *)puVar5 = 0;

    *(unsigned short *)puVar3 = *(unsigned short *)puVar2 | 3;

    *(unsigned int *)puVar1 = (unsigned int)param_1;

  }

  else if ((char *)(unsigned int)param_1 == 0x0000FFFE) {

    *(short *)0x060635B4 = 3;

    *(int *)puVar5 = 0;

    *(unsigned short *)puVar3 = *(unsigned short *)puVar2 | 3;

    *(unsigned int *)puVar1 = (unsigned int)param_1;

  }

  else {

    if ((param_1 & DAT_06038efa) == 0) {

      *(int *)0x060635B8 = 1;

    }

    else {

      *(int *)0x060635B8 = 0;

    }

    uVar6 = (unsigned int)(param_1 & DAT_06038efc);

    if (uVar6 == 0) {

      *(short *)puVar4 = 0;

    }

    else {

      *(unsigned short *)puVar4 = (unsigned short)(uVar6 != 1);

    }

    *(unsigned int *)puVar1 = uVar6;

    if (*(short *)puVar4 == 0) {

      *(short *)puVar3 = *(short *)puVar2;

    }

    else {

      *(unsigned short *)puVar3 = *(unsigned short *)puVar2 | 3;

    }

  }

  return;

}
