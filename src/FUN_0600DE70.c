extern int DAT_0600deb2;

extern void FUN_0600e0c0();
extern void FUN_0600e4f2();

void FUN_0600de70()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  short uVar7;

  int uVar8;

  char *puVar9;

  unsigned short uVar10;

  puVar5 = 0x0607ED88;

  puVar4 = 0x0607EAE4;

  puVar3 = 0x0607ED8C;

  puVar2 = 0x0607E940;

  puVar1 = 0x0607E944;

  uVar7 = (*0x06035340)();

  *(short *)0x060786CA = uVar7;

  puVar6 = 0x06078900;

  uVar8 = *(int *)0x06063EF0;

  puVar9 = 0x06078900 + DAT_0600deb2;

  for (uVar10 = 0; uVar10 < (unsigned char)*0x06078634; uVar10 = uVar10 + 1) {

    if (*0x06078635 == '\0') {

      if (*(int *)puVar4 == 0) {

        *(int *)puVar4 = 1;

      }

    }

    else if (uVar10 == 0) {

      *(short *)puVar3 = 1;

      *(char **)puVar1 = puVar9;

      *(char **)puVar2 = puVar9;

    }

    else {

      *(short *)puVar3 = 0;

      *(int *)puVar5 = *(int *)puVar5 + -2;

      *(char **)puVar1 = puVar6;

      *(int *)0x06063EF0 = uVar8;

      *(int *)puVar2 = *(int *)puVar1;

    }

    FUN_0600e4f2();

  }

  (*0x0600A8BC)();

  if (*0x06083255 == '\0') {

    (*0x0602F7EA)();

  }

  else {

    (*0x06034900)();

  }

  (*0x0602F99C)();

  FUN_0600e0c0();

  return;

}
