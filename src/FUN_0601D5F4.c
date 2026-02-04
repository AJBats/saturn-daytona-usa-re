extern void FUN_0601db84();

int FUN_0601d5f4(param_1, param_2)
    int param_1;
    unsigned int param_2;
{

  int iVar1;

  int iVar2;

  iVar1 = *(int *)0x06086050;

  if (*(int *)0x06086050 == 0) {

    iVar1 = param_1;

    if (param_1 == 0) {

      if ((param_2 & 0xA0000000) == 0xA0000000) {

        iVar1 = FUN_0601db84();

        *(unsigned int *)0x25A02C20 = param_2;

        *(unsigned int *)0x0608604C = param_2;

      }

    }

    else {

      if (param_1 == 1) {

        iVar2 = 0xA07000FF + param_2 * 0x100;

        iVar1 = 1;

        if (*(int *)0x0605DF94 != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DF94 = iVar2;

          *(int *)0x0608604C = iVar2;

          *(int *)0x25A02C20 = iVar2;

        }

        return iVar1;

      }

      if (param_1 == 2) {

        iVar2 = 0xA17000FF + param_2 * 0x100;

        iVar1 = 2;

        if (*(int *)0x0605DF98 != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DF98 = iVar2;

          *(int *)0x0608604C = iVar2;

          *(int *)0x25A02C20 = iVar2;

        }

        return iVar1;

      }

      if (param_1 == 3) {

        iVar2 = 0xA27000FF + param_2 * 0x100;

        iVar1 = 3;

        if (*(int *)0x0605DF9C != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DF9C = iVar2;

          *(int *)0x0608604C = iVar2;

          *(int *)0x25A02C20 = iVar2;

        }

        return iVar1;

      }

      if (param_1 == 4) {

        iVar1 = 4;

        if (*(unsigned int *)0x0605DFA4 != param_2) {

          iVar1 = FUN_0601db84();

          *(unsigned int *)0x0605DFA4 = param_2;

          *(unsigned int *)0x0608604C = param_2;

          *(unsigned int *)0x25A02C20 = param_2;

        }

        return iVar1;

      }

      if (param_1 == 5) {

        iVar2 = 0xA37000FF + param_2 * 0x100;

        iVar1 = 5;

        if (*(int *)0x0605DFA8 != iVar2) {

          iVar1 = FUN_0601db84();

          *(int *)0x0605DFA8 = iVar2;

          *(int *)0x0608604C = iVar2;

          *(int *)0x25A02C20 = iVar2;

        }

        return iVar1;

      }

      if ((param_1 == 0xf) && ((param_2 & 0xA0000000) == 0xA0000000)) {

        iVar1 = FUN_0601db84();

        *(unsigned int *)0x25A02C20 = param_2;

        *(unsigned int *)0x0608604C = param_2;

      }

    }

  }

  return iVar1;

}
