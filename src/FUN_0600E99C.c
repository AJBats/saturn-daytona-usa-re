extern int DAT_0600e9e2;

extern int DAT_0600e9e8;

extern int DAT_0600e9ea;

extern int PTR_DAT_0600e9ec;

extern int PTR_DAT_0600e9ec;

extern int FUN_0600e906();

void FUN_0600e99c()
{

  short extraout_var;

  int iVar1;

  int iVar2;

  iVar2 = *(int *)0x0607E944;

  FUN_0600e906();

  if (*(int *)0x0607EAD8 == 0) {

    (*(void(*)())0x06027552)(*(int *)(iVar2 + 0xc),0x066505B3);

    *(int *)(DAT_0600e9e8 + iVar2) = (int)extraout_var;

    *(int *)(DAT_0600e9ea + iVar2) = (int)extraout_var;

  }

  if (*(int *)(iVar2 + PTR_DAT_0600e9ec) == 0) {

    *(int *)0x0607EAD0 = 0;

    iVar1 = (int)DAT_0600e9e2;

    *(int *)(iVar2 + iVar1) = 0;

    *(int *)(iVar2 + iVar1 + -0xc) = 0;

  }

  return;

}
