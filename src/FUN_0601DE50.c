extern int DAT_0601df14;

extern int DAT_0601df16;

extern int DAT_0601df18;

extern int DAT_0601df1a;

extern int DAT_0601df1c;

extern int DAT_0601df1e;

extern int DAT_0601df7a;

extern int PTR_DAT_0601df20;

extern int PTR_DAT_0601df20;

extern int FUN_0601e26c();

int FUN_0601de50()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int uVar5;

  int *puVar6;

  if ((char *)(*(int *)0x0607EBD0 * 5) < 0x000927BF) {

    FUN_0601e26c();

  }

  else {

    FUN_0601e26c(0x000927BF);

  }

  puVar2 = 0x06028400;

  puVar1 = 0x06063750;

  (*(int(*)())0x06028400)(8,0x0605DFF4,(int)DAT_0601df16,

             0x00009000 + *(int *)(0x06063750 + DAT_0601df14));

  puVar3 = 0x06078900;

  uVar5 = 0;

  if (*(unsigned int *)(0x06078900 + DAT_0601df18) < *(unsigned int *)0x06086008 &&

      *(int *)(0x06078900 + DAT_0601df1a) != 0) {

    *(int *)

     (*(int *)(0x0605DE24 + (*(int *)(0x0607EAD8 << 1) + *(int *)0x0607EAE0) << 2) + 4

     ) = *(int *)(0x06078900 + DAT_0601df18);

    puVar6 = (int *)(puVar1 + DAT_0601df1c);

    (*(int(*)())puVar2)(8,*puVar6,0x3c2,0x0000A000 + puVar6[1]);

    puVar4 = 0x0605DFEC;

    *(int *)0x0605DFEC = *(int *)0x0605DFEC + '@';

    if ((char)*puVar4 < '\0') {

      uVar5 = (*(int(*)())0x060283E0)(8,0x442,0x0000E000,0x0605ACE3);

      return uVar5;

    }

    FUN_0601e26c(*(int *)(puVar3 + DAT_0601df18));

    uVar5 = (*(int(*)())puVar2)(8,0x0605DFF4,(int)PTR_DAT_0601df20,

                              0x0000A000 + *(int *)(puVar1 + DAT_0601df14));

  }

  return uVar5;

}
