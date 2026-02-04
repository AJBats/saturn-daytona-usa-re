extern int FUN_0601e810();
extern int FUN_0601efc4();

void FUN_0601f40c()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x060877D8;

  if (((int *)0x060877DD)[(unsigned char)*(int *)0x060877D8] != '\0') {

    FUN_0601efc4();

    iVar2 = FUN_0601e810(((int *)0x060877D9)[(unsigned char)*puVar1],

                         0x0604A57C + (unsigned int)(unsigned char)*puVar1 * 0xc,

                         *(int *)0x0605E098);

    if (iVar2 != 0) {

      *(int *)0x0605E05C = 0xc;

      (*(int(*)())0x0601F8BC)();

      return;

    }

  }

  return;

}
