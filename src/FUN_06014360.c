extern int DAT_0601440e;

extern int DAT_06014410;

extern int FUN_06013e12();

void FUN_06014360()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int *puVar6;

  unsigned int uVar7;

  int iVar8;

  puVar3 = 0x06089EDC;

  puVar2 = 0x06026E2E;

  puVar1 = 0x06026F2A;

  iVar5 = (int)DAT_0601440e;

  iVar8 = (int)DAT_06014410;

  (*(void(*)())0x06026E0C)();

  puVar4 = 0x06089E4A;

  uVar7 = 0;

  do {

    puVar6 = (int *)(0x0605AD5C + uVar7 * 0x20);

    (*(void(*)())0x06026DBC)();

    (*(void(*)())puVar2)(0,iVar5,0x00010000);

    (*(void(*)())puVar1)((int)*(short *)(puVar6 + 6));

    (*(void(*)())puVar2)(0,*puVar6);

    (*(void(*)())puVar1)(-(int)*(short *)(puVar6 + 6));

    if (*(unsigned int *)0x06084B08 == uVar7) {

      FUN_06013e12();

    }

    (*(void(*)())0x06026E60)(iVar8,iVar8,iVar8);

    (*(void(*)())0x06031D8C)(*(int *)(0x06062338 + uVar7 * 4),4);

    (*(void(*)())0x06031A28)(*(int *)(0x060622C0 + uVar7 * 4),(int)*(short *)puVar4,1);

    uVar7 = uVar7 + 1;

    *(int *)puVar3 = *(int *)puVar3 + -0x30;

  } while (uVar7 < 0x1d);

  return;

}
