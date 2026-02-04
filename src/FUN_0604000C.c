extern int DAT_0604009e;

extern int DAT_060400a0;

extern int DAT_060400a2;

int FUN_0604000c(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = 0x060A4D14;

  *(unsigned int *)(*(int *)0x060A4D14 + (int)DAT_0604009e) =

       *(unsigned int *)(*(int *)0x060A4D14 + (int)DAT_0604009e) & 0xfffffffe;

  iVar2 = (*0x06040C98)(*(int *)puVar1 + (int)DAT_060400a0,param_1);

  if (iVar2 == 0) {

    *(unsigned int *)((int)DAT_0604009e + *(int *)puVar1) =

         *(unsigned int *)(*(int *)puVar1 + (int)DAT_0604009e) | 1;

  }

  if (param_1 == 0) {

    uVar3 = 0xffffffff;

  }

  else {

    uVar3 = 0x17;

  }

  *(int *)(*(int *)puVar1 + (int)DAT_060400a2) = uVar3;

  if (iVar2 == -0xf) {

    return 0xfffffffd;

  }

  if (iVar2 == -0xe) {

    return 0xfffffffe;

  }

  if (iVar2 != -0xd) {

    if (iVar2 != 0) {

      return 0xffffffff;

    }

    return 0;

  }

  return 0xffffffe9;

}
