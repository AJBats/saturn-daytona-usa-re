extern int DAT_06014212;

void FUN_0601416c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  unsigned char bVar5;

  unsigned int uVar6;

  puVar2 = 0x00010000;

  puVar1 = 0x06089EDC;

  iVar4 = (int)DAT_06014212;

  (*0x06026E0C)();

  puVar3 = 0x06089E4A;

  uVar6 = 0;

  do {

    if (uVar6 < *(unsigned int *)0x06084B18) {

      (*0x06026DBC)();

      (*0x06026E2E)(*(int *)(0x0605AD4C + uVar6 * 4),iVar4,puVar2);

      (*0x06026E60)(puVar2,puVar2,puVar2);

      if (0x06084B14[uVar6] == '.') {

        bVar5 = 0x1a;

      }

      else {

        bVar5 = 0x06084B14[uVar6] + 0xbf;

      }

      (*0x06031D8C)(*(int *)(0x06062338 + (unsigned int)bVar5 * 4),4);

      (*0x06031A28)

                (*(int *)(0x060622C0 + (unsigned int)bVar5 * 4),(int)*(short *)puVar3,1);

      *(int *)puVar1 = *(int *)puVar1 + -0x30;

    }

    uVar6 = uVar6 + 1;

  } while (uVar6 < 3);

  return;

}
