extern int PTR_DAT_060182f4;

extern int PTR_DAT_060182f4;

unsigned int FUN_06018278()
{

  char *puVar1;

  char *puVar2;

  unsigned int uVar3;

  unsigned short *puVar4;

  unsigned int uVar5;

  unsigned short uVar6;

  short *puVar7;

  uVar3 = (unsigned int)*(unsigned short *)0x0605BE1C;

  uVar5 = (unsigned int)*(unsigned short *)0x06063D9A;

  if ((uVar3 == 0) && (uVar5 != 0)) {

    uVar6 = 0;

    puVar4 = (unsigned short *)0x0605BE1E;

    puVar7 = (short *)0x0605BE1C;

    uVar3 = (*0x06035280)();

    if ((uVar3 & uVar5) == 0) {

      *puVar4 = uVar6;

      uVar3 = 0;

    }

    else {

      *puVar4 = *puVar4 + 1;

      uVar3 = (unsigned int)*puVar4;

      if (uVar3 == 7) {

        *puVar4 = uVar6;

        *puVar7 = 1;

        puVar2 = 0x06069BB6;

        puVar1 = 0x06063F64;

        *(int *)(0x06063F64 + (unsigned int)*(unsigned short *)0x06069BB6 * 8) =

             *(int *)0x06089E3C;

        uVar3 = (unsigned int)PTR_DAT_060182f4;

        *(short *)(puVar1 + (unsigned int)*(unsigned short *)puVar2 * 8 + 6) = PTR_DAT_060182f4;

      }

    }

  }

  return uVar3;

}
