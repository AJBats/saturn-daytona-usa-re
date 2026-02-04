extern int PTR_LAB_0600307c;

void main()
{

  char *puVar1;

  char *puVar2;

  void *pcVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  (*0x060030FC)();

  do {

    (*0x0600A392)();

    puVar1 = 0x0607EBC4;

    iVar4 = *(int *)0x0605AD10;

    *(int *)0x0607EBC0 = iVar4;

    puVar2 = 0x0607EBC8;

    iVar5 = 1;

    iVar6 = iVar4;

    if (0xf < iVar4) {

      iVar5 = 0x10000;

      iVar6 = iVar4 + -0x10;

    }

    if (7 < iVar6) {

      iVar5 = iVar5 << 8;

      iVar6 = iVar6 + -8;

    }

    if (5 < iVar6) {

      iVar5 = iVar5 << 6;

      iVar6 = iVar6 + -6;

    }

    for (; iVar6 != 0; iVar6 = iVar6 + -1) {

      iVar5 = iVar5 << 1;

    }

    *(int *)puVar1 = iVar5;

    pcVar3 = (&PTR_LAB_0600307c)[iVar4];

    *(int *)puVar2 = *(int *)puVar2 + 1;

    (*pcVar3)();

  } while( true );

}
