extern int DAT_0604155c;

extern int DAT_0604155e;

extern int DAT_060415ec;

extern int DAT_060415ee;

extern int PTR_DAT_060415f0;

extern int PTR_DAT_060415f0;

extern void FUN_06042134();

int FUN_060414d0(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char auStack_c [8];

  puVar1 = 0x060A5400;

  iVar3 = (int)DAT_0604155e;

  iVar2 = *(int *)(*(int *)0x060A5400 + (int)DAT_0604155c);

  if ((((param_1 != iVar3) && (param_1 != -2)) && ((param_1 < 0 || (0x17 < param_1)))) ||

     (((param_2 < 0 || (0x17 < param_2)) ||

      ((param_3 != iVar3 && ((param_3 != -2 && ((param_3 < 0 || (0x17 < param_3)))))))))) {

    return 0xfffffffa;

  }

  if (((param_1 == iVar3) ||

      ((param_1 == -2 || (*(char *)(param_1 + *(int *)0x060A5400 + 0x18) == '\x01')))) &&

     (((param_3 == iVar3 ||

       ((param_3 == -2 || (*(char *)(param_3 + *(int *)0x060A5400 + 0x18) == '\x01')))) &&

      (*(char *)(param_2 + *(int *)0x060A5400) == '\x01')))) {

    if (0x17 < iVar2) {

      return 0xfffffff8;

    }

    if (*(int *)(*(int *)0x060A5400 + (int)DAT_060415ec) == 0) {

      *(int *)(*(int *)0x060A5400 + (int)DAT_060415ec) = 1;

    }

    iVar3 = (int)(short)((short)iVar2 * 0xc);

    iVar2 = (int)DAT_060415ee;

    *(int *)(*(int *)puVar1 + iVar2 + iVar3) = param_1;

    *(int *)(iVar2 + *(int *)puVar1 + iVar3 + 4) = param_2;

    *(int *)(iVar3 + (int)DAT_060415ee + *(int *)puVar1 + 8) = param_3;

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_060415f0) =

         *(int *)(*(int *)puVar1 + (int)PTR_DAT_060415f0) + 1;

    FUN_06042134(auStack_c);

    return 0;

  }

  return 0xfffffff9;

}
