extern int DAT_0603f2c2;

int FUN_0603f22c()
{

  int uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  int local_24;

  char auStack_20 [4];

  char auStack_1c [8];

  puVar4 = 0x060A4D14;

  puVar3 = 0x06041470;

  puVar2 = 0x06041698;

  uVar1 = 0x00FFFFFF;

  iVar5 = (*0x06041470)

                    (0x00FFFFFF,*(int *)(*(int *)0x060A4D14 + (int)DAT_0603f2c2));

  if (iVar5 == -5) {

    local_24 = -1;

  }

  else {

    (*0x06041884)(0x00008000);

    while (iVar5 != 0) {

      iVar5 = (*puVar2)();

      if (iVar5 == -0xc) {

        return -1;

      }

      iVar5 = (*puVar3)(uVar1,*(int *)(*(int *)puVar4 + (int)DAT_0603f2c2));

    }

    iVar5 = (*0x0604188C)();

    if (iVar5 == 0) {

      iVar5 = (*0x06036A98)(auStack_20,&local_24,auStack_1c);

      if (iVar5 == 0) {

        local_24 = local_24 + 2;

      }

      else {

        local_24 = -1;

      }

    }

    else {

      local_24 = -1;

    }

  }

  return local_24;

}
