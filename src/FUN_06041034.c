extern int FUN_060418be();

int _unknown_()
{

  char *puVar1;

  int uVar2;

  int iVar3;

  char auStack_10 [8];

  puVar1 = 0x060A5400;

  iVar3 = *(int *)(*(int *)0x060A5400 + 0x54);

  if (*(char *)(param_1 + *(int *)0x060A5400 + 0x18) == '\x01') {

    if (iVar3 < 0x18) {

      if (*(int *)(*(int *)0x060A5400 + 0x58) == 0) {

        *(int *)(*(int *)0x060A5400 + 0x58) = 1;

      }

      iVar3 = (iVar3 << 4);

      *(char *)(*(int *)puVar1 + 0x5c + iVar3) = (char)param_1;

      *(char *)(*(int *)puVar1 + iVar3 + 0x5d) = param_2;

      (*(int(*)())0x06035228)();

      *(int *)(*(int *)puVar1 + iVar3 + 100) = param_4;

      *(int *)(iVar3 + *(int *)puVar1 + 0x68) = param_5;

      *(int *)(*(int *)puVar1 + 0x54) = *(int *)(*(int *)puVar1 + 0x54) + 1;

      FUN_060418be(auStack_10);

      uVar2 = 0;

    }

    else {

      uVar2 = 0xfffffff8;

    }

  }

  else {

    uVar2 = 0xfffffff9;

  }

  return uVar2;

}
