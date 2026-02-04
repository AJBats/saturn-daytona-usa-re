extern int DAT_06012218;

extern int DAT_0601221a;

extern int DAT_0601221c;

extern int DAT_0601221e;

extern void FUN_06012344();
extern void FUN_06012400();
extern void FUN_060125d0();

void FUN_060121a8()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x060788AC;

  iVar2 = *(int *)0x060788AC;

  *(int *)0x060788AC = iVar2 + 1;

  if (iVar2 + 1 < 0x14) {

    (*0x06028400)

              (8,*(int *)0x06063AF0,(int)DAT_06012218,

               0x0000B000 + *(int *)(0x06063AF0 + 4));

    FUN_060125d0();

  }

  if (*(int *)puVar1 == 0x14) {

    (*0x0601D5F4)(0,0xAE110EFF);

    puVar1 = 0x0605ACF0;

    (*0x060284AE)(8,(int)DAT_06012218,(int)DAT_0601221a,0x0605ACF0);

    (*0x060284AE)(8,(int)DAT_0601221c,(int)DAT_0601221a,puVar1);

    (*0x060283E0)(8,(int)DAT_0601221e,0x0000E000,puVar1);

    return;

  }

  if (0x28 < *(int *)puVar1) {

    *0x06078636 = 0;

    (*0x0601D5F4)(0,0xAE110FFF);

    return;

  }

  if (0x14 < *(int *)puVar1) {

    FUN_06012344();

    FUN_06012400();

    return;

  }

  return;

}
