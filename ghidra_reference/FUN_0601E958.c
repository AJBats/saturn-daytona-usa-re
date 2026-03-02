extern int FUN_0601e2b4();
extern int FUN_0601e4d4();
extern int FUN_0601e764();
extern int FUN_0601eb70();
extern int FUN_0601ebda();
extern int FUN_0601f40c();

int FUN_0601e958()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = 0x0605E05C;

  puVar2 = 0x0601F8BC;

  puVar1 = 0x0605E098;

  iVar5 = (int)(char)*(int *)0x0605E05D;

  if (iVar5 == 0) {

    FUN_0601e2b4();

    puVar4 = 0x060877D8;

    bVar6 = FUN_0601e4d4(0x0604A57C + (unsigned int)(unsigned char)*(int *)0x060877D8 * 0xc);

    if (bVar6 < 7) {

      ((int *)0x060877DD)[(unsigned char)*puVar4] = 1;

      if (2 < bVar6) {

        ((int *)0x060877D9)[(unsigned char)*puVar4] = bVar6 - 3;

        FUN_0601eb70();

        iVar5 = FUN_0601f40c();

        return iVar5;

      }

      ((int *)0x060877D9)[(unsigned char)*puVar4] = bVar6;

      iVar5 = FUN_0601e764(((int *)0x060877D9)[(unsigned char)*puVar4],

                           0x0604A57C + (unsigned int)(unsigned char)*puVar4 * 0xc,

                           *(int *)puVar1);

      if (iVar5 == 0) {

        iVar5 = 0;

        if (*(int *)0x06087080 == '\0') {

          iVar5 = 0;

          while (*(char *)(*(int *)puVar1 + iVar5) == ((int *)0x0604A5AC)[iVar5]) {

            iVar5 = iVar5 + 1;

            if (0xf < iVar5) {

              iVar5 = FUN_0601ebda();

              return iVar5;

            }

          }

          *puVar3 = 8;

          iVar5 = (*(int(*)())puVar2)();

        }

      }

      else {

        *puVar3 = 8;

        iVar5 = (*(int(*)())puVar2)();

      }

    }

    else {

      FUN_0601eb70();

      ((int *)0x060877DD)[(unsigned char)*puVar4] = 0;

      *puVar3 = 4;

      iVar5 = (*(int(*)())puVar2)();

    }

  }

  else {

    *(int *)0x0605E05C = 0;

  }

  return iVar5;

}
