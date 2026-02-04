extern void FUN_0603a6c0();
extern void FUN_0603a72c();
extern void FUN_0603a766();

int FUN_06039808(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  puVar2 = 0x06063608;

  puVar1 = 0x06063601;

  if ((*0x060A4CAA == '\x01') || (*0x060A4CAA == '\x02')) {

    if ((*0x20100061 & 0x10) == 0x10) {

      iVar5 = *(int *)0x06063608;

      *(int *)0x06063608 = iVar5 + 1;

      if (2 < iVar5 + 1) {

        *puVar1 = 1;

        *(int *)puVar2 = *(int *)puVar2 + -1;

      }

    }

    else {

      *0x06063601 = 0;

      *(int *)puVar2 = 0;

    }

    if ((int)(unsigned int)(unsigned char)*0x060A4CAB <= *(int *)0x060A4CB8) {

      *(int *)0x060A4CB8 = 0;

      puVar1 = 0x06063600;

      if (*(int *)0x060A4CB4 < (int)(unsigned int)*(unsigned short *)0x060A4CAC) {

        *0x06063600 = *0x06063600 + '\x01';

        if (2 < (unsigned char)*puVar1) {

          FUN_0603a766();

          *puVar1 = *puVar1 + -1;

        }

      }

      else {

        *0x06063600 = 0;

      }

      puVar2 = 0x060A4CC4;

      puVar1 = 0x060A4CE8;

      *(int *)0x060A4CC4 = *(int *)0x060A4CE8;

      puVar3 = 0x060A4C98;

      *(int *)puVar1 = *(int *)0x060A4C98;

      *(int *)puVar3 = *(int *)puVar2;

      puVar1 = 0x060A4CC0;

      *(int *)puVar2 = *(int *)0x060A4CC0;

      puVar3 = 0x060A4CBC;

      *(int *)puVar1 = *(int *)0x060A4CBC;

      uVar4 = *(int *)puVar2;

      *(int *)puVar3 = uVar4;

      *param_1 = uVar4;

      FUN_0603a6c0();

      uVar4 = FUN_0603a72c();

      return uVar4;

    }

    *(int *)0x060A4CB8 = *(int *)0x060A4CB8 + 1;

    uVar4 = 0;

  }

  else {

    *param_1 = 0;

    uVar4 = 1;

  }

  return uVar4;

}
