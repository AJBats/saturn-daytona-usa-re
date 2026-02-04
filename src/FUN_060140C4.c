extern int DAT_06014136;

extern int FUN_06013e12();

void FUN_060140c4()
{

  char *puVar1;

  int uVar2;

  if (*(unsigned int *)0x06084B18 < 4) {

    uVar2 = *(int *)(0x0605AD4C + *(int *)(0x06084B18 << 2));

    (*(int(*)())0x06026DBC)();

    puVar1 = 0x00010000;

    (*(int(*)())0x06026E2E)(uVar2,-13107,0x00010000);

    (*(int(*)())0x06026E60)(puVar1,puVar1,puVar1);

    FUN_06013e12();

    (*(int(*)())0x06031D8C)(*(int *)(0x06062338 + *(int *)(0x06084B08 << 2)),4);

    (*(int(*)())0x06031A28)(*(int *)(0x060622C0 + *(int *)(0x06084B08 << 2)),

               (int)*(short *)0x06089E4A,1);

    *(int *)0x06089EDC = *(int *)0x06089EDC + -0x30;

  }

  return;

}
