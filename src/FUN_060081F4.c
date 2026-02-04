extern int DAT_060082aa;

extern int DAT_060082ac;

extern int DAT_060082ae;

extern int DAT_060082b0;

extern int DAT_060082b2;

extern int DAT_06008358;

extern int DAT_0600835a;

void FUN_060081f4()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  char *puVar4;

  int iVar5;

  puVar2 = 0x00020000;

  puVar4 = 0x0607EBC4;

  puVar1 = 0x0607E944;

  if (*(int *)(*(int *)0x0607E944 + (int)DAT_060082aa) == 0) {

    if ((0x13 < *(int *)(*(int *)0x0607E944 + 8)) &&

       (*(int *)(*(int *)0x0607E944 + (int)DAT_060082b2) == 0)) {

      if ((**(unsigned char **)0x0607E944 & 0x10) == 0) {

        if ((**(unsigned char **)0x0607E944 & 0x20) != 0) {

          *(int *)(*(int *)0x0607E944 + (int)DAT_06008358) = 0x30;

          *(int *)(*(int *)puVar1 + (int)DAT_0600835a) = 1;

          if (((unsigned int)puVar2 & *(unsigned int *)puVar4) != 0) {

            (*0x0601D5F4)(0,0xAE111BFF);

          }

        }

      }

      else {

        *(int *)(*(int *)0x0607E944 + (int)DAT_060082aa) = 0x30;

        *(int *)(*(int *)puVar1 + (int)DAT_060082ac) = 0xffffffff;

        if (((unsigned int)puVar2 & *(unsigned int *)puVar4) != 0) {

          (*0x0601D5F4)(0,0xAE111BFF);

        }

      }

    }

  }

  else {

    *(int *)0x0607EBD4 = 0x46;

    iVar3 = (int)DAT_060082aa;

    iVar5 = *(int *)(*(int *)puVar1 + iVar3);

    *(int *)(*(int *)puVar1 + iVar3) = *(int *)(*(int *)puVar1 + iVar3) + -1;

    puVar4 = 0x0604546C;

    if ((**(unsigned char **)puVar1 & 0x40) != 0) {

      puVar4 = 0x0604540C;

    }

    if (*(int *)(*(int *)puVar1 + (int)DAT_060082ac) < 0) {

      iVar3 = (int)*(short *)(puVar4 + (0x30 - iVar5) * 2);

    }

    else {

      iVar3 = -(int)*(short *)(puVar4 + (0x30 - iVar5) * 2);

    }

    *(int *)(*(int *)puVar1 + (int)DAT_060082ae) = iVar3;

    *(int *)(*(int *)puVar1 + 0xc) = *(int *)(*(int *)puVar1 + 0xc) - (int)DAT_060082b0;

  }

  (*0x06034F78)(0);

  (*0x06034F78)();

  return;

}
