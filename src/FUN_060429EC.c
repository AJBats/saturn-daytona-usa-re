void FUN_060429ec(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int *param_4;
{

  int iVar1;

  iVar1 = (*0x0603C156)();

  if (iVar1 == 2) {

    iVar1 = (*0x06042BFC)(param_1);

    if (param_3 != 1) {

      (*0x06038A48)

                (0x25F00000 + param_2 * 4 + iVar1 * 0x400,param_4,param_3 << 2);

      return;

    }

    *(int *)(0x25F00000 + param_2 * 4 + iVar1 * 0x400) = *param_4;

  }

  else {

    iVar1 = (*0x06042BFC)(param_1);

    if (param_3 != 1) {

      (*0x06038A48)

                (0x25F00000 + param_2 * 2 + iVar1 * 0x200,param_4,param_3 << 1);

      return;

    }

    *(short *)(0x25F00000 + param_2 * 2 + iVar1 * 0x200) = *(short *)param_4;

  }

  return;

}
