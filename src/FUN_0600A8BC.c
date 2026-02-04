extern int PTR_DAT_0600a900;

extern int PTR_DAT_0600a900;

unsigned short FUN_0600a8bc()
{

  char *puVar1;

  unsigned short uVar2;

  int iVar3;

  puVar1 = 0x06063F46;

  iVar3 = *(int *)0x0607E940;

  if (*(int *)(iVar3 + 0xc) == 0) {

    *(short *)0x06063F46 = 0;

    uVar2 = 0;

  }

  else {

    if (*(int *)(iVar3 + 8) < 100) {

      *(short *)0x06063F46 = *(short *)0x06063F46 + 1;

    }

    else if (*(int *)(iVar3 + 8) < (int)PTR_DAT_0600a900) {

      *(short *)0x06063F46 = *(short *)0x06063F46 + 2;

    }

    else {

      *(short *)0x06063F46 = *(short *)0x06063F46 + 4;

    }

    uVar2 = *(unsigned short *)puVar1 & 0xf;

    *(unsigned short *)puVar1 = uVar2;

  }

  return uVar2;

}
