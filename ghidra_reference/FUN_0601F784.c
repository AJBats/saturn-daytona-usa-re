extern int DAT_0601f804;

extern int DAT_0601f806;

extern int PTR_DAT_0601f808;

extern int PTR_DAT_0601f808;

extern int FUN_0601f87a();

unsigned int FUN_0601f784()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  puVar2 = 0x0607EAD8;

  puVar1 = 0x0607ED90;

  uVar5 = (unsigned int)DAT_0601f804;

  uVar3 = 0;

  if (*(int *)0x06078635 != '\0') {

    FUN_0601f87a(*(int *)0x0607EAD8 + 1U & 0xff);

    (*(int(*)())0x0601E2B4)();

    uVar3 = (*(int(*)())0x0601EAA0)();

    uVar3 = uVar3 & 0xff;

    if ((uVar3 == 0) &&

       ((*(int *)0x0605E0A1 == '\0' || ((unsigned int)(unsigned char)*(int *)0x0605E0A0 != *(unsigned int *)0x0607EAD8)))

       ) {

      if (*(int *)puVar2 == 0) {

        uVar3 = (*(int(*)())0x06027630)(puVar1,0x002F8000,(int)DAT_0601f806);

      }

      else if (*(int *)puVar2 == 1) {

        uVar3 = (*(int(*)())0x06027630)(puVar1,0x002F8000,(int)PTR_DAT_0601f808);

      }

      else {

        uVar3 = *(unsigned int *)puVar2;

        if (uVar3 == 2) {

          uVar3 = (*(int(*)())0x06027630)(puVar1,0x002F8000,uVar5);

        }

      }

    }

    for (uVar4 = *(unsigned int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2)); uVar4 < uVar5;

        uVar4 = uVar4 + 2) {

      uVar3 = uVar4 + 1;

      puVar1[uVar4] = 0x40;

      puVar1[uVar3] = 0x80;

    }

    *(int *)0x0605E0A1 = 0;

  }

  return uVar3;

}
