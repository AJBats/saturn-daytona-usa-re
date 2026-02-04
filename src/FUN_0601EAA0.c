extern void FUN_0601e4d4();

int FUN_0601eaa0()
{

  char *puVar1;

  unsigned char bVar2;

  int uVar3;

  puVar1 = 0x060877D8;

  uVar3 = 0;

  bVar2 = FUN_0601e4d4(0x0604A57C + (unsigned int)(unsigned char)*0x060877D8 * 0xc);

  if (bVar2 < 7) {

    0x060877DD[(unsigned char)*puVar1] = 1;

    if (bVar2 < 3) {

      0x060877D9[(unsigned char)*puVar1] = bVar2;

      uVar3 = 1;

    }

    else {

      0x060877D9[(unsigned char)*puVar1] = bVar2 - 3;

    }

  }

  else {

    0x060877DD[(unsigned char)*puVar1] = 0;

  }

  return uVar3;

}
