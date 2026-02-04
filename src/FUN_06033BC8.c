extern void FUN_06033f54();

int FUN_06033bc8()
{

  int iVar1;

  int bVar2;

  if ((*(int *)(0x000001EC + *(int *)0x0607E944) < 0x000000DC) ||

     (0x000000EC < *(int *)(0x000001EC + *(int *)0x0607E944))) {

    bVar2 = false;

  }

  else {

    bVar2 = true;

  }

  if (bVar2) {

    (*0x06033F54)(0);

    (*0x06033F54)(1);

    (*0x06033F54)(2);

  }

  else {

    (*0x0603446C)();

  }

  if ((*(int *)(0x000001EC + *(int *)0x0607E944) < 0x000000ED) ||

     (0x00000104 < *(int *)(0x000001EC + *(int *)0x0607E944))) {

    bVar2 = false;

  }

  else {

    bVar2 = true;

  }

  if (bVar2) {

    FUN_06033f54(5);

    FUN_06033f54(6);

    FUN_06033f54(7);

    FUN_06033f54(8);

    FUN_06033f54(9);

    FUN_06033f54(10);

    FUN_06033f54(0xb);

    FUN_06033f54(0xc);

    FUN_06033f54(0xd);

    FUN_06033f54(0xe);

    FUN_06033f54(0xf);

    FUN_06033f54(0x10);

    FUN_06033f54(0x11);

    FUN_06033f54(0x12);

    FUN_06033f54(0x13);

    FUN_06033f54(0x14);

    FUN_06033f54(0x15);

    FUN_06033f54(0x16);

    FUN_06033f54(0x17);

    FUN_06033f54(0x18);

  }

  if ((*(int *)(0x000001EC + *(int *)0x0607E944) < 0x000001B8) ||

     (0x000001E0 < *(int *)(0x000001EC + *(int *)0x0607E944))) {

    bVar2 = false;

  }

  else {

    bVar2 = true;

  }

  if (bVar2) {

    if (*(int *)0x0607EAE0 == 0) {

      iVar1 = 0;

    }

    else {

      FUN_06033f54(0x00000019);

      iVar1 = *(int *)0x06083250;

      if (0x0000013B <= iVar1) {

        FUN_06033f54(0x0000001A);

        FUN_06033f54(0x0000001B);

        FUN_06033f54(0x0000001C);

        FUN_06033f54(0x0000001D);

        if (0x00000276 <= iVar1) {

          FUN_06033f54(0x1e);

          FUN_06033f54(0x1f);

          FUN_06033f54(0x20);

          FUN_06033f54(0x21);

          FUN_06033f54(0x22);

          if (0x000003B1 <= iVar1) {

            FUN_06033f54(0x23);

            FUN_06033f54(0x24);

            FUN_06033f54(0x25);

            FUN_06033f54(0x26);

            FUN_06033f54(0x27);

            FUN_06033f54(0x28);

            FUN_06033f54(0x29);

            FUN_06033f54(0x2a);

            FUN_06033f54(0x2b);

            FUN_06033f54(0x2c);

          }

        }

      }

      iVar1 = *(int *)0x06083250 + 1;

      if (0x00000EC4 <= *(int *)0x06083250 + 1) {

        iVar1 = 0x00000EC4;

      }

      *(int *)0x06083250 = iVar1;

    }

  }

  else {

    iVar1 = 0;

    *(int *)0x06083250 = 0;

  }

  return iVar1;

}
