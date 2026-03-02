extern int DAT_06012218;

extern int DAT_0601221a;

extern int DAT_0601221c;

extern int DAT_0601221e;

extern int FUN_06012344();
extern int FUN_06012400();
extern int FUN_060125d0();

void FUN_060121a8()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x060788AC;

  iVar2 = *(int *)0x060788AC;

  *(int *)0x060788AC = iVar2 + 1;

  if (iVar2 + 1 < 0x14) {

    (*(int(*)())0x06028400)(8,*(int *)0x06063AF0,0x390,

               0x0000B000 + *(int *)(0x06063AF0 + 4));

    FUN_060125d0();

  }

  if (*(int *)puVar1 == 0x14) {

    (*(int(*)())0x0601D5F4)(0,0xAE110EFF);

    puVar1 = 0x0605ACF0;

    (*(int(*)())0x060284AE)(8,0x390,0x90,0x0605ACF0);

    (*(int(*)())0x060284AE)(8,0x490,0x90,puVar1);

    (*(int(*)())0x060283E0)(8,0x590,0x0000E000,puVar1);

    return;

  }

  if (0x28 < *(int *)puVar1) {

    *(int *)0x06078636 = 0;

    (*(int(*)())0x0601D5F4)(0,0xAE110FFF);

    return;

  }

  if (0x14 < *(int *)puVar1) {

    FUN_06012344();

    FUN_06012400();

    return;

  }

  return;

}
