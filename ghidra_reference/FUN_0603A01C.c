char FUN_0603a01c(param_1)
    unsigned int param_1;
{

  char cVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  puVar3 = 0x060A4CD4;

  puVar2 = 0x060A4CEC;

  func_0x0603aa82();

  puVar5 = 0x060A4CD0;

  puVar4 = 0x060A4CC8;

  *(int *)0x060A4CD0 = *(int *)0x060A4CC8;

  *(int *)puVar3 = *(int *)puVar4;

  *(int *)0x060A4CCC = 1;

  puVar4 = 0x060A4CFD;

  cVar1 = *(int *)0x060A4CFC;

  if (cVar1 == ' ') {

    if ((unsigned char)*(int *)0x060A4D02 < 5) {

      *(char **)puVar5 = 0x060A4CFD;

      *(char **)puVar3 = puVar4 + 2;

    }

    else {

      *(int *)puVar3 = *(int *)puVar3 + 2;

    }

  }

  while (*(unsigned int *)puVar2 < param_1) {

    **(char **)puVar3 = **(char **)puVar2;

    *(int *)puVar3 = *(int *)puVar3 + 1;

    *(int *)puVar2 = *(int *)puVar2 + 2;

  }

  return cVar1;

}
