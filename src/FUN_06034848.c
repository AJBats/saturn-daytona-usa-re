extern int DAT_0603489e;

unsigned int FUN_06034848()
{

  unsigned int uVar1;

  int uVar2;

  int unaff_r14;

  uVar1 = 0;

  if (((*0x06083255 != '\0') &&

      (uVar1 = *(unsigned int *)0x0607EBC4, ((unsigned int)0x00028000 & uVar1) != 0)) &&

     (uVar1 = *(unsigned int *)(unaff_r14 + 0x0000000C), uVar1 != *(unsigned int *)(unaff_r14 + 0x00000010))) {

    uVar2 = 0xAE113DFF;

    if (*(int *)(*(int *)0x0607E944 + 0x00000008) < (int)DAT_0603489e) {

      uVar1 = *(unsigned int *)(unaff_r14 + 0x0000000C);

      if (((uVar1 != 0) && (uVar2 = 0xAE113BFF, uVar1 != 3)) &&

         ((uVar2 = 0xAE113CFF, uVar1 != 4 && (uVar2 = 0xAE113DFF, uVar1 != 5)))) {

        return uVar1;

      }

    }

    else {

      uVar1 = *(unsigned int *)(unaff_r14 + 0x0000000C);

      if (((uVar1 != 0) && (uVar2 = 0xAE113BFF, uVar1 != 3)) && (uVar2 = 0xAE113CFF, uVar1 != 4)

         ) {

        return uVar1;

      }

    }

    uVar1 = (*0x0601D5F4)(0x00000000,uVar2);

  }

  return uVar1;

}
