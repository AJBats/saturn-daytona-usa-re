extern int DAT_06007412;

extern int DAT_06007414;

extern int DAT_06007416;

extern int DAT_06007418;

extern int DAT_0600741a;

extern int PTR_DAT_0600741c;

extern int PTR_DAT_0600741c;

void FUN_0600736c()
{

  char *puVar1;

  puVar1 = 0x06063F5C;

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_06007412;

  (*(int(*)())0x06039250)(puVar1);

  (*(int(*)())0x0603931C)(0,2);

  (*(int(*)())0x060393FC)(0,0,0,(int)DAT_06007416,(int)DAT_06007414);

  (*(int(*)())0x06038E54)(0x0000FFFF);

  (*(int(*)())0x06012E00)();

  (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)puVar1,0x002A0000,0x3c0);

  if ((*(unsigned int *)0x0607EAB8 & 1) != 0) {

    (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)puVar1 + 0x300,

               0x06059F78,0x80);

  }

  (*(int(*)())0x0602766C)(*(int *)puVar1,0x0605A018,0x60);

  *(int *)0x0605A008 = 3;

  *(short *)(*(int *)puVar1 + 0x60) = (short)0x00008000;

  (*(int(*)())0x0602382C)();

  (*(int(*)())0x06028654)(0x002A3457,0x0606B178);

  (*(int(*)())0x06026CE0)();

  return;

}
