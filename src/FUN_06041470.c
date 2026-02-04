extern int PTR_DAT_060414c4;

extern int PTR_DAT_060414c4;

extern int FUN_06042088();

int FUN_06041470(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = 0x060A5400;

  if ((*(char *)(param_2 + *(int *)0x060A5400 + 0x18) == '\x01') &&

     (*(char *)(param_2 + *(int *)0x060A5400) == '\x01')) {

    if (*(int *)(*(int *)0x060A5400 + (int)PTR_DAT_060414c4) != 0) {

      return 0xffffffff;

    }

    iVar2 = (int)PTR_DAT_060414c4;

    *(int *)(*(int *)0x060A5400 + iVar2) = 1;

    *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

    *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

    FUN_06042088(auStack_8);

    return 0;

  }

  return 0xfffffffb;

}
