extern int DAT_0603ac16;

extern int DAT_0603ac18;

extern int DAT_0603ac1a;

void FUN_0603ab46(param_1)
    char param_1;
{

  unsigned short uVar1;

  int iVar2;

  uVar1 = (unsigned short)(unsigned char)*0x060A4CAF;

  if (uVar1 == 0) {

    iVar2 = *(int *)0x060A4CB4;

LAB_0603abe6:

    *(char *)(iVar2 * 6 + *(int *)0x060A4CC0 + 4) = param_1;

  }

  else {

    if (uVar1 == 0x10) {

      iVar2 = *(int *)0x060A4CB4;

    }

    else {

      if (uVar1 != 0x20) {

        if (uVar1 == 0x30) {

          *(char *)(*(int *)0x060A4CB4 * 10 + *(int *)0x060A4CC0 + 8) = param_1;

          return;

        }

        if (uVar1 == DAT_0603ac16) {

          *(char *)(*(int *)0x060A4CB4 * 3 + *(int *)0x060A4CC0 + 2) = param_1;

          return;

        }

        if (uVar1 != DAT_0603ac18) {

          if (uVar1 != DAT_0603ac1a) {

            return;

          }

          *(char *)

           (((unsigned char)*0x060A4CAE + 1) * *(int *)0x060A4CB4 + *(int *)0x060A4CC0) =

               param_1;

          return;

        }

        iVar2 = *(int *)0x060A4CB4;

        goto LAB_0603abe6;

      }

      iVar2 = *(int *)0x060A4CB4;

    }

    *(char *)(iVar2 * 0x12 + *(int *)0x060A4CC0 + 0x10) = param_1;

  }

  return;

}
