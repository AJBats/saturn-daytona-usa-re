extern int DAT_0600e456;

extern int PTR_DAT_0600e458;

extern int PTR_DAT_0600e458;

extern int FUN_0600e71a();

void FUN_0600e410()
{

  short extraout_var;

  int iVar1;

  iVar1 = *(int *)0x0607E944;

  *(int *)0x0607E940 = iVar1;

  (*(int(*)())0x060081F4)();

  (*(int(*)())0x060085B8)();

  (*(int(*)())0x06030A06)();

  (*(int(*)())0x06030EE0)();

  FUN_0600e71a();

  (*(int(*)())0x06027552)(*(int *)(iVar1 + 0xc),0x066505B3);

  *(int *)(DAT_0600e456 + iVar1) = (int)extraout_var;

  *(int *)(PTR_DAT_0600e458 + iVar1) = (int)extraout_var;

  return;

}
