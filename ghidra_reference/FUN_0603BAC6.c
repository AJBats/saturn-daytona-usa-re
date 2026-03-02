extern int DAT_0603bbb0;

extern int DAT_0603bbb2;

extern int FUN_0603b21c();
extern int FUN_0603b81e();
extern int FUN_0603ba2c();
extern int FUN_0603bf22();

int FUN_0603bac6(param_1)
    int param_1;
{

  int iVar1;

  int uVar2;

  int iVar3;

  int iVar4;

  int uVar5;

  int local_24;

  int iStack_20;

  char uStack_1c;

  char uStack_1b;

  char uStack_1a;

  char uStack_19;

  uVar5 = 0;

  iVar1 = (*(int(*)())0x06040680)();

  if (iVar1 == 0) {

    uVar5 = 0;

  }

  else {

    local_24 = (*(int(*)())0x06040F82)();

    local_24 = local_24 + DAT_0603bbb0;

    iVar4 = 0x800;

    uStack_1a = 0;

    uStack_19 = 0;

    uStack_1c = 0;

    uStack_1b = 0;

    iStack_20 = iVar4;

    uVar2 = FUN_0603b81e();

    iVar1 = FUN_0603ba2c(uVar2,&local_24,0);

    if ((iVar1 != 0) && (iVar3 = FUN_0603b21c(iVar1,1,param_1,iVar4), iVar3 == iVar4)) {

      uVar5 = 1;

    }

    FUN_0603bf22(uVar2,iVar1);

  }

  return uVar5;

}
