extern int DAT_0600a460;

extern int DAT_0600a462;

extern int FUN_06009ffc();
extern int FUN_0600a1b8();

void FUN_0600a392()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  char auStack_1c [6];

  unsigned char bStack_16;

  puVar1 = 0x0605AD10;

  uVar3 = (*(int(*)())0x06018EAC)();

  if ((uVar3 & 0xf) == 6) {

    (*(int(*)())(*(int *)0x0600026C))();

  }

  puVar2 = 0x0607864A;

  if (*(int *)0x0607864A == '\0') {

    (*(int(*)())0x060349C4)(auStack_1c);

    if (bStack_16 < 100) {

      *(int *)0x06078649 = bStack_16;

    }

  }

  else if ((*(int *)0x0607864A == '\x01') && ((uVar3 & 0xf) == 1)) {

    (*(int(*)())0x06012B58)();

    *puVar2 = 2;

  }

  if (((*(unsigned short *)(0x06063D98 + 2) & DAT_0600a460) != 0) &&

     (((unsigned int)*(unsigned short *)0x06063D98 & 0x700) == 0x700)) {

    FUN_06009ffc();

    if (*(unsigned int *)puVar1 < 6) {

      (*(int(*)())(*(int *)0x0600026C))();

    }

    else {

      FUN_0600a1b8();

      if (*(int *)puVar1 == 0x17) {

        (*(int(*)())0x06020BCE)();

      }

      *(int *)puVar1 = 0;

    }

  }

  return;

}
