extern int DAT_0601096e;

extern int PTR_DAT_06010870;

extern int PTR_DAT_06010870;

extern int PTR_DAT_06010970;

extern int PTR_DAT_06010970;

unsigned int FUN_06010760()
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  unsigned int uVar9;

  int iVar10;

  int iVar11;

  int uVar12;

  puVar5 = 0x0607EADC;

  puVar4 = 0x06078868;

  puVar3 = 0x060788A8;

  puVar2 = 0x0602761E;

  cVar1 = *(int *)0x0605AB16;

  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {

LAB_06010782:

    iVar11 = 5;

  }

  else {

    if (cVar1 != '\x03') {

      if (cVar1 == '\x04') goto LAB_06010782;

      if ((cVar1 != '\x05') && (cVar1 != '\x06')) {

        if (cVar1 == '\a') {

          iVar11 = 9;

        }

        else {

          iVar11 = 3;

        }

        goto LAB_060107c8;

      }

    }

    iVar11 = 7;

  }

LAB_060107c8:

  if (*(int *)0x0605AB17 == '\a') {

    iVar11 = 0xb;

  }

  if (*(int *)0x0605AB17 == '\x0f') {

    iVar11 = 0xd;

  }

  uVar7 = ((unsigned int)*(unsigned short *)0x06063D9C ^ (unsigned int)0x0000FFFF) & 0xff;

  uVar8 = uVar7;

  if (0x90 < (int)uVar7) {

    *(int *)0x0607889C = 0xFFFF0000;

    *(int *)0x0605AA9C = 0x1e;

    iVar10 = *(int *)puVar5;

    *(int *)puVar5 = iVar10 + 1;

    if (iVar11 < iVar10 + 1) {

      *(int *)puVar5 = 0;

    }

    puVar6 = 0x000C0000;

    uVar8 = (unsigned int)(unsigned char)*puVar3;

    if (uVar8 == 0) {

      *puVar3 = 1;

      *(char **)0x06078898 = puVar6;

      *(int *)0x060788A4 = *(int *)puVar5;

    }

    else {

      *puVar3 = 0;

      *(char **)0x06078894 = puVar6;

      *(int *)0x060788A0 = *(int *)puVar5;

    }

  }

  if (uVar7 < 0x70) {

    *(char **)0x0607889C = 0x00010000;

    *(int *)0x0605AA9C = 0x1e;

    iVar10 = *(int *)puVar5;

    *(int *)puVar5 = iVar10 + -1;

    if (iVar10 + -1 < 0) {

      *(int *)puVar5 = iVar11;

    }

    uVar12 = 0xFFF40000;

    uVar8 = (unsigned int)(unsigned char)*puVar3;

    if (uVar8 == 0) {

      *puVar3 = 1;

      *(int *)0x06078898 = uVar12;

      *(int *)0x060788A4 = *(int *)puVar5;

    }

    else {

      *puVar3 = 0;

      *(int *)0x06078894 = uVar12;

      *(int *)0x060788A0 = *(int *)puVar5;

    }

  }

  uVar9 = *(unsigned int *)puVar5;

  *(unsigned int *)puVar4 = uVar9;

  *(unsigned int *)0x0607EAB8 = uVar9 & 1;

  if (*(unsigned int *)puVar4 < 10) {

    if (*puVar3 == '\0') {

      uVar12 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      iVar11 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x40;

    }

    else {

      uVar12 = *(int *)(0x0605D05C + *(int *)((int)(int)puVar4 << 2));

      iVar11 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + DAT_0601096e + 0x40;

    }

    uVar8 = (*(int(*)())puVar2)(iVar11,uVar12,0xc0);

  }

  if ((uVar7 < 0x70) || (0x90 < (int)uVar7)) {

    if (*(unsigned int *)puVar4 < 0xc) {

      iVar11 = *(int *)puVar4;

    }

    else {

      iVar11 = *(int *)puVar4 + -2;

    }

    uVar8 = (*(int(*)())puVar2)(0x25F00000 + (*(int *)(0x0607EAB8 << 1) + 0x23) << 5,

                              0x0605CA9C + (iVar11 << 6),0x40);

  }

  return uVar8;

}
