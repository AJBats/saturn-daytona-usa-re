extern int DAT_06008358;

extern int DAT_0600835a;

extern int DAT_060083fa;

extern int DAT_060083fc;

extern int DAT_060083fe;

extern int DAT_06008400;

extern int DAT_06008402;

extern int PTR_DAT_06008360;

extern int PTR_DAT_06008360;

int FUN_06008318()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  puVar2 = 0x0607EBE0;

  puVar1 = 0x0607E940;

  if (*(int *)(*(int *)0x0607E940 + (int)DAT_06008358) == 0) {

    if (((int)DAT_060083fa < *(int *)0x0607EBD0) &&

       (*(int *)(*(int *)0x0607E940 + (int)DAT_060083fc) == 0)) {

      if ((**(unsigned char **)0x0607E940 & 0x10) == 0) {

        if ((**(unsigned char **)0x0607E940 & 0x20) != 0) {

          *(int *)(*(int *)0x0607E940 + (int)DAT_060083fe) = 0x20;

          *(int *)(*(int *)puVar1 + (int)DAT_06008400) = 1;

          *(int *)puVar2 = *(int *)puVar1;

          *(short *)(*(int *)puVar1 + (int)DAT_06008402) = 0x28;

        }

      }

      else {

        *(int *)(*(int *)0x0607E940 + (int)DAT_060083fe) = 0x20;

        *(int *)(*(int *)puVar1 + (int)DAT_06008400) = 0xffffffff;

        *(int *)puVar2 = *(int *)puVar1;

        *(short *)(*(int *)puVar1 + (int)DAT_06008402) = 0x28;

      }

    }

  }

  else {

    iVar3 = (int)DAT_06008358;

    *(int *)(*(int *)0x0607E940 + iVar3) = *(int *)(*(int *)0x0607E940 + iVar3) + -1;

    if (*(int *)(*(int *)puVar1 + (int)DAT_0600835a) < 1) {

      iVar3 = -(int)*(short *)(0x060453CC + *(int *)(*(int *)puVar1 + iVar3) * 2);

    }

    else {

      iVar3 = (int)*(short *)(0x060453CC + *(int *)(*(int *)puVar1 + iVar3) * 2);

    }

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_06008360) = iVar3;

  }

  (*(void(*)())0x06034F78)(puVar1,0);

  uVar4 = (*(void(*)())0x06034F78)();

  return uVar4;

}
