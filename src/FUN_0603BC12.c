extern int DAT_0603bc56;

extern void FUN_0603b81e();
extern void FUN_0603ba2c();
extern void FUN_0603bb86();
extern void FUN_0603bf22();

int FUN_0603bc12(param_1)
    int param_1;
{

  int iVar1;

  int uVar2;

  int unaff_r13;

  char auStack_18 [4];

  int uStack_14;

  iVar1 = FUN_0603bb86(auStack_18);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    unaff_r13 = FUN_0603b81e();

    iVar1 = FUN_0603ba2c(unaff_r13,auStack_18,0);

  }

  if (((*(unsigned int *)((int)DAT_0603bc56 + *(int *)0x060A4D14) & 1) == 0) || (iVar1 != 0)) {

    uVar2 = (*0x0603F0FC)(iVar1,param_1,uStack_14);

    if (iVar1 != 0) {

      FUN_0603bf22(unaff_r13,iVar1);

    }

  }

  else {

    uVar2 = 0xfffffffd;

  }

  return uVar2;

}
