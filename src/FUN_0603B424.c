extern int DAT_0603b4c6;

extern int DAT_0603b4c8;

extern int DAT_0603b4ca;

extern int DAT_0603b4cc;

extern int DAT_0603b4ce;

extern void FUN_0603afd0();
extern void FUN_0603b8b4();
extern void FUN_0603b8f4();
extern void FUN_0603b93c();
extern void FUN_0603b9d6();
extern void FUN_0603bd1c();
extern void FUN_0603bdac();
extern void FUN_0603bf5a();

unsigned int FUN_0603b424(param_1)
    int param_1;
{

  int iVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned char bVar4;

  if (*(char *)(param_1 + 0x12) != '\0') {

    iVar1 = FUN_0603bd1c(param_1);

    if (iVar1 == 0) {

      if (*(char *)(param_1 + 0x11) == '\x02') {

        *(char *)(param_1 + 0x12) = 0;

        FUN_0603b9d6(param_1);

        FUN_0603b93c(0);

        bVar4 = *(unsigned char *)(param_1 + 0x12);

        goto LAB_0603b530;

      }

    }

    else if (iVar1 == 1) {

      iVar3 = FUN_0603bf5a(param_1);

      if (iVar3 == 1) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4ce;

        uVar2 = FUN_0603b93c(0xffffffe8);

        return uVar2;

      }

    }

    else {

      if (iVar1 == 3) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4c8;

        uVar2 = FUN_0603b93c(0xffffffe9);

        return uVar2;

      }

      if (iVar1 == 4) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4ca;

        uVar2 = FUN_0603b93c(0xfffffffe);

        return uVar2;

      }

      if (iVar1 == 5) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4cc;

        uVar2 = FUN_0603b93c(0xffffffec);

        return uVar2;

      }

      if (iVar1 == 6) {

        *(char *)(param_1 + 0x12) = (char)DAT_0603b4c6;

        uVar2 = FUN_0603b93c(0xffffffff);

        return uVar2;

      }

    }

    iVar3 = FUN_0603bdac(param_1);

    if ((iVar1 == 2) && (iVar3 == 5)) {

      iVar1 = (*0x0603F9F2)(*(int *)(param_1 + 8));

      iVar3 = (*0x0603F9F6)(*(int *)(param_1 + 8));

      FUN_0603afd0(param_1,iVar1 - iVar3,1);

      *(char *)(param_1 + 0x12) = 0;

      FUN_0603b8b4(param_1);

      FUN_0603b8f4(param_1);

      FUN_0603b9d6(param_1);

    }

  }

  FUN_0603b93c(0);

  bVar4 = *(unsigned char *)(param_1 + 0x12);

LAB_0603b530:

  return (unsigned int)bVar4;

}
