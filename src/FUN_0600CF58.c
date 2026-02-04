extern int DAT_0600cfe2;

extern int DAT_0600cfe4;

extern int DAT_0600cfe6;

extern int DAT_0600d0aa;

extern int DAT_0600d0ac;

extern int DAT_0600d0ae;

extern int DAT_0600d0b0;

extern int DAT_0600d0b2;

extern int DAT_0600d0b4;

extern int DAT_0600d0b6;

extern int PTR_DAT_0600cfe8;

extern int PTR_DAT_0600cfe8;

extern void FUN_0600d0b8();
extern void FUN_0600d12c();
extern void FUN_0600d210();

unsigned int FUN_0600cf58()
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  unsigned char local_18;

  iVar4 = (int)DAT_0600cfe2;

  iVar6 = *(int *)0x0607E940;

  iVar5 = *(int *)0x0607E944;

  if ((*(unsigned int *)(iVar6 + 4) != 0) && ((int)DAT_0600cfe4 < *(int *)(iVar6 + 8))) {

    if ((**(unsigned int **)0x0607E940 & (unsigned int)0x00C00000) == 0) {

      return *(unsigned int *)(iVar6 + 4);

    }

    (*0x06035168)();

    if (*(int *)(iVar6 + DAT_0600cfe6) == 0) {

      uVar1 = FUN_0600d0b8();

      return uVar1;

    }

    uVar1 = (unsigned int)(char)local_18;

    if ((uVar1 & 2) != 0) {

      if (*(int *)(iVar6 + 8) <= *(int *)(iVar5 + 8)) {

        iVar5 = (int)PTR_DAT_0600cfe8;

        *(int *)(iVar6 + iVar5 + -4) = *(int *)(iVar6 + iVar5);

        *(int *)(iVar6 + iVar5 + 8U) = iVar4;

        return iVar5 + 8U;

      }

      uVar1 = FUN_0600d12c();

    }

    if (*(int *)(iVar5 + 8) < *(int *)(iVar6 + 8)) {

      return uVar1;

    }

    if ((local_18 & 1) != 0) {

      if (*(int *)(iVar6 + DAT_0600d0aa) == 2) {

        if (((int)DAT_0600d0ac < *(int *)(iVar5 + 8)) && (*(int *)(iVar6 + DAT_0600d0ae) < 10)) {

          uVar1 = FUN_0600d210();

          return uVar1;

        }

        uVar1 = FUN_0600d12c();

        return uVar1;

      }

      if (*(unsigned int *)(iVar6 + DAT_0600d0aa) != 1) {

        return *(unsigned int *)(iVar6 + DAT_0600d0aa);

      }

      uVar1 = (unsigned int)DAT_0600d0b0;

      uVar2 = *(int *)(iVar5 + uVar1) >> 8;

      uVar3 = *(int *)(iVar6 + uVar1) >> 8;

      if ((uVar2 < 2) && (uVar3 < 3)) {

        iVar5 = (int)DAT_0600d0b4;

        *(int *)(iVar6 + iVar5) = (int)DAT_0600d0b2;

        uVar1 = iVar5 + 0xc;

        *(int *)(iVar6 + uVar1) = iVar4;

        return uVar1;

      }

      if (uVar2 < 6) {

        return uVar1;

      }

      if (uVar3 < 5) {

        return uVar1;

      }

      iVar5 = (int)DAT_0600d0b4;

      *(int *)(iVar6 + iVar5) = (int)DAT_0600d0b6;

      uVar1 = iVar5 + 0xc;

      *(int *)(iVar6 + uVar1) = iVar4;

      return uVar1;

    }

    FUN_0600d12c();

  }

  uVar1 = *(unsigned int *)(iVar6 + 4);

  if (uVar1 == 0) {

    uVar1 = FUN_0600d12c();

  }

  return uVar1;

}
