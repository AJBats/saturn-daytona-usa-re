extern int DAT_060087e8;

extern int DAT_060087ea;

extern int DAT_060087ec;

extern int DAT_060087ee;

extern int DAT_060087f0;

extern int DAT_060087f2;

extern int DAT_060087f4;

extern int DAT_060087f6;

extern int DAT_060088aa;

extern int DAT_060088ac;

extern int DAT_060088ae;

extern int DAT_060088b0;

extern int DAT_060088b2;

extern int DAT_060088b4;

extern int DAT_060088b6;

int FUN_06008730()
{

  short sVar1;

  char *puVar2;

  int iVar3;

  int *puVar4;

  puVar2 = 0x0607E940;

  if (0 < *(int *)(*(int *)0x0607E940 + (int)DAT_060087e8)) {

    *(int *)(*(int *)0x0607E940 + (int)DAT_060087e8) =

         *(int *)(*(int *)0x0607E940 + (int)DAT_060087e8) + -1;

  }

  if (0 < *(int *)(*(int *)puVar2 + (int)DAT_060087ea)) {

    *(int *)(*(int *)puVar2 + (int)DAT_060087ea) = *(int *)(*(int *)puVar2 + (int)DAT_060087ea) + -1

    ;

  }

  if (*(int *)((int)DAT_060087ea + *(int *)puVar2) == 10) {

    *(short *)(*(int *)puVar2 + (int)DAT_060087ec) = 10;

  }

  iVar3 = (int)DAT_060087ee;

  puVar4 = *(int **)(*(int *)puVar2 + iVar3);

  *(int **)(*(int *)puVar2 + iVar3) = puVar4 + 3;

  *(int *)(*(int *)puVar2 + iVar3 + -4) = *puVar4;

  sVar1 = *(short *)(puVar4 + 1);

  if ((*(unsigned char *)(*(int *)puVar2 + (int)DAT_060087f0) & 0x40) == 0) {

    if (((int)*(char *)(*(int *)puVar2 + (int)DAT_060087f0) & 0x80U) == 0) {

      *(int *)(*(int *)puVar2 + (int)DAT_060088aa) = (int)*(short *)((int)puVar4 + 6);

      *(int *)(*(int *)puVar2 + (int)DAT_060088ac) = (int)*(short *)(puVar4 + 2);

      *(int *)(*(int *)puVar2 + (int)DAT_060088ae) = (int)*(short *)((int)puVar4 + 10);

    }

    else {

      *(int *)(*(int *)puVar2 + (int)DAT_060087f2) = -(int)*(short *)((int)puVar4 + 6);

      *(int *)(*(int *)puVar2 + (int)DAT_060087f4) = -(int)*(short *)(puVar4 + 2);

      *(int *)(*(int *)puVar2 + (int)DAT_060087f6) = (int)*(short *)((int)puVar4 + 10);

    }

  }

  else {

    *(int *)(*(int *)puVar2 + (int)DAT_060087f2) = (int)*(short *)((int)puVar4 + 6);

    *(int *)(*(int *)puVar2 + (int)DAT_060087f4) = -(int)*(short *)(puVar4 + 2);

    *(int *)(*(int *)puVar2 + (int)DAT_060087f6) = -(int)*(short *)((int)puVar4 + 10);

  }

  if (*(unsigned int *)(*(int *)puVar2 + 4) == (unsigned int)(unsigned char)*0x0607EBBC) {

    *(int *)(*(int *)puVar2 + (int)DAT_060088b0) = *(int *)(*(int *)puVar2 + (int)DAT_060088b0) + 1;

    if (DAT_060088b2 < sVar1) {

      *(int *)(*(int *)puVar2 + (int)DAT_060088b0) = 0;

    }

    if ((*(int *)(*(int *)puVar2 + (int)DAT_060088b4) == 0) &&

       ((*(int *)0x0607866C = 0, *(int *)0x06078635 != '\0' || (*(short *)0x0607ED8C == 0)))) {

      *(short *)0x0605A016 = 4;

    }

  }

  iVar3 = *(int *)(*(int *)puVar2 + (int)DAT_060088b4);

  if (iVar3 == 0) {

    iVar3 = (int)DAT_060088b6;

    *(int *)(*(int *)puVar2 + iVar3) = 0;

    *(int *)(*(int *)puVar2 + iVar3 + 0x14) = 0;

    *(int *)(*(int *)puVar2 + iVar3 + 0x18) = 0;

    iVar3 = iVar3 + 0x1c;

    *(int *)(*(int *)puVar2 + iVar3) = 0;

  }

  return iVar3;

}
