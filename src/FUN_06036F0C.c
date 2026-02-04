extern int DAT_06036fba;

extern int DAT_06036fbc;

extern int DAT_06036fbe;

extern int DAT_06036fc0;

extern int DAT_06036fc2;

extern int DAT_06037078;

extern int DAT_0603707a;

extern int DAT_0603707c;

extern int DAT_0603707e;

extern int PTR_DAT_06036fc4;

extern int PTR_DAT_06036fc4;

void FUN_06036f0c(param_1, param_2, param_3)
    char param_1;
    char param_2;
    char param_3;
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned short uVar5;

  int iVar6;

  puVar4 = 0x060A3D88;

  puVar3 = 0x060635B0;

  puVar2 = 0x060635AE;

  uVar1 = DAT_06036fba;

  iVar6 = *(int *)0x06000324;

  *(unsigned short *)0x060A3D88 = *(unsigned short *)0x060A3D88 & (unsigned short)0x0000FFCF;

  if (param_2 == '\0') {

    *(short *)puVar3 = DAT_06036fbc;

  }

  else {

    if (param_2 == '\x01') {

      *(short *)puVar3 = DAT_06036fbe;

      uVar5 = *(unsigned short *)puVar4 | 0x10;

    }

    else {

      if (param_2 != '\x02') goto LAB_06036f58;

      *(short *)puVar3 = DAT_06036fc0;

      uVar5 = *(unsigned short *)puVar4 | 0x20;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_06036f58:

  *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FF3F;

  if (param_1 != '\0') {

    if (param_1 == '\x02') {

      uVar5 = *(unsigned short *)puVar4 | 0x80;

    }

    else {

      if (param_1 != '\x03') goto LAB_06036f86;

      *(short *)puVar3 = *(short *)puVar3 + *(short *)puVar3;

      uVar5 = *(unsigned short *)puVar4 | 0xc0;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_06036f86:

  *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & (unsigned short)0x0000FFF0;

  if (param_3 == '\0') {

    if (iVar6 != 0) {

      (*(void(*)())(*(int *)0x06000320))(0);

    }

    *(short *)puVar2 = DAT_06036fc2;

  }

  else {

    if (param_3 == '\x01') {

      if (iVar6 != 1) {

        (*(void(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = PTR_DAT_06036fc4;

      uVar5 = *(unsigned short *)puVar4 | 1;

    }

    else if (param_3 == '\x02') {

      if (iVar6 != 0) {

        (*(void(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_06037078;

      uVar5 = *(unsigned short *)puVar4 | 2;

    }

    else if (param_3 == '\x03') {

      if (iVar6 != 1) {

        (*(void(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707a;

      uVar5 = *(unsigned short *)puVar4 | 3;

    }

    else if (param_3 == '\x04') {

      if (iVar6 != 0) {

        (*(void(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_0603707c;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 4;

    }

    else if (param_3 == '\x05') {

      if (iVar6 != 1) {

        (*(void(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707e;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 5;

    }

    else if (param_3 == '\x06') {

      if (iVar6 != 0) {

        (*(void(*)())(*(int *)0x06000320))(0);

      }

      *(short *)puVar2 = DAT_06037078;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 6;

    }

    else {

      if (param_3 != '\a') goto LAB_060370a0;

      if (iVar6 != 1) {

        (*(void(*)())(*(int *)0x06000320))(1);

      }

      *(short *)puVar2 = DAT_0603707a;

      *(short *)puVar3 = uVar1;

      uVar5 = *(unsigned short *)puVar4 | 7;

    }

    *(unsigned short *)puVar4 = uVar5;

  }

LAB_060370a0:

  if (*(short *)0x060635AC == 0) {

    *(short *)0x060635AC = 1;

  }

  return;

}
