extern void FUN_060412b2();
extern void FUN_06041310();
extern void FUN_06041698();

int FUN_06040f16(param_1)
    int param_1;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  puVar1 = 0x060A5400;

  if ((param_1 < 0) || (0x17 < param_1)) {

    uVar2 = 0xfffffffa;

  }

  else if (*(char *)(param_1 + *(int *)0x060A5400) == '\x01') {

    FUN_060412b2(param_1,0,0x0000FFFF);

    *(char **)(*(int *)puVar1 + 0x3c) = 0x00008000;

    do {

      iVar3 = FUN_06041698();

      if (iVar3 == 3) {

        return 0xfffffff4;

      }

      iVar3 = FUN_06041310(param_1);

    } while (iVar3 != 1);

    *(int *)(*(int *)puVar1 + 0x3c) = 0;

    *(char *)(param_1 + *(int *)puVar1) = 0;

    uVar2 = 0;

  }

  else {

    uVar2 = 0xfffffff9;

  }

  return uVar2;

}
