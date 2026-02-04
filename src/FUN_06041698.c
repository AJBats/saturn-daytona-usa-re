extern int PTR_DAT_0604172a;

extern int PTR_DAT_0604172a;

extern int FUN_060417a8();
extern int FUN_06041826();
extern int FUN_0604231e();

int FUN_06041698()
{

  char *puVar1;

  int uVar2;

  short sVar4;

  int iVar3;

  int iVar5;

  int iVar6;

  int local_30;

  unsigned int uStack_2c;

  char auStack_28 [16];

  puVar1 = 0x060A5400;

  local_30 = 0;

  iVar6 = 0;

  if ((*(int *)(*(int *)0x060A5400 + 0x3c) == 0) ||

     (iVar5 = *(int *)(*(int *)0x060A5400 + 0x3c) + -1,

     *(int *)(*(int *)0x060A5400 + 0x3c) = iVar5, 0 < iVar5)) {

    uStack_2c = (unsigned int)PTR_DAT_0604172a;

    sVar4 = (*(void(*)())0x06035C4E)();

    if (((int)sVar4 & uStack_2c) == 0) {

      iVar5 = (*(void(*)())0x060349C4)(auStack_28);

      if (iVar5 == 0) {

        (*(void(*)())0x06035168)();

      }

    }

    else {

      (*(void(*)())0x06035C54)(0x0000FBFF);

      (*(void(*)())0x06034984)(auStack_28);

      (*(void(*)())0x06035168)();

      if (*(int *)(*(int *)puVar1 + 0x4c) != 0) {

        iVar5 = *(int *)puVar1;

        (*(void(*)())(*(int *)(iVar5 + 0x4c)))(*(int *)(iVar5 + 0x50));

      }

    }

    for (iVar5 = 0; iVar5 < 8; iVar5 = iVar5 + 1) {

      iVar3 = FUN_060417a8(iVar5);

      if (iVar3 == 0) {

        iVar3 = FUN_06041826(iVar5,&local_30);

        iVar6 = iVar6 + iVar3;

        if (0x1e < local_30) {

          return 1;

        }

      }

    }

    if (iVar6 < 1) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

    }

  }

  else {

    FUN_0604231e();

    uVar2 = 3;

  }

  return uVar2;

}
