extern int DAT_0600d82a;

extern int DAT_0600d82c;

extern int DAT_0600d82e;

extern void FUN_0600d84c();
extern void FUN_0600d8a4();
extern void FUN_0600d92c();
extern void FUN_0600d9bc();

int FUN_0600d780(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  puVar2 = 0x0607EA9C;

  puVar1 = 0x06063F1C;

  iVar4 = *(int *)0x0607E940;

  iVar5 = *(int *)(iVar4 + DAT_0600d82a);

  iVar3 = DAT_0600d82a + 4;

  iVar6 = iVar5 - *(int *)(iVar4 + iVar3);

  if (iVar5 != *(int *)(iVar4 + iVar3)) {

    if (iVar6 < -1) {

      iVar3 = (int)DAT_0600d82c;

      *(int *)(iVar4 + iVar3) = *(int *)(iVar4 + iVar3) + 1;

      iVar3 = iVar3 + -0x40;

      if ((*(int *)(iVar4 + iVar3) == *(int *)puVar2) && (param_1 == 0)) {

        *(int *)(iVar4 + DAT_0600d82e) = 0;

        *(int *)puVar1 = *(int *)0x06063F18;

        FUN_0600d9bc(0);

        iVar3 = FUN_0600d92c();

        *0x0605DE3C = 0;

      }

    }

    else if (iVar6 < 2) {

      if (param_1 == 0) {

        FUN_0600d84c();

        iVar3 = FUN_0600d8a4(0);

        return iVar3;

      }

    }

    else {

      iVar3 = (int)DAT_0600d82c;

      *(int *)(iVar4 + iVar3) = *(int *)(iVar4 + iVar3) + -1;

      iVar5 = *(int *)puVar2;

      iVar3 = iVar3 + -0x40;

      if (((int)(iVar5 + (unsigned int)(iVar5 < 0)) >> 1 <= *(int *)(iVar4 + iVar3)) && (param_1 == 0)) {

        *(int *)(iVar4 + DAT_0600d82e) = 0;

        *(int *)puVar1 = *(int *)0x06063F18;

        FUN_0600d9bc(0);

        iVar3 = FUN_0600d92c();

        *0x0605DE3C = 1;

      }

    }

  }

  return iVar3;

}
