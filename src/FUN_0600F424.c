extern int DAT_0600f462;

extern int DAT_0600f612;

extern int DAT_0600f614;

extern int DAT_0600f616;

extern int DAT_0600f618;

extern int DAT_0600f61a;

extern int PTR_DAT_0600f520;

extern int PTR_DAT_0600f520;

extern int FUN_0600ffd0();

void FUN_0600f424()
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  puVar2 = 0x0607887F;

  if (((unsigned char)*(int *)0x0607887F < 5) || (*(int *)0x0607887F == 9)) {

    if (*(int *)0x0607887F == '\t') {

      uVar4 = (*(int(*)())0x06034FE0)();

      (*(int(*)())0x06028430)(0xc,0x148,0x18,uVar4);

    }

    else {

      uVar4 = (*(int(*)())0x06034FE0)();

      (*(int(*)())0x06028430)(8,0x148,0x18,uVar4);

    }

  }

  if (((9 < (unsigned char)*puVar2) && ((char *)(unsigned int)*(unsigned short *)0x0607865E == 0x00008000))

     && (*(int *)0x0605AB18 == '\0')) {

    uVar1 = *(unsigned short *)0x06063D98;

    if ((uVar1 & *(unsigned short *)0x06078656) == 0) {

      if ((uVar1 & *(unsigned short *)0x06078658) == 0) {

        if ((uVar1 & *(unsigned short *)0x0607865A) == 0) {

          if ((uVar1 & *(unsigned short *)0x0607865C) != 0) {

            *(int *)0x06078648 = 3;

          }

        }

        else {

          *(int *)0x06078648 = 2;

        }

      }

      else {

        *(int *)0x06078648 = 1;

      }

    }

    else {

      *(int *)0x06078648 = 0;

    }

  }

  puVar3 = 0x0605ACE4;

  if (((unsigned char)*puVar2 < 0xc) && (8 < (unsigned char)*puVar2)) {

    iVar5 = (int)DAT_0600f612;

    if (*(int *)0x0607EAE0 == 0) {

      (*(int(*)())0x060284AE)(0xc,iVar5,0x90,0x0605ACE4);

      (*(int(*)())0x060284AE)(0xc,(int)DAT_0600f618,0x90,puVar3);

      (*(int(*)())0x060283E0)(0xc,(int)DAT_0600f61a,0,puVar3);

    }

    else if (*(int *)0x06078644 == 1) {

      (*(int(*)())0x06028400)(0xc,*(int *)0x06063848,iVar5,

                 *(int *)(0x06063848 + 4) + (int)DAT_0600f614,0x06063848);

    }

    else {

      (*(int(*)())0x06028400)(0xc,*(int *)0x06063850,iVar5,

                 *(int *)(0x06063850 + 4) + (int)DAT_0600f614,0x06063850);

    }

  }

  (*(int(*)())0x06026DBC)();

  (*(int(*)())(*(int *)(0x0605AC2C + ((unsigned int)(unsigned char)(*puVar2) << 2))))();

  FUN_0600ffd0();

  *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

  (*(int(*)())0x060078DC)();

  return;

}
