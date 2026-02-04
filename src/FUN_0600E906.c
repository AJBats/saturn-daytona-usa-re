extern int DAT_0600e9e2;

extern int DAT_0600e9e4;

extern int DAT_0600e9e6;

void FUN_0600e906()
{

  char *puVar1;

  short extraout_var;

  int iVar2;

  int iVar3;

  iVar3 = *(int *)0x0607E940;

  if (*(int *)0x0607EAD8 == 0) {

    (*0x0600D266)();

    (*0x0600C74E)();

    (*0x06027552)(*(int *)(iVar3 + 0xc),0x00480000);

    *(int *)(iVar3 + 8) = (int)extraout_var;

    puVar1 = 0x0600CEBA;

    *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x20);

    (*puVar1)();

    iVar2 = (int)DAT_0600e9e2;

    *(int *)(iVar3 + iVar2 + -0x34) =

         *(int *)(iVar3 + iVar2) * *(int *)0x0607EA9C + *(int *)(iVar3 + iVar2 + -0x3c);

    if (*(int *)(iVar3 + iVar2 + -0x3c) == 0) {

      iVar2 = (int)DAT_0600e9e4;

      *(int *)(iVar3 + iVar2) = 0;

      *(int *)(iVar3 + iVar2 + -0x18) = (int)DAT_0600e9e6;

    }

  }

  else {

    *(int *)(iVar3 + 0xc) = 0;

  }

  return;

}
