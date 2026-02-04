extern int DAT_06014080;

extern int DAT_06014082;

extern int DAT_06014084;

extern int DAT_06014086;

void FUN_06013fc4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int *puVar7;

  int iVar8;

  int *puVar9;

  puVar4 = 0x00010000;

  puVar3 = 0x06026E2E;

  puVar2 = 0x06089EDC;

  puVar1 = 0x06026F2A;

  (*0x06026E0C)();

  puVar5 = 0x06089E4A;

  iVar8 = 0;

  puVar7 = (int *)(0x0605AD5C + DAT_06014080);

  puVar9 = (int *)0x0605AD5C;

  do {

    (*0x06026DBC)();

    (*puVar3)(0,(int)DAT_06014082,puVar4);

    (*puVar1)((int)*(short *)(puVar9 + 6));

    (*puVar3)(0,*puVar9);

    (*puVar1)(-(int)*(short *)(puVar9 + 6));

    iVar6 = (*0x06027552)

                      ((int)DAT_06014084,(unsigned int)*(unsigned short *)0x06084AF6 * (int)puVar4);

    iVar6 = DAT_06014086 + iVar6;

    (*0x06026E60)(iVar6,iVar6,iVar6);

    (*0x06031D8C)(*(int *)(0x06062338 + iVar8),4);

    (*0x06031A28)(*(int *)(0x060622C0 + iVar8),(int)*(short *)puVar5,1);

    puVar9 = puVar9 + 8;

    *(int *)puVar2 = *(int *)puVar2 + -0x30;

    iVar8 = iVar8 + 4;

  } while (puVar9 < puVar7);

  return;

}
