extern int DAT_06006662;

extern int DAT_06006666;

extern int DAT_06006668;

extern int DAT_0600666a;

extern int DAT_06006752;

extern int DAT_06006754;

extern int DAT_06006756;

extern int DAT_06006758;

extern int DAT_0600675a;

extern int DAT_06006802;

int FUN_060064f2()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  int uVar11;

  int iVar12;

  puVar4 = 0x06063F4C;

  puVar3 = 0x00008000;

  puVar2 = 0x06063E24;

  puVar1 = 0x06063E1C;

  *(int *)0x06063F4C = *(int *)(0x060446B8 + *(int *)0x06063E20 * 4)

  ;

  if (((int)puVar3 < *(int *)puVar2) || (*0x06078654 == '\x04')) {

    (*0x06038BD4)(8,0);

  }

  else {

    (*0x06038BD4)(8,5);

  }

  puVar10 = 0x06063E34;

  puVar9 = 0x06063E28;

  puVar8 = 0x06063E2C;

  puVar7 = 0x06063E30;

  puVar6 = 0x00010000;

  puVar5 = 0x00058000;

  if (*(int *)puVar2 == *(int *)puVar4) {

    *(int *)puVar1 = *(int *)0x06063E20;

  }

  else if (*(int *)puVar4 < *(int *)puVar2) {

    if ((int)0x00078000 < *(int *)puVar2) {

      *(int *)puVar1 = 4;

      *(int *)puVar2 = *(int *)puVar2 - (int)puVar6;

      *(int *)puVar10 = *(int *)puVar10 - (int)DAT_06006662;

      *(int *)puVar9 = *(int *)puVar9 - (int)0x0003C000;

    }

    else if ((int)0x00058000 < *(int *)puVar2) {

      *(int *)puVar1 = 3;

      *(int *)puVar2 = *(int *)puVar2 - (int)0x4000E000;

      *(int *)puVar10 = *(int *)puVar10 + 0x80;

      *(int *)puVar9 = *(int *)puVar9 - (int)0x0001C000;

    }

    else if ((int)puVar3 < *(int *)puVar2) {

      *(int *)puVar1 = 2;

      *(int *)puVar2 = *(int *)puVar2 - (int)0x0000A000;

      *(int *)puVar10 = *(int *)puVar10 + 0x40;

      *(int *)puVar9 = *(int *)puVar9 - (int)puVar6;

      *(int *)puVar7 = *(int *)puVar7 - (int)DAT_06006666;

    }

    else if (*(int *)puVar2 < 1) {

      *(int *)puVar1 = 0;

    }

    else {

      *(int *)puVar1 = 1;

      *(int *)puVar2 = *(int *)puVar2 - (int)DAT_06006668;

      *(int *)puVar10 = *(int *)puVar10 - (int)DAT_0600666a;

      *(int *)puVar9 = *(int *)puVar9 - (int)puVar5;

      *(int *)puVar8 = *(int *)puVar8 - (int)0x000D0000;

      if (*0x06083255 != '\0') {

        *(int *)puVar8 = *(int *)puVar8 - (int)0x000A0000;

      }

    }

  }

  else if (*(int *)puVar2 < *(int *)puVar4) {

    if (*(int *)puVar2 < (int)puVar3) {

      *(int *)puVar1 = 0;

      *(int *)puVar2 = *(int *)puVar2 + (int)DAT_06006752;

      *(int *)puVar10 = *(int *)puVar10 + (int)DAT_06006754;

      *(char **)puVar9 = puVar5 + *(int *)puVar9;

      *(char **)puVar8 = 0x000D0000 + *(int *)puVar8;

      if (*0x06083255 != '\0') {

        *(char **)puVar8 = 0x000A0000 + *(int *)puVar8;

      }

    }

    else if (*(int *)puVar2 < (int)0x00058000) {

      *(int *)puVar1 = 1;

      *(char **)puVar2 = 0x0000A000 + *(int *)puVar2;

      *(int *)puVar10 = *(int *)puVar10 + -0x40;

      *(char **)puVar9 = puVar6 + *(int *)puVar9;

      *(int *)puVar7 = *(int *)puVar7 + (int)DAT_06006756;

    }

    else if (*(int *)puVar2 < (int)0x00078000) {

      *(int *)puVar1 = 2;

      *(int *)puVar2 = *(int *)puVar2 + (int)DAT_06006758;

      *(int *)puVar10 = *(int *)puVar10 + -0x80;

      *(char **)puVar9 = 0x0001C000 + *(int *)puVar9;

    }

    else if (*(int *)puVar2 < (int)0x00178000) {

      *(int *)puVar1 = 3;

      *(char **)puVar2 = puVar6 + *(int *)puVar2;

      *(int *)puVar10 = *(int *)puVar10 + (int)DAT_0600675a;

      *(char **)puVar9 = 0x0003C000 + *(int *)puVar9;

    }

    else {

      *(int *)puVar1 = 4;

    }

  }

  uVar11 = (*0x06027552)(*(int *)puVar2,(int)DAT_06006802);

  *(int *)0x06063F04 = uVar11;

  iVar12 = (*0x06027552)(*(int *)puVar2,(int)DAT_06006802);

  *(int *)0x06063F08 = iVar12;

  if ((*(int *)puVar1 == 0) ||

     ((iVar12 = *(int *)puVar1, iVar12 == 1 && (*(unsigned int *)0x06063E20 < 2)))) {

    *(int *)0x06059F30 = 0;

  }

  else {

    *(int *)0x06059F30 = 1;

  }

  return iVar12;

}
