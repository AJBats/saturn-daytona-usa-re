extern int DAT_060124d2;

void FUN_06012450(param_1)
    int *param_1;
{

  int iVar1;

  (*(void(*)())0x06026DBC)();

  (*(void(*)())0x06026E0C)();

  (*(void(*)())0x06026E2E)(*param_1,param_1[1],param_1[2]);

  iVar1 = (*(void(*)())0x06035C2C)();

  (*(void(*)())0x06026E94)(iVar1 * 0xc000 + (int)DAT_060124d2);

  (*(void(*)())0x06031D8C)(*(int *)(0x06063564 + (*(int *)0x0607EAD8 + -1) * 4),

             *(int *)0x06063570);

  (*(void(*)())0x06031A28)(*(int *)(0x0606355C + (*(int *)0x0607EAD8 + -1) * 4),

             (int)*(short *)0x06089EA0,*(int *)0x0606356C);

  (*(void(*)())0x06026DF8)();

  return;

}
