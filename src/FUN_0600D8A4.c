extern int DAT_0600d91a;

extern int FUN_0600d9bc();

void FUN_0600d8a4(param_1)
    int param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned int uVar6;

  puVar4 = 0x06063F3C;

  puVar3 = 0x060786AC;

  puVar2 = 0x0607E940;

  puVar1 = 0x0607E944;

  uVar6 = 0;

  uVar5 = **(unsigned int **)0x06063F3C;

  if (uVar5 != 0) {

    do {

      if (((*(int *)((uVar6 << 2) + *(int *)(*(int *)puVar4 + 4)) ==

            *(int *)(*(int *)puVar2 + (int)DAT_0600d91a)) && (param_1 == 0)) &&

         (FUN_0600d9bc(uVar6 + 1), (*(unsigned char *)(*(int *)puVar1 + 3) & 8) != 0)) {

        *(int *)puVar3 = 1;

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < uVar5);

  }

  return;

}
