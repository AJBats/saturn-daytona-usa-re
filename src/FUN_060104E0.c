extern int DAT_0601064a;

extern int DAT_06010736;

unsigned int FUN_060104e0(param_1)
    unsigned int param_1;
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  int iVar9;

  int *puVar10;

  int uVar11;

  puVar5 = 0x060788A8;

  puVar4 = 0x06078868;

  puVar3 = 0x0607EAB8;

  puVar2 = 0x0607EADC;

  cVar1 = *(int *)0x0605AB16;

  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {

LAB_06010504:

    iVar9 = 5;

  }

  else {

    if (cVar1 != '\x03') {

      if (cVar1 == '\x04') goto LAB_06010504;

      if ((cVar1 != '\x05') && (cVar1 != '\x06')) {

        if (cVar1 == '\a') {

          iVar9 = 9;

        }

        else {

          iVar9 = 3;

        }

        goto LAB_06010570;

      }

    }

    iVar9 = 7;

  }

LAB_06010570:

  if (*(int *)0x0605AB17 == '\a') {

    iVar9 = 0xb;

  }

  uVar6 = (unsigned int)(char)*0x0605AB17;

  if (uVar6 == 0xf) {

    iVar9 = 0xd;

  }

  if ((param_1 & 0xffff & (unsigned int)0x00008000) == 0) {

    if ((param_1 & 0xffff & (int)DAT_0601064a) != 0) {

      *(char **)0x0607889C = 0x00010000;

      iVar7 = *(int *)puVar2;

      *(int *)puVar2 = iVar7 + -1;

      if (iVar7 + -1 < 0) {

        *(int *)puVar2 = iVar9;

      }

      uVar11 = 0xFFF40000;

      uVar6 = (unsigned int)(unsigned char)*puVar5;

      if (uVar6 == 0) {

        *puVar5 = 1;

        *(int *)0x06078898 = uVar11;

        *(int *)0x060788A4 = *(int *)puVar2;

      }

      else {

        *puVar5 = 0;

        *(int *)0x06078894 = uVar11;

        *(int *)0x060788A0 = *(int *)puVar2;

      }

    }

  }

  else {

    *(int *)0x0607889C = 0xFFFF0000;

    iVar7 = *(int *)puVar2;

    *(int *)puVar2 = iVar7 + 1;

    if (iVar9 < iVar7 + 1) {

      *(int *)puVar2 = 0;

    }

    if (*puVar5 == '\0') {

      *puVar5 = 1;

      (*(void(*)())0x060359E4)();

      uVar6 = (*(void(*)())0x060357B8)();

      *(unsigned int *)0x06078898 = uVar6;

      *(int *)0x060788A4 = *(int *)puVar2;

    }

    else {

      *puVar5 = 0;

      (*(void(*)())0x060359E4)();

      uVar6 = (*(void(*)())0x060357B8)();

      *(unsigned int *)0x06078894 = uVar6;

      *(int *)0x060788A0 = *(int *)puVar2;

    }

  }

  uVar8 = *(unsigned int *)puVar2;

  *(unsigned int *)puVar4 = uVar8;

  *(unsigned int *)puVar3 = uVar8 & 1;

  if (*(unsigned int *)puVar4 < 10) {

    if (*puVar5 == '\0') {

      uVar11 = *(int *)(0x0605D05C + *(int *)puVar4 * 4);

      puVar10 = (int *)0x06078884;

    }

    else {

      uVar11 = *(int *)(0x0605D05C + *(int *)puVar4 * 4);

      puVar10 = (int *)0x06078880;

    }

    uVar6 = (*(void(*)())0x0602766C)(*puVar10,uVar11,(int)DAT_06010736);

  }

  if ((param_1 & 0xffff & (unsigned int)0x0000C000) != 0) {

    if (*(unsigned int *)puVar4 < 0xc) {

      iVar9 = *(int *)puVar4;

    }

    else {

      iVar9 = *(int *)puVar4 + -2;

    }

    uVar6 = (*(void(*)())0x0602761E)(0x25F00000 + (*(int *)puVar3 * 2 + 0x23) * 0x20,

                       0x0605CA9C + iVar9 * 0x40,0x40);

    return uVar6;

  }

  return uVar6;

}
